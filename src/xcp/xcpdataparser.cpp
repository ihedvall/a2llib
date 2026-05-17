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
#line 28 "D:/projects/a2llib/src/xcp/xcpdataparser.y"

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
      case symbol_kind::S_address_mapping: // address_mapping
        value.copy< AddressMapping > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        value.copy< CommunicationMode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        value.copy< CoreLoadEp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        value.copy< CoreLoadMax > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        value.copy< CpuLoadConsumption > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq: // daq
        value.copy< Daq > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_event: // daq_event
        value.copy< DaqEvent > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_list: // daq_list
        value.copy< DaqList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        value.copy< DaqMemoryConsumption > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        value.copy< DaqPackedMode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        value.copy< DaqStim > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_state_block: // state_block
        value.copy< EcuState > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_d_event: // d_event
        value.copy< Event > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_access: // memory_access
        value.copy< MemoryAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt: // odt
        value.copy< Odt > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        value.copy< OdtEntry > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        value.copy< OdtEntrySizeFactor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pag: // pag
        value.copy< Pag > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pgm: // pgm
        value.copy< Pgm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        value.copy< ProtocolLayer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sector: // sector
        value.copy< Sector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_segment: // segment
        value.copy< Segment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        value.copy< TimeCorrelation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        value.copy< Timestamp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        value.copy< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        value.copy< std::optional<BufferReserve> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        value.copy< std::optional<uint8_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        value.copy< std::vector<EcuState> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        value.copy< std::vector<MemoryAccess> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_list: // odt_list
        value.copy< std::vector<Odt> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        value.copy< std::vector<OdtEntry> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        value.copy< std::vector<uint16_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        value.copy< std::vector<uint32_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        value.copy< uint16_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fixed: // fixed
        value.copy< uint32_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_address_mapping: // address_mapping
        value.move< AddressMapping > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        value.move< CommunicationMode > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        value.move< CoreLoadEp > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        value.move< CoreLoadMax > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        value.move< CpuLoadConsumption > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_daq: // daq
        value.move< Daq > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_daq_event: // daq_event
        value.move< DaqEvent > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_daq_list: // daq_list
        value.move< DaqList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        value.move< DaqMemoryConsumption > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        value.move< DaqPackedMode > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        value.move< DaqStim > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_state_block: // state_block
        value.move< EcuState > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_d_event: // d_event
        value.move< Event > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_memory_access: // memory_access
        value.move< MemoryAccess > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_odt: // odt
        value.move< Odt > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        value.move< OdtEntry > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        value.move< OdtEntrySizeFactor > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pag: // pag
        value.move< Pag > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_pgm: // pgm
        value.move< Pgm > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        value.move< ProtocolLayer > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sector: // sector
        value.move< Sector > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_segment: // segment
        value.move< Segment > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        value.move< TimeCorrelation > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        value.move< Timestamp > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        value.move< std::optional<BufferReserve> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        value.move< std::optional<uint8_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        value.move< std::vector<EcuState> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        value.move< std::vector<MemoryAccess> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_odt_list: // odt_list
        value.move< std::vector<Odt> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        value.move< std::vector<OdtEntry> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        value.move< std::vector<uint16_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        value.move< std::vector<uint32_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        value.move< uint16_t > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fixed: // fixed
        value.move< uint32_t > (YY_MOVE (s.value));
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
      case symbol_kind::S_address_mapping: // address_mapping
        value.YY_MOVE_OR_COPY< AddressMapping > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        value.YY_MOVE_OR_COPY< CommunicationMode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        value.YY_MOVE_OR_COPY< CoreLoadEp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        value.YY_MOVE_OR_COPY< CoreLoadMax > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        value.YY_MOVE_OR_COPY< CpuLoadConsumption > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq: // daq
        value.YY_MOVE_OR_COPY< Daq > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_event: // daq_event
        value.YY_MOVE_OR_COPY< DaqEvent > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_list: // daq_list
        value.YY_MOVE_OR_COPY< DaqList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        value.YY_MOVE_OR_COPY< DaqMemoryConsumption > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        value.YY_MOVE_OR_COPY< DaqPackedMode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        value.YY_MOVE_OR_COPY< DaqStim > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_state_block: // state_block
        value.YY_MOVE_OR_COPY< EcuState > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_d_event: // d_event
        value.YY_MOVE_OR_COPY< Event > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_access: // memory_access
        value.YY_MOVE_OR_COPY< MemoryAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt: // odt
        value.YY_MOVE_OR_COPY< Odt > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        value.YY_MOVE_OR_COPY< OdtEntry > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        value.YY_MOVE_OR_COPY< OdtEntrySizeFactor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pag: // pag
        value.YY_MOVE_OR_COPY< Pag > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pgm: // pgm
        value.YY_MOVE_OR_COPY< Pgm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        value.YY_MOVE_OR_COPY< ProtocolLayer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sector: // sector
        value.YY_MOVE_OR_COPY< Sector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_segment: // segment
        value.YY_MOVE_OR_COPY< Segment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        value.YY_MOVE_OR_COPY< TimeCorrelation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        value.YY_MOVE_OR_COPY< Timestamp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        value.YY_MOVE_OR_COPY< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        value.YY_MOVE_OR_COPY< std::optional<BufferReserve> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        value.YY_MOVE_OR_COPY< std::optional<uint8_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        value.YY_MOVE_OR_COPY< std::vector<EcuState> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        value.YY_MOVE_OR_COPY< std::vector<MemoryAccess> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_list: // odt_list
        value.YY_MOVE_OR_COPY< std::vector<Odt> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        value.YY_MOVE_OR_COPY< std::vector<OdtEntry> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        value.YY_MOVE_OR_COPY< std::vector<uint16_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        value.YY_MOVE_OR_COPY< std::vector<uint32_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        value.YY_MOVE_OR_COPY< uint16_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fixed: // fixed
        value.YY_MOVE_OR_COPY< uint32_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_address_mapping: // address_mapping
        value.move< AddressMapping > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        value.move< CommunicationMode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        value.move< CoreLoadEp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        value.move< CoreLoadMax > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        value.move< CpuLoadConsumption > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq: // daq
        value.move< Daq > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_event: // daq_event
        value.move< DaqEvent > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_list: // daq_list
        value.move< DaqList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        value.move< DaqMemoryConsumption > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        value.move< DaqPackedMode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        value.move< DaqStim > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_state_block: // state_block
        value.move< EcuState > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_d_event: // d_event
        value.move< Event > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_access: // memory_access
        value.move< MemoryAccess > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt: // odt
        value.move< Odt > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        value.move< OdtEntry > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        value.move< OdtEntrySizeFactor > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pag: // pag
        value.move< Pag > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pgm: // pgm
        value.move< Pgm > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        value.move< ProtocolLayer > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sector: // sector
        value.move< Sector > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_segment: // segment
        value.move< Segment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        value.move< TimeCorrelation > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        value.move< Timestamp > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        value.move< std::optional<BufferReserve> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        value.move< std::optional<uint8_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        value.move< std::vector<EcuState> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        value.move< std::vector<MemoryAccess> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_list: // odt_list
        value.move< std::vector<Odt> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        value.move< std::vector<OdtEntry> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        value.move< std::vector<uint16_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        value.move< std::vector<uint32_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        value.move< uint16_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fixed: // fixed
        value.move< uint32_t > (YY_MOVE (that.value));
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
      case symbol_kind::S_address_mapping: // address_mapping
        value.copy< AddressMapping > (that.value);
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        value.copy< CommunicationMode > (that.value);
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        value.copy< CoreLoadEp > (that.value);
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        value.copy< CoreLoadMax > (that.value);
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        value.copy< CpuLoadConsumption > (that.value);
        break;

      case symbol_kind::S_daq: // daq
        value.copy< Daq > (that.value);
        break;

      case symbol_kind::S_daq_event: // daq_event
        value.copy< DaqEvent > (that.value);
        break;

      case symbol_kind::S_daq_list: // daq_list
        value.copy< DaqList > (that.value);
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        value.copy< DaqMemoryConsumption > (that.value);
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        value.copy< DaqPackedMode > (that.value);
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        value.copy< DaqStim > (that.value);
        break;

      case symbol_kind::S_state_block: // state_block
        value.copy< EcuState > (that.value);
        break;

      case symbol_kind::S_d_event: // d_event
        value.copy< Event > (that.value);
        break;

      case symbol_kind::S_memory_access: // memory_access
        value.copy< MemoryAccess > (that.value);
        break;

      case symbol_kind::S_odt: // odt
        value.copy< Odt > (that.value);
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        value.copy< OdtEntry > (that.value);
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        value.copy< OdtEntrySizeFactor > (that.value);
        break;

      case symbol_kind::S_pag: // pag
        value.copy< Pag > (that.value);
        break;

      case symbol_kind::S_pgm: // pgm
        value.copy< Pgm > (that.value);
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        value.copy< ProtocolLayer > (that.value);
        break;

      case symbol_kind::S_sector: // sector
        value.copy< Sector > (that.value);
        break;

      case symbol_kind::S_segment: // segment
        value.copy< Segment > (that.value);
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        value.copy< TimeCorrelation > (that.value);
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        value.copy< Timestamp > (that.value);
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        value.copy< int64_t > (that.value);
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        value.copy< std::optional<BufferReserve> > (that.value);
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        value.copy< std::optional<uint8_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        value.copy< std::vector<EcuState> > (that.value);
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        value.copy< std::vector<MemoryAccess> > (that.value);
        break;

      case symbol_kind::S_odt_list: // odt_list
        value.copy< std::vector<Odt> > (that.value);
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        value.copy< std::vector<OdtEntry> > (that.value);
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        value.copy< std::vector<uint16_t> > (that.value);
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        value.copy< std::vector<uint32_t> > (that.value);
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        value.copy< uint16_t > (that.value);
        break;

      case symbol_kind::S_fixed: // fixed
        value.copy< uint32_t > (that.value);
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
      case symbol_kind::S_address_mapping: // address_mapping
        value.move< AddressMapping > (that.value);
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        value.move< CommunicationMode > (that.value);
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        value.move< CoreLoadEp > (that.value);
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        value.move< CoreLoadMax > (that.value);
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        value.move< CpuLoadConsumption > (that.value);
        break;

      case symbol_kind::S_daq: // daq
        value.move< Daq > (that.value);
        break;

      case symbol_kind::S_daq_event: // daq_event
        value.move< DaqEvent > (that.value);
        break;

      case symbol_kind::S_daq_list: // daq_list
        value.move< DaqList > (that.value);
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        value.move< DaqMemoryConsumption > (that.value);
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        value.move< DaqPackedMode > (that.value);
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        value.move< DaqStim > (that.value);
        break;

      case symbol_kind::S_state_block: // state_block
        value.move< EcuState > (that.value);
        break;

      case symbol_kind::S_d_event: // d_event
        value.move< Event > (that.value);
        break;

      case symbol_kind::S_memory_access: // memory_access
        value.move< MemoryAccess > (that.value);
        break;

      case symbol_kind::S_odt: // odt
        value.move< Odt > (that.value);
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        value.move< OdtEntry > (that.value);
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        value.move< OdtEntrySizeFactor > (that.value);
        break;

      case symbol_kind::S_pag: // pag
        value.move< Pag > (that.value);
        break;

      case symbol_kind::S_pgm: // pgm
        value.move< Pgm > (that.value);
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        value.move< ProtocolLayer > (that.value);
        break;

      case symbol_kind::S_sector: // sector
        value.move< Sector > (that.value);
        break;

      case symbol_kind::S_segment: // segment
        value.move< Segment > (that.value);
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        value.move< TimeCorrelation > (that.value);
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        value.move< Timestamp > (that.value);
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        value.move< int64_t > (that.value);
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        value.move< std::optional<BufferReserve> > (that.value);
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        value.move< std::optional<uint8_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        value.move< std::vector<EcuState> > (that.value);
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        value.move< std::vector<MemoryAccess> > (that.value);
        break;

      case symbol_kind::S_odt_list: // odt_list
        value.move< std::vector<Odt> > (that.value);
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        value.move< std::vector<OdtEntry> > (that.value);
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        value.move< std::vector<uint16_t> > (that.value);
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        value.move< std::vector<uint32_t> > (that.value);
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        value.move< uint16_t > (that.value);
        break;

      case symbol_kind::S_fixed: // fixed
        value.move< uint32_t > (that.value);
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
      case symbol_kind::S_address_mapping: // address_mapping
        yylhs.value.emplace< AddressMapping > ();
        break;

      case symbol_kind::S_communication_mode_supported: // communication_mode_supported
        yylhs.value.emplace< CommunicationMode > ();
        break;

      case symbol_kind::S_core_load_ep: // core_load_ep
        yylhs.value.emplace< CoreLoadEp > ();
        break;

      case symbol_kind::S_core_load_max: // core_load_max
        yylhs.value.emplace< CoreLoadMax > ();
        break;

      case symbol_kind::S_cpu_load_consumption_daq: // cpu_load_consumption_daq
      case symbol_kind::S_cpu_load_consumption_stim: // cpu_load_consumption_stim
      case symbol_kind::S_cpu_load_consumption_queue: // cpu_load_consumption_queue
      case symbol_kind::S_cpu_load_consumption_queue_stim: // cpu_load_consumption_queue_stim
        yylhs.value.emplace< CpuLoadConsumption > ();
        break;

      case symbol_kind::S_daq: // daq
        yylhs.value.emplace< Daq > ();
        break;

      case symbol_kind::S_daq_event: // daq_event
        yylhs.value.emplace< DaqEvent > ();
        break;

      case symbol_kind::S_daq_list: // daq_list
        yylhs.value.emplace< DaqList > ();
        break;

      case symbol_kind::S_daq_memory_consumption: // daq_memory_consumption
        yylhs.value.emplace< DaqMemoryConsumption > ();
        break;

      case symbol_kind::S_daq_packed_mode: // daq_packed_mode
        yylhs.value.emplace< DaqPackedMode > ();
        break;

      case symbol_kind::S_stim_struct: // stim_struct
        yylhs.value.emplace< DaqStim > ();
        break;

      case symbol_kind::S_state_block: // state_block
        yylhs.value.emplace< EcuState > ();
        break;

      case symbol_kind::S_d_event: // d_event
        yylhs.value.emplace< Event > ();
        break;

      case symbol_kind::S_memory_access: // memory_access
        yylhs.value.emplace< MemoryAccess > ();
        break;

      case symbol_kind::S_odt: // odt
        yylhs.value.emplace< Odt > ();
        break;

      case symbol_kind::S_odt_entry: // odt_entry
        yylhs.value.emplace< OdtEntry > ();
        break;

      case symbol_kind::S_odt_entry_size_factor_table: // odt_entry_size_factor_table
        yylhs.value.emplace< OdtEntrySizeFactor > ();
        break;

      case symbol_kind::S_pag: // pag
        yylhs.value.emplace< Pag > ();
        break;

      case symbol_kind::S_pgm: // pgm
        yylhs.value.emplace< Pgm > ();
        break;

      case symbol_kind::S_protocol_layer: // protocol_layer
        yylhs.value.emplace< ProtocolLayer > ();
        break;

      case symbol_kind::S_sector: // sector
        yylhs.value.emplace< Sector > ();
        break;

      case symbol_kind::S_segment: // segment
        yylhs.value.emplace< Segment > ();
        break;

      case symbol_kind::S_time_correlation: // time_correlation
        yylhs.value.emplace< TimeCorrelation > ();
        break;

      case symbol_kind::S_timestamp_supported: // timestamp_supported
        yylhs.value.emplace< Timestamp > ();
        break;

      case symbol_kind::S_ecu_switch_to_default: // ecu_switch_to_default
      case symbol_kind::S_bit_stim: // bit_stim
      case symbol_kind::S_timestamp_fixed: // timestamp_fixed
      case symbol_kind::S_initial_enum: // initial_enum
      case symbol_kind::S_initial_value: // initial_value
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_any_float: // any_float
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_any_int: // any_int
        yylhs.value.emplace< int64_t > ();
        break;

      case symbol_kind::S_buffer_reserve: // buffer_reserve
        yylhs.value.emplace< std::optional<BufferReserve> > ();
        break;

      case symbol_kind::S_min_st_stim: // min_st_stim
        yylhs.value.emplace< std::optional<uint8_t> > ();
        break;

      case symbol_kind::S_IDENT: // IDENT
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_consistency: // consistency
      case symbol_kind::S_daq_list_type: // daq_list_type
      case symbol_kind::S_transport_layer_instance: // transport_layer_instance
      case symbol_kind::S_ident_or_string: // ident_or_string
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_ecu_states: // ecu_states
      case symbol_kind::S_state_list: // state_list
        yylhs.value.emplace< std::vector<EcuState> > ();
        break;

      case symbol_kind::S_memory_access_list: // memory_access_list
        yylhs.value.emplace< std::vector<MemoryAccess> > ();
        break;

      case symbol_kind::S_odt_list: // odt_list
        yylhs.value.emplace< std::vector<Odt> > ();
        break;

      case symbol_kind::S_odt_entry_list: // odt_entry_list
        yylhs.value.emplace< std::vector<OdtEntry> > ();
        break;

      case symbol_kind::S_alt_sample_count_list: // alt_sample_count_list
      case symbol_kind::S_event_list: // event_list
        yylhs.value.emplace< std::vector<uint16_t> > ();
        break;

      case symbol_kind::S_fixed_list: // fixed_list
        yylhs.value.emplace< std::vector<uint32_t> > ();
        break;

      case symbol_kind::S_alt_sample_count: // alt_sample_count
      case symbol_kind::S_event: // event
        yylhs.value.emplace< uint16_t > ();
        break;

      case symbol_kind::S_fixed: // fixed
        yylhs.value.emplace< uint32_t > ();
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
  case 3: // if_data: XCPplus UINT definitions
