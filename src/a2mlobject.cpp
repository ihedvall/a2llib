/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include "a2l/a2mlobject.h"
#include <sstream>
#include <string_view>

namespace a2l {

A2mlObject::A2mlObject(A2mlTypeName type)
: type_(type) {

}
std::string_view A2mlObject::TypeAsString() const {
  switch (type_) {
    case A2mlTypeName::PREDEFINED: return "PREDEFINED";
    case A2mlTypeName::STRUCT: return "STRUCT";
    case A2mlTypeName::TAGGED_STRUCT: return "TAGGED STRUCT";
    case A2mlTypeName::TAGGED_UNION: return "TAGGED UNION";
    case A2mlTypeName::ENUMERATE: return "ENUMERATE";
    case A2mlTypeName::BLOCK: return "BLOCK";
    default:
      break;
  }
  return "";
}

std::string_view A2mlObject::DataTypeAsString() const {
  switch (data_type_) {
    case A2mlDataType::CHAR: return "char";
    case A2mlDataType::INT: return "int";
    case A2mlDataType::LONG: return "long";
    case A2mlDataType::INT64: return "int64";
    case A2mlDataType::UCHAR: return "uchar";
    case A2mlDataType::UINT: return "uint";
    case A2mlDataType::ULONG: return "ulong";
    case A2mlDataType::UINT64: return "uint64";
    case A2mlDataType::DOUBLE: return "double";
    case A2mlDataType::FLOAT: return "float";
    case A2mlDataType::TEXT_ARRAY: return "string";
    default:
      break;

  }
  return {};
}

std::string A2mlObject::AsString() const {
  std::ostringstream temp;
  switch (type_) {
    case A2mlTypeName::PREDEFINED:
      if (!tag_.empty()) {
        temp << "\"" << tag_ << "\"" << " ";
      }
      if (!ident_.empty()) {
        temp << ident_ << " ";
      }
      temp << DataTypeAsString();
      break;

    case A2mlTypeName::ENUMERATE:
      temp << TypeAsString() << " ";
      if (!tag_.empty()) {
        temp << "\"" << tag_ << "\"" << " ";
      }
      if (!ident_.empty()) {
        temp << ident_ << " ";
      }
      if (!enumerate_list_.empty()) {
        temp << DataTypeAsString() << " {" << std::endl;
        for (const auto& [key, value] : enumerate_list_) {
          temp << value << " = " << key << std::endl;
        }
        temp << "}";
      }
      break;

    default:
      temp << TypeAsString() << " ";
      if (!tag_.empty()) {
        temp << "\"" << tag_ << "\"" << " ";
      }
      if (!ident_.empty()) {
        temp << ident_ << " ";
      }
      if (!member_list_.empty()) {
        temp << "{" << std::endl;
        for (const auto& object : member_list_) {
          temp << object.AsString();
        }
        temp << "}";
      }
      break;
  }

  temp << std::endl;
  return temp.str();
}

}  // namespace a2l