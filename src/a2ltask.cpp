/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#include "a2l/a2ltask.h"

#include <filesystem>
#include <fstream>

using namespace std::filesystem;

namespace a2l {


void A2lTask::Reset() {
  error_message_.clear();
  result_ = false;
}

std::string A2lTask::FileToString(const std::string& filename) {
  std::string file_content;
  try {
    const std::u8string file_utf8 =
      reinterpret_cast<const char8_t*>(source_file_.c_str());
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

    file_content.reserve(size);

    std::ifstream file(file_path, std::ios::binary | std::ios::in);
    auto itr = std::istreambuf_iterator<char>(file);
    auto end = std::istreambuf_iterator<char>();
    file_content.append(itr, end);
    file.close();
  } catch (const std::exception& err) {
    std::ostringstream error;
    error << "Error reading file. Error: " << err.what() << ", File: " << filename;
    SetErrorMessage(error.str());
    file_content.clear();
  }
  return file_content;
}

} // a2l