#line 147 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
       scanner.SetVersion(yystack_[1].value.as < uint64_t > ());
      }
#line 1827 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 7: // definition: common_parameter
#line 154 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  scanner.SaveCommonParameters();
	}
#line 1835 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 9: // common_parameter: protocol_layer
#line 158 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	CommonParameters& common = scanner.GetCommonParameters();
	common.SetProtocolLayer(std::move(yystack_[0].value.as < ProtocolLayer > ()));
    }
#line 1844 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 10: // common_parameter: daq
#line 161 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaq(std::move(yystack_[0].value.as < Daq > ()));
    }
#line 1853 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 11: // common_parameter: daq_event
#line 164 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaqEvent(std::move(yystack_[0].value.as < DaqEvent > ()));
    }
#line 1862 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 12: // common_parameter: pag
#line 167 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPag(std::move(yystack_[0].value.as < Pag > ()));
    }
#line 1871 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 13: // common_parameter: pgm
#line 170 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPgm(std::move(yystack_[0].value.as < Pgm > ()));
    }
#line 1880 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 14: // common_parameter: segment
#line 173 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetSegment(std::move(yystack_[0].value.as < Segment > ()));
    }
#line 1889 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 15: // common_parameter: time_correlation
#line 176 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	CommonParameters& common = scanner.GetCommonParameters();
        common.SetTimeCorrelation(std::move(yystack_[0].value.as < TimeCorrelation > ()));
    }
#line 1898 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 23: // protocol_layer: BLOCK_BEGIN PROTOCOL_LAYER UINT UINT UINT UINT UINT UINT UINT UINT UINT UINT IDENT IDENT protocol_optional_items BLOCK_END PROTOCOL_LAYER
#line 191 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetVersion(yystack_[14].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T1, yystack_[13].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T2, yystack_[12].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T3, yystack_[11].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T4, yystack_[10].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T5, yystack_[9].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T6, yystack_[8].value.as < uint64_t > ());
	  protocol.SetTimer(ProtocolTimer::T7, yystack_[7].value.as < uint64_t > ());
	  protocol.SetMaxCto(yystack_[6].value.as < uint64_t > ());
	  protocol.SetMaxDto(yystack_[5].value.as < uint64_t > ());
	  protocol.SetByteOrder(yystack_[4].value.as < std::string > ());
	  yylhs.value.as < ProtocolLayer > () = std::move(protocol);
	  protocol.Reset();
	}
#line 1919 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 26: // protocol_optional_item: OPTIONAL_CMD IDENT
#line 211 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommand(yystack_[0].value.as < std::string > ());
        }
#line 1928 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 27: // protocol_optional_item: OPTIONAL_LEVEL1_CMD IDENT
#line 214 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommandLevel1(yystack_[0].value.as < std::string > ());
	}
#line 1937 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 28: // protocol_optional_item: communication_mode_supported
#line 217 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetCommunicationMode(std::move(yystack_[0].value.as < CommunicationMode > ()));
	}
#line 1946 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 29: // protocol_optional_item: SEED_AND_KEY_EXTERNAL_FUNCTION STRING
#line 220 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                  {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetSeedAndKeyFunction(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1955 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 30: // protocol_optional_item: MAX_DTO_STIM UINT
#line 223 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetMaxDtoStim(yystack_[0].value.as < uint64_t > ());
	}
#line 1964 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 31: // protocol_optional_item: ecu_states
#line 226 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetEcuStates(std::move(yystack_[0].value.as < std::vector<EcuState> > ()));
	}
#line 1973 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 32: // ecu_states: BLOCK_BEGIN ECU_STATES state_list BLOCK_END ECU_STATES
#line 233 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::vector<EcuState> > () = std::move(yystack_[2].value.as < std::vector<EcuState> > ()); }
#line 1979 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 33: // state_list: %empty
#line 235 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<EcuState> > ().clear(); }
#line 1985 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 34: // state_list: state_list state_block
#line 236 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
            	yylhs.value.as < std::vector<EcuState> > () = std::move(yystack_[1].value.as < std::vector<EcuState> > ());
            	yylhs.value.as < std::vector<EcuState> > ().emplace_back(std::move(yystack_[0].value.as < EcuState > ()));
            }
#line 1994 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 35: // state_block: BLOCK_BEGIN STATE UINT STRING ecu_switch_to_default IDENT IDENT IDENT IDENT memory_access_list BLOCK_END STATE
#line 243 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
             	yylhs.value.as < EcuState > ().SetNumber(yystack_[9].value.as < uint64_t > ());
             	yylhs.value.as < EcuState > ().SetName(yystack_[8].value.as < std::string > ());
             	yylhs.value.as < EcuState > ().SetEcuSwithedToDefaultPage(yystack_[7].value.as < bool > ());
             	yylhs.value.as < EcuState > ().SetCalPagResource(yystack_[6].value.as < std::string > ());
             	yylhs.value.as < EcuState > ().SetDaqResource(yystack_[5].value.as < std::string > ());
              	yylhs.value.as < EcuState > ().SetStimResource(yystack_[4].value.as < std::string > ());
              	yylhs.value.as < EcuState > ().SetPgmResource(yystack_[3].value.as < std::string > ());
              	yylhs.value.as < EcuState > ().SetMemoryAccessList(yystack_[2].value.as < std::vector<MemoryAccess> > ());
             }
#line 2009 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 36: // ecu_switch_to_default: %empty
#line 254 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < bool > () = false; }
#line 2015 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 37: // ecu_switch_to_default: ECU_SWITCHED_TO_DEFAULT_PAGE
#line 255 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                      { yylhs.value.as < bool > () = true; }
#line 2021 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 38: // memory_access_list: %empty
#line 257 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           { yylhs.value.as < std::vector<MemoryAccess> > ().clear(); }
#line 2027 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 39: // memory_access_list: memory_access_list memory_access
#line 258 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
         		yylhs.value.as < std::vector<MemoryAccess> > () = std::move(yystack_[1].value.as < std::vector<MemoryAccess> > ());
         		yylhs.value.as < std::vector<MemoryAccess> > ().emplace_back(yystack_[0].value.as < MemoryAccess > ());
                    }
#line 2036 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 40: // memory_access: BLOCK_BEGIN MEMORY_ACCESS UINT UINT IDENT IDENT BLOCK_END MEMORY_ACCESS
#line 264 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		yylhs.value.as < MemoryAccess > ().SetSegment(yystack_[5].value.as < uint64_t > ());
		yylhs.value.as < MemoryAccess > ().SetPage(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < MemoryAccess > ().SetReadAccess(yystack_[3].value.as < std::string > ());
		yylhs.value.as < MemoryAccess > ().SetWriteAccess(yystack_[2].value.as < std::string > ());
	}
#line 2047 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 41: // daq: BLOCK_BEGIN DAQ IDENT UINT UINT UINT IDENT IDENT IDENT IDENT UINT IDENT daq_optionals BLOCK_END DAQ
#line 273 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
        Daq& daq = scanner.GetDaq();
     	daq.SetType(yystack_[12].value.as < std::string > ());
     	daq.SetMaxDaq(yystack_[11].value.as < uint64_t > ());
     	daq.SetMaxEvent(yystack_[10].value.as < uint64_t > ());
     	daq.SetMinDaq(yystack_[9].value.as < uint64_t > ());
     	daq.SetOptimisationType(yystack_[8].value.as < std::string > ());
     	daq.SetAddressExtension(yystack_[7].value.as < std::string > ());
     	daq.SetIdentificationFieldType(yystack_[6].value.as < std::string > ());
     	daq.SetGranularityOdtEntrySizeDaq(yystack_[5].value.as < std::string > ());
     	daq.SetMaxOdtEntrySize(yystack_[4].value.as < uint64_t > ());
     	daq.SetOverloadIndicator(yystack_[3].value.as < std::string > ());
     	yylhs.value.as < Daq > () = std::move(daq);
     	daq.Reset();
       }
#line 2067 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 42: // daq: BLOCK_BEGIN DAQ IDENT UINT UINT UINT IDENT IDENT IDENT UINT IDENT daq_optionals BLOCK_END DAQ
#line 289 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
        Daq& daq = scanner.GetDaq();
     	daq.SetType(yystack_[11].value.as < std::string > ());
     	daq.SetMaxDaq(yystack_[10].value.as < uint64_t > ());
     	daq.SetMaxEvent(yystack_[9].value.as < uint64_t > ());
     	daq.SetMinDaq(yystack_[8].value.as < uint64_t > ());
     	daq.SetOptimisationType(yystack_[7].value.as < std::string > ());
     	daq.SetAddressExtension(yystack_[6].value.as < std::string > ());
     	daq.SetIdentificationFieldType(yystack_[5].value.as < std::string > ());
     	daq.SetMaxOdtEntrySize(yystack_[4].value.as < uint64_t > ());
     	daq.SetOverloadIndicator(yystack_[3].value.as < std::string > ());
     	yylhs.value.as < Daq > () = std::move(daq);
     	daq.Reset();
     }
#line 2086 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 45: // daq_optional: DAQ_ALTERNATING_SUPPORTED UINT
#line 307 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqAlternatingSupported(yystack_[0].value.as < uint64_t > ());
      }
#line 2095 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 46: // daq_optional: PRESCALER_SUPPORTED
#line 310 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPrescalerSupported();
      }
#line 2104 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 47: // daq_optional: RESUME_SUPPORTED
#line 313 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
      	Daq& daq = scanner.GetDaq();
      	daq.SetResumeSupported();
      }
#line 2113 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 48: // daq_optional: STORE_DAQ_SUPPORTED
#line 316 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStoreDaqSupported();
      }
#line 2122 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 49: // daq_optional: DTO_CTR_FIELD_SUPPORTED
#line 319 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDtoCtrSupported();
      }
#line 2131 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 50: // daq_optional: OPTIMISATION_TYPE_ODT_STRICT
#line 322 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Daq& daq = scanner.GetDaq();
      	daq.SetOptimisationTypeOdtStrict();
      }
#line 2140 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 51: // daq_optional: stim_struct
#line 325 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStim(yystack_[0].value.as < DaqStim > ());
      }
#line 2149 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 52: // daq_optional: timestamp_supported
#line 328 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetTimestamp(yystack_[0].value.as < Timestamp > ());
      }
#line 2158 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 53: // daq_optional: PID_OFF_SUPPORTED
#line 331 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPidOffSupported();
      }
#line 2167 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 54: // daq_optional: MAX_DAQ_TOTAL UINT
#line 334 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2176 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 55: // daq_optional: MAX_ODT_TOTAL UINT
#line 337 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2185 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 56: // daq_optional: MAX_ODT_DAQ_TOTAL UINT
#line 340 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2194 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 57: // daq_optional: MAX_ODT_STIM_TOTAL UINT
#line 343 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtStimTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2203 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 58: // daq_optional: MAX_ODT_ENTRIES_TOTAL UINT
#line 346 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2212 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 59: // daq_optional: MAX_ODT_ENTRIES_DAQ_TOTAL UINT
#line 349 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2221 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 60: // daq_optional: MAX_ODT_ENTRIES_STIM_TOTAL UINT
#line 352 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesStimTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2230 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 61: // daq_optional: CPU_LOAD_MAX_TOTAL any_float
#line 355 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCpuLoadMaxTotal(yystack_[0].value.as < double > ());
      }
#line 2239 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 62: // daq_optional: CORE_LOAD_MAX_TOTAL any_float
#line 358 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCoreLoadMaxTotal(yystack_[0].value.as < double > ());
      }
#line 2248 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 63: // daq_optional: core_load_max
#line 361 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Daq& daq = scanner.GetDaq();
      	daq.AddCoreLoadMax(yystack_[0].value.as < CoreLoadMax > ());
      }
