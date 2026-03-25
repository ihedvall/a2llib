/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include <cstdint>
#include <deque>

#include "a2l/a2lobject.h"


namespace a2l {

class Transformer : public A2lObject {
 public:
  void Version(std::string version) { version_ = std::move(version); }
  [[nodiscard]] const std::string& Version() const {return version_; }

  void Executable32(std::string exe) { executable32_ = std::move(exe); }
  [[nodiscard]] const std::string& Executable32() const { return executable32_; }

  void Executable64(std::string exe) { executable64_ = std::move(exe); }
  [[nodiscard]] const std::string& Executable64() const { return executable64_; }

  void Timeout(uint64_t timeout) { timeout_ = timeout; }
  [[nodiscard]] uint64_t Timeout() const {return timeout_; }

  void Trigger(A2lTrigger trigger) { trigger_ = trigger; }
  [[nodiscard]] A2lTrigger Trigger() const { return trigger_; }

  void InverseTransformer(std::string inverse) {
    inverse_transformer_ = std::move(inverse);
  }
  [[nodiscard]] const std::string& InverseTransformer() const {
    return inverse_transformer_;
  }

  void TransformerInObjects(std::deque<std::string> list) {
    in_object_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& TransformerInObjects() const {
    return in_object_list_;
  }

  void TransformerOutObjects(std::deque<std::string> list) {
    out_object_list_ = std::move(list);
  }
  [[nodiscard]] const std::deque<std::string>& TransformerOutObjects() const {
    return out_object_list_;
  }

 private:
  std::string version_;
  std::string executable32_;
  std::string executable64_;
  uint64_t timeout_ = 0;
  A2lTrigger trigger_ = A2lTrigger::UNKNOWN;
  std::string inverse_transformer_;
  std::deque<std::string> in_object_list_;
  std::deque<std::string> out_object_list_;
};

using TransformerList = std::unordered_map<std::string, std::unique_ptr<Transformer>>;

} // end namespace a2l
