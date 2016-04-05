/*
 * GridFS.cpp
 *
 *  Created on: Oct 23, 2012
 *      Author: ubuntu
 */


#include <mongo/pch.h>

#include <boost/smart_ptr.hpp>
#include <fcntl.h>
#include <fstream>
#include <utility>

#include "MyGridFS.h"
#include <mongo/client/dbclientcursor.h>

#if defined(_WIN32)
#include <io.h>
#endif

#ifndef MIN
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#endif

#include <boost/filesystem/operations.hpp>

namespace mongo {

    const unsigned DEFAULT_CHUNK_SIZE = 256 * 1024;

    MyGridFSChunk::MyGridFSChunk( BSONObj o ) {
        _data = o;
    }

    MyGridFSChunk::MyGridFSChunk( BSONObj fileObject , int chunkNumber , const char * data , int len ) {
        BSONObjBuilder b;
        b.appendAs( fileObject["_id"] , "files_id" );
        b.append( "n" , chunkNumber );
        b.appendBinData( "data" , len, BinDataGeneral, data );
        _data = b.obj();
    }


    MyGridFS::MyGridFS( DBClientBase& client , const string& dbName , const string& prefix ) : _client( client ) , _dbName( dbName ) , _prefix( prefix ) {
        _filesNS = dbName + "." + prefix + ".files";
        _chunksNS = dbName + "." + prefix + ".chunks";
        _chunkSize = DEFAULT_CHUNK_SIZE;

        client.ensureIndex( _filesNS , BSON( "filename" << 1 ) );
        client.ensureIndex( _chunksNS , BSON( "files_id" << 1 << "n" << 1 ) );
    }

    MyGridFS::~MyGridFS() {

    }

    void MyGridFS::setChunkSize(unsigned int size) {
        massert( 13296 , "invalid chunk size is specified", (size != 0 ));
        _chunkSize = size;
    }

    unsigned int MyGridFS::getChunkSize() const {
        return _chunkSize;
    }

    BSONObj MyGridFS::storeFile( const char* data , size_t length , const string& remoteName , const string& contentType) {
        char const * const end = data + length;

        OID id;
        id.init();
        BSONObj idObj = BSON("_id" << id);

        int chunkNumber = 0;
        while (data < end) {
            int chunkLen = MIN(_chunkSize, (unsigned)(end-data));
            MyGridFSChunk c(idObj, chunkNumber, data, chunkLen);
            _client.insert( _chunksNS.c_str() , c._data );

            chunkNumber++;
            data += chunkLen;
        }

        return insertFile(remoteName, id, length, contentType);
    }


    BSONObj MyGridFS::storeFile( const string& fileName , const string& remoteName , const string& contentType) {
        uassert( 10012 ,  "file doesn't exist" , fileName == "-" || boost::filesystem::exists( boost::filesystem::path( fileName ) ) );

        FILE* fd;
        if (fileName == "-")
            fd = stdin;
        else
            fd = fopen( fileName.c_str() , "rb" );
        uassert( 10013 , "error opening file", fd);

        OID id;
        id.init();
        BSONObj idObj = BSON("_id" << id);

        int chunkNumber = 0;
        gridfs_offset length = 0;
        while (!feof(fd)) {
            //boost::scoped_array<char>buf (new char[_chunkSize+1]);
            char * buf = new char[_chunkSize+1];
            char* bufPos = buf;//.get();
            unsigned int chunkLen = 0; // how much in the chunk now
            while(chunkLen != _chunkSize && !feof(fd)) {
                int readLen = fread(bufPos, 1, _chunkSize - chunkLen, fd);
                chunkLen += readLen;
                bufPos += readLen;

                verify(chunkLen <= _chunkSize);
            }

            MyGridFSChunk c(idObj, chunkNumber, buf, chunkLen);
            _client.insert( _chunksNS.c_str() , c._data );

            length += chunkLen;
            chunkNumber++;
            delete[] buf;
        }

        if (fd != stdin)
            fclose( fd );

        return insertFile((remoteName.empty() ? fileName : remoteName), id, length, contentType);
    }