#line 2257 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 64: // daq_optional: daq_memory_consumption
#line 364 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqMemoryConsumption(yystack_[0].value.as < DaqMemoryConsumption > ());
      }
#line 2266 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 65: // daq_optional: daq_list
#line 367 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Daq& daq = scanner.GetDaq();
      	daq.AddDaqList(std::move(yystack_[0].value.as < DaqList > ()));
      }
#line 2275 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 66: // daq_optional: d_event
#line 370 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
      	Daq& daq = scanner.GetDaq();
      	daq.AddEvent(std::move(yystack_[0].value.as < Event > ()));
      }
#line 2284 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 67: // stim_struct: BLOCK_BEGIN STIM IDENT UINT bit_stim min_st_stim BLOCK_END STIM
#line 377 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		yylhs.value.as < DaqStim > ().SetSize(yystack_[5].value.as < std::string > ());
		yylhs.value.as < DaqStim > ().max_odt_entry_size = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < DaqStim > ().bit_stim_supported = yystack_[3].value.as < bool > ();
		yylhs.value.as < DaqStim > ().min_st_stim = yystack_[2].value.as < std::optional<uint8_t> > ();
	  }
#line 2295 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 68: // bit_stim: %empty
#line 384 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < bool > () = false; }
#line 2301 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 69: // bit_stim: BIT_STIM_SUPPORTED
#line 385 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               { yylhs.value.as < bool > () = true; }
#line 2307 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 70: // min_st_stim: %empty
#line 387 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::optional<uint8_t> > ().reset(); }
#line 2313 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 71: // min_st_stim: MIN_ST_STIM UINT
#line 388 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                { yylhs.value.as < std::optional<uint8_t> > () = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2319 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 72: // timestamp_supported: BLOCK_BEGIN TIMESTAMP_SUPPORTED UINT IDENT IDENT timestamp_fixed BLOCK_END TIMESTAMP_SUPPORTED
#line 392 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
     		yylhs.value.as < Timestamp > ().SetTicks(yystack_[5].value.as < uint64_t > ());
     		yylhs.value.as < Timestamp > ().SetSize(yystack_[4].value.as < std::string > ());
     		yylhs.value.as < Timestamp > ().SetResolution(yystack_[3].value.as < std::string > ());
     		if (yystack_[2].value.as < bool > ()) {
     		  yylhs.value.as < Timestamp > ().SetFixed();
     		}
          }
#line 2332 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 73: // timestamp_fixed: %empty
#line 401 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        { yylhs.value.as < bool > () = false; }
#line 2338 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 74: // timestamp_fixed: TIMESTAMP_FIXED
#line 402 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {yylhs.value.as < bool > () = true;}
#line 2344 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 75: // core_load_max: BLOCK_BEGIN CORE_LOAD_MAX UINT any_float BLOCK_END CORE_LOAD_MAX
#line 406 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
	       	yylhs.value.as < CoreLoadMax > ().number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	       	yylhs.value.as < CoreLoadMax > ().max = static_cast<float>(yystack_[2].value.as < double > ());
	       }
#line 2353 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 76: // daq_memory_consumption: BLOCK_BEGIN DAQ_MEMORY_CONSUMPTION UINT UINT UINT UINT UINT UINT buffer_reserve BLOCK_END DAQ_MEMORY_CONSUMPTION
#line 413 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
              yylhs.value.as < DaqMemoryConsumption > ().limit = static_cast<uint32_t>(yystack_[8].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().daq_size = static_cast<uint16_t>(yystack_[7].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_size = static_cast<uint16_t>(yystack_[6].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_entry_size = static_cast<uint16_t>(yystack_[5].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_daq_buffer_element_size = static_cast<uint16_t>(yystack_[4].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_stim_buffer_element_size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().dto_stim_size = yystack_[2].value.as < std::optional<BufferReserve> > ();
           }
#line 2367 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 77: // buffer_reserve: %empty
#line 423 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::optional<BufferReserve> > ().reset(); }
#line 2373 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 78: // buffer_reserve: BLOCK_BEGIN BUFFER_RESERVE UINT UINT BLOCK_END BUFFER_RESERVE
#line 426 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
	     BufferReserve buffer;
	     buffer.odt_daq_buffer = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
	     buffer.odt_stim_buffer = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
	     yylhs.value.as < std::optional<BufferReserve> > () = buffer;
	   }
#line 2384 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 79: // daq_list: BLOCK_BEGIN DAQ_LIST UINT daq_list_optionals BLOCK_END DAQ_LIST
#line 435 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetNumber(yystack_[3].value.as < uint64_t > ());
	   	yylhs.value.as < DaqList > () = std::move(list);
	   	list.Reset();
          }
#line 2395 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 82: // daq_list_optional: DAQ_LIST_TYPE daq_list_type
#line 445 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetType(yystack_[0].value.as < std::string > ());
           }
#line 2404 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 83: // daq_list_optional: MAX_ODT UINT
#line 448 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdt(yystack_[0].value.as < uint64_t > ());
	   }
#line 2413 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 84: // daq_list_optional: MAX_ODT_ENTRIES UINT
#line 451 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdtEntries(yystack_[0].value.as < uint64_t > ());
	   }
#line 2422 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 85: // daq_list_optional: FIRST_PID UINT
#line 454 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetFirstPid(yystack_[0].value.as < uint64_t > ());
	   }
#line 2431 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 86: // daq_list_optional: EVENT_FIXED UINT
#line 457 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetEventFixed(yystack_[0].value.as < uint64_t > ());
	   }
#line 2440 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 87: // daq_list_optional: DAQ_PACKED_MODE_SUPPORTED
#line 460 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetDaqPackedModeSupported();
	   }
#line 2449 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 88: // daq_list_optional: BLOCK_BEGIN PREDEFINED odt_list BLOCK_END PREDEFINED
#line 465 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetPredefinedList(std::move(yystack_[2].value.as < std::vector<Odt> > ()));
	   }
#line 2458 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 89: // odt_list: %empty
#line 470 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::vector<Odt> > () = {}; }
#line 2464 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 90: // odt_list: odt_list odt
#line 471 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	yylhs.value.as < std::vector<Odt> > () = std::move(yystack_[1].value.as < std::vector<Odt> > ());
     	yylhs.value.as < std::vector<Odt> > ().emplace_back(std::move(yystack_[0].value.as < Odt > ()));
     }
#line 2473 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 91: // odt: BLOCK_BEGIN ODT UINT odt_entry_list BLOCK_END ODT
#line 478 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	yylhs.value.as < Odt > ().number = yystack_[3].value.as < uint64_t > ();
     	yylhs.value.as < Odt > ().odt_entry_list = std::move(yystack_[2].value.as < std::vector<OdtEntry> > ());
     }
#line 2482 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 92: // odt_entry_list: %empty
#line 483 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::vector<OdtEntry> > () = {}; }
#line 2488 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 93: // odt_entry_list: odt_entry_list odt_entry
#line 484 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
         	yylhs.value.as < std::vector<OdtEntry> > () = std::move(yystack_[1].value.as < std::vector<OdtEntry> > ());
         	yylhs.value.as < std::vector<OdtEntry> > ().emplace_back(std::move(yystack_[0].value.as < OdtEntry > ()));
         }
#line 2497 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 94: // odt_entry: ODT_ENTRY UINT UINT UINT UINT UINT
#line 489 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
		yylhs.value.as < OdtEntry > ().number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().address = yystack_[3].value.as < uint64_t > ();
		yylhs.value.as < OdtEntry > ().address_extension = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().size = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().bit_offset = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
	}
#line 2509 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 95: // d_event: BLOCK_BEGIN EVENT ident_or_string ident_or_string UINT daq_list_type UINT UINT UINT UINT d_event_optionals BLOCK_END EVENT
#line 499 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
		Event& event = scanner.GetEvent();
                event.SetName(yystack_[10].value.as < std::string > ());
                event.SetShortName(yystack_[9].value.as < std::string > ());
                event.SetNumber(yystack_[8].value.as < uint64_t > ());
                event.SetType(yystack_[7].value.as < std::string > ());
                event.SetMaxDaqList(yystack_[6].value.as < uint64_t > ());
                event.SetTimeCycle(yystack_[5].value.as < uint64_t > ());
                event.SetTimeUnit(yystack_[4].value.as < uint64_t > ());
                event.SetPriority(yystack_[3].value.as < uint64_t > ());
                yylhs.value.as < Event > () = std::move(event);
                event.Reset();
       }
#line 2527 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 98: // d_event_optional: COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER UINT
#line 514 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
		Event& event = scanner.GetEvent();
                event.SetComplementaryBypassNumber(yystack_[0].value.as < uint64_t > ());
        }
#line 2536 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 99: // d_event_optional: CONSISTENCY consistency
#line 517 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetConsistency(yystack_[0].value.as < std::string > ());
	}
#line 2545 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 100: // d_event_optional: EVENT_COUNTER_PRESENT
#line 520 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
		Event& event = scanner.GetEvent();
                event.SetEventCounterPresent();
	}
#line 2554 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 101: // d_event_optional: RELATED_EVENT_CHANNEL_NUMBER UINT
#line 523 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumber(yystack_[0].value.as < uint64_t > ());
	}
#line 2563 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 102: // d_event_optional: RELATED_EVENT_CHANNEL_NUMBER_FIXED
#line 526 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumberFixed();
	}
#line 2572 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 103: // d_event_optional: DTO_CTR_DAQ_MODE IDENT
#line 529 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqMode(yystack_[0].value.as < std::string > ());
	}
#line 2581 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 104: // d_event_optional: DTO_CTR_DAQ_MODE_FIXED
#line 532 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqModeFixed();
	}
#line 2590 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 105: // d_event_optional: DTO_CTR_STIM_MODE IDENT
#line 535 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimMode(yystack_[0].value.as < std::string > ());
	}
#line 2599 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 106: // d_event_optional: DTO_CTR_STIM_MODE_FIXED
#line 538 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimModeFixed();
	}
#line 2608 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 107: // d_event_optional: STIM_DTO_CTR_COPY_PRESENT
#line 541 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
                event.SetStimDtoCtrCopyPresent();
	}
#line 2617 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 108: // d_event_optional: daq_packed_mode
#line 544 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		Event& event = scanner.GetEvent();
                event.SetDaqPackedMode(std::move(yystack_[0].value.as < DaqPackedMode > ()));
	}
#line 2626 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 109: // d_event_optional: MIN_CYCLE_TIME UINT UINT
#line 547 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		MinCycleTime cycle;
		cycle.time_cycle = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		cycle.time_unit = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetMinCycleTime(std::move(cycle));
	}
#line 2638 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 110: // d_event_optional: BUFFER_RESERVE_EVENT UINT UINT
#line 553 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
		BufferReserveEvent buffer;
		buffer.odt_daq_buffer_element_reserve = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		buffer.odt_stim_buffer_element_reserve = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetBufferReserveEvent(std::move(buffer));
	}
#line 2650 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 111: // d_event_optional: CPU_LOAD_MAX any_float
#line 559 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadMax(yystack_[0].value.as < double > ());
	}
#line 2659 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 112: // d_event_optional: cpu_load_consumption_daq
#line 562 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionDaq(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2668 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 113: // d_event_optional: cpu_load_consumption_stim
#line 565 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2677 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 114: // d_event_optional: cpu_load_consumption_queue
#line 568 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueue(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2686 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 115: // d_event_optional: cpu_load_consumption_queue_stim
#line 571 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueueStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2695 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 116: // daq_packed_mode: BLOCK_BEGIN DAQ_PACKED_MODE IDENT IDENT IDENT UINT alt_sample_count_list BLOCK_END DAQ_PACKED_MODE
#line 578 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          	yylhs.value.as < DaqPackedMode > ().SetGroup(yystack_[6].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetTimestampMode(yystack_[5].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetUsage(yystack_[4].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().sample_count = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
          	yylhs.value.as < DaqPackedMode > ().alt_sample_count = std::move(yystack_[2].value.as < std::vector<uint16_t> > ());
          }
#line 2707 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 117: // alt_sample_count_list: %empty
#line 586 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < std::vector<uint16_t> > () = {};}
#line 2713 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 118: // alt_sample_count_list: alt_sample_count_list alt_sample_count
#line 587 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                {
                       	yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
                       	yylhs.value.as < std::vector<uint16_t> > ().push_back(static_cast<uint16_t>(yystack_[0].value.as < uint16_t > ()));
                       }
#line 2722 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 119: // alt_sample_count: ALT_SAMPLE_COUNT UINT
#line 592 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > ();}
#line 2728 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 120: // cpu_load_consumption_daq: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_DAQ any_float any_float any_float cpu_load_consumption_daq_options BLOCK_END CPU_LOAD_CONSUMPTION_DAQ
#line 596 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
           }
#line 2741 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 123: // cpu_load_consumption_daq_option: odt_entry_size_factor_table
#line 608 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	   }
#line 2750 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 124: // cpu_load_consumption_daq_option: core_load_ep
#line 611 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
 		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
           }
#line 2759 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 125: // cpu_load_consumption_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_STIM any_float any_float any_float cpu_load_consumption_stim_options BLOCK_END CPU_LOAD_CONSUMPTION_STIM
#line 618 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
           }
#line 2772 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 128: // cpu_load_consumption_stim_option: odt_entry_size_factor_table
#line 630 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	  }
#line 2781 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 129: // cpu_load_consumption_stim_option: core_load_ep
#line 633 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2790 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 130: // odt_entry_size_factor_table: BLOCK_BEGIN ODT_ENTRY_SIZE_FACTOR_TABLE UINT any_float BLOCK_END ODT_ENTRY_SIZE_FACTOR_TABLE
#line 640 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                   {
         	yylhs.value.as < OdtEntrySizeFactor > ().size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
         	yylhs.value.as < OdtEntrySizeFactor > ().factor = static_cast<float>(yystack_[2].value.as < double > ());
         }
#line 2799 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 131: // cpu_load_consumption_queue: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE any_float any_float cpu_load_consumption_queue_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 647 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
         }
#line 2811 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 133: // cpu_load_consumption_queue_option: core_load_ep
#line 656 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2820 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 134: // cpu_load_consumption_queue_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE_STIM any_float any_float cpu_load_consumption_queue_stim_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 663 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
         }
#line 2832 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 136: // cpu_load_consumption_queue_stim_option: core_load_ep
#line 672 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
	}
#line 2841 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 137: // core_load_ep: BLOCK_BEGIN CORE_LOAD_EP UINT any_float BLOCK_END CORE_LOAD_EP
#line 679 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
              yylhs.value.as < CoreLoadEp > ().number = yystack_[3].value.as < uint64_t > ();
              yylhs.value.as < CoreLoadEp > ().max = yystack_[2].value.as < double > ();
              }
