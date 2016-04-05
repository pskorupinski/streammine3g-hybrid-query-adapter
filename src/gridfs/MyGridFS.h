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

namespace mongo {

    typedef unsigned long long gridfs_offset;

    class MyGridFS;
    class MyGridFile;

    class MyGridFSChunk {
    public:
        MyGridFSChunk( BSONObj data );
        MyGridFSChunk( BSONObj fileId , int chunkNumber , const char * data , int len );

        int len() const {
            int len;
            _data["data"].binDataClean( len );
            return len;
        }

        const char * data( int & len ) const {
            return _data["data"].binDataClean( len );
        }

    private:
        BSONObj _data;
        friend class MyGridFS;
    };


    /**
      GridFS is for storing large file-style objects in MongoDB.
      @see http://dochub.mongodb.org/core/gridfsspec
     */
    class MyGridFS {
    public:
        /**
         * @param client - db connection
         * @param dbName - root database name
         * @param prefix - if you want your data somewhere besides <dbname>.fs
         */
        MyGridFS( DBClientBase& client , const string& dbName , const string& prefix="fs" );
        ~MyGridFS();

        /**
         * @param
         */
        void setChunkSize(unsigned int size);

        unsigned int getChunkSize() const;

        /**
         * puts the file reference by fileName into the db
         * @param fileName local filename relative to process
         * @param remoteName optional filename to use for file stored in GridFS
         *                   (default is to use fileName parameter)
         * @param contentType optional MIME type for this object.
         *                    (default is to omit)
         * @return the file object
         */
        BSONObj storeFile( const string& fileName , const string& remoteName="" , const string& contentType="");

        /**
         * puts the file represented by data into the db
         * @param data pointer to buffer to store in GridFS
         * @param length length of buffer
         * @param remoteName optional filename to use for file stored in GridFS
         *                   (default is to use fileName parameter)
         * @param contentType optional MIME type for this object.
         *                    (default is to omit)
         * @return the file object
         */
        BSONObj storeFile( const char* data , size_t length , const string& remoteName , const string& contentType="");

        /**
         * removes file referenced by fileName from the db
         * @param fileName filename (in GridFS) of the file to remove
         * @return the file object
         */
        void removeFile( const string& fileName );

        MyGridFile findFile( const std::string& key ) const;

        /**
         * convenience method to get all the files
         */
        auto_ptr<DBClientCursor> list() const;

        /**
         * convenience method to get all the files with a filter
         */
        auto_ptr<DBClientCursor> list( BSONObj query ) const;

    private:
        DBClientBase& _client;
        string _dbName;
        string _prefix;
        string _filesNS;
        string _chunksNS;
        unsigned int _chunkSize;

        // insert fileobject. All chunks must be in DB.
        BSONObj insertFile(const string& name, const OID& id, gridfs_offset length, const string& contentType);

        friend class MyGridFile;
    };

    /**
       wrapper for a file stored in the Mongo database
     */
    class MyGridFile {
    public:

        bool exists() const;
        int getChunkSize() const;
        MyGridFSChunk getChunk( int n ) const;
        int getNumChunks() const;

        string getFilename() const {
            return _files_id;
        }

    private:
        MyGridFile(const MyGridFS * grid , const std::string files_id );

        void _exists() const;

        const MyGridFS * _grid;
        std::string _files_id;
        int _chunkSize;

        friend class MyGridFS;
    };
}
#endif /* GRIDFS_H_ */
