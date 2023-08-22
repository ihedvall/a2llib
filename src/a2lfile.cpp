/*
* Copyright 2022 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lfile.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include <array>
#include <boost/locale.hpp>
#include <boost/endian.hpp>
#include "a2lscanner.h"
#include "a2lhelper.h"

using namespace std::filesystem;
using namespace boost::locale;
using namespace boost::endian;

namespace {

constexpr std::array<std::string_view,5> BomList = {
    std::string_view("\x00\x00\xFE\xFF",4),
    std::string_view("\xFF\xFE\x00\x00",4),
    std::string_view("\xFE\xFF",2),
    std::string_view("\xFF\xFE",2),
    std::string_view("\xEF\xBB\xBF", 3)
};

}

namespace a2l {

std::string A2lFile::Name() const {
  return A2lHelper::GetStem(filename_);
}

bool A2lFile::ParseFile() {
  last_error_.clear();
  content_.str("");
  content_.clear();
  bool parse = true;
  try {
    // Read in the file into a memory stream and convert to UTF8 coding at
    // the same time
    ReadAndConvertFile();
    A2lScanner scanner(content_);
    // scanner.set_debug(2);
    A2lParser parser(scanner);
    parse = parser.parse() == 0;
    last_error_ = scanner.LastError();

  } catch (const std::exception& err) {
    last_error_ = err.what();
    parse = false;
  } catch (...) {
    parse = false;
  }
  return parse;
}

void A2lFile::ReadAndConvertFile() {
  const std::u8string file_utf8 =
      reinterpret_cast<const char8_t*>(filename_.c_str());
  const path file_path(file_utf8);

  // Check if the file exist
   if (!exists(file_path)) {
    std::ostringstream error;
    error << "The file doesn't exist. File: " << filename_;
    throw std::runtime_error(error.str());
  }

  // Check file size
  const auto size = file_size(file_path);
  if (size <= 4) {
    std::ostringstream error;
    error << "The file is empty. File: " << filename_;
    throw std::runtime_error(error.str());
  }
  std::string temp_buffer;
  std::ifstream file(file_path, std::ios::binary | std::ios::in);
  auto itr = std::istreambuf_iterator<char>(file);
  auto end = std::istreambuf_iterator<char>();
  temp_buffer.append(itr, end);
  file.close();

  encoding_ = A2lEncoding::ASCII;
  int enc = 0;
  for (const auto& bom : BomList) {
    if (temp_buffer.compare(0,bom.length(), bom) == 0) {
      encoding_ = static_cast<A2lEncoding>(enc);
      temp_buffer = temp_buffer.substr(bom.length());
      break;
    }
    ++enc;
  }

  switch (encoding_) {
    case A2lEncoding::UTF32_BE:{
      const auto size32 = temp_buffer.length() / 4;
      std::u32string temp32(size32, 0);
      for (size_t index = 0; index < size32; ++index) {
        const auto input =
            static_cast<uint32_t>(static_cast<uint8_t>(temp_buffer[index * 4]));
        temp32[index] = big_to_native(input);
      }
      content_.str( conv::to_utf<char>(temp_buffer,"UTF-32"));
      break;
    }

    case A2lEncoding::UTF32_LE:{
      const auto size32 = temp_buffer.length() / 4;
      std::u32string temp32(size32, 0);
      for (size_t index = 0; index < size32; ++index) {
        const auto input =
            static_cast<uint32_t>(static_cast<uint8_t>(temp_buffer[index * 4]));
        temp32[index] = little_to_native(input);
      }
      content_.str( conv::to_utf<char>(temp_buffer,"UTF-32"));
      break;
    }

    case A2lEncoding::UTF16_BE:{
      const auto size16 = temp_buffer.length() / 2;
      std::u16string temp16(size16, 0);
      for (size_t index = 0; index < size16; ++index) {
        const auto input =
            static_cast<uint16_t>(static_cast<uint8_t>(temp_buffer[index * 2]));
        temp16[index] = big_to_native(input);
      }
      content_.str( conv::to_utf<char>(temp_buffer,"UTF-16") );
      break;
    }

    case A2lEncoding::UTF16_LE:{
      const auto size16 = temp_buffer.length() / 2;
      std::u16string temp16(size16, 0);
      for (size_t index = 0; index < size16; ++index) {
        const auto input =
            static_cast<uint16_t>(static_cast<uint8_t>(temp_buffer[index * 2]));
        temp16[index] = little_to_native(input);
      }
      content_.str(conv::to_utf<char>(temp_buffer,"UTF-16"));
      break;
    }

    case A2lEncoding::ASCII:
      content_.str(conv::to_utf<char>(temp_buffer,"ISO-8859-1"));
      break;

    case A2lEncoding::UTF8:
    default:
      content_.str(temp_buffer);
      break;
  }

}

}  // namespace a2l