#line 2850 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 138: // daq_event: BLOCK_BEGIN DAQ_EVENT daq_event_union BLOCK_END DAQ_EVENT
#line 686 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		DaqEvent& event_list = scanner.GetDaqEvent();
       		yylhs.value.as < DaqEvent > () = std::move(event_list);
       		event_list.Reset();
           }
#line 2860 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 141: // fixed_event_list: FIXED_EVENT_LIST event_list
#line 695 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetFixedEventList(yystack_[0].value.as < std::vector<uint16_t> > ());
	}
#line 2869 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 145: // variable_option: BLOCK_BEGIN AVAILABLE_EVENT_LIST event_list BLOCK_END AVAILABLE_EVENT_LIST
#line 706 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetAvailableEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2878 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 146: // variable_option: BLOCK_BEGIN DEFAULT_EVENT_LIST event_list BLOCK_END DEFAULT_EVENT_LIST
#line 711 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetDefaultEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2887 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 147: // variable_option: BLOCK_BEGIN CONSISTENCY_EVENT_LIST event_list BLOCK_END CONSISTENCY_EVENT_LIST
#line 716 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetConsistencyEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2896 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 148: // pag: BLOCK_BEGIN PAG UINT freeze_supported BLOCK_END PAG
#line 721 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
     	Pag& pag = scanner.GetPag();
     	pag.SetMaxSegments(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pag > () = std::move(pag);
     	pag.Reset();
     }
#line 2907 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 150: // freeze_supported: FREEZE_SUPPORTED
#line 729 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
     	Pag& pag = scanner.GetPag();
     	pag.SetFreezeSupported();
     }
#line 2916 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 151: // pgm: BLOCK_BEGIN PGM IDENT UINT UINT pgm_options BLOCK_END PGM
#line 736 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	Pgm& pgm = scanner.GetPgm();
     	pgm.SetType(yystack_[5].value.as < std::string > ());
     	pgm.SetMaxSectors(yystack_[4].value.as < uint64_t > ());
     	pgm.SetMaxCtoPgm(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pgm > () = std::move(pgm);
     	pgm.Reset();
     }
#line 2929 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 154: // pgm_option: sector
#line 748 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.AddSector(std::move(yystack_[0].value.as < Sector > ()));
      }
#line 2938 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 155: // pgm_option: communication_mode_supported
#line 751 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.SetCommunicationModeSupported(yystack_[0].value.as < CommunicationMode > ());
      }
#line 2947 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 156: // communication_mode_supported: COMMUNICATION_MODE_SUPPORTED communication_mode_union
#line 756 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = std::move(mode);
             	mode.Reset();
             }
#line 2957 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 157: // communication_mode_supported: BLOCK_BEGIN COMMUNICATION_MODE_SUPPORTED communication_mode_union BLOCK_END COMMUNICATION_MODE_SUPPORTED
#line 762 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = std::move(mode);
             	mode.Reset();
             }
#line 2967 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 160: // communication_mode_union: INTERLEAVED UINT
#line 772 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
        	CommunicationMode& mode = scanner.GetCommunicationMode();
        	mode.SetInterleavedSupported();
        	mode.SetQueueSize(yystack_[0].value.as < uint64_t > ());
            }
#line 2977 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 163: // slave_item: SLAVE
#line 780 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetSlaveModeSupported();
            }
#line 2986 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 165: // master_item: MASTER UINT UINT
#line 785 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetMasterModeSupported();
       		mode.SetMaxBs(yystack_[1].value.as < uint64_t > ());
       		mode.SetMinSt(yystack_[0].value.as < uint64_t > ());
            }
#line 2997 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 166: // sector: BLOCK_BEGIN SECTOR STRING UINT UINT UINT UINT UINT UINT BLOCK_END SECTOR
#line 794 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
        	yylhs.value.as < Sector > ().name = std::move(yystack_[8].value.as < std::string > ());
        	yylhs.value.as < Sector > ().number = static_cast<uint8_t>(yystack_[7].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().address = static_cast<uint32_t>(yystack_[6].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().length = static_cast<uint32_t>(yystack_[5].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().clear_sequence_number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_sequence_number = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_method = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
        }
#line 3011 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 167: // segment: BLOCK_BEGIN SEGMENT UINT UINT UINT UINT UINT segment_options BLOCK_END SEGMENT
#line 806 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
      	Segment& segment = scanner.GetSegment();
      	segment.SetNumber(yystack_[7].value.as < uint64_t > ());
      	segment.SetNumberOfPages(yystack_[6].value.as < uint64_t > ());
      	segment.SetAddressExtension(yystack_[5].value.as < uint64_t > ());
      	segment.SetCompressionMethod(yystack_[4].value.as < uint64_t > ());
      	segment.SetEncryptionMethod(yystack_[3].value.as < uint64_t > ());
      	yylhs.value.as < Segment > () = std::move(segment);
      	segment.Reset();
      }
#line 3026 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 171: // segment_option: DEFAULT_PAGE_NUMBER UINT
#line 821 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
        Segment& segment = scanner.GetSegment();
        segment.SetDefaultPageNumber(yystack_[0].value.as < uint64_t > ());
      }
#line 3035 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 173: // segment_option: address_mapping
#line 825 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Segment& segment = scanner.GetSegment();
      	segment.AddAddressMapping(std::move(yystack_[0].value.as < AddressMapping > ()));
      }
#line 3044 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 174: // checksum: BLOCK_BEGIN CHECKSUM IDENT checksum_options BLOCK_END CHECKSUM
#line 832 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.SetType(yystack_[3].value.as < std::string > ());
      	Segment& segment = scanner.GetSegment();
      	segment.SetChecksum(std::move(checksum));
      	checksum.Reset();
      }
#line 3056 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 177: // checksum_option: MAX_BLOCK_SIZE UINT
#line 843 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.max_block_size = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3065 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 178: // checksum_option: EXTERNAL_FUNCTION STRING
#line 846 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.external_function = std::move(yystack_[0].value.as < std::string > ());
      }
#line 3074 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 179: // checksum_option: MTA_BLOCK_SIZE_ALIGN UINT
#line 849 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.mta_block_size_align =	static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3083 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 180: // page: BLOCK_BEGIN PAGE UINT IDENT IDENT IDENT init_segment BLOCK_END PAGE
#line 856 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
      	Page& page = scanner.GetPage();
      	page.SetNumber(yystack_[6].value.as < uint64_t > ());
      	page.SetEcuAccessType(yystack_[5].value.as < std::string > ());
      	page.SetReadAccessType(yystack_[4].value.as < std::string > ());
      	page.SetWriteAccessType(yystack_[3].value.as < std::string > ());
      	Segment& segment = scanner.GetSegment();
      	segment.AddPage(std::move(page));
      	page.Reset();
      }
#line 3098 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 181: // address_mapping: BLOCK_BEGIN ADDRESS_MAPPING UINT UINT UINT BLOCK_END ADDRESS_MAPPING
#line 869 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	yylhs.value.as < AddressMapping > ().source_address = static_cast<uint32_t>(yystack_[4].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().destination_address = static_cast<uint32_t>(yystack_[3].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().length = static_cast<uint32_t>(yystack_[2].value.as < uint64_t > ());
      }
#line 3108 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 183: // init_segment: INIT_SEGMENT UINT
#line 876 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Page& page = scanner.GetPage();
      	page.SetInitSegment(yystack_[0].value.as < uint64_t > ());
      }
#line 3117 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 184: // time_correlation: BLOCK_BEGIN TIME_CORRELATION IDENT clock_list BLOCK_END TIME_CORRELATION
#line 883 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
 		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
 		correlation.SetTimestampsRelateTo(yystack_[3].value.as < std::string > ());
		yylhs.value.as < TimeCorrelation > () = std::move(correlation);
 		correlation.Reset();
        }
#line 3128 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 187: // clock: BLOCK_BEGIN CLOCK any_int any_int any_int any_int any_int any_int any_int any_int IDENT IDENT IDENT UINT timestamp_characterization UINT IDENT BLOCK_END CLOCK
#line 896 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
       		Clock& clock = scanner.GetClock();
		clock.SetUuid(yystack_[16].value.as < int64_t > (), 0);
		clock.SetUuid(yystack_[15].value.as < int64_t > (), 1);
		clock.SetUuid(yystack_[14].value.as < int64_t > (), 2);
		clock.SetUuid(yystack_[13].value.as < int64_t > (), 3);
		clock.SetUuid(yystack_[12].value.as < int64_t > (), 4);
		clock.SetUuid(yystack_[11].value.as < int64_t > (), 5);
		clock.SetUuid(yystack_[10].value.as < int64_t > (), 6);
		clock.SetUuid(yystack_[9].value.as < int64_t > (), 7);
		clock.SetType(yystack_[8].value.as < std::string > ());
		clock.SetReadability(yystack_[7].value.as < std::string > ());
		clock.SetSynchronization(yystack_[6].value.as < std::string > ());
		clock.SetClockQuality(yystack_[5].value.as < uint64_t > ());
		clock.SetMaxTimestampValueBeforeWrapAround(yystack_[3].value.as < uint64_t > ());
		clock.SetEpoch(yystack_[2].value.as < std::string > ());
		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
		correlation.AddClock(std::move(clock));
		clock.Reset();
       }
#line 3153 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 189: // timestamp_characterization: BLOCK_BEGIN TIME_CHARACTERIZATION UINT IDENT IDENT BLOCK_END TIME_CHARACTERIZATION
#line 920 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                 {
                TimestampCharacteristic characteristic;
                characteristic.SetTicks(yystack_[4].value.as < uint64_t > ());
                characteristic.SetResolution(yystack_[3].value.as < std::string > ());
                characteristic.SetSize(yystack_[2].value.as < std::string > ());
       		Clock& clock = scanner.GetClock();
       		clock.SetCharacteristic(std::move(characteristic));
        }
#line 3166 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 190: // event_list: %empty
#line 929 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint16_t> > ().clear(); }
#line 3172 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 191: // event_list: event_list event
#line 930 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
            yylhs.value.as < std::vector<uint16_t> > ().push_back(yystack_[0].value.as < uint16_t > ());
            }
#line 3181 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 192: // event: EVENT UINT
#line 934 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3187 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 193: // xcp_on_can: BLOCK_BEGIN XCP_ON_CAN UINT can_parameter_options transport_layer_instance BLOCK_END XCP_ON_CAN
#line 938 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetVersion(yystack_[4].value.as < uint64_t > ());
		can.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
		scanner.SaveXcpOnCan();
       }
#line 3198 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 196: // can_parameter_option: CAN_ID_BROADCAST UINT
#line 948 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdBroadcast(yystack_[0].value.as < uint64_t > ());
        }
#line 3207 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 197: // can_parameter_option: CAN_ID_MASTER UINT
#line 951 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMaster(yystack_[0].value.as < uint64_t > ());
        }
#line 3216 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 198: // can_parameter_option: CAN_ID_MASTER_INCREMENTAL
#line 954 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMasterIncremental();
        }
#line 3225 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 199: // can_parameter_option: CAN_ID_SLAVE UINT
#line 957 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdSlave(yystack_[0].value.as < uint64_t > ());
        }
#line 3234 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 200: // can_parameter_option: CAN_ID_GET_DAQ_CLOCK_MULTICAST UINT
#line 960 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdGetDaqClockMulticast(yystack_[0].value.as < uint64_t > ());
        }
#line 3243 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 201: // can_parameter_option: BAUDRATE UINT
#line 963 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBaudrate(yystack_[0].value.as < uint64_t > ());
        }
#line 3252 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 202: // can_parameter_option: SAMPLE_POINT UINT
#line 966 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSamplePoint(yystack_[0].value.as < uint64_t > ());
        }
#line 3261 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 203: // can_parameter_option: SAMPLE_RATE IDENT
#line 969 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSampleRate(yystack_[0].value.as < std::string > ());
        }
#line 3270 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 204: // can_parameter_option: BTL_CYCLES UINT
#line 972 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBtlCycles(yystack_[0].value.as < uint64_t > ());
        }
#line 3279 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 205: // can_parameter_option: SJW UINT
#line 975 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSjw(yystack_[0].value.as < uint64_t > ());
        }
#line 3288 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 206: // can_parameter_option: SYNC_EDGE IDENT
#line 978 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSyncEdge(yystack_[0].value.as < std::string > ());
        }
#line 3297 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 207: // can_parameter_option: MAX_DLC_REQUIRED
#line 981 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxDlcRequired();
        }
#line 3306 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 210: // can_parameter_option: MAX_BUS_LOAD UINT
#line 986 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
        }
#line 3315 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 211: // can_parameter_option: MEASUREMENT_SPLIT_ALLOWED
#line 990 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMeasurementSplitAllowed();
        }
#line 3324 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 213: // can_parameter_option: OPTIONAL_TL_SUBCMD IDENT
#line 994 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.AddSubCmd(yystack_[0].value.as < std::string > ());
        }
#line 3333 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 214: // can_parameter_option: common_parameter
#line 997 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		CommonParameters& common_parameters = scanner.GetCommonParameters();
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetOverrulingParameters(common_parameters);
		common_parameters.Reset();
        }
#line 3344 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 215: // daq_list_can_id: BLOCK_BEGIN DAQ_LIST_CAN_ID UINT daq_list_can_id_options BLOCK_END DAQ_LIST_CAN_ID
#line 1006 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
	   XcpOnCan& can = scanner.GetXcpOnCan();
           DaqListCanId& daq_list = can.GetCurrentDaqList();
           daq_list.number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
           can.AddDaqList();
        }
#line 3355 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 218: // daq_list_can_id_option: VARIABLE
#line 1016 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.variable = true;
        }
#line 3365 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 219: // daq_list_can_id_option: fixed
#line 1020 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.fixed = static_cast<uint32_t>(yystack_[0].value.as < uint32_t > ());
        }
#line 3375 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 220: // event_can_id_list: BLOCK_BEGIN EVENT_CAN_ID_LIST UINT fixed_list BLOCK_END EVENT_CAN_ID_LIST
#line 1028 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   EventCanIdList list;
	   list.number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	   list.fixed_list = std::move(yystack_[2].value.as < std::vector<uint32_t> > ());
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddCanIdEventList(list);
        }
#line 3387 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 221: // fixed_list: %empty
#line 1036 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint32_t> > () = {};}
#line 3393 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 222: // fixed_list: fixed_list fixed
#line 1037 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
       	yylhs.value.as < std::vector<uint32_t> > () = std::move(yystack_[1].value.as < std::vector<uint32_t> > ());
       	yylhs.value.as < std::vector<uint32_t> > ().push_back(yystack_[0].value.as < uint32_t > ());
       }
