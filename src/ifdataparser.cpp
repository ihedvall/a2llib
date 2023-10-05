// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   ifdatalex



#include "ifdataparser.hpp"


// Unqualified %code blocks.
#line 26 "D:/projects/a2llib/src/ifdataparser.y"

    #include <sstream>
    #include "ifdatascanner.h"


    #include "a2lhelper.h"
    #include <limits>

    #undef yylex
    #define yylex scanner.ifdatalex

#line 60 "D:/projects/a2llib/src/ifdataparser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if IFDATADEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !IFDATADEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !IFDATADEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "D:/projects/a2llib/src/ifdataparser.y"
namespace a2l {
#line 134 "D:/projects/a2llib/src/ifdataparser.cpp"

  /// Build a parser object.
  IfDataParser::IfDataParser (a2l::IfDataScanner &scanner_yyarg)
#if IFDATADEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  IfDataParser::~IfDataParser ()
  {}

  IfDataParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  IfDataParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_block_data: // block_data
        value.copy< a2l::IfDataItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        value.copy< std::vector<a2l::IfDataItem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.copy< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  IfDataParser::symbol_kind_type
  IfDataParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  IfDataParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  IfDataParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_block_data: // block_data
        value.move< a2l::IfDataItem > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        value.move< std::vector<a2l::IfDataItem> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  IfDataParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  IfDataParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  IfDataParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  IfDataParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  IfDataParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  IfDataParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  IfDataParser::symbol_kind_type
  IfDataParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  IfDataParser::symbol_kind_type
  IfDataParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  IfDataParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  IfDataParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  IfDataParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  IfDataParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  IfDataParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  IfDataParser::symbol_kind_type
  IfDataParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  IfDataParser::stack_symbol_type::stack_symbol_type ()
  {}

  IfDataParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_block_data: // block_data
        value.YY_MOVE_OR_COPY< a2l::IfDataItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        value.YY_MOVE_OR_COPY< std::vector<a2l::IfDataItem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.YY_MOVE_OR_COPY< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  IfDataParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_block_data: // block_data
        value.move< a2l::IfDataItem > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        value.move< std::vector<a2l::IfDataItem> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  IfDataParser::stack_symbol_type&
  IfDataParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_block_data: // block_data
        value.copy< a2l::IfDataItem > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        value.copy< std::vector<a2l::IfDataItem> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.copy< uint64_t > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  IfDataParser::stack_symbol_type&
  IfDataParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_block_data: // block_data
        value.move< a2l::IfDataItem > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        value.move< std::vector<a2l::IfDataItem> > (that.value);
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        value.move< uint64_t > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  IfDataParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if IFDATADEBUG
  template <typename Base>
  void
  IfDataParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  IfDataParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  IfDataParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  IfDataParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if IFDATADEBUG
  std::ostream&
  IfDataParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  IfDataParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  IfDataParser::debug_level_type
  IfDataParser::debug_level () const
  {
    return yydebug_;
  }

  void
  IfDataParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // IFDATADEBUG

  IfDataParser::state_type
  IfDataParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  IfDataParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  IfDataParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  IfDataParser::operator() ()
  {
    return parse ();
  }

  int
  IfDataParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_block_data: // block_data
        yylhs.value.emplace< a2l::IfDataItem > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_protocol: // protocol
      case symbol_kind::S_block_name: // block_name
      case symbol_kind::S_item_value: // item_value
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_block_data_list: // block_data_list
      case symbol_kind::S_item_list: // item_list
        yylhs.value.emplace< std::vector<a2l::IfDataItem> > ();
        break;

      case symbol_kind::S_UINT: // UINT
      case symbol_kind::S_HEX: // HEX
        yylhs.value.emplace< uint64_t > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 3: // if_data_block: IF_DATA_BEGIN IF_DATA protocol block_data_list IF_DATA_END IF_DATA
#line 62 "D:/projects/a2llib/src/ifdataparser.y"
                                                                         {
        scanner.Protocol(yystack_[3].value.as < std::string > ());
        scanner.ItemList(yystack_[2].value.as < std::vector<a2l::IfDataItem> > ());
    }
#line 822 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 4: // protocol: IDENT
#line 67 "D:/projects/a2llib/src/ifdataparser.y"
          { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 828 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 5: // block_data_list: %empty
#line 69 "D:/projects/a2llib/src/ifdataparser.y"
                        {}
#line 834 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 6: // block_data_list: block_data_list block_data
#line 70 "D:/projects/a2llib/src/ifdataparser.y"
                                 {
        yylhs.value.as < std::vector<a2l::IfDataItem> > () = yystack_[1].value.as < std::vector<a2l::IfDataItem> > ();
        yylhs.value.as < std::vector<a2l::IfDataItem> > ().emplace_back(yystack_[0].value.as < a2l::IfDataItem > ());
    }
#line 843 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 7: // block_data_list: block_data_list item_value
#line 74 "D:/projects/a2llib/src/ifdataparser.y"
                                 {
        yylhs.value.as < std::vector<a2l::IfDataItem> > () = yystack_[1].value.as < std::vector<a2l::IfDataItem> > ();
        IfDataItem item;
        item.Value = yystack_[0].value.as < std::string > ();
        yylhs.value.as < std::vector<a2l::IfDataItem> > ().emplace_back(yystack_[0].value.as < std::string > ());
    }
#line 854 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 8: // block_data: IF_DATA_BEGIN block_name item_list IF_DATA_END block_name
#line 81 "D:/projects/a2llib/src/ifdataparser.y"
                                                                      {
    IfDataItem block;
    block.BlockName = yystack_[3].value.as < std::string > ();
    block.ItemList = yystack_[2].value.as < std::vector<a2l::IfDataItem> > ();
    yylhs.value.as < a2l::IfDataItem > () = block;
}
#line 865 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 9: // block_name: IDENT
#line 88 "D:/projects/a2llib/src/ifdataparser.y"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 871 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 10: // item_list: %empty
#line 90 "D:/projects/a2llib/src/ifdataparser.y"
                  {}
#line 877 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 11: // item_list: item_list block_data
#line 91 "D:/projects/a2llib/src/ifdataparser.y"
                           {
        yylhs.value.as < std::vector<a2l::IfDataItem> > () = yystack_[1].value.as < std::vector<a2l::IfDataItem> > ();
        yylhs.value.as < std::vector<a2l::IfDataItem> > ().emplace_back(yystack_[0].value.as < a2l::IfDataItem > ());
    }
#line 886 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 12: // item_list: item_list item_value
#line 95 "D:/projects/a2llib/src/ifdataparser.y"
                           {
        yylhs.value.as < std::vector<a2l::IfDataItem> > () = yystack_[1].value.as < std::vector<a2l::IfDataItem> > ();
        IfDataItem item;
        item.Value = yystack_[0].value.as < std::string > ();
        yylhs.value.as < std::vector<a2l::IfDataItem> > ().emplace_back(yystack_[0].value.as < std::string > ());
    }
#line 897 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 13: // item_value: IDENT
#line 102 "D:/projects/a2llib/src/ifdataparser.y"
                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 903 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 14: // item_value: STRING
#line 103 "D:/projects/a2llib/src/ifdataparser.y"
             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 909 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 15: // item_value: HEX
#line 104 "D:/projects/a2llib/src/ifdataparser.y"
          { yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ()); }
#line 915 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 16: // item_value: UINT
#line 105 "D:/projects/a2llib/src/ifdataparser.y"
           { yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < uint64_t > ()); }
