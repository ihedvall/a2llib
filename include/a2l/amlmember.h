/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <string>

namespace a2l {

enum class AmlDefinitionType : int {
  TYPE_DEFINITION = 0,
  BLOCK_DEFINITION = 1,
  UNKNOWN = 2
};

enum class AmlTypeName : int {
  PREDEFINED = 0,
  STRUCT,
  TAGGED_STRUCT,
  TAGGED_UNION,
  ENUMERATE,
  UNKNOWN
};

enum class AmlDataType : int {
  CHAR,
  INT,
  LONG,
  INT64,
  UCHAR,
  UINT,
  UINT64,
  ULONG,
  DOUBLE,
  FLOAT,
  TEXT_ARRAY,
  UNKNOWN
};
class AmlMember;
using AmlEnumerateList = std::vector<std::pair<std::string, int64_t>>;
using AmlMemberList = std::vector<AmlMember>;
using AmlArrayList = std::vector<uint64_t>;

class AmlMember {
 public:
  AmlMember() = default;
  AmlMember(const AmlMember&) = default;
  AmlMember(AmlMember&&) = default;
  AmlMember& operator=(const AmlMember&) = default;
  AmlMember& operator=(AmlMember&&) = default;
  virtual ~AmlMember() = default;

  void DefinitionType(AmlDefinitionType type) { definition_type_ = type;}
  [[nodiscard]] AmlDefinitionType DefinitionType() const {
    return definition_type_;
  };

  void TypeName(AmlTypeName type) { type_name_ = type; }
  [[nodiscard]] AmlTypeName TypeName() const { return type_name_; }
  [[nodiscard]] std::string_view TypeNameAsString() const;

  void DataType(AmlDataType type) { data_type_ = type; }
  [[nodiscard]] AmlDataType DataType() const { return data_type_; }
  [[nodiscard]] std::string_view DataTypeAsString() const;

  void Identity(std::string ident) { identity_ = std::move(ident); }
  [[nodiscard]] const std::string& Identity() const { return identity_; }


  void EnumerateList(AmlEnumerateList list) { enumerate_list_ = std::move(list); }
  [[nodiscard]] AmlEnumerateList& EnumerateList() { return enumerate_list_; }
  [[nodiscard]] const AmlEnumerateList& EnumerateList() const {
    return enumerate_list_;
  }

  [[nodiscard]] bool IsEnumerated() const;

  void MemberList(AmlMemberList list) { member_list_ = std::move(list); }
  [[nodiscard]] AmlMemberList& MemberList() { return member_list_; }
  [[nodiscard]] const AmlMemberList& MemberList() const { return member_list_; }

  void Tag(std::string tag) { tag_ = std::move(tag); }
  [[nodiscard]] const std::string& Tag() const { return tag_; }

  void ArrayList(AmlArrayList list) { array_list_ = std::move(list); }
  [[nodiscard]] const AmlArrayList& ArrayList() const { return array_list_; }

  void VectorType(bool type) { vector_type_ = type; }
  [[nodiscard]] bool VectorType() const { return vector_type_; }
  ;
  [[nodiscard]] std::string AsString(size_t level) const;

  [[nodiscard]] const AmlMember* GetMemberByTag(const std::string& tag) const;
  [[nodiscard]] const AmlMember* GetMemberByIdentity(const std::string& identity) const;

 private:
  AmlDefinitionType definition_type_ = AmlDefinitionType::TYPE_DEFINITION;
  AmlTypeName type_name_ = AmlTypeName::UNKNOWN;
  AmlDataType data_type_  = AmlDataType::UNKNOWN;
  std::string identity_;
  AmlEnumerateList enumerate_list_;
  AmlMemberList member_list_;
  std::string tag_;
  AmlArrayList array_list_;
  bool vector_type_ = false; // Within (...)* declaration
};

}  // namespace a2l