#line 3402 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 223: // fixed: FIXED UINT
#line 1041 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint32_t > () = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ()); }
#line 3408 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 224: // can_fd: BLOCK_BEGIN CAN_FD can_fd_options BLOCK_END CAN_FD
#line 1045 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
      	XcpOnCan& can = scanner.GetXcpOnCan();
      	can.SetCanFd();
     }
#line 3417 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 227: // can_fd_option: MAX_DLC UINT
#line 1053 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc = static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3427 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 228: // can_fd_option: CAN_FD_DATA_TRANSFER_BAUDRATE UINT
#line 1057 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.baudrate = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3437 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 229: // can_fd_option: SAMPLE_POINT UINT
#line 1061 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3447 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 230: // can_fd_option: BTL_CYCLES UINT
#line 1065 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.btl_cycles = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3457 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 231: // can_fd_option: SJW UINT
#line 1069 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sjw = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3467 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 232: // can_fd_option: SYNC_EDGE IDENT
#line 1073 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetSyncEdge(yystack_[0].value.as < std::string > ());
     }
#line 3477 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 233: // can_fd_option: MAX_DLC_REQUIRED
#line 1077 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc_required = true;
     }
#line 3487 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 234: // can_fd_option: SECONDARY_SAMPLE_POINT UINT
#line 1081 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.secondary_sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3497 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 235: // can_fd_option: TRANSCEIVER_DELAY_COMPENSATION IDENT
#line 1085 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetTransceiverDelayCompensation(yystack_[0].value.as < std::string > ());
     }
#line 3507 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 236: // xcp_on_sxi: BLOCK_BEGIN XCP_ON_SxI UINT UINT sxi_parameter_options IDENT IDENT sxi_option transport_layer_instance BLOCK_END XCP_ON_SxI
#line 1093 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetVersion(yystack_[8].value.as < uint64_t > ());
               sxi.SetBaudrate(yystack_[7].value.as < uint64_t > ());
               sxi.SetHeaderLength(yystack_[5].value.as < std::string > ());
               sxi.SetChecksum(yystack_[4].value.as < std::string > ());
               sxi.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnSxi();
            }
#line 3521 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 239: // sxi_parameter_option: ASYNCH_FULL_DUPLEX_MODE IDENT IDENT framing
#line 1106 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               AsynchFullDuplexMode& asynch = sxi.GetCurrentAsynch();
               asynch.SetParity(yystack_[2].value.as < std::string > ());
               asynch.SetStopBits(yystack_[1].value.as < std::string > ());
               sxi.SetAsynchFullDuplexMode();
	    }
#line 3533 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 240: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_BYTE
#line 1112 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeByte();
            }
#line 3542 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 241: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_WORD
#line 1115 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeWord();
            }
#line 3551 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 242: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_DWORD
#line 1118 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeDword();
            }
#line 3560 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 243: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_BYTE
#line 1121 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeByte();
            }
#line 3569 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 244: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_WORD
#line 1124 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeWord();
            }
#line 3578 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 245: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_DWORD
#line 1127 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeDword();
            }
#line 3587 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 247: // sxi_option: common_parameter
#line 1133 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
           CommonParameters& common_parameters = scanner.GetCommonParameters();
           XcpOnSxi& sxi = scanner.GetXcpOnSxi();
           sxi.SetOverrulingParameters(common_parameters);
           common_parameters.Reset();
         }
#line 3598 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 249: // framing: BLOCK_BEGIN FRAMING UINT UINT BLOCK_END FRAMING
#line 1143 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
             XcpOnSxi& sxi = scanner.GetXcpOnSxi();
             Framing& framing = sxi.GetCurrentFraming();
             framing.sync = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
             sxi.SetFraming();
           }
#line 3609 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 250: // xcp_on_tcp_ip: BLOCK_BEGIN XCP_ON_TCP_IP UINT UINT tcp_ip_options transport_layer_instance BLOCK_END XCP_ON_TCP_IP
#line 1152 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetVersion(yystack_[5].value.as < uint64_t > ());
               tcp.SetPort(yystack_[4].value.as < uint64_t > ());
               tcp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnTcpIp();
            }
#line 3621 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 253: // tcp_ip_option: HOST_NAME STRING
#line 1163 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetHostName(yystack_[0].value.as < std::string > ());
	     }
#line 3630 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 254: // tcp_ip_option: ADDRESS STRING
#line 1166 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetAddress(yystack_[0].value.as < std::string > ());
	     }
#line 3639 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 255: // tcp_ip_option: IPV6 STRING
#line 1169 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetIpv6(yystack_[0].value.as < std::string > ());
	     }
#line 3648 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 256: // tcp_ip_option: MAX_BUS_LOAD UINT
#line 1172 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
	     }
#line 3657 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 257: // tcp_ip_option: MAX_BIT_RATE UINT
#line 1175 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
	     }
#line 3666 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 258: // tcp_ip_option: PACKET_ALIGNMENT IDENT
#line 1178 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
	     }
#line 3675 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 259: // tcp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1181 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.AddSubCmd(yystack_[0].value.as < std::string > ());
	     }
#line 3684 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 260: // tcp_ip_option: common_parameter
#line 1184 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
	     }
#line 3695 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 261: // xcp_on_udp_ip: BLOCK_BEGIN XCP_ON_UDP_IP UINT UINT udp_ip_options transport_layer_instance BLOCK_END XCP_ON_UDP_IP
#line 1193 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetVersion(yystack_[5].value.as < uint64_t > ());
               udp.SetPort(yystack_[4].value.as < uint64_t > ());
               udp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnUdpIp();
             }
#line 3707 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 264: // udp_ip_option: HOST_NAME STRING
#line 1204 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetHostName(yystack_[0].value.as < std::string > ());
	    }
#line 3716 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 265: // udp_ip_option: ADDRESS STRING
#line 1207 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetAddress(yystack_[0].value.as < std::string > ());
            }
#line 3725 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 266: // udp_ip_option: IPV6 STRING
#line 1210 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetIpv6(yystack_[0].value.as < std::string > ());
            }
#line 3734 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 267: // udp_ip_option: MAX_BUS_LOAD UINT
#line 1213 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
            }
#line 3743 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 268: // udp_ip_option: MAX_BIT_RATE UINT
#line 1216 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
            }
#line 3752 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 269: // udp_ip_option: PACKET_ALIGNMENT IDENT
#line 1219 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
            }
#line 3761 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 270: // udp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1222 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.AddSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3770 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 271: // udp_ip_option: common_parameter
#line 1225 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
            }
#line 3781 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 272: // xcp_on_usb: BLOCK_BEGIN XCP_ON_USB UINT UINT UINT UINT IDENT usb_options transport_layer_instance BLOCK_END XCP_ON_USB
#line 1234 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
                XcpOnUsb& usb = scanner.GetXcpOnUsb();
                usb.SetVersion(yystack_[8].value.as < uint64_t > ());
                usb.SetVendorId(yystack_[7].value.as < uint64_t > ());
                usb.SetProductId(yystack_[6].value.as < uint64_t > ());
                usb.SetNumberOfInterfaces(yystack_[5].value.as < uint64_t > ());
                usb.SetHeaderLength(yystack_[4].value.as < std::string > ());
                usb.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
            	scanner.SaveXcpOnUsb();
            }
#line 3796 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 275: // usb_option: BLOCK_BEGIN OUT_EP_CMD_STIM ep_parameters BLOCK_END OUT_EP_CMD_STIM
#line 1250 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetOutEpCmdStim();
            }
#line 3805 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 276: // usb_option: BLOCK_BEGIN IN_EP_RESERR_DAQ_EVSERV ep_parameters BLOCK_END IN_EP_RESERR_DAQ_EVSERV
#line 1255 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetInEpReserrDaqEvserv();
            }
#line 3814 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 277: // usb_option: ALTERNATE_SETTING_NO UINT
#line 1258 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetAlternateSettingNo(yystack_[0].value.as < uint64_t > ());
            }
#line 3823 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 278: // usb_option: INTERFACE_STRING_DESCRIPTOR STRING
#line 1261 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetInterfaceStringDescriptor(yystack_[0].value.as < std::string > ());
            }
#line 3832 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 279: // usb_option: BLOCK_BEGIN OUT_EP_ONLY_STIM ep_parameters BLOCK_END OUT_EP_ONLY_STIM
#line 1266 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddOutEpOnlyStim();
            }
#line 3841 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 280: // usb_option: BLOCK_BEGIN IN_EP_ONLY_DAQ ep_parameters BLOCK_END IN_EP_ONLY_DAQ
#line 1271 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddInEpOnlyDaq();
            }
#line 3850 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 281: // usb_option: BLOCK_BEGIN IN_EP_ONLY_EVSERV ep_parameters BLOCK_END IN_EP_ONLY_EVSERV
#line 1276 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddDaqListUsbEndpoint();
            }
#line 3859 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 282: // usb_option: daq_list_usb_endpoint
#line 1279 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
            	XcpOnUsb& usb = scanner.GetXcpOnUsb();
            	usb.AddDaqListUsbEndpoint();
            }
#line 3868 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 283: // usb_option: OPTIONAL_TL_SUBCMD IDENT
#line 1282 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
  		XcpOnUsb& usb = scanner.GetXcpOnUsb();
  		usb.AddSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3877 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 284: // usb_option: common_parameter
#line 1285 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               CommonParameters& common_parameters = scanner.GetCommonParameters();
               XcpOnUsb& usb = scanner.GetXcpOnUsb();
               usb.SetOverrulingParameters(common_parameters);
               common_parameters.Reset();
          }
#line 3888 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 285: // daq_list_usb_endpoint: BLOCK_BEGIN DAQ_LIST_USB_ENDPOINT UINT fixed_in fixed_out BLOCK_END DAQ_LIST_USB_ENDPOINT
#line 1294 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.number = yystack_[4].value.as < uint64_t > ();
          }
#line 3898 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 287: // fixed_in: FIXED_IN UINT
#line 1300 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_in = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3908 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 289: // fixed_out: FIXED_OUT UINT
#line 1306 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_out = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3918 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 290: // ep_parameters: UINT IDENT UINT UINT IDENT IDENT recommended_host_bufsize
#line 1311 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                         {
	XcpOnUsb& usb = scanner.GetXcpOnUsb();
        EpParameters& ep_par = usb.GetEpParameters();
        ep_par.SetEndpointNumber(yystack_[6].value.as < uint64_t > ());
        ep_par.SetTransferType(yystack_[5].value.as < std::string > ());
        ep_par.SetMaxPacketSize(yystack_[4].value.as < uint64_t > ());
        ep_par.SetInterval(yystack_[3].value.as < uint64_t > ());
        ep_par.SetMessagePacking(yystack_[2].value.as < std::string > ());
        ep_par.SetUsbAlignment(yystack_[1].value.as < std::string > ());
	}
#line 3933 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 292: // recommended_host_bufsize: RECOMMENDED_HOST_BUFSIZE UINT
#line 1322 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {

           }
#line 3941 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 293: // xcp_on_flx: BLOCK_BEGIN XCP_ON_FLX UINT UINT STRING STRING UINT IDENT IDENT flx_options transport_layer_instance BLOCK_END XCP_ON_FLX
#line 1328 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
              XcpOnFlx& flx = scanner.GetXcpOnFlx();
              flx.SetVersion(yystack_[10].value.as < uint64_t > ());
              flx.SetT1Flx(yystack_[9].value.as < uint64_t > ());
              flx.SetFibexFile(yystack_[8].value.as < std::string > ());
              flx.SetClusterId(yystack_[7].value.as < std::string > ());
              flx.SetNax(yystack_[6].value.as < uint64_t > ());
              flx.SetHeaderNax(yystack_[5].value.as < std::string > ());
              flx.SetPacketAlignment(yystack_[4].value.as < std::string > ());
              flx.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
              scanner.SaveXcpOnFlx();
              flx.Reset();
        }
#line 3959 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 296: // flx_option: BLOCK_BEGIN INITIAL_CMD_BUFFER buffer BLOCK_END INITIAL_CMD_BUFFER
#line 1346 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
            flx.SetInitialCmdBuffer(buffer);
            buffer.Reset();
       	  }
#line 3970 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 297: // flx_option: BLOCK_BEGIN INITIAL_RES_ERR_BUFFER buffer BLOCK_END INITIAL_RES_ERR_BUFFER
#line 1353 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
            flx.SetInitialResErrBuffer(buffer);
            buffer.Reset();
          }
#line 3981 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 298: // flx_option: BLOCK_BEGIN POOL_BUFFER buffer BLOCK_END POOL_BUFFER
#line 1360 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
            flx.AddPoolBuffer(buffer);
            buffer.Reset();
          }
#line 3992 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 299: // flx_option: OPTIONAL_TL_SUBCMD IDENT
#line 1365 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            flx.AddSubCmd(yystack_[0].value.as < std::string > ());
          }
#line 4001 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 300: // flx_option: common_parameter
#line 1368 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            CommonParameters& common_parameters = scanner.GetCommonParameters();
            scanner.GetXcpOnFlx().SetOverrulingParameters(common_parameters);
            common_parameters.Reset();
         }
#line 4011 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 301: // buffer: UINT buffer_options
#line 1374 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  buffer.SetBufferNo(yystack_[1].value.as < uint64_t > ());
	}
#line 4021 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 304: // buffer_option: MAX_FLX_LEN_BUF max_flx_len_buf_union
#line 1381 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                     {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetMaxFlxLenBuffer(var_fixed);
	  var_fixed.Reset();
	}
#line 4033 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 307: // max_flx_len_buf_union: FIXED UINT
#line 1390 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4044 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 308: // max_flx_len_buf_union: VARIABLE UINT
#line 1395 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = yystack_[0].value.as < uint64_t > ();
	}
#line 4055 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 316: // flx_slot_id_union: FLX_SLOT_ID lpu_id_union
#line 1411 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetFlxSlotId(var_fixed);
	  var_fixed.Reset();
	}
#line 4067 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 317: // offset_union: OFFSET lpu_id_option
#line 1418 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetOffset(var_fixed);
	  var_fixed.Reset();
	}
#line 4079 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 318: // cycle_repetition: CYCLE_REPETITION lpu_id_union
#line 1425 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetCycleRepetition(var_fixed);
	  var_fixed.Reset();
	}
#line 4091 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 319: // channel: CHANNEL channel_union
#line 1432 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetChannel(var_fixed);
	  var_fixed.Reset();
	}
#line 4103 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 320: // channel_union: FIXED IDENT
#line 1439 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.FixedChannel(yystack_[0].value.as < std::string > ());
	  var_fixed.fixed = static_cast<uint64_t>(
               	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4116 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 321: // channel_union: VARIABLE initial_enum
#line 1446 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = static_cast<uint64_t>(
	  	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4128 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 322: // initial_enum: %empty
#line 1453 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < bool > () = false; }
#line 4134 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 323: // initial_enum: INITIAL_VALUE IDENT
#line 1454 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel(yystack_[0].value.as < std::string > ());
	  yylhs.value.as < bool > () = true;
        }
