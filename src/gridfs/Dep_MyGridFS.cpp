/*
 * GridFS.cpp
 *
 *  Created on: Oct 23, 2012
 *      Author: ubuntu
 */


#include <pch.h>

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
        orig(o);
    }

    MyGridFSChunk::MyGridFSChunk( BSONObj fileObject , int chunkNumber , const char * data , int len ) {
        orig(fileObject, chunkNumber, data, len);
    }


    MyGridFS::MyGridFS( DBClientBase& client , const string& dbName , const string& prefix ) {
    	_client = client;
    	_dbName = dbName;
    	_prefix = prefix;

    	_filesNS = dbName + "." + prefix + ".files";
    	_chunksNS = dbName + "." + prefix + ".chunks";
    	_chunkSize = DEFAULT_CHUNK_SIZE;

    	client.ensureIndex( _filesNS , BSON( "filename" << 1 ) );
    	client.ensureIndex( _chunksNS , BSON( "files_id" << 1 << "n" << 1 ) );

        orig(client, dbName, prefix);
    }

    MyGridFS::~MyGridFS() {
    	delete orig;
    }

    void MyGridFS::setChunkSize(unsigned int size) {
        orig.setChunkSize(size);
    }

    unsigned int MyGridFS::getChunkSize() const {
        return orig.getChunkSize();
    }

    BSONObj MyGridFS::storeFile( const char* data , size_t length , const string& remoteName , const string& contentType) {
        return orig.storeFile( data , length , remoteName , contentType);
    }


    BSONObj MyGridFS::storeFile( const string& fileName , const string& remoteName , const string& contentType) {
        return orig.storeFile( fileName , remoteName , contentType);
    }

    BSONObj MyGridFS::insertFile(const string& name, const OID& id, gridfs_offset length, const string& contentType) {
        return orig.insertFile(name, id, length, contentType);
    }

    void MyGridFS::removeFile( const string& fileName ) {
        orig.removeFile( fileName );
    }

    MyGridFile::MyGridFile(const GridFS * grid , BSONObj obj ) {
        orig(grid, obj);
    }

    MyGridFile MyGridFS::findFile( const string& fileName ) const {
        return orig.findFile( fileName );
    };

    MyGridFile MyGridFS::findFile( BSONObj query ) const {
        return orig.findFile(query);
    }

    auto_ptr<DBClientCursor> MyGridFS::list() const {
    	bool slaveOk = 1;
        //return _client.query( _filesNS.c_str() , BSONObj() );
        return _client.query( _filesNS.c_str() , BSONObj() , 0 , slaveOk );
    }

    auto_ptr<DBClientCursor> MyGridFS::list( BSONObj o ) const {
    	bool slaveOk = 1;
    	//return _client.query( _filesNS.c_str() , o );
        return _client.query( _filesNS.c_str() , o , 0 , slaveOk );
    }

    BSONObj MyGridFile::getMetadata() const {
        return orig.getMetadata();
    }

    GridFSChunk MyGridFile::getChunk( int n ) const {
        _exists();
        BSONObjBuilder b;
        b.appendAs( _obj["_id"] , "files_id" );
        b.append( "n" , n );

        std::cout << "GRIDFS EDITED." << std::endl;

		/* add a flag of slaveOk */
		bool slaveOk = 1;

        //BSONObj o = _grid->_client.findOne( _grid->_chunksNS.c_str() , b.obj() );
        BSONObj o; // = _grid->_client.findOne( _grid->_chunksNS.c_str() , b.obj() , 0, slaveOk );
        uassert( 10014 ,  "chunk is empty!" , ! o.isEmpty() );
        return GridFSChunk(o);
    }

    gridfs_offset MyGridFile::write( ostream & out ) const {
        return orig.write(out);
    }

    gridfs_offset MyGridFile::write( const string& where ) const {
        return orig.write(where);
    }

    void MyGridFile::_exists() const {
        orig._exists();
    }

}
