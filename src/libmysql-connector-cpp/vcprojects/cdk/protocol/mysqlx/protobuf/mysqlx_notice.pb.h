// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mysqlx_notice.proto

#ifndef PROTOBUF_mysqlx_5fnotice_2eproto__INCLUDED
#define PROTOBUF_mysqlx_5fnotice_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include "mysqlx_datatypes.pb.h"
// @@protoc_insertion_point(includes)

namespace Mysqlx {
namespace Notice {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_mysqlx_5fnotice_2eproto();
void protobuf_AssignDesc_mysqlx_5fnotice_2eproto();
void protobuf_ShutdownFile_mysqlx_5fnotice_2eproto();

class Frame;
class Warning;
class SessionVariableChanged;
class SessionStateChanged;

enum Frame_Scope {
  Frame_Scope_GLOBAL = 1,
  Frame_Scope_LOCAL = 2
};
bool Frame_Scope_IsValid(int value);
const Frame_Scope Frame_Scope_Scope_MIN = Frame_Scope_GLOBAL;
const Frame_Scope Frame_Scope_Scope_MAX = Frame_Scope_LOCAL;
const int Frame_Scope_Scope_ARRAYSIZE = Frame_Scope_Scope_MAX + 1;

enum Frame_Type {
  Frame_Type_WARNING = 1,
  Frame_Type_SESSION_VARIABLE_CHANGED = 2,
  Frame_Type_SESSION_STATE_CHANGED = 3
};
bool Frame_Type_IsValid(int value);
const Frame_Type Frame_Type_Type_MIN = Frame_Type_WARNING;
const Frame_Type Frame_Type_Type_MAX = Frame_Type_SESSION_STATE_CHANGED;
const int Frame_Type_Type_ARRAYSIZE = Frame_Type_Type_MAX + 1;

enum Warning_Level {
  Warning_Level_NOTE = 1,
  Warning_Level_WARNING = 2,
  Warning_Level_ERROR = 3
};
bool Warning_Level_IsValid(int value);
const Warning_Level Warning_Level_Level_MIN = Warning_Level_NOTE;
const Warning_Level Warning_Level_Level_MAX = Warning_Level_ERROR;
const int Warning_Level_Level_ARRAYSIZE = Warning_Level_Level_MAX + 1;

enum SessionStateChanged_Parameter {
  SessionStateChanged_Parameter_CURRENT_SCHEMA = 1,
  SessionStateChanged_Parameter_ACCOUNT_EXPIRED = 2,
  SessionStateChanged_Parameter_GENERATED_INSERT_ID = 3,
  SessionStateChanged_Parameter_ROWS_AFFECTED = 4,
  SessionStateChanged_Parameter_ROWS_FOUND = 5,
  SessionStateChanged_Parameter_ROWS_MATCHED = 6,
  SessionStateChanged_Parameter_TRX_COMMITTED = 7,
  SessionStateChanged_Parameter_TRX_ROLLEDBACK = 9,
  SessionStateChanged_Parameter_PRODUCED_MESSAGE = 10,
  SessionStateChanged_Parameter_CLIENT_ID_ASSIGNED = 11,
  SessionStateChanged_Parameter_GENERATED_DOCUMENT_IDS = 12
};
bool SessionStateChanged_Parameter_IsValid(int value);
const SessionStateChanged_Parameter SessionStateChanged_Parameter_Parameter_MIN = SessionStateChanged_Parameter_CURRENT_SCHEMA;
const SessionStateChanged_Parameter SessionStateChanged_Parameter_Parameter_MAX = SessionStateChanged_Parameter_GENERATED_DOCUMENT_IDS;
const int SessionStateChanged_Parameter_Parameter_ARRAYSIZE = SessionStateChanged_Parameter_Parameter_MAX + 1;

// ===================================================================

class Frame : public ::google::protobuf::MessageLite {
 public:
  Frame();
  virtual ~Frame();

  Frame(const Frame& from);

  inline Frame& operator=(const Frame& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const Frame& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Frame* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Frame* other);

  // implements Message ----------------------------------------------