#line 4146 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 324: // lpu_id_union: FIXED UINT
#line 1462 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4157 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 325: // lpu_id_union: VARIABLE initial_value
#line 1467 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = var_fixed.initial_value.value_or(0);
	}
#line 4168 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 326: // initial_value: %empty
#line 1473 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < bool > () = false;}
#line 4174 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 327: // initial_value: INITIAL_VALUE UINT
#line 1474 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.initial_value = yystack_[0].value.as < uint64_t > ();
	  yylhs.value.as < bool > () = true;
       }
#line 4186 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 331: // xcp_packet_option: CMD IDENT
#line 1489 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetCmd(yystack_[0].value.as < std::string > ());
 	}
#line 4196 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 332: // xcp_packet_option: RES_ERR IDENT
#line 1493 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetResErr(yystack_[0].value.as < std::string > ());
 	}
#line 4206 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 333: // xcp_packet_option: EV_SERV IDENT
#line 1497 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetEvServ(yystack_[0].value.as < std::string > ());
 	}
#line 4216 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 334: // xcp_packet_option: DAQ IDENT
#line 1501 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetDaq(yystack_[0].value.as < std::string > ());
 	}
#line 4226 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 335: // xcp_packet_option: STIM IDENT
#line 1505 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
 	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
 	  	buffer.SetStim(yystack_[0].value.as < std::string > ());
 	}
#line 4236 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 336: // xcp_packet_option: MULTICAST IDENT
#line 1509 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
  	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
  	  	buffer.SetMulticast(yystack_[0].value.as < std::string > ());
 	}
#line 4246 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 337: // xcp_on_simulink: BLOCK_BEGIN XCP_ON_SIMULINK simulink_options transport_layer_instance BLOCK_END XCP_ON_SIMULINK
#line 1517 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
                   XcpOnSimulink& simulink = scanner.GetXcpOnSimulink();
                   simulink.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
                   scanner.SaveXcpOnSimulink();
                 }
#line 4256 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 340: // simulink_option: MODEL_NAME STRING
#line 1526 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		   scanner.GetXcpOnSimulink().SetModelName(yystack_[0].value.as < std::string > ());
		 }
#line 4264 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 341: // simulink_option: common_parameter
#line 1528 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
                    CommonParameters& common_parameters = scanner.GetCommonParameters();
                    scanner.GetXcpOnSimulink().SetOverrulingParameters(common_parameters);
                 }
#line 4273 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 342: // consistency: DAQ
#line 1533 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::string > () = "DAQ"; }
#line 4279 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 343: // consistency: EVENT
#line 1534 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < std::string > () = "EVENT"; }
#line 4285 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 344: // consistency: ODT
#line 1535 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "ODT"; }
#line 4291 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 345: // consistency: NONE
#line 1536 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::string > () = "NONE"; }
#line 4297 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 346: // daq_list_type: DAQ
#line 1538 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "DAQ"; }
#line 4303 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 347: // daq_list_type: STIM
#line 1539 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < std::string > () = "STIM"; }
#line 4309 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 348: // daq_list_type: DAQ_STIM
#line 1540 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = "DAQ_STIM"; }
#line 4315 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 349: // transport_layer_instance: %empty
#line 1542 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::string > ().clear(); }
#line 4321 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 350: // transport_layer_instance: TRANSPORT_LAYER_INSTANCE STRING
#line 1543 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4327 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 351: // ident_or_string: IDENT
#line 1545 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4333 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 352: // ident_or_string: STRING
#line 1546 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4339 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 353: // any_float: FLOAT
#line 1548 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 4345 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 354: // any_float: INT
#line 1549 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 4351 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 355: // any_float: UINT
#line 1550 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 4357 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 356: // any_int: INT
#line 1552 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 4363 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 357: // any_int: UINT
#line 1553 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 4369 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;


