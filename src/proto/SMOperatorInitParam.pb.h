// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SMOperatorInitParam.proto

#ifndef PROTOBUF_SMOperatorInitParam_2eproto__INCLUDED
#define PROTOBUF_SMOperatorInitParam_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_SMOperatorInitParam_2eproto();
void protobuf_AssignDesc_SMOperatorInitParam_2eproto();
void protobuf_ShutdownFile_SMOperatorInitParam_2eproto();

class SearchRequest;
class GeneralKey;

enum SearchRequest_DataSourceImplType {
  SearchRequest_DataSourceImplType_REAL_TIME = 0,
  SearchRequest_DataSourceImplType_MONGO_GRIDFS = 1,
  SearchRequest_DataSourceImplType_HADOOPDFS = 2
};
bool SearchRequest_DataSourceImplType_IsValid(int value);
const SearchRequest_DataSourceImplType SearchRequest_DataSourceImplType_DataSourceImplType_MIN = SearchRequest_DataSourceImplType_REAL_TIME;
const SearchRequest_DataSourceImplType SearchRequest_DataSourceImplType_DataSourceImplType_MAX = SearchRequest_DataSourceImplType_HADOOPDFS;
const int SearchRequest_DataSourceImplType_DataSourceImplType_ARRAYSIZE = SearchRequest_DataSourceImplType_DataSourceImplType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SearchRequest_DataSourceImplType_descriptor();
inline const ::std::string& SearchRequest_DataSourceImplType_Name(SearchRequest_DataSourceImplType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SearchRequest_DataSourceImplType_descriptor(), value);
}
inline bool SearchRequest_DataSourceImplType_Parse(
    const ::std::string& name, SearchRequest_DataSourceImplType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SearchRequest_DataSourceImplType>(
    SearchRequest_DataSourceImplType_descriptor(), name, value);
}
enum SearchRequest_ReadPreferenceType {
  SearchRequest_ReadPreferenceType_READ_ALL = 0,
  SearchRequest_ReadPreferenceType_LIST_OF_KEYS = 1
};
bool SearchRequest_ReadPreferenceType_IsValid(int value);
const SearchRequest_ReadPreferenceType SearchRequest_ReadPreferenceType_ReadPreferenceType_MIN = SearchRequest_ReadPreferenceType_READ_ALL;
const SearchRequest_ReadPreferenceType SearchRequest_ReadPreferenceType_ReadPreferenceType_MAX = SearchRequest_ReadPreferenceType_LIST_OF_KEYS;
const int SearchRequest_ReadPreferenceType_ReadPreferenceType_ARRAYSIZE = SearchRequest_ReadPreferenceType_ReadPreferenceType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SearchRequest_ReadPreferenceType_descriptor();
inline const ::std::string& SearchRequest_ReadPreferenceType_Name(SearchRequest_ReadPreferenceType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SearchRequest_ReadPreferenceType_descriptor(), value);
}
inline bool SearchRequest_ReadPreferenceType_Parse(
    const ::std::string& name, SearchRequest_ReadPreferenceType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SearchRequest_ReadPreferenceType>(
    SearchRequest_ReadPreferenceType_descriptor(), name, value);
}
// ===================================================================

class SearchRequest : public ::google::protobuf::Message {
 public:
  SearchRequest();
  virtual ~SearchRequest();

  SearchRequest(const SearchRequest& from);

