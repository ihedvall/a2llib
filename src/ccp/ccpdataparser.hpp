// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file D:/projects/a2llib/src/ccp/ccpdataparser.hpp
 ** Define the a2l::ccp::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_CCP_D_PROJECTS_A2LLIB_SRC_CCP_CCPDATAPARSER_HPP_INCLUDED
# define YY_CCP_D_PROJECTS_A2LLIB_SRC_CCP_CCPDATAPARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 10 "D:/projects/a2llib/src/ccp/ccpdataparser.y"

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/ccp/kpblob.h"
#include "a2l/ccp/dpblob.h"
#include "a2l/ccp/addressmapping.h"
#include "a2l/ccp/definedpages.h"
#include "a2l/ccp/checksumparam.h"
#include "a2l/ccp/canparam.h"
#include "a2l/ccp/tpblob.h"
#include "a2l/ccp/seedkey.h"
#include "a2l/ccp/eventgroup.h"
#include "a2l/ccp/raster.h"
#include "a2l/ccp/qpblob.h"
#include "a2l/ccp/source.h"

namespace a2l::ccp {
class CcpDataScanner;
}


#line 74 "D:/projects/a2llib/src/ccp/ccpdataparser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef CCPDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define CCPDEBUG 1
#  else
#   define CCPDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define CCPDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined CCPDEBUG */

#line 6 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
namespace a2l { namespace ccp {
#line 218 "D:/projects/a2llib/src/ccp/ccpdataparser.hpp"




  /// A Bison parser.
  class CcpDataParser
  {
  public:
#ifdef CCPSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define CCPSTYPE in C++, use %define api.value.type"
# endif
    typedef CCPSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // addr_mapping
      char dummy1[sizeof (AddressMapping)];

      // can_param
      char dummy2[sizeof (CanParam)];

      // checksum_param
      char dummy3[sizeof (ChecksumParam)];

      // defined_pages
      char dummy4[sizeof (DefinedPages)];

      // dp_blob
      char dummy5[sizeof (DpBlob)];

      // event_group
      char dummy6[sizeof (EventGroup)];

      // kp_blob
      char dummy7[sizeof (KpBlob)];

      // qp_blob
      char dummy8[sizeof (QpBlob)];

      // raster
      char dummy9[sizeof (Raster)];

      // seed_key
      char dummy10[sizeof (SeedKey)];

      // source
      char dummy11[sizeof (Source)];

      // tp_blob
      char dummy12[sizeof (TpBlob)];

      // FLOAT
      char dummy13[sizeof (double)];

      // INT
      // exclusive
      // any_int
      char dummy14[sizeof (int64_t)];

      // IDENT
      // STRING
      // checksum
      // checksum_calculation
      // ident_or_string
      char dummy15[sizeof (std::string)];

      // exclusive_list
      // raster_list
      char dummy16[sizeof (std::vector<uint8_t>)];

      // UINT
      // HEX
      char dummy17[sizeof (uint64_t)];

