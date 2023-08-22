/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
/** \file a2lfile.h
 * \brief The A2L file object is the main user object.
 */
#pragma once
#include <string>
#include <memory>
#include <sstream>

namespace a2l {

enum class A2lEncoding : int {
  UTF32_BE  = 0,
  UTF32_LE,
  UTF16_BE,
  UTF16_LE,
  UTF8,
  ASCII
};

/** \brief Main user object that is an interface against an A2L file.
 *
 * The A2L file is the only object the user shall create. It handle the parsing
 * of the file. An A2L file defines an ECU and optional hoe it communicate.
 */
class A2lFile {
 public:
  /** \brief Sets the file name. Full path required. */
  void Filename(const std::string& filename) {filename_ = filename; }
  /** \brief Returns the file name with full path. */
  [[nodiscard]] const std::string& Filename() const {return filename_; }

  /** \brief Returns the File name without path and extension. */
  [[nodiscard]] std::string Name() const;

  /** \brief Returns the last (parser) error text. */
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  [[nodiscard]] std::string Content() const { return content_.str(); }

  /** \brief Parses the A2L file. Returns true on success. */
  [[nodiscard]] bool ParseFile();


 private:
  std::string filename_; ///< Full path name
  mutable std::string  last_error_; ///< Last error message
  std::istringstream content_; ///< File content converted to UTF8
  A2lEncoding encoding_ = A2lEncoding::ASCII;

  void ReadAndConvertFile();
};

}  // namespace dbc