  Frame* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Frame& from);
  void MergeFrom(const Frame& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  typedef Frame_Scope Scope;
  static const Scope GLOBAL = Frame_Scope_GLOBAL;
  static const Scope LOCAL = Frame_Scope_LOCAL;
  static inline bool Scope_IsValid(int value) {
    return Frame_Scope_IsValid(value);
  }
  static const Scope Scope_MIN =
    Frame_Scope_Scope_MIN;
  static const Scope Scope_MAX =
    Frame_Scope_Scope_MAX;
  static const int Scope_ARRAYSIZE =
    Frame_Scope_Scope_ARRAYSIZE;

  typedef Frame_Type Type;
  static const Type WARNING = Frame_Type_WARNING;
  static const Type SESSION_VARIABLE_CHANGED = Frame_Type_SESSION_VARIABLE_CHANGED;
  static const Type SESSION_STATE_CHANGED = Frame_Type_SESSION_STATE_CHANGED;
  static inline bool Type_IsValid(int value) {
    return Frame_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Frame_Type_Type_MIN;
  static const Type Type_MAX =
    Frame_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Frame_Type_Type_ARRAYSIZE;

  // accessors -------------------------------------------------------

  // required uint32 type = 1;
  inline bool has_type() const;
  inline void clear_type();
  static const int kTypeFieldNumber = 1;
  inline ::google::protobuf::uint32 type() const;
  inline void set_type(::google::protobuf::uint32 value);

  // optional .Mysqlx.Notice.Frame.Scope scope = 2 [default = GLOBAL];
  inline bool has_scope() const;
  inline void clear_scope();
  static const int kScopeFieldNumber = 2;
  inline ::Mysqlx::Notice::Frame_Scope scope() const;
  inline void set_scope(::Mysqlx::Notice::Frame_Scope value);

  // optional bytes payload = 3;
  inline bool has_payload() const;
  inline void clear_payload();
  static const int kPayloadFieldNumber = 3;
  inline const ::std::string& payload() const;
  inline void set_payload(const ::std::string& value);
  inline void set_payload(const char* value);
  inline void set_payload(const void* value, size_t size);
  inline ::std::string* mutable_payload();
  inline ::std::string* release_payload();
  inline void set_allocated_payload(::std::string* payload);

  // @@protoc_insertion_point(class_scope:Mysqlx.Notice.Frame)
 private:
  inline void set_has_type();
  inline void clear_has_type();
  inline void set_has_scope();
  inline void clear_has_scope();
  inline void set_has_payload();
  inline void clear_has_payload();

  ::std::string _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 type_;
  int scope_;
  ::std::string* payload_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto();
  #endif
  friend void protobuf_AssignDesc_mysqlx_5fnotice_2eproto();
  friend void protobuf_ShutdownFile_mysqlx_5fnotice_2eproto();

  void InitAsDefaultInstance();
  static Frame* default_instance_;
};
// -------------------------------------------------------------------

class Warning : public ::google::protobuf::MessageLite {
 public:
  Warning();
  virtual ~Warning();

  Warning(const Warning& from);

  inline Warning& operator=(const Warning& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const Warning& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const Warning* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(Warning* other);

  // implements Message ----------------------------------------------

  Warning* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const Warning& from);
  void MergeFrom(const Warning& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  typedef Warning_Level Level;
  static const Level NOTE = Warning_Level_NOTE;
  static const Level WARNING = Warning_Level_WARNING;
  static const Level ERROR = Warning_Level_ERROR;
  static inline bool Level_IsValid(int value) {
    return Warning_Level_IsValid(value);
  }
  static const Level Level_MIN =
    Warning_Level_Level_MIN;
  static const Level Level_MAX =
    Warning_Level_Level_MAX;
  static const int Level_ARRAYSIZE =
    Warning_Level_Level_ARRAYSIZE;

  // accessors -------------------------------------------------------

  // optional .Mysqlx.Notice.Warning.Level level = 1 [default = WARNING];
  inline bool has_level() const;
  inline void clear_level();
  static const int kLevelFieldNumber = 1;
  inline ::Mysqlx::Notice::Warning_Level level() const;
  inline void set_level(::Mysqlx::Notice::Warning_Level value);

  // required uint32 code = 2;
  inline bool has_code() const;
  inline void clear_code();
  static const int kCodeFieldNumber = 2;
  inline ::google::protobuf::uint32 code() const;
  inline void set_code(::google::protobuf::uint32 value);

  // required string msg = 3;
  inline bool has_msg() const;
  inline void clear_msg();
  static const int kMsgFieldNumber = 3;
  inline const ::std::string& msg() const;
  inline void set_msg(const ::std::string& value);
  inline void set_msg(const char* value);
  inline void set_msg(const char* value, size_t size);
  inline ::std::string* mutable_msg();
  inline ::std::string* release_msg();
  inline void set_allocated_msg(::std::string* msg);

  // @@protoc_insertion_point(class_scope:Mysqlx.Notice.Warning)
 private:
  inline void set_has_level();
  inline void clear_has_level();
  inline void set_has_code();
  inline void clear_has_code();
  inline void set_has_msg();
  inline void clear_has_msg();

  ::std::string _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  int level_;
  ::google::protobuf::uint32 code_;
  ::std::string* msg_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto();
  #endif
  friend void protobuf_AssignDesc_mysqlx_5fnotice_2eproto();
  friend void protobuf_ShutdownFile_mysqlx_5fnotice_2eproto();

  void InitAsDefaultInstance();
  static Warning* default_instance_;
};
// -------------------------------------------------------------------

class SessionVariableChanged : public ::google::protobuf::MessageLite {
 public:
  SessionVariableChanged();
  virtual ~SessionVariableChanged();

  SessionVariableChanged(const SessionVariableChanged& from);

  inline SessionVariableChanged& operator=(const SessionVariableChanged& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const SessionVariableChanged& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const SessionVariableChanged* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(SessionVariableChanged* other);

  // implements Message ----------------------------------------------

  SessionVariableChanged* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const SessionVariableChanged& from);
  void MergeFrom(const SessionVariableChanged& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string param = 1;
  inline bool has_param() const;
  inline void clear_param();
  static const int kParamFieldNumber = 1;
  inline const ::std::string& param() const;
  inline void set_param(const ::std::string& value);
  inline void set_param(const char* value);
  inline void set_param(const char* value, size_t size);
  inline ::std::string* mutable_param();
  inline ::std::string* release_param();
  inline void set_allocated_param(::std::string* param);

  // optional .Mysqlx.Datatypes.Scalar value = 2;
  inline bool has_value() const;
  inline void clear_value();
  static const int kValueFieldNumber = 2;
  inline const ::Mysqlx::Datatypes::Scalar& value() const;
  inline ::Mysqlx::Datatypes::Scalar* mutable_value();
  inline ::Mysqlx::Datatypes::Scalar* release_value();
  inline void set_allocated_value(::Mysqlx::Datatypes::Scalar* value);

  // @@protoc_insertion_point(class_scope:Mysqlx.Notice.SessionVariableChanged)
 private:
  inline void set_has_param();
  inline void clear_has_param();
  inline void set_has_value();
  inline void clear_has_value();

  ::std::string _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* param_;
  ::Mysqlx::Datatypes::Scalar* value_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto();
  #endif
  friend void protobuf_AssignDesc_mysqlx_5fnotice_2eproto();
  friend void protobuf_ShutdownFile_mysqlx_5fnotice_2eproto();

  void InitAsDefaultInstance();
  static SessionVariableChanged* default_instance_;
};
// -------------------------------------------------------------------

class SessionStateChanged : public ::google::protobuf::MessageLite {
 public:
  SessionStateChanged();
  virtual ~SessionStateChanged();

  SessionStateChanged(const SessionStateChanged& from);

  inline SessionStateChanged& operator=(const SessionStateChanged& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::std::string& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::std::string* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const SessionStateChanged& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const SessionStateChanged* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(SessionStateChanged* other);

  // implements Message ----------------------------------------------

  SessionStateChanged* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const SessionStateChanged& from);
  void MergeFrom(const SessionStateChanged& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  void DiscardUnknownFields();
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  typedef SessionStateChanged_Parameter Parameter;
  static const Parameter CURRENT_SCHEMA = SessionStateChanged_Parameter_CURRENT_SCHEMA;
  static const Parameter ACCOUNT_EXPIRED = SessionStateChanged_Parameter_ACCOUNT_EXPIRED;
  static const Parameter GENERATED_INSERT_ID = SessionStateChanged_Parameter_GENERATED_INSERT_ID;
  static const Parameter ROWS_AFFECTED = SessionStateChanged_Parameter_ROWS_AFFECTED;
  static const Parameter ROWS_FOUND = SessionStateChanged_Parameter_ROWS_FOUND;
  static const Parameter ROWS_MATCHED = SessionStateChanged_Parameter_ROWS_MATCHED;
  static const Parameter TRX_COMMITTED = SessionStateChanged_Parameter_TRX_COMMITTED;
  static const Parameter TRX_ROLLEDBACK = SessionStateChanged_Parameter_TRX_ROLLEDBACK;
  static const Parameter PRODUCED_MESSAGE = SessionStateChanged_Parameter_PRODUCED_MESSAGE;
  static const Parameter CLIENT_ID_ASSIGNED = SessionStateChanged_Parameter_CLIENT_ID_ASSIGNED;
  static const Parameter GENERATED_DOCUMENT_IDS = SessionStateChanged_Parameter_GENERATED_DOCUMENT_IDS;
  static inline bool Parameter_IsValid(int value) {
    return SessionStateChanged_Parameter_IsValid(value);
  }
  static const Parameter Parameter_MIN =
    SessionStateChanged_Parameter_Parameter_MIN;
  static const Parameter Parameter_MAX =
    SessionStateChanged_Parameter_Parameter_MAX;
  static const int Parameter_ARRAYSIZE =
    SessionStateChanged_Parameter_Parameter_ARRAYSIZE;

  // accessors -------------------------------------------------------

  // required .Mysqlx.Notice.SessionStateChanged.Parameter param = 1;
  inline bool has_param() const;
  inline void clear_param();
  static const int kParamFieldNumber = 1;
  inline ::Mysqlx::Notice::SessionStateChanged_Parameter param() const;
  inline void set_param(::Mysqlx::Notice::SessionStateChanged_Parameter value);

  // repeated .Mysqlx.Datatypes.Scalar value = 2;
  inline int value_size() const;
  inline void clear_value();
  static const int kValueFieldNumber = 2;
  inline const ::Mysqlx::Datatypes::Scalar& value(int index) const;
  inline ::Mysqlx::Datatypes::Scalar* mutable_value(int index);
  inline ::Mysqlx::Datatypes::Scalar* add_value();
  inline const ::google::protobuf::RepeatedPtrField< ::Mysqlx::Datatypes::Scalar >&
      value() const;
  inline ::google::protobuf::RepeatedPtrField< ::Mysqlx::Datatypes::Scalar >*
      mutable_value();

  // @@protoc_insertion_point(class_scope:Mysqlx.Notice.SessionStateChanged)
 private:
  inline void set_has_param();
  inline void clear_has_param();

  ::std::string _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Mysqlx::Datatypes::Scalar > value_;
  int param_;
  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_mysqlx_5fnotice_2eproto();
  #endif
  friend void protobuf_AssignDesc_mysqlx_5fnotice_2eproto();
  friend void protobuf_ShutdownFile_mysqlx_5fnotice_2eproto();

  void InitAsDefaultInstance();
  static SessionStateChanged* default_instance_;
};
// ===================================================================


// ===================================================================

// Frame

// required uint32 type = 1;
inline bool Frame::has_type() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Frame::set_has_type() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Frame::clear_has_type() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Frame::clear_type() {
  type_ = 0u;
  clear_has_type();
}
inline ::google::protobuf::uint32 Frame::type() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.Frame.type)
  return type_;
}
inline void Frame::set_type(::google::protobuf::uint32 value) {
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.Frame.type)
}

// optional .Mysqlx.Notice.Frame.Scope scope = 2 [default = GLOBAL];
inline bool Frame::has_scope() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Frame::set_has_scope() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Frame::clear_has_scope() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Frame::clear_scope() {
  scope_ = 1;
  clear_has_scope();
}
inline ::Mysqlx::Notice::Frame_Scope Frame::scope() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.Frame.scope)
  return static_cast< ::Mysqlx::Notice::Frame_Scope >(scope_);
}
inline void Frame::set_scope(::Mysqlx::Notice::Frame_Scope value) {
  assert(::Mysqlx::Notice::Frame_Scope_IsValid(value));
  set_has_scope();
  scope_ = value;
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.Frame.scope)
}

