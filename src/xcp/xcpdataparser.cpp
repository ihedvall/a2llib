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
#define yylex   xcplex



#include "xcpdataparser.hpp"


// Unqualified %code blocks.
#line 26 "D:/projects/a2llib/src/xcp/xcpdataparser.y"

    #include <sstream>
    #include <limits>
    #include "xcpdatascanner.h"


    #undef yylex
    #define yylex scanner.xcplex

#line 58 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"


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
#if XCPDEBUG

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

#else // !XCPDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !XCPDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
namespace a2l { namespace xcp {
#line 132 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

  /// Build a parser object.
  XcpDataParser::XcpDataParser (a2l::xcp::XcpDataScanner &scanner_yyarg)
#if XCPDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  XcpDataParser::~XcpDataParser ()
  {}

  XcpDataParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  XcpDataParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.copy< std::string > (YY_MOVE (that.value));
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
  XcpDataParser::symbol_kind_type
  XcpDataParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  XcpDataParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  XcpDataParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (YY_MOVE (s.value));
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
  XcpDataParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  XcpDataParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  XcpDataParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  XcpDataParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  XcpDataParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  XcpDataParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  XcpDataParser::symbol_kind_type
  XcpDataParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  XcpDataParser::symbol_kind_type
  XcpDataParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  XcpDataParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  XcpDataParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  XcpDataParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  XcpDataParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  XcpDataParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  XcpDataParser::symbol_kind_type
  XcpDataParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  XcpDataParser::stack_symbol_type::stack_symbol_type ()
  {}

  XcpDataParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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

  XcpDataParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (YY_MOVE (that.value));
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
  XcpDataParser::stack_symbol_type&
  XcpDataParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.copy< std::string > (that.value);
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

  XcpDataParser::stack_symbol_type&
  XcpDataParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (that.value);
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
  XcpDataParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if XCPDEBUG
  template <typename Base>
  void
  XcpDataParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  XcpDataParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  XcpDataParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  XcpDataParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if XCPDEBUG
  std::ostream&
  XcpDataParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  XcpDataParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  XcpDataParser::debug_level_type
  XcpDataParser::debug_level () const
  {
    return yydebug_;
  }

  void
  XcpDataParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // XCPDEBUG

  XcpDataParser::state_type
  XcpDataParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  XcpDataParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  XcpDataParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  XcpDataParser::operator() ()
  {
    return parse ();
  }

  int
  XcpDataParser::parse ()
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
      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        yylhs.value.emplace< std::string > ();
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
  case 353: // daq_list_type: DAQ
#line 600 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "DAQ"; }
#line 754 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 354: // daq_list_type: STIM
#line 601 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < std::string > () = "STIM"; }
#line 760 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 355: // daq_list_type: DAQ_STIM
#line 602 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = "DAQ_STIM"; }
#line 766 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 356: // transport_layer_instance: %empty
#line 603 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::string > ().clear(); }
#line 772 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 357: // transport_layer_instance: TRANSPORT_LAYER_INSTANCE STRING
#line 604 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 778 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 358: // ident_or_string: IDENT
#line 605 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 784 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 359: // ident_or_string: STRING
#line 606 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 790 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;


#line 794 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

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
  XcpDataParser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if XCPDEBUG || 0
  const char *
  XcpDataParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if XCPDEBUG || 0









  const short XcpDataParser::yypact_ninf_ = -687;

  const signed char XcpDataParser::yytable_ninf_ = -1;