#line 4373 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

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









  const short XcpDataParser::yypact_ninf_ = -706;

  const signed char XcpDataParser::yytable_ninf_ = -1;

  const short
  XcpDataParser::yypact_[] =
  {
      13,   -28,    82,  -133,  -706,  -706,  -155,    72,    83,  -706,
      55,   241,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,    83,
    -706,   -41,   -56,   -32,   -34,   -17,    24,    -4,    27,    37,
      47,    49,    57,    63,  -706,    67,  -706,  -706,   175,  -706,
    -706,   116,    78,    80,   104,  -706,  -706,   105,   107,   110,
     112,   113,     6,   122,   131,   244,   227,  -706,   267,   125,
     127,   128,   164,    89,  -706,  -706,  -706,   133,   129,   188,
     132,   139,  -706,  -706,   297,   145,   147,  -706,    39,  -706,
    -706,   197,  -706,   149,   150,   304,   174,  -706,   157,    97,
     159,   162,   165,  -706,   169,   171,  -706,   176,  -706,   177,
     178,   179,   180,   185,  -706,  -706,  -706,  -706,  -706,   336,
       0,     1,     3,   190,   172,  -706,  -706,   181,   191,  -706,
    -706,  -706,  -706,  -706,    43,   201,   202,  -107,  -706,  -706,
    -706,   203,   205,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,   214,   193,  -706,  -706,  -706,  -706,
    -706,  -706,   208,  -706,   210,   212,   213,   219,   221,   209,
     218,  -706,  -706,   368,   225,   226,   235,   224,   245,   222,
     237,  -706,  -706,   384,   240,   246,  -706,   243,    17,    20,
      30,   -19,   295,    54,  -706,  -706,  -706,   249,  -706,  -706,
    -706,  -107,    21,  -706,  -706,  -706,   248,   412,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,   260,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   262,  -706,   255,   256,   427,   407,   385,
      54,   258,  -706,   294,   429,   268,  -706,   269,    46,  -107,
     430,   270,   275,  -706,   277,   278,   279,   280,   281,   283,
    -706,    -5,     7,   444,  -706,   296,  -706,  -706,    -1,   284,
    -130,  -706,  -706,  -706,   447,   289,  -706,  -706,   376,   294,
    -706,   292,    12,   326,   298,  -706,  -706,  -706,  -706,  -107,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   422,
     299,  -706,  -706,  -706,   405,  -706,   396,  -706,   458,   301,
     323,   303,   302,  -706,  -706,  -706,   461,  -706,   305,   310,
     448,   311,   312,  -706,   464,   313,   314,   315,   316,  -706,
    -706,  -107,  -706,  -706,  -706,   317,   322,  -706,   318,   320,
     320,   320,   320,   320,  -706,  -706,   308,     5,  -706,   319,
    -706,   321,   324,   468,   325,   327,  -706,   328,  -107,   329,
    -706,   425,   330,   487,   489,   491,   492,   494,  -706,   300,
     331,  -706,  -706,   497,   160,  -706,   337,  -706,  -706,   334,
     339,   123,   338,  -107,   501,   341,   445,   344,   441,   442,
     440,   400,   401,   349,   349,   349,  -706,   354,    42,   484,
    -102,  -102,   353,  -706,   355,   356,   357,   358,   359,   360,
     361,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   257,   362,   350,   524,   513,   363,   365,
     366,  -706,   367,  -107,   467,  -706,   369,   531,   372,  -706,
    -706,  -706,  -706,  -706,  -706,   534,   535,   536,  -706,   377,
     378,   379,    41,   380,   381,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   508,
     382,  -706,   550,  -706,  -706,  -706,  -706,   476,   383,  -706,
    -706,   512,   386,     9,   477,   478,   434,  -102,  -706,   391,
    -706,  -706,    41,   392,   389,  -706,   555,    50,  -706,   395,
     557,   393,  -706,   394,   -43,   -59,  -706,  -706,  -706,  -706,
    -706,  -706,   560,   192,   402,   403,   564,   397,   438,    -6,
     449,   406,   404,   408,   409,  -706,  -706,  -706,  -706,   453,
     411,   450,  -706,  -706,   410,   413,  -706,   554,   460,   546,
     -16,  -706,   418,   419,   420,   421,  -706,   423,   -16,  -706,
     490,   437,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     424,   426,  -706,    16,   106,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   428,   431,
     432,   588,  -706,   590,   167,   592,  -706,   519,   -46,   -45,
     -45,    29,  -706,  -706,  -706,  -706,  -706,   435,   433,   436,
     439,   443,   446,   451,  -706,   173,   452,   454,  -706,   462,
     455,   466,   553,  -706,   459,   456,  -706,   457,   528,  -706,
     463,   537,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   504,   493,  -706,   608,   465,  -706,  -706,   469,
    -706,   470,   471,  -706,   472,  -706,  -706,   473,  -706,   474,
    -706,   607,   612,   479,   475,   480,   614,  -706,  -706,  -706,
     481,   582,  -706,   571,   482,   610,    14,   483,  -706,   282,
    -706,   485,   620,  -706,   520,   488,  -706,   625,   207,   577,
     495,    86,   496,  -102,   486,  -706,   498,  -706,  -706,   499,
     500,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   502,
     509,  -706,   503,   626,  -102,  -102,  -102,  -102,   505,  -706,
     507,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     510,  -706,   511,  -706,   514,  -706,  -102,  -102,  -102,  -102,
     515,  -706,  -706,   516,   517,  -102,  -102,   630,   630,   518,
    -706,   521,   633,   633,   613,   638,  -706,   639,  -706,   523,
     196,  -706,    19,   223,  -706,  -706,  -706,   236,  -706,  -706,
    -706,   525,   617,   622,  -706,   552,   522,  -706,   526,   628,
    -706,   629,  -706,  -102,  -706,  -706,    33,   527,  -706,  -102,
    -706,  -706,   658,   529,   632,  -706,   530,   659,   642,  -706,
    -706,   532,   562,  -706,   533,  -706,   666,   578,  -706
  };

  const short
  XcpDataParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     5,     0,     0,     4,     5,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     3,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,     0,   190,   143,     0,   139,
     140,   149,     0,     0,     0,   185,   194,     0,     0,     0,
       0,     0,   349,     0,   141,   142,     0,   150,     0,     0,
       0,     0,     0,   349,   237,   251,   262,     0,     0,     0,
       0,     0,   341,   339,     0,     0,     0,   191,     0,   144,
     138,     0,   152,     0,     0,     0,     0,   186,     0,     0,
       0,     0,     0,   198,     0,     0,   207,     0,   211,     0,
       0,     0,     0,     0,   214,   195,   208,   209,   212,     0,
       0,   349,   349,     0,     0,   340,   350,     0,     0,   192,
     190,   190,   190,   148,     0,     0,     0,     0,   184,   201,
     225,     0,     0,   204,   196,   197,   199,   200,   210,   213,
     202,   203,   205,   206,     0,     0,   240,   241,   242,   243,
     244,   245,     0,   238,     0,     0,     0,     0,     0,     0,
       0,   260,   252,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   263,     0,     0,     0,   337,     0,     0,     0,
       0,     0,     0,     0,   153,   155,   154,     0,   168,   357,
     356,     0,     0,   216,   221,   193,     0,   246,   254,   253,
     255,   256,   257,   259,   258,     0,   265,   264,   266,   267,
     268,   270,   269,     0,   273,     0,     0,     0,     0,     0,
       0,     0,   151,   162,     0,     0,   156,     0,     0,     0,
       0,     0,     0,   233,     0,     0,     0,     0,     0,     0,
     226,     0,     0,   248,   247,   349,   250,   261,   349,     0,
       0,   145,   147,   146,     0,     0,   163,   158,   164,   162,
     160,     0,     0,     0,     0,   169,   170,   172,   173,     0,
     224,   230,   228,   227,   229,   234,   231,   232,   235,     0,
       0,   218,   217,   219,     0,   222,     0,   239,     0,     0,
       0,     0,     0,   284,   274,   282,     0,   294,     0,     0,
       0,     0,     0,   161,     0,     0,     0,     0,     0,   167,
     171,     0,   215,   223,   220,     0,     0,   277,     0,     0,
       0,     0,     0,     0,   278,   283,     0,   349,    43,     0,
     157,     0,     0,     0,     0,     0,   175,     0,     0,     0,
     236,   286,     0,     0,     0,     0,     0,     0,   272,     0,
       0,   300,   295,     0,     0,    43,     0,   165,   159,     0,
       0,     0,     0,     0,     0,     0,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   299,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    50,    53,    46,    47,    48,    44,    51,    52,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,     0,     0,   287,     0,     0,     0,   280,
     281,   276,   279,   275,   302,     0,     0,     0,   293,     0,
       0,     0,     0,     0,     0,    42,   355,   354,   353,    62,
      61,    45,    54,    56,    59,    60,    58,    57,    55,     0,
       0,    24,     0,   174,   178,   177,   179,   182,     0,   249,
     289,     0,     0,   301,     0,     0,     0,     0,    80,     0,
     351,   352,     0,     0,     0,    41,     0,     0,   181,     0,
       0,     0,   285,     0,     0,     0,   303,   305,   306,   296,
     297,   298,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    31,    28,   183,     0,
       0,   291,   310,   329,     0,     0,   304,     0,     0,     0,
       0,    87,     0,     0,     0,     0,    81,     0,     0,    69,
      70,    73,   166,    33,    23,    30,    26,    27,    29,   180,
       0,     0,   290,     0,     0,   307,   308,    75,    89,    79,
     346,   348,   347,    82,    86,    85,    83,    84,     0,     0,
       0,     0,    74,     0,     0,   188,   292,     0,     0,     0,
       0,     0,   311,   312,   313,   314,   315,     0,     0,     0,
       0,     0,     0,     0,   330,     0,     0,     0,    71,     0,
       0,     0,     0,    34,     0,     0,   309,     0,   322,   319,
       0,   326,   318,   316,   317,   328,   331,   334,   333,   336,
     332,   335,     0,     0,    90,    77,     0,    67,    72,     0,
      32,     0,     0,   320,     0,   321,   324,     0,   325,     0,
      88,     0,     0,     0,     0,     0,     0,   323,   327,    92,
       0,     0,    96,    36,     0,     0,     0,     0,    76,     0,
      37,     0,     0,   187,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,   106,   100,     0,
       0,   102,   107,    97,   108,   112,   113,   114,   115,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,    95,
       0,   342,   343,   345,   344,    99,    98,   111,   103,   105,
       0,   101,     0,   189,     0,    78,     0,     0,     0,     0,
       0,   110,   109,     0,     0,     0,     0,   132,   135,     0,
      38,     0,     0,     0,     0,     0,   133,     0,   136,     0,
       0,    94,     0,     0,   121,   123,   124,     0,   126,   128,
     129,     0,     0,     0,   117,     0,     0,    39,     0,     0,
     122,     0,   127,     0,   131,   134,     0,     0,    35,     0,
     120,   125,     0,     0,     0,   118,     0,     0,     0,   119,
     116,     0,     0,   137,     0,   130,     0,     0,    40
  };

  const short
  XcpDataParser::yypgoto_[] =
  {
    -706,  -706,  -706,   677,  -706,   -61,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,   333,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   -53,  -706,  -706,   -60,  -705,  -706,  -706,  -706,
    -706,  -521,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   215,   506,   538,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,    84,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   539,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   -58,  -706,  -706,  -706,  -706,  -117,  -706,
    -706,  -706,  -706,  -706,   111,  -706,  -706,  -706,  -706,  -706,
    -706,   126,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     170,   -71,   230,  -391,  -198
  };

  const short
  XcpDataParser::yydefgoto_[] =
  {
       0,     2,     7,     8,    12,    13,    14,    15,   487,   515,
     516,   574,   603,   661,   740,   757,    16,   364,   406,   407,
     540,   571,   408,   573,   409,   410,   642,   411,   503,   536,
     595,   624,   656,   666,   412,   659,   683,   684,   766,   775,
     685,   743,   744,   686,   747,   748,   745,   687,   735,   688,
     737,   746,    17,    48,    49,    50,    65,    89,    18,    68,
      19,   134,   194,   195,   236,   267,   268,   313,   196,    20,
     238,   275,   276,   371,   421,   277,   278,   490,    21,    72,
      97,   605,    64,    87,    22,    73,   115,   116,   251,   292,
     117,   252,   293,   118,   202,   250,    23,   120,   163,   255,
     297,    24,   121,   172,    25,   122,   182,    26,   258,   304,
     305,   376,   427,   353,   552,    27,   337,   362,   435,   473,
     496,   526,   497,   553,   582,   583,   584,   585,   586,   609,
     635,   612,   638,   498,   554,   594,    28,    62,    83,   705,
     563,    84,   482,   449,   201
  };

  const short
  XcpDataParser::yytable_[] =
  {
     450,    82,   119,   239,   164,   299,   174,   155,   289,   230,
     524,   300,   114,    79,    46,    79,   316,   359,    79,     9,
     294,   494,   230,   607,   610,     1,   560,   664,   749,   577,
     227,     5,     6,   228,   240,   241,   561,   317,   773,   242,
     578,   279,   749,   229,   308,   522,   774,   130,   309,     3,
     173,   183,   751,   578,   543,   191,   192,   579,   272,   273,
     171,   181,   509,   510,   290,   233,   234,   199,   131,   200,
     579,   193,   446,   439,   447,   448,   290,   165,   193,   175,
      86,   321,     4,    86,   301,    10,   502,   440,   166,   580,
     176,   441,   132,    86,   167,    11,   177,   168,    98,   178,
     274,    99,   580,   100,   525,   442,   495,    47,   101,   102,
     103,   104,   105,   243,   140,   244,    80,   608,   611,   587,
     302,   231,   169,   348,   179,   170,   360,   180,   701,   665,
     523,   562,    30,   588,   581,   758,   417,    45,   318,    31,
     235,    32,    51,   141,    52,   511,   254,   581,   589,   702,
     373,   156,   157,   158,   159,   160,   161,    53,   291,   245,
      81,   142,    81,   246,    81,   247,    81,    81,   590,   512,
     513,   248,   388,   389,    55,   423,    95,    96,   162,   601,
     602,   106,   107,   249,   298,   622,   623,   306,    66,   443,
     418,    67,   390,   514,    86,   108,   391,   303,    54,   703,
     704,    56,   444,   392,   528,   529,   736,   738,   755,   756,
     109,    57,   750,   419,   188,   189,   190,   393,   591,   480,
     481,    58,    33,    59,    34,   468,   750,   110,   111,    35,
      31,    60,    32,   112,   420,   742,   759,    61,    36,   113,
     530,    63,   592,   531,   694,   695,   696,   697,   742,   761,
      81,   394,    69,   593,    70,    37,    88,   698,   532,   395,
     533,   396,   397,   398,   399,   400,   363,   436,   437,   388,
     459,    90,   354,   355,   356,   357,   361,   401,    71,    74,
      91,    75,   707,    31,    76,    32,    77,    78,   402,   390,
     534,   403,   535,   391,   668,   669,    85,   404,   670,    92,
     392,    93,    94,   716,   717,   718,   719,   123,   124,   405,
     127,   125,   671,    33,   393,    34,   672,   673,   126,   128,
      35,   129,   133,   135,   136,   725,   726,   727,   728,    36,
     137,   139,   138,   143,   732,   733,   144,   674,   675,   145,
     676,   677,    31,   146,    32,   147,    37,   678,   394,   154,
     148,   185,   150,   186,   152,   149,   395,   151,   396,   397,
     398,   399,   400,   153,   184,    31,    33,    32,    34,   187,
     328,   206,   772,    35,   401,   197,   198,   203,   777,   204,
     205,   215,    36,   383,   384,   402,   207,   213,   403,   208,
     679,   209,   210,   211,   404,   212,   214,   223,   219,    37,
     221,   329,   330,   331,   216,   217,   405,    38,    39,    40,
      41,    42,    43,    44,   218,   222,   680,   681,   224,   220,
     225,   226,   232,   237,    79,    33,   253,    34,   256,   385,
     682,   257,    35,   259,   260,   261,   262,   265,   263,   266,
     269,    36,   270,   271,   281,   332,   333,   280,    33,   282,
      34,   283,   284,   285,   286,    35,   296,    81,    37,   287,
     310,   288,   307,   311,    36,   312,   315,   319,   322,   324,
     325,   326,   320,   323,   336,   327,   340,   343,   358,   368,
     335,    37,   334,   338,   339,   341,   342,   344,   345,   350,
     347,   349,   351,   346,   352,   366,   375,   365,   367,   369,
     378,   370,   379,   374,   380,   381,   372,   382,   377,   386,
     387,   414,   415,   416,   424,   425,   422,   426,   428,   429,
     431,   430,   432,   434,   433,   438,   445,   451,   461,   452,
     453,   454,   455,   456,   457,   458,   460,   462,   463,   465,
     466,   469,   464,   470,   471,   467,   472,   474,   475,   476,
     485,   477,   478,   479,   488,   484,   486,   489,   483,   492,
     499,   491,   500,   501,   493,   504,   506,   507,   508,   518,
     519,   520,   521,   527,   539,   541,   537,   538,   542,   549,
     545,   544,   546,   551,   555,   557,   547,   556,   548,   550,
     558,   559,   564,   565,   566,   567,   572,   568,   575,   570,
     576,   599,   596,   600,   604,   597,   598,   606,   615,   627,
     634,   616,   629,   630,   617,   628,   631,   618,   639,   637,
     641,   619,   650,   640,   620,   651,   625,   655,   626,   621,
     632,   658,   660,   690,   691,   633,   663,   636,   693,   643,
     699,   715,   734,   644,   645,   742,   751,   648,   649,   646,
     647,   752,   753,   652,   653,   657,   764,   667,   654,   767,
     662,   765,   692,   689,   708,   770,   713,   771,   768,   700,
     706,   778,   782,   710,   711,   783,   709,   714,   785,   787,
     712,   721,   780,   720,   722,   788,    29,   762,   724,   723,
     760,   731,   614,   729,   730,   741,   739,   754,   413,   763,
     769,   776,   517,   779,   781,     0,   613,     0,   569,     0,
     784,   786,   505,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   295,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   314
  };

  const short
  XcpDataParser::yycheck_[] =
  {
     391,    62,    73,   201,     3,     6,     3,     7,    13,    28,
      69,    12,    73,    12,    70,    12,     4,    12,    12,   174,
      13,    12,    28,    69,    69,    12,    42,    13,   733,    13,
      13,   164,   165,    13,    13,    14,    52,    25,     5,    18,
      24,   239,   747,    13,   174,    88,    13,     8,   178,    77,
     121,   122,    33,    24,    60,    12,    13,    41,    12,    13,
     121,   122,    12,    13,    69,    11,    12,   174,    29,   176,
      41,    28,   174,    31,   176,   177,    69,    76,    28,    76,
      63,   279,     0,    63,    85,    13,   477,    45,    87,    73,
      87,    49,    53,    63,    93,    12,    93,    96,     9,    96,
      54,    12,    73,    14,   163,    63,    97,   163,    19,    20,
      21,    22,    23,    92,    17,    94,   110,   163,   163,    13,
     121,   140,   121,   321,   121,   124,   121,   124,    42,   115,
     173,   147,    77,    27,   118,   116,    13,   178,   126,    42,
      86,    44,   174,    46,   178,    95,   207,   118,    42,    63,
     348,   151,   152,   153,   154,   155,   156,   174,   163,   138,
     161,    64,   161,   142,   161,   144,   161,   161,    62,   119,
     120,   150,    12,    13,   178,   373,    12,    13,   178,    12,
      13,    92,    93,   162,   255,    12,    13,   258,    13,   147,
      67,    75,    32,   143,    63,   106,    36,   258,   174,   113,
     114,   174,   160,    43,    12,    13,   727,   728,    12,    13,
     121,   174,   733,    90,   130,   131,   132,    57,   112,   178,
     179,   174,   125,   174,   127,   423,   747,   138,   139,   132,
      42,   174,    44,   144,   111,    12,    13,   174,   141,   150,
      48,   174,   136,    51,    37,    38,    39,    40,    12,    13,
     161,    91,   174,   147,   174,   158,    12,    50,    66,    99,
      68,   101,   102,   103,   104,   105,   337,   384,   385,    12,
      13,    44,   330,   331,   332,   333,   337,   117,   174,   174,
      13,   174,   673,    42,   174,    44,   174,   174,   128,    32,
      98,   131,   100,    36,    12,    13,   174,   137,    16,   174,
      43,   174,   174,   694,   695,   696,   697,   174,   179,   149,
      13,   179,    30,   125,    57,   127,    34,    35,   179,   174,
     132,   174,   125,   174,   174,   716,   717,   718,   719,   141,
      26,   174,   158,   174,   725,   726,   174,    55,    56,   174,
      58,    59,    42,   174,    44,   174,   158,    65,    91,    13,
     174,   179,   174,   172,   174,   178,    99,   178,   101,   102,
     103,   104,   105,   178,   174,    42,   125,    44,   127,   178,
      47,   178,   763,   132,   117,   174,   174,   174,   769,   174,
     166,    13,   141,    83,    84,   128,   178,   178,   131,   179,
     108,   179,   179,   174,   137,   174,   178,    13,   174,   158,
     178,    78,    79,    80,   179,   179,   149,   166,   167,   168,
     169,   170,   171,   172,   179,   178,   134,   135,   178,   174,
     174,   178,   127,   174,    12,   125,   178,   127,   168,   129,
     148,   169,   132,   178,   178,     8,    29,   179,    53,   145,
      11,   141,   174,   174,   174,   122,   123,    17,   125,   174,
     127,   174,   174,   174,   174,   132,    12,   161,   158,   178,
      13,   178,   178,   174,   141,    89,   174,   141,    46,    64,
      74,    13,   174,   174,    13,   174,    28,    13,   170,    11,
     178,   158,   179,   178,   174,   174,   174,   174,   174,   167,
     174,   174,   174,   178,   174,   174,    71,   178,   174,   174,
      13,   174,    13,   174,    13,    13,   178,    13,   178,   178,
      13,   174,   178,   174,    13,   174,   178,    72,   174,    78,
      80,    79,   122,   174,   123,   171,    42,   174,   178,   174,
     174,   174,   174,   174,   174,   174,   174,    13,    25,   174,
     174,    74,   179,   174,    13,   178,   174,    13,    13,    13,
      42,   174,   174,   174,     4,   174,   174,    81,   178,    47,
      83,   178,    84,   129,   178,   174,   174,   178,    13,   174,
      13,   178,   178,    13,    10,   178,   174,   174,   140,   126,
     174,   132,   178,   133,   174,    31,   178,   174,   179,   178,
     130,    45,   174,   174,   174,   174,   159,   174,   174,   109,
     174,    13,   174,    13,    12,   174,   174,    88,   173,   147,
      82,   178,   146,    60,   178,   160,   157,   178,   114,    82,
      12,   178,    15,   130,   178,    13,   174,    13,   174,   178,
     174,    49,    61,    13,   114,   178,    26,   174,    13,   174,
      63,    15,    12,   174,   174,    12,    33,   174,   174,   178,
     178,    13,    13,   174,   179,   174,    39,   174,   178,   107,
     178,    39,   174,   178,   178,    37,   157,    38,   146,   174,
     174,    13,    13,   174,   174,    33,   178,   174,   116,    13,
     178,   174,    50,   178,   174,   107,     9,   747,   174,   178,
     743,   174,   581,   178,   178,   174,   178,   174,   365,   174,
     174,   174,   487,   174,   174,    -1,   580,    -1,   538,    -1,
     178,   178,   482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269
  };

  const short
  XcpDataParser::yystos_[] =
  {
       0,    12,   181,    77,     0,   164,   165,   182,   183,   174,
      13,    12,   184,   185,   186,   187,   196,   232,   238,   240,
     249,   258,   264,   276,   281,   284,   287,   295,   316,   183,
      77,    42,    44,   125,   127,   132,   141,   158,   166,   167,
     168,   169,   170,   171,   172,   178,    70,   163,   233,   234,
     235,   174,   178,   174,   174,   178,   174,   174,   174,   174,
     174,   174,   317,   174,   262,   236,    13,    75,   239,   174,
     174,   174,   259,   265,   174,   174,   174,   174,   174,    12,
     110,   161,   185,   318,   321,   174,    63,   263,    12,   237,
      44,    13,   174,   174,   174,    12,    13,   260,     9,    12,
      14,    19,    20,    21,    22,    23,    92,    93,   106,   121,
     138,   139,   144,   150,   185,   266,   267,   270,   273,   321,
     277,   282,   285,   174,   179,   179,   179,    13,   174,   174,
       8,    29,    53,   125,   241,   174,   174,    26,   158,   174,
      17,    46,    64,   174,   174,   174,   174,   174,   174,   178,
     174,   178,   174,   178,    13,     7,   151,   152,   153,   154,
     155,   156,   178,   278,     3,    76,    87,    93,    96,   121,
     124,   185,   283,   321,     3,    76,    87,    93,    96,   121,
     124,   185,   286,   321,   174,   179,   172,   178,   262,   262,
     262,    12,    13,    28,   242,   243,   248,   174,   174,   174,
     176,   324,   274,   174,   174,   166,   178,   178,   179,   179,
     179,   174,   174,   178,   178,    13,   179,   179,   179,   174,
     174,   178,   178,    13,   178,   174,   178,    13,    13,    13,
      28,   140,   127,    11,    12,    86,   244,   174,   250,   324,
      13,    14,    18,    92,    94,   138,   142,   144,   150,   162,
     275,   268,   271,   178,   185,   279,   168,   169,   288,   178,
     178,     8,    29,    53,   244,   179,   145,   245,   246,    11,
     174,   174,    12,    13,    54,   251,   252,   255,   256,   324,
      17,   174,   174,   174,   174,   174,   174,   178,   178,    13,
      69,   163,   269,   272,    13,   272,    12,   280,   321,     6,
      12,    85,   121,   185,   289,   290,   321,   178,   174,   178,
      13,   174,    89,   247,   245,   174,     4,    25,   126,   141,
     174,   324,    46,   174,    64,    74,    13,   174,    47,    78,
      79,    80,   122,   123,   179,   178,    13,   296,   178,   174,
      28,   174,   174,    13,   174,   174,   178,   174,   324,   174,
     167,   174,   174,   293,   293,   293,   293,   293,   170,    12,
     121,   185,   297,   321,   197,   178,   174,   174,    11,   174,
     174,   253,   178,   324,   174,    71,   291,   178,    13,    13,
      13,    13,    13,    83,    84,   129,   178,    13,    12,    13,
      32,    36,    43,    57,    91,    99,   101,   102,   103,   104,
     105,   117,   128,   131,   137,   149,   198,   199,   202,   204,
     205,   207,   214,   197,   174,   178,   174,    13,    67,    90,
     111,   254,   178,   324,    13,   174,    72,   292,   174,    78,
      79,    80,   122,   123,   174,   298,   298,   298,   171,    31,
      45,    49,    63,   147,   160,    42,   174,   176,   177,   323,
     323,   174,   174,   174,   174,   174,   174,   174,   174,    13,
     174,   178,    13,    25,   179,   174,   174,   178,   324,    74,
     174,    13,   174,   299,    13,    13,    13,   174,   174,   174,
     178,   179,   322,   178,   174,    42,   174,   188,     4,    81,
     257,   178,    47,   178,    12,    97,   300,   302,   313,    83,
      84,   129,   323,   208,   174,   322,   174,   178,    13,    12,
      13,    95,   119,   120,   143,   189,   190,   243,   174,    13,
     178,   178,    88,   173,    69,   163,   301,    13,    12,    13,
      48,    51,    66,    68,    98,   100,   209,   174,   174,    10,
     200,   178,   140,    60,   132,   174,   178,   178,   179,   126,
     178,   133,   294,   303,   314,   174,   174,    31,   130,    45,
      42,    52,   147,   320,   174,   174,   174,   174,   174,   320,
     109,   201,   159,   203,   191,   174,   174,    13,    24,    41,
      73,   118,   304,   305,   306,   307,   308,    13,    27,    42,
      62,   112,   136,   147,   315,   210,   174,   174,   174,    13,
      13,    12,    13,   192,    12,   261,    88,    69,   163,   309,
      69,   163,   311,   311,   304,   173,   178,   178,   178,   178,
     178,   178,    12,    13,   211,   174,   174,   147,   160,   146,
      60,   157,   174,   178,    82,   310,   174,    82,   312,   114,
     130,    12,   206,   174,   174,   174,   178,   178,   174,   174,
      15,    13,   174,   179,   178,    13,   212,   174,    49,   215,
      61,   193,   178,    26,    13,   115,   213,   174,    12,    13,
      16,    30,    34,    35,    55,    56,    58,    59,    65,   108,
     134,   135,   148,   216,   217,   220,   223,   227,   229,   178,
      13,   114,   174,    13,    37,    38,    39,    40,    50,    63,
     174,    42,    63,   113,   114,   319,   174,   323,   178,   178,
     174,   174,   178,   157,   174,    15,   323,   323,   323,   323,
     178,   174,   174,   178,   174,   323,   323,   323,   323,   178,
     178,   174,   323,   323,    12,   228,   231,   230,   231,   178,
     194,   174,    12,   221,   222,   226,   231,   224,   225,   226,
     231,    33,    13,    13,   174,    12,    13,   195,   116,    13,
     222,    13,   225,   174,    39,    39,   218,   107,   146,   174,
      37,    38,   323,     5,    13,   219,   174,   323,    13,   174,
      50,   174,    13,    33,   178,   116,   178,    13,   107
  };

  const short
  XcpDataParser::yyr1_[] =
  {
       0,   180,   181,   182,   182,   183,   183,   184,   184,   185,
     185,   185,   185,   185,   185,   185,   186,   186,   186,   186,
     186,   186,   186,   187,   188,   188,   189,   189,   189,   189,
     189,   189,   190,   191,   191,   192,   193,   193,   194,   194,
     195,   196,   196,   197,   197,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   199,   200,   200,
     201,   201,   202,   203,   203,   204,   205,   206,   206,   207,
     208,   208,   209,   209,   209,   209,   209,   209,   209,   210,
     210,   211,   212,   212,   213,   214,   215,   215,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   217,   218,   218,   219,
     220,   221,   221,   222,   222,   223,   224,   224,   225,   225,
     226,   227,   228,   228,   229,   230,   230,   231,   232,   233,
     233,   234,   235,   236,   236,   237,   237,   237,   238,   239,
     239,   240,   241,   241,   242,   242,   243,   243,   244,   244,
     244,   245,   246,   246,   247,   247,   248,   249,   250,   250,
     251,   251,   251,   251,   252,   253,   253,   254,   254,   254,
     255,   256,   257,   257,   258,   259,   259,   260,   261,   261,
     262,   262,   263,   264,   265,   265,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   267,   268,   268,   269,   269,
     270,   271,   271,   272,   273,   274,   274,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   277,   277,   278,
     278,   278,   278,   278,   278,   278,   279,   279,   280,   280,
     281,   282,   282,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   285,   285,   286,   286,   286,   286,   286,   286,
     286,   286,   287,   288,   288,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   290,   291,   291,   292,   292,
     293,   294,   294,   295,   296,   296,   297,   297,   297,   297,
     297,   298,   299,   299,   300,   300,   300,   301,   301,   302,
     303,   303,   304,   304,   304,   304,   305,   306,   307,   308,
     309,   309,   310,   310,   311,   311,   312,   312,   313,   314,
     314,   315,   315,   315,   315,   315,   315,   316,   317,   317,
     318,   318,   319,   319,   319,   319,   320,   320,   320,   321,
     321,   322,   322,   323,   323,   323,   324,   324
  };

  const signed char
  XcpDataParser::yyr2_[] =
  {
       0,     2,     5,     3,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,    17,     0,     2,     2,     2,     1,     2,
       2,     1,     5,     0,     2,    12,     0,     1,     0,     2,
       8,    15,    14,     0,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     8,     0,     1,
       0,     2,     8,     0,     1,     6,    11,     0,     6,     6,
       0,     2,     2,     2,     2,     2,     2,     1,     5,     0,
       2,     6,     0,     2,     6,    13,     0,     2,     2,     2,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     3,
       3,     2,     1,     1,     1,     1,     9,     0,     2,     2,
       8,     1,     2,     1,     1,     8,     1,     2,     1,     1,
       6,     7,     0,     1,     7,     0,     1,     6,     5,     1,
       1,     2,     2,     0,     2,     5,     5,     5,     6,     0,
       1,     8,     0,     2,     1,     1,     2,     5,     2,     5,
       2,     2,     0,     1,     0,     3,    11,    10,     0,     2,
       1,     2,     1,     1,     6,     0,     2,     2,     2,     2,
       9,     7,     0,     2,     6,     0,     2,    19,     0,     7,
       0,     2,     2,     7,     0,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       2,     1,     1,     2,     1,     6,     0,     2,     1,     1,
       6,     0,     2,     2,     5,     0,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,    11,     0,     2,     4,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     6,
       8,     0,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     8,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     1,    11,     0,     2,     5,     5,     2,     2,     5,
       5,     5,     1,     2,     1,     7,     0,     2,     0,     2,
       7,     0,     2,    13,     0,     2,     5,     5,     5,     2,
       1,     2,     0,     2,     2,     1,     1,     2,     2,     5,
       0,     2,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     0,     2,     2,     2,     0,     2,     5,     0,
       2,     2,     2,     2,     2,     2,     2,     6,     0,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1
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
  "MTA_BLOCK_SIZE_ALIGN", "MULTICAST", "NONE", "ODT", "ODT_ENTRY",
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
  "common_parameter", "transport_protocol", "protocol_layer",
  "protocol_optional_items", "protocol_optional_item", "ecu_states",
  "state_list", "state_block", "ecu_switch_to_default",
  "memory_access_list", "memory_access", "daq", "daq_optionals",
  "daq_optional", "stim_struct", "bit_stim", "min_st_stim",
  "timestamp_supported", "timestamp_fixed", "core_load_max",
  "daq_memory_consumption", "buffer_reserve", "daq_list",
  "daq_list_optionals", "daq_list_optional", "odt_list", "odt",
  "odt_entry_list", "odt_entry", "d_event", "d_event_optionals",
  "d_event_optional", "daq_packed_mode", "alt_sample_count_list",
  "alt_sample_count", "cpu_load_consumption_daq",
  "cpu_load_consumption_daq_options", "cpu_load_consumption_daq_option",
  "cpu_load_consumption_stim", "cpu_load_consumption_stim_options",
  "cpu_load_consumption_stim_option", "odt_entry_size_factor_table",
  "cpu_load_consumption_queue", "cpu_load_consumption_queue_option",
  "cpu_load_consumption_queue_stim",
  "cpu_load_consumption_queue_stim_option", "core_load_ep", "daq_event",
  "daq_event_union", "fixed_event_list", "variable", "variable_options",
  "variable_option", "pag", "freeze_supported", "pgm", "pgm_options",
  "pgm_option", "communication_mode_supported", "communication_mode_union",
  "block_struct", "slave_item", "master_item", "sector", "segment",
  "segment_options", "segment_option", "checksum", "checksum_options",
  "checksum_option", "page", "address_mapping", "init_segment",
  "time_correlation", "clock_list", "clock", "timestamp_characterization",
  "event_list", "event", "xcp_on_can", "can_parameter_options",
  "can_parameter_option", "daq_list_can_id", "daq_list_can_id_options",
  "daq_list_can_id_option", "event_can_id_list", "fixed_list", "fixed",
  "can_fd", "can_fd_options", "can_fd_option", "xcp_on_sxi",
  "sxi_parameter_options", "sxi_parameter_option", "sxi_option", "framing",
  "xcp_on_tcp_ip", "tcp_ip_options", "tcp_ip_option", "xcp_on_udp_ip",
  "udp_ip_options", "udp_ip_option", "xcp_on_usb", "usb_options",
  "usb_option", "daq_list_usb_endpoint", "fixed_in", "fixed_out",
  "ep_parameters", "recommended_host_bufsize", "xcp_on_flx", "flx_options",
  "flx_option", "buffer", "buffer_options", "buffer_option",
  "max_flx_len_buf_union", "lpu_id", "lpu_id_options", "lpu_id_option",
  "flx_slot_id_union", "offset_union", "cycle_repetition", "channel",
  "channel_union", "initial_enum", "lpu_id_union", "initial_value",
  "xcp_packet", "xcp_packet_options", "xcp_packet_option",
  "xcp_on_simulink", "simulink_options", "simulink_option", "consistency",
  "daq_list_type", "transport_layer_instance", "ident_or_string",
  "any_float", "any_int", YY_NULLPTR
  };
