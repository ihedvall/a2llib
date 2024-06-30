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
 ** \file /home/ihedvall/CLionProjects/a2llib/src/a2lparser.hpp
 ** Define the a2l::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_A2L_HOME_IHEDVALL_CLIONPROJECTS_A2LLIB_SRC_A2LPARSER_HPP_INCLUDED
# define YY_A2L_HOME_IHEDVALL_CLIONPROJECTS_A2LLIB_SRC_A2LPARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 9 "/home/ihedvall/CLionProjects/a2llib/src/a2lparser.y"

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/a2lenums.h"
#include "a2l/a2lstructs.h"
namespace a2l {
class A2lScanner;
class A2lFile;
}


#line 63 "/home/ihedvall/CLionProjects/a2llib/src/a2lparser.hpp"


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
#ifndef A2LDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define A2LDEBUG 1
#  else
#   define A2LDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define A2LDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined A2LDEBUG */

#line 5 "/home/ihedvall/CLionProjects/a2llib/src/a2lparser.y"
namespace a2l {
#line 207 "/home/ihedvall/CLionProjects/a2llib/src/a2lparser.hpp"




  /// A Bison parser.
  class A2lParser
  {
  public:
#ifdef A2LSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define A2LSTYPE in C++, use %define api.value.type"
# endif
    typedef A2LSTYPE value_type;
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
      // address_type
      char dummy1[sizeof (A2lAddressType)];

      // annotation
      // annotation_attributes
      char dummy2[sizeof (A2lAnnotation)];

      // axis_pts_x
      // axis_pts_y
      // axis_pts_z
      // axis_pts_4
      // axis_pts_5
      char dummy3[sizeof (A2lAxisPts)];

      // axis_rescale_x
      char dummy4[sizeof (A2lAxisRescale)];

      // bit_operation
      char dummy5[sizeof (A2lBitOperation)];

      // byte_order
      char dummy6[sizeof (A2lByteOrder)];

      // calibration_access
      char dummy7[sizeof (A2lCalibrationAccess)];

      // calibration_handle
      char dummy8[sizeof (A2lCalibrationHandle)];

      // calibration_method
      char dummy9[sizeof (A2lCalibrationMethod)];

      // dependent_characteristic
      // virtual_characteristic
      char dummy10[sizeof (A2lDependentCharacteristic)];

      // deposit
      char dummy11[sizeof (A2lDeposit)];

      // dist_op_x
      // dist_op_y
      // dist_op_z
      // dist_op_4
      // dist_op_5
      // no_axis_pts_x
      // no_axis_pts_y
      // no_axis_pts_z
      // no_axis_pts_4
      // no_axis_pts_5
      // no_rescale_x
      // offset_x
      // offset_y
      // offset_z
      // offset_4
      // offset_5
      // reserved
      // rip_addr_w
      // rip_addr_x
      // rip_addr_y
      // rip_addr_z
      // rip_addr_4
      // rip_addr_5
      // shift_op_x
      // shift_op_y
      // shift_op_z
      // shift_op_4
      // shift_op_5
      // src_addr_x
      // src_addr_y
      // src_addr_z
      // src_addr_4
      // src_addr_5
      char dummy12[sizeof (A2lDistOp)];

      // encoding
      char dummy13[sizeof (A2lEncoding)];

      // extended_limits
      char dummy14[sizeof (A2lExtendedLimits)];

      // fix_axis_par
      char dummy15[sizeof (A2lFixAxisPar)];

      // fix_axis_par_dist
      char dummy16[sizeof (A2lFixAxisParDist)];

      // fnc_values
      char dummy17[sizeof (A2lFncValue)];

      // identification
      char dummy18[sizeof (A2lIdentification)];

      // layout
      char dummy19[sizeof (A2lLayout)];

      // limits
      char dummy20[sizeof (A2lLimits)];

      // max_refresh
      char dummy21[sizeof (A2lMaxRefresh)];

      // memory_layout
      char dummy22[sizeof (A2lMemoryLayout)];

      // memory_segment
      char dummy23[sizeof (A2lMemorySegment)];

      // monotony
      char dummy24[sizeof (A2lMonotony)];

      // prg_type
      char dummy25[sizeof (A2lSegmentType)];

      // si_exponents
      char dummy26[sizeof (A2lSiExponents)];

      // symbol_link
      char dummy27[sizeof (A2lSymbolLink)];

      // var_characteristic
      char dummy28[sizeof (A2lVarCharacteristic)];

      // var_criterion
      char dummy29[sizeof (A2lVarCriterion)];

      // FLOAT
      // any_float
      // default_value_numeric
      // max_grad
      // step_size
      char dummy30[sizeof (double)];

      // INT
      // any_int
      // ecu_address_extension
      // ecu_calibration_offset
      char dummy31[sizeof (int64_t)];

      // float_pair_list
      char dummy32[sizeof (std::map<double, double>)];

      // float_string_list
      char dummy33[sizeof (std::map<double, std::string>)];

      // float_range_list
      char dummy34[sizeof (std::map<std::pair<double, double>, std::string>)];

      // key_value_list
      // memory_layout_attributes
      // memory_segment_attributes
      // var_forbidden_comb
      char dummy35[sizeof (std::map<std::string, std::string>)];

      // unit_conversion
      char dummy36[sizeof (std::pair<double,double>)];

      // formula
      // system_constant
      char dummy37[sizeof (std::pair<std::string,std::string>)];

      // IDENT
      // STRING
      // A2ML
      // IF_DATA
      // ar_component_attribute
      // calibration_handle_attribute
      // formula_attribute
      // a2ml
      // annotation_label
      // annotation_origin
      // ar_prototype_of
      // axis_pts_ref
      // calibration_handle_text
      // comparison_quantity
      // compu_tab_ref
      // conversion
      // cpu_type
      // curve_axis_ref
      // customer
      // customer_no
      // default_value
      // display_identifier
      // ecu
      // epk
      // format
      // formula_inv
      // function_version
      // if_data
      // input_quantity
      // model_link
      // phone_no
      // phys_unit
      // proj_no
      // project_no
      // ref_memory_segment
      // ref_unit
      // status_string_ref
      // supplier
      // symbol_type_link
      // user
      // var_measurement
      // var_naming
      // var_selection_characteristic
      // var_separator
      // version
      char dummy38[sizeof (std::string)];

      // calibration_method_attributes
      char dummy39[sizeof (std::vector<A2lCalibrationHandle>)];

      // float_list
      // fix_axis_par_list
      // coeffs
      // coeffs_linear
      char dummy40[sizeof (std::vector<double>)];

      // int_list
      char dummy41[sizeof (std::vector<int64_t>)];

      // string_list
      // ident_list
      // annotation_text
      // def_characteristic
      // function_list
      // in_measurement
      // loc_measurement
      // map_list
      // out_measurement
      // ref_characteristic
      // ref_group
      // ref_measurement
      // sub_function
      // sub_group
      // transformer_in_objects
      // transformer_out_objects
      // virtual
      // frame_measurement
      char dummy42[sizeof (std::vector<std::string>)];

      // uint_list
      // var_address
      // var_characteristic_attribute
      // matrix_dim
      char dummy43[sizeof (std::vector<uint64_t>)];