  const short
  XcpDataParser::yypact_[] =
  {
      17,   -43,    50,   -22,  -687,  -687,  -121,    42,    61,  -687,
      -2,   152,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,    61,
    -687,   -88,   -50,   -40,   -42,    15,    41,     5,    48,    54,
      68,    78,    80,    90,  -687,    92,  -687,  -687,   177,  -687,
    -687,   136,    96,   104,  -687,   106,  -687,  -687,    74,   107,
      74,   108,    74,   113,    74,   116,   121,    56,   123,   224,
     278,   253,  -687,   289,   131,   134,    -5,   137,   172,    16,
     135,   302,  -687,   303,  -687,   313,  -687,   314,   160,   156,
     222,   165,   159,  -687,  -687,   166,   168,  -687,    24,  -687,
    -687,   214,  -687,   169,    26,   209,    86,   170,   173,   174,
     171,  -687,  -687,  -687,  -687,  -687,  -687,  -687,   182,   318,
     188,  -687,   184,    -1,   185,   191,   192,  -687,   194,   197,
    -687,   198,  -687,   189,   201,   199,   208,   206,  -687,  -687,
    -687,  -687,  -687,  -687,   204,    -6,   181,   117,   219,   212,
     216,   215,   183,  -687,  -687,   210,  -687,  -687,  -687,  -687,
    -687,    36,   220,    86,  -687,  -687,   245,   379,   221,  -687,
    -687,  -687,  -687,  -687,   223,   225,  -687,  -687,  -687,   227,
     229,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,   218,  -687,  -687,  -687,  -687,  -687,  -687,
     230,  -687,  -687,   231,   233,   235,   232,   241,   238,   239,
    -687,  -687,  -687,   240,   242,   243,   244,   246,   247,   248,
    -687,  -687,  -687,   250,   256,   254,    13,    18,    31,   -18,
     266,  -687,  -687,  -687,   257,   384,   187,  -687,  -687,   310,
     245,  -687,  -687,   259,    -9,  -687,  -687,   258,   389,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,   260,   261,   395,   375,   353,   262,
    -687,   263,   394,   281,   363,  -687,   268,  -687,   415,    34,
     269,   416,   270,   271,  -687,   272,   273,   274,   275,   276,
     277,  -687,  -687,   -11,     9,   422,  -687,  -687,    53,   279,
     -81,  -687,  -687,  -687,   282,   284,  -687,   285,  -687,   286,
     428,     2,   309,   287,  -687,  -687,  -687,  -687,   288,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,   404,   290,
    -687,  -687,  -687,   387,  -687,   378,  -687,   291,   251,   293,
     292,   294,  -687,  -687,  -687,  -687,   295,   296,   300,   301,
     297,  -687,  -687,   304,   299,   305,  -687,  -687,   306,  -687,
    -687,  -687,   307,  -687,   308,   311,   311,   311,   311,   311,
    -687,  -687,  -687,     6,  -687,   315,   316,   317,   405,   320,
    -687,   319,   321,   322,   396,   323,   452,   455,   469,   470,
     472,   228,   327,   324,  -687,  -687,    59,  -687,   325,   326,
    -687,   328,   329,    20,   330,   331,   473,   333,   419,   335,
     409,   420,   408,   388,   390,   337,   337,   337,  -687,  -687,
      11,   471,   338,   339,   343,  -687,   344,   345,   346,   347,
     348,   349,   350,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,   155,   351,   334,   352,   512,
     501,   354,   355,   357,  -687,   356,   358,   453,  -687,   361,
     522,   364,  -687,  -687,  -687,  -687,  -687,  -687,   523,   525,
     526,   367,   368,   369,    39,   366,   371,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,   503,   373,
    -687,   370,   544,  -687,  -687,  -687,  -687,   468,   374,  -687,
    -687,   505,   376,     3,   467,   474,   426,   380,  -687,   382,
    -687,  -687,    39,   386,   383,  -687,   548,   385,  -687,   391,
     550,   392,  -687,   393,   -48,   -56,  -687,  -687,  -687,  -687,
    -687,  -687,   552,   312,   398,   399,   547,   397,   427,  -687,
    -687,   442,   400,   436,  -687,  -687,   402,   403,  -687,   542,
     449,   534,   -31,  -687,   407,   410,   411,   412,  -687,   413,
     -31,  -687,   478,   423,  -687,   193,  -687,   417,   418,  -687,
      38,    57,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,   421,   424,   425,   569,  -687,
     575,   482,   447,  -687,   581,  -687,   507,   -55,   -45,   -45,
     211,  -687,  -687,  -687,  -687,  -687,   429,   430,   431,   432,
     433,   434,   435,  -687,   196,   440,   441,  -687,   450,   443,
     444,  -687,   448,   445,  -687,   438,   517,  -687,   446,   518,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
     490,   476,  -687,   594,   451,  -687,  -687,   454,   456,   439,
    -687,   457,  -687,  -687,   458,  -687,   459,  -687,   605,   608,
     460,   461,   462,   609,  -687,  -687,  -687,   463,   574,  -687,
     464,   465,   599,     4,   475,  -687,   167,   613,   615,  -687,
     524,   477,  -687,   617,   205,   572,   479,   466,   480,   481,
     483,  -687,   484,  -687,  -687,   485,   486,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,   533,   488,  -687,   489,   630,
     487,   491,   492,   493,   494,  -687,   497,  -687,  -687,  -687,
    -687,  -687,   499,  -687,  -687,  -687,   500,  -687,   498,   502,
     504,   506,   508,  -687,  -687,   510,   511,   513,   514,   515,
     509,   519,   634,   634,   635,   635,   520,  -687,    28,   217,
    -687,  -687,  -687,   226,  -687,  -687,  -687,   616,   249,  -687,
    -687,   255,  -687,  -687,  -687,   521,   527,   614,  -687,   618,
    -687,   625,  -687,   626,  -687,    88,   528,   529,  -687,  -687,
    -687,  -687,   530,   604,  -687,   642,   653,  -687,  -687,   643,
     560,  -687,  -687
  };

  const short
  XcpDataParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     5,     0,     0,     4,     5,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     3,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,   196,   159,     0,   155,
     156,   165,     0,     0,    25,     0,   191,   201,   356,     0,
     356,     0,   356,     0,   356,     0,     0,     0,     0,   157,
     158,     0,   166,     0,     0,     0,     0,     0,     0,   200,
       0,     0,   246,     0,   261,     0,   273,     0,     0,     0,
       0,     0,     0,   352,   350,     0,     0,   197,     0,   160,
     154,     0,   168,     0,     0,     0,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,     0,     0,
       0,   192,     0,     0,     0,     0,     0,   205,     0,     0,
     214,     0,   218,     0,     0,     0,     0,     0,   221,   202,
     215,   216,   219,   357,     0,     0,     0,   260,     0,   272,
       0,     0,     0,   348,   351,     0,   198,   196,   196,   196,
     164,     0,     0,     0,    48,    23,    41,     0,     0,    35,
      46,    33,    34,    45,     0,     0,   190,   208,   232,     0,
       0,   211,   203,   204,   206,   207,   217,   220,   209,   210,
     212,   213,   199,     0,   249,   250,   251,   252,   253,   254,
       0,   247,   244,     0,     0,     0,     0,     0,     0,     0,
     270,   262,   259,     0,     0,     0,     0,     0,     0,     0,
     282,   274,   271,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   169,   170,     0,     0,     0,    42,    37,    43,
      41,    39,   174,     0,     0,   223,   228,     0,   255,   264,
     263,   265,   266,   267,   269,   268,   276,   275,   277,   278,
     279,   281,   280,   284,     0,     0,     0,     0,     0,     0,
     167,     0,     0,     0,     0,    49,     0,    40,     0,     0,
       0,     0,     0,     0,   240,     0,     0,     0,     0,     0,
       0,   243,   233,     0,     0,   257,   256,   245,     0,     0,
       0,   161,   163,   162,     0,     0,    36,     0,    47,     0,
       0,     0,     0,     0,   175,   176,   178,   179,     0,   231,
     237,   235,   234,   236,   241,   238,   239,   242,     0,     0,
     225,   224,   226,     0,   229,     0,   248,     0,     0,     0,
       0,     0,   295,   285,   293,   305,     0,     0,     0,     0,
       0,    44,    38,     0,     0,     0,   173,   177,     0,   222,
     230,   227,     0,   288,     0,     0,     0,     0,     0,     0,
     283,   289,   294,     0,    58,     0,     0,     0,    51,     0,
     181,     0,     0,     0,   297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,   306,     0,    58,     0,     0,
      52,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   304,   310,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,    65,    68,    61,    62,    63,    59,    66,
      67,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,     0,     0,   298,     0,
       0,     0,   291,   292,   287,   290,   286,   313,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    77,    76,
      60,    69,    71,    74,    75,    73,    72,    70,     0,     0,
      24,     0,     0,   180,   184,   183,   185,   188,     0,   258,
     300,     0,     0,   312,     0,     0,     0,     0,    94,     0,
     358,   359,     0,     0,     0,    56,     0,     0,   187,     0,
       0,     0,   296,     0,     0,     0,   314,   316,   317,   307,
     308,   309,     0,     0,     0,     0,    83,     0,     0,    53,
     189,     0,     0,   302,   321,   340,     0,     0,   315,     0,
       0,     0,     0,   101,     0,     0,     0,     0,    95,     0,
       0,    84,    85,    88,   172,     0,   186,     0,     0,   301,
       0,     0,   318,   319,    90,   103,    93,   353,   355,   354,
      96,   100,    99,    97,    98,     0,     0,     0,     0,    89,
       0,     0,     0,    54,   194,   303,     0,     0,     0,     0,
       0,   322,   323,   324,   325,   326,     0,     0,     0,     0,
       0,     0,     0,   341,     0,     0,     0,    86,     0,     0,
       0,    50,     0,     0,   320,     0,   333,   330,     0,   337,
     329,   327,   328,   339,   342,   345,   344,   347,   343,   346,
       0,     0,   104,     0,     0,    82,    87,     0,     0,     0,
     331,     0,   332,   335,     0,   336,     0,   102,     0,     0,
       0,     0,     0,     0,   334,   338,   106,     0,     0,   110,
       0,     0,     0,     0,     0,    91,     0,     0,     0,   193,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,   118,     0,   120,   114,     0,     0,   116,   121,   111,
     122,   126,   127,   128,   129,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,   109,     0,   113,   112,   125,
     117,   119,     0,   115,    55,   195,     0,    92,     0,     0,
       0,     0,     0,   124,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,     0,
     135,   137,   138,     0,   140,   142,   143,     0,     0,   146,
     148,     0,   150,   152,   131,     0,     0,     0,   136,     0,
     141,     0,   147,     0,   151,     0,     0,     0,   134,   139,
     145,   149,     0,     0,   132,     0,     0,   133,   130,     0,
       0,   153,   144
  };

