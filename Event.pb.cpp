#include "src/GPBPatch.hpp"
// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Event.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Financial {

namespace {

const ::google::protobuf::Descriptor* Event_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Event_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Event_2eproto() {
  protobuf_AddDesc_Event_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Event.proto");
  GOOGLE_CHECK(file != NULL);
  Event_descriptor_ = file->message_type(0);
  static const int Event_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, stockid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, tick_),
  };
  Event_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Event_descriptor_,
      Event::default_instance_,
      Event_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Event, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Event));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Event_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Event_descriptor_, &Event::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Event_2eproto() {
  delete Event::default_instance_;
  delete Event_reflection_;
}

void protobuf_AddDesc_Event_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013Event.proto\022\tFinancial\"9\n\005Event\022\021\n\ttim"
    "estamp\030\001 \002(\003\022\017\n\007stockId\030\002 \002(\005\022\014\n\004tick\030\003 "
    "\002(\005B)\n\030streammine3G.example.msgB\013EventFo"
    "rmatH\001", 126);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Event.proto", &protobuf_RegisterTypes);
  Event::default_instance_ = new Event();
  Event::default_instance_->InitAsDefaultInstance();
  GPBPatch::InitShutdownFunctions();GPBPatch::OnShutdown(&protobuf_ShutdownFile_Event_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Event_2eproto {
  StaticDescriptorInitializer_Event_2eproto() {
    protobuf_AddDesc_Event_2eproto();
  }
} static_descriptor_initializer_Event_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int Event::kTimestampFieldNumber;
const int Event::kStockIdFieldNumber;
const int Event::kTickFieldNumber;
#endif  // !_MSC_VER

Event::Event()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void Event::InitAsDefaultInstance() {
}

Event::Event(const Event& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void Event::SharedCtor() {
  _cached_size_ = 0;
  timestamp_ = GOOGLE_LONGLONG(0);
  stockid_ = 0;
  tick_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Event::~Event() {
  SharedDtor();
}

void Event::SharedDtor() {
  if (this != default_instance_) {
  }
}

void Event::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Event::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Event_descriptor_;
}

const Event& Event::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Event_2eproto();  return *default_instance_;
}

Event* Event::default_instance_ = NULL;

Event* Event::New() const {
  return new Event;
}

void Event::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    timestamp_ = GOOGLE_LONGLONG(0);
    stockid_ = 0;
    tick_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Event::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 timestamp = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &timestamp_)));
          set_has_timestamp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_stockId;
        break;
      }
      
      // required int32 stockId = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_stockId:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &stockid_)));
          set_has_stockid();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_tick;
        break;
      }
      
      // required int32 tick = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_tick:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &tick_)));
          set_has_tick();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void Event::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int64 timestamp = 1;
  if (has_timestamp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->timestamp(), output);
  }
  
  // required int32 stockId = 2;
  if (has_stockid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->stockid(), output);
  }
  
  // required int32 tick = 3;
  if (has_tick()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->tick(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* Event::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int64 timestamp = 1;
  if (has_timestamp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->timestamp(), target);
  }
  
  // required int32 stockId = 2;
  if (has_stockid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->stockid(), target);
  }
  
  // required int32 tick = 3;
  if (has_tick()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->tick(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int Event::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 timestamp = 1;
    if (has_timestamp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->timestamp());
    }
    
    // required int32 stockId = 2;
    if (has_stockid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->stockid());
    }
    
    // required int32 tick = 3;
    if (has_tick()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->tick());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Event::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Event* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Event*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Event::MergeFrom(const Event& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_timestamp()) {
      set_timestamp(from.timestamp());
    }
    if (from.has_stockid()) {
      set_stockid(from.stockid());
    }
    if (from.has_tick()) {
      set_tick(from.tick());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Event::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Event::CopyFrom(const Event& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Event::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000007) != 0x00000007) return false;
  
  return true;
}

void Event::Swap(Event* other) {
  if (other != this) {
    std::swap(timestamp_, other->timestamp_);
    std::swap(stockid_, other->stockid_);
    std::swap(tick_, other->tick_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Event::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Event_descriptor_;
  metadata.reflection = Event_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Financial

// @@protoc_insertion_point(global_scope)
