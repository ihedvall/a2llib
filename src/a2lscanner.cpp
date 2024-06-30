/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2lscanner.h"
#include <filesystem>
#include <sstream>
#include <array>
#include <cstring>
#include <boost/locale.hpp>
#include <boost/endian.hpp>
#include "a2l/a2lfile.h"
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

enum class FileEncoding : int {
  UTF32_BE  = 0,
  UTF32_LE,
  UTF16_BE,
  UTF16_LE,
  UTF8,
  ASCII
};

}

namespace a2l {

A2lScanner::A2lScanner(std::istringstream& message)
    : a2lFlexLexer(&message), yylval(nullptr) {
  // I add a dummy file item onto the stack. This item is used to store
  // the current stack state pointer in case of an include file.
  file_stack_.emplace_back("");
}

void A2lScanner::ReadAndConvertFile(const std::string& filename, std::istringstream& utf8_stream) {
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
  std::ifstream file(file_path, std::ios::binary | std::ios::in);
  auto itr = std::istreambuf_iterator<char>(file);
  auto end = std::istreambuf_iterator<char>();
  temp_buffer.append(itr, end);
  file.close();

  auto encoding = FileEncoding::ASCII;
  int enc = 0;
  for (const auto& bom : BomList) {
    if (temp_buffer.compare(0,bom.length(), bom) == 0) {
      encoding = static_cast<FileEncoding>(enc);
      temp_buffer = temp_buffer.substr(bom.length());
      break;
    }
    ++enc;
  }

  switch (encoding) {
    case FileEncoding::UTF32_BE:{
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

    case FileEncoding::UTF32_LE:{
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

    case FileEncoding::UTF16_BE:{
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

    case FileEncoding::UTF16_LE:{
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

    case FileEncoding::ASCII:
      utf8_stream.str(conv::to_utf<char>(temp_buffer,"ISO-8859-1"));
      break;

    case FileEncoding::UTF8:
    default:
      utf8_stream.str(temp_buffer);
      break;
  }

}

std::string A2lScanner::ReadA2ML() {
  std::ostringstream a2ml_text;
  a2ml_text << yytext;

  std::string match;
  constexpr std::string_view end_a2ml = "/endA2ML";
  for (auto data = yyinput(); data != '\0'; data = yyinput()) {
    a2ml_text << static_cast<char>(data);
    if (std::isspace(data)) {
      continue;
    }
    match.push_back(static_cast<char>(data));
    if (match == end_a2ml) {
      break;
    }
    while (match.size() >= end_a2ml.size()) {
      match.erase(0,1);
    }
  }
  return a2ml_text.str();
}

std::string A2lScanner::ReadIfData() {
  std::ostringstream if_data_text;
  if_data_text << yytext;

  std::string match;
  constexpr std::string_view end_if_data = "/endIF_DATA";
  for (auto data = yyinput(); data != '\0'; data = yyinput()) {
    if_data_text << static_cast<char>(data);
    if (std::isspace(data)) {
      continue;
    }
    match.push_back(static_cast<char>(data));
    if (match == end_if_data) {
      break;
    }
    while (match.size() >= end_if_data.size()) {
      match.erase(0,1);
    }
  }
  return if_data_text.str();
}

std::string A2lScanner::ReadIfDataSingleLine() {
  std::ostringstream if_data_text;
  if_data_text << "/begin " << yytext;

  constexpr std::string_view end_if_data = "/endIF_DATA";
  for (auto data = yyinput();
       data != '\0' && data != '\n' && data != '\r';
       data = yyinput()) {
    if_data_text << static_cast<char>(data);
  }
  if_data_text << " " << end_if_data;
  return if_data_text.str();
}

std::string A2lScanner::ReadIfDataMultiLine() {
  std::ostringstream if_data_text;
  if_data_text << "/begin IF_DATA";

  constexpr std::string_view end_if_data = "/endIF_DATA";
  int state = 0; // The state becomes -1 at end of string
  for (auto data = yyinput(); data != '\0'; data = yyinput()) {
    switch (data) {
      case '{':
        ++state;
        break;
      case '}':
        --state;
        break;
      default:
        break;
    }
    if (state < 0) {
      break;
    }
    if_data_text << static_cast<char>(data);
  }
  if_data_text << " " << end_if_data;
  return if_data_text.str();
}

void A2lScanner::SkipUntil(char end_char) {
  for (auto data = yyinput();
       data != '\0' && data != end_char;
       data = yyinput()) {
  }
}

Module& A2lScanner::CurrentModule() {
  if (!module_) {
    module_ = std::make_unique<Module>();
  }
  return *module_;
}

AxisDescr& A2lScanner::CurrentAxisDescr() {
  if (!axis_descr_) {
    axis_descr_ = std::make_unique<AxisDescr>();
  }
  return *axis_descr_;
}

AxisPts& A2lScanner::CurrentAxisPts() {
  if (!axis_pts_) {
    axis_pts_ = std::make_unique<AxisPts>();
  }
  return *axis_pts_;
}

Blob& A2lScanner::CurrentBlob() {
  if (!blob_) {
    blob_ = std::make_unique<Blob>();
  }
  return *blob_;
}

Characteristic& A2lScanner::CurrentCharacteristic() {
  if (!characteristic_) {
    characteristic_ = std::make_unique<Characteristic>();
  }
  return *characteristic_;
}

CompuMethod& A2lScanner::CurrentCompuMethod() {
  if (!compu_method_) {
    compu_method_ = std::make_unique<CompuMethod>();
  }
  return *compu_method_;
}

CompuTab& A2lScanner::CurrentCompuTab() {
  if (!compu_tab_) {
    compu_tab_ = std::make_unique<CompuTab>();
  }
  return *compu_tab_;
}

CompuVtab& A2lScanner::CurrentCompuVtab() {
  if (!compu_vtab_) {
    compu_vtab_ = std::make_unique<CompuVtab>();
  }
  return *compu_vtab_;
}

CompuVtabRange& A2lScanner::CurrentCompuVtabRange() {
  if (!compu_vtab_range_) {
    compu_vtab_range_ = std::make_unique<CompuVtabRange>();
  }
  return *compu_vtab_range_;
}

Frame& A2lScanner::CurrentFrame() {
  if (!frame_) {
    frame_ = std::make_unique<Frame>();
  }
  return *frame_;
}

Function& A2lScanner::CurrentFunction() {
  if (!function_) {
    function_ = std::make_unique<Function>();
  }
  return *function_;
}

Group& A2lScanner::CurrentGroup() {
  if (!group_) {
    group_ = std::make_unique<Group>();
  }
  return *group_;
}

Instance& A2lScanner::CurrentInstance() {
  if (!instance_) {
    instance_ = std::make_unique<Instance>();
  }
  return *instance_;
}

Overwrite& A2lScanner::CurrentOverwrite() {
  if (!overwrite_) {
    overwrite_ = std::make_unique<Overwrite>();
  }
  return *overwrite_;
}

Measurement& A2lScanner::CurrentMeasurement() {
  if (!measurement_) {
    measurement_ = std::make_unique<Measurement>();
  }
  return *measurement_;
}

RecordLayout& A2lScanner::CurrentRecordLayout() {
  if (!record_layout_) {
    record_layout_ = std::make_unique<RecordLayout>();
  }
  return *record_layout_;
}

Transformer& A2lScanner::CurrentTransformer() {
  if (!transformer_) {
    transformer_ = std::make_unique<Transformer>();
  }
  return *transformer_;
}

AxisPts& A2lScanner::CurrentTypedefAxis() {
  if (!typedef_axis_) {
    typedef_axis_ = std::make_unique<AxisPts>();
  }
  return *typedef_axis_;
}

Blob& A2lScanner::CurrentTypedefBlob() {
  if (!typedef_blob_) {
    typedef_blob_ = std::make_unique<Blob>();
    typedef_blob_->AddressType(A2lAddressType::DIRECT);
  }
  return *typedef_blob_;
}

Characteristic& A2lScanner::CurrentTypedefCharacteristic() {
  if (!typedef_characteristic_) {
    typedef_characteristic_ = std::make_unique<Characteristic>();
  }
  return *typedef_characteristic_;
}

Measurement& A2lScanner::CurrentTypedefMeasurement() {
  if (!typedef_measurement_) {
    typedef_measurement_ = std::make_unique<Measurement>();
  }
  return *typedef_measurement_;
}

Structure& A2lScanner::CurrentTypedefStructure() {
  if (!typedef_structure_) {
    typedef_structure_ = std::make_unique<Structure>();
  }
  return *typedef_structure_;
}

A2lStructureComponent& A2lScanner::CurrentStructureComponent() {
  if (!structure_component_) {
    structure_component_ = std::make_unique<A2lStructureComponent>();
  }
  return *structure_component_;
}

Unit& A2lScanner::CurrentUnit() {
  if (!unit_) {
    unit_ = std::make_unique<Unit>();
  }
  return *unit_;
}

A2lUserRight& A2lScanner::CurrentUserRight() {
  if (!user_right_) {
    user_right_ = std::make_unique<A2lUserRight>();
  }
  return *user_right_;
}

void A2lScanner::FixIncludeFile() {
  // I shall read in "<file path>" but also <file_path> should work
  // Skip white space and '"' characters

  std::ostringstream file_path;
  for (auto data = yyinput(); data != '\0' ; data = yyinput()) {
    if (std::isspace(data)) {
      continue;
    }
    if (data == '"') {
      continue;
    }
    file_path << static_cast<char>(data);
    break;
  }

  for (auto input = yyinput(); input != '\0' ; input = yyinput()) {
    if (std::isspace(input)) {
      break;
    }
    if (input == '"') {
      break;
    }
    file_path << static_cast<char>(input);
  }

  std::string include_file;
  std::string file_extension;
  try {
    const path fullname(file_path.str());
    if (fullname.is_absolute() ) {
      if (exists(fullname)) {
        include_file = fullname.string();
        file_extension = fullname.extension().string();
      } else {
        // File doesn't exists
        std::ostringstream err;
        err << "File doesn't exist. File: " << fullname;
        throw std::runtime_error(err.str());
      }
    } else {
      // Relative path assume the file should be relative the input_file
      path input_file(InputFile()); // Current filename with path
      input_file.replace_filename(fullname);
      if (exists(input_file)) {
        include_file = input_file.string();
        file_extension = input_file.extension().string();
      } else {
        // File doesn't exists
        std::ostringstream err;
        err << "File doesn't exist. File: " << InputFile();
        throw std::runtime_error(err.str());
      }
    }
  }
  catch (const std::exception& error) {
    std::ostringstream err;
    err << "Include file path error. Error: " << error.what() << ", File: " << file_path.str();
    throw std::runtime_error(err.str());
  }

  // The included file exist but if the extension is A2L then
  // it could be an existing A2L but the current parser already defined a
  // PROJECT tag. To solve this try to parse the A2L file and if it succeeds,
  // merge in that MODULE into the module list of the other project.
  if (A2lHelper::stricmp(file_extension.c_str(), ".a2l") == 0) {
    A2lFile temp_file;
    temp_file.Filename(include_file);
    const bool parse = temp_file.ParseFile();
    if (parse && parent_ != nullptr) {
      // Move the project to the original project
      parent_->Merge(temp_file);
      return;
    }

    // Continue with plan B that includes the file according to the standard.
  }
  // The include file exist. Store the current state and switch to the new file.
  // Note that the <<EOF>> function in the lexer file will restore the state to
  // the old one.
  FileItem& current_item = file_stack_.back();
  current_item.buffer_state = yy_buffer_stack[yy_buffer_stack_top];

    // Switch to the include file
  file_stack_.emplace_back(include_file);
  auto& new_stack = file_stack_.back();
  ReadAndConvertFile(new_stack.file, new_stack.utf8_stream);
  new_stack.buffer_state = yy_create_buffer(new_stack.utf8_stream, 16384);

  a2lFlexLexer::yy_switch_to_buffer(new_stack.buffer_state);

}

void A2lScanner::InputFile(std::string filename) {
  if (!file_stack_.empty()) {
    file_stack_.back().file = std::move(filename);
  }
}

std::string A2lScanner::InputFile() const {
  return file_stack_.empty() ? "" : file_stack_.back().file;
}

void A2lScanner::Parent(A2lFile *parent) {
  parent_ = parent;
}

}  // namespace a2l