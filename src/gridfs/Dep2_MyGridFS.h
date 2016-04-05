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

        /**
         * returns a file object matching the query
         */
        MyGridFile findFile( BSONObj query ) const;

        /**
         * equiv to findFile( { filename : filename } )
         */
        MyGridFile findFile( const string& fileName ) const;

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
        /**
         * @return whether or not this file exists
         * findFile will always return a GriFile, so need to check this
         */
        bool exists() const {
            return ! _obj.isEmpty();
        }

        string getFilename() const {
            return _obj["filename"].str();
        }

        int getChunkSize() const {
            return (int)(_obj["chunkSize"].number());
        }

        gridfs_offset getContentLength() const {
            return (gridfs_offset)(_obj["length"].number());
        }

        string getContentType() const {
            return _obj["contentType"].valuestr();
        }

        Date_t getUploadDate() const {
            return _obj["uploadDate"].date();
        }

        string getMD5() const {
            return _obj["md5"].str();
        }

        BSONElement getFileField( const string& name ) const {
            return _obj[name];
        }

        BSONObj getMetadata() const;

        int getNumChunks() const {
            return (int) ceil( (double)getContentLength() / (double)getChunkSize() );
        }

        MyGridFSChunk getChunk( int n ) const;

        /**
           write the file to the output stream
         */
        gridfs_offset write( ostream & out ) const;

        /**
           write the file to this filename
         */
        gridfs_offset write( const string& where ) const;

    private:
        MyGridFile(const MyGridFS * grid , BSONObj obj );

        void _exists() const;

        const MyGridFS * _grid;
        BSONObj        _obj;

        friend class MyGridFS;
    };
}
#endif /* GRIDFS_H_ */
