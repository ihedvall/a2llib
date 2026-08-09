/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "a2l/a2llogstream.h"

#include <iostream>
#include <array>
#include <string_view>
#include <vector>
#include <chrono>
#include <format>
#include <locale>

using namespace std::chrono;
using namespace std::chrono_literals;

namespace {

std::vector<a2l::A2lLogFunction> kLogFunctionList;

constexpr std::array<std::string_view, 9> kSeverityList = {
  "Trace", "Debug", "Info",
  "Notice", "Warning", "Error",
  "Critical","Alert", "Emergency" };

a2l::A2lLogSeverity kLogLevel = a2l::A2lLogSeverity::kTrace;
bool kShowLocation = true;
}  // end namespace

namespace a2l {

A2lLogStream::A2lLogStream(std::source_location location, A2lLogSeverity severity)
    : location_(location), severity_(severity) {
  imbue(std::locale::classic());
}

A2lLogStream::~A2lLogStream() {
  A2lLogStream::LogString(location_, severity_, str());
}

void A2lLogStream::LogString(const std::source_location &location,
    A2lLogSeverity severity, const std::string &text) {
  for (const auto &func : kLogFunctionList) {
    if (func) {
      func(location, severity, text);
    }
  }
}

void A2lLogStream::SetLogFunction(const A2lLogFunction &func) {
  kLogFunctionList.emplace_back(func);
}

void A2lLogStream::ResetLogFunction() {
  kLogFunctionList.clear();
}

void A2lLogStream::LogToConsole(const std::source_location& location,
           A2lLogSeverity severity, const std::string& text) {
  if (severity < kLogLevel) {
    return;
  }
  try {
    const auto now = system_clock::now();
    const auto time_zone = current_zone();
    const auto local_time = time_zone->to_local(now);
    const hh_mm_ss time_of_day(local_time - floor<days>(local_time));
    std::ostringstream time_string;
    time_string.imbue(std::locale(""));
    time_string << std::format("{:%T}", time_of_day); ;

    std::cout << time_string.str() << " ";
    if (const auto index = static_cast<size_t>(severity);
        index < kSeverityList.size()) {
      std::cout << "[" << kSeverityList[index] << "] ";
    }

    std::cout << text;
    if (kShowLocation) {
      std::cout << " (" << location.file_name() << ":"
                << location.function_name()
                << " C:" << location.column()
                << " L:" << location.line() << ")";
    }
    std::cout << std::endl;
  } catch (const std::exception&) {

  }
}

void A2lLogStream::SetLogLevel(A2lLogSeverity severity) {
  kLogLevel = severity;
}
void A2lLogStream::ShowLocation(bool show_location) {
  kShowLocation = show_location;
}

}  // namespace mdf