  const short
  XcpDataParser::yypgoto_[] =
  {
    -687,  -687,  -687,   668,  -687,   -67,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,   535,   516,   495,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,   298,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,   -68,  -687,  -687,   -69,  -686,  -687,  -687,   -70,
    -687,  -687,   -64,  -525,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,   -54,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
     414,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
    -687,  -687,  -687,  -687,  -119,  -687,  -687,  -687,  -687,  -143,
    -687,  -687,  -687,  -687,  -687,    98,  -687,  -687,  -687,  -687,
    -687,  -687,   100,  -687,  -687,  -687,  -687,  -687,  -687,  -687,
     141,   114,   190
  };

  const short
  XcpDataParser::yydefgoto_[] =
  {
       0,     2,     7,     8,    12,    13,    14,    15,    54,    76,
     111,   112,   113,   114,   169,   238,   239,   277,   115,   116,
     117,   236,   275,   401,   565,   593,    16,   396,   438,   439,
     562,   588,   440,   590,   441,   442,   659,   443,   533,   558,
     614,   642,   673,   682,   444,   676,   699,   700,   775,   784,
     701,   749,   750,   702,   753,   754,   751,   703,   758,   759,
     704,   761,   762,   752,    17,    48,    49,    50,    70,    99,
      18,    73,    19,   161,   232,   233,    20,   279,   314,   315,
     403,   454,   316,   317,   520,    21,    78,   121,   623,    69,
      97,    22,    58,    79,   139,   140,   293,   331,   141,   294,
     332,   142,   244,   292,    23,    60,   145,   201,   297,   336,
      24,    62,   147,   211,    25,    64,   149,   221,    26,   298,
     343,   344,   408,   460,   386,   569,    27,   373,   395,   468,
     503,   526,   548,   527,   570,   601,   602,   603,   604,   605,
     627,   652,   630,   655,   528,   571,   613,    28,    67,    94,
     580,    81,   512
  };

