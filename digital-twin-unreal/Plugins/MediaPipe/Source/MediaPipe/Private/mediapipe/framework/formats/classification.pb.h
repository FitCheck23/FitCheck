// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mediapipe/framework/formats/classification.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mediapipe_2fframework_2fformats_2fclassification_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_mediapipe_2fframework_2fformats_2fclassification_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_mediapipe_2fframework_2fformats_2fclassification_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mediapipe_2fframework_2fformats_2fclassification_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_mediapipe_2fframework_2fformats_2fclassification_2eproto;
namespace mediapipe {
class Classification;
class ClassificationDefaultTypeInternal;
extern ClassificationDefaultTypeInternal _Classification_default_instance_;
class ClassificationList;
class ClassificationListDefaultTypeInternal;
extern ClassificationListDefaultTypeInternal _ClassificationList_default_instance_;
}  // namespace mediapipe
PROTOBUF_NAMESPACE_OPEN
template<> ::mediapipe::Classification* Arena::CreateMaybeMessage<::mediapipe::Classification>(Arena*);
template<> ::mediapipe::ClassificationList* Arena::CreateMaybeMessage<::mediapipe::ClassificationList>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mediapipe {

// ===================================================================

class Classification :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mediapipe.Classification) */ {
 public:
  Classification();
  virtual ~Classification();

  Classification(const Classification& from);
  Classification(Classification&& from) noexcept
    : Classification() {
    *this = ::std::move(from);
  }