      // UINT
      // HEX
      // any_uint
      // addr_epk
      // alignment_byte
      // alignment_float16_ieee
      // alignment_float32_ieee
      // alignment_float64_ieee
      // alignment_int64
      // alignment_long
      // alignment_word
      // array_size
      // bit_mask
      // data_size
      // ecu_address
      // error_mask
      // fix_no_axis_pts_x
      // fix_no_axis_pts_y
      // fix_no_axis_pts_z
      // fix_no_axis_pts_4
      // fix_no_axis_pts_5
      // left_shift
      // no_of_interfaces
      // number
      // right_shift
      char dummy44[sizeof (uint64_t)];
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
        A2LEMPTY = -2,
    EOL = 0,                       // EOL
    A2Lerror = 256,                // error
    A2LUNDEF = 257,                // "invalid token"
    A2L_BEGIN = 258,               // A2L_BEGIN
    A2L_END = 259,                 // A2L_END
    A2L_INCLUDE = 260,             // A2L_INCLUDE
    IDENT = 261,                   // IDENT
    STRING = 262,                  // STRING
    INT = 263,                     // INT
    UINT = 264,                    // UINT
    HEX = 265,                     // HEX
    FLOAT = 266,                   // FLOAT
    ASAP2_VERSION = 267,           // ASAP2_VERSION
    A2L_VERSION = 268,             // A2L_VERSION
    A2ML_VERSION = 269,            // A2ML_VERSION
    A2ML = 270,                    // A2ML
    ADDR_EPK = 271,                // ADDR_EPK
    ADDRESS_TYPE = 272,            // ADDRESS_TYPE
    ALIGNMENT_BYTE = 273,          // ALIGNMENT_BYTE
    ALIGNMENT_FLOAT16_IEEE = 274,  // ALIGNMENT_FLOAT16_IEEE
    ALIGNMENT_FLOAT32_IEEE = 275,  // ALIGNMENT_FLOAT32_IEEE
    ALIGNMENT_FLOAT64_IEEE = 276,  // ALIGNMENT_FLOAT64_IEEE
    ALIGNMENT_INT64 = 277,         // ALIGNMENT_INT64
    ALIGNMENT_LONG = 278,          // ALIGNMENT_LONG
    ALIGNMENT_WORD = 279,          // ALIGNMENT_WORD
    ANNOTATION = 280,              // ANNOTATION
    ANNOTATION_LABEL = 281,        // ANNOTATION_LABEL
    ANNOTATION_ORIGIN = 282,       // ANNOTATION_ORIGIN
    ANNOTATION_TEXT = 283,         // ANNOTATION_TEXT
    ARRAY_SIZE = 284,              // ARRAY_SIZE
    AR_COMPONENT = 285,            // AR_COMPONENT
    AR_PROTOTYPE_OF = 286,         // AR_PROTOTYPE_OF
    AXIS_DESCR = 287,              // AXIS_DESCR
    AXIS_PTS = 288,                // AXIS_PTS
    AXIS_PTS_REF = 289,            // AXIS_PTS_REF
    AXIS_PTS_X = 290,              // AXIS_PTS_X
    AXIS_PTS_Y = 291,              // AXIS_PTS_Y
    AXIS_PTS_Z = 292,              // AXIS_PTS_Z
    AXIS_PTS_4 = 293,              // AXIS_PTS_4
    AXIS_PTS_5 = 294,              // AXIS_PTS_5
    AXIS_RESCALE_X = 295,          // AXIS_RESCALE_X
    BIT_MASK = 296,                // BIT_MASK
    BIT_OPERATION = 297,           // BIT_OPERATION
    BLOB = 298,                    // BLOB
    A2L_BYTE_ORDER = 299,          // A2L_BYTE_ORDER
    CALIBRATION_ACCESS = 300,      // CALIBRATION_ACCESS
    CALIBRATION_HANDLE = 301,      // CALIBRATION_HANDLE
    CALIBRATION_HANDLE_TEXT = 302, // CALIBRATION_HANDLE_TEXT
    CALIBRATION_METHOD = 303,      // CALIBRATION_METHOD
    CHARACTERISTIC = 304,          // CHARACTERISTIC
    COEFFS = 305,                  // COEFFS
    COEFFS_LINEAR = 306,           // COEFFS_LINEAR
    COMPARISON_QUANTITY = 307,     // COMPARISON_QUANTITY
    COMPU_METHOD = 308,            // COMPU_METHOD
    COMPU_TAB = 309,               // COMPU_TAB
    COMPU_TAB_REF = 310,           // COMPU_TAB_REF
    COMPU_VTAB = 311,              // COMPU_VTAB
    COMPU_VTAB_RANGE = 312,        // COMPU_VTAB_RANGE
    CONSISTENT_EXCHANGE = 313,     // CONSISTENT_EXCHANGE
    CONVERSION = 314,              // CONVERSION
    CPU_TYPE = 315,                // CPU_TYPE
    CURVE_AXIS_REF = 316,          // CURVE_AXIS_REF
    CUSTOMER = 317,                // CUSTOMER
    CUSTOMER_NO = 318,             // CUSTOMER_NO
    DATA_SIZE = 319,               // DATA_SIZE
    DEF_CHARACTERISTIC = 320,      // DEF_CHARACTERISTIC
    DEFAULT_VALUE = 321,           // DEFAULT_VALUE
    DEFAULT_VALUE_NUMERIC = 322,   // DEFAULT_VALUE_NUMERIC
    DEPENDENT_CHARACTERISTIC = 323, // DEPENDENT_CHARACTERISTIC
    DEPOSIT = 324,                 // DEPOSIT
    DISCRETE = 325,                // DISCRETE
    DISPLAY_IDENTIFIER = 326,      // DISPLAY_IDENTIFIER
    DIST_OP_X = 327,               // DIST_OP_X
    DIST_OP_Y = 328,               // DIST_OP_Y
    DIST_OP_Z = 329,               // DIST_OP_Z
    DIST_OP_4 = 330,               // DIST_OP_4
    DIST_OP_5 = 331,               // DIST_OP_5
    ECU = 332,                     // ECU
    ECU_ADDRESS = 333,             // ECU_ADDRESS
    ECU_ADDRESS_EXTENSION = 334,   // ECU_ADDRESS_EXTENSION
    ECU_CALIBRATION_OFFSET = 335,  // ECU_CALIBRATION_OFFSET
    ENCODING = 336,                // ENCODING
    EPK = 337,                     // EPK
    ERROR_MASK = 338,              // ERROR_MASK
    EXTENDED_LIMITS = 339,         // EXTENDED_LIMITS
    FIX_AXIS_PAR = 340,            // FIX_AXIS_PAR
    FIX_AXIS_PAR_DIST = 341,       // FIX_AXIS_PAR_DIST
    FIX_AXIS_PAR_LIST = 342,       // FIX_AXIS_PAR_LIST
    FIX_NO_AXIS_PTS_X = 343,       // FIX_NO_AXIS_PTS_X
    FIX_NO_AXIS_PTS_Y = 344,       // FIX_NO_AXIS_PTS_Y
    FIX_NO_AXIS_PTS_Z = 345,       // FIX_NO_AXIS_PTS_Z
    FIX_NO_AXIS_PTS_4 = 346,       // FIX_NO_AXIS_PTS_4
    FIX_NO_AXIS_PTS_5 = 347,       // FIX_NO_AXIS_PTS_5
    FNC_VALUES = 348,              // FNC_VALUES
    FORMAT = 349,                  // FORMAT
    FORMULA = 350,                 // FORMULA
    FORMULA_INV = 351,             // FORMULA_INV
    FRAME = 352,                   // FRAME
    FRAME_MEASUREMENT = 353,       // FRAME_MEASUREMENT
    FUNCTION = 354,                // FUNCTION
    FUNCTION_LIST = 355,           // FUNCTION_LIST
    FUNCTION_VERSION = 356,        // FUNCTION_VERSION
    GROUP = 357,                   // GROUP
    GUARD_RAILS = 358,             // GUARD_RAILS
    HEADER = 359,                  // HEADER
    IDENTIFICATION = 360,          // IDENTIFICATION
    IF_DATA = 361,                 // IF_DATA
    IN_MEASUREMENT = 362,          // IN_MEASUREMENT
    INPUT_QUANTITY = 363,          // INPUT_QUANTITY
    INSTANCE = 364,                // INSTANCE
    LAYOUT = 365,                  // LAYOUT
    LEFT_SHIFT = 366,              // LEFT_SHIFT
    LIMITS = 367,                  // LIMITS
    LOC_MEASUREMENT = 368,         // LOC_MEASUREMENT
    MAP_LIST = 369,                // MAP_LIST
    MATRIX_DIM = 370,              // MATRIX_DIM
    MAX_GRAD = 371,                // MAX_GRAD
    MAX_REFRESH = 372,             // MAX_REFRESH
    MEASUREMENT = 373,             // MEASUREMENT
    MEMORY_LAYOUT = 374,           // MEMORY_LAYOUT
    MEMORY_SEGMENT = 375,          // MEMORY_SEGMENT
    MODULE = 376,                  // MODULE
    MOD_COMMON = 377,              // MOD_COMMON
    MOD_PAR = 378,                 // MOD_PAR
    MODEL_LINK = 379,              // MODEL_LINK
    MONOTONY = 380,                // MONOTONY
    NO_AXIS_PTS_X = 381,           // NO_AXIS_PTS_X
    NO_AXIS_PTS_Y = 382,           // NO_AXIS_PTS_Y
    NO_AXIS_PTS_Z = 383,           // NO_AXIS_PTS_Z
    NO_AXIS_PTS_4 = 384,           // NO_AXIS_PTS_4
    NO_AXIS_PTS_5 = 385,           // NO_AXIS_PTS_5
    NO_OF_INTERFACES = 386,        // NO_OF_INTERFACES
    NO_RESCALE_X = 387,            // NO_RESCALE_X
    NUMBER = 388,                  // NUMBER
    OFFSET_X = 389,                // OFFSET_X
    OFFSET_Y = 390,                // OFFSET_Y
    OFFSET_Z = 391,                // OFFSET_Z
    OFFSET_4 = 392,                // OFFSET_4
    OFFSET_5 = 393,                // OFFSET_5
    OUT_MEASUREMENT = 394,         // OUT_MEASUREMENT
    OVERWRITE = 395,               // OVERWRITE
    PHONE_NO = 396,                // PHONE_NO
    PHYS_UNIT = 397,               // PHYS_UNIT
    PROJECT = 398,                 // PROJECT
    PROJECT_NO = 399,              // PROJECT_NO
    READ_ONLY = 400,               // READ_ONLY
    READ_WRITE = 401,              // READ_WRITE
    RECORD_LAYOUT = 402,           // RECORD_LAYOUT
    REF_CHARACTERISTIC = 403,      // REF_CHARACTERISTIC
    REF_GROUP = 404,               // REF_GROUP
    REF_MEASUREMENT = 405,         // REF_MEASUREMENT
    REF_MEMORY_SEGMENT = 406,      // REF_MEMORY_SEGMENT
    REF_UNIT = 407,                // REF_UNIT
    RESERVED = 408,                // RESERVED
    RIGHT_SHIFT = 409,             // RIGHT_SHIFT
    RIP_ADDR_W = 410,              // RIP_ADDR_W
    RIP_ADDR_X = 411,              // RIP_ADDR_X
    RIP_ADDR_Y = 412,              // RIP_ADDR_Y
    RIP_ADDR_Z = 413,              // RIP_ADDR_Z
    RIP_ADDR_4 = 414,              // RIP_ADDR_4
    RIP_ADDR_5 = 415,              // RIP_ADDR_5
    ROOT = 416,                    // ROOT
    S_REC_LAYOUT = 417,            // S_REC_LAYOUT
    SHIFT_OP_X = 418,              // SHIFT_OP_X
    SHIFT_OP_Y = 419,              // SHIFT_OP_Y
    SHIFT_OP_Z = 420,              // SHIFT_OP_Z
    SHIFT_OP_4 = 421,              // SHIFT_OP_4
    SHIFT_OP_5 = 422,              // SHIFT_OP_5
    SIGN_EXTEND = 423,             // SIGN_EXTEND
    SI_EXPONENTS = 424,            // SI_EXPONENTS
    SRC_ADDR_X = 425,              // SRC_ADDR_X
    SRC_ADDR_Y = 426,              // SRC_ADDR_Y
    SRC_ADDR_Z = 427,              // SRC_ADDR_Z
    SRC_ADDR_4 = 428,              // SRC_ADDR_4
    SRC_ADDR_5 = 429,              // SRC_ADDR_5
    STATIC_ADDRESS_OFFSETS = 430,  // STATIC_ADDRESS_OFFSETS
    STATIC_RECORD_LAYOUT = 431,    // STATIC_RECORD_LAYOUT
    STATUS_STRING_REF = 432,       // STATUS_STRING_REF
    STEP_SIZE = 433,               // STEP_SIZE
    STRUCTURE_COMPONENT = 434,     // STRUCTURE_COMPONENT
    SUB_FUNCTION = 435,            // SUB_FUNCTION
    SUB_GROUP = 436,               // SUB_GROUP
    SUPPLIER = 437,                // SUPPLIER
    SYMBOL_LINK = 438,             // SYMBOL_LINK
    SYMBOL_TYPE_LINK = 439,        // SYMBOL_TYPE_LINK
    SYSTEM_CONSTANT = 440,         // SYSTEM_CONSTANT
    TRANSFORMER = 441,             // TRANSFORMER
    TRANSFORMER_IN_OBJECTS = 442,  // TRANSFORMER_IN_OBJECTS
    TRANSFORMER_OUT_OBJECTS = 443, // TRANSFORMER_OUT_OBJECTS
    TYPEDEF_AXIS = 444,            // TYPEDEF_AXIS
    TYPEDEF_BLOB = 445,            // TYPEDEF_BLOB
    TYPEDEF_CHARACTERISTIC = 446,  // TYPEDEF_CHARACTERISTIC
    TYPEDEF_MEASUREMENT = 447,     // TYPEDEF_MEASUREMENT
    TYPEDEF_STRUCTURE = 448,       // TYPEDEF_STRUCTURE
    UNIT = 449,                    // UNIT
    UNIT_CONVERSION = 450,         // UNIT_CONVERSION
    USER = 451,                    // USER
    USER_RIGHTS = 452,             // USER_RIGHTS
    VAR_ADDRESS = 453,             // VAR_ADDRESS
    VAR_CHARACTERISTIC = 454,      // VAR_CHARACTERISTIC
    VAR_CRITERION = 455,           // VAR_CRITERION
    VAR_FORBIDDEN_COMB = 456,      // VAR_FORBIDDEN_COMB
    VAR_MEASUREMENT = 457,         // VAR_MEASUREMENT
    VAR_NAMING = 458,              // VAR_NAMING
    VAR_SELECTION_CHARACTERISTIC = 459, // VAR_SELECTION_CHARACTERISTIC
    VAR_SEPARATOR = 460,           // VAR_SEPARATOR
    VARIANT_CODING = 461,          // VARIANT_CODING
    VIRTUAL = 462,                 // VIRTUAL
    VIRTUAL_CHARACTERISTIC = 463   // VIRTUAL_CHARACTERISTIC
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
        YYNTOKENS = 209, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // EOL
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_A2L_BEGIN = 3,                         // A2L_BEGIN
        S_A2L_END = 4,                           // A2L_END
        S_A2L_INCLUDE = 5,                       // A2L_INCLUDE
        S_IDENT = 6,                             // IDENT
        S_STRING = 7,                            // STRING
        S_INT = 8,                               // INT
        S_UINT = 9,                              // UINT
        S_HEX = 10,                              // HEX
        S_FLOAT = 11,                            // FLOAT
        S_ASAP2_VERSION = 12,                    // ASAP2_VERSION
        S_A2L_VERSION = 13,                      // A2L_VERSION
        S_A2ML_VERSION = 14,                     // A2ML_VERSION
        S_A2ML = 15,                             // A2ML
        S_ADDR_EPK = 16,                         // ADDR_EPK
        S_ADDRESS_TYPE = 17,                     // ADDRESS_TYPE
        S_ALIGNMENT_BYTE = 18,                   // ALIGNMENT_BYTE
        S_ALIGNMENT_FLOAT16_IEEE = 19,           // ALIGNMENT_FLOAT16_IEEE
        S_ALIGNMENT_FLOAT32_IEEE = 20,           // ALIGNMENT_FLOAT32_IEEE
        S_ALIGNMENT_FLOAT64_IEEE = 21,           // ALIGNMENT_FLOAT64_IEEE
        S_ALIGNMENT_INT64 = 22,                  // ALIGNMENT_INT64
        S_ALIGNMENT_LONG = 23,                   // ALIGNMENT_LONG
        S_ALIGNMENT_WORD = 24,                   // ALIGNMENT_WORD
        S_ANNOTATION = 25,                       // ANNOTATION
        S_ANNOTATION_LABEL = 26,                 // ANNOTATION_LABEL
        S_ANNOTATION_ORIGIN = 27,                // ANNOTATION_ORIGIN
        S_ANNOTATION_TEXT = 28,                  // ANNOTATION_TEXT
        S_ARRAY_SIZE = 29,                       // ARRAY_SIZE
        S_AR_COMPONENT = 30,                     // AR_COMPONENT
        S_AR_PROTOTYPE_OF = 31,                  // AR_PROTOTYPE_OF
        S_AXIS_DESCR = 32,                       // AXIS_DESCR
        S_AXIS_PTS = 33,                         // AXIS_PTS
        S_AXIS_PTS_REF = 34,                     // AXIS_PTS_REF
        S_AXIS_PTS_X = 35,                       // AXIS_PTS_X
        S_AXIS_PTS_Y = 36,                       // AXIS_PTS_Y
        S_AXIS_PTS_Z = 37,                       // AXIS_PTS_Z
        S_AXIS_PTS_4 = 38,                       // AXIS_PTS_4
        S_AXIS_PTS_5 = 39,                       // AXIS_PTS_5
        S_AXIS_RESCALE_X = 40,                   // AXIS_RESCALE_X
        S_BIT_MASK = 41,                         // BIT_MASK
        S_BIT_OPERATION = 42,                    // BIT_OPERATION
        S_BLOB = 43,                             // BLOB
        S_A2L_BYTE_ORDER = 44,                   // A2L_BYTE_ORDER
        S_CALIBRATION_ACCESS = 45,               // CALIBRATION_ACCESS
        S_CALIBRATION_HANDLE = 46,               // CALIBRATION_HANDLE
        S_CALIBRATION_HANDLE_TEXT = 47,          // CALIBRATION_HANDLE_TEXT
        S_CALIBRATION_METHOD = 48,               // CALIBRATION_METHOD
        S_CHARACTERISTIC = 49,                   // CHARACTERISTIC
        S_COEFFS = 50,                           // COEFFS
        S_COEFFS_LINEAR = 51,                    // COEFFS_LINEAR
        S_COMPARISON_QUANTITY = 52,              // COMPARISON_QUANTITY
        S_COMPU_METHOD = 53,                     // COMPU_METHOD
        S_COMPU_TAB = 54,                        // COMPU_TAB
        S_COMPU_TAB_REF = 55,                    // COMPU_TAB_REF
        S_COMPU_VTAB = 56,                       // COMPU_VTAB
        S_COMPU_VTAB_RANGE = 57,                 // COMPU_VTAB_RANGE
        S_CONSISTENT_EXCHANGE = 58,              // CONSISTENT_EXCHANGE
        S_CONVERSION = 59,                       // CONVERSION
        S_CPU_TYPE = 60,                         // CPU_TYPE
        S_CURVE_AXIS_REF = 61,                   // CURVE_AXIS_REF
        S_CUSTOMER = 62,                         // CUSTOMER
        S_CUSTOMER_NO = 63,                      // CUSTOMER_NO
        S_DATA_SIZE = 64,                        // DATA_SIZE
        S_DEF_CHARACTERISTIC = 65,               // DEF_CHARACTERISTIC
        S_DEFAULT_VALUE = 66,                    // DEFAULT_VALUE
        S_DEFAULT_VALUE_NUMERIC = 67,            // DEFAULT_VALUE_NUMERIC
        S_DEPENDENT_CHARACTERISTIC = 68,         // DEPENDENT_CHARACTERISTIC
        S_DEPOSIT = 69,                          // DEPOSIT
        S_DISCRETE = 70,                         // DISCRETE
        S_DISPLAY_IDENTIFIER = 71,               // DISPLAY_IDENTIFIER
        S_DIST_OP_X = 72,                        // DIST_OP_X
        S_DIST_OP_Y = 73,                        // DIST_OP_Y
        S_DIST_OP_Z = 74,                        // DIST_OP_Z
        S_DIST_OP_4 = 75,                        // DIST_OP_4
        S_DIST_OP_5 = 76,                        // DIST_OP_5
        S_ECU = 77,                              // ECU
        S_ECU_ADDRESS = 78,                      // ECU_ADDRESS
        S_ECU_ADDRESS_EXTENSION = 79,            // ECU_ADDRESS_EXTENSION
        S_ECU_CALIBRATION_OFFSET = 80,           // ECU_CALIBRATION_OFFSET
        S_ENCODING = 81,                         // ENCODING
        S_EPK = 82,                              // EPK
        S_ERROR_MASK = 83,                       // ERROR_MASK
        S_EXTENDED_LIMITS = 84,                  // EXTENDED_LIMITS
        S_FIX_AXIS_PAR = 85,                     // FIX_AXIS_PAR
        S_FIX_AXIS_PAR_DIST = 86,                // FIX_AXIS_PAR_DIST
        S_FIX_AXIS_PAR_LIST = 87,                // FIX_AXIS_PAR_LIST
        S_FIX_NO_AXIS_PTS_X = 88,                // FIX_NO_AXIS_PTS_X
        S_FIX_NO_AXIS_PTS_Y = 89,                // FIX_NO_AXIS_PTS_Y
        S_FIX_NO_AXIS_PTS_Z = 90,                // FIX_NO_AXIS_PTS_Z
        S_FIX_NO_AXIS_PTS_4 = 91,                // FIX_NO_AXIS_PTS_4
        S_FIX_NO_AXIS_PTS_5 = 92,                // FIX_NO_AXIS_PTS_5
        S_FNC_VALUES = 93,                       // FNC_VALUES
        S_FORMAT = 94,                           // FORMAT
        S_FORMULA = 95,                          // FORMULA
        S_FORMULA_INV = 96,                      // FORMULA_INV
        S_FRAME = 97,                            // FRAME
        S_FRAME_MEASUREMENT = 98,                // FRAME_MEASUREMENT
        S_FUNCTION = 99,                         // FUNCTION
        S_FUNCTION_LIST = 100,                   // FUNCTION_LIST
        S_FUNCTION_VERSION = 101,                // FUNCTION_VERSION
        S_GROUP = 102,                           // GROUP
        S_GUARD_RAILS = 103,                     // GUARD_RAILS
        S_HEADER = 104,                          // HEADER
        S_IDENTIFICATION = 105,                  // IDENTIFICATION
        S_IF_DATA = 106,                         // IF_DATA
        S_IN_MEASUREMENT = 107,                  // IN_MEASUREMENT
        S_INPUT_QUANTITY = 108,                  // INPUT_QUANTITY
        S_INSTANCE = 109,                        // INSTANCE
        S_LAYOUT = 110,                          // LAYOUT
        S_LEFT_SHIFT = 111,                      // LEFT_SHIFT
        S_LIMITS = 112,                          // LIMITS
        S_LOC_MEASUREMENT = 113,                 // LOC_MEASUREMENT
        S_MAP_LIST = 114,                        // MAP_LIST
        S_MATRIX_DIM = 115,                      // MATRIX_DIM
        S_MAX_GRAD = 116,                        // MAX_GRAD
        S_MAX_REFRESH = 117,                     // MAX_REFRESH
        S_MEASUREMENT = 118,                     // MEASUREMENT
        S_MEMORY_LAYOUT = 119,                   // MEMORY_LAYOUT
        S_MEMORY_SEGMENT = 120,                  // MEMORY_SEGMENT
        S_MODULE = 121,                          // MODULE
        S_MOD_COMMON = 122,                      // MOD_COMMON
        S_MOD_PAR = 123,                         // MOD_PAR
        S_MODEL_LINK = 124,                      // MODEL_LINK
        S_MONOTONY = 125,                        // MONOTONY
        S_NO_AXIS_PTS_X = 126,                   // NO_AXIS_PTS_X
        S_NO_AXIS_PTS_Y = 127,                   // NO_AXIS_PTS_Y
        S_NO_AXIS_PTS_Z = 128,                   // NO_AXIS_PTS_Z
        S_NO_AXIS_PTS_4 = 129,                   // NO_AXIS_PTS_4
        S_NO_AXIS_PTS_5 = 130,                   // NO_AXIS_PTS_5
        S_NO_OF_INTERFACES = 131,                // NO_OF_INTERFACES
        S_NO_RESCALE_X = 132,                    // NO_RESCALE_X
        S_NUMBER = 133,                          // NUMBER
        S_OFFSET_X = 134,                        // OFFSET_X
        S_OFFSET_Y = 135,                        // OFFSET_Y
        S_OFFSET_Z = 136,                        // OFFSET_Z
        S_OFFSET_4 = 137,                        // OFFSET_4
        S_OFFSET_5 = 138,                        // OFFSET_5
        S_OUT_MEASUREMENT = 139,                 // OUT_MEASUREMENT
        S_OVERWRITE = 140,                       // OVERWRITE
        S_PHONE_NO = 141,                        // PHONE_NO
        S_PHYS_UNIT = 142,                       // PHYS_UNIT
        S_PROJECT = 143,                         // PROJECT
        S_PROJECT_NO = 144,                      // PROJECT_NO
        S_READ_ONLY = 145,                       // READ_ONLY
        S_READ_WRITE = 146,                      // READ_WRITE
        S_RECORD_LAYOUT = 147,                   // RECORD_LAYOUT
        S_REF_CHARACTERISTIC = 148,              // REF_CHARACTERISTIC
        S_REF_GROUP = 149,                       // REF_GROUP
        S_REF_MEASUREMENT = 150,                 // REF_MEASUREMENT
        S_REF_MEMORY_SEGMENT = 151,              // REF_MEMORY_SEGMENT
        S_REF_UNIT = 152,                        // REF_UNIT
        S_RESERVED = 153,                        // RESERVED
        S_RIGHT_SHIFT = 154,                     // RIGHT_SHIFT
        S_RIP_ADDR_W = 155,                      // RIP_ADDR_W
        S_RIP_ADDR_X = 156,                      // RIP_ADDR_X
        S_RIP_ADDR_Y = 157,                      // RIP_ADDR_Y
        S_RIP_ADDR_Z = 158,                      // RIP_ADDR_Z
        S_RIP_ADDR_4 = 159,                      // RIP_ADDR_4
        S_RIP_ADDR_5 = 160,                      // RIP_ADDR_5
        S_ROOT = 161,                            // ROOT
        S_S_REC_LAYOUT = 162,                    // S_REC_LAYOUT
        S_SHIFT_OP_X = 163,                      // SHIFT_OP_X
        S_SHIFT_OP_Y = 164,                      // SHIFT_OP_Y
        S_SHIFT_OP_Z = 165,                      // SHIFT_OP_Z
        S_SHIFT_OP_4 = 166,                      // SHIFT_OP_4
        S_SHIFT_OP_5 = 167,                      // SHIFT_OP_5
        S_SIGN_EXTEND = 168,                     // SIGN_EXTEND
        S_SI_EXPONENTS = 169,                    // SI_EXPONENTS
        S_SRC_ADDR_X = 170,                      // SRC_ADDR_X
        S_SRC_ADDR_Y = 171,                      // SRC_ADDR_Y
        S_SRC_ADDR_Z = 172,                      // SRC_ADDR_Z
        S_SRC_ADDR_4 = 173,                      // SRC_ADDR_4
        S_SRC_ADDR_5 = 174,                      // SRC_ADDR_5
        S_STATIC_ADDRESS_OFFSETS = 175,          // STATIC_ADDRESS_OFFSETS
        S_STATIC_RECORD_LAYOUT = 176,            // STATIC_RECORD_LAYOUT
        S_STATUS_STRING_REF = 177,               // STATUS_STRING_REF
        S_STEP_SIZE = 178,                       // STEP_SIZE
        S_STRUCTURE_COMPONENT = 179,             // STRUCTURE_COMPONENT
        S_SUB_FUNCTION = 180,                    // SUB_FUNCTION
        S_SUB_GROUP = 181,                       // SUB_GROUP
        S_SUPPLIER = 182,                        // SUPPLIER
        S_SYMBOL_LINK = 183,                     // SYMBOL_LINK
        S_SYMBOL_TYPE_LINK = 184,                // SYMBOL_TYPE_LINK
        S_SYSTEM_CONSTANT = 185,                 // SYSTEM_CONSTANT
        S_TRANSFORMER = 186,                     // TRANSFORMER
        S_TRANSFORMER_IN_OBJECTS = 187,          // TRANSFORMER_IN_OBJECTS
        S_TRANSFORMER_OUT_OBJECTS = 188,         // TRANSFORMER_OUT_OBJECTS
        S_TYPEDEF_AXIS = 189,                    // TYPEDEF_AXIS
        S_TYPEDEF_BLOB = 190,                    // TYPEDEF_BLOB
        S_TYPEDEF_CHARACTERISTIC = 191,          // TYPEDEF_CHARACTERISTIC
        S_TYPEDEF_MEASUREMENT = 192,             // TYPEDEF_MEASUREMENT
        S_TYPEDEF_STRUCTURE = 193,               // TYPEDEF_STRUCTURE
        S_UNIT = 194,                            // UNIT
        S_UNIT_CONVERSION = 195,                 // UNIT_CONVERSION
        S_USER = 196,                            // USER
        S_USER_RIGHTS = 197,                     // USER_RIGHTS
        S_VAR_ADDRESS = 198,                     // VAR_ADDRESS
        S_VAR_CHARACTERISTIC = 199,              // VAR_CHARACTERISTIC
        S_VAR_CRITERION = 200,                   // VAR_CRITERION
        S_VAR_FORBIDDEN_COMB = 201,              // VAR_FORBIDDEN_COMB
        S_VAR_MEASUREMENT = 202,                 // VAR_MEASUREMENT
        S_VAR_NAMING = 203,                      // VAR_NAMING
        S_VAR_SELECTION_CHARACTERISTIC = 204,    // VAR_SELECTION_CHARACTERISTIC
        S_VAR_SEPARATOR = 205,                   // VAR_SEPARATOR
        S_VARIANT_CODING = 206,                  // VARIANT_CODING
        S_VIRTUAL = 207,                         // VIRTUAL
        S_VIRTUAL_CHARACTERISTIC = 208,          // VIRTUAL_CHARACTERISTIC
        S_YYACCEPT = 209,                        // $accept
        S_any_uint = 210,                        // any_uint
        S_any_int = 211,                         // any_int
        S_any_float = 212,                       // any_float
        S_int_list = 213,                        // int_list
        S_uint_list = 214,                       // uint_list
        S_float_list = 215,                      // float_list
        S_float_pair_list = 216,                 // float_pair_list
        S_float_string_list = 217,               // float_string_list
        S_float_range_list = 218,                // float_range_list
        S_string_list = 219,                     // string_list
        S_ident_list = 220,                      // ident_list
        S_key_value_list = 221,                  // key_value_list
        S_a2l_file = 222,                        // a2l_file
        S_file_version = 223,                    // file_version
        S_annotation = 224,                      // annotation
        S_annotation_attributes = 225,           // annotation_attributes
        S_annotation_text = 226,                 // annotation_text
        S_ar_component = 227,                    // ar_component
        S_ar_component_attribute = 228,          // ar_component_attribute
        S_axis_descr = 229,                      // axis_descr
        S_axis_descr_attributes = 230,           // axis_descr_attributes
        S_axis_descr_attribute = 231,            // axis_descr_attribute
        S_axis_pts = 232,                        // axis_pts
        S_axis_pts_attributes = 233,             // axis_pts_attributes
        S_axis_pts_attribute = 234,              // axis_pts_attribute
        S_bit_operation = 235,                   // bit_operation
        S_bit_operation_attributes = 236,        // bit_operation_attributes
        S_bit_operation_attribute = 237,         // bit_operation_attribute
        S_blob = 238,                            // blob
        S_blob_attributes = 239,                 // blob_attributes
        S_blob_attribute = 240,                  // blob_attribute
        S_calibration_handle = 241,              // calibration_handle
        S_calibration_handle_attribute = 242,    // calibration_handle_attribute
        S_calibration_method = 243,              // calibration_method
        S_calibration_method_attributes = 244,   // calibration_method_attributes
        S_characteristic = 245,                  // characteristic
        S_characteristic_attributes = 246,       // characteristic_attributes
        S_characteristic_attribute = 247,        // characteristic_attribute
        S_compu_method = 248,                    // compu_method
        S_compu_method_attributes = 249,         // compu_method_attributes
        S_compu_method_attribute = 250,          // compu_method_attribute
        S_compu_tab = 251,                       // compu_tab
        S_compu_tab_attributes = 252,            // compu_tab_attributes
        S_compu_tab_attribute = 253,             // compu_tab_attribute
        S_compu_vtab = 254,                      // compu_vtab
        S_compu_vtab_attributes = 255,           // compu_vtab_attributes
        S_compu_vtab_attribute = 256,            // compu_vtab_attribute
        S_compu_vtab_range = 257,                // compu_vtab_range
        S_compu_vtab_range_attributes = 258,     // compu_vtab_range_attributes
        S_compu_vtab_range_attribute = 259,      // compu_vtab_range_attribute
        S_def_characteristic = 260,              // def_characteristic
        S_dependent_characteristic = 261,        // dependent_characteristic
        S_fix_axis_par_list = 262,               // fix_axis_par_list
        S_formula = 263,                         // formula
        S_formula_attribute = 264,               // formula_attribute
        S_frame = 265,                           // frame
        S_frame_attributes = 266,                // frame_attributes
        S_frame_attribute = 267,                 // frame_attribute
        S_function = 268,                        // function
        S_function_attributes = 269,             // function_attributes
        S_function_attribute = 270,              // function_attribute
        S_function_list = 271,                   // function_list
        S_group = 272,                           // group
        S_group_attributes = 273,                // group_attributes
        S_group_attribute = 274,                 // group_attribute
        S_header = 275,                          // header
        S_header_attributes = 276,               // header_attributes
        S_header_attribute = 277,                // header_attribute
        S_in_measurement = 278,                  // in_measurement
        S_instance = 279,                        // instance
        S_instance_attributes = 280,             // instance_attributes
        S_instance_attribute = 281,              // instance_attribute
        S_loc_measurement = 282,                 // loc_measurement
        S_map_list = 283,                        // map_list
        S_measurement = 284,                     // measurement
        S_measurement_attributes = 285,          // measurement_attributes
        S_measurement_attribute = 286,           // measurement_attribute
        S_memory_layout = 287,                   // memory_layout
        S_memory_layout_attributes = 288,        // memory_layout_attributes
        S_prg_type = 289,                        // prg_type
        S_memory_segment = 290,                  // memory_segment
        S_memory_segment_attributes = 291,       // memory_segment_attributes
        S_mod_common = 292,                      // mod_common
        S_mod_common_attributes = 293,           // mod_common_attributes
        S_mod_common_attribute = 294,            // mod_common_attribute
        S_mod_par = 295,                         // mod_par
        S_mod_par_attributes = 296,              // mod_par_attributes
        S_mod_par_attribute = 297,               // mod_par_attribute
        S_module = 298,                          // module
        S_module_attributes = 299,               // module_attributes
        S_module_attribute = 300,                // module_attribute
        S_out_measurement = 301,                 // out_measurement
        S_overwrite = 302,                       // overwrite
        S_overwrite_attributes = 303,            // overwrite_attributes
        S_overwrite_attribute = 304,             // overwrite_attribute
        S_project = 305,                         // project
        S_project_attributes = 306,              // project_attributes
        S_project_attribute = 307,               // project_attribute
        S_record_layout = 308,                   // record_layout
        S_record_layout_attributes = 309,        // record_layout_attributes
        S_record_layout_attribute = 310,         // record_layout_attribute
        S_ref_characteristic = 311,              // ref_characteristic
        S_ref_group = 312,                       // ref_group
        S_ref_measurement = 313,                 // ref_measurement
        S_structure_component = 314,             // structure_component
        S_structure_component_attributes = 315,  // structure_component_attributes
        S_structure_component_attribute = 316,   // structure_component_attribute
        S_sub_function = 317,                    // sub_function
        S_sub_group = 318,                       // sub_group
        S_transformer = 319,                     // transformer
        S_transformer_attributes = 320,          // transformer_attributes
        S_transformer_attribute = 321,           // transformer_attribute
        S_transformer_in_objects = 322,          // transformer_in_objects
        S_transformer_out_objects = 323,         // transformer_out_objects
        S_typedef_axis = 324,                    // typedef_axis
        S_typedef_axis_attributes = 325,         // typedef_axis_attributes
        S_typedef_axis_attribute = 326,          // typedef_axis_attribute
        S_typedef_blob = 327,                    // typedef_blob
        S_typedef_blob_attributes = 328,         // typedef_blob_attributes
        S_typedef_blob_attribute = 329,          // typedef_blob_attribute
        S_typedef_characteristic = 330,          // typedef_characteristic
        S_typedef_characteristic_attributes = 331, // typedef_characteristic_attributes
        S_typedef_characteristic_attribute = 332, // typedef_characteristic_attribute
        S_typedef_measurement = 333,             // typedef_measurement
        S_typedef_measurement_attributes = 334,  // typedef_measurement_attributes
        S_typedef_measurement_attribute = 335,   // typedef_measurement_attribute
        S_typedef_structure = 336,               // typedef_structure
        S_typedef_structure_attributes = 337,    // typedef_structure_attributes
        S_typedef_structure_attribute = 338,     // typedef_structure_attribute
        S_unit = 339,                            // unit
        S_unit_attributes = 340,                 // unit_attributes
        S_unit_attribute = 341,                  // unit_attribute
        S_user_rights = 342,                     // user_rights
        S_user_rights_attributes = 343,          // user_rights_attributes
        S_user_rights_attribute = 344,           // user_rights_attribute
        S_var_address = 345,                     // var_address
        S_var_characteristic = 346,              // var_characteristic
        S_var_characteristic_attribute = 347,    // var_characteristic_attribute
        S_var_criterion = 348,                   // var_criterion
        S_var_criterion_attributes = 349,        // var_criterion_attributes
        S_var_criterion_attribute = 350,         // var_criterion_attribute
        S_var_forbidden_comb = 351,              // var_forbidden_comb
        S_variant_coding = 352,                  // variant_coding
        S_variant_coding_attributes = 353,       // variant_coding_attributes
        S_variant_coding_attribute = 354,        // variant_coding_attribute
        S_virtual = 355,                         // virtual
        S_virtual_characteristic = 356,          // virtual_characteristic
        S_a2ml = 357,                            // a2ml
        S_a2ml_version = 358,                    // a2ml_version
        S_asap2_version = 359,                   // asap2_version
        S_addr_epk = 360,                        // addr_epk
        S_address_type = 361,                    // address_type
        S_alignment_byte = 362,                  // alignment_byte
        S_alignment_float16_ieee = 363,          // alignment_float16_ieee
        S_alignment_float32_ieee = 364,          // alignment_float32_ieee
        S_alignment_float64_ieee = 365,          // alignment_float64_ieee
        S_alignment_int64 = 366,                 // alignment_int64
        S_alignment_long = 367,                  // alignment_long
        S_alignment_word = 368,                  // alignment_word
        S_annotation_label = 369,                // annotation_label
        S_annotation_origin = 370,               // annotation_origin
        S_array_size = 371,                      // array_size
        S_ar_prototype_of = 372,                 // ar_prototype_of
        S_axis_pts_ref = 373,                    // axis_pts_ref
        S_axis_pts_x = 374,                      // axis_pts_x
        S_axis_pts_y = 375,                      // axis_pts_y
        S_axis_pts_z = 376,                      // axis_pts_z
        S_axis_pts_4 = 377,                      // axis_pts_4
        S_axis_pts_5 = 378,                      // axis_pts_5
        S_axis_rescale_x = 379,                  // axis_rescale_x
        S_bit_mask = 380,                        // bit_mask
        S_byte_order = 381,                      // byte_order
        S_calibration_access = 382,              // calibration_access
        S_calibration_handle_text = 383,         // calibration_handle_text
        S_coeffs = 384,                          // coeffs
        S_coeffs_linear = 385,                   // coeffs_linear
        S_comparison_quantity = 386,             // comparison_quantity
        S_compu_tab_ref = 387,                   // compu_tab_ref
        S_consistent_exchange = 388,             // consistent_exchange
        S_conversion = 389,                      // conversion
        S_cpu_type = 390,                        // cpu_type
        S_curve_axis_ref = 391,                  // curve_axis_ref
        S_customer = 392,                        // customer
        S_customer_no = 393,                     // customer_no
        S_data_size = 394,                       // data_size
        S_default_value = 395,                   // default_value
        S_default_value_numeric = 396,           // default_value_numeric
        S_deposit = 397,                         // deposit
        S_discrete = 398,                        // discrete
        S_display_identifier = 399,              // display_identifier
        S_dist_op_x = 400,                       // dist_op_x
        S_dist_op_y = 401,                       // dist_op_y
        S_dist_op_z = 402,                       // dist_op_z
        S_dist_op_4 = 403,                       // dist_op_4
        S_dist_op_5 = 404,                       // dist_op_5
        S_ecu = 405,                             // ecu
        S_ecu_address = 406,                     // ecu_address
        S_ecu_address_extension = 407,           // ecu_address_extension
        S_ecu_calibration_offset = 408,          // ecu_calibration_offset
        S_encoding = 409,                        // encoding
        S_epk = 410,                             // epk
        S_error_mask = 411,                      // error_mask
        S_extended_limits = 412,                 // extended_limits
        S_fix_axis_par = 413,                    // fix_axis_par
        S_fix_axis_par_dist = 414,               // fix_axis_par_dist
        S_fix_no_axis_pts_x = 415,               // fix_no_axis_pts_x
        S_fix_no_axis_pts_y = 416,               // fix_no_axis_pts_y
        S_fix_no_axis_pts_z = 417,               // fix_no_axis_pts_z
        S_fix_no_axis_pts_4 = 418,               // fix_no_axis_pts_4
        S_fix_no_axis_pts_5 = 419,               // fix_no_axis_pts_5
        S_fnc_values = 420,                      // fnc_values
        S_format = 421,                          // format
        S_formula_inv = 422,                     // formula_inv
        S_frame_measurement = 423,               // frame_measurement
        S_function_version = 424,                // function_version
        S_guard_rails = 425,                     // guard_rails
        S_identification = 426,                  // identification
        S_if_data = 427,                         // if_data
        S_input_quantity = 428,                  // input_quantity
        S_layout = 429,                          // layout
        S_left_shift = 430,                      // left_shift
        S_limits = 431,                          // limits
        S_matrix_dim = 432,                      // matrix_dim
        S_max_grad = 433,                        // max_grad
        S_max_refresh = 434,                     // max_refresh
        S_model_link = 435,                      // model_link
        S_monotony = 436,                        // monotony
        S_no_axis_pts_x = 437,                   // no_axis_pts_x
        S_no_axis_pts_y = 438,                   // no_axis_pts_y
        S_no_axis_pts_z = 439,                   // no_axis_pts_z
        S_no_axis_pts_4 = 440,                   // no_axis_pts_4
        S_no_axis_pts_5 = 441,                   // no_axis_pts_5
        S_no_of_interfaces = 442,                // no_of_interfaces
        S_no_rescale_x = 443,                    // no_rescale_x
        S_number = 444,                          // number
        S_offset_x = 445,                        // offset_x
        S_offset_y = 446,                        // offset_y
        S_offset_z = 447,                        // offset_z
        S_offset_4 = 448,                        // offset_4
        S_offset_5 = 449,                        // offset_5
        S_phone_no = 450,                        // phone_no
        S_phys_unit = 451,                       // phys_unit
        S_proj_no = 452,                         // proj_no
        S_project_no = 453,                      // project_no
        S_read_only = 454,                       // read_only
        S_read_write = 455,                      // read_write
        S_ref_memory_segment = 456,              // ref_memory_segment
        S_ref_unit = 457,                        // ref_unit
        S_reserved = 458,                        // reserved
        S_right_shift = 459,                     // right_shift
        S_rip_addr_w = 460,                      // rip_addr_w
        S_rip_addr_x = 461,                      // rip_addr_x
        S_rip_addr_y = 462,                      // rip_addr_y
        S_rip_addr_z = 463,                      // rip_addr_z
        S_rip_addr_4 = 464,                      // rip_addr_4
        S_rip_addr_5 = 465,                      // rip_addr_5
        S_root = 466,                            // root
        S_s_rec_layout = 467,                    // s_rec_layout
        S_shift_op_x = 468,                      // shift_op_x
        S_shift_op_y = 469,                      // shift_op_y
        S_shift_op_z = 470,                      // shift_op_z
        S_shift_op_4 = 471,                      // shift_op_4
        S_shift_op_5 = 472,                      // shift_op_5
        S_sign_extend = 473,                     // sign_extend
        S_si_exponents = 474,                    // si_exponents
        S_src_addr_x = 475,                      // src_addr_x
        S_src_addr_y = 476,                      // src_addr_y
        S_src_addr_z = 477,                      // src_addr_z
        S_src_addr_4 = 478,                      // src_addr_4
        S_src_addr_5 = 479,                      // src_addr_5
        S_static_address_offsets = 480,          // static_address_offsets
        S_static_record_layout = 481,            // static_record_layout
        S_status_string_ref = 482,               // status_string_ref
        S_step_size = 483,                       // step_size
        S_supplier = 484,                        // supplier
        S_symbol_link = 485,                     // symbol_link
        S_symbol_type_link = 486,                // symbol_type_link
        S_system_constant = 487,                 // system_constant
        S_unit_conversion = 488,                 // unit_conversion
        S_user = 489,                            // user
        S_var_measurement = 490,                 // var_measurement
        S_var_naming = 491,                      // var_naming
        S_var_selection_characteristic = 492,    // var_selection_characteristic
        S_var_separator = 493,                   // var_separator
        S_version = 494                          // version
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
      case symbol_kind::S_address_type: // address_type
        value.move< A2lAddressType > (std::move (that.value));
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.move< A2lAnnotation > (std::move (that.value));
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.move< A2lAxisPts > (std::move (that.value));
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.move< A2lAxisRescale > (std::move (that.value));
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.move< A2lBitOperation > (std::move (that.value));
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.move< A2lByteOrder > (std::move (that.value));
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.move< A2lCalibrationAccess > (std::move (that.value));
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.move< A2lCalibrationHandle > (std::move (that.value));
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.move< A2lCalibrationMethod > (std::move (that.value));
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.move< A2lDependentCharacteristic > (std::move (that.value));
        break;