  const short
  XcpDataParser::yytable_[] =
  {
      93,   193,   328,    90,   281,   282,   353,   104,   105,   283,
     163,   577,   138,   546,   625,   524,   178,   680,   391,   392,
      46,   578,   333,   106,   628,   122,   266,   354,   123,     1,
     124,   267,   157,   450,     3,   125,   126,   127,   128,   129,
     544,    31,   471,    32,   268,   179,   311,   312,   229,   230,
       4,   596,     9,   158,   163,    10,   472,   755,   329,   337,
     473,   765,   597,   180,   106,   338,   339,   755,    90,    91,
     606,   420,   421,    11,   474,    30,    96,   159,   329,   598,
     210,    96,   220,   284,   607,   285,   164,   451,   313,    45,
     107,   422,   346,   782,    96,   423,   347,   166,   167,   608,
     525,   783,   424,   226,   227,   228,   547,   626,   130,   131,
     452,   599,    47,   108,   109,   579,   425,   629,   681,   609,
     203,   269,   132,    33,   545,    34,   393,   355,   286,    90,
      35,   453,   287,    51,   288,    52,   133,   110,   340,    36,
     289,     5,     6,   766,   194,   195,   196,   197,   198,   199,
     426,   330,   290,   134,   135,   600,    37,   475,   427,   136,
     428,   429,   430,   431,   432,   137,    92,   420,   488,   610,
     476,   200,   168,   341,    83,   433,    85,   291,    87,   684,
     685,   296,    56,   686,   119,   120,   434,   422,    53,   435,
      71,   423,   611,   204,    31,   436,    32,   687,   424,   273,
     274,   688,   689,   612,   205,   591,   592,   437,   640,   641,
     206,    72,   425,   207,    55,   213,   510,   511,   756,   760,
     763,    57,   690,   691,    90,   692,   693,    59,   756,   748,
     767,   342,   694,   760,    80,   597,   763,   208,   748,   769,
     209,    61,   710,   711,   712,   713,   426,   387,   388,   389,
     390,    63,   598,    65,   427,   714,   428,   429,   430,   431,
     432,   757,   771,    66,    31,    68,    32,   757,   773,    74,
      31,   433,    32,   469,   470,   695,    33,    75,    34,    77,
      82,    84,   434,    35,   599,   435,    86,    96,   214,    88,
      98,   436,    36,    31,    89,    32,    95,   100,   364,   215,
     696,   697,   101,   437,   102,   216,   394,   103,   217,    37,
     118,   415,   416,   143,   698,   144,   146,    38,    39,    40,
      41,    42,    43,    44,   550,   551,   148,   150,   600,   365,
     366,   367,   218,   151,   152,   219,   153,   154,   160,   155,
     165,   156,   162,   170,   175,   176,    33,   202,    34,   173,
     171,   172,    33,    35,    34,   174,   417,   177,   181,    35,
     552,   224,    36,   553,   182,   183,   187,   184,    36,   192,
     185,   186,   368,   369,   188,    33,   189,    34,   554,    37,
     555,   190,    35,   191,   222,    37,   212,   225,   223,   237,
     240,    36,   270,   234,   241,   247,   242,   272,   243,   276,
     245,    90,   246,   301,   302,   252,   303,   248,    37,   249,
     556,   250,   557,   251,   253,   254,   255,   259,   256,   260,
     257,   258,   306,   308,   261,   262,   307,   263,   310,   264,
     271,   265,   280,   319,   335,   295,   305,   299,   300,   352,
     304,   309,   318,   320,   321,   322,   323,   324,   325,   356,
     359,   361,   362,   326,   327,   348,   345,   349,   350,   351,
     357,   358,   370,   360,   363,   410,   400,   407,   411,   375,
     371,   372,   374,   376,   377,   378,   380,   379,   381,   382,
     383,   384,   412,   413,   385,   414,   457,   462,   464,   398,
     399,   459,   397,   402,   405,   406,   404,   418,   446,   463,
     409,   419,   449,   447,   456,   448,   458,   455,   461,   465,
     467,   490,   466,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   489,   492,   493,   499,   495,   491,
     496,   498,   494,   497,   500,   501,   504,   502,   505,   506,
     507,   508,   509,   513,   514,   515,   516,   517,   518,   519,
     529,   521,   522,   523,   531,   534,   532,   561,   530,   536,
     537,   538,   539,   541,   540,   549,   564,   566,   568,   542,
     543,   559,   560,   574,   563,   572,   573,   567,   575,   576,
     581,   589,   618,   582,   583,   584,   585,   587,   619,   620,
     594,   595,   621,   622,   615,   624,   645,   616,   617,   651,
     654,   633,   646,   656,   648,   657,   658,   634,   635,   636,
     637,   638,   639,   643,   644,   650,   663,   647,   649,   653,
     667,   668,   672,   675,   660,   679,   705,   661,   706,   662,
     709,   665,   666,   669,   664,   715,   674,   707,   670,   671,
     724,   677,   678,   717,   725,   727,   748,   757,   683,   765,
     708,   778,   716,   718,   788,   789,   779,   719,   722,   723,
     720,   721,   726,   728,   780,   781,   790,   729,   730,   731,
     733,   732,   734,   735,   736,   792,   791,    29,   737,   235,
     738,   768,   739,   741,   770,   740,   746,   742,   772,   743,
     744,   745,   747,   764,   776,   445,   231,   774,   632,   631,
     777,   586,   535,   787,   785,   786,     0,     0,   334,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278
  };

  const short
  XcpDataParser::yycheck_[] =
  {
      67,     7,    13,    12,    13,    14,     4,    12,    13,    18,
      28,    42,    79,    69,    69,    12,    17,    13,    12,    13,
      70,    52,    13,    28,    69,     9,    13,    25,    12,    12,
      14,    13,     8,    13,    77,    19,    20,    21,    22,    23,
      88,    42,    31,    44,    13,    46,    12,    13,    12,    13,
       0,    13,   173,    29,    28,    13,    45,   743,    69,     6,
      49,    33,    24,    64,    28,    12,    13,   753,    12,    13,
      13,    12,    13,    12,    63,    77,    63,    53,    69,    41,
     147,    63,   149,    92,    27,    94,    60,    67,    54,   177,
      95,    32,   173,     5,    63,    36,   177,    11,    12,    42,
      97,    13,    43,   157,   158,   159,   162,   162,    92,    93,
      90,    73,   162,   118,   119,   146,    57,   162,   114,    62,
       3,   139,   106,   124,   172,   126,   120,   125,   137,    12,
     131,   111,   141,   173,   143,   177,   120,   142,    85,   140,
     149,   163,   164,   115,   150,   151,   152,   153,   154,   155,
      91,   162,   161,   137,   138,   117,   157,   146,    99,   143,
     101,   102,   103,   104,   105,   149,   110,    12,    13,   112,
     159,   177,    86,   120,    60,   116,    62,   244,    64,    12,
      13,   248,   177,    16,    12,    13,   127,    32,   173,   130,
      13,    36,   135,    76,    42,   136,    44,    30,    43,    12,
      13,    34,    35,   146,    87,    12,    13,   148,    12,    13,
      93,    75,    57,    96,   173,     3,   177,   178,   743,   744,
     745,   173,    55,    56,    12,    58,    59,   173,   753,    12,
      13,   298,    65,   758,   160,    24,   761,   120,    12,    13,
     123,   173,    37,    38,    39,    40,    91,   366,   367,   368,
     369,   173,    41,   173,    99,    50,   101,   102,   103,   104,
     105,    12,    13,   173,    42,   173,    44,    12,    13,   173,
      42,   116,    44,   416,   417,   108,   124,   173,   126,   173,
     173,   173,   127,   131,    73,   130,   173,    63,    76,   173,
      12,   136,   140,    42,   173,    44,   173,    44,    47,    87,
     133,   134,    13,   148,   173,    93,   373,   173,    96,   157,
     173,    83,    84,   178,   147,    13,    13,   165,   166,   167,
     168,   169,   170,   171,    12,    13,    13,    13,   117,    78,
      79,    80,   120,   173,   178,   123,   171,   178,   124,   173,
     131,   173,   173,   173,    26,   157,   124,   166,   126,   178,
     177,   177,   124,   131,   126,   173,   128,   173,   173,   131,
      48,   178,   140,    51,   173,   173,   177,   173,   140,   165,
     173,   173,   121,   122,   173,   124,   177,   126,    66,   157,
      68,   173,   131,   177,   168,   157,   167,   177,   173,   144,
      11,   140,   126,   173,   173,   177,   173,    13,   173,    89,
     173,    12,   173,     8,    29,   173,    53,   177,   157,   178,
      98,   178,   100,   178,   173,   177,   177,   173,   178,   173,
     178,   178,    28,    60,   177,   177,   145,   177,    13,   173,
     173,   177,   173,    17,    12,   177,   173,   177,   177,    11,
     178,   173,   173,   173,   173,   173,   173,   173,   173,   140,
      46,    64,    74,   177,   177,   173,   177,   173,   173,   173,
     173,   173,   169,   173,   173,    13,    61,    71,    13,   173,
     178,   177,   177,   173,   173,   178,   177,   173,   173,   173,
     173,   173,    13,    13,   173,    13,    13,    78,    80,   173,
     173,    72,   177,   173,   173,   173,   177,   170,   173,    79,
     177,   177,   173,   177,   173,   177,   173,   177,   173,   121,
     173,   177,   122,    42,   176,   176,   173,   173,   173,   173,
     173,   173,   173,   173,   173,    13,    25,    74,   173,   177,
     173,   173,   178,   177,   173,    13,    13,   173,    13,    13,
     173,   173,   173,   177,   173,    42,   173,   177,     4,    81,
      83,   177,    47,   177,   128,   173,   176,    10,    84,   173,
     177,    13,   177,    13,   173,    13,   139,   125,   132,   177,
     177,   173,   173,    31,   177,   173,   173,   177,   129,    45,
     173,   158,    13,   173,   173,   173,   173,   109,    13,   107,
     173,   173,   145,    12,   173,    88,   146,   173,   173,    82,
      82,   172,   159,   113,   156,   129,    12,   177,   177,   177,
     177,   177,   177,   173,   173,   177,   177,   173,   173,   173,
      15,    13,    13,    49,   173,    26,    13,   173,    13,   173,
      13,   173,   173,   173,   177,    63,   173,   113,   177,   177,
     107,   177,   177,   177,   156,    15,    12,    12,   173,    33,
     173,    37,   173,   173,    50,    13,    38,   176,   173,   173,
     177,   177,   173,   176,    39,    39,    13,   176,   176,   176,
     173,   177,   173,   173,   176,   115,    33,     9,   176,   163,
     176,   749,   176,   173,   753,   177,   177,   176,   758,   176,
     176,   176,   173,   173,   173,   397,   161,   761,   600,   599,
     173,   560,   512,   173,   176,   176,    -1,    -1,   294,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240
  };

