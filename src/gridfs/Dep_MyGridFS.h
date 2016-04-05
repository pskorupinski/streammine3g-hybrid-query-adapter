/*
 * GridFS.h
 *
 *  Created on: Oct 23, 2012
 *      Author: ubuntu
 */

#ifndef GRIDFS_H_
#define GRIDFS_H_

#include <mongo/bson/bsonelement.h>
#include <mongo/bson/bsonobj.h>
#include <mongo/client/dbclientinterface.h>

#include <mongo/client/gridfs.h>

namespace mongo {

    typedef unsigned long long gridfs_offset;

    class MyGridFS;
    class MyGridFile;

    class MyGridFSChunk {
    	GridFSChunk orig;

    public:
        MyGridFSChunk( BSONObj data );
        MyGridFSChunk( BSONObj fileId , int chunkNumber , const char * data , int len );

        int len() const {
            return orig.len();
        }

        const char * data( int & len ) const {
            return orig.data(len);
        }
    };

    class MyGridFS {
    	GridFS orig;

    public:
        MyGridFS( DBClientBase& client , const string& dbName , const string& prefix="fs" );
        ~MyGridFS();

        void setChunkSize(unsigned int size);

        unsigned int getChunkSize() const;

        BSONObj storeFile( const string& fileName , const string& remoteName="" , const string& contentType="");

        BSONObj storeFile( const char* data , size_t length , const string& remoteName , const string& contentType="");

        void removeFile( const string& fileName );

        MyGridFile findFile( BSONObj query ) const;

        MyGridFile findFile( const string& fileName ) const;

        auto_ptr<DBClientCursor> list() const;

        auto_ptr<DBClientCursor> list( BSONObj query ) const;

    private:
        DBClientBase& _client;
        string _dbName;
        string _prefix;
        string _filesNS;
        string _chunksNS;
        unsigned int _chunkSize;

        BSONObj insertFile(const string& name, const OID& id, gridfs_offset length, const string& contentType);

        friend class MyGridFile;
    };

    class MyGridFile {
    	GridFile orig;

    public:
        bool exists() const {
            return orig.exists();
        }

        string getFilename() const {
            return orig.getFilename();
        }

        int getChunkSize() const {
            return orig.getChunkSize();
        }

        gridfs_offset getContentLength() const {
            return orig.getContentLength();
        }

        string getContentType() const {
            return orig.getContentType();
        }

        Date_t getUploadDate() const {
            return orig.getUploadDate();
        }

        string getMD5() const {
            return orig.getMD5();
        }

        BSONElement getFileField( const string& name ) const {
            return orig.getFileField(name);
        }

        BSONObj getMetadata() const;

        int getNumChunks() const {
            return orig.getNumChunks();
        }

        GridFSChunk getChunk( int n ) const;

        gridfs_offset write( ostream & out ) const;

        gridfs_offset write( const string& where ) const;

    private:
        MyGridFile(const GridFS * grid , BSONObj obj );

        void _exists() const;

        friend class MyGridFS;
    };
}
#endif /* GRIDFS_H_ */
