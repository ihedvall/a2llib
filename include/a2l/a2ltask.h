/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>

#include "amlsection.h"

namespace a2l {

class A2lTask {
public:
  A2lTask() = default;
  virtual ~A2lTask() = default;

  virtual void SetSourceFile(std::string source_file) {
    source_file_ = std::move(source_file);
  }
  [[nodiscard]] const std::string& GetSourceFile() const { return source_file_; }

  void SetSourceText(std::string source_text) {
    source_text_ = std::move(source_text);
  }
  [[nodiscard]] const std::string& GetSourceText() const { return source_text_; }

  void SetErrorMessage(std::string error_message) {
    error_message_ = std::move(error_message);
    result_ = false;
  }
  [[nodiscard]] const std::string& GetErrorMessage() const {
    return error_message_;
  }

  void SetResult(bool result) { result_ = result; }
  [[nodiscard]] bool GetResult() const { return result_; }



  virtual void Run() = 0;
  virtual void Reset();

protected:

  std::string FileToString(const std::string& file_name);
private:
  std::string source_file_;
  std::string source_text_;
  std::string error_message_;
  bool result_ = false;


};

}  // namespace a2l