  const short
  XcpDataParser::yystos_[] =
  {
       0,    12,   180,    77,     0,   163,   164,   181,   182,   173,
      13,    12,   183,   184,   185,   186,   205,   243,   249,   251,
     255,   264,   270,   283,   289,   293,   297,   305,   326,   182,
      77,    42,    44,   124,   126,   131,   140,   157,   165,   166,
     167,   168,   169,   170,   171,   177,    70,   162,   244,   245,
     246,   173,   177,   173,   187,   173,   177,   173,   271,   173,
     284,   173,   290,   173,   294,   173,   173,   327,   173,   268,
     247,    13,    75,   250,   173,   173,   188,   173,   265,   272,
     160,   330,   173,   330,   173,   330,   173,   330,   173,   173,
      12,    13,   110,   184,   328,   173,    63,   269,    12,   248,
      44,    13,   173,   173,    12,    13,    28,    95,   118,   119,
     142,   189,   190,   191,   192,   197,   198,   199,   173,    12,
      13,   266,     9,    12,    14,    19,    20,    21,    22,    23,
      92,    93,   106,   120,   137,   138,   143,   149,   184,   273,
     274,   277,   280,   178,    13,   285,    13,   291,    13,   295,
      13,   173,   178,   171,   178,   173,   173,     8,    29,    53,
     124,   252,   173,    28,    60,   131,    11,    12,    86,   193,
     173,   177,   177,   178,   173,    26,   157,   173,    17,    46,
      64,   173,   173,   173,   173,   173,   173,   177,   173,   177,
     173,   177,   165,     7,   150,   151,   152,   153,   154,   155,
     177,   286,   166,     3,    76,    87,    93,    96,   120,   123,
     184,   292,   167,     3,    76,    87,    93,    96,   120,   123,
     184,   296,   168,   173,   178,   177,   268,   268,   268,    12,
      13,   192,   253,   254,   173,   193,   200,   144,   194,   195,
      11,   173,   173,   173,   281,   173,   173,   177,   177,   178,
     178,   178,   173,   173,   177,   177,   178,   178,   178,   173,
     173,   177,   177,   177,   173,   177,    13,    13,    13,   139,
     126,   173,    13,    12,    13,   201,    89,   196,   194,   256,
     173,    13,    14,    18,    92,    94,   137,   141,   143,   149,
     161,   184,   282,   275,   278,   177,   184,   287,   298,   177,
     177,     8,    29,    53,   178,   173,    28,   145,    60,   173,
      13,    12,    13,    54,   257,   258,   261,   262,   173,    17,
     173,   173,   173,   173,   173,   173,   177,   177,    13,    69,
     162,   276,   279,    13,   279,    12,   288,     6,    12,    13,
      85,   120,   184,   299,   300,   177,   173,   177,   173,   173,
     173,   173,    11,     4,    25,   125,   140,   173,   173,    46,
     173,    64,    74,   173,    47,    78,    79,    80,   121,   122,
     169,   178,   177,   306,   177,   173,   173,   173,   178,   173,
     177,   173,   173,   173,   173,   173,   303,   303,   303,   303,
     303,    12,    13,   120,   184,   307,   206,   177,   173,   173,
      61,   202,   173,   259,   177,   173,   173,    71,   301,   177,
      13,    13,    13,    13,    13,    83,    84,   128,   170,   177,
      12,    13,    32,    36,    43,    57,    91,    99,   101,   102,
     103,   104,   105,   116,   127,   130,   136,   148,   207,   208,
     211,   213,   214,   216,   223,   206,   173,   177,   177,   173,
      13,    67,    90,   111,   260,   177,   173,    13,   173,    72,
     302,   173,    78,    79,    80,   121,   122,   173,   308,   308,
     308,    31,    45,    49,    63,   146,   159,    42,   176,   176,
     173,   173,   173,   173,   173,   173,   173,   173,    13,   173,
     177,   177,    13,    25,   178,   173,   173,   177,   173,    74,
     173,    13,   173,   309,    13,    13,    13,   173,   173,   173,
     177,   178,   331,   177,   173,    42,   173,   177,     4,    81,
     263,   177,    47,   177,    12,    97,   310,   312,   323,    83,
      84,   128,   176,   217,   173,   331,   173,   177,    13,   177,
     173,    13,   177,   177,    88,   172,    69,   162,   311,    13,
      12,    13,    48,    51,    66,    68,    98,   100,   218,   173,
     173,    10,   209,   177,   139,   203,   125,   177,   132,   304,
     313,   324,   173,   173,    31,   129,    45,    42,    52,   146,
     329,   173,   173,   173,   173,   173,   329,   109,   210,   158,
     212,    12,    13,   204,   173,   173,    13,    24,    41,    73,
     117,   314,   315,   316,   317,   318,    13,    27,    42,    62,
     112,   135,   146,   325,   219,   173,   173,   173,    13,    13,
     107,   145,    12,   267,    88,    69,   162,   319,    69,   162,
     321,   321,   314,   172,   177,   177,   177,   177,   177,   177,
      12,    13,   220,   173,   173,   146,   159,   173,   156,   173,
     177,    82,   320,   173,    82,   322,   113,   129,    12,   215,
     173,   173,   173,   177,   177,   173,   173,    15,    13,   173,
     177,   177,    13,   221,   173,    49,   224,   177,   177,    26,
      13,   114,   222,   173,    12,    13,    16,    30,    34,    35,
      55,    56,    58,    59,    65,   108,   133,   134,   147,   225,
     226,   229,   232,   236,   239,    13,    13,   113,   173,    13,
      37,    38,    39,    40,    50,    63,   173,   177,   173,   176,
     177,   177,   173,   173,   107,   156,   173,    15,   176,   176,
     176,   176,   177,   173,   173,   173,   176,   176,   176,   176,
     177,   173,   176,   176,   176,   176,   177,   173,    12,   230,
     231,   235,   242,   233,   234,   235,   242,    12,   237,   238,
     242,   240,   241,   242,   173,    33,   115,    13,   231,    13,
     234,    13,   238,    13,   241,   227,   173,   173,    37,    38,
      39,    39,     5,    13,   228,   176,   176,   173,    50,    13,
      13,    33,   115
  };

