/*
 * Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

/** \file a2llogstream.h
 * \brief The A2L log stream file is intended to isolate the logging so
 * the library can be built without dependency of the util library.
 */
#pragma once

#include <string>
#include <sstream>
#include <functional>
#include <source_location>

namespace a2l {

/** \brief Defines the log severity level. */
enum class A2lLogSeverity : uint8_t {
  kTrace = 0,  ///< Trace or listen message
  kDebug,      ///< Debug message
  kInfo,       ///< Informational message
  kNotice,     ///< Notice message. Notify the user.
  kWarning,    ///< Warning message
  kError,      ///< Error message
  kCritical,   ///< Critical message (device error)
  kAlert,      ///< Alert or alarm message
  kEmergency   ///< Fatal error message
};

#define A2L_TRACE() A2lLogStream(std::source_location::current(),\
                           A2lLogSeverity::kTrace) ///< Trace log message
#define A2L_DEBUG() A2lLogStream(std::source_location::current(), \
                           A2lLogSeverity::kDebug)  ///< Debug log message
#define A2L_INFO() A2lLogStream(std::source_location::current(), \
                           A2lLogSeverity::kInfo)  ///< Info log message
#define A2L_ERROR() A2lLogStream(std::source_location::current(), \
                           A2lLogSeverity::kError)  ///< Error log message

/** \brief MDF log function definition. */
using A2lLogFunction = std::function<void(const std::source_location &location,
  A2lLogSeverity severity, const std::string &text)>;

/** \brief MDF log stream interface.
 *
 *
 */
class A2lLogStream : public std::ostringstream {
 public:
  A2lLogStream(std::source_location location, A2lLogSeverity severity);  ///< Constructor
  ~A2lLogStream() override;                                    ///< Destructor

  A2lLogStream() = delete;
  A2lLogStream(const A2lLogStream&) = delete;
  A2lLogStream(A2lLogStream&&) = delete;
  A2lLogStream& operator=(const A2lLogStream&) = delete;
  A2lLogStream& operator=(A2lLogStream&&) = delete;

  /** \brief Sets a log function. */
  static void SetLogFunction(const A2lLogFunction& func);
  /** \brief Sets a log function. */
  static void ResetLogFunction();

  static void LogToConsole( const std::source_location& location,
                            A2lLogSeverity severity,
                            const std::string& text);
  static void SetLogLevel(A2lLogSeverity severity);
  static void ShowLocation(bool show_location);
 protected:
  std::source_location location_;     ///< File and function location.
  A2lLogSeverity severity_;           ///< Log level of the stream

  /** \brief Defines the logging function. */
  virtual void LogString(const std::source_location& location, A2lLogSeverity severity,
                         const std::string& text);

};

}  // namespace mdf
