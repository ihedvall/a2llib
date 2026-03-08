/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
/** \file a2lfile.h
 * \brief The A2L file object is the main user object.
 */
#pragma once
#include <string>
#include <functional>
#include <thread>
#include <atomic>


#include "a2l/a2lproject.h"
#include "a2l/a2lstructs.h"
namespace a2l {

class A2lScanner;

using A2lReadyFunction = std::function<void(bool)>;

/** \brief Main user object that is an interface against an A2L file.
 *
 * The A2L file is the only object the user shall create. It handle the parsing
 * of the file. An A2L file defines an ECU and optional hoe it communicate.
 */
class A2lFile {
 public:
  virtual ~A2lFile();
  /** \brief Sets the file name. Full path required. */
  void Filename(std::string filename) {filename_ = std::move(filename); }
  /** \brief Returns the file name with full path. */
  [[nodiscard]] const std::string& Filename() const {return filename_; }

  /** \brief Returns the File name without path and extension. */
  [[nodiscard]] std::string Name() const;

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

 private:
  bool found_ = false;
  std::string filename_; ///< Full path name
  mutable std::string  last_error_; ///< Last error message
  mutable std::atomic<int> current_lineno_ = 0;
  std::atomic<int> number_of_lines_ = 0;
  Asap2Version a2l_version_;
  Asap2Version a2ml_version_;
  A2lProject project_;
  A2lReadyFunction ready_function_;
  std::thread parse_thread_;
  std::atomic<A2lScanner*> scanner_ = nullptr;

  void ParseThread();


};

}  // namespace dbc