  const short
  XcpDataParser::yyr1_[] =
  {
       0,   179,   180,   181,   181,   182,   182,   183,   183,   184,
     184,   184,   184,   184,   184,   184,   185,   185,   185,   185,
     185,   185,   185,   186,   187,   188,   188,   189,   189,   189,
     189,   189,   189,   190,   191,   192,   192,   193,   193,   193,
     194,   195,   195,   196,   196,   197,   198,   199,   200,   200,
     201,   202,   202,   203,   203,   204,   205,   205,   206,   206,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   207,   207,   207,   207,
     207,   207,   208,   209,   209,   210,   210,   211,   212,   212,
     213,   214,   215,   216,   217,   217,   218,   218,   218,   218,
     218,   218,   218,   219,   219,   220,   221,   221,   222,   223,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     226,   227,   227,   228,   229,   230,   230,   231,   231,   232,
     233,   233,   234,   234,   235,   236,   237,   237,   238,   239,
     240,   240,   241,   242,   243,   244,   244,   245,   246,   247,
     247,   248,   248,   248,   249,   250,   250,   251,   252,   252,
     253,   253,   254,   255,   256,   256,   257,   257,   257,   257,
     258,   259,   259,   260,   260,   260,   261,   262,   263,   263,
     264,   265,   265,   266,   267,   267,   268,   268,   269,   270,
     271,   272,   272,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   274,   275,   275,   276,   276,   277,   278,   278,
     279,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   283,   284,   285,   285,   286,   286,
     286,   286,   286,   286,   286,   287,   287,   288,   288,   289,
     290,   291,   291,   292,   292,   292,   292,   292,   292,   292,
     292,   293,   294,   295,   295,   296,   296,   296,   296,   296,
     296,   296,   296,   297,   298,   298,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   300,   301,   301,   302,
     302,   303,   304,   304,   305,   306,   306,   307,   307,   307,
     307,   307,   308,   309,   309,   310,   310,   310,   311,   311,
     312,   313,   313,   314,   314,   314,   314,   315,   316,   317,
     318,   319,   319,   320,   320,   321,   321,   322,   322,   323,
     324,   324,   325,   325,   325,   325,   325,   325,   326,   327,
     327,   328,   328,   329,   329,   329,   330,   330,   331,   331
  };

