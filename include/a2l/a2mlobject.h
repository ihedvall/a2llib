/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#pragma once

#include <vector>
#include <map>
#include <string>

namespace a2l {

enum class A2mlTypeName : int {
  PREDEFINED,
  STRUCT,
  TAGGED_STRUCT,
  TAGGED_UNION,
  ENUMERATE,
  BLOCK,
  UNKNOWN
};

enum class A2mlDataType : int {
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

class A2mlObject;
using A2mlMemberList = std::vector<A2mlObject>;
using A2mlEnumerateList = std::map<int64_t, std::string>;
using A2mlBlockList = A2mlMemberList;

class A2mlObject {
 public:
  A2mlObject() = default;

  explicit A2mlObject(A2mlTypeName type);

  void Ident(const std::string& ident) { ident_ = ident; }
  [[nodiscard]] const std::string& Ident() const { return ident_; }

  void Tag(const std::string& tag) { tag_ = tag; }
  [[nodiscard]] const std::string& Tag() const { return tag_; }

  void Type(A2mlTypeName type) { type_ = type; }
  [[nodiscard]] A2mlTypeName Type() const { return type_; }
  [[nodiscard]] std::string_view TypeAsString() const;

  void DataType(A2mlDataType type) { data_type_ = type; }
  [[nodiscard]] A2mlDataType DataType() const { return data_type_; }
  [[nodiscard]] std::string_view DataTypeAsString() const;

  void MemberList(const A2mlMemberList& list) { member_list_ = list; }
  [[nodiscard]] A2mlMemberList& MemberList() { return member_list_; }
  [[nodiscard]] const A2mlMemberList& MemberList() const {
    return member_list_;
  }

  void EnumerateList(const A2mlEnumerateList& list) { enumerate_list_ = list; }
  [[nodiscard]] A2mlEnumerateList& EnumerateList() { return enumerate_list_; }
  [[nodiscard]] const A2mlEnumerateList& EnumerateList() const {
    return enumerate_list_;
  }

  [[nodiscard]] std::string AsString() const;
 private:

  std::string tag_;
  std::string ident_;
  A2mlMemberList member_list_;
  A2mlEnumerateList enumerate_list_;

  A2mlTypeName type_ = A2mlTypeName::UNKNOWN;
  A2mlDataType data_type_  = A2mlDataType::UNKNOWN;

};

}  // namespace a2l