  inline SearchRequest& operator=(const SearchRequest& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SearchRequest& default_instance();

  void Swap(SearchRequest* other);

  // implements Message ----------------------------------------------

  SearchRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SearchRequest& from);
  void MergeFrom(const SearchRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  typedef SearchRequest_DataSourceImplType DataSourceImplType;
  static const DataSourceImplType REAL_TIME = SearchRequest_DataSourceImplType_REAL_TIME;
  static const DataSourceImplType MONGO_GRIDFS = SearchRequest_DataSourceImplType_MONGO_GRIDFS;
  static const DataSourceImplType HADOOPDFS = SearchRequest_DataSourceImplType_HADOOPDFS;
  static inline bool DataSourceImplType_IsValid(int value) {
    return SearchRequest_DataSourceImplType_IsValid(value);
  }
  static const DataSourceImplType DataSourceImplType_MIN =
    SearchRequest_DataSourceImplType_DataSourceImplType_MIN;
  static const DataSourceImplType DataSourceImplType_MAX =
    SearchRequest_DataSourceImplType_DataSourceImplType_MAX;
  static const int DataSourceImplType_ARRAYSIZE =
    SearchRequest_DataSourceImplType_DataSourceImplType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  DataSourceImplType_descriptor() {
    return SearchRequest_DataSourceImplType_descriptor();
  }
  static inline const ::std::string& DataSourceImplType_Name(DataSourceImplType value) {
    return SearchRequest_DataSourceImplType_Name(value);
  }
  static inline bool DataSourceImplType_Parse(const ::std::string& name,
      DataSourceImplType* value) {
    return SearchRequest_DataSourceImplType_Parse(name, value);
  }

  typedef SearchRequest_ReadPreferenceType ReadPreferenceType;
  static const ReadPreferenceType READ_ALL = SearchRequest_ReadPreferenceType_READ_ALL;
  static const ReadPreferenceType LIST_OF_KEYS = SearchRequest_ReadPreferenceType_LIST_OF_KEYS;
  static inline bool ReadPreferenceType_IsValid(int value) {
    return SearchRequest_ReadPreferenceType_IsValid(value);
  }
  static const ReadPreferenceType ReadPreferenceType_MIN =
    SearchRequest_ReadPreferenceType_ReadPreferenceType_MIN;
  static const ReadPreferenceType ReadPreferenceType_MAX =
    SearchRequest_ReadPreferenceType_ReadPreferenceType_MAX;
  static const int ReadPreferenceType_ARRAYSIZE =
    SearchRequest_ReadPreferenceType_ReadPreferenceType_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  ReadPreferenceType_descriptor() {
    return SearchRequest_ReadPreferenceType_descriptor();
  }
  static inline const ::std::string& ReadPreferenceType_Name(ReadPreferenceType value) {
    return SearchRequest_ReadPreferenceType_Name(value);
  }
  static inline bool ReadPreferenceType_Parse(const ::std::string& name,
      ReadPreferenceType* value) {
    return SearchRequest_ReadPreferenceType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required string host = 1;
  inline bool has_host() const;
  inline void clear_host();
  static const int kHostFieldNumber = 1;
  inline const ::std::string& host() const;
  inline void set_host(const ::std::string& value);
  inline void set_host(const char* value);
  inline void set_host(const char* value, size_t size);
  inline ::std::string* mutable_host();
  inline ::std::string* release_host();
  inline void set_allocated_host(::std::string* host);

  // required int32 port = 2;
  inline bool has_port() const;
  inline void clear_port();
  static const int kPortFieldNumber = 2;
  inline ::google::protobuf::int32 port() const;
  inline void set_port(::google::protobuf::int32 value);

  // optional string sourceName = 3;
  inline bool has_sourcename() const;
  inline void clear_sourcename();
  static const int kSourceNameFieldNumber = 3;
  inline const ::std::string& sourcename() const;
  inline void set_sourcename(const ::std::string& value);
  inline void set_sourcename(const char* value);
  inline void set_sourcename(const char* value, size_t size);
  inline ::std::string* mutable_sourcename();
  inline ::std::string* release_sourcename();
  inline void set_allocated_sourcename(::std::string* sourcename);

  // required .SearchRequest.DataSourceImplType dataSourceImplType = 4;
  inline bool has_datasourceimpltype() const;
  inline void clear_datasourceimpltype();
  static const int kDataSourceImplTypeFieldNumber = 4;
  inline ::SearchRequest_DataSourceImplType datasourceimpltype() const;
  inline void set_datasourceimpltype(::SearchRequest_DataSourceImplType value);

  // required .SearchRequest.ReadPreferenceType readPreferenceType = 5;
  inline bool has_readpreferencetype() const;
  inline void clear_readpreferencetype();
  static const int kReadPreferenceTypeFieldNumber = 5;
  inline ::SearchRequest_ReadPreferenceType readpreferencetype() const;
  inline void set_readpreferencetype(::SearchRequest_ReadPreferenceType value);

  // repeated .GeneralKey generalKeys = 6;
  inline int generalkeys_size() const;
  inline void clear_generalkeys();
  static const int kGeneralKeysFieldNumber = 6;
  inline const ::GeneralKey& generalkeys(int index) const;
  inline ::GeneralKey* mutable_generalkeys(int index);
  inline ::GeneralKey* add_generalkeys();
  inline const ::google::protobuf::RepeatedPtrField< ::GeneralKey >&
      generalkeys() const;
  inline ::google::protobuf::RepeatedPtrField< ::GeneralKey >*
      mutable_generalkeys();

  // optional int32 partitionKey = 7;
  inline bool has_partitionkey() const;
  inline void clear_partitionkey();
  static const int kPartitionKeyFieldNumber = 7;
  inline ::google::protobuf::int32 partitionkey() const;
  inline void set_partitionkey(::google::protobuf::int32 value);

  // optional int32 timeLimitMin = 8;
  inline bool has_timelimitmin() const;
  inline void clear_timelimitmin();
  static const int kTimeLimitMinFieldNumber = 8;
  inline ::google::protobuf::int32 timelimitmin() const;
  inline void set_timelimitmin(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:SearchRequest)
 private:
  inline void set_has_host();
  inline void clear_has_host();
  inline void set_has_port();
  inline void clear_has_port();
  inline void set_has_sourcename();
  inline void clear_has_sourcename();
  inline void set_has_datasourceimpltype();
  inline void clear_has_datasourceimpltype();
  inline void set_has_readpreferencetype();
  inline void clear_has_readpreferencetype();
  inline void set_has_partitionkey();
  inline void clear_has_partitionkey();
  inline void set_has_timelimitmin();
  inline void clear_has_timelimitmin();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* host_;
  ::std::string* sourcename_;
  ::google::protobuf::int32 port_;
  int datasourceimpltype_;
  ::google::protobuf::RepeatedPtrField< ::GeneralKey > generalkeys_;
  int readpreferencetype_;
  ::google::protobuf::int32 partitionkey_;
  ::google::protobuf::int32 timelimitmin_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_SMOperatorInitParam_2eproto();
  friend void protobuf_AssignDesc_SMOperatorInitParam_2eproto();
  friend void protobuf_ShutdownFile_SMOperatorInitParam_2eproto();

  void InitAsDefaultInstance();
  static SearchRequest* default_instance_;
};
// -------------------------------------------------------------------

class GeneralKey : public ::google::protobuf::Message {
 public:
  GeneralKey();
  virtual ~GeneralKey();

  GeneralKey(const GeneralKey& from);

  inline GeneralKey& operator=(const GeneralKey& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GeneralKey& default_instance();

  void Swap(GeneralKey* other);

  // implements Message ----------------------------------------------

  GeneralKey* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GeneralKey& from);
  void MergeFrom(const GeneralKey& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  inline void set_allocated_name(::std::string* name);

  // optional int64 first = 2;
  inline bool has_first() const;
  inline void clear_first();
  static const int kFirstFieldNumber = 2;
  inline ::google::protobuf::int64 first() const;
  inline void set_first(::google::protobuf::int64 value);

  // optional int64 last = 3;
  inline bool has_last() const;
  inline void clear_last();
  static const int kLastFieldNumber = 3;
  inline ::google::protobuf::int64 last() const;
  inline void set_last(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:GeneralKey)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_first();
  inline void clear_has_first();
  inline void set_has_last();
  inline void clear_has_last();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* name_;
  ::google::protobuf::int64 first_;
  ::google::protobuf::int64 last_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_SMOperatorInitParam_2eproto();
  friend void protobuf_AssignDesc_SMOperatorInitParam_2eproto();
  friend void protobuf_ShutdownFile_SMOperatorInitParam_2eproto();

  void InitAsDefaultInstance();
  static GeneralKey* default_instance_;
};
// ===================================================================


// ===================================================================

// SearchRequest

// required string host = 1;
inline bool SearchRequest::has_host() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SearchRequest::set_has_host() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SearchRequest::clear_has_host() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SearchRequest::clear_host() {
  if (host_ != &::google::protobuf::internal::kEmptyString) {
    host_->clear();
  }
  clear_has_host();
}
inline const ::std::string& SearchRequest::host() const {
  return *host_;
}
inline void SearchRequest::set_host(const ::std::string& value) {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  host_->assign(value);
}
inline void SearchRequest::set_host(const char* value) {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  host_->assign(value);
}
inline void SearchRequest::set_host(const char* value, size_t size) {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  host_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* SearchRequest::mutable_host() {
  set_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    host_ = new ::std::string;
  }
  return host_;
}
inline ::std::string* SearchRequest::release_host() {
  clear_has_host();
  if (host_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = host_;
    host_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void SearchRequest::set_allocated_host(::std::string* host) {
  if (host_ != &::google::protobuf::internal::kEmptyString) {
    delete host_;
  }
  if (host) {
    set_has_host();
    host_ = host;
  } else {
    clear_has_host();
    host_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required int32 port = 2;
inline bool SearchRequest::has_port() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SearchRequest::set_has_port() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SearchRequest::clear_has_port() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SearchRequest::clear_port() {
  port_ = 0;
  clear_has_port();
}
inline ::google::protobuf::int32 SearchRequest::port() const {
  return port_;
}
inline void SearchRequest::set_port(::google::protobuf::int32 value) {
  set_has_port();
  port_ = value;
}

// optional string sourceName = 3;
inline bool SearchRequest::has_sourcename() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SearchRequest::set_has_sourcename() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SearchRequest::clear_has_sourcename() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SearchRequest::clear_sourcename() {
  if (sourcename_ != &::google::protobuf::internal::kEmptyString) {
    sourcename_->clear();
  }
  clear_has_sourcename();
}
inline const ::std::string& SearchRequest::sourcename() const {
  return *sourcename_;
}
inline void SearchRequest::set_sourcename(const ::std::string& value) {
  set_has_sourcename();
  if (sourcename_ == &::google::protobuf::internal::kEmptyString) {
    sourcename_ = new ::std::string;
  }
  sourcename_->assign(value);
}
inline void SearchRequest::set_sourcename(const char* value) {
  set_has_sourcename();
  if (sourcename_ == &::google::protobuf::internal::kEmptyString) {
    sourcename_ = new ::std::string;
  }
  sourcename_->assign(value);
}
inline void SearchRequest::set_sourcename(const char* value, size_t size) {
  set_has_sourcename();
  if (sourcename_ == &::google::protobuf::internal::kEmptyString) {
    sourcename_ = new ::std::string;
  }
  sourcename_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* SearchRequest::mutable_sourcename() {
  set_has_sourcename();
  if (sourcename_ == &::google::protobuf::internal::kEmptyString) {
    sourcename_ = new ::std::string;
  }
  return sourcename_;
}
inline ::std::string* SearchRequest::release_sourcename() {
  clear_has_sourcename();
  if (sourcename_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = sourcename_;
    sourcename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void SearchRequest::set_allocated_sourcename(::std::string* sourcename) {
  if (sourcename_ != &::google::protobuf::internal::kEmptyString) {
    delete sourcename_;
  }
  if (sourcename) {
    set_has_sourcename();
    sourcename_ = sourcename;
  } else {
    clear_has_sourcename();
    sourcename_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required .SearchRequest.DataSourceImplType dataSourceImplType = 4;
inline bool SearchRequest::has_datasourceimpltype() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SearchRequest::set_has_datasourceimpltype() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SearchRequest::clear_has_datasourceimpltype() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SearchRequest::clear_datasourceimpltype() {
  datasourceimpltype_ = 0;
  clear_has_datasourceimpltype();
}
inline ::SearchRequest_DataSourceImplType SearchRequest::datasourceimpltype() const {
  return static_cast< ::SearchRequest_DataSourceImplType >(datasourceimpltype_);
}
inline void SearchRequest::set_datasourceimpltype(::SearchRequest_DataSourceImplType value) {
  assert(::SearchRequest_DataSourceImplType_IsValid(value));
  set_has_datasourceimpltype();
  datasourceimpltype_ = value;
}

// required .SearchRequest.ReadPreferenceType readPreferenceType = 5;
inline bool SearchRequest::has_readpreferencetype() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SearchRequest::set_has_readpreferencetype() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SearchRequest::clear_has_readpreferencetype() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SearchRequest::clear_readpreferencetype() {
  readpreferencetype_ = 0;
  clear_has_readpreferencetype();
}
inline ::SearchRequest_ReadPreferenceType SearchRequest::readpreferencetype() const {
  return static_cast< ::SearchRequest_ReadPreferenceType >(readpreferencetype_);
}
inline void SearchRequest::set_readpreferencetype(::SearchRequest_ReadPreferenceType value) {
  assert(::SearchRequest_ReadPreferenceType_IsValid(value));
  set_has_readpreferencetype();
  readpreferencetype_ = value;
}

// repeated .GeneralKey generalKeys = 6;
inline int SearchRequest::generalkeys_size() const {
  return generalkeys_.size();
}
inline void SearchRequest::clear_generalkeys() {
  generalkeys_.Clear();
}
inline const ::GeneralKey& SearchRequest::generalkeys(int index) const {
  return generalkeys_.Get(index);
}
inline ::GeneralKey* SearchRequest::mutable_generalkeys(int index) {
  return generalkeys_.Mutable(index);
}
inline ::GeneralKey* SearchRequest::add_generalkeys() {
  return generalkeys_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::GeneralKey >&
SearchRequest::generalkeys() const {
  return generalkeys_;
}
inline ::google::protobuf::RepeatedPtrField< ::GeneralKey >*
SearchRequest::mutable_generalkeys() {
  return &generalkeys_;
}

// optional int32 partitionKey = 7;
inline bool SearchRequest::has_partitionkey() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void SearchRequest::set_has_partitionkey() {
  _has_bits_[0] |= 0x00000040u;
}
inline void SearchRequest::clear_has_partitionkey() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void SearchRequest::clear_partitionkey() {
  partitionkey_ = 0;
  clear_has_partitionkey();
}
inline ::google::protobuf::int32 SearchRequest::partitionkey() const {
  return partitionkey_;
}
inline void SearchRequest::set_partitionkey(::google::protobuf::int32 value) {
  set_has_partitionkey();
  partitionkey_ = value;
}

// optional int32 timeLimitMin = 8;
inline bool SearchRequest::has_timelimitmin() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void SearchRequest::set_has_timelimitmin() {
  _has_bits_[0] |= 0x00000080u;
}
inline void SearchRequest::clear_has_timelimitmin() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void SearchRequest::clear_timelimitmin() {
  timelimitmin_ = 0;
  clear_has_timelimitmin();
}
inline ::google::protobuf::int32 SearchRequest::timelimitmin() const {
  return timelimitmin_;
}
inline void SearchRequest::set_timelimitmin(::google::protobuf::int32 value) {
  set_has_timelimitmin();
  timelimitmin_ = value;
}

// -------------------------------------------------------------------

// GeneralKey

// required string name = 1;
inline bool GeneralKey::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GeneralKey::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GeneralKey::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GeneralKey::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& GeneralKey::name() const {
  return *name_;
}
inline void GeneralKey::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void GeneralKey::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void GeneralKey::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* GeneralKey::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* GeneralKey::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void GeneralKey::set_allocated_name(::std::string* name) {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (name) {
    set_has_name();
    name_ = name;
  } else {
    clear_has_name();
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int64 first = 2;
inline bool GeneralKey::has_first() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void GeneralKey::set_has_first() {
  _has_bits_[0] |= 0x00000002u;
}
inline void GeneralKey::clear_has_first() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void GeneralKey::clear_first() {
  first_ = GOOGLE_LONGLONG(0);
  clear_has_first();
}
inline ::google::protobuf::int64 GeneralKey::first() const {
  return first_;
}
inline void GeneralKey::set_first(::google::protobuf::int64 value) {
  set_has_first();
  first_ = value;
}

// optional int64 last = 3;
inline bool GeneralKey::has_last() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void GeneralKey::set_has_last() {
  _has_bits_[0] |= 0x00000004u;
}
inline void GeneralKey::clear_has_last() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void GeneralKey::clear_last() {
  last_ = GOOGLE_LONGLONG(0);
  clear_has_last();
}
inline ::google::protobuf::int64 GeneralKey::last() const {
  return last_;
}
inline void GeneralKey::set_last(::google::protobuf::int64 value) {
  set_has_last();
  last_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SearchRequest_DataSourceImplType>() {
  return ::SearchRequest_DataSourceImplType_descriptor();
}
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SearchRequest_ReadPreferenceType>() {
  return ::SearchRequest_ReadPreferenceType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_SMOperatorInitParam_2eproto__INCLUDED