  const signed char
  XcpDataParser::yyr2_[] =
  {
       0,     2,     5,     3,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     6,    12,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     5,     2,     5,     2,
       2,     0,     1,     0,     3,     2,     2,     5,     0,     2,
      12,     0,     1,     0,     2,     8,    15,    14,     0,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     8,     0,     1,     0,     2,     8,     0,     1,
       6,    11,     6,     6,     0,     2,     2,     2,     2,     2,
       2,     1,     5,     0,     2,     6,     0,     2,     6,    13,
       0,     2,     2,     2,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     3,     3,     2,     1,     1,     1,     1,
       9,     0,     2,     2,     8,     1,     2,     1,     1,     8,
       1,     2,     1,     1,     6,     8,     1,     2,     1,     8,
       1,     2,     1,     6,     5,     1,     1,     2,     2,     0,
       2,     5,     5,     5,     6,     0,     1,     8,     0,     2,
       1,     1,    11,    10,     0,     2,     1,     2,     1,     1,
       6,     0,     2,     2,     2,     2,     9,     7,     0,     2,
       6,     0,     2,    19,     0,     7,     0,     2,     2,     6,
       2,     0,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     2,     1,     1,
       2,     1,     6,     0,     2,     1,     1,     6,     0,     2,
       2,     5,     0,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     6,     6,     0,     2,     4,     1,
       1,     1,     1,     1,     1,     0,     1,     0,     6,     6,
       3,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     6,     3,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     1,    10,     0,     2,     5,     5,     2,     2,
       5,     5,     5,     1,     2,     1,     7,     0,     2,     0,
       2,     7,     0,     2,    12,     0,     2,     5,     5,     5,
       2,     1,     2,     0,     2,     2,     1,     1,     2,     2,
       5,     0,     2,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     0,     2,     2,     2,     0,     2,     5,
       0,     2,     2,     2,     2,     2,     2,     2,     5,     0,
       2,     2,     1,     1,     1,     1,     0,     2,     1,     1
  };


#if XCPDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const XcpDataParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ADDRESS",
  "ADDRESS_MAPPING", "ALT_SAMPLE_COUNT", "ALTERNATE_SETTING_NO",
  "ASYNCH_FULL_DUPLEX_MODE", "AVAILABLE_EVENT_LIST", "BAUDRATE",
  "BIT_STIM_SUPPORTED", "BLOCK", "BLOCK_BEGIN", "BLOCK_END", "BTL_CYCLES",
  "BUFFER_RESERVE", "BUFFER_RESERVE_EVENT", "CAN_FD",
  "CAN_FD_DATA_TRANSFER_BAUDRATE", "CAN_ID_BROADCAST", "CAN_ID_MASTER",
  "CAN_ID_MASTER_INCREMENTAL", "CAN_ID_SLAVE",
  "CAN_ID_GET_DAQ_CLOCK_MULTICAST", "CHANNEL", "CHECKSUM", "CLOCK", "CMD",
  "COMMUNICATION_MODE_SUPPORTED", "CONSISTENCY_EVENT_LIST", "CONSISTENCY",
  "CORE_LOAD_MAX", "CORE_LOAD_MAX_TOTAL", "CORE_LOAD_EP",
  "COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER", "CPU_LOAD_MAX",
  "CPU_LOAD_MAX_TOTAL", "CPU_LOAD_CONSUMPTION_DAQ",
  "CPU_LOAD_CONSUMPTION_STIM", "CPU_LOAD_CONSUMPTION_QUEUE",
  "CPU_LOAD_CONSUMPTION_QUEUE_STIM", "CYCLE_REPETITION", "DAQ",
  "DAQ_ALTERNATING_SUPPORTED", "DAQ_EVENT", "DAQ_LIST", "DAQ_LIST_CAN_ID",
  "DAQ_LIST_USB_ENDPOINT", "DAQ_LIST_TYPE", "DAQ_MEMORY_CONSUMPTION",
  "DAQ_PACKED_MODE", "DAQ_PACKED_MODE_SUPPORTED", "DAQ_STIM",
  "DEFAULT_EVENT_LIST", "DEFAULT_PAGE_NUMBER", "DTO_CTR_DAQ_MODE",
  "DTO_CTR_DAQ_MODE_FIXED", "DTO_CTR_FIELD_SUPPORTED", "DTO_CTR_STIM_MODE",
  "DTO_CTR_STIM_MODE_FIXED", "ECU_STATES", "ECU_SWITCHED_TO_DEFAULT_PAGE",
  "EV_SERV", "EVENT", "EVENT_CAN_ID_LIST", "EVENT_COUNTER_PRESENT",
  "EVENT_FIXED", "EXTERNAL_FUNCTION", "FIRST_PID", "FIXED",
  "FIXED_EVENT_LIST", "FIXED_IN", "FIXED_OUT", "FLX_SLOT_ID", "FRAMING",
  "FREEZE_SUPPORTED", "HOST_NAME", "IF_DATA", "IN_EP_ONLY_DAQ",
  "IN_EP_ONLY_EVSERV", "IN_EP_RESERR_DAQ_EVSERV", "INIT_SEGMENT",
  "INITIAL_VALUE", "INITIAL_CMD_BUFFER", "INITIAL_RES_ERR_BUFFER",
  "INTERFACE_STRING_DESCRIPTOR", "INTERLEAVED", "IPV6", "LPU_ID", "MASTER",
  "MAX_BLOCK_SIZE", "MAX_DAQ_TOTAL", "MAX_DLC_REQUIRED", "MAX_BUS_LOAD",
  "MAX_DLC", "MAX_DTO_STIM", "MAX_BIT_RATE", "MAX_FLX_LEN_BUF", "MAX_ODT",
  "MAX_ODT_DAQ_TOTAL", "MAX_ODT_ENTRIES", "MAX_ODT_ENTRIES_DAQ_TOTAL",
  "MAX_ODT_ENTRIES_STIM_TOTAL", "MAX_ODT_ENTRIES_TOTAL",
  "MAX_ODT_STIM_TOTAL", "MAX_ODT_TOTAL", "MEASUREMENT_SPLIT_ALLOWED",
  "MEMORY_ACCESS", "MIN_CYCLE_TIME", "MIN_ST_STIM", "MODEL_NAME",
  "MTA_BLOCK_SIZE_ALIGN", "MULTICAST", "ODT", "ODT_ENTRY",
  "ODT_ENTRY_SIZE_FACTOR_TABLE", "OPTIMISATION_TYPE_ODT_STRICT", "OFFSET",
  "OPTIONAL_CMD", "OPTIONAL_LEVEL1_CMD", "OPTIONAL_TL_SUBCMD",
  "OUT_EP_ONLY_STIM", "OUT_EP_CMD_STIM", "PACKET_ALIGNMENT", "PAG", "PAGE",
  "PGM", "PID_OFF_SUPPORTED", "POOL_BUFFER", "PREDEFINED",
  "PRESCALER_SUPPORTED", "PROTOCOL_LAYER", "RECOMMENDED_HOST_BUFSIZE",
  "RELATED_EVENT_CHANNEL_NUMBER", "RELATED_EVENT_CHANNEL_NUMBER_FIXED",
  "RES_ERR", "RESUME_SUPPORTED", "SAMPLE_POINT", "SAMPLE_RATE", "SECTOR",
  "SEGMENT", "SECONDARY_SAMPLE_POINT", "SEED_AND_KEY_EXTERNAL_FUNCTION",
  "SJW", "SLAVE", "STATE", "STIM", "STIM_DTO_CTR_COPY_PRESENT",
  "STORE_DAQ_SUPPORTED", "SYNC_EDGE", "SYNCH_FULL_DUPLEX_MODE_BYTE",
  "SYNCH_FULL_DUPLEX_MODE_WORD", "SYNCH_FULL_DUPLEX_MODE_DWORD",
  "SYNCH_FULL_MASTER_MODE_BYTE", "SYNCH_FULL_MASTER_MODE_WORD",
  "SYNCH_FULL_MASTER_MODE_DWORD", "TIME_CHARACTERIZATION",
  "TIME_CORRELATION", "TIMESTAMP_FIXED", "TIMESTAMP_SUPPORTED",
  "TRANSPORT_LAYER_INSTANCE", "TRANSCEIVER_DELAY_COMPENSATION", "VARIABLE",
  "XCP", "XCPplus", "XCP_ON_CAN", "XCP_ON_SxI", "XCP_ON_TCP_IP",
  "XCP_ON_UDP_IP", "XCP_ON_USB", "XCP_ON_FLX", "XCP_ON_SIMULINK",
  "XCP_PACKET", "UINT", "HEX", "INT", "FLOAT", "IDENT", "STRING",
  "$accept", "xcp_data_block", "if_data", "definitions", "definition",
  "common_definition", "transport_protocol", "protocol_layer",
  "protocol_fixed_items", "protocol_optional_items",
  "protocol_optional_item", "optional_command", "optional_level1_command",
  "communication_mode_supported", "communication_mode_union",
  "block_struct", "slave_item", "master_item", "seed_and_key_function",
  "max_dto_stim", "ecu_states", "state_list", "state_block",
  "ecu_switch_to_default", "memory_access_list", "memory_access", "daq",
  "daq_optionals", "daq_optional", "stim_struct", "bit_stim",
  "min_st_stim", "timestamp_supported", "timestamp_fixed", "core_load_max",
  "daq_memory_consumption", "daq_memory_consumption_optional", "daq_list",
  "daq_list_optionals", "daq_list_optional", "odt_list", "odt",
  "odt_entry_list", "odt_entry", "d_event", "d_event_optionals",
  "d_event_optional", "daq_packed_mode", "alt_sample_count_list",
  "alt_sample_count", "cpu_load_consumption_daq",
  "cpu_load_consumption_daq_options", "cpu_load_consumption_daq_option",
  "cpu_load_consumption_stim", "cpu_load_consumption_stim_options",
  "cpu_load_consumption_stim_option", "odt_entry_size_factor_table",
  "cpu_load_consumption_queue", "cpu_load_consumption_queue_options",
  "cpu_load_consumption_queue_option", "cpu_load_consumption_queue_stim",
  "cpu_load_consumption_queue_stim_options",
  "cpu_load_consumption_queue_stim_option", "core_load_ep", "daq_event",
  "daq_event_union", "fixed_event_list", "variable", "variable_options",
  "variable_option", "pag", "freeze_supported", "pgm", "pgm_options",
  "pgm_option", "sector", "segment", "segment_options", "segment_option",
  "checksum", "checksum_options", "checksum_option", "page",
  "address_mapping", "init_segment", "time_correlation", "clock_list",
  "clock", "timestamp_characterization", "event_list", "event",
  "xcp_on_can", "can_parameters", "can_parameter_options",
  "can_parameter_option", "daq_list_can_id", "daq_list_can_id_options",
  "daq_list_can_id_option", "event_can_id_list", "fixed_list", "fixed",
  "can_fd", "can_fd_options", "can_fd_option", "xcp_on_sxi",
  "sxi_parameter", "sxi_parameter_options", "sxi_parameter_option",
  "sxi_option", "framing", "xcp_on_tcp_ip", "tcp_ip_parameter",
  "tcp_ip_options", "tcp_ip_option", "xcp_on_udp_ip", "udp_ip_parameter",
  "udp_ip_options", "udp_ip_option", "xcp_on_usb", "usb_options",
  "usb_option", "daq_list_usb_endpoint", "fixed_in", "fixed_out",
  "ep_parameters", "recommended_host_bufsize", "xcp_on_flx", "flx_options",
  "flx_option", "buffer", "buffer_options", "buffer_option",
  "max_flx_len_buf_union", "lpu_id", "lpu_id_options", "lpu_id_option",
  "flx_slot_id_union", "offset_union", "cycle_repetition", "channel",
  "channel_union", "initial_enum", "lpu_id_union", "initial_value",
  "xcp_packet", "xcp_packet_options", "xcp_packet_option",
  "xcp_on_simulink", "simulink_options", "simulink_option",
  "daq_list_type", "transport_layer_instance", "ident_or_string", YY_NULLPTR
  };