  inline Classification& operator=(const Classification& from) {
    CopyFrom(from);
    return *this;
  }
  inline Classification& operator=(Classification&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Classification& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Classification* internal_default_instance() {
    return reinterpret_cast<const Classification*>(
               &_Classification_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Classification& a, Classification& b) {
    a.Swap(&b);
  }
  inline void Swap(Classification* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Classification* New() const final {
    return CreateMaybeMessage<Classification>(nullptr);
  }

  Classification* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Classification>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Classification& from);
  void MergeFrom(const Classification& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Classification* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mediapipe.Classification";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mediapipe_2fframework_2fformats_2fclassification_2eproto);
    return ::descriptor_table_mediapipe_2fframework_2fformats_2fclassification_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLabelFieldNumber = 3,
    kDisplayNameFieldNumber = 4,
    kIndexFieldNumber = 1,
    kScoreFieldNumber = 2,
  };
  // optional string label = 3;
  bool has_label() const;
  private:
  bool _internal_has_label() const;
  public:
  void clear_label();
  const std::string& label() const;
  void set_label(const std::string& value);
  void set_label(std::string&& value);
  void set_label(const char* value);
  void set_label(const char* value, size_t size);
  std::string* mutable_label();
  std::string* release_label();
  void set_allocated_label(std::string* label);
  private:
  const std::string& _internal_label() const;
  void _internal_set_label(const std::string& value);
  std::string* _internal_mutable_label();
  public:

  // optional string display_name = 4;
  bool has_display_name() const;
  private:
  bool _internal_has_display_name() const;
  public:
  void clear_display_name();
  const std::string& display_name() const;
  void set_display_name(const std::string& value);
  void set_display_name(std::string&& value);
  void set_display_name(const char* value);
  void set_display_name(const char* value, size_t size);
  std::string* mutable_display_name();
  std::string* release_display_name();
  void set_allocated_display_name(std::string* display_name);
  private:
  const std::string& _internal_display_name() const;
  void _internal_set_display_name(const std::string& value);
  std::string* _internal_mutable_display_name();
  public:

  // optional int32 index = 1;
  bool has_index() const;
  private:
  bool _internal_has_index() const;
  public:
  void clear_index();
  ::PROTOBUF_NAMESPACE_ID::int32 index() const;
  void set_index(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_index() const;
  void _internal_set_index(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // optional float score = 2;
  bool has_score() const;
  private:
  bool _internal_has_score() const;
  public:
  void clear_score();
  float score() const;
  void set_score(float value);
  private:
  float _internal_score() const;
  void _internal_set_score(float value);
  public:

  // @@protoc_insertion_point(class_scope:mediapipe.Classification)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr label_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr display_name_;
  ::PROTOBUF_NAMESPACE_ID::int32 index_;
  float score_;
  friend struct ::TableStruct_mediapipe_2fframework_2fformats_2fclassification_2eproto;
};
// -------------------------------------------------------------------

class ClassificationList :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mediapipe.ClassificationList) */ {
 public:
  ClassificationList();
  virtual ~ClassificationList();

  ClassificationList(const ClassificationList& from);
  ClassificationList(ClassificationList&& from) noexcept
    : ClassificationList() {
    *this = ::std::move(from);
  }

  inline ClassificationList& operator=(const ClassificationList& from) {
    CopyFrom(from);
    return *this;
  }
  inline ClassificationList& operator=(ClassificationList&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ClassificationList& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ClassificationList* internal_default_instance() {
    return reinterpret_cast<const ClassificationList*>(
               &_ClassificationList_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ClassificationList& a, ClassificationList& b) {
    a.Swap(&b);
  }
  inline void Swap(ClassificationList* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ClassificationList* New() const final {
    return CreateMaybeMessage<ClassificationList>(nullptr);
  }

  ClassificationList* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ClassificationList>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ClassificationList& from);
  void MergeFrom(const ClassificationList& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ClassificationList* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mediapipe.ClassificationList";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_mediapipe_2fframework_2fformats_2fclassification_2eproto);
    return ::descriptor_table_mediapipe_2fframework_2fformats_2fclassification_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kClassificationFieldNumber = 1,
  };
  // repeated .mediapipe.Classification classification = 1;
  int classification_size() const;
  private:
  int _internal_classification_size() const;
  public:
  void clear_classification();
  ::mediapipe::Classification* mutable_classification(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mediapipe::Classification >*
      mutable_classification();
  private:
  const ::mediapipe::Classification& _internal_classification(int index) const;
  ::mediapipe::Classification* _internal_add_classification();
  public:
  const ::mediapipe::Classification& classification(int index) const;
  ::mediapipe::Classification* add_classification();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mediapipe::Classification >&
      classification() const;

  // @@protoc_insertion_point(class_scope:mediapipe.ClassificationList)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mediapipe::Classification > classification_;
  friend struct ::TableStruct_mediapipe_2fframework_2fformats_2fclassification_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Classification

// optional int32 index = 1;
inline bool Classification::_internal_has_index() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Classification::has_index() const {
  return _internal_has_index();
}
inline void Classification::clear_index() {
  index_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Classification::_internal_index() const {
  return index_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Classification::index() const {
  // @@protoc_insertion_point(field_get:mediapipe.Classification.index)
  return _internal_index();
}
inline void Classification::_internal_set_index(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000004u;
  index_ = value;
}
inline void Classification::set_index(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_index(value);
  // @@protoc_insertion_point(field_set:mediapipe.Classification.index)
}

// optional float score = 2;
inline bool Classification::_internal_has_score() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool Classification::has_score() const {
  return _internal_has_score();
}
inline void Classification::clear_score() {
  score_ = 0;
  _has_bits_[0] &= ~0x00000008u;
}
inline float Classification::_internal_score() const {
  return score_;
}
inline float Classification::score() const {
  // @@protoc_insertion_point(field_get:mediapipe.Classification.score)
  return _internal_score();
}
inline void Classification::_internal_set_score(float value) {
  _has_bits_[0] |= 0x00000008u;
  score_ = value;
}
inline void Classification::set_score(float value) {
  _internal_set_score(value);
  // @@protoc_insertion_point(field_set:mediapipe.Classification.score)
}

// optional string label = 3;
inline bool Classification::_internal_has_label() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Classification::has_label() const {
  return _internal_has_label();
}
inline void Classification::clear_label() {
  label_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Classification::label() const {
  // @@protoc_insertion_point(field_get:mediapipe.Classification.label)
  return _internal_label();
}
inline void Classification::set_label(const std::string& value) {
  _internal_set_label(value);
  // @@protoc_insertion_point(field_set:mediapipe.Classification.label)
}
inline std::string* Classification::mutable_label() {
  // @@protoc_insertion_point(field_mutable:mediapipe.Classification.label)
  return _internal_mutable_label();
}
inline const std::string& Classification::_internal_label() const {
  return label_.GetNoArena();
}
inline void Classification::_internal_set_label(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  label_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Classification::set_label(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  label_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mediapipe.Classification.label)
}
inline void Classification::set_label(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  label_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mediapipe.Classification.label)
}
inline void Classification::set_label(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  label_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mediapipe.Classification.label)
}
inline std::string* Classification::_internal_mutable_label() {
  _has_bits_[0] |= 0x00000001u;
  return label_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Classification::release_label() {
  // @@protoc_insertion_point(field_release:mediapipe.Classification.label)
  if (!_internal_has_label()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return label_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Classification::set_allocated_label(std::string* label) {
  if (label != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  label_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), label);
  // @@protoc_insertion_point(field_set_allocated:mediapipe.Classification.label)
}

// optional string display_name = 4;
inline bool Classification::_internal_has_display_name() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Classification::has_display_name() const {
  return _internal_has_display_name();
}
inline void Classification::clear_display_name() {
  display_name_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Classification::display_name() const {
  // @@protoc_insertion_point(field_get:mediapipe.Classification.display_name)
  return _internal_display_name();
}
inline void Classification::set_display_name(const std::string& value) {
  _internal_set_display_name(value);
  // @@protoc_insertion_point(field_set:mediapipe.Classification.display_name)
}
inline std::string* Classification::mutable_display_name() {
  // @@protoc_insertion_point(field_mutable:mediapipe.Classification.display_name)
  return _internal_mutable_display_name();
}
inline const std::string& Classification::_internal_display_name() const {
  return display_name_.GetNoArena();
}
inline void Classification::_internal_set_display_name(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  display_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void Classification::set_display_name(std::string&& value) {
  _has_bits_[0] |= 0x00000002u;
  display_name_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:mediapipe.Classification.display_name)
}
inline void Classification::set_display_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000002u;
  display_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:mediapipe.Classification.display_name)
}
inline void Classification::set_display_name(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000002u;
  display_name_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:mediapipe.Classification.display_name)
}
inline std::string* Classification::_internal_mutable_display_name() {
  _has_bits_[0] |= 0x00000002u;
  return display_name_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* Classification::release_display_name() {
  // @@protoc_insertion_point(field_release:mediapipe.Classification.display_name)
  if (!_internal_has_display_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return display_name_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void Classification::set_allocated_display_name(std::string* display_name) {
  if (display_name != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  display_name_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), display_name);
  // @@protoc_insertion_point(field_set_allocated:mediapipe.Classification.display_name)
}

// -------------------------------------------------------------------

// ClassificationList

// repeated .mediapipe.Classification classification = 1;
inline int ClassificationList::_internal_classification_size() const {
  return classification_.size();
}
inline int ClassificationList::classification_size() const {
  return _internal_classification_size();
}
inline void ClassificationList::clear_classification() {
  classification_.Clear();
}
inline ::mediapipe::Classification* ClassificationList::mutable_classification(int index) {
  // @@protoc_insertion_point(field_mutable:mediapipe.ClassificationList.classification)
  return classification_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mediapipe::Classification >*
ClassificationList::mutable_classification() {
  // @@protoc_insertion_point(field_mutable_list:mediapipe.ClassificationList.classification)
  return &classification_;
}
inline const ::mediapipe::Classification& ClassificationList::_internal_classification(int index) const {
  return classification_.Get(index);
}
inline const ::mediapipe::Classification& ClassificationList::classification(int index) const {
  // @@protoc_insertion_point(field_get:mediapipe.ClassificationList.classification)
  return _internal_classification(index);
}
inline ::mediapipe::Classification* ClassificationList::_internal_add_classification() {
  return classification_.Add();
}
inline ::mediapipe::Classification* ClassificationList::add_classification() {
  // @@protoc_insertion_point(field_add:mediapipe.ClassificationList.classification)
  return _internal_add_classification();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::mediapipe::Classification >&
ClassificationList::classification() const {
  // @@protoc_insertion_point(field_list:mediapipe.ClassificationList.classification)
  return classification_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mediapipe

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_mediapipe_2fframework_2fformats_2fclassification_2eproto