#line 921 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 17: // item_value: INT
#line 106 "D:/projects/a2llib/src/ifdataparser.y"
          { yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < int64_t > ()); }
#line 927 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;

  case 18: // item_value: FLOAT
#line 107 "D:/projects/a2llib/src/ifdataparser.y"
            { yylhs.value.as < std::string > () = std::to_string(yystack_[0].value.as < double > ()); }
#line 933 "D:/projects/a2llib/src/ifdataparser.cpp"
    break;


#line 937 "D:/projects/a2llib/src/ifdataparser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  IfDataParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if IFDATADEBUG || 0
  const char *
  IfDataParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if IFDATADEBUG || 0









  const signed char IfDataParser::yypact_ninf_ = -4;

  const signed char IfDataParser::yytable_ninf_ = -1;

  const signed char
  IfDataParser::yypact_[] =
  {
       4,     8,    16,    10,    -4,    -4,    -4,    -3,    11,    12,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,     6,    11,    -4,    -4,    -4
  };

  const signed char
  IfDataParser::yydefact_[] =
  {
       2,     0,     0,     0,     1,     4,     5,     0,     0,     0,
      16,    15,    17,    18,    13,    14,     6,     7,     9,    10,
       3,     0,     0,    11,    12,     8
  };

  const signed char
  IfDataParser::yypgoto_[] =
  {
      -4,    -4,    -4,    -4,     0,     1,    -4,     3
  };

  const signed char
  IfDataParser::yydefgoto_[] =
  {
       0,     2,     6,     7,    16,    19,    21,    17
  };

  const signed char
  IfDataParser::yytable_[] =
  {
       8,     9,    10,    11,    12,    13,    14,     1,    15,     8,
      22,    10,    11,    12,    13,    14,     4,    15,     3,     5,
      18,    23,    20,    25,    24
  };

  const signed char
  IfDataParser::yycheck_[] =
  {
       3,     4,     5,     6,     7,     8,     9,     3,    11,     3,
       4,     5,     6,     7,     8,     9,     0,    11,    10,     9,
       9,    21,    10,    22,    21
  };

  const signed char
  IfDataParser::yystos_[] =
  {
       0,     3,    13,    10,     0,     9,    14,    15,     3,     4,
       5,     6,     7,     8,     9,    11,    16,    19,     9,    17,
      10,    18,     4,    16,    19,    17
  };

  const signed char
  IfDataParser::yyr1_[] =
  {
       0,    12,    13,    13,    14,    15,    15,    15,    16,    17,
      18,    18,    18,    19,    19,    19,    19,    19,    19
  };

  const signed char
  IfDataParser::yyr2_[] =
  {
       0,     2,     0,     6,     1,     0,     2,     2,     5,     1,
       0,     2,     2,     1,     1,     1,     1,     1,     1
  };


#if IFDATADEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const IfDataParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "IF_DATA_BEGIN",
  "IF_DATA_END", "UINT", "HEX", "INT", "FLOAT", "IDENT", "IF_DATA",
  "STRING", "$accept", "if_data_block", "protocol", "block_data_list",
  "block_data", "block_name", "item_list", "item_value", YY_NULLPTR
  };
#endif


#if IFDATADEBUG
  const signed char
  IfDataParser::yyrline_[] =
  {
       0,    61,    61,    62,    67,    69,    70,    74,    81,    88,
      90,    91,    95,   102,   103,   104,   105,   106,   107
  };

  void
  IfDataParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  IfDataParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // IFDATADEBUG

  IfDataParser::symbol_kind_type
  IfDataParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11
    };
    // Last valid token kind.
    const int code_max = 266;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/ifdataparser.y"
} // a2l
#line 1296 "D:/projects/a2llib/src/ifdataparser.cpp"

#line 110 "D:/projects/a2llib/src/ifdataparser.y"


void a2l::IfDataParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
