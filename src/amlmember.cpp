/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
*/

#include <sstream>
#include <string_view>
#include <ranges>
#include <algorithm>

#include "a2l/amlmember.h"

namespace a2l {


std::string_view AmlMember::TypeNameAsString() const {
  switch (type_name_) {
    case AmlTypeName::PREDEFINED: return "PREDEFINED";
    case AmlTypeName::STRUCT: return "STRUCT";
    case AmlTypeName::TAGGED_STRUCT: return "TAGGED STRUCT";
    case AmlTypeName::TAGGED_UNION: return "TAGGED UNION";
    case AmlTypeName::ENUMERATE: return "ENUMERATE";
    default:
      break;
  }
  return "";
}
std::string_view AmlMember::DataTypeAsString() const {
  switch (data_type_) {
    case AmlDataType::CHAR: return "char";
    case AmlDataType::INT: return "int";
    case AmlDataType::LONG: return "long";
    case AmlDataType::INT64: return "int64";
    case AmlDataType::UCHAR: return "uchar";
    case AmlDataType::UINT: return "uint";
    case AmlDataType::ULONG: return "ulong";
    case AmlDataType::UINT64: return "uint64";
    case AmlDataType::DOUBLE: return "double";
    case AmlDataType::FLOAT: return "float";
    case AmlDataType::TEXT_ARRAY: return "string";
    default:
      break;

  }
  return "unknown";
}

bool AmlMember::IsEnumerated() const {
  if (enumerate_list_.empty()) {
    return false;
  }

  const bool no_enum = std::ranges::all_of(enumerate_list_,
    [](const auto& enumerate) ->bool {
      return enumerate.second == 0;
    });
  return !no_enum;
}

std::string AmlMember::AsString(size_t level) const {
  std::ostringstream temp;
  for (size_t tab = 0; tab < level; ++tab) {
    temp << "  ";
  }
  if (VectorType()) {
    temp << "*";
  }
  if (DefinitionType() == AmlDefinitionType::BLOCK_DEFINITION) {
    temp << "block " << BlockTag() << " " << TypeNameAsString();
    if (!Identity().empty() ) {
      temp << " " << Identity();
    }
    temp<< std::endl;
  } else {
    switch (TypeName()) {
      case AmlTypeName::PREDEFINED:
        temp << TypeNameAsString() << " ";
        if (!Identity().empty()) {
          temp << Identity() << " ";
        }
        if (!MemberTag().empty()) {
          temp << MemberTag() << " ";
        }
        temp << DataTypeAsString();
        for (int64_t array_size : ArrayList()) {
           temp << "[" << array_size << "]";
        }

        temp << std::endl;
        return temp.str();

      case AmlTypeName::ENUMERATE: {
        if (!MemberTag().empty()) {
          temp << MemberTag() << " ";
        }
        temp << TypeNameAsString();
        if (!Identity().empty() ) {
          temp << " " << Identity();
        }
        temp << " {";
        const bool is_enumerated = IsEnumerated();
        for (const auto& enumerate : EnumerateList()) {
          temp << enumerate.first;
          if (is_enumerated) {
            temp << "=" << enumerate.second;
          }
          temp << ",";
        }
        temp << "}"   << std::endl;
        return temp.str();
      }

      default:
        break;
    }
    if (!MemberTag().empty()) {
      temp << MemberTag() << " ";
    }
    if (!Identity().empty()) {
      temp << Identity() << " ";
    }
    temp << TypeNameAsString() << std::endl;
  }

  for (const auto& member : MemberList()) {
    for (size_t tab = 0; tab < level; ++tab) {
      temp << "  ";
    }
    temp << member.AsString(level + 1);
  }
  return temp.str();
}

}  // namespace a2l