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
 ** \file /home/ihedvall/CLionProjects/a2llib/src/a2mlparser.hpp
 ** Define the a2l::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_A2ML_HOME_IHEDVALL_CLIONPROJECTS_A2LLIB_SRC_A2MLPARSER_HPP_INCLUDED
# define YY_A2ML_HOME_IHEDVALL_CLIONPROJECTS_A2LLIB_SRC_A2MLPARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 10 "/home/ihedvall/CLionProjects/a2llib/src/a2mlparser.y"

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/a2mlobject.h"

namespace a2l {
class A2mlScanner;
}


#line 62 "/home/ihedvall/CLionProjects/a2llib/src/a2mlparser.hpp"


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
#ifndef A2MLDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define A2MLDEBUG 1
#  else
#   define A2MLDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define A2MLDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined A2MLDEBUG */

#line 6 "/home/ihedvall/CLionProjects/a2llib/src/a2mlparser.y"
namespace a2l {
#line 206 "/home/ihedvall/CLionProjects/a2llib/src/a2mlparser.hpp"




  /// A Bison parser.
  class A2mlParser
  {
  public:
#ifdef A2MLSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define A2MLSTYPE in C++, use %define api.value.type"
# endif
    typedef A2MLSTYPE value_type;
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
      // predefined_type_name
      char dummy1[sizeof (a2l::A2mlDataType)];

      // enumerator_list
      char dummy2[sizeof (a2l::A2mlEnumerateList)];

      // declaration_list
      // struct_member_list
      // taggedstruct_member_list
      // taggedunion_member_list
      char dummy3[sizeof (a2l::A2mlMemberList)];

      // declaration
      // type_definition
      // type_name
      // block_definition
      // enum_type_name
      // struct_type_name
      // struct_member
      // member
      // taggedstruct_type_name
      // taggedstruct_member
      // taggedstruct_definition
      // taggedunion_type_name
      // taggedunion_member
      char dummy4[sizeof (a2l::A2mlObject)];

      // FLOAT
      char dummy5[sizeof (double)];

      // CONSTANT
      char dummy6[sizeof (int64_t)];

      // enumerator
      char dummy7[sizeof (std::pair<int64_t, std::string>)];

