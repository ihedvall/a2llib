/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <map>
#include <memory>
#include <string>
#include <cstdint>
#include <vector>

#include "a2l/a2lobject.h"


namespace a2l {

class Transformer : public A2lObject {
 public:
  void Version(const std::string& version) { version_ = version; }
  [[nodiscard]] const std::string& Version() const {return version_; }

  void Executable32(const std::string& exe) { executable32_ = exe; }
  [[nodiscard]] const std::string& Executable32() const {return executable32_; }

  void Executable64(const std::string& exe) { executable64_ = exe; }
  [[nodiscard]] const std::string& Executable64() const {return executable64_; }

  void Timeout(uint64_t timeout) { timeout_ = timeout; }
  [[nodiscard]] uint64_t Timeout() const {return timeout_; }

  void Trigger(A2lTrigger trigger) { trigger_ = trigger; }
  [[nodiscard]] A2lTrigger Trigger() const { return trigger_; }

  void InverseTransformer(const std::string& inverse) {
    inverse_transformer_ = inverse;
  }
  [[nodiscard]] const std::string& InverseTransformer() const {
    return inverse_transformer_;
  }

  void TransformerInObjects(const std::vector<std::string>& list) {
    in_object_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& TransformerInObjects() const {
    return in_object_list_;
  }

  void TransformerOutObjects(const std::vector<std::string>& list) {
    out_object_list_ = list;
  }
  [[nodiscard]] const std::vector<std::string>& TransformerOutObjects() const {
    return out_object_list_;
  }

 private:
  std::string version_;
  std::string executable32_;
  std::string executable64_;
  uint64_t timeout_ = 0;
  A2lTrigger trigger_ = A2lTrigger::UNKNOWN;
  std::string inverse_transformer_;
  std::vector<std::string> in_object_list_;
  std::vector<std::string> out_object_list_;
};

using TransformerList = std::map<std::string, std::unique_ptr<Transformer>>;

} // end namespace a2l
