/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
/** \file a2lfile.h
 * \brief The A2L file object is the main user object.
 */
#pragma once
#include <memory>
#include <sstream>
#include <string>

#include "a2l/a2lproject.h"
#include "a2l/a2lstructs.h"
namespace a2l {

enum class FileEncoding : int {
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

  [[nodiscard]] Asap2Version& A2lVersion() { return a2l_version_; }
  [[nodiscard]] Asap2Version& A2mlVersion() { return a2ml_version_; }
  [[nodiscard]] A2lProject& Project() { return project_; }

 private:
  std::string filename_; ///< Full path name
  mutable std::string  last_error_; ///< Last error message
  std::istringstream content_; ///< File content converted to UTF8
  FileEncoding encoding_ = FileEncoding::ASCII;

  Asap2Version a2l_version_;
  Asap2Version a2ml_version_;
  A2lProject project_;

  void ReadAndConvertFile();
};

}  // namespace dbc