      // IDENT
      // STRING
      // keyword
      // identifier
      // tag
      char dummy8[sizeof (std::string)];
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
        A2MLEMPTY = -2,
    A2MLEOF = 0,                   // "end of file"
    A2MLerror = 256,               // error
    A2MLUNDEF = 257,               // "invalid token"
    A2ML_BEGIN = 258,              // A2ML_BEGIN
    A2ML_END = 259,                // A2ML_END
    A2ML = 260,                    // A2ML
    ARRAY_BEGIN = 261,             // ARRAY_BEGIN
    ARRAY_END = 262,               // ARRAY_END
    BLOCK = 263,                   // BLOCK
    BLOCK_BEGIN = 264,             // BLOCK_BEGIN
    BLOCK_END = 265,               // BLOCK_END
    CHAR = 266,                    // CHAR
    CONSTANT = 267,                // CONSTANT
    DEF_END = 268,                 // DEF_END
    DOUBLE = 269,                  // DOUBLE
    ENUM = 270,                    // ENUM
    EQUAL = 271,                   // EQUAL
    FLOAT = 272,                   // FLOAT
    IDENT = 273,                   // IDENT
    IF_DATA = 274,                 // IF_DATA
    INT = 275,                     // INT
    INT64 = 276,                   // INT64
    LONG = 277,                    // LONG
    MEM_BEGIN = 278,               // MEM_BEGIN
    MEM_END = 279,                 // MEM_END
    STRING = 280,                  // STRING
    STRUCT = 281,                  // STRUCT
    TAGGED_STRUCT = 282,           // TAGGED_STRUCT
    TAGGED_UNION = 283,            // TAGGED_UNION
    TEXT_ARRAY = 284,              // TEXT_ARRAY
    UCHAR = 285,                   // UCHAR
    UINT = 286,                    // UINT
    UINT64 = 287,                  // UINT64
    ULONG = 288                    // ULONG
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
        YYNTOKENS = 34, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_A2ML_BEGIN = 3,                        // A2ML_BEGIN
        S_A2ML_END = 4,                          // A2ML_END
        S_A2ML = 5,                              // A2ML
        S_ARRAY_BEGIN = 6,                       // ARRAY_BEGIN
        S_ARRAY_END = 7,                         // ARRAY_END
        S_BLOCK = 8,                             // BLOCK
        S_BLOCK_BEGIN = 9,                       // BLOCK_BEGIN
        S_BLOCK_END = 10,                        // BLOCK_END
        S_CHAR = 11,                             // CHAR
        S_CONSTANT = 12,                         // CONSTANT
        S_DEF_END = 13,                          // DEF_END
        S_DOUBLE = 14,                           // DOUBLE
        S_ENUM = 15,                             // ENUM
        S_EQUAL = 16,                            // EQUAL
        S_FLOAT = 17,                            // FLOAT
        S_IDENT = 18,                            // IDENT
        S_IF_DATA = 19,                          // IF_DATA
        S_INT = 20,                              // INT
        S_INT64 = 21,                            // INT64
        S_LONG = 22,                             // LONG
        S_MEM_BEGIN = 23,                        // MEM_BEGIN
        S_MEM_END = 24,                          // MEM_END
        S_STRING = 25,                           // STRING
        S_STRUCT = 26,                           // STRUCT
        S_TAGGED_STRUCT = 27,                    // TAGGED_STRUCT
        S_TAGGED_UNION = 28,                     // TAGGED_UNION
        S_TEXT_ARRAY = 29,                       // TEXT_ARRAY
        S_UCHAR = 30,                            // UCHAR
        S_UINT = 31,                             // UINT
        S_UINT64 = 32,                           // UINT64
        S_ULONG = 33,                            // ULONG
        S_YYACCEPT = 34,                         // $accept
        S_a2ml_block = 35,                       // a2ml_block
        S_declaration_list = 36,                 // declaration_list
        S_declaration = 37,                      // declaration
        S_type_definition = 38,                  // type_definition
        S_type_name = 39,                        // type_name
        S_predefined_type_name = 40,             // predefined_type_name
        S_block_definition = 41,                 // block_definition
        S_enum_type_name = 42,                   // enum_type_name
        S_enumerator_list = 43,                  // enumerator_list
        S_enumerator = 44,                       // enumerator
        S_struct_type_name = 45,                 // struct_type_name
        S_struct_member_list = 46,               // struct_member_list
        S_struct_member = 47,                    // struct_member
        S_member = 48,                           // member
        S_array_specifier = 49,                  // array_specifier
        S_taggedstruct_type_name = 50,           // taggedstruct_type_name
        S_taggedstruct_member_list = 51,         // taggedstruct_member_list
        S_taggedstruct_member = 52,              // taggedstruct_member
        S_taggedstruct_definition = 53,          // taggedstruct_definition
        S_taggedunion_type_name = 54,            // taggedunion_type_name
        S_taggedunion_member_list = 55,          // taggedunion_member_list
        S_taggedunion_member = 56,               // taggedunion_member
        S_keyword = 57,                          // keyword
        S_identifier = 58,                       // identifier
        S_tag = 59                               // tag
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
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.move< a2l::A2mlDataType > (std::move (that.value));
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.move< a2l::A2mlEnumerateList > (std::move (that.value));
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.move< a2l::A2mlMemberList > (std::move (that.value));
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.move< a2l::A2mlObject > (std::move (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.move< int64_t > (std::move (that.value));
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.move< std::pair<int64_t, std::string> > (std::move (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
        value.move< std::string > (std::move (that.value));
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
      basic_symbol (typename Base::kind_type t, a2l::A2mlDataType&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const a2l::A2mlDataType& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, a2l::A2mlEnumerateList&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const a2l::A2mlEnumerateList& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, a2l::A2mlMemberList&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const a2l::A2mlMemberList& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, a2l::A2mlObject&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const a2l::A2mlObject& v)
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
      basic_symbol (typename Base::kind_type t, std::pair<int64_t, std::string>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<int64_t, std::string>& v)
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
      case symbol_kind::S_predefined_type_name: // predefined_type_name
        value.template destroy< a2l::A2mlDataType > ();
        break;

      case symbol_kind::S_enumerator_list: // enumerator_list
        value.template destroy< a2l::A2mlEnumerateList > ();
        break;

      case symbol_kind::S_declaration_list: // declaration_list
      case symbol_kind::S_struct_member_list: // struct_member_list
      case symbol_kind::S_taggedstruct_member_list: // taggedstruct_member_list
      case symbol_kind::S_taggedunion_member_list: // taggedunion_member_list
        value.template destroy< a2l::A2mlMemberList > ();
        break;

      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_type_definition: // type_definition
      case symbol_kind::S_type_name: // type_name
      case symbol_kind::S_block_definition: // block_definition
      case symbol_kind::S_enum_type_name: // enum_type_name
      case symbol_kind::S_struct_type_name: // struct_type_name
      case symbol_kind::S_struct_member: // struct_member
      case symbol_kind::S_member: // member
      case symbol_kind::S_taggedstruct_type_name: // taggedstruct_type_name
      case symbol_kind::S_taggedstruct_member: // taggedstruct_member
      case symbol_kind::S_taggedstruct_definition: // taggedstruct_definition
      case symbol_kind::S_taggedunion_type_name: // taggedunion_type_name
      case symbol_kind::S_taggedunion_member: // taggedunion_member
        value.template destroy< a2l::A2mlObject > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.template destroy< double > ();
        break;

      case symbol_kind::S_CONSTANT: // CONSTANT
        value.template destroy< int64_t > ();
        break;

      case symbol_kind::S_enumerator: // enumerator
        value.template destroy< std::pair<int64_t, std::string> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_keyword: // keyword
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_tag: // tag
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if A2MLDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return A2mlParser::symbol_name (this->kind ());
      }
#endif // #if A2MLDEBUG || 0


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
    };

    /// Build a parser object.
    A2mlParser (a2l::A2mlScanner &scanner_yyarg);
    virtual ~A2mlParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    A2mlParser (const A2mlParser&) = delete;
    /// Non copyable.
    A2mlParser& operator= (const A2mlParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if A2MLDEBUG
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

#if A2MLDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if A2MLDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2MLEOF ()
      {
        return symbol_type (token::A2MLEOF);
      }
#else
      static
      symbol_type
      make_A2MLEOF ()
      {
        return symbol_type (token::A2MLEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2MLerror ()
      {
        return symbol_type (token::A2MLerror);
      }
#else
      static
      symbol_type
      make_A2MLerror ()
      {
        return symbol_type (token::A2MLerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2MLUNDEF ()
      {
        return symbol_type (token::A2MLUNDEF);
      }
#else
      static
      symbol_type
      make_A2MLUNDEF ()
      {
        return symbol_type (token::A2MLUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2ML_BEGIN ()
      {
        return symbol_type (token::A2ML_BEGIN);
      }
#else
      static
      symbol_type
      make_A2ML_BEGIN ()
      {
        return symbol_type (token::A2ML_BEGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2ML_END ()
      {
        return symbol_type (token::A2ML_END);
      }
#else
      static
      symbol_type
      make_A2ML_END ()
      {
        return symbol_type (token::A2ML_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_A2ML ()
      {
        return symbol_type (token::A2ML);
      }
#else
      static
      symbol_type
      make_A2ML ()
      {
        return symbol_type (token::A2ML);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_BEGIN ()
      {
        return symbol_type (token::ARRAY_BEGIN);
      }
#else
      static
      symbol_type
      make_ARRAY_BEGIN ()
      {
        return symbol_type (token::ARRAY_BEGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_END ()
      {
        return symbol_type (token::ARRAY_END);
      }
#else
      static
      symbol_type
      make_ARRAY_END ()
      {
        return symbol_type (token::ARRAY_END);
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
      make_CHAR ()
      {
        return symbol_type (token::CHAR);
      }
#else
      static
      symbol_type
      make_CHAR ()
      {
        return symbol_type (token::CHAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONSTANT (int64_t v)
      {
        return symbol_type (token::CONSTANT, std::move (v));
      }
#else
      static
      symbol_type
      make_CONSTANT (const int64_t& v)
      {
        return symbol_type (token::CONSTANT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEF_END ()
      {
        return symbol_type (token::DEF_END);
      }
#else
      static
      symbol_type
      make_DEF_END ()
      {
        return symbol_type (token::DEF_END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOUBLE ()
      {
        return symbol_type (token::DOUBLE);
      }
#else
      static
      symbol_type
      make_DOUBLE ()
      {
        return symbol_type (token::DOUBLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENUM ()
      {
        return symbol_type (token::ENUM);
      }
#else
      static
      symbol_type
      make_ENUM ()
      {
        return symbol_type (token::ENUM);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL ()
      {
        return symbol_type (token::EQUAL);
      }
#else
      static
      symbol_type
      make_EQUAL ()
      {
        return symbol_type (token::EQUAL);
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
      make_INT ()
      {
        return symbol_type (token::INT);
      }
#else
      static
      symbol_type
      make_INT ()
      {
        return symbol_type (token::INT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT64 ()
      {
        return symbol_type (token::INT64);
      }
#else
      static
      symbol_type
      make_INT64 ()
      {
        return symbol_type (token::INT64);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LONG ()
      {
        return symbol_type (token::LONG);
      }
#else
      static
      symbol_type
      make_LONG ()
      {
        return symbol_type (token::LONG);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEM_BEGIN ()
      {
        return symbol_type (token::MEM_BEGIN);
      }
#else
      static
      symbol_type
      make_MEM_BEGIN ()
      {
        return symbol_type (token::MEM_BEGIN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEM_END ()
      {
        return symbol_type (token::MEM_END);
      }
#else
      static
      symbol_type
      make_MEM_END ()
      {
        return symbol_type (token::MEM_END);
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
      make_STRUCT ()
      {
        return symbol_type (token::STRUCT);
      }
#else
      static
      symbol_type
      make_STRUCT ()
      {
        return symbol_type (token::STRUCT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAGGED_STRUCT ()
      {
        return symbol_type (token::TAGGED_STRUCT);
      }
#else
      static
      symbol_type
      make_TAGGED_STRUCT ()
      {
        return symbol_type (token::TAGGED_STRUCT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TAGGED_UNION ()
      {
        return symbol_type (token::TAGGED_UNION);
      }
#else
      static
      symbol_type
      make_TAGGED_UNION ()
      {
        return symbol_type (token::TAGGED_UNION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TEXT_ARRAY ()
      {
        return symbol_type (token::TEXT_ARRAY);
      }
#else
      static
      symbol_type
      make_TEXT_ARRAY ()
      {
        return symbol_type (token::TEXT_ARRAY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UCHAR ()
      {
        return symbol_type (token::UCHAR);
      }
#else
      static
      symbol_type
      make_UCHAR ()
      {
        return symbol_type (token::UCHAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT ()
      {
        return symbol_type (token::UINT);
      }
#else
      static
      symbol_type
      make_UINT ()
      {
        return symbol_type (token::UINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UINT64 ()
      {
        return symbol_type (token::UINT64);
      }
#else
      static
      symbol_type
      make_UINT64 ()
      {
        return symbol_type (token::UINT64);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ULONG ()
      {
        return symbol_type (token::ULONG);
      }
#else
      static
      symbol_type
      make_ULONG ()
      {
        return symbol_type (token::ULONG);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    A2mlParser (const A2mlParser&);
    /// Non copyable.
    A2mlParser& operator= (const A2mlParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

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

#if A2MLDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if A2MLDEBUG || 0


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
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if A2MLDEBUG
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
      yylast_ = 198,     ///< Last index in yytable_.
      yynnts_ = 26,  ///< Number of nonterminal symbols.
      yyfinal_ = 4 ///< Termination state number.
    };


    // User arguments.
    a2l::A2mlScanner &scanner;

  };


#line 6 "/home/ihedvall/CLionProjects/a2llib/src/a2mlparser.y"
} // a2l
#line 1871 "/home/ihedvall/CLionProjects/a2llib/src/a2mlparser.hpp"




#endif // !YY_A2ML_HOME_IHEDVALL_CLIONPROJECTS_A2LLIB_SRC_A2MLPARSER_HPP_INCLUDED
