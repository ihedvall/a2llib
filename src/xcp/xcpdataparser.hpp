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
 ** \file D:/projects/a2llib/src/xcp/xcpdataparser.hpp
 ** Define the a2l::xcp::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_XCP_D_PROJECTS_A2LLIB_SRC_XCP_XCPDATAPARSER_HPP_INCLUDED
# define YY_XCP_D_PROJECTS_A2LLIB_SRC_XCP_XCPDATAPARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 10 "D:/projects/a2llib/src/xcp/xcpdataparser.y"

#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <utility>

namespace a2l::xcp {
class XcpDataScanner;
}


#line 62 "D:/projects/a2llib/src/xcp/xcpdataparser.hpp"


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
#ifndef XCPDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define XCPDEBUG 1
#  else
#   define XCPDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define XCPDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined XCPDEBUG */

#line 6 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
namespace a2l { namespace xcp {
#line 206 "D:/projects/a2llib/src/xcp/xcpdataparser.hpp"




  /// A Bison parser.
  class XcpDataParser
  {
  public:
#ifdef XCPSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define XCPSTYPE in C++, use %define api.value.type"
# endif
    typedef XCPSTYPE value_type;
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
      // FLOAT
      char dummy1[sizeof (double)];

      // INT
      char dummy2[sizeof (int64_t)];

      // IDENT
      // STRING
      // daq_list_type
      // transport_layer_instance
      // ident_or_string
      char dummy3[sizeof (std::string)];