// optional bytes payload = 3;
inline bool Frame::has_payload() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Frame::set_has_payload() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Frame::clear_has_payload() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Frame::clear_payload() {
  if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    payload_->clear();
  }
  clear_has_payload();
}
inline const ::std::string& Frame::payload() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.Frame.payload)
  return *payload_;
}
inline void Frame::set_payload(const ::std::string& value) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    payload_ = new ::std::string;
  }
  payload_->assign(value);
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.Frame.payload)
}
inline void Frame::set_payload(const char* value) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    payload_ = new ::std::string;
  }
  payload_->assign(value);
  // @@protoc_insertion_point(field_set_char:Mysqlx.Notice.Frame.payload)
}
inline void Frame::set_payload(const void* value, size_t size) {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    payload_ = new ::std::string;
  }
  payload_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Mysqlx.Notice.Frame.payload)
}
inline ::std::string* Frame::mutable_payload() {
  set_has_payload();
  if (payload_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    payload_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Mysqlx.Notice.Frame.payload)
  return payload_;
}
inline ::std::string* Frame::release_payload() {
  clear_has_payload();
  if (payload_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = payload_;
    payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Frame::set_allocated_payload(::std::string* payload) {
  if (payload_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete payload_;
  }
  if (payload) {
    set_has_payload();
    payload_ = payload;
  } else {
    clear_has_payload();
    payload_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Mysqlx.Notice.Frame.payload)
}

// -------------------------------------------------------------------

// Warning

// optional .Mysqlx.Notice.Warning.Level level = 1 [default = WARNING];
inline bool Warning::has_level() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Warning::set_has_level() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Warning::clear_has_level() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Warning::clear_level() {
  level_ = 2;
  clear_has_level();
}
inline ::Mysqlx::Notice::Warning_Level Warning::level() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.Warning.level)
  return static_cast< ::Mysqlx::Notice::Warning_Level >(level_);
}
inline void Warning::set_level(::Mysqlx::Notice::Warning_Level value) {
  assert(::Mysqlx::Notice::Warning_Level_IsValid(value));
  set_has_level();
  level_ = value;
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.Warning.level)
}

