/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
/** \file a2lfile.h
 * \brief The A2L file object is the main user object.
 */
#pragma once

#include <cstdint>
#include <string>
#include <functional>
#include <thread>
#include <atomic>
#include <sstream>
#include <map>

#include "a2l/a2lproject.h"
#include "a2l/a2lstructs.h"
namespace a2l {
class A2lScanner;
class SelectionList;

using A2lReadyFunction = std::function<void(bool)>;

enum class A2lFileEncoding : int {
  UTF32_BE  = 0,
  UTF32_LE,
  UTF16_BE,
  UTF16_LE,
  UTF8,
  ASCII ///< ASCII means no BOM encoding in file or unknown encoding
};

enum class A2lParserType : int {
  FULL_PARSING = 0,
  PARSE_MODULE_INFORMATION_ONLY
};


/** \brief Main user object that is an interface against an A2L file.
 *
 * The A2L file is the only object the user shall create. It handle the parsing
 * of the file. An A2L file defines an ECU and optional hoe it communicate.
 */
class A2lFile {
public:
  virtual ~A2lFile();

  /** \brief Sets the A2L filename with full path.
   *
   * This function sets the A2L filename with full path..
   * Note, that this function assumes that the filename as a std::string.
   * Use the function with a wide character string instead.
   * @param filename Full path to the A2L file.
   */
  void Filename(const std::string& filename);

  /** \brief Set the A2L filename with full path.
   *
   * The function sets the A2L filename with full path.
   * Note, that this function use a wide character string.
   * @param filename Full path to the A2L file.
   */
void Filename(std::wstring filename) {
    filename_ = std::move(filename);
  }

  /** \brief Returns the file name with full path. */
  [[nodiscard]] std::string Filename() const;

  [[nodiscard]] const std::wstring& FilenameW() const {
    return filename_;
  }
  /** \brief Returns the File name without path and extension. */
  [[nodiscard]] std::string Name() const;

  void ParserType(A2lParserType parser_type) { parser_type_ = parser_type; }

  /** \brief Returns the last (parser) error text. */
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  /** \brief Parses the A2L file. Returns true on success. */
  [[nodiscard]] bool ParseFile();

  void AsynchParseFile(A2lReadyFunction ready_function);

  [[nodiscard]] Asap2Version& A2lVersion() { return a2l_version_; }
  [[nodiscard]] const Asap2Version& A2lVersion() const { return a2l_version_; }

  [[nodiscard]] Asap2Version& A2mlVersion() { return a2ml_version_; }
  [[nodiscard]] const Asap2Version& A2mlVersion() const {
    return a2ml_version_;
  }

  [[nodiscard]] A2lProject& Project() { return project_; }
  [[nodiscard]] const A2lProject& Project() const { return project_; }

  void IsA2lFile(bool is_a2l_file) { found_ = is_a2l_file; }

  [[nodiscard]] bool IsA2lFile() const { return found_; }

  void Merge(A2lFile& include_file);

  int LineNo() const;
  int NumberOfLines() const { return number_of_lines_; };
  int ProgressInfo() const;

  static int ReadAndConvertFile(const std::wstring& filename,
    std::istringstream& utf8_stream );

  void AddEncoding(const std::string& encoding);
  std::string GetEncoding() const;
  const std::map<std::string,size_t>& GetEncodingList() const {
    return encoding_list_;
  }
private:
  bool found_ = false;
  std::wstring filename_; ///< Full path name
  A2lFileEncoding encoding_ = A2lFileEncoding::ASCII;
  A2lParserType parser_type_ = A2lParserType::FULL_PARSING;

  mutable std::string  last_error_; ///< Last error message
  mutable std::atomic<int> current_lineno_ = 0;
  std::atomic<int> number_of_lines_ = 0;
  Asap2Version a2l_version_;
  Asap2Version a2ml_version_;
  A2lProject project_;
  A2lReadyFunction ready_function_;
  std::thread parse_thread_;
  std::atomic<A2lScanner*> scanner_ = nullptr;
  std::map<std::string,size_t> encoding_list_;

  void ParseThread();
  void CheckBom();
  void ConvertAllStrings(const std::string& encoding);
};

}  // namespace dbc