#endif


#if XCPDEBUG
  const short
  XcpDataParser::yyrline_[] =
  {
       0,   143,   143,   147,   149,   151,   152,   154,   156,   158,
     161,   164,   167,   170,   173,   176,   181,   182,   183,   184,
     185,   186,   187,   189,   208,   209,   211,   214,   217,   220,
     223,   226,   231,   235,   236,   241,   254,   255,   257,   258,
     262,   271,   287,   304,   305,   307,   310,   313,   316,   319,
     322,   325,   328,   331,   334,   337,   340,   343,   346,   349,
     352,   355,   358,   361,   364,   367,   370,   375,   384,   385,
     387,   388,   390,   401,   402,   404,   411,   423,   424,   433,
     442,   443,   445,   448,   451,   454,   457,   460,   463,   470,
     471,   476,   483,   484,   489,   497,   512,   513,   514,   517,
     520,   523,   526,   529,   532,   535,   538,   541,   544,   547,
     553,   559,   562,   565,   568,   571,   576,   586,   587,   592,
     594,   605,   606,   608,   611,   616,   627,   628,   630,   633,
     638,   645,   655,   656,   661,   671,   672,   677,   684,   692,
     693,   695,   700,   701,   702,   704,   709,   714,   721,   728,
     729,   734,   745,   746,   748,   751,   756,   760,   768,   769,
     772,   778,   779,   780,   784,   785,   792,   804,   817,   818,
     820,   821,   824,   825,   830,   840,   841,   843,   846,   849,
     854,   867,   875,   876,   881,   890,   891,   893,   917,   918,
     929,   930,   934,   936,   945,   946,   948,   951,   954,   957,
     960,   963,   966,   969,   972,   975,   978,   981,   984,   985,
     986,   990,   993,   994,   997,  1004,  1013,  1014,  1016,  1020,
    1026,  1036,  1037,  1041,  1043,  1050,  1051,  1053,  1057,  1061,
    1065,  1069,  1073,  1077,  1081,  1085,  1091,  1103,  1104,  1106,
    1112,  1115,  1118,  1121,  1124,  1127,  1132,  1133,  1140,  1141,
    1150,  1160,  1161,  1163,  1166,  1169,  1172,  1175,  1178,  1181,
    1184,  1191,  1201,  1202,  1204,  1207,  1210,  1213,  1216,  1219,
    1222,  1225,  1232,  1245,  1246,  1248,  1253,  1258,  1261,  1264,
    1269,  1274,  1279,  1282,  1285,  1292,  1299,  1300,  1305,  1306,
    1311,  1321,  1322,  1326,  1342,  1343,  1344,  1351,  1358,  1365,
    1368,  1374,  1379,  1380,  1381,  1388,  1389,  1390,  1395,  1401,
    1405,  1406,  1407,  1408,  1409,  1410,  1411,  1418,  1425,  1432,
    1439,  1446,  1453,  1454,  1462,  1467,  1473,  1474,  1482,  1486,
    1487,  1489,  1493,  1497,  1501,  1505,  1509,  1515,  1523,  1524,
    1526,  1528,  1533,  1534,  1535,  1536,  1538,  1539,  1540,  1542,
    1543,  1545,  1546,  1548,  1549,  1550,  1552,  1553
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
     175,   176,   177,   178,   179
    };
    // Last valid token kind.
    const int code_max = 434;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
} } // a2l::xcp
#line 5353 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

#line 1554 "D:/projects/a2llib/src/xcp/xcpdataparser.y"


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