      case symbol_kind::S_deposit: // deposit
        value.move< A2lDeposit > (std::move (that.value));
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.move< A2lDistOp > (std::move (that.value));
        break;

      case symbol_kind::S_encoding: // encoding
        value.move< A2lEncoding > (std::move (that.value));
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.move< A2lExtendedLimits > (std::move (that.value));
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.move< A2lFixAxisPar > (std::move (that.value));
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.move< A2lFixAxisParDist > (std::move (that.value));
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.move< A2lFncValue > (std::move (that.value));
        break;

      case symbol_kind::S_identification: // identification
        value.move< A2lIdentification > (std::move (that.value));
        break;

      case symbol_kind::S_layout: // layout
        value.move< A2lLayout > (std::move (that.value));
        break;

      case symbol_kind::S_limits: // limits
        value.move< A2lLimits > (std::move (that.value));
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.move< A2lMaxRefresh > (std::move (that.value));
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.move< A2lMemoryLayout > (std::move (that.value));
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.move< A2lMemorySegment > (std::move (that.value));
        break;

      case symbol_kind::S_monotony: // monotony
        value.move< A2lMonotony > (std::move (that.value));
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.move< A2lSegmentType > (std::move (that.value));
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.move< A2lSiExponents > (std::move (that.value));
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.move< A2lSymbolLink > (std::move (that.value));
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.move< A2lVarCharacteristic > (std::move (that.value));
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.move< A2lVarCriterion > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.move< int64_t > (std::move (that.value));
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.move< std::map<double, double> > (std::move (that.value));
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.move< std::map<double, std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.move< std::map<std::pair<double, double>, std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.move< std::map<std::string, std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.move< std::pair<double,double> > (std::move (that.value));
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.move< std::pair<std::string,std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.move< std::vector<A2lCalibrationHandle> > (std::move (that.value));
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.move< std::vector<double> > (std::move (that.value));
        break;