// required uint32 code = 2;
inline bool Warning::has_code() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Warning::set_has_code() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Warning::clear_has_code() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Warning::clear_code() {
  code_ = 0u;
  clear_has_code();
}
inline ::google::protobuf::uint32 Warning::code() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.Warning.code)
  return code_;
}
inline void Warning::set_code(::google::protobuf::uint32 value) {
  set_has_code();
  code_ = value;
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.Warning.code)
}

// required string msg = 3;
inline bool Warning::has_msg() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Warning::set_has_msg() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Warning::clear_has_msg() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Warning::clear_msg() {
  if (msg_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    msg_->clear();
  }
  clear_has_msg();
}
inline const ::std::string& Warning::msg() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.Warning.msg)
  return *msg_;
}
inline void Warning::set_msg(const ::std::string& value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.Warning.msg)
}
inline void Warning::set_msg(const char* value) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    msg_ = new ::std::string;
  }
  msg_->assign(value);
  // @@protoc_insertion_point(field_set_char:Mysqlx.Notice.Warning.msg)
}
inline void Warning::set_msg(const char* value, size_t size) {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    msg_ = new ::std::string;
  }
  msg_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Mysqlx.Notice.Warning.msg)
}
inline ::std::string* Warning::mutable_msg() {
  set_has_msg();
  if (msg_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    msg_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Mysqlx.Notice.Warning.msg)
  return msg_;
}
inline ::std::string* Warning::release_msg() {
  clear_has_msg();
  if (msg_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = msg_;
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Warning::set_allocated_msg(::std::string* msg) {
  if (msg_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete msg_;
  }
  if (msg) {
    set_has_msg();
    msg_ = msg;
  } else {
    clear_has_msg();
    msg_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Mysqlx.Notice.Warning.msg)
}

// -------------------------------------------------------------------

// SessionVariableChanged

// required string param = 1;
inline bool SessionVariableChanged::has_param() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SessionVariableChanged::set_has_param() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SessionVariableChanged::clear_has_param() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SessionVariableChanged::clear_param() {
  if (param_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    param_->clear();
  }
  clear_has_param();
}
inline const ::std::string& SessionVariableChanged::param() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.SessionVariableChanged.param)
  return *param_;
}
inline void SessionVariableChanged::set_param(const ::std::string& value) {
  set_has_param();
  if (param_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    param_ = new ::std::string;
  }
  param_->assign(value);
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.SessionVariableChanged.param)
}
inline void SessionVariableChanged::set_param(const char* value) {
  set_has_param();
  if (param_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    param_ = new ::std::string;
  }
  param_->assign(value);
  // @@protoc_insertion_point(field_set_char:Mysqlx.Notice.SessionVariableChanged.param)
}
inline void SessionVariableChanged::set_param(const char* value, size_t size) {
  set_has_param();
  if (param_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    param_ = new ::std::string;
  }
  param_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Mysqlx.Notice.SessionVariableChanged.param)
}
inline ::std::string* SessionVariableChanged::mutable_param() {
  set_has_param();
  if (param_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    param_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:Mysqlx.Notice.SessionVariableChanged.param)
  return param_;
}
inline ::std::string* SessionVariableChanged::release_param() {
  clear_has_param();
  if (param_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = param_;
    param_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void SessionVariableChanged::set_allocated_param(::std::string* param) {
  if (param_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete param_;
  }
  if (param) {
    set_has_param();
    param_ = param;
  } else {
    clear_has_param();
    param_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:Mysqlx.Notice.SessionVariableChanged.param)
}

// optional .Mysqlx.Datatypes.Scalar value = 2;
inline bool SessionVariableChanged::has_value() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SessionVariableChanged::set_has_value() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SessionVariableChanged::clear_has_value() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SessionVariableChanged::clear_value() {
  if (value_ != NULL) value_->::Mysqlx::Datatypes::Scalar::Clear();
  clear_has_value();
}
inline const ::Mysqlx::Datatypes::Scalar& SessionVariableChanged::value() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.SessionVariableChanged.value)
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  return value_ != NULL ? *value_ : *default_instance().value_;
#else
  return value_ != NULL ? *value_ : *default_instance_->value_;
#endif
}
inline ::Mysqlx::Datatypes::Scalar* SessionVariableChanged::mutable_value() {
  set_has_value();
  if (value_ == NULL) value_ = new ::Mysqlx::Datatypes::Scalar;
  // @@protoc_insertion_point(field_mutable:Mysqlx.Notice.SessionVariableChanged.value)
  return value_;
}
inline ::Mysqlx::Datatypes::Scalar* SessionVariableChanged::release_value() {
  clear_has_value();
  ::Mysqlx::Datatypes::Scalar* temp = value_;
  value_ = NULL;
  return temp;
}
inline void SessionVariableChanged::set_allocated_value(::Mysqlx::Datatypes::Scalar* value) {
  delete value_;
  value_ = value;
  if (value) {
    set_has_value();
  } else {
    clear_has_value();
  }
  // @@protoc_insertion_point(field_set_allocated:Mysqlx.Notice.SessionVariableChanged.value)
}