    BSONObj MyGridFS::insertFile(const string& name, const OID& id, gridfs_offset length, const string& contentType) {
        // Wait for any pending writebacks to finish
        string err = _client.getLastError();
        uassert( 16428,
                 str::stream() << "Error storing GridFS chunk for file: " << name
                               << ", error: " << err,
                 err == "" );

        BSONObj res;
        if ( ! _client.runCommand( _dbName.c_str() , BSON( "filemd5" << id << "root" << _prefix ) , res ) )
            throw UserException( 9008 , "filemd5 failed" );

        BSONObjBuilder file;
        file << "_id" << id
             << "filename" << name
             << "chunkSize" << _chunkSize
             << "uploadDate" << DATENOW
             << "md5" << res["md5"]
             ;

        if (length < 1024*1024*1024) { // 2^30
            file << "length" << (int) length;
        }
        else {
            file << "length" << (long long) length;
        }

        if (!contentType.empty())
            file << "contentType" << contentType;

        BSONObj ret = file.obj();
        _client.insert(_filesNS.c_str(), ret);

        return ret;
    }

    void MyGridFS::removeFile( const string& fileName ) {
        auto_ptr<DBClientCursor> files = _client.query( _filesNS , BSON( "filename" << fileName ) );
        while (files->more()) {
            BSONObj file = files->next();
            BSONElement id = file["_id"];
            _client.remove( _filesNS.c_str() , BSON( "_id" << id ) );
            _client.remove( _chunksNS.c_str() , BSON( "files_id" << id ) );
        }
    }

    MyGridFile MyGridFS::findFile( const std::string& key ) const {
    	return MyGridFile( this, key );
    }

    auto_ptr<DBClientCursor> MyGridFS::list() const {
	bool slaveOk = 1;
        //return _client.query( _filesNS.c_str() , BSONObj() );
        return _client.query( _filesNS.c_str() , BSONObj() , 0 , QueryOption_SlaveOk );
    }

    auto_ptr<DBClientCursor> MyGridFS::list( BSONObj o ) const {
	bool slaveOk = 1;
	//return _client.query( _filesNS.c_str() , o );
        return _client.query( _filesNS.c_str() , o , 0 , QueryOption_SlaveOk );
    }

////////////////////////////////////////////////////////////
// MyGridFile
////////////////////////////////////////////////////////////

    MyGridFile::MyGridFile(const MyGridFS * grid , const std::string files_id ) {
        _grid = grid;
        _files_id = files_id;
		BSONObj query = BSON("files_id" << _files_id);
		BSONObj o = _grid->_client.findOne( _grid->_chunksNS.c_str(), query, 0, QueryOption_SlaveOk );
		MyGridFSChunk chunk1 = MyGridFSChunk(o);
		_chunkSize = chunk1.len();
    }

    /**
     * @return whether any chunk of this file is on a server
     */
    bool MyGridFile::exists() const {
        BSONObjBuilder b;
        b.append( "files_id", _files_id );

        BSONObj o = _grid->_client.findOne( _grid->_chunksNS.c_str() , b.obj() , 0, QueryOption_SlaveOk );

        return !(o.isEmpty());
    }

    int MyGridFile::getChunkSize() const {
        return _chunkSize;
    }

    MyGridFSChunk MyGridFile::getChunk( int n ) const {
        _exists();
        BSONObjBuilder b;
        b.append( "files_id", _files_id );
        b.append( "n" , n );

        //BSONObj o = _grid->_client.findOne( _grid->_chunksNS.c_str() , b.obj() );
        BSONObj o = _grid->_client.findOne( _grid->_chunksNS.c_str() , b.obj() , 0, QueryOption_SlaveOk );
        uassert( 10014 ,  "chunk is empty!" , ! o.isEmpty() );
        return MyGridFSChunk(o);
    }

    /**
     * Unreliable
     */
    int MyGridFile::getNumChunks() const {
        BSONObj query = BSON("files_id" << _files_id);

        auto_ptr<DBClientCursor> c = _grid->_client.query( _grid->_chunksNS.c_str() , query , 0, QueryOption_SlaveOk );

        return c->itcount();
    }

    void MyGridFile::_exists() const {
        uassert( 10015 ,  "doesn't exists" , exists() );
    }

}