      // raster_value
      char dummy18[sizeof (uint8_t)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        CCPEMPTY = -2,
    CCPEOF = 0,                    // "end of file"
    CCPerror = 256,                // error
    CCPUNDEF = 257,                // "invalid token"
    UINT = 258,                    // UINT
    HEX = 259,                     // HEX
    INT = 260,                     // INT
    FLOAT = 261,                   // FLOAT
    IDENT = 262,                   // IDENT
    STRING = 263,                  // STRING
    ADDRESS_EXTENSION = 264,       // ADDRESS_EXTENSION
    ADDR_MAPPING = 265,            // ADDR_MAPPING
    ALTERNATING = 266,             // ALTERNATING
    ASAP1B_CCP = 267,              // ASAP1B_CCP
    AUTO_FLASH_BACK = 268,         // AUTO_FLASH_BACK
    BAUDRATE = 269,                // BAUDRATE
    BLOCK_BEGIN = 270,             // BLOCK_BEGIN
    BLOCK_END = 271,               // BLOCK_END
    BTL_CYCLES = 272,              // BTL_CYCLES
    BYTES_ONLY = 273,              // BYTES_ONLY
    CAN_ID_FIXED = 274,            // CAN_ID_FIXED
    CAN_ID_VARIABLE = 275,         // CAN_ID_VARIABLE
    CAN_PARAM = 276,               // CAN_PARAM
    CHECKSUM = 277,                // CHECKSUM
    CHECKSUM_CALCULATION = 278,    // CHECKSUM_CALCULATION
    CHECKSUM_PARAM = 279,          // CHECKSUM_PARAM
    CONSISTENCY = 280,             // CONSISTENCY
    DAQ_MODE = 281,                // DAQ_MODE
    DEFINED_PAGES = 282,           // DEFINED_PAGES
    DEFAULT = 283,                 // DEFAULT
    DISPLAY_IDENTIFIER = 284,      // DISPLAY_IDENTIFIER
    DP_BLOB = 285,                 // DP_BLOB
    DP_BLOB_VERSION = 286,         // DP_BLOB_VERSION
    EEPROM = 287,                  // EEPROM
    EVENT_GROUP = 288,             // EVENT_GROUP
    EXCLUSIVE = 289,               // EXCLUSIVE
    FIRST_PID = 290,               // FIRST_PID
    FLASH = 291,                   // FLASH
    FLASH_BACK = 292,              // FLASH_BACK
    IF_DATA = 293,                 // IF_DATA
    KP_BLOB = 294,                 // KP_BLOB
    LENGTH = 295,                  // LENGTH
    OPTIONAL_CMD = 296,            // OPTIONAL_CMD
    QP_BLOB = 297,                 // QP_BLOB
    RAM = 298,                     // RAM
    RAM_INIT_BY_ECU = 299,         // RAM_INIT_BY_ECU
    RAM_INIT_BY_TOOL = 300,        // RAM_INIT_BY_TOOL
    RASTER = 301,                  // RASTER
    REDUCTION_ALLOWED = 302,       // REDUCTION_ALLOWED
    RESUME_SUPPORTED = 303,        // RESUME_SUPPORTED
    ROM = 304,                     // ROM
    SAMPLE_POINT = 305,            // SAMPLE_POINT
    SAMPLE_RATE = 306,             // SAMPLE_RATE
    SEED_KEY = 307,                // SEED_KEY
    SINGLE = 308,                  // SINGLE
    SJW = 309,                     // SJW
    SOURCE = 310,                  // SOURCE
    STORE_SUPPORTED = 311,         // STORE_SUPPORTED
    SYNC_EDGE = 312,               // SYNC_EDGE
    TP_BLOB = 313                  // TP_BLOB
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 59, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_UINT = 3,                              // UINT
        S_HEX = 4,                               // HEX
        S_INT = 5,                               // INT
        S_FLOAT = 6,                             // FLOAT
        S_IDENT = 7,                             // IDENT
        S_STRING = 8,                            // STRING
        S_ADDRESS_EXTENSION = 9,                 // ADDRESS_EXTENSION
        S_ADDR_MAPPING = 10,                     // ADDR_MAPPING
        S_ALTERNATING = 11,                      // ALTERNATING
        S_ASAP1B_CCP = 12,                       // ASAP1B_CCP
        S_AUTO_FLASH_BACK = 13,                  // AUTO_FLASH_BACK
        S_BAUDRATE = 14,                         // BAUDRATE
        S_BLOCK_BEGIN = 15,                      // BLOCK_BEGIN
        S_BLOCK_END = 16,                        // BLOCK_END
        S_BTL_CYCLES = 17,                       // BTL_CYCLES
        S_BYTES_ONLY = 18,                       // BYTES_ONLY
        S_CAN_ID_FIXED = 19,                     // CAN_ID_FIXED
        S_CAN_ID_VARIABLE = 20,                  // CAN_ID_VARIABLE
        S_CAN_PARAM = 21,                        // CAN_PARAM
        S_CHECKSUM = 22,                         // CHECKSUM
        S_CHECKSUM_CALCULATION = 23,             // CHECKSUM_CALCULATION
        S_CHECKSUM_PARAM = 24,                   // CHECKSUM_PARAM
        S_CONSISTENCY = 25,                      // CONSISTENCY
        S_DAQ_MODE = 26,                         // DAQ_MODE
        S_DEFINED_PAGES = 27,                    // DEFINED_PAGES
        S_DEFAULT = 28,                          // DEFAULT
        S_DISPLAY_IDENTIFIER = 29,               // DISPLAY_IDENTIFIER
        S_DP_BLOB = 30,                          // DP_BLOB
        S_DP_BLOB_VERSION = 31,                  // DP_BLOB_VERSION
        S_EEPROM = 32,                           // EEPROM
        S_EVENT_GROUP = 33,                      // EVENT_GROUP
        S_EXCLUSIVE = 34,                        // EXCLUSIVE
        S_FIRST_PID = 35,                        // FIRST_PID
        S_FLASH = 36,                            // FLASH
        S_FLASH_BACK = 37,                       // FLASH_BACK
        S_IF_DATA = 38,                          // IF_DATA
        S_KP_BLOB = 39,                          // KP_BLOB
        S_LENGTH = 40,                           // LENGTH
        S_OPTIONAL_CMD = 41,                     // OPTIONAL_CMD
        S_QP_BLOB = 42,                          // QP_BLOB
        S_RAM = 43,                              // RAM
        S_RAM_INIT_BY_ECU = 44,                  // RAM_INIT_BY_ECU
        S_RAM_INIT_BY_TOOL = 45,                 // RAM_INIT_BY_TOOL
        S_RASTER = 46,                           // RASTER
        S_REDUCTION_ALLOWED = 47,                // REDUCTION_ALLOWED
        S_RESUME_SUPPORTED = 48,                 // RESUME_SUPPORTED
        S_ROM = 49,                              // ROM
        S_SAMPLE_POINT = 50,                     // SAMPLE_POINT
        S_SAMPLE_RATE = 51,                      // SAMPLE_RATE
        S_SEED_KEY = 52,                         // SEED_KEY
        S_SINGLE = 53,                           // SINGLE
        S_SJW = 54,                              // SJW
        S_SOURCE = 55,                           // SOURCE
        S_STORE_SUPPORTED = 56,                  // STORE_SUPPORTED
        S_SYNC_EDGE = 57,                        // SYNC_EDGE
        S_TP_BLOB = 58,                          // TP_BLOB
        S_YYACCEPT = 59,                         // $accept
        S_ccp_data_block = 60,                   // ccp_data_block
        S_if_data = 61,                          // if_data
        S_definitions = 62,                      // definitions
        S_definition = 63,                       // definition
        S_source = 64,                           // source
        S_source_options = 65,                   // source_options
        S_source_option = 66,                    // source_option
        S_qp_blob = 67,                          // qp_blob
        S_qp_blob_options = 68,                  // qp_blob_options
        S_qp_blob_option = 69,                   // qp_blob_option
        S_raster = 70,                           // raster
        S_event_group = 71,                      // event_group
        S_seed_key = 72,                         // seed_key
        S_checksum = 73,                         // checksum
        S_tp_blob = 74,                          // tp_blob
        S_tp_blob_options = 75,                  // tp_blob_options
        S_tp_blob_option = 76,                   // tp_blob_option
        S_can_param = 77,                        // can_param
        S_checksum_param = 78,                   // checksum_param
        S_checksum_calculation = 79,             // checksum_calculation
        S_defined_pages = 80,                    // defined_pages
        S_defined_pages_options = 81,            // defined_pages_options
        S_defined_pages_option = 82,             // defined_pages_option
        S_addr_mapping = 83,                     // addr_mapping
        S_dp_blob = 84,                          // dp_blob
        S_kp_blob = 85,                          // kp_blob
        S_exclusive_list = 86,                   // exclusive_list
        S_exclusive = 87,                        // exclusive
        S_raster_list = 88,                      // raster_list
        S_raster_value = 89,                     // raster_value
        S_any_int = 90,                          // any_int
        S_ident_or_string = 91                   // ident_or_string
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.move< AddressMapping > (std::move (that.value));
        break;

      case symbol_kind::S_can_param: // can_param
        value.move< CanParam > (std::move (that.value));
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.move< ChecksumParam > (std::move (that.value));
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.move< DefinedPages > (std::move (that.value));
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.move< DpBlob > (std::move (that.value));
        break;

      case symbol_kind::S_event_group: // event_group
        value.move< EventGroup > (std::move (that.value));
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.move< KpBlob > (std::move (that.value));
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.move< QpBlob > (std::move (that.value));
        break;

      case symbol_kind::S_raster: // raster
        value.move< Raster > (std::move (that.value));
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.move< SeedKey > (std::move (that.value));
        break;

      case symbol_kind::S_source: // source
        value.move< Source > (std::move (that.value));
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.move< TpBlob > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (std::move (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.move< std::vector<uint8_t> > (std::move (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (std::move (that.value));
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.move< uint8_t > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AddressMapping&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AddressMapping& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, CanParam&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const CanParam& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ChecksumParam&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ChecksumParam& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DefinedPages&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DefinedPages& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DpBlob&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DpBlob& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, EventGroup&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const EventGroup& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, KpBlob&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const KpBlob& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, QpBlob&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const QpBlob& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Raster&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Raster& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SeedKey&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SeedKey& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Source&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Source& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TpBlob&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TpBlob& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, int64_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const int64_t& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<uint8_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<uint8_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, uint64_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const uint64_t& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, uint8_t&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const uint8_t& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_addr_mapping: // addr_mapping
        value.template destroy< AddressMapping > ();
        break;

      case symbol_kind::S_can_param: // can_param
        value.template destroy< CanParam > ();
        break;

      case symbol_kind::S_checksum_param: // checksum_param
        value.template destroy< ChecksumParam > ();
        break;

      case symbol_kind::S_defined_pages: // defined_pages
        value.template destroy< DefinedPages > ();
        break;

      case symbol_kind::S_dp_blob: // dp_blob
        value.template destroy< DpBlob > ();
        break;

      case symbol_kind::S_event_group: // event_group
        value.template destroy< EventGroup > ();
        break;

      case symbol_kind::S_kp_blob: // kp_blob
        value.template destroy< KpBlob > ();
        break;

      case symbol_kind::S_qp_blob: // qp_blob
        value.template destroy< QpBlob > ();
        break;

      case symbol_kind::S_raster: // raster
        value.template destroy< Raster > ();
        break;

      case symbol_kind::S_seed_key: // seed_key
        value.template destroy< SeedKey > ();
        break;

      case symbol_kind::S_source: // source
        value.template destroy< Source > ();
        break;

      case symbol_kind::S_tp_blob: // tp_blob
        value.template destroy< TpBlob > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_exclusive: // exclusive
      case symbol_kind::S_any_int: // any_int
        value.template destroy< int64_t > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_checksum: // checksum
      case symbol_kind::S_checksum_calculation: // checksum_calculation
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_exclusive_list: // exclusive_list
      case symbol_kind::S_raster_list: // raster_list
        value.template destroy< std::vector<uint8_t> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.template destroy< uint64_t > ();
        break;

      case symbol_kind::S_raster_value: // raster_value
        value.template destroy< uint8_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if CCPDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return CcpDataParser::symbol_name (this->kind ());
      }
#endif // #if CCPDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const double& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, int64_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const int64_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, uint64_t v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const uint64_t& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    CcpDataParser (a2l::ccp::CcpDataScanner &scanner_yyarg);
    virtual ~CcpDataParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    CcpDataParser (const CcpDataParser&) = delete;
    /// Non copyable.
    CcpDataParser& operator= (const CcpDataParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if CCPDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if CCPDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if CCPDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CCPEOF ()
      {
        return symbol_type (token::CCPEOF);
      }
#else
      static
      symbol_type
      make_CCPEOF ()
      {
        return symbol_type (token::CCPEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CCPerror ()
      {
        return symbol_type (token::CCPerror);
      }
#else
      static
      symbol_type
      make_CCPerror ()
      {
        return symbol_type (token::CCPerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CCPUNDEF ()
      {
        return symbol_type (token::CCPUNDEF);
      }
#else
      static
      symbol_type
      make_CCPUNDEF ()
      {
        return symbol_type (token::CCPUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT (uint64_t v)
      {
        return symbol_type (token::UINT, std::move (v));
      }
#else
      static
      symbol_type
      make_UINT (const uint64_t& v)
      {
        return symbol_type (token::UINT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEX (uint64_t v)
      {
        return symbol_type (token::HEX, std::move (v));
      }
#else
      static
      symbol_type
      make_HEX (const uint64_t& v)
      {
        return symbol_type (token::HEX, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (int64_t v)
      {
        return symbol_type (token::INT, std::move (v));
      }
#else
      static
      symbol_type
      make_INT (const int64_t& v)
      {
        return symbol_type (token::INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (double v)
      {
        return symbol_type (token::FLOAT, std::move (v));
      }
#else
      static
      symbol_type
      make_FLOAT (const double& v)
      {
        return symbol_type (token::FLOAT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (std::string v)
      {
        return symbol_type (token::IDENT, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENT (const std::string& v)
      {
        return symbol_type (token::IDENT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v)
      {
        return symbol_type (token::STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v)
      {
        return symbol_type (token::STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDRESS_EXTENSION ()
      {
        return symbol_type (token::ADDRESS_EXTENSION);
      }
#else
      static
      symbol_type
      make_ADDRESS_EXTENSION ()
      {
        return symbol_type (token::ADDRESS_EXTENSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDR_MAPPING ()
      {
        return symbol_type (token::ADDR_MAPPING);
      }
#else
      static
      symbol_type
      make_ADDR_MAPPING ()
      {
        return symbol_type (token::ADDR_MAPPING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALTERNATING ()
      {
        return symbol_type (token::ALTERNATING);
      }
#else
      static
      symbol_type
      make_ALTERNATING ()
      {
        return symbol_type (token::ALTERNATING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASAP1B_CCP ()
      {
        return symbol_type (token::ASAP1B_CCP);
      }
#else
      static
      symbol_type
      make_ASAP1B_CCP ()
      {
        return symbol_type (token::ASAP1B_CCP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AUTO_FLASH_BACK ()
      {
        return symbol_type (token::AUTO_FLASH_BACK);
      }
#else
      static
      symbol_type
      make_AUTO_FLASH_BACK ()
      {
        return symbol_type (token::AUTO_FLASH_BACK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BAUDRATE ()
      {
        return symbol_type (token::BAUDRATE);
      }
#else
      static
      symbol_type
      make_BAUDRATE ()
      {
        return symbol_type (token::BAUDRATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BLOCK_BEGIN ()
      {
        return symbol_type (token::BLOCK_BEGIN);
      }
#else
      static
      symbol_type
      make_BLOCK_BEGIN ()
      {
        return symbol_type (token::BLOCK_BEGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BLOCK_END ()
      {
        return symbol_type (token::BLOCK_END);
      }
#else
      static
      symbol_type
      make_BLOCK_END ()
      {
        return symbol_type (token::BLOCK_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BTL_CYCLES ()
      {
        return symbol_type (token::BTL_CYCLES);
      }
#else
      static
      symbol_type
      make_BTL_CYCLES ()
      {
        return symbol_type (token::BTL_CYCLES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BYTES_ONLY ()
      {
        return symbol_type (token::BYTES_ONLY);
      }
#else
      static
      symbol_type
      make_BYTES_ONLY ()
      {
        return symbol_type (token::BYTES_ONLY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_FIXED ()
      {
        return symbol_type (token::CAN_ID_FIXED);
      }
#else
      static
      symbol_type
      make_CAN_ID_FIXED ()
      {
        return symbol_type (token::CAN_ID_FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_VARIABLE ()
      {
        return symbol_type (token::CAN_ID_VARIABLE);
      }
#else
      static
      symbol_type
      make_CAN_ID_VARIABLE ()
      {
        return symbol_type (token::CAN_ID_VARIABLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_PARAM ()
      {
        return symbol_type (token::CAN_PARAM);
      }
#else
      static
      symbol_type
      make_CAN_PARAM ()
      {
        return symbol_type (token::CAN_PARAM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHECKSUM ()
      {
        return symbol_type (token::CHECKSUM);
      }
#else
      static
      symbol_type
      make_CHECKSUM ()
      {
        return symbol_type (token::CHECKSUM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHECKSUM_CALCULATION ()
      {
        return symbol_type (token::CHECKSUM_CALCULATION);
      }
#else
      static
      symbol_type
      make_CHECKSUM_CALCULATION ()
      {
        return symbol_type (token::CHECKSUM_CALCULATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHECKSUM_PARAM ()
      {
        return symbol_type (token::CHECKSUM_PARAM);
      }
#else
      static
      symbol_type
      make_CHECKSUM_PARAM ()
      {
        return symbol_type (token::CHECKSUM_PARAM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSISTENCY ()
      {
        return symbol_type (token::CONSISTENCY);
      }
#else
      static
      symbol_type
      make_CONSISTENCY ()
      {
        return symbol_type (token::CONSISTENCY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_MODE ()
      {
        return symbol_type (token::DAQ_MODE);
      }
#else
      static
      symbol_type
      make_DAQ_MODE ()
      {
        return symbol_type (token::DAQ_MODE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFINED_PAGES ()
      {
        return symbol_type (token::DEFINED_PAGES);
      }
#else
      static
      symbol_type
      make_DEFINED_PAGES ()
      {
        return symbol_type (token::DEFINED_PAGES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT ()
      {
        return symbol_type (token::DEFAULT);
      }
#else
      static
      symbol_type
      make_DEFAULT ()
      {
        return symbol_type (token::DEFAULT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DISPLAY_IDENTIFIER ()
      {
        return symbol_type (token::DISPLAY_IDENTIFIER);
      }
#else
      static
      symbol_type
      make_DISPLAY_IDENTIFIER ()
      {
        return symbol_type (token::DISPLAY_IDENTIFIER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DP_BLOB ()
      {
        return symbol_type (token::DP_BLOB);
      }
#else
      static
      symbol_type
      make_DP_BLOB ()
      {
        return symbol_type (token::DP_BLOB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DP_BLOB_VERSION ()
      {
        return symbol_type (token::DP_BLOB_VERSION);
      }
#else
      static
      symbol_type
      make_DP_BLOB_VERSION ()
      {
        return symbol_type (token::DP_BLOB_VERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EEPROM ()
      {
        return symbol_type (token::EEPROM);
      }
#else
      static
      symbol_type
      make_EEPROM ()
      {
        return symbol_type (token::EEPROM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EVENT_GROUP ()
      {
        return symbol_type (token::EVENT_GROUP);
      }
#else
      static
      symbol_type
      make_EVENT_GROUP ()
      {
        return symbol_type (token::EVENT_GROUP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLUSIVE ()
      {
        return symbol_type (token::EXCLUSIVE);
      }
#else
      static
      symbol_type
      make_EXCLUSIVE ()
      {
        return symbol_type (token::EXCLUSIVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIRST_PID ()
      {
        return symbol_type (token::FIRST_PID);
      }
#else
      static
      symbol_type
      make_FIRST_PID ()
      {
        return symbol_type (token::FIRST_PID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLASH ()
      {
        return symbol_type (token::FLASH);
      }
#else
      static
      symbol_type
      make_FLASH ()
      {
        return symbol_type (token::FLASH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLASH_BACK ()
      {
        return symbol_type (token::FLASH_BACK);
      }
#else
      static
      symbol_type
      make_FLASH_BACK ()
      {
        return symbol_type (token::FLASH_BACK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF_DATA ()
      {
        return symbol_type (token::IF_DATA);
      }
#else
      static
      symbol_type
      make_IF_DATA ()
      {
        return symbol_type (token::IF_DATA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_KP_BLOB ()
      {
        return symbol_type (token::KP_BLOB);
      }
#else
      static
      symbol_type
      make_KP_BLOB ()
      {
        return symbol_type (token::KP_BLOB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LENGTH ()
      {
        return symbol_type (token::LENGTH);
      }
#else
      static
      symbol_type
      make_LENGTH ()
      {
        return symbol_type (token::LENGTH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPTIONAL_CMD ()
      {
        return symbol_type (token::OPTIONAL_CMD);
      }
#else
      static
      symbol_type
      make_OPTIONAL_CMD ()
      {
        return symbol_type (token::OPTIONAL_CMD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_QP_BLOB ()
      {
        return symbol_type (token::QP_BLOB);
      }
#else
      static
      symbol_type
      make_QP_BLOB ()
      {
        return symbol_type (token::QP_BLOB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAM ()
      {
        return symbol_type (token::RAM);
      }
#else
      static
      symbol_type
      make_RAM ()
      {
        return symbol_type (token::RAM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAM_INIT_BY_ECU ()
      {
        return symbol_type (token::RAM_INIT_BY_ECU);
      }
#else
      static
      symbol_type
      make_RAM_INIT_BY_ECU ()
      {
        return symbol_type (token::RAM_INIT_BY_ECU);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RAM_INIT_BY_TOOL ()
      {
        return symbol_type (token::RAM_INIT_BY_TOOL);
      }
#else
      static
      symbol_type
      make_RAM_INIT_BY_TOOL ()
      {
        return symbol_type (token::RAM_INIT_BY_TOOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RASTER ()
      {
        return symbol_type (token::RASTER);
      }
#else
      static
      symbol_type
      make_RASTER ()
      {
        return symbol_type (token::RASTER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REDUCTION_ALLOWED ()
      {
        return symbol_type (token::REDUCTION_ALLOWED);
      }
#else
      static
      symbol_type
      make_REDUCTION_ALLOWED ()
      {
        return symbol_type (token::REDUCTION_ALLOWED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESUME_SUPPORTED ()
      {
        return symbol_type (token::RESUME_SUPPORTED);
      }
#else
      static
      symbol_type
      make_RESUME_SUPPORTED ()
      {
        return symbol_type (token::RESUME_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROM ()
      {
        return symbol_type (token::ROM);
      }
#else
      static
      symbol_type
      make_ROM ()
      {
        return symbol_type (token::ROM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SAMPLE_POINT ()
      {
        return symbol_type (token::SAMPLE_POINT);
      }
#else
      static
      symbol_type
      make_SAMPLE_POINT ()
      {
        return symbol_type (token::SAMPLE_POINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SAMPLE_RATE ()
      {
        return symbol_type (token::SAMPLE_RATE);
      }
#else
      static
      symbol_type
      make_SAMPLE_RATE ()
      {
        return symbol_type (token::SAMPLE_RATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEED_KEY ()
      {
        return symbol_type (token::SEED_KEY);
      }
#else
      static
      symbol_type
      make_SEED_KEY ()
      {
        return symbol_type (token::SEED_KEY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SINGLE ()
      {
        return symbol_type (token::SINGLE);
      }
#else
      static
      symbol_type
      make_SINGLE ()
      {
        return symbol_type (token::SINGLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SJW ()
      {
        return symbol_type (token::SJW);
      }
#else
      static
      symbol_type
      make_SJW ()
      {
        return symbol_type (token::SJW);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOURCE ()
      {
        return symbol_type (token::SOURCE);
      }
#else
      static
      symbol_type
      make_SOURCE ()
      {
        return symbol_type (token::SOURCE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STORE_SUPPORTED ()
      {
        return symbol_type (token::STORE_SUPPORTED);
      }
#else
      static
      symbol_type
      make_STORE_SUPPORTED ()
      {
        return symbol_type (token::STORE_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNC_EDGE ()
      {
        return symbol_type (token::SYNC_EDGE);
      }
#else
      static
      symbol_type
      make_SYNC_EDGE ()
      {
        return symbol_type (token::SYNC_EDGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TP_BLOB ()
      {
        return symbol_type (token::TP_BLOB);
      }
#else
      static
      symbol_type
      make_TP_BLOB ()
      {
        return symbol_type (token::TP_BLOB);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    CcpDataParser (const CcpDataParser&);
    /// Non copyable.
    CcpDataParser& operator= (const CcpDataParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if CCPDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if CCPDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if CCPDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 155,     ///< Last index in yytable_.
      yynnts_ = 33,  ///< Number of nonterminal symbols.
      yyfinal_ = 4 ///< Termination state number.
    };


    // User arguments.
    a2l::ccp::CcpDataScanner &scanner;

  };


#line 6 "D:/projects/a2llib/src/ccp/ccpdataparser.y"
} } // a2l::ccp
#line 2520 "D:/projects/a2llib/src/ccp/ccpdataparser.hpp"




#endif // !YY_CCP_D_PROJECTS_A2LLIB_SRC_CCP_CCPDATAPARSER_HPP_INCLUDED