// -------------------------------------------------------------------

// SessionStateChanged

// required .Mysqlx.Notice.SessionStateChanged.Parameter param = 1;
inline bool SessionStateChanged::has_param() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SessionStateChanged::set_has_param() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SessionStateChanged::clear_has_param() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SessionStateChanged::clear_param() {
  param_ = 1;
  clear_has_param();
}
inline ::Mysqlx::Notice::SessionStateChanged_Parameter SessionStateChanged::param() const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.SessionStateChanged.param)
  return static_cast< ::Mysqlx::Notice::SessionStateChanged_Parameter >(param_);
}
inline void SessionStateChanged::set_param(::Mysqlx::Notice::SessionStateChanged_Parameter value) {
  assert(::Mysqlx::Notice::SessionStateChanged_Parameter_IsValid(value));
  set_has_param();
  param_ = value;
  // @@protoc_insertion_point(field_set:Mysqlx.Notice.SessionStateChanged.param)
}

// repeated .Mysqlx.Datatypes.Scalar value = 2;
inline int SessionStateChanged::value_size() const {
  return value_.size();
}
inline void SessionStateChanged::clear_value() {
  value_.Clear();
}
inline const ::Mysqlx::Datatypes::Scalar& SessionStateChanged::value(int index) const {
  // @@protoc_insertion_point(field_get:Mysqlx.Notice.SessionStateChanged.value)
  return value_.Get(index);
}
inline ::Mysqlx::Datatypes::Scalar* SessionStateChanged::mutable_value(int index) {
  // @@protoc_insertion_point(field_mutable:Mysqlx.Notice.SessionStateChanged.value)
  return value_.Mutable(index);
}
inline ::Mysqlx::Datatypes::Scalar* SessionStateChanged::add_value() {
  // @@protoc_insertion_point(field_add:Mysqlx.Notice.SessionStateChanged.value)
  return value_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Mysqlx::Datatypes::Scalar >&
SessionStateChanged::value() const {
  // @@protoc_insertion_point(field_list:Mysqlx.Notice.SessionStateChanged.value)
  return value_;
}
inline ::google::protobuf::RepeatedPtrField< ::Mysqlx::Datatypes::Scalar >*
SessionStateChanged::mutable_value() {
  // @@protoc_insertion_point(field_mutable_list:Mysqlx.Notice.SessionStateChanged.value)
  return &value_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Notice
}  // namespace Mysqlx

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_mysqlx_5fnotice_2eproto__INCLUDED