#endif


#if XCPDEBUG
  const short
  XcpDataParser::yyrline_[] =
  {
       0,    92,    92,    94,    95,    96,    97,    98,    99,   101,
     102,   103,   104,   105,   106,   107,   109,   110,   111,   112,
     113,   114,   115,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   128,   129,   131,   132,   135,   136,   139,
     140,   141,   142,   143,   144,   146,   148,   150,   152,   153,
     155,   158,   159,   160,   161,   162,   164,   167,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   195,   196,   197,   198,   199,   201,   204,   205,
     207,   209,   212,   214,   218,   219,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   231,   233,   234,   236,   238,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     262,   265,   266,   267,   269,   272,   273,   275,   276,   278,
     281,   282,   284,   285,   287,   291,   295,   296,   297,   299,
     302,   303,   304,   306,   310,   313,   314,   316,   317,   318,
     319,   320,   321,   322,   324,   325,   326,   328,   331,   332,
     333,   334,   335,   339,   342,   343,   344,   345,   346,   347,
     349,   352,   353,   354,   355,   356,   358,   362,   366,   367,
     369,   372,   373,   374,   378,   379,   383,   384,   385,   387,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   414,   417,   418,   419,   420,   421,   424,   425,
     426,   428,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   444,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   460,   461,   465,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   480,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   495,   498,   499,   500,   503,   506,   507,
     508,   511,   514,   517,   518,   519,   520,   523,   524,   525,
     526,   527,   528,   529,   531,   535,   536,   537,   540,   543,
     546,   547,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   575,   576,   577,   578,   580,
     583,   584,   585,   586,   587,   588,   589,   590,   592,   595,
     596,   597,   598,   600,   601,   602,   603,   604,   605,   606
  };

  void
  XcpDataParser::yy_stack_print_ () const
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
  XcpDataParser::yy_reduce_print_ (int yyrule) const
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
#endif // XCPDEBUG

  XcpDataParser::symbol_kind_type
  XcpDataParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const unsigned char
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178
    };
    // Last valid token kind.
    const int code_max = 433;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
} } // a2l::xcp
#line 1768 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

#line 608 "D:/projects/a2llib/src/xcp/xcpdataparser.y"


void a2l::xcp::XcpDataParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