      case symbol_kind::S_int_list: // int_list
        value.move< std::vector<int64_t> > (std::move (that.value));
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.move< std::vector<std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.move< std::vector<uint64_t> > (std::move (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
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
      basic_symbol (typename Base::kind_type t, A2lAddressType&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lAddressType& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lAnnotation&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lAnnotation& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lAxisPts&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lAxisPts& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lAxisRescale&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lAxisRescale& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lBitOperation&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lBitOperation& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lByteOrder&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lByteOrder& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lCalibrationAccess&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lCalibrationAccess& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lCalibrationHandle&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lCalibrationHandle& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lCalibrationMethod&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lCalibrationMethod& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lDependentCharacteristic&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lDependentCharacteristic& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lDeposit&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lDeposit& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lDistOp&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lDistOp& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lEncoding&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lEncoding& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lExtendedLimits&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lExtendedLimits& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lFixAxisPar&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lFixAxisPar& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lFixAxisParDist&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lFixAxisParDist& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lFncValue&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lFncValue& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lIdentification&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lIdentification& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lLayout&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lLayout& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lLimits&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lLimits& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lMaxRefresh&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lMaxRefresh& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lMemoryLayout&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lMemoryLayout& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lMemorySegment&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lMemorySegment& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lMonotony&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lMonotony& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lSegmentType&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lSegmentType& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lSiExponents&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lSiExponents& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lSymbolLink&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lSymbolLink& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lVarCharacteristic&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lVarCharacteristic& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, A2lVarCriterion&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const A2lVarCriterion& v)
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
      basic_symbol (typename Base::kind_type t, std::map<double, double>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::map<double, double>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::map<double, std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::map<double, std::string>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::map<std::pair<double, double>, std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::map<std::pair<double, double>, std::string>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::map<std::string, std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::map<std::string, std::string>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<double,double>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<double,double>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<std::string,std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<std::string,std::string>& v)
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
      basic_symbol (typename Base::kind_type t, std::vector<A2lCalibrationHandle>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<A2lCalibrationHandle>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<double>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<double>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<int64_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<int64_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::string>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<uint64_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<uint64_t>& v)
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
      case symbol_kind::S_address_type: // address_type
        value.template destroy< A2lAddressType > ();
        break;

      case symbol_kind::S_annotation: // annotation
      case symbol_kind::S_annotation_attributes: // annotation_attributes
        value.template destroy< A2lAnnotation > ();
        break;

      case symbol_kind::S_axis_pts_x: // axis_pts_x
      case symbol_kind::S_axis_pts_y: // axis_pts_y
      case symbol_kind::S_axis_pts_z: // axis_pts_z
      case symbol_kind::S_axis_pts_4: // axis_pts_4
      case symbol_kind::S_axis_pts_5: // axis_pts_5
        value.template destroy< A2lAxisPts > ();
        break;

      case symbol_kind::S_axis_rescale_x: // axis_rescale_x
        value.template destroy< A2lAxisRescale > ();
        break;

      case symbol_kind::S_bit_operation: // bit_operation
        value.template destroy< A2lBitOperation > ();
        break;

      case symbol_kind::S_byte_order: // byte_order
        value.template destroy< A2lByteOrder > ();
        break;

      case symbol_kind::S_calibration_access: // calibration_access
        value.template destroy< A2lCalibrationAccess > ();
        break;

      case symbol_kind::S_calibration_handle: // calibration_handle
        value.template destroy< A2lCalibrationHandle > ();
        break;

      case symbol_kind::S_calibration_method: // calibration_method
        value.template destroy< A2lCalibrationMethod > ();
        break;

      case symbol_kind::S_dependent_characteristic: // dependent_characteristic
      case symbol_kind::S_virtual_characteristic: // virtual_characteristic
        value.template destroy< A2lDependentCharacteristic > ();
        break;

      case symbol_kind::S_deposit: // deposit
        value.template destroy< A2lDeposit > ();
        break;

      case symbol_kind::S_dist_op_x: // dist_op_x
      case symbol_kind::S_dist_op_y: // dist_op_y
      case symbol_kind::S_dist_op_z: // dist_op_z
      case symbol_kind::S_dist_op_4: // dist_op_4
      case symbol_kind::S_dist_op_5: // dist_op_5
      case symbol_kind::S_no_axis_pts_x: // no_axis_pts_x
      case symbol_kind::S_no_axis_pts_y: // no_axis_pts_y
      case symbol_kind::S_no_axis_pts_z: // no_axis_pts_z
      case symbol_kind::S_no_axis_pts_4: // no_axis_pts_4
      case symbol_kind::S_no_axis_pts_5: // no_axis_pts_5
      case symbol_kind::S_no_rescale_x: // no_rescale_x
      case symbol_kind::S_offset_x: // offset_x
      case symbol_kind::S_offset_y: // offset_y
      case symbol_kind::S_offset_z: // offset_z
      case symbol_kind::S_offset_4: // offset_4
      case symbol_kind::S_offset_5: // offset_5
      case symbol_kind::S_reserved: // reserved
      case symbol_kind::S_rip_addr_w: // rip_addr_w
      case symbol_kind::S_rip_addr_x: // rip_addr_x
      case symbol_kind::S_rip_addr_y: // rip_addr_y
      case symbol_kind::S_rip_addr_z: // rip_addr_z
      case symbol_kind::S_rip_addr_4: // rip_addr_4
      case symbol_kind::S_rip_addr_5: // rip_addr_5
      case symbol_kind::S_shift_op_x: // shift_op_x
      case symbol_kind::S_shift_op_y: // shift_op_y
      case symbol_kind::S_shift_op_z: // shift_op_z
      case symbol_kind::S_shift_op_4: // shift_op_4
      case symbol_kind::S_shift_op_5: // shift_op_5
      case symbol_kind::S_src_addr_x: // src_addr_x
      case symbol_kind::S_src_addr_y: // src_addr_y
      case symbol_kind::S_src_addr_z: // src_addr_z
      case symbol_kind::S_src_addr_4: // src_addr_4
      case symbol_kind::S_src_addr_5: // src_addr_5
        value.template destroy< A2lDistOp > ();
        break;

      case symbol_kind::S_encoding: // encoding
        value.template destroy< A2lEncoding > ();
        break;

      case symbol_kind::S_extended_limits: // extended_limits
        value.template destroy< A2lExtendedLimits > ();
        break;

      case symbol_kind::S_fix_axis_par: // fix_axis_par
        value.template destroy< A2lFixAxisPar > ();
        break;

      case symbol_kind::S_fix_axis_par_dist: // fix_axis_par_dist
        value.template destroy< A2lFixAxisParDist > ();
        break;

      case symbol_kind::S_fnc_values: // fnc_values
        value.template destroy< A2lFncValue > ();
        break;

      case symbol_kind::S_identification: // identification
        value.template destroy< A2lIdentification > ();
        break;

      case symbol_kind::S_layout: // layout
        value.template destroy< A2lLayout > ();
        break;

      case symbol_kind::S_limits: // limits
        value.template destroy< A2lLimits > ();
        break;

      case symbol_kind::S_max_refresh: // max_refresh
        value.template destroy< A2lMaxRefresh > ();
        break;

      case symbol_kind::S_memory_layout: // memory_layout
        value.template destroy< A2lMemoryLayout > ();
        break;

      case symbol_kind::S_memory_segment: // memory_segment
        value.template destroy< A2lMemorySegment > ();
        break;

      case symbol_kind::S_monotony: // monotony
        value.template destroy< A2lMonotony > ();
        break;

      case symbol_kind::S_prg_type: // prg_type
        value.template destroy< A2lSegmentType > ();
        break;

      case symbol_kind::S_si_exponents: // si_exponents
        value.template destroy< A2lSiExponents > ();
        break;

      case symbol_kind::S_symbol_link: // symbol_link
        value.template destroy< A2lSymbolLink > ();
        break;

      case symbol_kind::S_var_characteristic: // var_characteristic
        value.template destroy< A2lVarCharacteristic > ();
        break;

      case symbol_kind::S_var_criterion: // var_criterion
        value.template destroy< A2lVarCriterion > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
      case symbol_kind::S_default_value_numeric: // default_value_numeric
      case symbol_kind::S_max_grad: // max_grad
      case symbol_kind::S_step_size: // step_size
        value.template destroy< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
      case symbol_kind::S_ecu_address_extension: // ecu_address_extension
      case symbol_kind::S_ecu_calibration_offset: // ecu_calibration_offset
        value.template destroy< int64_t > ();
        break;

      case symbol_kind::S_float_pair_list: // float_pair_list
        value.template destroy< std::map<double, double> > ();
        break;

      case symbol_kind::S_float_string_list: // float_string_list
        value.template destroy< std::map<double, std::string> > ();
        break;

      case symbol_kind::S_float_range_list: // float_range_list
        value.template destroy< std::map<std::pair<double, double>, std::string> > ();
        break;

      case symbol_kind::S_key_value_list: // key_value_list
      case symbol_kind::S_memory_layout_attributes: // memory_layout_attributes
      case symbol_kind::S_memory_segment_attributes: // memory_segment_attributes
      case symbol_kind::S_var_forbidden_comb: // var_forbidden_comb
        value.template destroy< std::map<std::string, std::string> > ();
        break;

      case symbol_kind::S_unit_conversion: // unit_conversion
        value.template destroy< std::pair<double,double> > ();
        break;

      case symbol_kind::S_formula: // formula
      case symbol_kind::S_system_constant: // system_constant
        value.template destroy< std::pair<std::string,std::string> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_A2ML: // A2ML
      case symbol_kind::S_IF_DATA: // IF_DATA
      case symbol_kind::S_ar_component_attribute: // ar_component_attribute
      case symbol_kind::S_calibration_handle_attribute: // calibration_handle_attribute
      case symbol_kind::S_formula_attribute: // formula_attribute
      case symbol_kind::S_a2ml: // a2ml
      case symbol_kind::S_annotation_label: // annotation_label
      case symbol_kind::S_annotation_origin: // annotation_origin
      case symbol_kind::S_ar_prototype_of: // ar_prototype_of
      case symbol_kind::S_axis_pts_ref: // axis_pts_ref
      case symbol_kind::S_calibration_handle_text: // calibration_handle_text
      case symbol_kind::S_comparison_quantity: // comparison_quantity
      case symbol_kind::S_compu_tab_ref: // compu_tab_ref
      case symbol_kind::S_conversion: // conversion
      case symbol_kind::S_cpu_type: // cpu_type
      case symbol_kind::S_curve_axis_ref: // curve_axis_ref
      case symbol_kind::S_customer: // customer
      case symbol_kind::S_customer_no: // customer_no
      case symbol_kind::S_default_value: // default_value
      case symbol_kind::S_display_identifier: // display_identifier
      case symbol_kind::S_ecu: // ecu
      case symbol_kind::S_epk: // epk
      case symbol_kind::S_format: // format
      case symbol_kind::S_formula_inv: // formula_inv
      case symbol_kind::S_function_version: // function_version
      case symbol_kind::S_if_data: // if_data
      case symbol_kind::S_input_quantity: // input_quantity
      case symbol_kind::S_model_link: // model_link
      case symbol_kind::S_phone_no: // phone_no
      case symbol_kind::S_phys_unit: // phys_unit
      case symbol_kind::S_proj_no: // proj_no
      case symbol_kind::S_project_no: // project_no
      case symbol_kind::S_ref_memory_segment: // ref_memory_segment
      case symbol_kind::S_ref_unit: // ref_unit
      case symbol_kind::S_status_string_ref: // status_string_ref
      case symbol_kind::S_supplier: // supplier
      case symbol_kind::S_symbol_type_link: // symbol_type_link
      case symbol_kind::S_user: // user
      case symbol_kind::S_var_measurement: // var_measurement
      case symbol_kind::S_var_naming: // var_naming
      case symbol_kind::S_var_selection_characteristic: // var_selection_characteristic
      case symbol_kind::S_var_separator: // var_separator
      case symbol_kind::S_version: // version
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_calibration_method_attributes: // calibration_method_attributes
        value.template destroy< std::vector<A2lCalibrationHandle> > ();
        break;

      case symbol_kind::S_float_list: // float_list
      case symbol_kind::S_fix_axis_par_list: // fix_axis_par_list
      case symbol_kind::S_coeffs: // coeffs
      case symbol_kind::S_coeffs_linear: // coeffs_linear
        value.template destroy< std::vector<double> > ();
        break;

      case symbol_kind::S_int_list: // int_list
        value.template destroy< std::vector<int64_t> > ();
        break;

      case symbol_kind::S_string_list: // string_list
      case symbol_kind::S_ident_list: // ident_list
      case symbol_kind::S_annotation_text: // annotation_text
      case symbol_kind::S_def_characteristic: // def_characteristic
      case symbol_kind::S_function_list: // function_list
      case symbol_kind::S_in_measurement: // in_measurement
      case symbol_kind::S_loc_measurement: // loc_measurement
      case symbol_kind::S_map_list: // map_list
      case symbol_kind::S_out_measurement: // out_measurement
      case symbol_kind::S_ref_characteristic: // ref_characteristic
      case symbol_kind::S_ref_group: // ref_group
      case symbol_kind::S_ref_measurement: // ref_measurement
      case symbol_kind::S_sub_function: // sub_function
      case symbol_kind::S_sub_group: // sub_group
      case symbol_kind::S_transformer_in_objects: // transformer_in_objects
      case symbol_kind::S_transformer_out_objects: // transformer_out_objects
      case symbol_kind::S_virtual: // virtual
      case symbol_kind::S_frame_measurement: // frame_measurement
        value.template destroy< std::vector<std::string> > ();
        break;

      case symbol_kind::S_uint_list: // uint_list
      case symbol_kind::S_var_address: // var_address
      case symbol_kind::S_var_characteristic_attribute: // var_characteristic_attribute
      case symbol_kind::S_matrix_dim: // matrix_dim
        value.template destroy< std::vector<uint64_t> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_any_uint: // any_uint
      case symbol_kind::S_addr_epk: // addr_epk
      case symbol_kind::S_alignment_byte: // alignment_byte
      case symbol_kind::S_alignment_float16_ieee: // alignment_float16_ieee
      case symbol_kind::S_alignment_float32_ieee: // alignment_float32_ieee
      case symbol_kind::S_alignment_float64_ieee: // alignment_float64_ieee
      case symbol_kind::S_alignment_int64: // alignment_int64
      case symbol_kind::S_alignment_long: // alignment_long
      case symbol_kind::S_alignment_word: // alignment_word
      case symbol_kind::S_array_size: // array_size
      case symbol_kind::S_bit_mask: // bit_mask
      case symbol_kind::S_data_size: // data_size
      case symbol_kind::S_ecu_address: // ecu_address
      case symbol_kind::S_error_mask: // error_mask
      case symbol_kind::S_fix_no_axis_pts_x: // fix_no_axis_pts_x
      case symbol_kind::S_fix_no_axis_pts_y: // fix_no_axis_pts_y
      case symbol_kind::S_fix_no_axis_pts_z: // fix_no_axis_pts_z
      case symbol_kind::S_fix_no_axis_pts_4: // fix_no_axis_pts_4
      case symbol_kind::S_fix_no_axis_pts_5: // fix_no_axis_pts_5
      case symbol_kind::S_left_shift: // left_shift
      case symbol_kind::S_no_of_interfaces: // no_of_interfaces
      case symbol_kind::S_number: // number
      case symbol_kind::S_right_shift: // right_shift
        value.template destroy< uint64_t > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if A2LDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return A2lParser::symbol_name (this->kind ());
      }
#endif // #if A2LDEBUG || 0


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
    A2lParser (a2l::A2lScanner &scanner_yyarg, a2l::A2lFile &file_yyarg);
    virtual ~A2lParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    A2lParser (const A2lParser&) = delete;
    /// Non copyable.
    A2lParser& operator= (const A2lParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if A2LDEBUG
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

#if A2LDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if A2LDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOL ()
      {
        return symbol_type (token::EOL);
      }
#else
      static
      symbol_type
      make_EOL ()
      {
        return symbol_type (token::EOL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2Lerror ()
      {
        return symbol_type (token::A2Lerror);
      }
#else
      static
      symbol_type
      make_A2Lerror ()
      {
        return symbol_type (token::A2Lerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2LUNDEF ()
      {
        return symbol_type (token::A2LUNDEF);
      }
#else
      static
      symbol_type
      make_A2LUNDEF ()
      {
        return symbol_type (token::A2LUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2L_BEGIN ()
      {
        return symbol_type (token::A2L_BEGIN);
      }
#else
      static
      symbol_type
      make_A2L_BEGIN ()
      {
        return symbol_type (token::A2L_BEGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2L_END ()
      {
        return symbol_type (token::A2L_END);
      }
#else
      static
      symbol_type
      make_A2L_END ()
      {
        return symbol_type (token::A2L_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2L_INCLUDE ()
      {
        return symbol_type (token::A2L_INCLUDE);
      }
#else
      static
      symbol_type
      make_A2L_INCLUDE ()
      {
        return symbol_type (token::A2L_INCLUDE);
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
      make_ASAP2_VERSION ()
      {
        return symbol_type (token::ASAP2_VERSION);
      }
#else
      static
      symbol_type
      make_ASAP2_VERSION ()
      {
        return symbol_type (token::ASAP2_VERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2L_VERSION ()
      {
        return symbol_type (token::A2L_VERSION);
      }
#else
      static
      symbol_type
      make_A2L_VERSION ()
      {
        return symbol_type (token::A2L_VERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2ML_VERSION ()
      {
        return symbol_type (token::A2ML_VERSION);
      }
#else
      static
      symbol_type
      make_A2ML_VERSION ()
      {
        return symbol_type (token::A2ML_VERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2ML (std::string v)
      {
        return symbol_type (token::A2ML, std::move (v));
      }
#else
      static
      symbol_type
      make_A2ML (const std::string& v)
      {
        return symbol_type (token::A2ML, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDR_EPK ()
      {
        return symbol_type (token::ADDR_EPK);
      }
#else
      static
      symbol_type
      make_ADDR_EPK ()
      {
        return symbol_type (token::ADDR_EPK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADDRESS_TYPE ()
      {
        return symbol_type (token::ADDRESS_TYPE);
      }
#else
      static
      symbol_type
      make_ADDRESS_TYPE ()
      {
        return symbol_type (token::ADDRESS_TYPE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_BYTE ()
      {
        return symbol_type (token::ALIGNMENT_BYTE);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_BYTE ()
      {
        return symbol_type (token::ALIGNMENT_BYTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_FLOAT16_IEEE ()
      {
        return symbol_type (token::ALIGNMENT_FLOAT16_IEEE);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_FLOAT16_IEEE ()
      {
        return symbol_type (token::ALIGNMENT_FLOAT16_IEEE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_FLOAT32_IEEE ()
      {
        return symbol_type (token::ALIGNMENT_FLOAT32_IEEE);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_FLOAT32_IEEE ()
      {
        return symbol_type (token::ALIGNMENT_FLOAT32_IEEE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_FLOAT64_IEEE ()
      {
        return symbol_type (token::ALIGNMENT_FLOAT64_IEEE);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_FLOAT64_IEEE ()
      {
        return symbol_type (token::ALIGNMENT_FLOAT64_IEEE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_INT64 ()
      {
        return symbol_type (token::ALIGNMENT_INT64);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_INT64 ()
      {
        return symbol_type (token::ALIGNMENT_INT64);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_LONG ()
      {
        return symbol_type (token::ALIGNMENT_LONG);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_LONG ()
      {
        return symbol_type (token::ALIGNMENT_LONG);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ALIGNMENT_WORD ()
      {
        return symbol_type (token::ALIGNMENT_WORD);
      }
#else
      static
      symbol_type
      make_ALIGNMENT_WORD ()
      {
        return symbol_type (token::ALIGNMENT_WORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANNOTATION ()
      {
        return symbol_type (token::ANNOTATION);
      }
#else
      static
      symbol_type
      make_ANNOTATION ()
      {
        return symbol_type (token::ANNOTATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANNOTATION_LABEL ()
      {
        return symbol_type (token::ANNOTATION_LABEL);
      }
#else
      static
      symbol_type
      make_ANNOTATION_LABEL ()
      {
        return symbol_type (token::ANNOTATION_LABEL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANNOTATION_ORIGIN ()
      {
        return symbol_type (token::ANNOTATION_ORIGIN);
      }
#else
      static
      symbol_type
      make_ANNOTATION_ORIGIN ()
      {
        return symbol_type (token::ANNOTATION_ORIGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ANNOTATION_TEXT ()
      {
        return symbol_type (token::ANNOTATION_TEXT);
      }
#else
      static
      symbol_type
      make_ANNOTATION_TEXT ()
      {
        return symbol_type (token::ANNOTATION_TEXT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_SIZE ()
      {
        return symbol_type (token::ARRAY_SIZE);
      }
#else
      static
      symbol_type
      make_ARRAY_SIZE ()
      {
        return symbol_type (token::ARRAY_SIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AR_COMPONENT ()
      {
        return symbol_type (token::AR_COMPONENT);
      }
#else
      static
      symbol_type
      make_AR_COMPONENT ()
      {
        return symbol_type (token::AR_COMPONENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AR_PROTOTYPE_OF ()
      {
        return symbol_type (token::AR_PROTOTYPE_OF);
      }
#else
      static
      symbol_type
      make_AR_PROTOTYPE_OF ()
      {
        return symbol_type (token::AR_PROTOTYPE_OF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_DESCR ()
      {
        return symbol_type (token::AXIS_DESCR);
      }
#else
      static
      symbol_type
      make_AXIS_DESCR ()
      {
        return symbol_type (token::AXIS_DESCR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS ()
      {
        return symbol_type (token::AXIS_PTS);
      }
#else
      static
      symbol_type
      make_AXIS_PTS ()
      {
        return symbol_type (token::AXIS_PTS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS_REF ()
      {
        return symbol_type (token::AXIS_PTS_REF);
      }
#else
      static
      symbol_type
      make_AXIS_PTS_REF ()
      {
        return symbol_type (token::AXIS_PTS_REF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS_X ()
      {
        return symbol_type (token::AXIS_PTS_X);
      }
#else
      static
      symbol_type
      make_AXIS_PTS_X ()
      {
        return symbol_type (token::AXIS_PTS_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS_Y ()
      {
        return symbol_type (token::AXIS_PTS_Y);
      }
#else
      static
      symbol_type
      make_AXIS_PTS_Y ()
      {
        return symbol_type (token::AXIS_PTS_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS_Z ()
      {
        return symbol_type (token::AXIS_PTS_Z);
      }
#else
      static
      symbol_type
      make_AXIS_PTS_Z ()
      {
        return symbol_type (token::AXIS_PTS_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS_4 ()
      {
        return symbol_type (token::AXIS_PTS_4);
      }
#else
      static
      symbol_type
      make_AXIS_PTS_4 ()
      {
        return symbol_type (token::AXIS_PTS_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_PTS_5 ()
      {
        return symbol_type (token::AXIS_PTS_5);
      }
#else
      static
      symbol_type
      make_AXIS_PTS_5 ()
      {
        return symbol_type (token::AXIS_PTS_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AXIS_RESCALE_X ()
      {
        return symbol_type (token::AXIS_RESCALE_X);
      }
#else
      static
      symbol_type
      make_AXIS_RESCALE_X ()
      {
        return symbol_type (token::AXIS_RESCALE_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_MASK ()
      {
        return symbol_type (token::BIT_MASK);
      }
#else
      static
      symbol_type
      make_BIT_MASK ()
      {
        return symbol_type (token::BIT_MASK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BIT_OPERATION ()
      {
        return symbol_type (token::BIT_OPERATION);
      }
#else
      static
      symbol_type
      make_BIT_OPERATION ()
      {
        return symbol_type (token::BIT_OPERATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BLOB ()
      {
        return symbol_type (token::BLOB);
      }
#else
      static
      symbol_type
      make_BLOB ()
      {
        return symbol_type (token::BLOB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2L_BYTE_ORDER ()
      {
        return symbol_type (token::A2L_BYTE_ORDER);
      }
#else
      static
      symbol_type
      make_A2L_BYTE_ORDER ()
      {
        return symbol_type (token::A2L_BYTE_ORDER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CALIBRATION_ACCESS ()
      {
        return symbol_type (token::CALIBRATION_ACCESS);
      }
#else
      static
      symbol_type
      make_CALIBRATION_ACCESS ()
      {
        return symbol_type (token::CALIBRATION_ACCESS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CALIBRATION_HANDLE ()
      {
        return symbol_type (token::CALIBRATION_HANDLE);
      }
#else
      static
      symbol_type
      make_CALIBRATION_HANDLE ()
      {
        return symbol_type (token::CALIBRATION_HANDLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CALIBRATION_HANDLE_TEXT ()
      {
        return symbol_type (token::CALIBRATION_HANDLE_TEXT);
      }
#else
      static
      symbol_type
      make_CALIBRATION_HANDLE_TEXT ()
      {
        return symbol_type (token::CALIBRATION_HANDLE_TEXT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CALIBRATION_METHOD ()
      {
        return symbol_type (token::CALIBRATION_METHOD);
      }
#else
      static
      symbol_type
      make_CALIBRATION_METHOD ()
      {
        return symbol_type (token::CALIBRATION_METHOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHARACTERISTIC ()
      {
        return symbol_type (token::CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_CHARACTERISTIC ()
      {
        return symbol_type (token::CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COEFFS ()
      {
        return symbol_type (token::COEFFS);
      }
#else
      static
      symbol_type
      make_COEFFS ()
      {
        return symbol_type (token::COEFFS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COEFFS_LINEAR ()
      {
        return symbol_type (token::COEFFS_LINEAR);
      }
#else
      static
      symbol_type
      make_COEFFS_LINEAR ()
      {
        return symbol_type (token::COEFFS_LINEAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPARISON_QUANTITY ()
      {
        return symbol_type (token::COMPARISON_QUANTITY);
      }
#else
      static
      symbol_type
      make_COMPARISON_QUANTITY ()
      {
        return symbol_type (token::COMPARISON_QUANTITY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPU_METHOD ()
      {
        return symbol_type (token::COMPU_METHOD);
      }
#else
      static
      symbol_type
      make_COMPU_METHOD ()
      {
        return symbol_type (token::COMPU_METHOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPU_TAB ()
      {
        return symbol_type (token::COMPU_TAB);
      }
#else
      static
      symbol_type
      make_COMPU_TAB ()
      {
        return symbol_type (token::COMPU_TAB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPU_TAB_REF ()
      {
        return symbol_type (token::COMPU_TAB_REF);
      }
#else
      static
      symbol_type
      make_COMPU_TAB_REF ()
      {
        return symbol_type (token::COMPU_TAB_REF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPU_VTAB ()
      {
        return symbol_type (token::COMPU_VTAB);
      }
#else
      static
      symbol_type
      make_COMPU_VTAB ()
      {
        return symbol_type (token::COMPU_VTAB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMPU_VTAB_RANGE ()
      {
        return symbol_type (token::COMPU_VTAB_RANGE);
      }
#else
      static
      symbol_type
      make_COMPU_VTAB_RANGE ()
      {
        return symbol_type (token::COMPU_VTAB_RANGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSISTENT_EXCHANGE ()
      {
        return symbol_type (token::CONSISTENT_EXCHANGE);
      }
#else
      static
      symbol_type
      make_CONSISTENT_EXCHANGE ()
      {
        return symbol_type (token::CONSISTENT_EXCHANGE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONVERSION ()
      {
        return symbol_type (token::CONVERSION);
      }
#else
      static
      symbol_type
      make_CONVERSION ()
      {
        return symbol_type (token::CONVERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CPU_TYPE ()
      {
        return symbol_type (token::CPU_TYPE);
      }
#else
      static
      symbol_type
      make_CPU_TYPE ()
      {
        return symbol_type (token::CPU_TYPE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CURVE_AXIS_REF ()
      {
        return symbol_type (token::CURVE_AXIS_REF);
      }
#else
      static
      symbol_type
      make_CURVE_AXIS_REF ()
      {
        return symbol_type (token::CURVE_AXIS_REF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CUSTOMER ()
      {
        return symbol_type (token::CUSTOMER);
      }
#else
      static
      symbol_type
      make_CUSTOMER ()
      {
        return symbol_type (token::CUSTOMER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CUSTOMER_NO ()
      {
        return symbol_type (token::CUSTOMER_NO);
      }
#else
      static
      symbol_type
      make_CUSTOMER_NO ()
      {
        return symbol_type (token::CUSTOMER_NO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DATA_SIZE ()
      {
        return symbol_type (token::DATA_SIZE);
      }
#else
      static
      symbol_type
      make_DATA_SIZE ()
      {
        return symbol_type (token::DATA_SIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEF_CHARACTERISTIC ()
      {
        return symbol_type (token::DEF_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_DEF_CHARACTERISTIC ()
      {
        return symbol_type (token::DEF_CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT_VALUE ()
      {
        return symbol_type (token::DEFAULT_VALUE);
      }
#else
      static
      symbol_type
      make_DEFAULT_VALUE ()
      {
        return symbol_type (token::DEFAULT_VALUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEFAULT_VALUE_NUMERIC ()
      {
        return symbol_type (token::DEFAULT_VALUE_NUMERIC);
      }
#else
      static
      symbol_type
      make_DEFAULT_VALUE_NUMERIC ()
      {
        return symbol_type (token::DEFAULT_VALUE_NUMERIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEPENDENT_CHARACTERISTIC ()
      {
        return symbol_type (token::DEPENDENT_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_DEPENDENT_CHARACTERISTIC ()
      {
        return symbol_type (token::DEPENDENT_CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEPOSIT ()
      {
        return symbol_type (token::DEPOSIT);
      }
#else
      static
      symbol_type
      make_DEPOSIT ()
      {
        return symbol_type (token::DEPOSIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DISCRETE ()
      {
        return symbol_type (token::DISCRETE);
      }
#else
      static
      symbol_type
      make_DISCRETE ()
      {
        return symbol_type (token::DISCRETE);
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
      make_DIST_OP_X ()
      {
        return symbol_type (token::DIST_OP_X);
      }
#else
      static
      symbol_type
      make_DIST_OP_X ()
      {
        return symbol_type (token::DIST_OP_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIST_OP_Y ()
      {
        return symbol_type (token::DIST_OP_Y);
      }
#else
      static
      symbol_type
      make_DIST_OP_Y ()
      {
        return symbol_type (token::DIST_OP_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIST_OP_Z ()
      {
        return symbol_type (token::DIST_OP_Z);
      }
#else
      static
      symbol_type
      make_DIST_OP_Z ()
      {
        return symbol_type (token::DIST_OP_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIST_OP_4 ()
      {
        return symbol_type (token::DIST_OP_4);
      }
#else
      static
      symbol_type
      make_DIST_OP_4 ()
      {
        return symbol_type (token::DIST_OP_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIST_OP_5 ()
      {
        return symbol_type (token::DIST_OP_5);
      }
#else
      static
      symbol_type
      make_DIST_OP_5 ()
      {
        return symbol_type (token::DIST_OP_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ECU ()
      {
        return symbol_type (token::ECU);
      }
#else
      static
      symbol_type
      make_ECU ()
      {
        return symbol_type (token::ECU);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ECU_ADDRESS ()
      {
        return symbol_type (token::ECU_ADDRESS);
      }
#else
      static
      symbol_type
      make_ECU_ADDRESS ()
      {
        return symbol_type (token::ECU_ADDRESS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ECU_ADDRESS_EXTENSION ()
      {
        return symbol_type (token::ECU_ADDRESS_EXTENSION);
      }
#else
      static
      symbol_type
      make_ECU_ADDRESS_EXTENSION ()
      {
        return symbol_type (token::ECU_ADDRESS_EXTENSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ECU_CALIBRATION_OFFSET ()
      {
        return symbol_type (token::ECU_CALIBRATION_OFFSET);
      }
#else
      static
      symbol_type
      make_ECU_CALIBRATION_OFFSET ()
      {
        return symbol_type (token::ECU_CALIBRATION_OFFSET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENCODING ()
      {
        return symbol_type (token::ENCODING);
      }
#else
      static
      symbol_type
      make_ENCODING ()
      {
        return symbol_type (token::ENCODING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EPK ()
      {
        return symbol_type (token::EPK);
      }
#else
      static
      symbol_type
      make_EPK ()
      {
        return symbol_type (token::EPK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ERROR_MASK ()
      {
        return symbol_type (token::ERROR_MASK);
      }
#else
      static
      symbol_type
      make_ERROR_MASK ()
      {
        return symbol_type (token::ERROR_MASK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDED_LIMITS ()
      {
        return symbol_type (token::EXTENDED_LIMITS);
      }
#else
      static
      symbol_type
      make_EXTENDED_LIMITS ()
      {
        return symbol_type (token::EXTENDED_LIMITS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_AXIS_PAR ()
      {
        return symbol_type (token::FIX_AXIS_PAR);
      }
#else
      static
      symbol_type
      make_FIX_AXIS_PAR ()
      {
        return symbol_type (token::FIX_AXIS_PAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_AXIS_PAR_DIST ()
      {
        return symbol_type (token::FIX_AXIS_PAR_DIST);
      }
#else
      static
      symbol_type
      make_FIX_AXIS_PAR_DIST ()
      {
        return symbol_type (token::FIX_AXIS_PAR_DIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_AXIS_PAR_LIST ()
      {
        return symbol_type (token::FIX_AXIS_PAR_LIST);
      }
#else
      static
      symbol_type
      make_FIX_AXIS_PAR_LIST ()
      {
        return symbol_type (token::FIX_AXIS_PAR_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_X ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_X);
      }
#else
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_X ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_Y ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_Y);
      }
#else
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_Y ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_Z ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_Z);
      }
#else
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_Z ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_4 ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_4);
      }
#else
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_4 ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_5 ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_5);
      }
#else
      static
      symbol_type
      make_FIX_NO_AXIS_PTS_5 ()
      {
        return symbol_type (token::FIX_NO_AXIS_PTS_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FNC_VALUES ()
      {
        return symbol_type (token::FNC_VALUES);
      }
#else
      static
      symbol_type
      make_FNC_VALUES ()
      {
        return symbol_type (token::FNC_VALUES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORMAT ()
      {
        return symbol_type (token::FORMAT);
      }
#else
      static
      symbol_type
      make_FORMAT ()
      {
        return symbol_type (token::FORMAT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORMULA ()
      {
        return symbol_type (token::FORMULA);
      }
#else
      static
      symbol_type
      make_FORMULA ()
      {
        return symbol_type (token::FORMULA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORMULA_INV ()
      {
        return symbol_type (token::FORMULA_INV);
      }
#else
      static
      symbol_type
      make_FORMULA_INV ()
      {
        return symbol_type (token::FORMULA_INV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FRAME ()
      {
        return symbol_type (token::FRAME);
      }
#else
      static
      symbol_type
      make_FRAME ()
      {
        return symbol_type (token::FRAME);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FRAME_MEASUREMENT ()
      {
        return symbol_type (token::FRAME_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_FRAME_MEASUREMENT ()
      {
        return symbol_type (token::FRAME_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#else
      static
      symbol_type
      make_FUNCTION ()
      {
        return symbol_type (token::FUNCTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION_LIST ()
      {
        return symbol_type (token::FUNCTION_LIST);
      }
#else
      static
      symbol_type
      make_FUNCTION_LIST ()
      {
        return symbol_type (token::FUNCTION_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION_VERSION ()
      {
        return symbol_type (token::FUNCTION_VERSION);
      }
#else
      static
      symbol_type
      make_FUNCTION_VERSION ()
      {
        return symbol_type (token::FUNCTION_VERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GROUP ()
      {
        return symbol_type (token::GROUP);
      }
#else
      static
      symbol_type
      make_GROUP ()
      {
        return symbol_type (token::GROUP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GUARD_RAILS ()
      {
        return symbol_type (token::GUARD_RAILS);
      }
#else
      static
      symbol_type
      make_GUARD_RAILS ()
      {
        return symbol_type (token::GUARD_RAILS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEADER ()
      {
        return symbol_type (token::HEADER);
      }
#else
      static
      symbol_type
      make_HEADER ()
      {
        return symbol_type (token::HEADER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFICATION ()
      {
        return symbol_type (token::IDENTIFICATION);
      }
#else
      static
      symbol_type
      make_IDENTIFICATION ()
      {
        return symbol_type (token::IDENTIFICATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF_DATA (std::string v)
      {
        return symbol_type (token::IF_DATA, std::move (v));
      }
#else
      static
      symbol_type
      make_IF_DATA (const std::string& v)
      {
        return symbol_type (token::IF_DATA, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IN_MEASUREMENT ()
      {
        return symbol_type (token::IN_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_IN_MEASUREMENT ()
      {
        return symbol_type (token::IN_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUT_QUANTITY ()
      {
        return symbol_type (token::INPUT_QUANTITY);
      }
#else
      static
      symbol_type
      make_INPUT_QUANTITY ()
      {
        return symbol_type (token::INPUT_QUANTITY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INSTANCE ()
      {
        return symbol_type (token::INSTANCE);
      }
#else
      static
      symbol_type
      make_INSTANCE ()
      {
        return symbol_type (token::INSTANCE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LAYOUT ()
      {
        return symbol_type (token::LAYOUT);
      }
#else
      static
      symbol_type
      make_LAYOUT ()
      {
        return symbol_type (token::LAYOUT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_SHIFT ()
      {
        return symbol_type (token::LEFT_SHIFT);
      }
#else
      static
      symbol_type
      make_LEFT_SHIFT ()
      {
        return symbol_type (token::LEFT_SHIFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIMITS ()
      {
        return symbol_type (token::LIMITS);
      }
#else
      static
      symbol_type
      make_LIMITS ()
      {
        return symbol_type (token::LIMITS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOC_MEASUREMENT ()
      {
        return symbol_type (token::LOC_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_LOC_MEASUREMENT ()
      {
        return symbol_type (token::LOC_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAP_LIST ()
      {
        return symbol_type (token::MAP_LIST);
      }
#else
      static
      symbol_type
      make_MAP_LIST ()
      {
        return symbol_type (token::MAP_LIST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MATRIX_DIM ()
      {
        return symbol_type (token::MATRIX_DIM);
      }
#else
      static
      symbol_type
      make_MATRIX_DIM ()
      {
        return symbol_type (token::MATRIX_DIM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_GRAD ()
      {
        return symbol_type (token::MAX_GRAD);
      }
#else
      static
      symbol_type
      make_MAX_GRAD ()
      {
        return symbol_type (token::MAX_GRAD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAX_REFRESH ()
      {
        return symbol_type (token::MAX_REFRESH);
      }
#else
      static
      symbol_type
      make_MAX_REFRESH ()
      {
        return symbol_type (token::MAX_REFRESH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEASUREMENT ()
      {
        return symbol_type (token::MEASUREMENT);
      }
#else
      static
      symbol_type
      make_MEASUREMENT ()
      {
        return symbol_type (token::MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEMORY_LAYOUT ()
      {
        return symbol_type (token::MEMORY_LAYOUT);
      }
#else
      static
      symbol_type
      make_MEMORY_LAYOUT ()
      {
        return symbol_type (token::MEMORY_LAYOUT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEMORY_SEGMENT ()
      {
        return symbol_type (token::MEMORY_SEGMENT);
      }
#else
      static
      symbol_type
      make_MEMORY_SEGMENT ()
      {
        return symbol_type (token::MEMORY_SEGMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULE ()
      {
        return symbol_type (token::MODULE);
      }
#else
      static
      symbol_type
      make_MODULE ()
      {
        return symbol_type (token::MODULE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_COMMON ()
      {
        return symbol_type (token::MOD_COMMON);
      }
#else
      static
      symbol_type
      make_MOD_COMMON ()
      {
        return symbol_type (token::MOD_COMMON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD_PAR ()
      {
        return symbol_type (token::MOD_PAR);
      }
#else
      static
      symbol_type
      make_MOD_PAR ()
      {
        return symbol_type (token::MOD_PAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODEL_LINK ()
      {
        return symbol_type (token::MODEL_LINK);
      }
#else
      static
      symbol_type
      make_MODEL_LINK ()
      {
        return symbol_type (token::MODEL_LINK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MONOTONY ()
      {
        return symbol_type (token::MONOTONY);
      }
#else
      static
      symbol_type
      make_MONOTONY ()
      {
        return symbol_type (token::MONOTONY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_AXIS_PTS_X ()
      {
        return symbol_type (token::NO_AXIS_PTS_X);
      }
#else
      static
      symbol_type
      make_NO_AXIS_PTS_X ()
      {
        return symbol_type (token::NO_AXIS_PTS_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_AXIS_PTS_Y ()
      {
        return symbol_type (token::NO_AXIS_PTS_Y);
      }
#else
      static
      symbol_type
      make_NO_AXIS_PTS_Y ()
      {
        return symbol_type (token::NO_AXIS_PTS_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_AXIS_PTS_Z ()
      {
        return symbol_type (token::NO_AXIS_PTS_Z);
      }
#else
      static
      symbol_type
      make_NO_AXIS_PTS_Z ()
      {
        return symbol_type (token::NO_AXIS_PTS_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_AXIS_PTS_4 ()
      {
        return symbol_type (token::NO_AXIS_PTS_4);
      }
#else
      static
      symbol_type
      make_NO_AXIS_PTS_4 ()
      {
        return symbol_type (token::NO_AXIS_PTS_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_AXIS_PTS_5 ()
      {
        return symbol_type (token::NO_AXIS_PTS_5);
      }
#else
      static
      symbol_type
      make_NO_AXIS_PTS_5 ()
      {
        return symbol_type (token::NO_AXIS_PTS_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_OF_INTERFACES ()
      {
        return symbol_type (token::NO_OF_INTERFACES);
      }
#else
      static
      symbol_type
      make_NO_OF_INTERFACES ()
      {
        return symbol_type (token::NO_OF_INTERFACES);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NO_RESCALE_X ()
      {
        return symbol_type (token::NO_RESCALE_X);
      }
#else
      static
      symbol_type
      make_NO_RESCALE_X ()
      {
        return symbol_type (token::NO_RESCALE_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER ()
      {
        return symbol_type (token::NUMBER);
      }
#else
      static
      symbol_type
      make_NUMBER ()
      {
        return symbol_type (token::NUMBER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OFFSET_X ()
      {
        return symbol_type (token::OFFSET_X);
      }
#else
      static
      symbol_type
      make_OFFSET_X ()
      {
        return symbol_type (token::OFFSET_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OFFSET_Y ()
      {
        return symbol_type (token::OFFSET_Y);
      }
#else
      static
      symbol_type
      make_OFFSET_Y ()
      {
        return symbol_type (token::OFFSET_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OFFSET_Z ()
      {
        return symbol_type (token::OFFSET_Z);
      }
#else
      static
      symbol_type
      make_OFFSET_Z ()
      {
        return symbol_type (token::OFFSET_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OFFSET_4 ()
      {
        return symbol_type (token::OFFSET_4);
      }
#else
      static
      symbol_type
      make_OFFSET_4 ()
      {
        return symbol_type (token::OFFSET_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OFFSET_5 ()
      {
        return symbol_type (token::OFFSET_5);
      }
#else
      static
      symbol_type
      make_OFFSET_5 ()
      {
        return symbol_type (token::OFFSET_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUT_MEASUREMENT ()
      {
        return symbol_type (token::OUT_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_OUT_MEASUREMENT ()
      {
        return symbol_type (token::OUT_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OVERWRITE ()
      {
        return symbol_type (token::OVERWRITE);
      }
#else
      static
      symbol_type
      make_OVERWRITE ()
      {
        return symbol_type (token::OVERWRITE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PHONE_NO ()
      {
        return symbol_type (token::PHONE_NO);
      }
#else
      static
      symbol_type
      make_PHONE_NO ()
      {
        return symbol_type (token::PHONE_NO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PHYS_UNIT ()
      {
        return symbol_type (token::PHYS_UNIT);
      }
#else
      static
      symbol_type
      make_PHYS_UNIT ()
      {
        return symbol_type (token::PHYS_UNIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROJECT ()
      {
        return symbol_type (token::PROJECT);
      }
#else
      static
      symbol_type
      make_PROJECT ()
      {
        return symbol_type (token::PROJECT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PROJECT_NO ()
      {
        return symbol_type (token::PROJECT_NO);
      }
#else
      static
      symbol_type
      make_PROJECT_NO ()
      {
        return symbol_type (token::PROJECT_NO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_READ_ONLY ()
      {
        return symbol_type (token::READ_ONLY);
      }
#else
      static
      symbol_type
      make_READ_ONLY ()
      {
        return symbol_type (token::READ_ONLY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_READ_WRITE ()
      {
        return symbol_type (token::READ_WRITE);
      }
#else
      static
      symbol_type
      make_READ_WRITE ()
      {
        return symbol_type (token::READ_WRITE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECORD_LAYOUT ()
      {
        return symbol_type (token::RECORD_LAYOUT);
      }
#else
      static
      symbol_type
      make_RECORD_LAYOUT ()
      {
        return symbol_type (token::RECORD_LAYOUT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF_CHARACTERISTIC ()
      {
        return symbol_type (token::REF_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_REF_CHARACTERISTIC ()
      {
        return symbol_type (token::REF_CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF_GROUP ()
      {
        return symbol_type (token::REF_GROUP);
      }
#else
      static
      symbol_type
      make_REF_GROUP ()
      {
        return symbol_type (token::REF_GROUP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF_MEASUREMENT ()
      {
        return symbol_type (token::REF_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_REF_MEASUREMENT ()
      {
        return symbol_type (token::REF_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF_MEMORY_SEGMENT ()
      {
        return symbol_type (token::REF_MEMORY_SEGMENT);
      }
#else
      static
      symbol_type
      make_REF_MEMORY_SEGMENT ()
      {
        return symbol_type (token::REF_MEMORY_SEGMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REF_UNIT ()
      {
        return symbol_type (token::REF_UNIT);
      }
#else
      static
      symbol_type
      make_REF_UNIT ()
      {
        return symbol_type (token::REF_UNIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESERVED ()
      {
        return symbol_type (token::RESERVED);
      }
#else
      static
      symbol_type
      make_RESERVED ()
      {
        return symbol_type (token::RESERVED);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_SHIFT ()
      {
        return symbol_type (token::RIGHT_SHIFT);
      }
#else
      static
      symbol_type
      make_RIGHT_SHIFT ()
      {
        return symbol_type (token::RIGHT_SHIFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIP_ADDR_W ()
      {
        return symbol_type (token::RIP_ADDR_W);
      }
#else
      static
      symbol_type
      make_RIP_ADDR_W ()
      {
        return symbol_type (token::RIP_ADDR_W);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIP_ADDR_X ()
      {
        return symbol_type (token::RIP_ADDR_X);
      }
#else
      static
      symbol_type
      make_RIP_ADDR_X ()
      {
        return symbol_type (token::RIP_ADDR_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIP_ADDR_Y ()
      {
        return symbol_type (token::RIP_ADDR_Y);
      }
#else
      static
      symbol_type
      make_RIP_ADDR_Y ()
      {
        return symbol_type (token::RIP_ADDR_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIP_ADDR_Z ()
      {
        return symbol_type (token::RIP_ADDR_Z);
      }
#else
      static
      symbol_type
      make_RIP_ADDR_Z ()
      {
        return symbol_type (token::RIP_ADDR_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIP_ADDR_4 ()
      {
        return symbol_type (token::RIP_ADDR_4);
      }
#else
      static
      symbol_type
      make_RIP_ADDR_4 ()
      {
        return symbol_type (token::RIP_ADDR_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIP_ADDR_5 ()
      {
        return symbol_type (token::RIP_ADDR_5);
      }
#else
      static
      symbol_type
      make_RIP_ADDR_5 ()
      {
        return symbol_type (token::RIP_ADDR_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROOT ()
      {
        return symbol_type (token::ROOT);
      }
#else
      static
      symbol_type
      make_ROOT ()
      {
        return symbol_type (token::ROOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_S_REC_LAYOUT ()
      {
        return symbol_type (token::S_REC_LAYOUT);
      }
#else
      static
      symbol_type
      make_S_REC_LAYOUT ()
      {
        return symbol_type (token::S_REC_LAYOUT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHIFT_OP_X ()
      {
        return symbol_type (token::SHIFT_OP_X);
      }
#else
      static
      symbol_type
      make_SHIFT_OP_X ()
      {
        return symbol_type (token::SHIFT_OP_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHIFT_OP_Y ()
      {
        return symbol_type (token::SHIFT_OP_Y);
      }
#else
      static
      symbol_type
      make_SHIFT_OP_Y ()
      {
        return symbol_type (token::SHIFT_OP_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHIFT_OP_Z ()
      {
        return symbol_type (token::SHIFT_OP_Z);
      }
#else
      static
      symbol_type
      make_SHIFT_OP_Z ()
      {
        return symbol_type (token::SHIFT_OP_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHIFT_OP_4 ()
      {
        return symbol_type (token::SHIFT_OP_4);
      }
#else
      static
      symbol_type
      make_SHIFT_OP_4 ()
      {
        return symbol_type (token::SHIFT_OP_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SHIFT_OP_5 ()
      {
        return symbol_type (token::SHIFT_OP_5);
      }
#else
      static
      symbol_type
      make_SHIFT_OP_5 ()
      {
        return symbol_type (token::SHIFT_OP_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIGN_EXTEND ()
      {
        return symbol_type (token::SIGN_EXTEND);
      }
#else
      static
      symbol_type
      make_SIGN_EXTEND ()
      {
        return symbol_type (token::SIGN_EXTEND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SI_EXPONENTS ()
      {
        return symbol_type (token::SI_EXPONENTS);
      }
#else
      static
      symbol_type
      make_SI_EXPONENTS ()
      {
        return symbol_type (token::SI_EXPONENTS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SRC_ADDR_X ()
      {
        return symbol_type (token::SRC_ADDR_X);
      }
#else
      static
      symbol_type
      make_SRC_ADDR_X ()
      {
        return symbol_type (token::SRC_ADDR_X);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SRC_ADDR_Y ()
      {
        return symbol_type (token::SRC_ADDR_Y);
      }
#else
      static
      symbol_type
      make_SRC_ADDR_Y ()
      {
        return symbol_type (token::SRC_ADDR_Y);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SRC_ADDR_Z ()
      {
        return symbol_type (token::SRC_ADDR_Z);
      }
#else
      static
      symbol_type
      make_SRC_ADDR_Z ()
      {
        return symbol_type (token::SRC_ADDR_Z);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SRC_ADDR_4 ()
      {
        return symbol_type (token::SRC_ADDR_4);
      }
#else
      static
      symbol_type
      make_SRC_ADDR_4 ()
      {
        return symbol_type (token::SRC_ADDR_4);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SRC_ADDR_5 ()
      {
        return symbol_type (token::SRC_ADDR_5);
      }
#else
      static
      symbol_type
      make_SRC_ADDR_5 ()
      {
        return symbol_type (token::SRC_ADDR_5);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC_ADDRESS_OFFSETS ()
      {
        return symbol_type (token::STATIC_ADDRESS_OFFSETS);
      }
#else
      static
      symbol_type
      make_STATIC_ADDRESS_OFFSETS ()
      {
        return symbol_type (token::STATIC_ADDRESS_OFFSETS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC_RECORD_LAYOUT ()
      {
        return symbol_type (token::STATIC_RECORD_LAYOUT);
      }
#else
      static
      symbol_type
      make_STATIC_RECORD_LAYOUT ()
      {
        return symbol_type (token::STATIC_RECORD_LAYOUT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATUS_STRING_REF ()
      {
        return symbol_type (token::STATUS_STRING_REF);
      }
#else
      static
      symbol_type
      make_STATUS_STRING_REF ()
      {
        return symbol_type (token::STATUS_STRING_REF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STEP_SIZE ()
      {
        return symbol_type (token::STEP_SIZE);
      }
#else
      static
      symbol_type
      make_STEP_SIZE ()
      {
        return symbol_type (token::STEP_SIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCTURE_COMPONENT ()
      {
        return symbol_type (token::STRUCTURE_COMPONENT);
      }
#else
      static
      symbol_type
      make_STRUCTURE_COMPONENT ()
      {
        return symbol_type (token::STRUCTURE_COMPONENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_FUNCTION ()
      {
        return symbol_type (token::SUB_FUNCTION);
      }
#else
      static
      symbol_type
      make_SUB_FUNCTION ()
      {
        return symbol_type (token::SUB_FUNCTION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB_GROUP ()
      {
        return symbol_type (token::SUB_GROUP);
      }
#else
      static
      symbol_type
      make_SUB_GROUP ()
      {
        return symbol_type (token::SUB_GROUP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUPPLIER ()
      {
        return symbol_type (token::SUPPLIER);
      }
#else
      static
      symbol_type
      make_SUPPLIER ()
      {
        return symbol_type (token::SUPPLIER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYMBOL_LINK ()
      {
        return symbol_type (token::SYMBOL_LINK);
      }
#else
      static
      symbol_type
      make_SYMBOL_LINK ()
      {
        return symbol_type (token::SYMBOL_LINK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYMBOL_TYPE_LINK ()
      {
        return symbol_type (token::SYMBOL_TYPE_LINK);
      }
#else
      static
      symbol_type
      make_SYMBOL_TYPE_LINK ()
      {
        return symbol_type (token::SYMBOL_TYPE_LINK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SYSTEM_CONSTANT ()
      {
        return symbol_type (token::SYSTEM_CONSTANT);
      }
#else
      static
      symbol_type
      make_SYSTEM_CONSTANT ()
      {
        return symbol_type (token::SYSTEM_CONSTANT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRANSFORMER ()
      {
        return symbol_type (token::TRANSFORMER);
      }
#else
      static
      symbol_type
      make_TRANSFORMER ()
      {
        return symbol_type (token::TRANSFORMER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRANSFORMER_IN_OBJECTS ()
      {
        return symbol_type (token::TRANSFORMER_IN_OBJECTS);
      }
#else
      static
      symbol_type
      make_TRANSFORMER_IN_OBJECTS ()
      {
        return symbol_type (token::TRANSFORMER_IN_OBJECTS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRANSFORMER_OUT_OBJECTS ()
      {
        return symbol_type (token::TRANSFORMER_OUT_OBJECTS);
      }
#else
      static
      symbol_type
      make_TRANSFORMER_OUT_OBJECTS ()
      {
        return symbol_type (token::TRANSFORMER_OUT_OBJECTS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF_AXIS ()
      {
        return symbol_type (token::TYPEDEF_AXIS);
      }
#else
      static
      symbol_type
      make_TYPEDEF_AXIS ()
      {
        return symbol_type (token::TYPEDEF_AXIS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF_BLOB ()
      {
        return symbol_type (token::TYPEDEF_BLOB);
      }
#else
      static
      symbol_type
      make_TYPEDEF_BLOB ()
      {
        return symbol_type (token::TYPEDEF_BLOB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF_CHARACTERISTIC ()
      {
        return symbol_type (token::TYPEDEF_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_TYPEDEF_CHARACTERISTIC ()
      {
        return symbol_type (token::TYPEDEF_CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF_MEASUREMENT ()
      {
        return symbol_type (token::TYPEDEF_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_TYPEDEF_MEASUREMENT ()
      {
        return symbol_type (token::TYPEDEF_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPEDEF_STRUCTURE ()
      {
        return symbol_type (token::TYPEDEF_STRUCTURE);
      }
#else
      static
      symbol_type
      make_TYPEDEF_STRUCTURE ()
      {
        return symbol_type (token::TYPEDEF_STRUCTURE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIT ()
      {
        return symbol_type (token::UNIT);
      }
#else
      static
      symbol_type
      make_UNIT ()
      {
        return symbol_type (token::UNIT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIT_CONVERSION ()
      {
        return symbol_type (token::UNIT_CONVERSION);
      }
#else
      static
      symbol_type
      make_UNIT_CONVERSION ()
      {
        return symbol_type (token::UNIT_CONVERSION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER ()
      {
        return symbol_type (token::USER);
      }
#else
      static
      symbol_type
      make_USER ()
      {
        return symbol_type (token::USER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER_RIGHTS ()
      {
        return symbol_type (token::USER_RIGHTS);
      }
#else
      static
      symbol_type
      make_USER_RIGHTS ()
      {
        return symbol_type (token::USER_RIGHTS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_ADDRESS ()
      {
        return symbol_type (token::VAR_ADDRESS);
      }
#else
      static
      symbol_type
      make_VAR_ADDRESS ()
      {
        return symbol_type (token::VAR_ADDRESS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_CHARACTERISTIC ()
      {
        return symbol_type (token::VAR_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_VAR_CHARACTERISTIC ()
      {
        return symbol_type (token::VAR_CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_CRITERION ()
      {
        return symbol_type (token::VAR_CRITERION);
      }
#else
      static
      symbol_type
      make_VAR_CRITERION ()
      {
        return symbol_type (token::VAR_CRITERION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_FORBIDDEN_COMB ()
      {
        return symbol_type (token::VAR_FORBIDDEN_COMB);
      }
#else
      static
      symbol_type
      make_VAR_FORBIDDEN_COMB ()
      {
        return symbol_type (token::VAR_FORBIDDEN_COMB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_MEASUREMENT ()
      {
        return symbol_type (token::VAR_MEASUREMENT);
      }
#else
      static
      symbol_type
      make_VAR_MEASUREMENT ()
      {
        return symbol_type (token::VAR_MEASUREMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_NAMING ()
      {
        return symbol_type (token::VAR_NAMING);
      }
#else
      static
      symbol_type
      make_VAR_NAMING ()
      {
        return symbol_type (token::VAR_NAMING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_SELECTION_CHARACTERISTIC ()
      {
        return symbol_type (token::VAR_SELECTION_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_VAR_SELECTION_CHARACTERISTIC ()
      {
        return symbol_type (token::VAR_SELECTION_CHARACTERISTIC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR_SEPARATOR ()
      {
        return symbol_type (token::VAR_SEPARATOR);
      }
#else
      static
      symbol_type
      make_VAR_SEPARATOR ()
      {
        return symbol_type (token::VAR_SEPARATOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VARIANT_CODING ()
      {
        return symbol_type (token::VARIANT_CODING);
      }
#else
      static
      symbol_type
      make_VARIANT_CODING ()
      {
        return symbol_type (token::VARIANT_CODING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VIRTUAL ()
      {
        return symbol_type (token::VIRTUAL);
      }
#else
      static
      symbol_type
      make_VIRTUAL ()
      {
        return symbol_type (token::VIRTUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VIRTUAL_CHARACTERISTIC ()
      {
        return symbol_type (token::VIRTUAL_CHARACTERISTIC);
      }
#else
      static
      symbol_type
      make_VIRTUAL_CHARACTERISTIC ()
      {
        return symbol_type (token::VIRTUAL_CHARACTERISTIC);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    A2lParser (const A2lParser&);
    /// Non copyable.
    A2lParser& operator= (const A2lParser&);
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

#if A2LDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if A2LDEBUG || 0


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


#if A2LDEBUG
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
      yylast_ = 1218,     ///< Last index in yytable_.
      yynnts_ = 286,  ///< Number of nonterminal symbols.
      yyfinal_ = 9 ///< Termination state number.
    };


    // User arguments.
    a2l::A2lScanner &scanner;
    a2l::A2lFile &file;

  };


#line 5 "/home/ihedvall/CLionProjects/a2llib/src/a2lparser.y"
} // a2l
#line 6307 "/home/ihedvall/CLionProjects/a2llib/src/a2lparser.hpp"




#endif // !YY_A2L_HOME_IHEDVALL_CLIONPROJECTS_A2LLIB_SRC_A2LPARSER_HPP_INCLUDED
