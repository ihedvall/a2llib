/*
* Copyright 2022 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2lfile.h"

#include <sstream>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <ranges>
#include <string_view>
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

A2lFile::~A2lFile() {
  if (parse_thread_.joinable()) {
    parse_thread_.join();
  }
  scanner_ = nullptr;
}

std::string A2lFile::Name() const {
  return A2lHelper::GetStem(filename_);
}

int A2lFile::ReadAndConvertFile( const std::string& filename,
  std::istringstream& utf8_stream) {

  const std::u8string file_utf8 =
      reinterpret_cast<const char8_t*>(filename.c_str());
  const path file_path(file_utf8);

  // Check if the file exist
  if (!exists(file_path)) {
    std::ostringstream error;
    error << "The file doesn't exist. File: " << filename;
    throw std::runtime_error(error.str());
  }

  // Check file size
  const auto size = file_size(file_path);
  if (size <= 4) {
    std::ostringstream error;
    error << "The file is empty. File: " << filename;
    throw std::runtime_error(error.str());
  }

  std::string temp_buffer;
  temp_buffer.reserve(size);

  std::ifstream file(file_path, std::ios::binary | std::ios::in);
  auto itr = std::istreambuf_iterator<char>(file);
  auto end = std::istreambuf_iterator<char>();
  temp_buffer.append(itr, end);
  file.close();


  int lines = static_cast<int>(std::ranges::count(temp_buffer, '\n'));
  if (temp_buffer.back() != '\n') {
    ++lines;
  }

  A2lFileEncoding encoding = A2lFileEncoding::ASCII;
  int enc = 0;
  for (const auto& bom : BomList) {
    if (temp_buffer.compare(0,bom.length(), bom) == 0) {
      encoding = static_cast<A2lFileEncoding>(enc);
      temp_buffer = temp_buffer.substr(bom.length());
      break;
    }
    ++enc;
  }

  switch (encoding) {
    case A2lFileEncoding::UTF32_BE:{
      const auto size32 = temp_buffer.length() / 4;
      std::u32string temp32(size32, 0);
      for (size_t index = 0; index < size32; ++index) {
        const auto input =
            static_cast<uint32_t>(static_cast<uint8_t>(temp_buffer[index * 4]));
        temp32[index] = big_to_native(input);
      }
      utf8_stream.str( conv::to_utf<char>(temp_buffer,"UTF-32"));
      break;
    }

    case A2lFileEncoding::UTF32_LE:{
      const auto size32 = temp_buffer.length() / 4;
      std::u32string temp32(size32, 0);
      for (size_t index = 0; index < size32; ++index) {
        const auto input =
            static_cast<uint32_t>(static_cast<uint8_t>(temp_buffer[index * 4]));
        temp32[index] = little_to_native(input);
      }
      utf8_stream.str( conv::to_utf<char>(temp_buffer,"UTF-32"));
      break;
    }

    case A2lFileEncoding::UTF16_BE:{
      const auto size16 = temp_buffer.length() / 2;
      std::u16string temp16(size16, 0);
      for (size_t index = 0; index < size16; ++index) {
        const auto input =
            static_cast<uint16_t>(static_cast<uint8_t>(temp_buffer[index * 2]));
        temp16[index] = big_to_native(input);
      }
      utf8_stream.str( conv::to_utf<char>(temp_buffer,"UTF-16") );
      break;
    }

    case A2lFileEncoding::UTF16_LE:{
      const auto size16 = temp_buffer.length() / 2;
      std::u16string temp16(size16, 0);
      for (size_t index = 0; index < size16; ++index) {
        const auto input =
            static_cast<uint16_t>(static_cast<uint8_t>(temp_buffer[index * 2]));
        temp16[index] = little_to_native(input);
      }
      utf8_stream.str(conv::to_utf<char>(temp_buffer,"UTF-16"));
      break;
    }

    case A2lFileEncoding::ASCII:
      utf8_stream.str(std::move(
        conv::to_utf<char>(temp_buffer,"ISO-8859-1")));
      break;

    case A2lFileEncoding::UTF8:
    default:
      utf8_stream.str(std::move(temp_buffer));
      break;
  }
  return lines;
}

bool A2lFile::ParseFile() {
  last_error_.clear();
  current_lineno_ = 0;
  number_of_lines_ = 0;

  bool parse = false;

  try {
    // Read in the file into a memory stream and convert to UTF8 coding at
    // the same time
    CheckBom();
    std::ifstream file_stream;
    std::istringstream utf8_stream;

    switch (encoding_) {
      case A2lFileEncoding::ASCII:
        file_stream.open(filename_, std::ios::binary | std::ios::in);
        break;

      case A2lFileEncoding::UTF8: {
        file_stream.open(filename_, std::ios::binary | std::ios::in);
        std::string boom_buffer(4, '\0');
        file_stream.read(boom_buffer.data(), 3); ///< Remove BOM from parser stream
        break;
      }

      default:
        number_of_lines_ = ReadAndConvertFile(filename_, utf8_stream);
        break;
    }

    A2lScanner scanner(file_stream.is_open() ?
      dynamic_cast<std::istream&>(file_stream) :
      dynamic_cast<std::istream&>(utf8_stream));

    switch (parser_type_) {
      case A2lParserType::PARSE_MODULE_INFORMATION_ONLY:
        scanner.SetParseModuleInformationOnly();
        break;

      default:
        break;
    }

    scanner_ = &scanner;
    scanner.InputFile(filename_); // Needed in case of include files.
    scanner.Parent(this);

    // scanner.set_debug(2);
    A2lParser parser(scanner, *this);

    parse = parser.parse() == 0;
    scanner_ = nullptr;
    if (file_stream.is_open()) {
      file_stream.close();
    }

    // Need to recover the module in case non-full parsing.
    // When doing full parser, this pointer should be null.
    project_.AddModule(scanner.ReleaseModule());

    IsA2lFile(scanner.IsA2lFile());
    last_error_ = scanner.LastError();
    // Save the last line in case of an error.
    current_lineno_ = scanner.lineno();

  } catch (const std::exception& err) {
    scanner_ = nullptr;
    last_error_ = err.what();
  } catch (...) {
    scanner_ = nullptr;
  }

  return parse;
}

void A2lFile::AsynchParseFile(A2lReadyFunction ready_function) {
  if (parse_thread_.joinable()) {
    parse_thread_.join();
  }
  current_lineno_ = 0;
  number_of_lines_ = 0;

  ready_function_ = std::move(ready_function);
  last_error_.clear();
  parse_thread_ = std::thread(&A2lFile::ParseThread, this);
}

void A2lFile::ParseThread() {
  bool parse = false;
  try {
    // Read in the file into a memory stream and convert to UTF8 coding at
    // the same time

    std::istringstream utf8_stream;
    number_of_lines_ = ReadAndConvertFile(filename_, utf8_stream);
    A2lScanner scanner(utf8_stream);

    switch (parser_type_) {
      case A2lParserType::PARSE_MODULE_INFORMATION_ONLY:
        scanner.SetParseModuleInformationOnly();
        break;

      default:
        break;
    }

    scanner_ = &scanner;
    scanner.InputFile(filename_); // Needed in case of include files.
    scanner.Parent(this);

    // scanner.set_debug(2);
    A2lParser parser(scanner, *this);

    parse = parser.parse() == 0;

    IsA2lFile(scanner.IsA2lFile());

    last_error_ = scanner.LastError();    // Save the last line in case of an error.
    current_lineno_ = scanner.lineno();
    scanner_ = nullptr;
  } catch (const std::exception& err) {
    scanner_ = nullptr;
    last_error_ = err.what();
  } catch (...) {
    scanner_ = nullptr;
  }

  if (ready_function_) {
    ready_function_(parse);
  }
}

void A2lFile::CheckBom() {
  const std::u8string file_utf8 =
      reinterpret_cast<const char8_t*>(filename_.c_str());
  const path file_path(file_utf8);

  // Check if the file exist
  if (!exists(file_path)) {
    std::ostringstream error;
    error << "The file doesn't exist. File: " << filename_;
    throw std::runtime_error(error.str());
  }

  std::string bom_buffer(5,'\0');
  std::ifstream file(file_path, std::ios::binary | std::ios::in );
  file.read(bom_buffer.data(), 4);
  file.close();

  int enc = 0;
  for (const auto& bom : BomList) {
    if (bom_buffer.compare(0,bom.length(), bom) == 0) {
      encoding_ = static_cast<A2lFileEncoding>(enc);
      break;
    }
    ++enc;
  }
}

void A2lFile::Merge(A2lFile &include_file) {
  // If this isn't an A2L file i.e. missing the project header, then copy the entire project.
  // Always move the modules
  auto& dest_project = Project();
  auto& remote_project = include_file.Project();
  if (!IsA2lFile()) {
    dest_project.Header() = remote_project.Header();
  }

  ModuleList& source_list = remote_project.Modules();
  for (auto &module : source_list | std::views::values) {
    dest_project.AddModule(module);
  }
  source_list.clear();
}

int A2lFile::LineNo() const {
  if (scanner_ != nullptr) {
    current_lineno_ = scanner_.load()->lineno();
  }
  return current_lineno_;
}

int A2lFile::ProgressInfo() const {
  if (current_lineno_ == 0) {
    return number_of_lines_ == 0 ? 0 : 100;
  }

  if (number_of_lines_ == 0 || scanner_ == nullptr) {
    return 100;
  }
  return static_cast<int>(100 * current_lineno_ / number_of_lines_);
}
}  // namespace a2l