      // UINT
      // HEX
      char dummy4[sizeof (uint64_t)];
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
        XCPEMPTY = -2,
    XCPEOF = 0,                    // "end of file"
    XCPerror = 256,                // error
    XCPUNDEF = 257,                // "invalid token"
    ADDRESS = 258,                 // ADDRESS
    ADDRESS_MAPPING = 259,         // ADDRESS_MAPPING
    ALT_SAMPLE_COUNT = 260,        // ALT_SAMPLE_COUNT
    ALTERNATE_SETTING_NO = 261,    // ALTERNATE_SETTING_NO
    ASYNCH_FULL_DUPLEX_MODE = 262, // ASYNCH_FULL_DUPLEX_MODE
    AVAILABLE_EVENT_LIST = 263,    // AVAILABLE_EVENT_LIST
    BAUDRATE = 264,                // BAUDRATE
    BIT_STIM_SUPPORTED = 265,      // BIT_STIM_SUPPORTED
    BLOCK = 266,                   // BLOCK
    BLOCK_BEGIN = 267,             // BLOCK_BEGIN
    BLOCK_END = 268,               // BLOCK_END
    BTL_CYCLES = 269,              // BTL_CYCLES
    BUFFER_RESERVE = 270,          // BUFFER_RESERVE
    BUFFER_RESERVE_EVENT = 271,    // BUFFER_RESERVE_EVENT
    CAN_FD = 272,                  // CAN_FD
    CAN_FD_DATA_TRANSFER_BAUDRATE = 273, // CAN_FD_DATA_TRANSFER_BAUDRATE
    CAN_ID_BROADCAST = 274,        // CAN_ID_BROADCAST
    CAN_ID_MASTER = 275,           // CAN_ID_MASTER
    CAN_ID_MASTER_INCREMENTAL = 276, // CAN_ID_MASTER_INCREMENTAL
    CAN_ID_SLAVE = 277,            // CAN_ID_SLAVE
    CAN_ID_GET_DAQ_CLOCK_MULTICAST = 278, // CAN_ID_GET_DAQ_CLOCK_MULTICAST
    CHANNEL = 279,                 // CHANNEL
    CHECKSUM = 280,                // CHECKSUM
    CLOCK = 281,                   // CLOCK
    CMD = 282,                     // CMD
    COMMUNICATION_MODE_SUPPORTED = 283, // COMMUNICATION_MODE_SUPPORTED
    CONSISTENCY_EVENT_LIST = 284,  // CONSISTENCY_EVENT_LIST
    CONSISTENCY = 285,             // CONSISTENCY
    CORE_LOAD_MAX = 286,           // CORE_LOAD_MAX
    CORE_LOAD_MAX_TOTAL = 287,     // CORE_LOAD_MAX_TOTAL
    CORE_LOAD_EP = 288,            // CORE_LOAD_EP
    COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER = 289, // COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER
    CPU_LOAD_MAX = 290,            // CPU_LOAD_MAX
    CPU_LOAD_MAX_TOTAL = 291,      // CPU_LOAD_MAX_TOTAL
    CPU_LOAD_CONSUMPTION_DAQ = 292, // CPU_LOAD_CONSUMPTION_DAQ
    CPU_LOAD_CONSUMPTION_STIM = 293, // CPU_LOAD_CONSUMPTION_STIM
    CPU_LOAD_CONSUMPTION_QUEUE = 294, // CPU_LOAD_CONSUMPTION_QUEUE
    CPU_LOAD_CONSUMPTION_QUEUE_STIM = 295, // CPU_LOAD_CONSUMPTION_QUEUE_STIM
    CYCLE_REPETITION = 296,        // CYCLE_REPETITION
    DAQ = 297,                     // DAQ
    DAQ_ALTERNATING_SUPPORTED = 298, // DAQ_ALTERNATING_SUPPORTED
    DAQ_EVENT = 299,               // DAQ_EVENT
    DAQ_LIST = 300,                // DAQ_LIST
    DAQ_LIST_CAN_ID = 301,         // DAQ_LIST_CAN_ID
    DAQ_LIST_USB_ENDPOINT = 302,   // DAQ_LIST_USB_ENDPOINT
    DAQ_LIST_TYPE = 303,           // DAQ_LIST_TYPE
    DAQ_MEMORY_CONSUMPTION = 304,  // DAQ_MEMORY_CONSUMPTION
    DAQ_PACKED_MODE = 305,         // DAQ_PACKED_MODE
    DAQ_PACKED_MODE_SUPPORTED = 306, // DAQ_PACKED_MODE_SUPPORTED
    DAQ_STIM = 307,                // DAQ_STIM
    DEFAULT_EVENT_LIST = 308,      // DEFAULT_EVENT_LIST
    DEFAULT_PAGE_NUMBER = 309,     // DEFAULT_PAGE_NUMBER
    DTO_CTR_DAQ_MODE = 310,        // DTO_CTR_DAQ_MODE
    DTO_CTR_DAQ_MODE_FIXED = 311,  // DTO_CTR_DAQ_MODE_FIXED
    DTO_CTR_FIELD_SUPPORTED = 312, // DTO_CTR_FIELD_SUPPORTED
    DTO_CTR_STIM_MODE = 313,       // DTO_CTR_STIM_MODE
    DTO_CTR_STIM_MODE_FIXED = 314, // DTO_CTR_STIM_MODE_FIXED
    ECU_STATES = 315,              // ECU_STATES
    ECU_SWITCHED_TO_DEFAULT_PAGE = 316, // ECU_SWITCHED_TO_DEFAULT_PAGE
    EV_SERV = 317,                 // EV_SERV
    EVENT = 318,                   // EVENT
    EVENT_CAN_ID_LIST = 319,       // EVENT_CAN_ID_LIST
    EVENT_COUNTER_PRESENT = 320,   // EVENT_COUNTER_PRESENT
    EVENT_FIXED = 321,             // EVENT_FIXED
    EXTERNAL_FUNCTION = 322,       // EXTERNAL_FUNCTION
    FIRST_PID = 323,               // FIRST_PID
    FIXED = 324,                   // FIXED
    FIXED_EVENT_LIST = 325,        // FIXED_EVENT_LIST
    FIXED_IN = 326,                // FIXED_IN
    FIXED_OUT = 327,               // FIXED_OUT
    FLX_SLOT_ID = 328,             // FLX_SLOT_ID
    FRAMING = 329,                 // FRAMING
    FREEZE_SUPPORTED = 330,        // FREEZE_SUPPORTED
    HOST_NAME = 331,               // HOST_NAME
    IF_DATA = 332,                 // IF_DATA
    IN_EP_ONLY_DAQ = 333,          // IN_EP_ONLY_DAQ
    IN_EP_ONLY_EVSERV = 334,       // IN_EP_ONLY_EVSERV
    IN_EP_RESERR_DAQ_EVSERV = 335, // IN_EP_RESERR_DAQ_EVSERV
    INIT_SEGMENT = 336,            // INIT_SEGMENT
    INITIAL_VALUE = 337,           // INITIAL_VALUE
    INITIAL_CMD_BUFFER = 338,      // INITIAL_CMD_BUFFER
    INITIAL_RES_ERR_BUFFER = 339,  // INITIAL_RES_ERR_BUFFER
    INTERFACE_STRING_DESCRIPTOR = 340, // INTERFACE_STRING_DESCRIPTOR
    INTERLEAVED = 341,             // INTERLEAVED
    IPV6 = 342,                    // IPV6
    LPU_ID = 343,                  // LPU_ID
    MASTER = 344,                  // MASTER
    MAX_BLOCK_SIZE = 345,          // MAX_BLOCK_SIZE
    MAX_DAQ_TOTAL = 346,           // MAX_DAQ_TOTAL
    MAX_DLC_REQUIRED = 347,        // MAX_DLC_REQUIRED
    MAX_BUS_LOAD = 348,            // MAX_BUS_LOAD
    MAX_DLC = 349,                 // MAX_DLC
    MAX_DTO_STIM = 350,            // MAX_DTO_STIM
    MAX_BIT_RATE = 351,            // MAX_BIT_RATE
    MAX_FLX_LEN_BUF = 352,         // MAX_FLX_LEN_BUF
    MAX_ODT = 353,                 // MAX_ODT
    MAX_ODT_DAQ_TOTAL = 354,       // MAX_ODT_DAQ_TOTAL
    MAX_ODT_ENTRIES = 355,         // MAX_ODT_ENTRIES
    MAX_ODT_ENTRIES_DAQ_TOTAL = 356, // MAX_ODT_ENTRIES_DAQ_TOTAL
    MAX_ODT_ENTRIES_STIM_TOTAL = 357, // MAX_ODT_ENTRIES_STIM_TOTAL
    MAX_ODT_ENTRIES_TOTAL = 358,   // MAX_ODT_ENTRIES_TOTAL
    MAX_ODT_STIM_TOTAL = 359,      // MAX_ODT_STIM_TOTAL
    MAX_ODT_TOTAL = 360,           // MAX_ODT_TOTAL
    MEASUREMENT_SPLIT_ALLOWED = 361, // MEASUREMENT_SPLIT_ALLOWED
    MEMORY_ACCESS = 362,           // MEMORY_ACCESS
    MIN_CYCLE_TIME = 363,          // MIN_CYCLE_TIME
    MIN_ST_STIM = 364,             // MIN_ST_STIM
    MODEL_NAME = 365,              // MODEL_NAME
    MTA_BLOCK_SIZE_ALIGN = 366,    // MTA_BLOCK_SIZE_ALIGN
    MULTICAST = 367,               // MULTICAST
    ODT = 368,                     // ODT
    ODT_ENTRY = 369,               // ODT_ENTRY
    ODT_ENTRY_SIZE_FACTOR_TABLE = 370, // ODT_ENTRY_SIZE_FACTOR_TABLE
    OPTIMISATION_TYPE_ODT_STRICT = 371, // OPTIMISATION_TYPE_ODT_STRICT
    OFFSET = 372,                  // OFFSET
    OPTIONAL_CMD = 373,            // OPTIONAL_CMD
    OPTIONAL_LEVEL1_CMD = 374,     // OPTIONAL_LEVEL1_CMD
    OPTIONAL_TL_SUBCMD = 375,      // OPTIONAL_TL_SUBCMD
    OUT_EP_ONLY_STIM = 376,        // OUT_EP_ONLY_STIM
    OUT_EP_CMD_STIM = 377,         // OUT_EP_CMD_STIM
    PACKET_ALIGNMENT = 378,        // PACKET_ALIGNMENT
    PAG = 379,                     // PAG
    PAGE = 380,                    // PAGE
    PGM = 381,                     // PGM
    PID_OFF_SUPPORTED = 382,       // PID_OFF_SUPPORTED
    POOL_BUFFER = 383,             // POOL_BUFFER
    PREDEFINED = 384,              // PREDEFINED
    PRESCALER_SUPPORTED = 385,     // PRESCALER_SUPPORTED
    PROTOCOL_LAYER = 386,          // PROTOCOL_LAYER
    RECOMMENDED_HOST_BUFSIZE = 387, // RECOMMENDED_HOST_BUFSIZE
    RELATED_EVENT_CHANNEL_NUMBER = 388, // RELATED_EVENT_CHANNEL_NUMBER
    RELATED_EVENT_CHANNEL_NUMBER_FIXED = 389, // RELATED_EVENT_CHANNEL_NUMBER_FIXED
    RES_ERR = 390,                 // RES_ERR
    RESUME_SUPPORTED = 391,        // RESUME_SUPPORTED
    SAMPLE_POINT = 392,            // SAMPLE_POINT
    SAMPLE_RATE = 393,             // SAMPLE_RATE
    SECTOR = 394,                  // SECTOR
    SEGMENT = 395,                 // SEGMENT
    SECONDARY_SAMPLE_POINT = 396,  // SECONDARY_SAMPLE_POINT
    SEED_AND_KEY_EXTERNAL_FUNCTION = 397, // SEED_AND_KEY_EXTERNAL_FUNCTION
    SJW = 398,                     // SJW
    SLAVE = 399,                   // SLAVE
    STATE = 400,                   // STATE
    STIM = 401,                    // STIM
    STIM_DTO_CTR_COPY_PRESENT = 402, // STIM_DTO_CTR_COPY_PRESENT
    STORE_DAQ_SUPPORTED = 403,     // STORE_DAQ_SUPPORTED
    SYNC_EDGE = 404,               // SYNC_EDGE
    SYNCH_FULL_DUPLEX_MODE_BYTE = 405, // SYNCH_FULL_DUPLEX_MODE_BYTE
    SYNCH_FULL_DUPLEX_MODE_WORD = 406, // SYNCH_FULL_DUPLEX_MODE_WORD
    SYNCH_FULL_DUPLEX_MODE_DWORD = 407, // SYNCH_FULL_DUPLEX_MODE_DWORD
    SYNCH_FULL_MASTER_MODE_BYTE = 408, // SYNCH_FULL_MASTER_MODE_BYTE
    SYNCH_FULL_MASTER_MODE_WORD = 409, // SYNCH_FULL_MASTER_MODE_WORD
    SYNCH_FULL_MASTER_MODE_DWORD = 410, // SYNCH_FULL_MASTER_MODE_DWORD
    TIME_CHARACTERIZATION = 411,   // TIME_CHARACTERIZATION
    TIME_CORRELATION = 412,        // TIME_CORRELATION
    TIMESTAMP_FIXED = 413,         // TIMESTAMP_FIXED
    TIMESTAMP_SUPPORTED = 414,     // TIMESTAMP_SUPPORTED
    TRANSPORT_LAYER_INSTANCE = 415, // TRANSPORT_LAYER_INSTANCE
    TRANSCEIVER_DELAY_COMPENSATION = 416, // TRANSCEIVER_DELAY_COMPENSATION
    VARIABLE = 417,                // VARIABLE
    XCP = 418,                     // XCP
    XCPplus = 419,                 // XCPplus
    XCP_ON_CAN = 420,              // XCP_ON_CAN
    XCP_ON_SxI = 421,              // XCP_ON_SxI
    XCP_ON_TCP_IP = 422,           // XCP_ON_TCP_IP
    XCP_ON_UDP_IP = 423,           // XCP_ON_UDP_IP
    XCP_ON_USB = 424,              // XCP_ON_USB
    XCP_ON_FLX = 425,              // XCP_ON_FLX
    XCP_ON_SIMULINK = 426,         // XCP_ON_SIMULINK
    XCP_PACKET = 427,              // XCP_PACKET
    UINT = 428,                    // UINT
    HEX = 429,                     // HEX
    INT = 430,                     // INT
    FLOAT = 431,                   // FLOAT
    IDENT = 432,                   // IDENT
    STRING = 433                   // STRING
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
        YYNTOKENS = 179, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_ADDRESS = 3,                           // ADDRESS
        S_ADDRESS_MAPPING = 4,                   // ADDRESS_MAPPING
        S_ALT_SAMPLE_COUNT = 5,                  // ALT_SAMPLE_COUNT
        S_ALTERNATE_SETTING_NO = 6,              // ALTERNATE_SETTING_NO
        S_ASYNCH_FULL_DUPLEX_MODE = 7,           // ASYNCH_FULL_DUPLEX_MODE
        S_AVAILABLE_EVENT_LIST = 8,              // AVAILABLE_EVENT_LIST
        S_BAUDRATE = 9,                          // BAUDRATE
        S_BIT_STIM_SUPPORTED = 10,               // BIT_STIM_SUPPORTED
        S_BLOCK = 11,                            // BLOCK
        S_BLOCK_BEGIN = 12,                      // BLOCK_BEGIN
        S_BLOCK_END = 13,                        // BLOCK_END
        S_BTL_CYCLES = 14,                       // BTL_CYCLES
        S_BUFFER_RESERVE = 15,                   // BUFFER_RESERVE
        S_BUFFER_RESERVE_EVENT = 16,             // BUFFER_RESERVE_EVENT
        S_CAN_FD = 17,                           // CAN_FD
        S_CAN_FD_DATA_TRANSFER_BAUDRATE = 18,    // CAN_FD_DATA_TRANSFER_BAUDRATE
        S_CAN_ID_BROADCAST = 19,                 // CAN_ID_BROADCAST
        S_CAN_ID_MASTER = 20,                    // CAN_ID_MASTER
        S_CAN_ID_MASTER_INCREMENTAL = 21,        // CAN_ID_MASTER_INCREMENTAL
        S_CAN_ID_SLAVE = 22,                     // CAN_ID_SLAVE
        S_CAN_ID_GET_DAQ_CLOCK_MULTICAST = 23,   // CAN_ID_GET_DAQ_CLOCK_MULTICAST
        S_CHANNEL = 24,                          // CHANNEL
        S_CHECKSUM = 25,                         // CHECKSUM
        S_CLOCK = 26,                            // CLOCK
        S_CMD = 27,                              // CMD
        S_COMMUNICATION_MODE_SUPPORTED = 28,     // COMMUNICATION_MODE_SUPPORTED
        S_CONSISTENCY_EVENT_LIST = 29,           // CONSISTENCY_EVENT_LIST
        S_CONSISTENCY = 30,                      // CONSISTENCY
        S_CORE_LOAD_MAX = 31,                    // CORE_LOAD_MAX
        S_CORE_LOAD_MAX_TOTAL = 32,              // CORE_LOAD_MAX_TOTAL
        S_CORE_LOAD_EP = 33,                     // CORE_LOAD_EP
        S_COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER = 34, // COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER
        S_CPU_LOAD_MAX = 35,                     // CPU_LOAD_MAX
        S_CPU_LOAD_MAX_TOTAL = 36,               // CPU_LOAD_MAX_TOTAL
        S_CPU_LOAD_CONSUMPTION_DAQ = 37,         // CPU_LOAD_CONSUMPTION_DAQ
        S_CPU_LOAD_CONSUMPTION_STIM = 38,        // CPU_LOAD_CONSUMPTION_STIM
        S_CPU_LOAD_CONSUMPTION_QUEUE = 39,       // CPU_LOAD_CONSUMPTION_QUEUE
        S_CPU_LOAD_CONSUMPTION_QUEUE_STIM = 40,  // CPU_LOAD_CONSUMPTION_QUEUE_STIM
        S_CYCLE_REPETITION = 41,                 // CYCLE_REPETITION
        S_DAQ = 42,                              // DAQ
        S_DAQ_ALTERNATING_SUPPORTED = 43,        // DAQ_ALTERNATING_SUPPORTED
        S_DAQ_EVENT = 44,                        // DAQ_EVENT
        S_DAQ_LIST = 45,                         // DAQ_LIST
        S_DAQ_LIST_CAN_ID = 46,                  // DAQ_LIST_CAN_ID
        S_DAQ_LIST_USB_ENDPOINT = 47,            // DAQ_LIST_USB_ENDPOINT
        S_DAQ_LIST_TYPE = 48,                    // DAQ_LIST_TYPE
        S_DAQ_MEMORY_CONSUMPTION = 49,           // DAQ_MEMORY_CONSUMPTION
        S_DAQ_PACKED_MODE = 50,                  // DAQ_PACKED_MODE
        S_DAQ_PACKED_MODE_SUPPORTED = 51,        // DAQ_PACKED_MODE_SUPPORTED
        S_DAQ_STIM = 52,                         // DAQ_STIM
        S_DEFAULT_EVENT_LIST = 53,               // DEFAULT_EVENT_LIST
        S_DEFAULT_PAGE_NUMBER = 54,              // DEFAULT_PAGE_NUMBER
        S_DTO_CTR_DAQ_MODE = 55,                 // DTO_CTR_DAQ_MODE
        S_DTO_CTR_DAQ_MODE_FIXED = 56,           // DTO_CTR_DAQ_MODE_FIXED
        S_DTO_CTR_FIELD_SUPPORTED = 57,          // DTO_CTR_FIELD_SUPPORTED
        S_DTO_CTR_STIM_MODE = 58,                // DTO_CTR_STIM_MODE
        S_DTO_CTR_STIM_MODE_FIXED = 59,          // DTO_CTR_STIM_MODE_FIXED
        S_ECU_STATES = 60,                       // ECU_STATES
        S_ECU_SWITCHED_TO_DEFAULT_PAGE = 61,     // ECU_SWITCHED_TO_DEFAULT_PAGE
        S_EV_SERV = 62,                          // EV_SERV
        S_EVENT = 63,                            // EVENT
        S_EVENT_CAN_ID_LIST = 64,                // EVENT_CAN_ID_LIST
        S_EVENT_COUNTER_PRESENT = 65,            // EVENT_COUNTER_PRESENT
        S_EVENT_FIXED = 66,                      // EVENT_FIXED
        S_EXTERNAL_FUNCTION = 67,                // EXTERNAL_FUNCTION
        S_FIRST_PID = 68,                        // FIRST_PID
        S_FIXED = 69,                            // FIXED
        S_FIXED_EVENT_LIST = 70,                 // FIXED_EVENT_LIST
        S_FIXED_IN = 71,                         // FIXED_IN
        S_FIXED_OUT = 72,                        // FIXED_OUT
        S_FLX_SLOT_ID = 73,                      // FLX_SLOT_ID
        S_FRAMING = 74,                          // FRAMING
        S_FREEZE_SUPPORTED = 75,                 // FREEZE_SUPPORTED
        S_HOST_NAME = 76,                        // HOST_NAME
        S_IF_DATA = 77,                          // IF_DATA
        S_IN_EP_ONLY_DAQ = 78,                   // IN_EP_ONLY_DAQ
        S_IN_EP_ONLY_EVSERV = 79,                // IN_EP_ONLY_EVSERV
        S_IN_EP_RESERR_DAQ_EVSERV = 80,          // IN_EP_RESERR_DAQ_EVSERV
        S_INIT_SEGMENT = 81,                     // INIT_SEGMENT
        S_INITIAL_VALUE = 82,                    // INITIAL_VALUE
        S_INITIAL_CMD_BUFFER = 83,               // INITIAL_CMD_BUFFER
        S_INITIAL_RES_ERR_BUFFER = 84,           // INITIAL_RES_ERR_BUFFER
        S_INTERFACE_STRING_DESCRIPTOR = 85,      // INTERFACE_STRING_DESCRIPTOR
        S_INTERLEAVED = 86,                      // INTERLEAVED
        S_IPV6 = 87,                             // IPV6
        S_LPU_ID = 88,                           // LPU_ID
        S_MASTER = 89,                           // MASTER
        S_MAX_BLOCK_SIZE = 90,                   // MAX_BLOCK_SIZE
        S_MAX_DAQ_TOTAL = 91,                    // MAX_DAQ_TOTAL
        S_MAX_DLC_REQUIRED = 92,                 // MAX_DLC_REQUIRED
        S_MAX_BUS_LOAD = 93,                     // MAX_BUS_LOAD
        S_MAX_DLC = 94,                          // MAX_DLC
        S_MAX_DTO_STIM = 95,                     // MAX_DTO_STIM
        S_MAX_BIT_RATE = 96,                     // MAX_BIT_RATE
        S_MAX_FLX_LEN_BUF = 97,                  // MAX_FLX_LEN_BUF
        S_MAX_ODT = 98,                          // MAX_ODT
        S_MAX_ODT_DAQ_TOTAL = 99,                // MAX_ODT_DAQ_TOTAL
        S_MAX_ODT_ENTRIES = 100,                 // MAX_ODT_ENTRIES
        S_MAX_ODT_ENTRIES_DAQ_TOTAL = 101,       // MAX_ODT_ENTRIES_DAQ_TOTAL
        S_MAX_ODT_ENTRIES_STIM_TOTAL = 102,      // MAX_ODT_ENTRIES_STIM_TOTAL
        S_MAX_ODT_ENTRIES_TOTAL = 103,           // MAX_ODT_ENTRIES_TOTAL
        S_MAX_ODT_STIM_TOTAL = 104,              // MAX_ODT_STIM_TOTAL
        S_MAX_ODT_TOTAL = 105,                   // MAX_ODT_TOTAL
        S_MEASUREMENT_SPLIT_ALLOWED = 106,       // MEASUREMENT_SPLIT_ALLOWED
        S_MEMORY_ACCESS = 107,                   // MEMORY_ACCESS
        S_MIN_CYCLE_TIME = 108,                  // MIN_CYCLE_TIME
        S_MIN_ST_STIM = 109,                     // MIN_ST_STIM
        S_MODEL_NAME = 110,                      // MODEL_NAME
        S_MTA_BLOCK_SIZE_ALIGN = 111,            // MTA_BLOCK_SIZE_ALIGN
        S_MULTICAST = 112,                       // MULTICAST
        S_ODT = 113,                             // ODT
        S_ODT_ENTRY = 114,                       // ODT_ENTRY
        S_ODT_ENTRY_SIZE_FACTOR_TABLE = 115,     // ODT_ENTRY_SIZE_FACTOR_TABLE
        S_OPTIMISATION_TYPE_ODT_STRICT = 116,    // OPTIMISATION_TYPE_ODT_STRICT
        S_OFFSET = 117,                          // OFFSET
        S_OPTIONAL_CMD = 118,                    // OPTIONAL_CMD
        S_OPTIONAL_LEVEL1_CMD = 119,             // OPTIONAL_LEVEL1_CMD
        S_OPTIONAL_TL_SUBCMD = 120,              // OPTIONAL_TL_SUBCMD
        S_OUT_EP_ONLY_STIM = 121,                // OUT_EP_ONLY_STIM
        S_OUT_EP_CMD_STIM = 122,                 // OUT_EP_CMD_STIM
        S_PACKET_ALIGNMENT = 123,                // PACKET_ALIGNMENT
        S_PAG = 124,                             // PAG
        S_PAGE = 125,                            // PAGE
        S_PGM = 126,                             // PGM
        S_PID_OFF_SUPPORTED = 127,               // PID_OFF_SUPPORTED
        S_POOL_BUFFER = 128,                     // POOL_BUFFER
        S_PREDEFINED = 129,                      // PREDEFINED
        S_PRESCALER_SUPPORTED = 130,             // PRESCALER_SUPPORTED
        S_PROTOCOL_LAYER = 131,                  // PROTOCOL_LAYER
        S_RECOMMENDED_HOST_BUFSIZE = 132,        // RECOMMENDED_HOST_BUFSIZE
        S_RELATED_EVENT_CHANNEL_NUMBER = 133,    // RELATED_EVENT_CHANNEL_NUMBER
        S_RELATED_EVENT_CHANNEL_NUMBER_FIXED = 134, // RELATED_EVENT_CHANNEL_NUMBER_FIXED
        S_RES_ERR = 135,                         // RES_ERR
        S_RESUME_SUPPORTED = 136,                // RESUME_SUPPORTED
        S_SAMPLE_POINT = 137,                    // SAMPLE_POINT
        S_SAMPLE_RATE = 138,                     // SAMPLE_RATE
        S_SECTOR = 139,                          // SECTOR
        S_SEGMENT = 140,                         // SEGMENT
        S_SECONDARY_SAMPLE_POINT = 141,          // SECONDARY_SAMPLE_POINT
        S_SEED_AND_KEY_EXTERNAL_FUNCTION = 142,  // SEED_AND_KEY_EXTERNAL_FUNCTION
        S_SJW = 143,                             // SJW
        S_SLAVE = 144,                           // SLAVE
        S_STATE = 145,                           // STATE
        S_STIM = 146,                            // STIM
        S_STIM_DTO_CTR_COPY_PRESENT = 147,       // STIM_DTO_CTR_COPY_PRESENT
        S_STORE_DAQ_SUPPORTED = 148,             // STORE_DAQ_SUPPORTED
        S_SYNC_EDGE = 149,                       // SYNC_EDGE
        S_SYNCH_FULL_DUPLEX_MODE_BYTE = 150,     // SYNCH_FULL_DUPLEX_MODE_BYTE
        S_SYNCH_FULL_DUPLEX_MODE_WORD = 151,     // SYNCH_FULL_DUPLEX_MODE_WORD
        S_SYNCH_FULL_DUPLEX_MODE_DWORD = 152,    // SYNCH_FULL_DUPLEX_MODE_DWORD
        S_SYNCH_FULL_MASTER_MODE_BYTE = 153,     // SYNCH_FULL_MASTER_MODE_BYTE
        S_SYNCH_FULL_MASTER_MODE_WORD = 154,     // SYNCH_FULL_MASTER_MODE_WORD
        S_SYNCH_FULL_MASTER_MODE_DWORD = 155,    // SYNCH_FULL_MASTER_MODE_DWORD
        S_TIME_CHARACTERIZATION = 156,           // TIME_CHARACTERIZATION
        S_TIME_CORRELATION = 157,                // TIME_CORRELATION
        S_TIMESTAMP_FIXED = 158,                 // TIMESTAMP_FIXED
        S_TIMESTAMP_SUPPORTED = 159,             // TIMESTAMP_SUPPORTED
        S_TRANSPORT_LAYER_INSTANCE = 160,        // TRANSPORT_LAYER_INSTANCE
        S_TRANSCEIVER_DELAY_COMPENSATION = 161,  // TRANSCEIVER_DELAY_COMPENSATION
        S_VARIABLE = 162,                        // VARIABLE
        S_XCP = 163,                             // XCP
        S_XCPplus = 164,                         // XCPplus
        S_XCP_ON_CAN = 165,                      // XCP_ON_CAN
        S_XCP_ON_SxI = 166,                      // XCP_ON_SxI
        S_XCP_ON_TCP_IP = 167,                   // XCP_ON_TCP_IP
        S_XCP_ON_UDP_IP = 168,                   // XCP_ON_UDP_IP
        S_XCP_ON_USB = 169,                      // XCP_ON_USB
        S_XCP_ON_FLX = 170,                      // XCP_ON_FLX
        S_XCP_ON_SIMULINK = 171,                 // XCP_ON_SIMULINK
        S_XCP_PACKET = 172,                      // XCP_PACKET
        S_UINT = 173,                            // UINT
        S_HEX = 174,                             // HEX
        S_INT = 175,                             // INT
        S_FLOAT = 176,                           // FLOAT
        S_IDENT = 177,                           // IDENT
        S_STRING = 178,                          // STRING
        S_YYACCEPT = 179,                        // $accept
        S_xcp_data_block = 180,                  // xcp_data_block
        S_if_data = 181,                         // if_data
        S_definitions = 182,                     // definitions
        S_definition = 183,                      // definition
        S_common_definition = 184,               // common_definition
        S_transport_protocol = 185,              // transport_protocol
        S_protocol_layer = 186,                  // protocol_layer
        S_protocol_fixed_items = 187,            // protocol_fixed_items
        S_protocol_optional_items = 188,         // protocol_optional_items
        S_protocol_optional_item = 189,          // protocol_optional_item
        S_optional_command = 190,                // optional_command
        S_optional_level1_command = 191,         // optional_level1_command
        S_communication_mode_supported = 192,    // communication_mode_supported
        S_communication_mode_union = 193,        // communication_mode_union
        S_block_struct = 194,                    // block_struct
        S_slave_item = 195,                      // slave_item
        S_master_item = 196,                     // master_item
        S_seed_and_key_function = 197,           // seed_and_key_function
        S_max_dto_stim = 198,                    // max_dto_stim
        S_ecu_states = 199,                      // ecu_states
        S_state_list = 200,                      // state_list
        S_state_block = 201,                     // state_block
        S_ecu_switch_to_default = 202,           // ecu_switch_to_default
        S_memory_access_list = 203,              // memory_access_list
        S_memory_access = 204,                   // memory_access
        S_daq = 205,                             // daq
        S_daq_optionals = 206,                   // daq_optionals
        S_daq_optional = 207,                    // daq_optional
        S_stim_struct = 208,                     // stim_struct
        S_bit_stim = 209,                        // bit_stim
        S_min_st_stim = 210,                     // min_st_stim
        S_timestamp_supported = 211,             // timestamp_supported
        S_timestamp_fixed = 212,                 // timestamp_fixed
        S_core_load_max = 213,                   // core_load_max
        S_daq_memory_consumption = 214,          // daq_memory_consumption
        S_daq_memory_consumption_optional = 215, // daq_memory_consumption_optional
        S_daq_list = 216,                        // daq_list
        S_daq_list_optionals = 217,              // daq_list_optionals
        S_daq_list_optional = 218,               // daq_list_optional
        S_odt_list = 219,                        // odt_list
        S_odt = 220,                             // odt
        S_odt_entry_list = 221,                  // odt_entry_list
        S_odt_entry = 222,                       // odt_entry
        S_d_event = 223,                         // d_event
        S_d_event_optionals = 224,               // d_event_optionals
        S_d_event_optional = 225,                // d_event_optional
        S_daq_packed_mode = 226,                 // daq_packed_mode
        S_alt_sample_count_list = 227,           // alt_sample_count_list
        S_alt_sample_count = 228,                // alt_sample_count
        S_cpu_load_consumption_daq = 229,        // cpu_load_consumption_daq
        S_cpu_load_consumption_daq_options = 230, // cpu_load_consumption_daq_options
        S_cpu_load_consumption_daq_option = 231, // cpu_load_consumption_daq_option
        S_cpu_load_consumption_stim = 232,       // cpu_load_consumption_stim
        S_cpu_load_consumption_stim_options = 233, // cpu_load_consumption_stim_options
        S_cpu_load_consumption_stim_option = 234, // cpu_load_consumption_stim_option
        S_odt_entry_size_factor_table = 235,     // odt_entry_size_factor_table
        S_cpu_load_consumption_queue = 236,      // cpu_load_consumption_queue
        S_cpu_load_consumption_queue_options = 237, // cpu_load_consumption_queue_options
        S_cpu_load_consumption_queue_option = 238, // cpu_load_consumption_queue_option
        S_cpu_load_consumption_queue_stim = 239, // cpu_load_consumption_queue_stim
        S_cpu_load_consumption_queue_stim_options = 240, // cpu_load_consumption_queue_stim_options
        S_cpu_load_consumption_queue_stim_option = 241, // cpu_load_consumption_queue_stim_option
        S_core_load_ep = 242,                    // core_load_ep
        S_daq_event = 243,                       // daq_event
        S_daq_event_union = 244,                 // daq_event_union
        S_fixed_event_list = 245,                // fixed_event_list
        S_variable = 246,                        // variable
        S_variable_options = 247,                // variable_options
        S_variable_option = 248,                 // variable_option
        S_pag = 249,                             // pag
        S_freeze_supported = 250,                // freeze_supported
        S_pgm = 251,                             // pgm
        S_pgm_options = 252,                     // pgm_options
        S_pgm_option = 253,                      // pgm_option
        S_sector = 254,                          // sector
        S_segment = 255,                         // segment
        S_segment_options = 256,                 // segment_options
        S_segment_option = 257,                  // segment_option
        S_checksum = 258,                        // checksum
        S_checksum_options = 259,                // checksum_options
        S_checksum_option = 260,                 // checksum_option
        S_page = 261,                            // page
        S_address_mapping = 262,                 // address_mapping
        S_init_segment = 263,                    // init_segment
        S_time_correlation = 264,                // time_correlation
        S_clock_list = 265,                      // clock_list
        S_clock = 266,                           // clock
        S_timestamp_characterization = 267,      // timestamp_characterization
        S_event_list = 268,                      // event_list
        S_event = 269,                           // event
        S_xcp_on_can = 270,                      // xcp_on_can
        S_can_parameters = 271,                  // can_parameters
        S_can_parameter_options = 272,           // can_parameter_options
        S_can_parameter_option = 273,            // can_parameter_option
        S_daq_list_can_id = 274,                 // daq_list_can_id
        S_daq_list_can_id_options = 275,         // daq_list_can_id_options
        S_daq_list_can_id_option = 276,          // daq_list_can_id_option
        S_event_can_id_list = 277,               // event_can_id_list
        S_fixed_list = 278,                      // fixed_list
        S_fixed = 279,                           // fixed
        S_can_fd = 280,                          // can_fd
        S_can_fd_options = 281,                  // can_fd_options
        S_can_fd_option = 282,                   // can_fd_option
        S_xcp_on_sxi = 283,                      // xcp_on_sxi
        S_sxi_parameter = 284,                   // sxi_parameter
        S_sxi_parameter_options = 285,           // sxi_parameter_options
        S_sxi_parameter_option = 286,            // sxi_parameter_option
        S_sxi_option = 287,                      // sxi_option
        S_framing = 288,                         // framing
        S_xcp_on_tcp_ip = 289,                   // xcp_on_tcp_ip
        S_tcp_ip_parameter = 290,                // tcp_ip_parameter
        S_tcp_ip_options = 291,                  // tcp_ip_options
        S_tcp_ip_option = 292,                   // tcp_ip_option
        S_xcp_on_udp_ip = 293,                   // xcp_on_udp_ip
        S_udp_ip_parameter = 294,                // udp_ip_parameter
        S_udp_ip_options = 295,                  // udp_ip_options
        S_udp_ip_option = 296,                   // udp_ip_option
        S_xcp_on_usb = 297,                      // xcp_on_usb
        S_usb_options = 298,                     // usb_options
        S_usb_option = 299,                      // usb_option
        S_daq_list_usb_endpoint = 300,           // daq_list_usb_endpoint
        S_fixed_in = 301,                        // fixed_in
        S_fixed_out = 302,                       // fixed_out
        S_ep_parameters = 303,                   // ep_parameters
        S_recommended_host_bufsize = 304,        // recommended_host_bufsize
        S_xcp_on_flx = 305,                      // xcp_on_flx
        S_flx_options = 306,                     // flx_options
        S_flx_option = 307,                      // flx_option
        S_buffer = 308,                          // buffer
        S_buffer_options = 309,                  // buffer_options
        S_buffer_option = 310,                   // buffer_option
        S_max_flx_len_buf_union = 311,           // max_flx_len_buf_union
        S_lpu_id = 312,                          // lpu_id
        S_lpu_id_options = 313,                  // lpu_id_options
        S_lpu_id_option = 314,                   // lpu_id_option
        S_flx_slot_id_union = 315,               // flx_slot_id_union
        S_offset_union = 316,                    // offset_union
        S_cycle_repetition = 317,                // cycle_repetition
        S_channel = 318,                         // channel
        S_channel_union = 319,                   // channel_union
        S_initial_enum = 320,                    // initial_enum
        S_lpu_id_union = 321,                    // lpu_id_union
        S_initial_value = 322,                   // initial_value
        S_xcp_packet = 323,                      // xcp_packet
        S_xcp_packet_options = 324,              // xcp_packet_options
        S_xcp_packet_option = 325,               // xcp_packet_option
        S_xcp_on_simulink = 326,                 // xcp_on_simulink
        S_simulink_options = 327,                // simulink_options
        S_simulink_option = 328,                 // simulink_option
        S_daq_list_type = 329,                   // daq_list_type
        S_transport_layer_instance = 330,        // transport_layer_instance
        S_ident_or_string = 331                  // ident_or_string
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
      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (std::move (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (std::move (that.value));
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
      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< double > ();
        break;

      case symbol_kind::S_INT: // INT
        value.template destroy< int64_t > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.template destroy< uint64_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if XCPDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return XcpDataParser::symbol_name (this->kind ());
      }
#endif // #if XCPDEBUG || 0


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
    XcpDataParser (a2l::xcp::XcpDataScanner &scanner_yyarg);
    virtual ~XcpDataParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    XcpDataParser (const XcpDataParser&) = delete;
    /// Non copyable.
    XcpDataParser& operator= (const XcpDataParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if XCPDEBUG
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

#if XCPDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if XCPDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCPEOF ()
      {
        return symbol_type (token::XCPEOF);
      }
#else
      static
      symbol_type
      make_XCPEOF ()
      {
        return symbol_type (token::XCPEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCPerror ()
      {
        return symbol_type (token::XCPerror);
      }
#else
      static
      symbol_type
      make_XCPerror ()
      {
        return symbol_type (token::XCPerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCPUNDEF ()
      {
        return symbol_type (token::XCPUNDEF);
      }
#else
      static
      symbol_type
      make_XCPUNDEF ()
      {
        return symbol_type (token::XCPUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDRESS ()
      {
        return symbol_type (token::ADDRESS);
      }
#else
      static
      symbol_type
      make_ADDRESS ()
      {
        return symbol_type (token::ADDRESS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDRESS_MAPPING ()
      {
        return symbol_type (token::ADDRESS_MAPPING);
      }
#else
      static
      symbol_type
      make_ADDRESS_MAPPING ()
      {
        return symbol_type (token::ADDRESS_MAPPING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALT_SAMPLE_COUNT ()
      {
        return symbol_type (token::ALT_SAMPLE_COUNT);
      }
#else
      static
      symbol_type
      make_ALT_SAMPLE_COUNT ()
      {
        return symbol_type (token::ALT_SAMPLE_COUNT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALTERNATE_SETTING_NO ()
      {
        return symbol_type (token::ALTERNATE_SETTING_NO);
      }
#else
      static
      symbol_type
      make_ALTERNATE_SETTING_NO ()
      {
        return symbol_type (token::ALTERNATE_SETTING_NO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASYNCH_FULL_DUPLEX_MODE ()
      {
        return symbol_type (token::ASYNCH_FULL_DUPLEX_MODE);
      }
#else
      static
      symbol_type
      make_ASYNCH_FULL_DUPLEX_MODE ()
      {
        return symbol_type (token::ASYNCH_FULL_DUPLEX_MODE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AVAILABLE_EVENT_LIST ()
      {
        return symbol_type (token::AVAILABLE_EVENT_LIST);
      }
#else
      static
      symbol_type
      make_AVAILABLE_EVENT_LIST ()
      {
        return symbol_type (token::AVAILABLE_EVENT_LIST);
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
      make_BIT_STIM_SUPPORTED ()
      {
        return symbol_type (token::BIT_STIM_SUPPORTED);
      }
#else
      static
      symbol_type
      make_BIT_STIM_SUPPORTED ()
      {
        return symbol_type (token::BIT_STIM_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BLOCK ()
      {
        return symbol_type (token::BLOCK);
      }
#else
      static
      symbol_type
      make_BLOCK ()
      {
        return symbol_type (token::BLOCK);
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
      make_BUFFER_RESERVE ()
      {
        return symbol_type (token::BUFFER_RESERVE);
      }
#else
      static
      symbol_type
      make_BUFFER_RESERVE ()
      {
        return symbol_type (token::BUFFER_RESERVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BUFFER_RESERVE_EVENT ()
      {
        return symbol_type (token::BUFFER_RESERVE_EVENT);
      }
#else
      static
      symbol_type
      make_BUFFER_RESERVE_EVENT ()
      {
        return symbol_type (token::BUFFER_RESERVE_EVENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_FD ()
      {
        return symbol_type (token::CAN_FD);
      }
#else
      static
      symbol_type
      make_CAN_FD ()
      {
        return symbol_type (token::CAN_FD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_FD_DATA_TRANSFER_BAUDRATE ()
      {
        return symbol_type (token::CAN_FD_DATA_TRANSFER_BAUDRATE);
      }
#else
      static
      symbol_type
      make_CAN_FD_DATA_TRANSFER_BAUDRATE ()
      {
        return symbol_type (token::CAN_FD_DATA_TRANSFER_BAUDRATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_BROADCAST ()
      {
        return symbol_type (token::CAN_ID_BROADCAST);
      }
#else
      static
      symbol_type
      make_CAN_ID_BROADCAST ()
      {
        return symbol_type (token::CAN_ID_BROADCAST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_MASTER ()
      {
        return symbol_type (token::CAN_ID_MASTER);
      }
#else
      static
      symbol_type
      make_CAN_ID_MASTER ()
      {
        return symbol_type (token::CAN_ID_MASTER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_MASTER_INCREMENTAL ()
      {
        return symbol_type (token::CAN_ID_MASTER_INCREMENTAL);
      }
#else
      static
      symbol_type
      make_CAN_ID_MASTER_INCREMENTAL ()
      {
        return symbol_type (token::CAN_ID_MASTER_INCREMENTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_SLAVE ()
      {
        return symbol_type (token::CAN_ID_SLAVE);
      }
#else
      static
      symbol_type
      make_CAN_ID_SLAVE ()
      {
        return symbol_type (token::CAN_ID_SLAVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAN_ID_GET_DAQ_CLOCK_MULTICAST ()
      {
        return symbol_type (token::CAN_ID_GET_DAQ_CLOCK_MULTICAST);
      }
#else
      static
      symbol_type
      make_CAN_ID_GET_DAQ_CLOCK_MULTICAST ()
      {
        return symbol_type (token::CAN_ID_GET_DAQ_CLOCK_MULTICAST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHANNEL ()
      {
        return symbol_type (token::CHANNEL);
      }
#else
      static
      symbol_type
      make_CHANNEL ()
      {
        return symbol_type (token::CHANNEL);
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
      make_CLOCK ()
      {
        return symbol_type (token::CLOCK);
      }
#else
      static
      symbol_type
      make_CLOCK ()
      {
        return symbol_type (token::CLOCK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CMD ()
      {
        return symbol_type (token::CMD);
      }
#else
      static
      symbol_type
      make_CMD ()
      {
        return symbol_type (token::CMD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMUNICATION_MODE_SUPPORTED ()
      {
        return symbol_type (token::COMMUNICATION_MODE_SUPPORTED);
      }
#else
      static
      symbol_type
      make_COMMUNICATION_MODE_SUPPORTED ()
      {
        return symbol_type (token::COMMUNICATION_MODE_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSISTENCY_EVENT_LIST ()
      {
        return symbol_type (token::CONSISTENCY_EVENT_LIST);
      }
#else
      static
      symbol_type
      make_CONSISTENCY_EVENT_LIST ()
      {
        return symbol_type (token::CONSISTENCY_EVENT_LIST);
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
      make_CORE_LOAD_MAX ()
      {
        return symbol_type (token::CORE_LOAD_MAX);
      }
#else
      static
      symbol_type
      make_CORE_LOAD_MAX ()
      {
        return symbol_type (token::CORE_LOAD_MAX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CORE_LOAD_MAX_TOTAL ()
      {
        return symbol_type (token::CORE_LOAD_MAX_TOTAL);
      }
#else
      static
      symbol_type
      make_CORE_LOAD_MAX_TOTAL ()
      {
        return symbol_type (token::CORE_LOAD_MAX_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CORE_LOAD_EP ()
      {
        return symbol_type (token::CORE_LOAD_EP);
      }
#else
      static
      symbol_type
      make_CORE_LOAD_EP ()
      {
        return symbol_type (token::CORE_LOAD_EP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER ()
      {
        return symbol_type (token::COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER);
      }
#else
      static
      symbol_type
      make_COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER ()
      {
        return symbol_type (token::COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_LOAD_MAX ()
      {
        return symbol_type (token::CPU_LOAD_MAX);
      }
#else
      static
      symbol_type
      make_CPU_LOAD_MAX ()
      {
        return symbol_type (token::CPU_LOAD_MAX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_LOAD_MAX_TOTAL ()
      {
        return symbol_type (token::CPU_LOAD_MAX_TOTAL);
      }
#else
      static
      symbol_type
      make_CPU_LOAD_MAX_TOTAL ()
      {
        return symbol_type (token::CPU_LOAD_MAX_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_DAQ ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_DAQ);
      }
#else
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_DAQ ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_DAQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_STIM ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_STIM);
      }
#else
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_STIM ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_QUEUE ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_QUEUE);
      }
#else
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_QUEUE ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_QUEUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_QUEUE_STIM ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_QUEUE_STIM);
      }
#else
      static
      symbol_type
      make_CPU_LOAD_CONSUMPTION_QUEUE_STIM ()
      {
        return symbol_type (token::CPU_LOAD_CONSUMPTION_QUEUE_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CYCLE_REPETITION ()
      {
        return symbol_type (token::CYCLE_REPETITION);
      }
#else
      static
      symbol_type
      make_CYCLE_REPETITION ()
      {
        return symbol_type (token::CYCLE_REPETITION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ ()
      {
        return symbol_type (token::DAQ);
      }
#else
      static
      symbol_type
      make_DAQ ()
      {
        return symbol_type (token::DAQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_ALTERNATING_SUPPORTED ()
      {
        return symbol_type (token::DAQ_ALTERNATING_SUPPORTED);
      }
#else
      static
      symbol_type
      make_DAQ_ALTERNATING_SUPPORTED ()
      {
        return symbol_type (token::DAQ_ALTERNATING_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_EVENT ()
      {
        return symbol_type (token::DAQ_EVENT);
      }
#else
      static
      symbol_type
      make_DAQ_EVENT ()
      {
        return symbol_type (token::DAQ_EVENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_LIST ()
      {
        return symbol_type (token::DAQ_LIST);
      }
#else
      static
      symbol_type
      make_DAQ_LIST ()
      {
        return symbol_type (token::DAQ_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_LIST_CAN_ID ()
      {
        return symbol_type (token::DAQ_LIST_CAN_ID);
      }
#else
      static
      symbol_type
      make_DAQ_LIST_CAN_ID ()
      {
        return symbol_type (token::DAQ_LIST_CAN_ID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_LIST_USB_ENDPOINT ()
      {
        return symbol_type (token::DAQ_LIST_USB_ENDPOINT);
      }
#else
      static
      symbol_type
      make_DAQ_LIST_USB_ENDPOINT ()
      {
        return symbol_type (token::DAQ_LIST_USB_ENDPOINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_LIST_TYPE ()
      {
        return symbol_type (token::DAQ_LIST_TYPE);
      }
#else
      static
      symbol_type
      make_DAQ_LIST_TYPE ()
      {
        return symbol_type (token::DAQ_LIST_TYPE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_MEMORY_CONSUMPTION ()
      {
        return symbol_type (token::DAQ_MEMORY_CONSUMPTION);
      }
#else
      static
      symbol_type
      make_DAQ_MEMORY_CONSUMPTION ()
      {
        return symbol_type (token::DAQ_MEMORY_CONSUMPTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_PACKED_MODE ()
      {
        return symbol_type (token::DAQ_PACKED_MODE);
      }
#else
      static
      symbol_type
      make_DAQ_PACKED_MODE ()
      {
        return symbol_type (token::DAQ_PACKED_MODE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_PACKED_MODE_SUPPORTED ()
      {
        return symbol_type (token::DAQ_PACKED_MODE_SUPPORTED);
      }
#else
      static
      symbol_type
      make_DAQ_PACKED_MODE_SUPPORTED ()
      {
        return symbol_type (token::DAQ_PACKED_MODE_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DAQ_STIM ()
      {
        return symbol_type (token::DAQ_STIM);
      }
#else
      static
      symbol_type
      make_DAQ_STIM ()
      {
        return symbol_type (token::DAQ_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT_EVENT_LIST ()
      {
        return symbol_type (token::DEFAULT_EVENT_LIST);
      }
#else
      static
      symbol_type
      make_DEFAULT_EVENT_LIST ()
      {
        return symbol_type (token::DEFAULT_EVENT_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT_PAGE_NUMBER ()
      {
        return symbol_type (token::DEFAULT_PAGE_NUMBER);
      }
#else
      static
      symbol_type
      make_DEFAULT_PAGE_NUMBER ()
      {
        return symbol_type (token::DEFAULT_PAGE_NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DTO_CTR_DAQ_MODE ()
      {
        return symbol_type (token::DTO_CTR_DAQ_MODE);
      }
#else
      static
      symbol_type
      make_DTO_CTR_DAQ_MODE ()
      {
        return symbol_type (token::DTO_CTR_DAQ_MODE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DTO_CTR_DAQ_MODE_FIXED ()
      {
        return symbol_type (token::DTO_CTR_DAQ_MODE_FIXED);
      }
#else
      static
      symbol_type
      make_DTO_CTR_DAQ_MODE_FIXED ()
      {
        return symbol_type (token::DTO_CTR_DAQ_MODE_FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DTO_CTR_FIELD_SUPPORTED ()
      {
        return symbol_type (token::DTO_CTR_FIELD_SUPPORTED);
      }
#else
      static
      symbol_type
      make_DTO_CTR_FIELD_SUPPORTED ()
      {
        return symbol_type (token::DTO_CTR_FIELD_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DTO_CTR_STIM_MODE ()
      {
        return symbol_type (token::DTO_CTR_STIM_MODE);
      }
#else
      static
      symbol_type
      make_DTO_CTR_STIM_MODE ()
      {
        return symbol_type (token::DTO_CTR_STIM_MODE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DTO_CTR_STIM_MODE_FIXED ()
      {
        return symbol_type (token::DTO_CTR_STIM_MODE_FIXED);
      }
#else
      static
      symbol_type
      make_DTO_CTR_STIM_MODE_FIXED ()
      {
        return symbol_type (token::DTO_CTR_STIM_MODE_FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ECU_STATES ()
      {
        return symbol_type (token::ECU_STATES);
      }
#else
      static
      symbol_type
      make_ECU_STATES ()
      {
        return symbol_type (token::ECU_STATES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ECU_SWITCHED_TO_DEFAULT_PAGE ()
      {
        return symbol_type (token::ECU_SWITCHED_TO_DEFAULT_PAGE);
      }
#else
      static
      symbol_type
      make_ECU_SWITCHED_TO_DEFAULT_PAGE ()
      {
        return symbol_type (token::ECU_SWITCHED_TO_DEFAULT_PAGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EV_SERV ()
      {
        return symbol_type (token::EV_SERV);
      }
#else
      static
      symbol_type
      make_EV_SERV ()
      {
        return symbol_type (token::EV_SERV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EVENT ()
      {
        return symbol_type (token::EVENT);
      }
#else
      static
      symbol_type
      make_EVENT ()
      {
        return symbol_type (token::EVENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EVENT_CAN_ID_LIST ()
      {
        return symbol_type (token::EVENT_CAN_ID_LIST);
      }
#else
      static
      symbol_type
      make_EVENT_CAN_ID_LIST ()
      {
        return symbol_type (token::EVENT_CAN_ID_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EVENT_COUNTER_PRESENT ()
      {
        return symbol_type (token::EVENT_COUNTER_PRESENT);
      }
#else
      static
      symbol_type
      make_EVENT_COUNTER_PRESENT ()
      {
        return symbol_type (token::EVENT_COUNTER_PRESENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EVENT_FIXED ()
      {
        return symbol_type (token::EVENT_FIXED);
      }
#else
      static
      symbol_type
      make_EVENT_FIXED ()
      {
        return symbol_type (token::EVENT_FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTERNAL_FUNCTION ()
      {
        return symbol_type (token::EXTERNAL_FUNCTION);
      }
#else
      static
      symbol_type
      make_EXTERNAL_FUNCTION ()
      {
        return symbol_type (token::EXTERNAL_FUNCTION);
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
      make_FIXED ()
      {
        return symbol_type (token::FIXED);
      }
#else
      static
      symbol_type
      make_FIXED ()
      {
        return symbol_type (token::FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIXED_EVENT_LIST ()
      {
        return symbol_type (token::FIXED_EVENT_LIST);
      }
#else
      static
      symbol_type
      make_FIXED_EVENT_LIST ()
      {
        return symbol_type (token::FIXED_EVENT_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIXED_IN ()
      {
        return symbol_type (token::FIXED_IN);
      }
#else
      static
      symbol_type
      make_FIXED_IN ()
      {
        return symbol_type (token::FIXED_IN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIXED_OUT ()
      {
        return symbol_type (token::FIXED_OUT);
      }
#else
      static
      symbol_type
      make_FIXED_OUT ()
      {
        return symbol_type (token::FIXED_OUT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLX_SLOT_ID ()
      {
        return symbol_type (token::FLX_SLOT_ID);
      }
#else
      static
      symbol_type
      make_FLX_SLOT_ID ()
      {
        return symbol_type (token::FLX_SLOT_ID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FRAMING ()
      {
        return symbol_type (token::FRAMING);
      }
#else
      static
      symbol_type
      make_FRAMING ()
      {
        return symbol_type (token::FRAMING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FREEZE_SUPPORTED ()
      {
        return symbol_type (token::FREEZE_SUPPORTED);
      }
#else
      static
      symbol_type
      make_FREEZE_SUPPORTED ()
      {
        return symbol_type (token::FREEZE_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HOST_NAME ()
      {
        return symbol_type (token::HOST_NAME);
      }
#else
      static
      symbol_type
      make_HOST_NAME ()
      {
        return symbol_type (token::HOST_NAME);
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
      make_IN_EP_ONLY_DAQ ()
      {
        return symbol_type (token::IN_EP_ONLY_DAQ);
      }
#else
      static
      symbol_type
      make_IN_EP_ONLY_DAQ ()
      {
        return symbol_type (token::IN_EP_ONLY_DAQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN_EP_ONLY_EVSERV ()
      {
        return symbol_type (token::IN_EP_ONLY_EVSERV);
      }
#else
      static
      symbol_type
      make_IN_EP_ONLY_EVSERV ()
      {
        return symbol_type (token::IN_EP_ONLY_EVSERV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN_EP_RESERR_DAQ_EVSERV ()
      {
        return symbol_type (token::IN_EP_RESERR_DAQ_EVSERV);
      }
#else
      static
      symbol_type
      make_IN_EP_RESERR_DAQ_EVSERV ()
      {
        return symbol_type (token::IN_EP_RESERR_DAQ_EVSERV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INIT_SEGMENT ()
      {
        return symbol_type (token::INIT_SEGMENT);
      }
#else
      static
      symbol_type
      make_INIT_SEGMENT ()
      {
        return symbol_type (token::INIT_SEGMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INITIAL_VALUE ()
      {
        return symbol_type (token::INITIAL_VALUE);
      }
#else
      static
      symbol_type
      make_INITIAL_VALUE ()
      {
        return symbol_type (token::INITIAL_VALUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INITIAL_CMD_BUFFER ()
      {
        return symbol_type (token::INITIAL_CMD_BUFFER);
      }
#else
      static
      symbol_type
      make_INITIAL_CMD_BUFFER ()
      {
        return symbol_type (token::INITIAL_CMD_BUFFER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INITIAL_RES_ERR_BUFFER ()
      {
        return symbol_type (token::INITIAL_RES_ERR_BUFFER);
      }
#else
      static
      symbol_type
      make_INITIAL_RES_ERR_BUFFER ()
      {
        return symbol_type (token::INITIAL_RES_ERR_BUFFER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERFACE_STRING_DESCRIPTOR ()
      {
        return symbol_type (token::INTERFACE_STRING_DESCRIPTOR);
      }
#else
      static
      symbol_type
      make_INTERFACE_STRING_DESCRIPTOR ()
      {
        return symbol_type (token::INTERFACE_STRING_DESCRIPTOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERLEAVED ()
      {
        return symbol_type (token::INTERLEAVED);
      }
#else
      static
      symbol_type
      make_INTERLEAVED ()
      {
        return symbol_type (token::INTERLEAVED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IPV6 ()
      {
        return symbol_type (token::IPV6);
      }
#else
      static
      symbol_type
      make_IPV6 ()
      {
        return symbol_type (token::IPV6);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPU_ID ()
      {
        return symbol_type (token::LPU_ID);
      }
#else
      static
      symbol_type
      make_LPU_ID ()
      {
        return symbol_type (token::LPU_ID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MASTER ()
      {
        return symbol_type (token::MASTER);
      }
#else
      static
      symbol_type
      make_MASTER ()
      {
        return symbol_type (token::MASTER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_BLOCK_SIZE ()
      {
        return symbol_type (token::MAX_BLOCK_SIZE);
      }
#else
      static
      symbol_type
      make_MAX_BLOCK_SIZE ()
      {
        return symbol_type (token::MAX_BLOCK_SIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_DAQ_TOTAL ()
      {
        return symbol_type (token::MAX_DAQ_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_DAQ_TOTAL ()
      {
        return symbol_type (token::MAX_DAQ_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_DLC_REQUIRED ()
      {
        return symbol_type (token::MAX_DLC_REQUIRED);
      }
#else
      static
      symbol_type
      make_MAX_DLC_REQUIRED ()
      {
        return symbol_type (token::MAX_DLC_REQUIRED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_BUS_LOAD ()
      {
        return symbol_type (token::MAX_BUS_LOAD);
      }
#else
      static
      symbol_type
      make_MAX_BUS_LOAD ()
      {
        return symbol_type (token::MAX_BUS_LOAD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_DLC ()
      {
        return symbol_type (token::MAX_DLC);
      }
#else
      static
      symbol_type
      make_MAX_DLC ()
      {
        return symbol_type (token::MAX_DLC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_DTO_STIM ()
      {
        return symbol_type (token::MAX_DTO_STIM);
      }
#else
      static
      symbol_type
      make_MAX_DTO_STIM ()
      {
        return symbol_type (token::MAX_DTO_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_BIT_RATE ()
      {
        return symbol_type (token::MAX_BIT_RATE);
      }
#else
      static
      symbol_type
      make_MAX_BIT_RATE ()
      {
        return symbol_type (token::MAX_BIT_RATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_FLX_LEN_BUF ()
      {
        return symbol_type (token::MAX_FLX_LEN_BUF);
      }
#else
      static
      symbol_type
      make_MAX_FLX_LEN_BUF ()
      {
        return symbol_type (token::MAX_FLX_LEN_BUF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT ()
      {
        return symbol_type (token::MAX_ODT);
      }
#else
      static
      symbol_type
      make_MAX_ODT ()
      {
        return symbol_type (token::MAX_ODT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_DAQ_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_DAQ_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_ODT_DAQ_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_DAQ_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_ENTRIES ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES);
      }
#else
      static
      symbol_type
      make_MAX_ODT_ENTRIES ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_ENTRIES_DAQ_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES_DAQ_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_ODT_ENTRIES_DAQ_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES_DAQ_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_ENTRIES_STIM_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES_STIM_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_ODT_ENTRIES_STIM_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES_STIM_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_ENTRIES_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_ODT_ENTRIES_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_ENTRIES_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_STIM_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_STIM_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_ODT_STIM_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_STIM_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_ODT_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_TOTAL);
      }
#else
      static
      symbol_type
      make_MAX_ODT_TOTAL ()
      {
        return symbol_type (token::MAX_ODT_TOTAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEASUREMENT_SPLIT_ALLOWED ()
      {
        return symbol_type (token::MEASUREMENT_SPLIT_ALLOWED);
      }
#else
      static
      symbol_type
      make_MEASUREMENT_SPLIT_ALLOWED ()
      {
        return symbol_type (token::MEASUREMENT_SPLIT_ALLOWED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEMORY_ACCESS ()
      {
        return symbol_type (token::MEMORY_ACCESS);
      }
#else
      static
      symbol_type
      make_MEMORY_ACCESS ()
      {
        return symbol_type (token::MEMORY_ACCESS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN_CYCLE_TIME ()
      {
        return symbol_type (token::MIN_CYCLE_TIME);
      }
#else
      static
      symbol_type
      make_MIN_CYCLE_TIME ()
      {
        return symbol_type (token::MIN_CYCLE_TIME);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MIN_ST_STIM ()
      {
        return symbol_type (token::MIN_ST_STIM);
      }
#else
      static
      symbol_type
      make_MIN_ST_STIM ()
      {
        return symbol_type (token::MIN_ST_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODEL_NAME ()
      {
        return symbol_type (token::MODEL_NAME);
      }
#else
      static
      symbol_type
      make_MODEL_NAME ()
      {
        return symbol_type (token::MODEL_NAME);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MTA_BLOCK_SIZE_ALIGN ()
      {
        return symbol_type (token::MTA_BLOCK_SIZE_ALIGN);
      }
#else
      static
      symbol_type
      make_MTA_BLOCK_SIZE_ALIGN ()
      {
        return symbol_type (token::MTA_BLOCK_SIZE_ALIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTICAST ()
      {
        return symbol_type (token::MULTICAST);
      }
#else
      static
      symbol_type
      make_MULTICAST ()
      {
        return symbol_type (token::MULTICAST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ODT ()
      {
        return symbol_type (token::ODT);
      }
#else
      static
      symbol_type
      make_ODT ()
      {
        return symbol_type (token::ODT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ODT_ENTRY ()
      {
        return symbol_type (token::ODT_ENTRY);
      }
#else
      static
      symbol_type
      make_ODT_ENTRY ()
      {
        return symbol_type (token::ODT_ENTRY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ODT_ENTRY_SIZE_FACTOR_TABLE ()
      {
        return symbol_type (token::ODT_ENTRY_SIZE_FACTOR_TABLE);
      }
#else
      static
      symbol_type
      make_ODT_ENTRY_SIZE_FACTOR_TABLE ()
      {
        return symbol_type (token::ODT_ENTRY_SIZE_FACTOR_TABLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPTIMISATION_TYPE_ODT_STRICT ()
      {
        return symbol_type (token::OPTIMISATION_TYPE_ODT_STRICT);
      }
#else
      static
      symbol_type
      make_OPTIMISATION_TYPE_ODT_STRICT ()
      {
        return symbol_type (token::OPTIMISATION_TYPE_ODT_STRICT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OFFSET ()
      {
        return symbol_type (token::OFFSET);
      }
#else
      static
      symbol_type
      make_OFFSET ()
      {
        return symbol_type (token::OFFSET);
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
      make_OPTIONAL_LEVEL1_CMD ()
      {
        return symbol_type (token::OPTIONAL_LEVEL1_CMD);
      }
#else
      static
      symbol_type
      make_OPTIONAL_LEVEL1_CMD ()
      {
        return symbol_type (token::OPTIONAL_LEVEL1_CMD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPTIONAL_TL_SUBCMD ()
      {
        return symbol_type (token::OPTIONAL_TL_SUBCMD);
      }
#else
      static
      symbol_type
      make_OPTIONAL_TL_SUBCMD ()
      {
        return symbol_type (token::OPTIONAL_TL_SUBCMD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUT_EP_ONLY_STIM ()
      {
        return symbol_type (token::OUT_EP_ONLY_STIM);
      }
#else
      static
      symbol_type
      make_OUT_EP_ONLY_STIM ()
      {
        return symbol_type (token::OUT_EP_ONLY_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUT_EP_CMD_STIM ()
      {
        return symbol_type (token::OUT_EP_CMD_STIM);
      }
#else
      static
      symbol_type
      make_OUT_EP_CMD_STIM ()
      {
        return symbol_type (token::OUT_EP_CMD_STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PACKET_ALIGNMENT ()
      {
        return symbol_type (token::PACKET_ALIGNMENT);
      }
#else
      static
      symbol_type
      make_PACKET_ALIGNMENT ()
      {
        return symbol_type (token::PACKET_ALIGNMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PAG ()
      {
        return symbol_type (token::PAG);
      }
#else
      static
      symbol_type
      make_PAG ()
      {
        return symbol_type (token::PAG);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PAGE ()
      {
        return symbol_type (token::PAGE);
      }
#else
      static
      symbol_type
      make_PAGE ()
      {
        return symbol_type (token::PAGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PGM ()
      {
        return symbol_type (token::PGM);
      }
#else
      static
      symbol_type
      make_PGM ()
      {
        return symbol_type (token::PGM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PID_OFF_SUPPORTED ()
      {
        return symbol_type (token::PID_OFF_SUPPORTED);
      }
#else
      static
      symbol_type
      make_PID_OFF_SUPPORTED ()
      {
        return symbol_type (token::PID_OFF_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POOL_BUFFER ()
      {
        return symbol_type (token::POOL_BUFFER);
      }
#else
      static
      symbol_type
      make_POOL_BUFFER ()
      {
        return symbol_type (token::POOL_BUFFER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PREDEFINED ()
      {
        return symbol_type (token::PREDEFINED);
      }
#else
      static
      symbol_type
      make_PREDEFINED ()
      {
        return symbol_type (token::PREDEFINED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRESCALER_SUPPORTED ()
      {
        return symbol_type (token::PRESCALER_SUPPORTED);
      }
#else
      static
      symbol_type
      make_PRESCALER_SUPPORTED ()
      {
        return symbol_type (token::PRESCALER_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROTOCOL_LAYER ()
      {
        return symbol_type (token::PROTOCOL_LAYER);
      }
#else
      static
      symbol_type
      make_PROTOCOL_LAYER ()
      {
        return symbol_type (token::PROTOCOL_LAYER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECOMMENDED_HOST_BUFSIZE ()
      {
        return symbol_type (token::RECOMMENDED_HOST_BUFSIZE);
      }
#else
      static
      symbol_type
      make_RECOMMENDED_HOST_BUFSIZE ()
      {
        return symbol_type (token::RECOMMENDED_HOST_BUFSIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELATED_EVENT_CHANNEL_NUMBER ()
      {
        return symbol_type (token::RELATED_EVENT_CHANNEL_NUMBER);
      }
#else
      static
      symbol_type
      make_RELATED_EVENT_CHANNEL_NUMBER ()
      {
        return symbol_type (token::RELATED_EVENT_CHANNEL_NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELATED_EVENT_CHANNEL_NUMBER_FIXED ()
      {
        return symbol_type (token::RELATED_EVENT_CHANNEL_NUMBER_FIXED);
      }
#else
      static
      symbol_type
      make_RELATED_EVENT_CHANNEL_NUMBER_FIXED ()
      {
        return symbol_type (token::RELATED_EVENT_CHANNEL_NUMBER_FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RES_ERR ()
      {
        return symbol_type (token::RES_ERR);
      }
#else
      static
      symbol_type
      make_RES_ERR ()
      {
        return symbol_type (token::RES_ERR);
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
      make_SECTOR ()
      {
        return symbol_type (token::SECTOR);
      }
#else
      static
      symbol_type
      make_SECTOR ()
      {
        return symbol_type (token::SECTOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEGMENT ()
      {
        return symbol_type (token::SEGMENT);
      }
#else
      static
      symbol_type
      make_SEGMENT ()
      {
        return symbol_type (token::SEGMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SECONDARY_SAMPLE_POINT ()
      {
        return symbol_type (token::SECONDARY_SAMPLE_POINT);
      }
#else
      static
      symbol_type
      make_SECONDARY_SAMPLE_POINT ()
      {
        return symbol_type (token::SECONDARY_SAMPLE_POINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEED_AND_KEY_EXTERNAL_FUNCTION ()
      {
        return symbol_type (token::SEED_AND_KEY_EXTERNAL_FUNCTION);
      }
#else
      static
      symbol_type
      make_SEED_AND_KEY_EXTERNAL_FUNCTION ()
      {
        return symbol_type (token::SEED_AND_KEY_EXTERNAL_FUNCTION);
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
      make_SLAVE ()
      {
        return symbol_type (token::SLAVE);
      }
#else
      static
      symbol_type
      make_SLAVE ()
      {
        return symbol_type (token::SLAVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATE ()
      {
        return symbol_type (token::STATE);
      }
#else
      static
      symbol_type
      make_STATE ()
      {
        return symbol_type (token::STATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STIM ()
      {
        return symbol_type (token::STIM);
      }
#else
      static
      symbol_type
      make_STIM ()
      {
        return symbol_type (token::STIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STIM_DTO_CTR_COPY_PRESENT ()
      {
        return symbol_type (token::STIM_DTO_CTR_COPY_PRESENT);
      }
#else
      static
      symbol_type
      make_STIM_DTO_CTR_COPY_PRESENT ()
      {
        return symbol_type (token::STIM_DTO_CTR_COPY_PRESENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STORE_DAQ_SUPPORTED ()
      {
        return symbol_type (token::STORE_DAQ_SUPPORTED);
      }
#else
      static
      symbol_type
      make_STORE_DAQ_SUPPORTED ()
      {
        return symbol_type (token::STORE_DAQ_SUPPORTED);
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
      make_SYNCH_FULL_DUPLEX_MODE_BYTE ()
      {
        return symbol_type (token::SYNCH_FULL_DUPLEX_MODE_BYTE);
      }
#else
      static
      symbol_type
      make_SYNCH_FULL_DUPLEX_MODE_BYTE ()
      {
        return symbol_type (token::SYNCH_FULL_DUPLEX_MODE_BYTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNCH_FULL_DUPLEX_MODE_WORD ()
      {
        return symbol_type (token::SYNCH_FULL_DUPLEX_MODE_WORD);
      }
#else
      static
      symbol_type
      make_SYNCH_FULL_DUPLEX_MODE_WORD ()
      {
        return symbol_type (token::SYNCH_FULL_DUPLEX_MODE_WORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNCH_FULL_DUPLEX_MODE_DWORD ()
      {
        return symbol_type (token::SYNCH_FULL_DUPLEX_MODE_DWORD);
      }
#else
      static
      symbol_type
      make_SYNCH_FULL_DUPLEX_MODE_DWORD ()
      {
        return symbol_type (token::SYNCH_FULL_DUPLEX_MODE_DWORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNCH_FULL_MASTER_MODE_BYTE ()
      {
        return symbol_type (token::SYNCH_FULL_MASTER_MODE_BYTE);
      }
#else
      static
      symbol_type
      make_SYNCH_FULL_MASTER_MODE_BYTE ()
      {
        return symbol_type (token::SYNCH_FULL_MASTER_MODE_BYTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNCH_FULL_MASTER_MODE_WORD ()
      {
        return symbol_type (token::SYNCH_FULL_MASTER_MODE_WORD);
      }
#else
      static
      symbol_type
      make_SYNCH_FULL_MASTER_MODE_WORD ()
      {
        return symbol_type (token::SYNCH_FULL_MASTER_MODE_WORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYNCH_FULL_MASTER_MODE_DWORD ()
      {
        return symbol_type (token::SYNCH_FULL_MASTER_MODE_DWORD);
      }
#else
      static
      symbol_type
      make_SYNCH_FULL_MASTER_MODE_DWORD ()
      {
        return symbol_type (token::SYNCH_FULL_MASTER_MODE_DWORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIME_CHARACTERIZATION ()
      {
        return symbol_type (token::TIME_CHARACTERIZATION);
      }
#else
      static
      symbol_type
      make_TIME_CHARACTERIZATION ()
      {
        return symbol_type (token::TIME_CHARACTERIZATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIME_CORRELATION ()
      {
        return symbol_type (token::TIME_CORRELATION);
      }
#else
      static
      symbol_type
      make_TIME_CORRELATION ()
      {
        return symbol_type (token::TIME_CORRELATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIMESTAMP_FIXED ()
      {
        return symbol_type (token::TIMESTAMP_FIXED);
      }
#else
      static
      symbol_type
      make_TIMESTAMP_FIXED ()
      {
        return symbol_type (token::TIMESTAMP_FIXED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TIMESTAMP_SUPPORTED ()
      {
        return symbol_type (token::TIMESTAMP_SUPPORTED);
      }
#else
      static
      symbol_type
      make_TIMESTAMP_SUPPORTED ()
      {
        return symbol_type (token::TIMESTAMP_SUPPORTED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRANSPORT_LAYER_INSTANCE ()
      {
        return symbol_type (token::TRANSPORT_LAYER_INSTANCE);
      }
#else
      static
      symbol_type
      make_TRANSPORT_LAYER_INSTANCE ()
      {
        return symbol_type (token::TRANSPORT_LAYER_INSTANCE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRANSCEIVER_DELAY_COMPENSATION ()
      {
        return symbol_type (token::TRANSCEIVER_DELAY_COMPENSATION);
      }
#else
      static
      symbol_type
      make_TRANSCEIVER_DELAY_COMPENSATION ()
      {
        return symbol_type (token::TRANSCEIVER_DELAY_COMPENSATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VARIABLE ()
      {
        return symbol_type (token::VARIABLE);
      }
#else
      static
      symbol_type
      make_VARIABLE ()
      {
        return symbol_type (token::VARIABLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP ()
      {
        return symbol_type (token::XCP);
      }
#else
      static
      symbol_type
      make_XCP ()
      {
        return symbol_type (token::XCP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCPplus ()
      {
        return symbol_type (token::XCPplus);
      }
#else
      static
      symbol_type
      make_XCPplus ()
      {
        return symbol_type (token::XCPplus);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_CAN ()
      {
        return symbol_type (token::XCP_ON_CAN);
      }
#else
      static
      symbol_type
      make_XCP_ON_CAN ()
      {
        return symbol_type (token::XCP_ON_CAN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_SxI ()
      {
        return symbol_type (token::XCP_ON_SxI);
      }
#else
      static
      symbol_type
      make_XCP_ON_SxI ()
      {
        return symbol_type (token::XCP_ON_SxI);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_TCP_IP ()
      {
        return symbol_type (token::XCP_ON_TCP_IP);
      }
#else
      static
      symbol_type
      make_XCP_ON_TCP_IP ()
      {
        return symbol_type (token::XCP_ON_TCP_IP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_UDP_IP ()
      {
        return symbol_type (token::XCP_ON_UDP_IP);
      }
#else
      static
      symbol_type
      make_XCP_ON_UDP_IP ()
      {
        return symbol_type (token::XCP_ON_UDP_IP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_USB ()
      {
        return symbol_type (token::XCP_ON_USB);
      }
#else
      static
      symbol_type
      make_XCP_ON_USB ()
      {
        return symbol_type (token::XCP_ON_USB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_FLX ()
      {
        return symbol_type (token::XCP_ON_FLX);
      }
#else
      static
      symbol_type
      make_XCP_ON_FLX ()
      {
        return symbol_type (token::XCP_ON_FLX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_ON_SIMULINK ()
      {
        return symbol_type (token::XCP_ON_SIMULINK);
      }
#else
      static
      symbol_type
      make_XCP_ON_SIMULINK ()
      {
        return symbol_type (token::XCP_ON_SIMULINK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_XCP_PACKET ()
      {
        return symbol_type (token::XCP_PACKET);
      }
#else
      static
      symbol_type
      make_XCP_PACKET ()
      {
        return symbol_type (token::XCP_PACKET);
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


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    XcpDataParser (const XcpDataParser&);
    /// Non copyable.
    XcpDataParser& operator= (const XcpDataParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

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

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if XCPDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if XCPDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const short yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const short yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if XCPDEBUG
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
      yylast_ = 735,     ///< Last index in yytable_.
      yynnts_ = 153,  ///< Number of nonterminal symbols.
      yyfinal_ = 4 ///< Termination state number.
    };


    // User arguments.
    a2l::xcp::XcpDataScanner &scanner;

  };


#line 6 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
} } // a2l::xcp
#line 4337 "D:/projects/a2llib/src/xcp/xcpdataparser.hpp"




#endif // !YY_XCP_D_PROJECTS_A2LLIB_SRC_XCP_XCPDATAPARSER_HPP_INCLUDED
