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
	  yylhs.value.as < ProtocolLayer > () = protocol;
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
     	yylhs.value.as < Daq > () = daq;
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
     	yylhs.value.as < Daq > () = daq;
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
	   	yylhs.value.as < DaqList > () = list;
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
                yylhs.value.as < Event > () = event;
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

  case 110: // d_event_optional: BLOCK_BEGIN MIN_CYCLE_TIME UINT UINT BLOCK_END MIN_CYCLE_TIME
#line 553 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                          {
		MinCycleTime cycle;
		cycle.time_cycle = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
		cycle.time_unit = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetMinCycleTime(std::move(cycle));
    }
#line 2650 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 111: // d_event_optional: BUFFER_RESERVE_EVENT UINT UINT
#line 559 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		BufferReserveEvent buffer;
		buffer.odt_daq_buffer_element_reserve = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		buffer.odt_stim_buffer_element_reserve = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetBufferReserveEvent(std::move(buffer));
	}
#line 2662 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 112: // d_event_optional: CPU_LOAD_MAX any_float
#line 565 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadMax(yystack_[0].value.as < double > ());
	}
#line 2671 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 113: // d_event_optional: cpu_load_consumption_daq
#line 568 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionDaq(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2680 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 114: // d_event_optional: cpu_load_consumption_stim
#line 571 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2689 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 115: // d_event_optional: cpu_load_consumption_queue
#line 574 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueue(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2698 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 116: // d_event_optional: cpu_load_consumption_queue_stim
#line 577 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueueStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2707 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 117: // daq_packed_mode: BLOCK_BEGIN DAQ_PACKED_MODE IDENT IDENT IDENT UINT alt_sample_count_list BLOCK_END DAQ_PACKED_MODE
#line 584 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          	yylhs.value.as < DaqPackedMode > ().SetGroup(yystack_[6].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetTimestampMode(yystack_[5].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetUsage(yystack_[4].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().sample_count = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
          	yylhs.value.as < DaqPackedMode > ().alt_sample_count = std::move(yystack_[2].value.as < std::vector<uint16_t> > ());
          }
#line 2719 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 118: // alt_sample_count_list: %empty
#line 592 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < std::vector<uint16_t> > () = {};}
#line 2725 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 119: // alt_sample_count_list: alt_sample_count_list alt_sample_count
#line 593 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                {
                       	yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
                       	yylhs.value.as < std::vector<uint16_t> > ().push_back(static_cast<uint16_t>(yystack_[0].value.as < uint16_t > ()));
                       }
#line 2734 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 120: // alt_sample_count: ALT_SAMPLE_COUNT UINT
#line 598 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > ();}
#line 2740 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 121: // cpu_load_consumption_daq: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_DAQ any_float any_float any_float cpu_load_consumption_daq_options BLOCK_END CPU_LOAD_CONSUMPTION_DAQ
#line 602 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = cpu_load;
               	cpu_load.Reset();
           }
#line 2753 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 124: // cpu_load_consumption_daq_option: odt_entry_size_factor_table
#line 614 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	   }
#line 2762 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 125: // cpu_load_consumption_daq_option: core_load_ep
#line 617 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
 		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
           }
#line 2771 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 126: // cpu_load_consumption_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_STIM any_float any_float any_float cpu_load_consumption_stim_options BLOCK_END CPU_LOAD_CONSUMPTION_STIM
#line 624 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = cpu_load;
               	cpu_load.Reset();
           }
#line 2784 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 129: // cpu_load_consumption_stim_option: odt_entry_size_factor_table
#line 636 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	  }
#line 2793 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 130: // cpu_load_consumption_stim_option: core_load_ep
#line 639 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2802 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 131: // odt_entry_size_factor_table: BLOCK_BEGIN ODT_ENTRY_SIZE_FACTOR_TABLE UINT any_float BLOCK_END ODT_ENTRY_SIZE_FACTOR_TABLE
#line 646 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                   {
         	yylhs.value.as < OdtEntrySizeFactor > ().size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
         	yylhs.value.as < OdtEntrySizeFactor > ().factor = static_cast<float>(yystack_[2].value.as < double > ());
         }
#line 2811 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 132: // cpu_load_consumption_queue: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE any_float any_float cpu_load_consumption_queue_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 653 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = cpu_load;
               	cpu_load.Reset();
         }
#line 2823 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 134: // cpu_load_consumption_queue_option: core_load_ep
#line 662 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2832 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 135: // cpu_load_consumption_queue_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE_STIM any_float any_float cpu_load_consumption_queue_stim_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 669 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = cpu_load;
               	cpu_load.Reset();
         }
#line 2844 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 137: // cpu_load_consumption_queue_stim_option: core_load_ep
#line 678 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
	}
#line 2853 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 138: // core_load_ep: BLOCK_BEGIN CORE_LOAD_EP UINT any_float BLOCK_END CORE_LOAD_EP
#line 685 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
              yylhs.value.as < CoreLoadEp > ().number = yystack_[3].value.as < uint64_t > ();
              yylhs.value.as < CoreLoadEp > ().max = yystack_[2].value.as < double > ();
              }
#line 2862 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 139: // daq_event: BLOCK_BEGIN DAQ_EVENT daq_event_union BLOCK_END DAQ_EVENT
#line 692 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		DaqEvent& event_list = scanner.GetDaqEvent();
       		yylhs.value.as < DaqEvent > () = event_list;
       		event_list.Reset();
           }
#line 2872 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 142: // fixed_event_list: FIXED_EVENT_LIST event_list
#line 701 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetFixedEventList(yystack_[0].value.as < std::vector<uint16_t> > ());
	}
#line 2881 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 146: // variable_option: BLOCK_BEGIN AVAILABLE_EVENT_LIST event_list BLOCK_END AVAILABLE_EVENT_LIST
#line 712 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetAvailableEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2890 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 147: // variable_option: BLOCK_BEGIN DEFAULT_EVENT_LIST event_list BLOCK_END DEFAULT_EVENT_LIST
#line 717 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetDefaultEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2899 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 148: // variable_option: BLOCK_BEGIN CONSISTENCY_EVENT_LIST event_list BLOCK_END CONSISTENCY_EVENT_LIST
#line 722 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetConsistencyEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2908 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 149: // pag: BLOCK_BEGIN PAG UINT freeze_supported BLOCK_END PAG
#line 727 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
     	Pag& pag = scanner.GetPag();
     	pag.SetMaxSegments(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pag > () = pag;
     	pag.Reset();
     }
#line 2919 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 151: // freeze_supported: FREEZE_SUPPORTED
#line 735 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
     	Pag& pag = scanner.GetPag();
     	pag.SetFreezeSupported();
     }
#line 2928 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 152: // pgm: BLOCK_BEGIN PGM IDENT UINT UINT pgm_options BLOCK_END PGM
#line 742 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	Pgm& pgm = scanner.GetPgm();
     	pgm.SetType(yystack_[5].value.as < std::string > ());
     	pgm.SetMaxSectors(yystack_[4].value.as < uint64_t > ());
     	pgm.SetMaxCtoPgm(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pgm > () = pgm;
     	pgm.Reset();
     }
#line 2941 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 155: // pgm_option: sector
#line 754 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.AddSector(std::move(yystack_[0].value.as < Sector > ()));
      }
#line 2950 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 156: // pgm_option: communication_mode_supported
#line 757 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.SetCommunicationModeSupported(yystack_[0].value.as < CommunicationMode > ());
      }
#line 2959 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 157: // communication_mode_supported: COMMUNICATION_MODE_SUPPORTED communication_mode_union
#line 762 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = mode;
             	mode.Reset();
             }
#line 2969 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 158: // communication_mode_supported: BLOCK_BEGIN COMMUNICATION_MODE_SUPPORTED communication_mode_union BLOCK_END COMMUNICATION_MODE_SUPPORTED
#line 768 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = mode;
             	mode.Reset();
             }
#line 2979 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 161: // communication_mode_union: INTERLEAVED UINT
#line 778 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
        	CommunicationMode& mode = scanner.GetCommunicationMode();
        	mode.SetInterleavedSupported();
        	mode.SetQueueSize(yystack_[0].value.as < uint64_t > ());
            }
#line 2989 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 164: // slave_item: SLAVE
#line 786 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetSlaveModeSupported();
            }
#line 2998 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 166: // master_item: MASTER UINT UINT
#line 791 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetMasterModeSupported();
       		mode.SetMaxBs(yystack_[1].value.as < uint64_t > ());
       		mode.SetMinSt(yystack_[0].value.as < uint64_t > ());
            }
#line 3009 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 167: // sector: BLOCK_BEGIN SECTOR STRING UINT UINT UINT UINT UINT UINT BLOCK_END SECTOR
#line 800 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
        	yylhs.value.as < Sector > ().name = std::move(yystack_[8].value.as < std::string > ());
        	yylhs.value.as < Sector > ().number = static_cast<uint8_t>(yystack_[7].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().address = static_cast<uint32_t>(yystack_[6].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().length = static_cast<uint32_t>(yystack_[5].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().clear_sequence_number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_sequence_number = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_method = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
        }
#line 3023 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 168: // segment: BLOCK_BEGIN SEGMENT UINT UINT UINT UINT UINT segment_options BLOCK_END SEGMENT
#line 812 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
      	Segment& segment = scanner.GetSegment();
      	segment.SetNumber(yystack_[7].value.as < uint64_t > ());
      	segment.SetNumberOfPages(yystack_[6].value.as < uint64_t > ());
      	segment.SetAddressExtension(yystack_[5].value.as < uint64_t > ());
      	segment.SetCompressionMethod(yystack_[4].value.as < uint64_t > ());
      	segment.SetEncryptionMethod(yystack_[3].value.as < uint64_t > ());
      	yylhs.value.as < Segment > () = segment;
      	segment.Reset();
      }
#line 3038 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 172: // segment_option: DEFAULT_PAGE_NUMBER UINT
#line 827 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
        Segment& segment = scanner.GetSegment();
        segment.SetDefaultPageNumber(yystack_[0].value.as < uint64_t > ());
      }
#line 3047 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 174: // segment_option: address_mapping
#line 831 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Segment& segment = scanner.GetSegment();
      	segment.AddAddressMapping(std::move(yystack_[0].value.as < AddressMapping > ()));
      }
#line 3056 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 175: // checksum: BLOCK_BEGIN CHECKSUM IDENT checksum_options BLOCK_END CHECKSUM
#line 838 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.SetType(yystack_[3].value.as < std::string > ());
      	Segment& segment = scanner.GetSegment();
      	segment.SetChecksum(checksum);
      	checksum.Reset();
      }
#line 3068 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 178: // checksum_option: MAX_BLOCK_SIZE UINT
#line 849 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.max_block_size = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3077 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 179: // checksum_option: EXTERNAL_FUNCTION STRING
#line 852 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.external_function = std::move(yystack_[0].value.as < std::string > ());
      }
#line 3086 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 180: // checksum_option: MTA_BLOCK_SIZE_ALIGN UINT
#line 855 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.mta_block_size_align =	static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3095 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 181: // page: BLOCK_BEGIN PAGE UINT IDENT IDENT IDENT init_segment BLOCK_END PAGE
#line 862 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
      	Page& page = scanner.GetPage();
      	page.SetNumber(yystack_[6].value.as < uint64_t > ());
      	page.SetEcuAccessType(yystack_[5].value.as < std::string > ());
      	page.SetReadAccessType(yystack_[4].value.as < std::string > ());
      	page.SetWriteAccessType(yystack_[3].value.as < std::string > ());
      	Segment& segment = scanner.GetSegment();
      	segment.AddPage(page);
      	page.Reset();
      }
#line 3110 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 182: // address_mapping: BLOCK_BEGIN ADDRESS_MAPPING UINT UINT UINT BLOCK_END ADDRESS_MAPPING
#line 875 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	yylhs.value.as < AddressMapping > ().source_address = static_cast<uint32_t>(yystack_[4].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().destination_address = static_cast<uint32_t>(yystack_[3].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().length = static_cast<uint32_t>(yystack_[2].value.as < uint64_t > ());
      }
#line 3120 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 184: // init_segment: INIT_SEGMENT UINT
#line 882 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Page& page = scanner.GetPage();
      	page.SetInitSegment(yystack_[0].value.as < uint64_t > ());
      }
#line 3129 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 185: // time_correlation: BLOCK_BEGIN TIME_CORRELATION IDENT clock_list BLOCK_END TIME_CORRELATION
#line 889 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
 		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
 		correlation.SetTimestampsRelateTo(yystack_[3].value.as < std::string > ());
		yylhs.value.as < TimeCorrelation > () = correlation;
 		correlation.Reset();
        }
#line 3140 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 188: // clock: BLOCK_BEGIN CLOCK any_int any_int any_int any_int any_int any_int any_int any_int IDENT IDENT IDENT UINT timestamp_characterization UINT IDENT BLOCK_END CLOCK
#line 902 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
		correlation.AddClock(clock);
		clock.Reset();
       }
#line 3165 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 190: // timestamp_characterization: BLOCK_BEGIN TIME_CHARACTERIZATION UINT IDENT IDENT BLOCK_END TIME_CHARACTERIZATION
#line 926 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                 {
                TimestampCharacteristic characteristic;
                characteristic.SetTicks(yystack_[4].value.as < uint64_t > ());
                characteristic.SetResolution(yystack_[3].value.as < std::string > ());
                characteristic.SetSize(yystack_[2].value.as < std::string > ());
       		Clock& clock = scanner.GetClock();
       		clock.SetCharacteristic(std::move(characteristic));
        }
#line 3178 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 191: // event_list: %empty
#line 935 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint16_t> > ().clear(); }
#line 3184 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 192: // event_list: event_list event
#line 936 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
            yylhs.value.as < std::vector<uint16_t> > ().push_back(yystack_[0].value.as < uint16_t > ());
            }
#line 3193 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 193: // event: EVENT UINT
#line 940 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3199 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 194: // xcp_on_can: BLOCK_BEGIN XCP_ON_CAN UINT can_parameter_options transport_layer_instance BLOCK_END XCP_ON_CAN
#line 944 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetVersion(yystack_[4].value.as < uint64_t > ());
		can.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
		scanner.SaveXcpOnCan();
       }
#line 3210 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 197: // can_parameter_option: CAN_ID_BROADCAST UINT
#line 954 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdBroadcast(yystack_[0].value.as < uint64_t > ());
        }
#line 3219 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 198: // can_parameter_option: CAN_ID_MASTER UINT
#line 957 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMaster(yystack_[0].value.as < uint64_t > ());
        }
#line 3228 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 199: // can_parameter_option: CAN_ID_MASTER_INCREMENTAL
#line 960 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMasterIncremental();
        }
#line 3237 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 200: // can_parameter_option: CAN_ID_SLAVE UINT
#line 963 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdSlave(yystack_[0].value.as < uint64_t > ());
        }
#line 3246 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 201: // can_parameter_option: CAN_ID_GET_DAQ_CLOCK_MULTICAST UINT
#line 966 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdGetDaqClockMulticast(yystack_[0].value.as < uint64_t > ());
        }
#line 3255 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 202: // can_parameter_option: BAUDRATE UINT
#line 969 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBaudrate(yystack_[0].value.as < uint64_t > ());
        }
#line 3264 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 203: // can_parameter_option: SAMPLE_POINT UINT
#line 972 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSamplePoint(yystack_[0].value.as < uint64_t > ());
        }
#line 3273 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 204: // can_parameter_option: SAMPLE_RATE IDENT
#line 975 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSampleRate(yystack_[0].value.as < std::string > ());
        }
#line 3282 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 205: // can_parameter_option: BTL_CYCLES UINT
#line 978 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBtlCycles(yystack_[0].value.as < uint64_t > ());
        }
#line 3291 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 206: // can_parameter_option: SJW UINT
#line 981 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSjw(yystack_[0].value.as < uint64_t > ());
        }
#line 3300 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 207: // can_parameter_option: SYNC_EDGE IDENT
#line 984 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSyncEdge(yystack_[0].value.as < std::string > ());
        }
#line 3309 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 208: // can_parameter_option: MAX_DLC_REQUIRED
#line 987 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxDlcRequired();
        }
#line 3318 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 211: // can_parameter_option: MAX_BUS_LOAD UINT
#line 992 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
        }
#line 3327 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 212: // can_parameter_option: MEASUREMENT_SPLIT_ALLOWED
#line 996 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMeasurementSplitAllowed();
        }
#line 3336 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 214: // can_parameter_option: OPTIONAL_TL_SUBCMD IDENT
#line 1000 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.AddSubCmd(yystack_[0].value.as < std::string > ());
        }
#line 3345 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 215: // can_parameter_option: common_parameter
#line 1003 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		CommonParameters& common_parameters = scanner.GetCommonParameters();
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetOverrulingParameters(common_parameters);
		common_parameters.Reset();
        }
#line 3356 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 216: // daq_list_can_id: BLOCK_BEGIN DAQ_LIST_CAN_ID UINT daq_list_can_id_options BLOCK_END DAQ_LIST_CAN_ID
#line 1012 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
	   XcpOnCan& can = scanner.GetXcpOnCan();
           DaqListCanId& daq_list = can.GetCurrentDaqList();
           daq_list.number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
           can.AddDaqList();
        }
#line 3367 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 219: // daq_list_can_id_option: VARIABLE
#line 1022 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.variable = true;
        }
#line 3377 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 220: // daq_list_can_id_option: fixed
#line 1026 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.fixed = static_cast<uint32_t>(yystack_[0].value.as < uint32_t > ());
        }
#line 3387 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 221: // event_can_id_list: BLOCK_BEGIN EVENT_CAN_ID_LIST UINT fixed_list BLOCK_END EVENT_CAN_ID_LIST
#line 1034 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   EventCanIdList list;
	   list.number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	   list.fixed_list = std::move(yystack_[2].value.as < std::vector<uint32_t> > ());
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddCanIdEventList(std::move(list));
        }
#line 3399 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 222: // fixed_list: %empty
#line 1042 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint32_t> > () = {};}
#line 3405 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 223: // fixed_list: fixed_list fixed
#line 1043 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
       	yylhs.value.as < std::vector<uint32_t> > () = std::move(yystack_[1].value.as < std::vector<uint32_t> > ());
       	yylhs.value.as < std::vector<uint32_t> > ().push_back(yystack_[0].value.as < uint32_t > ());
       }
#line 3414 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 224: // fixed: FIXED UINT
#line 1047 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint32_t > () = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ()); }
#line 3420 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 225: // can_fd: BLOCK_BEGIN CAN_FD can_fd_options BLOCK_END CAN_FD
#line 1051 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
      	XcpOnCan& can = scanner.GetXcpOnCan();
      	can.SetCanFd();
     }
#line 3429 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 228: // can_fd_option: MAX_DLC UINT
#line 1059 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc = static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3439 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 229: // can_fd_option: CAN_FD_DATA_TRANSFER_BAUDRATE UINT
#line 1063 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.baudrate = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3449 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 230: // can_fd_option: SAMPLE_POINT UINT
#line 1067 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3459 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 231: // can_fd_option: BTL_CYCLES UINT
#line 1071 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.btl_cycles = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3469 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 232: // can_fd_option: SJW UINT
#line 1075 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sjw = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3479 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 233: // can_fd_option: SYNC_EDGE IDENT
#line 1079 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetSyncEdge(yystack_[0].value.as < std::string > ());
     }
#line 3489 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 234: // can_fd_option: MAX_DLC_REQUIRED
#line 1083 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc_required = true;
     }
#line 3499 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 235: // can_fd_option: SECONDARY_SAMPLE_POINT UINT
#line 1087 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.secondary_sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3509 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 236: // can_fd_option: TRANSCEIVER_DELAY_COMPENSATION IDENT
#line 1091 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetTransceiverDelayCompensation(yystack_[0].value.as < std::string > ());
     }
#line 3519 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 237: // xcp_on_sxi: BLOCK_BEGIN XCP_ON_SxI UINT UINT sxi_parameter_options IDENT IDENT sxi_option transport_layer_instance BLOCK_END XCP_ON_SxI
#line 1099 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetVersion(yystack_[8].value.as < uint64_t > ());
               sxi.SetBaudrate(yystack_[7].value.as < uint64_t > ());
               sxi.SetHeaderLength(yystack_[5].value.as < std::string > ());
               sxi.SetChecksum(yystack_[4].value.as < std::string > ());
               sxi.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnSxi();
            }
#line 3533 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 240: // sxi_parameter_option: ASYNCH_FULL_DUPLEX_MODE IDENT IDENT framing
#line 1112 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               AsynchFullDuplexMode& asynch = sxi.GetCurrentAsynch();
               asynch.SetParity(yystack_[2].value.as < std::string > ());
               asynch.SetStopBits(yystack_[1].value.as < std::string > ());
               sxi.SetAsynchFullDuplexMode();
	    }
#line 3545 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 241: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_BYTE
#line 1118 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeByte();
            }
#line 3554 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 242: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_WORD
#line 1121 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeWord();
            }
#line 3563 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 243: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_DWORD
#line 1124 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeDword();
            }
#line 3572 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 244: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_BYTE
#line 1127 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeByte();
            }
#line 3581 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 245: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_WORD
#line 1130 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeWord();
            }
#line 3590 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 246: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_DWORD
#line 1133 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeDword();
            }
#line 3599 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 248: // sxi_option: common_parameter
#line 1139 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
           CommonParameters& common_parameters = scanner.GetCommonParameters();
           XcpOnSxi& sxi = scanner.GetXcpOnSxi();
           sxi.SetOverrulingParameters(common_parameters);
           common_parameters.Reset();
         }
#line 3610 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 250: // framing: BLOCK_BEGIN FRAMING UINT UINT BLOCK_END FRAMING
#line 1149 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
             XcpOnSxi& sxi = scanner.GetXcpOnSxi();
             Framing& framing = sxi.GetCurrentFraming();
             framing.sync = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
             sxi.SetFraming();
           }
#line 3621 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 251: // xcp_on_tcp_ip: BLOCK_BEGIN XCP_ON_TCP_IP UINT UINT tcp_ip_options transport_layer_instance BLOCK_END XCP_ON_TCP_IP
#line 1158 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetVersion(yystack_[5].value.as < uint64_t > ());
               tcp.SetPort(yystack_[4].value.as < uint64_t > ());
               tcp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnTcpIp();
            }
#line 3633 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 254: // tcp_ip_option: HOST_NAME STRING
#line 1169 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetHostName(yystack_[0].value.as < std::string > ());
	     }
#line 3642 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 255: // tcp_ip_option: ADDRESS STRING
#line 1172 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetAddress(yystack_[0].value.as < std::string > ());
	     }
#line 3651 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 256: // tcp_ip_option: IPV6 STRING
#line 1175 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetIpv6(yystack_[0].value.as < std::string > ());
	     }
#line 3660 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 257: // tcp_ip_option: MAX_BUS_LOAD UINT
#line 1178 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
	     }
#line 3669 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 258: // tcp_ip_option: MAX_BIT_RATE UINT
#line 1181 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
	     }
#line 3678 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 259: // tcp_ip_option: PACKET_ALIGNMENT IDENT
#line 1184 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
	     }
#line 3687 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 260: // tcp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1187 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.AddSubCmd(yystack_[0].value.as < std::string > ());
	     }
#line 3696 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 261: // tcp_ip_option: common_parameter
#line 1190 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
	     }
#line 3707 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 262: // xcp_on_udp_ip: BLOCK_BEGIN XCP_ON_UDP_IP UINT UINT udp_ip_options transport_layer_instance BLOCK_END XCP_ON_UDP_IP
#line 1199 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetVersion(yystack_[5].value.as < uint64_t > ());
               udp.SetPort(yystack_[4].value.as < uint64_t > ());
               udp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnUdpIp();
             }
#line 3719 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 265: // udp_ip_option: HOST_NAME STRING
#line 1210 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetHostName(yystack_[0].value.as < std::string > ());
	    }
#line 3728 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 266: // udp_ip_option: ADDRESS STRING
#line 1213 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetAddress(yystack_[0].value.as < std::string > ());
            }
#line 3737 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 267: // udp_ip_option: IPV6 STRING
#line 1216 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetIpv6(yystack_[0].value.as < std::string > ());
            }
#line 3746 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 268: // udp_ip_option: MAX_BUS_LOAD UINT
#line 1219 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
            }
#line 3755 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 269: // udp_ip_option: MAX_BIT_RATE UINT
#line 1222 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
            }
#line 3764 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 270: // udp_ip_option: PACKET_ALIGNMENT IDENT
#line 1225 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
            }
#line 3773 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 271: // udp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1228 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.AddSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3782 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 272: // udp_ip_option: common_parameter
#line 1231 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
            }
#line 3793 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 273: // xcp_on_usb: BLOCK_BEGIN XCP_ON_USB UINT UINT UINT UINT IDENT usb_options transport_layer_instance BLOCK_END XCP_ON_USB
#line 1240 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3808 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 276: // usb_option: BLOCK_BEGIN OUT_EP_CMD_STIM ep_parameters BLOCK_END OUT_EP_CMD_STIM
#line 1256 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetOutEpCmdStim();
            }
#line 3817 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 277: // usb_option: BLOCK_BEGIN IN_EP_RESERR_DAQ_EVSERV ep_parameters BLOCK_END IN_EP_RESERR_DAQ_EVSERV
#line 1261 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetInEpReserrDaqEvserv();
            }
#line 3826 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 278: // usb_option: ALTERNATE_SETTING_NO UINT
#line 1264 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetAlternateSettingNo(yystack_[0].value.as < uint64_t > ());
            }
#line 3835 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 279: // usb_option: INTERFACE_STRING_DESCRIPTOR STRING
#line 1267 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetInterfaceStringDescriptor(yystack_[0].value.as < std::string > ());
            }
#line 3844 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 280: // usb_option: BLOCK_BEGIN OUT_EP_ONLY_STIM ep_parameters BLOCK_END OUT_EP_ONLY_STIM
#line 1272 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddOutEpOnlyStim();
            }
#line 3853 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 281: // usb_option: BLOCK_BEGIN IN_EP_ONLY_DAQ ep_parameters BLOCK_END IN_EP_ONLY_DAQ
#line 1277 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddInEpOnlyDaq();
            }
#line 3862 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 282: // usb_option: BLOCK_BEGIN IN_EP_ONLY_EVSERV ep_parameters BLOCK_END IN_EP_ONLY_EVSERV
#line 1282 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddDaqListUsbEndpoint();
            }
#line 3871 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 283: // usb_option: daq_list_usb_endpoint
#line 1285 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
            	XcpOnUsb& usb = scanner.GetXcpOnUsb();
            	usb.AddDaqListUsbEndpoint();
            }
#line 3880 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 284: // usb_option: OPTIONAL_TL_SUBCMD IDENT
#line 1288 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
  		XcpOnUsb& usb = scanner.GetXcpOnUsb();
  		usb.AddSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3889 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 285: // usb_option: common_parameter
#line 1291 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               CommonParameters& common_parameters = scanner.GetCommonParameters();
               XcpOnUsb& usb = scanner.GetXcpOnUsb();
               usb.SetOverrulingParameters(common_parameters);
               common_parameters.Reset();
          }
#line 3900 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 286: // daq_list_usb_endpoint: BLOCK_BEGIN DAQ_LIST_USB_ENDPOINT UINT fixed_in fixed_out BLOCK_END DAQ_LIST_USB_ENDPOINT
#line 1300 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.number = yystack_[4].value.as < uint64_t > ();
          }
#line 3910 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 288: // fixed_in: FIXED_IN UINT
#line 1306 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_in = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3920 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 290: // fixed_out: FIXED_OUT UINT
#line 1312 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_out = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3930 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 291: // ep_parameters: UINT IDENT UINT UINT IDENT IDENT recommended_host_bufsize
#line 1317 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3945 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 293: // recommended_host_bufsize: RECOMMENDED_HOST_BUFSIZE UINT
#line 1328 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {

           }
#line 3953 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 294: // xcp_on_flx: BLOCK_BEGIN XCP_ON_FLX UINT UINT STRING STRING UINT IDENT IDENT flx_options transport_layer_instance BLOCK_END XCP_ON_FLX
#line 1334 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3971 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 297: // flx_option: BLOCK_BEGIN INITIAL_CMD_BUFFER buffer BLOCK_END INITIAL_CMD_BUFFER
#line 1352 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
            flx.SetInitialCmdBuffer(buffer);
            buffer.Reset();
       	  }
#line 3982 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 298: // flx_option: BLOCK_BEGIN INITIAL_RES_ERR_BUFFER buffer BLOCK_END INITIAL_RES_ERR_BUFFER
#line 1359 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
            flx.SetInitialResErrBuffer(buffer);
            buffer.Reset();
          }
#line 3993 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 299: // flx_option: BLOCK_BEGIN POOL_BUFFER buffer BLOCK_END POOL_BUFFER
#line 1366 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
            flx.AddPoolBuffer(buffer);
            buffer.Reset();
          }
#line 4004 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 300: // flx_option: OPTIONAL_TL_SUBCMD IDENT
#line 1371 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            flx.AddSubCmd(yystack_[0].value.as < std::string > ());
          }
#line 4013 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 301: // flx_option: common_parameter
#line 1374 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            CommonParameters& common_parameters = scanner.GetCommonParameters();
            scanner.GetXcpOnFlx().SetOverrulingParameters(common_parameters);
            common_parameters.Reset();
         }
#line 4023 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 302: // buffer: UINT buffer_options
#line 1380 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  buffer.SetBufferNo(yystack_[1].value.as < uint64_t > ());
	}
#line 4033 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 305: // buffer_option: MAX_FLX_LEN_BUF max_flx_len_buf_union
#line 1387 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                     {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetMaxFlxLenBuffer(var_fixed);
	  var_fixed.Reset();
	}
#line 4045 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 308: // max_flx_len_buf_union: FIXED UINT
#line 1396 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4056 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 309: // max_flx_len_buf_union: VARIABLE UINT
#line 1401 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = yystack_[0].value.as < uint64_t > ();
	}
#line 4067 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 317: // flx_slot_id_union: FLX_SLOT_ID lpu_id_union
#line 1417 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetFlxSlotId(var_fixed);
	  var_fixed.Reset();
	}
#line 4079 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 318: // offset_union: OFFSET lpu_id_option
#line 1424 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetOffset(var_fixed);
	  var_fixed.Reset();
	}
#line 4091 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 319: // cycle_repetition: CYCLE_REPETITION lpu_id_union
#line 1431 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetCycleRepetition(var_fixed);
	  var_fixed.Reset();
	}
#line 4103 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 320: // channel: CHANNEL channel_union
#line 1438 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetChannel(var_fixed);
	  var_fixed.Reset();
	}
#line 4115 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 321: // channel_union: FIXED IDENT
#line 1445 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.FixedChannel(yystack_[0].value.as < std::string > ());
	  var_fixed.fixed = static_cast<uint64_t>(
               	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4128 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 322: // channel_union: VARIABLE initial_enum
#line 1452 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = static_cast<uint64_t>(
	  	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4140 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 323: // initial_enum: %empty
#line 1459 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < bool > () = false; }
#line 4146 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 324: // initial_enum: INITIAL_VALUE IDENT
#line 1460 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel(yystack_[0].value.as < std::string > ());
	  yylhs.value.as < bool > () = true;
        }
#line 4158 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 325: // lpu_id_union: FIXED UINT
#line 1468 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4169 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 326: // lpu_id_union: VARIABLE initial_value
#line 1473 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = var_fixed.initial_value.value_or(0);
	}
#line 4180 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 327: // initial_value: %empty
#line 1479 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < bool > () = false;}
#line 4186 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 328: // initial_value: INITIAL_VALUE UINT
#line 1480 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.initial_value = yystack_[0].value.as < uint64_t > ();
	  yylhs.value.as < bool > () = true;
       }
#line 4198 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 332: // xcp_packet_option: CMD IDENT
#line 1495 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetCmd(yystack_[0].value.as < std::string > ());
 	}
#line 4208 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 333: // xcp_packet_option: RES_ERR IDENT
#line 1499 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetResErr(yystack_[0].value.as < std::string > ());
 	}
#line 4218 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 334: // xcp_packet_option: EV_SERV IDENT
#line 1503 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetEvServ(yystack_[0].value.as < std::string > ());
 	}
#line 4228 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 335: // xcp_packet_option: DAQ IDENT
#line 1507 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
	  	buffer.SetDaq(yystack_[0].value.as < std::string > ());
 	}
#line 4238 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 336: // xcp_packet_option: STIM IDENT
#line 1511 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
 	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
 	  	buffer.SetStim(yystack_[0].value.as < std::string > ());
 	}
#line 4248 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 337: // xcp_packet_option: MULTICAST IDENT
#line 1515 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
  	  	FlxBuffer& buffer = flx.GetCurrentFlxBuffer();
  	  	buffer.SetMulticast(yystack_[0].value.as < std::string > ());
 	}
#line 4258 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 338: // xcp_on_simulink: BLOCK_BEGIN XCP_ON_SIMULINK simulink_options transport_layer_instance BLOCK_END XCP_ON_SIMULINK
#line 1523 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
                   XcpOnSimulink& simulink = scanner.GetXcpOnSimulink();
                   simulink.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
                   scanner.SaveXcpOnSimulink();
                 }
#line 4268 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 341: // simulink_option: MODEL_NAME STRING
#line 1532 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		   scanner.GetXcpOnSimulink().SetModelName(yystack_[0].value.as < std::string > ());
		 }
#line 4276 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 342: // simulink_option: common_parameter
#line 1534 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
                    CommonParameters& common_parameters = scanner.GetCommonParameters();
                    scanner.GetXcpOnSimulink().SetOverrulingParameters(common_parameters);
                 }
#line 4285 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 343: // consistency: DAQ
#line 1539 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::string > () = "DAQ"; }
#line 4291 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 344: // consistency: EVENT
#line 1540 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < std::string > () = "EVENT"; }
#line 4297 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 345: // consistency: ODT
#line 1541 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "ODT"; }
#line 4303 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 346: // consistency: NONE
#line 1542 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::string > () = "NONE"; }
#line 4309 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 347: // daq_list_type: DAQ
#line 1544 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "DAQ"; }
#line 4315 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 348: // daq_list_type: STIM
#line 1545 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < std::string > () = "STIM"; }
#line 4321 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 349: // daq_list_type: DAQ_STIM
#line 1546 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = "DAQ_STIM"; }
#line 4327 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 350: // transport_layer_instance: %empty
#line 1548 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::string > ().clear(); }
#line 4333 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 351: // transport_layer_instance: TRANSPORT_LAYER_INSTANCE STRING
#line 1549 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4339 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 352: // ident_or_string: IDENT
#line 1551 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4345 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 353: // ident_or_string: STRING
#line 1552 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4351 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 354: // any_float: FLOAT
#line 1554 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 4357 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 355: // any_float: INT
#line 1555 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < int64_t > ()); }
#line 4363 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 356: // any_float: UINT
#line 1556 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < double > () = static_cast<double>(yystack_[0].value.as < uint64_t > ()); }
#line 4369 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 357: // any_int: INT
#line 1558 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 4375 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 358: // any_int: UINT
#line 1559 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 4381 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;


#line 4385 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

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
      13,   -58,    69,  -116,  -706,  -706,  -136,    59,    70,  -706,
      -3,   243,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,    70,
    -706,   -93,   -56,   -79,   -41,   -42,   -32,   -34,   -17,    11,
      24,    34,    47,    49,  -706,    52,  -706,  -706,   161,  -706,
    -706,   113,    63,    78,    80,  -706,  -706,    82,    84,   101,
     104,   105,     6,   107,   128,   182,   172,  -706,   230,   109,
     110,   112,   164,    89,  -706,  -706,  -706,   116,    81,   167,
     117,   119,  -706,  -706,   267,   121,   127,  -706,    39,  -706,
    -706,   177,  -706,   133,   136,   285,   154,  -706,   139,    97,
     142,   143,   144,  -706,   145,   148,  -706,   149,  -706,   152,
     157,   155,   158,   156,  -706,  -706,  -706,  -706,  -706,   322,
       0,     1,     3,   165,   162,  -706,  -706,   168,   166,  -706,
    -706,  -706,  -706,  -706,    43,   171,   173,  -132,  -706,  -706,
    -706,   176,   178,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,   180,   175,  -706,  -706,  -706,  -706,
    -706,  -706,   179,  -706,   186,   190,   192,   181,   198,   200,
     201,  -706,  -706,   341,   197,   202,   203,   206,   212,   215,
     217,  -706,  -706,   383,   219,   224,  -706,   225,    17,    20,
      30,   -19,   275,    54,  -706,  -706,  -706,   231,  -706,  -706,
    -706,  -132,    21,  -706,  -706,  -706,   226,   395,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,   240,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   248,  -706,   241,   242,   410,   392,   369,
      54,   247,  -706,   282,   417,   256,  -706,   263,    46,  -132,
     412,   266,   270,  -706,   271,   272,   273,   276,   253,   274,
    -706,    -5,     7,   421,  -706,   280,  -706,  -706,    -1,   279,
    -146,  -706,  -706,  -706,   436,   277,  -706,  -706,   365,   282,
    -706,   284,    12,   318,   286,  -706,  -706,  -706,  -706,  -132,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   415,
     288,  -706,  -706,  -706,   399,  -706,   390,  -706,   453,   295,
     345,   292,   296,  -706,  -706,  -706,   460,  -706,   297,   302,
     450,   305,   306,  -706,   468,   309,   310,   304,   314,  -706,
    -706,  -132,  -706,  -706,  -706,   315,   323,  -706,   317,   319,
     319,   319,   319,   319,  -706,  -706,   324,     5,  -706,   320,
    -706,   321,   325,   481,   326,   327,  -706,   328,  -132,   330,
    -706,   425,   329,   484,   489,   492,   495,   496,  -706,   307,
     332,  -706,  -706,   498,   160,  -706,   338,  -706,  -706,   335,
     340,   123,   337,  -132,   503,   343,   446,   346,   441,   442,
     443,   400,   401,   351,   351,   351,  -706,   355,    42,   485,
      38,    38,   354,  -706,   356,   357,   358,   359,   360,   361,
     362,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   257,   363,   364,   516,   513,   366,   367,
     370,  -706,   368,  -132,   465,  -706,   373,   527,   374,  -706,
    -706,  -706,  -706,  -706,  -706,   530,   536,   537,  -706,   377,
     378,   379,    41,   376,   381,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   514,
     384,  -706,   553,  -706,  -706,  -706,  -706,   478,   382,  -706,
    -706,   515,   385,     9,   482,   477,   435,    38,  -706,   393,
    -706,  -706,    41,   394,   388,  -706,   556,    50,  -706,   396,
     558,   397,  -706,   398,   -43,   -59,  -706,  -706,  -706,  -706,
    -706,  -706,   559,   387,   403,   404,   563,   402,   434,    -6,
     447,   407,   405,   406,   408,  -706,  -706,  -706,  -706,   456,
     411,   452,  -706,  -706,   414,   416,  -706,   555,   461,   547,
     -16,  -706,   419,   420,   422,   423,  -706,   424,   -16,  -706,
     486,   440,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     426,   427,  -706,    16,   106,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   428,   429,
     430,   592,  -706,   593,   223,   595,  -706,   520,   -46,   -45,
     -45,    29,  -706,  -706,  -706,  -706,  -706,   437,   431,   433,
     438,   439,   444,   445,  -706,   228,   451,   454,  -706,   466,
     455,   472,   552,  -706,   457,   458,  -706,   448,   538,  -706,
     459,   539,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   505,   494,  -706,   615,   462,  -706,  -706,   463,
    -706,   464,   467,  -706,   469,  -706,  -706,   470,  -706,   474,
    -706,   614,   617,   475,   471,   473,   618,  -706,  -706,  -706,
     479,   585,  -706,   574,   476,   613,    14,   483,  -706,   308,
    -706,   480,   627,  -706,   528,   487,  -706,   628,   207,   580,
     488,    86,   490,    38,   491,  -706,   493,  -706,  -706,   499,
     500,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,   497,
     502,  -706,   504,   631,    38,    38,    38,    38,   501,   506,
    -706,   507,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,   508,  -706,   509,  -706,   510,  -706,    38,    38,    38,
      38,   511,   512,  -706,  -706,   517,   518,    38,    38,   640,
     640,   519,   642,  -706,   522,   644,   644,   630,   647,  -706,
     652,  -706,   524,   560,   236,  -706,    19,   255,  -706,  -706,
    -706,   259,  -706,  -706,  -706,   525,   633,   637,  -706,  -706,
     570,   521,  -706,   526,   629,  -706,   632,  -706,    38,  -706,
    -706,    62,   529,  -706,    38,  -706,  -706,   670,   531,   635,
    -706,   532,   675,   657,  -706,  -706,   523,   575,  -706,   533,
    -706,   680,   587,  -706
  };

  const short
  XcpDataParser::yydefact_[] =
  {
       0,     0,     0,     0,     1,     5,     0,     0,     4,     5,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     3,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   339,     0,   191,   144,     0,   140,
     141,   150,     0,     0,     0,   186,   195,     0,     0,     0,
       0,     0,   350,     0,   142,   143,     0,   151,     0,     0,
       0,     0,     0,   350,   238,   252,   263,     0,     0,     0,
       0,     0,   342,   340,     0,     0,     0,   192,     0,   145,
     139,     0,   153,     0,     0,     0,     0,   187,     0,     0,
       0,     0,     0,   199,     0,     0,   208,     0,   212,     0,
       0,     0,     0,     0,   215,   196,   209,   210,   213,     0,
       0,   350,   350,     0,     0,   341,   351,     0,     0,   193,
     191,   191,   191,   149,     0,     0,     0,     0,   185,   202,
     226,     0,     0,   205,   197,   198,   200,   201,   211,   214,
     203,   204,   206,   207,     0,     0,   241,   242,   243,   244,
     245,   246,     0,   239,     0,     0,     0,     0,     0,     0,
       0,   261,   253,     0,     0,     0,     0,     0,     0,     0,
       0,   272,   264,     0,     0,     0,   338,     0,     0,     0,
       0,     0,     0,     0,   154,   156,   155,     0,   169,   358,
     357,     0,     0,   217,   222,   194,     0,   247,   255,   254,
     256,   257,   258,   260,   259,     0,   266,   265,   267,   268,
     269,   271,   270,     0,   274,     0,     0,     0,     0,     0,
       0,     0,   152,   163,     0,     0,   157,     0,     0,     0,
       0,     0,     0,   234,     0,     0,     0,     0,     0,     0,
     227,     0,     0,   249,   248,   350,   251,   262,   350,     0,
       0,   146,   148,   147,     0,     0,   164,   159,   165,   163,
     161,     0,     0,     0,     0,   170,   171,   173,   174,     0,
     225,   231,   229,   228,   230,   235,   232,   233,   236,     0,
       0,   219,   218,   220,     0,   223,     0,   240,     0,     0,
       0,     0,     0,   285,   275,   283,     0,   295,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,   168,
     172,     0,   216,   224,   221,     0,     0,   278,     0,     0,
       0,     0,     0,     0,   279,   284,     0,   350,    43,     0,
     158,     0,     0,     0,     0,     0,   176,     0,     0,     0,
     237,   287,     0,     0,     0,     0,     0,     0,   273,     0,
       0,   301,   296,     0,     0,    43,     0,   166,   160,     0,
       0,     0,     0,     0,     0,     0,   289,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   300,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,    50,    53,    46,    47,    48,    44,    51,    52,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,   177,     0,     0,     0,   288,     0,     0,     0,   281,
     282,   277,   280,   276,   303,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,    42,   356,   355,   354,    62,
      61,    45,    54,    56,    59,    60,    58,    57,    55,     0,
       0,    24,     0,   175,   179,   178,   180,   183,     0,   250,
     290,     0,     0,   302,     0,     0,     0,     0,    80,     0,
     352,   353,     0,     0,     0,    41,     0,     0,   182,     0,
       0,     0,   286,     0,     0,     0,   304,   306,   307,   297,
     298,   299,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    31,    28,   184,     0,
       0,   292,   311,   330,     0,     0,   305,     0,     0,     0,
       0,    87,     0,     0,     0,     0,    81,     0,     0,    69,
      70,    73,   167,    33,    23,    30,    26,    27,    29,   181,
       0,     0,   291,     0,     0,   308,   309,    75,    89,    79,
     347,   349,   348,    82,    86,    85,    83,    84,     0,     0,
       0,     0,    74,     0,     0,   189,   293,     0,     0,     0,
       0,     0,   312,   313,   314,   315,   316,     0,     0,     0,
       0,     0,     0,     0,   331,     0,     0,     0,    71,     0,
       0,     0,     0,    34,     0,     0,   310,     0,   323,   320,
       0,   327,   319,   317,   318,   329,   332,   335,   334,   337,
     333,   336,     0,     0,    90,    77,     0,    67,    72,     0,
      32,     0,     0,   321,     0,   322,   325,     0,   326,     0,
      88,     0,     0,     0,     0,     0,     0,   324,   328,    92,
       0,     0,    96,    36,     0,     0,     0,     0,    76,     0,
      37,     0,     0,   188,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,   106,   100,     0,
       0,   102,   107,    97,   108,   113,   114,   115,   116,     0,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,   343,   344,   346,   345,    99,    98,   112,   103,
     105,     0,   101,     0,   190,     0,    78,     0,     0,     0,
       0,     0,     0,   111,   109,     0,     0,     0,     0,   133,
     136,     0,     0,    38,     0,     0,     0,     0,     0,   134,
       0,   137,     0,     0,     0,    94,     0,     0,   122,   124,
     125,     0,   127,   129,   130,     0,     0,     0,   118,   110,
       0,     0,    39,     0,     0,   123,     0,   128,     0,   132,
     135,     0,     0,    35,     0,   121,   126,     0,     0,     0,
     119,     0,     0,     0,   120,   117,     0,     0,   138,     0,
     131,     0,     0,    40
  };

  const short
  XcpDataParser::yypgoto_[] =
  {
    -706,  -706,  -706,   693,  -706,   -61,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,   339,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   -40,  -706,  -706,   -39,  -705,  -706,  -706,  -706,
    -706,  -550,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,   221,   534,   449,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   100,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,   535,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
    -706,  -706,  -706,  -126,  -706,  -706,  -706,  -706,  -111,  -706,
    -706,  -706,  -706,  -706,   129,  -706,  -706,  -706,  -706,  -706,
    -706,   134,  -706,  -706,  -706,  -706,  -706,  -706,  -706,  -706,
     183,   -71,   227,  -391,  -198
  };

  const short
  XcpDataParser::yydefgoto_[] =
  {
       0,     2,     7,     8,    12,    13,    14,    15,   487,   515,
     516,   574,   603,   661,   744,   762,    16,   364,   406,   407,
     540,   571,   408,   573,   409,   410,   642,   411,   503,   536,
     595,   624,   656,   666,   412,   659,   683,   684,   771,   780,
     685,   747,   748,   686,   751,   752,   749,   687,   738,   688,
     740,   750,    17,    48,    49,    50,    65,    89,    18,    68,
      19,   134,   194,   195,   236,   267,   268,   313,   196,    20,
     238,   275,   276,   371,   421,   277,   278,   490,    21,    72,
      97,   605,    64,    87,    22,    73,   115,   116,   251,   292,
     117,   252,   293,   118,   202,   250,    23,   120,   163,   255,
     297,    24,   121,   172,    25,   122,   182,    26,   258,   304,
     305,   376,   427,   353,   552,    27,   337,   362,   435,   473,
     496,   526,   497,   553,   582,   583,   584,   585,   586,   609,
     635,   612,   638,   498,   554,   594,    28,    62,    83,   706,
     563,    84,   482,   449,   201
  };

  const short
  XcpDataParser::yytable_[] =
  {
     450,    82,   119,   239,   164,   299,   174,   155,   289,   230,
     524,   300,   114,    79,    46,    79,   316,   359,    79,     3,
     294,   494,   230,   607,   610,     1,   560,   664,   308,   577,
     227,   753,   309,   228,   240,   241,   561,   317,     9,   242,
     578,   279,   199,   229,   200,   522,   753,   130,     5,     6,
     173,   183,   755,   578,   543,   191,   192,   579,   272,   273,
     171,   181,   509,   510,   290,   233,   234,   778,   131,     4,
     579,   193,    10,   439,    30,   779,   290,   165,   193,   175,
      86,   321,    11,    86,   301,    45,   502,   440,   166,   580,
     176,   441,   132,    86,   167,    51,   177,   168,    98,   178,
     274,    99,   580,   100,   525,   442,   495,    47,   101,   102,
     103,   104,   105,   243,   140,   244,    80,   608,   611,   587,
     302,   231,   169,   348,   179,   170,   360,   180,   702,   665,
     523,   562,    53,   588,   581,   763,   417,    52,   318,    31,
     235,    32,    54,   141,    55,   511,   254,   581,   589,   703,
     373,   156,   157,   158,   159,   160,   161,    56,   291,   245,
      81,   142,    81,   246,    81,   247,    81,    81,   590,   512,
     513,   248,   388,   389,    66,   423,    95,    96,   162,   739,
     741,   106,   107,   249,   298,    57,   754,   306,    67,   443,
     418,    86,   390,   514,    88,   108,   391,   303,    58,   704,
     705,   754,   444,   392,   354,   355,   356,   357,    59,    31,
     109,    32,   446,   419,   447,   448,    90,   393,   591,   480,
     481,    60,    33,    61,    34,   468,    63,   110,   111,    35,
     188,   189,   190,   112,   420,   601,   602,    69,    36,   113,
     622,   623,   592,    91,   694,   695,   696,   697,   760,   761,
      81,   394,    70,   593,    71,    37,    74,   698,    75,   395,
     124,   396,   397,   398,   399,   400,   363,   746,   764,   388,
     459,   746,   766,   436,   437,    76,   361,   401,    77,    78,
     127,    85,   708,    92,    93,    31,    94,    32,   402,   390,
     123,   403,    33,   391,    34,   128,   125,   404,   126,    35,
     392,   129,   133,   717,   718,   719,   720,   135,    36,   405,
     136,   137,   138,   139,   393,   699,   143,   144,   145,   146,
     668,   669,   147,   148,   670,    37,   727,   728,   729,   730,
     149,   150,   152,   151,   153,   154,   735,   736,   671,   184,
     186,   185,   672,   673,   187,   197,   205,   198,   394,    31,
     203,    32,   204,   206,   215,   211,   395,   207,   396,   397,
     398,   399,   400,   674,   675,   208,   676,   677,    33,   209,
      34,   210,   212,   678,   401,    35,   216,   777,   213,   214,
     219,   217,   218,   782,    36,   402,   220,    31,   403,    32,
     383,   384,   328,   221,   404,   222,   223,   224,   225,   528,
     529,    37,   232,   226,   253,   237,   405,    79,   256,    38,
      39,    40,    41,    42,    43,    44,   679,   257,   261,   259,
     260,   262,   263,   329,   330,   331,   265,   266,   269,   280,
     270,   287,    33,   296,    34,   530,   385,   271,   531,    35,
     281,    81,   680,   681,   282,   283,   284,   285,    36,   310,
     286,   311,   288,   532,   312,   533,   682,   307,   315,   319,
     320,   322,   323,   324,   325,    37,   326,   332,   333,   327,
      33,   334,    34,   336,   335,   338,   339,    35,   340,   341,
     342,   343,   346,   344,   345,   534,    36,   535,   347,   349,
     350,   351,   368,   352,   358,   366,   375,   378,   365,   367,
     369,   370,   379,    37,   374,   380,   372,   377,   381,   382,
     386,   387,   414,   415,   416,   422,   424,   425,   426,   429,
     428,   430,   432,   431,   433,   434,   438,   445,   451,   462,
     452,   453,   454,   455,   456,   457,   458,   460,   463,   469,
     471,   465,   461,   474,   466,   464,   467,   470,   472,   475,
     476,   477,   478,   479,   483,   484,   485,   488,   486,   489,
     491,   500,   492,   493,   501,   499,   507,   504,   506,   508,
     518,   519,   527,   539,   542,   520,   521,   537,   538,   544,
     541,   545,   549,   546,   547,   551,   557,   548,   555,   550,
     556,   558,   559,   564,   565,   570,   566,   567,   568,   572,
     575,   576,   596,   597,   598,   599,   600,   604,   606,   616,
     615,   617,   630,   627,   631,   628,   618,   619,   629,   639,
     634,   637,   620,   621,   640,   625,   633,   641,   626,   650,
     651,   655,   632,   636,   658,   660,   643,   644,   645,   663,
     690,   693,   691,   700,   648,   646,   716,   647,   649,   652,
     653,   654,   737,   657,   662,   743,   746,   667,   689,   714,
     756,   692,   701,   755,   707,   757,   775,   773,   759,   709,
     776,   710,   769,   711,   712,   713,   770,   772,   715,   721,
     722,   723,   724,   783,   726,   785,   732,   725,   787,   731,
     788,   790,   734,   792,   793,   733,   745,   742,   758,   768,
     774,   789,    29,   781,   413,   784,   786,   765,   517,   505,
     614,   791,   767,     0,   613,     0,     0,     0,   314,     0,
       0,   569,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295
  };

  const short
  XcpDataParser::yycheck_[] =
  {
     391,    62,    73,   201,     3,     6,     3,     7,    13,    28,
      69,    12,    73,    12,    70,    12,     4,    12,    12,    77,
      13,    12,    28,    69,    69,    12,    42,    13,   174,    13,
      13,   736,   178,    13,    13,    14,    52,    25,   174,    18,
      24,   239,   174,    13,   176,    88,   751,     8,   164,   165,
     121,   122,    33,    24,    60,    12,    13,    41,    12,    13,
     121,   122,    12,    13,    69,    11,    12,     5,    29,     0,
      41,    28,    13,    31,    77,    13,    69,    76,    28,    76,
      63,   279,    12,    63,    85,   178,   477,    45,    87,    73,
      87,    49,    53,    63,    93,   174,    93,    96,     9,    96,
      54,    12,    73,    14,   163,    63,    97,   163,    19,    20,
      21,    22,    23,    92,    17,    94,   110,   163,   163,    13,
     121,   140,   121,   321,   121,   124,   121,   124,    42,   115,
     173,   147,   174,    27,   118,   116,    13,   178,   126,    42,
      86,    44,   174,    46,   178,    95,   207,   118,    42,    63,
     348,   151,   152,   153,   154,   155,   156,   174,   163,   138,
     161,    64,   161,   142,   161,   144,   161,   161,    62,   119,
     120,   150,    12,    13,    13,   373,    12,    13,   178,   729,
     730,    92,    93,   162,   255,   174,   736,   258,    75,   147,
      67,    63,    32,   143,    12,   106,    36,   258,   174,   113,
     114,   751,   160,    43,   330,   331,   332,   333,   174,    42,
     121,    44,   174,    90,   176,   177,    44,    57,   112,   178,
     179,   174,   125,   174,   127,   423,   174,   138,   139,   132,
     130,   131,   132,   144,   111,    12,    13,   174,   141,   150,
      12,    13,   136,    13,    37,    38,    39,    40,    12,    13,
     161,    91,   174,   147,   174,   158,   174,    50,   174,    99,
     179,   101,   102,   103,   104,   105,   337,    12,    13,    12,
      13,    12,    13,   384,   385,   174,   337,   117,   174,   174,
      13,   174,   673,   174,   174,    42,   174,    44,   128,    32,
     174,   131,   125,    36,   127,   174,   179,   137,   179,   132,
      43,   174,   125,   694,   695,   696,   697,   174,   141,   149,
     174,    26,   158,   174,    57,   108,   174,   174,   174,   174,
      12,    13,   174,   174,    16,   158,   717,   718,   719,   720,
     178,   174,   174,   178,   178,    13,   727,   728,    30,   174,
     172,   179,    34,    35,   178,   174,   166,   174,    91,    42,
     174,    44,   174,   178,    13,   174,    99,   178,   101,   102,
     103,   104,   105,    55,    56,   179,    58,    59,   125,   179,
     127,   179,   174,    65,   117,   132,   179,   768,   178,   178,
     174,   179,   179,   774,   141,   128,   174,    42,   131,    44,
      83,    84,    47,   178,   137,   178,    13,   178,   174,    12,
      13,   158,   127,   178,   178,   174,   149,    12,   168,   166,
     167,   168,   169,   170,   171,   172,   108,   169,     8,   178,
     178,    29,    53,    78,    79,    80,   179,   145,    11,    17,
     174,   178,   125,    12,   127,    48,   129,   174,    51,   132,
     174,   161,   134,   135,   174,   174,   174,   174,   141,    13,
     174,   174,   178,    66,    89,    68,   148,   178,   174,   141,
     174,    46,   174,    64,    74,   158,    13,   122,   123,   174,
     125,   179,   127,    13,   178,   178,   174,   132,    28,   174,
     174,    13,   178,   174,   174,    98,   141,   100,   174,   174,
     167,   174,    11,   174,   170,   174,    71,    13,   178,   174,
     174,   174,    13,   158,   174,    13,   178,   178,    13,    13,
     178,    13,   174,   178,   174,   178,    13,   174,    72,    78,
     174,    79,   122,    80,   123,   174,   171,    42,   174,    13,
     174,   174,   174,   174,   174,   174,   174,   174,    25,    74,
      13,   174,   178,    13,   174,   179,   178,   174,   174,    13,
      13,   174,   174,   174,   178,   174,    42,     4,   174,    81,
     178,    84,    47,   178,   129,    83,   178,   174,   174,    13,
     174,    13,    13,    10,   140,   178,   178,   174,   174,   132,
     178,   174,   126,   178,   178,   133,    31,   179,   174,   178,
     174,   130,    45,   174,   174,   109,   174,   174,   174,   159,
     174,   174,   174,   174,   174,    13,    13,    12,    88,   178,
     173,   178,    60,   147,   157,   160,   178,   178,   146,   114,
      82,    82,   178,   178,   130,   174,   178,    12,   174,    15,
      13,    13,   174,   174,    49,    61,   174,   174,   174,    26,
      13,    13,   114,    63,   174,   178,    15,   178,   174,   174,
     179,   178,    12,   174,   178,    13,    12,   174,   178,   157,
      13,   174,   174,    33,   174,    13,    37,   146,   108,   178,
      38,   178,    39,   174,   174,   178,    39,   107,   174,   178,
     174,   174,   174,    13,   174,    50,   174,   178,    13,   178,
      33,   116,   174,    13,   107,   178,   174,   178,   174,   174,
     174,   178,     9,   174,   365,   174,   174,   747,   487,   482,
     581,   178,   751,    -1,   580,    -1,    -1,    -1,   269,    -1,
      -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   252
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
      13,   114,   174,    13,    37,    38,    39,    40,    50,   108,
      63,   174,    42,    63,   113,   114,   319,   174,   323,   178,
     178,   174,   174,   178,   157,   174,    15,   323,   323,   323,
     323,   178,   174,   174,   174,   178,   174,   323,   323,   323,
     323,   178,   174,   178,   174,   323,   323,    12,   228,   231,
     230,   231,   178,    13,   194,   174,    12,   221,   222,   226,
     231,   224,   225,   226,   231,    33,    13,    13,   174,   108,
      12,    13,   195,   116,    13,   222,    13,   225,   174,    39,
      39,   218,   107,   146,   174,    37,    38,   323,     5,    13,
     219,   174,   323,    13,   174,    50,   174,    13,    33,   178,
     116,   178,    13,   107
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
     216,   216,   216,   216,   216,   216,   216,   217,   218,   218,
     219,   220,   221,   221,   222,   222,   223,   224,   224,   225,
     225,   226,   227,   228,   228,   229,   230,   230,   231,   232,
     233,   233,   234,   235,   236,   236,   237,   237,   237,   238,
     239,   239,   240,   241,   241,   242,   242,   243,   243,   244,
     244,   244,   245,   246,   246,   247,   247,   248,   249,   250,
     250,   251,   251,   251,   251,   252,   253,   253,   254,   254,
     254,   255,   256,   257,   257,   258,   259,   259,   260,   261,
     261,   262,   262,   263,   264,   265,   265,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   268,   268,   269,
     269,   270,   271,   271,   272,   273,   274,   274,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   276,   277,   277,
     278,   278,   278,   278,   278,   278,   278,   279,   279,   280,
     280,   281,   282,   282,   283,   283,   283,   283,   283,   283,
     283,   283,   284,   285,   285,   286,   286,   286,   286,   286,
     286,   286,   286,   287,   288,   288,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   290,   291,   291,   292,
     292,   293,   294,   294,   295,   296,   296,   297,   297,   297,
     297,   297,   298,   299,   299,   300,   300,   300,   301,   301,
     302,   303,   303,   304,   304,   304,   304,   305,   306,   307,
     308,   309,   309,   310,   310,   311,   311,   312,   312,   313,
     314,   314,   315,   315,   315,   315,   315,   315,   316,   317,
     317,   318,   318,   319,   319,   319,   319,   320,   320,   320,
     321,   321,   322,   322,   323,   323,   323,   324,   324
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
       6,     3,     2,     1,     1,     1,     1,     9,     0,     2,
       2,     8,     1,     2,     1,     1,     8,     1,     2,     1,
       1,     6,     7,     0,     1,     7,     0,     1,     6,     5,
       1,     1,     2,     2,     0,     2,     5,     5,     5,     6,
       0,     1,     8,     0,     2,     1,     1,     2,     5,     2,
       5,     2,     2,     0,     1,     0,     3,    11,    10,     0,
       2,     1,     2,     1,     1,     6,     0,     2,     2,     2,
       2,     9,     7,     0,     2,     6,     0,     2,    19,     0,
       7,     0,     2,     2,     7,     0,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     2,     1,     1,     2,     1,     6,     0,     2,     1,
       1,     6,     0,     2,     2,     5,     0,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,    11,     0,     2,
       4,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       6,     8,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     8,     0,     2,     2,     2,     2,     2,     2,
       2,     2,     1,    11,     0,     2,     5,     5,     2,     2,
       5,     5,     5,     1,     2,     1,     7,     0,     2,     0,
       2,     7,     0,     2,    13,     0,     2,     5,     5,     5,
       2,     1,     2,     0,     2,     2,     1,     1,     2,     2,
       5,     0,     2,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     0,     2,     2,     2,     0,     2,     5,
       0,     2,     2,     2,     2,     2,     2,     2,     6,     0,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1
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
     553,   559,   565,   568,   571,   574,   577,   582,   592,   593,
     598,   600,   611,   612,   614,   617,   622,   633,   634,   636,
     639,   644,   651,   661,   662,   667,   677,   678,   683,   690,
     698,   699,   701,   706,   707,   708,   710,   715,   720,   727,
     734,   735,   740,   751,   752,   754,   757,   762,   766,   774,
     775,   778,   784,   785,   786,   790,   791,   798,   810,   823,
     824,   826,   827,   830,   831,   836,   846,   847,   849,   852,
     855,   860,   873,   881,   882,   887,   896,   897,   899,   923,
     924,   935,   936,   940,   942,   951,   952,   954,   957,   960,
     963,   966,   969,   972,   975,   978,   981,   984,   987,   990,
     991,   992,   996,   999,  1000,  1003,  1010,  1019,  1020,  1022,
    1026,  1032,  1042,  1043,  1047,  1049,  1056,  1057,  1059,  1063,
    1067,  1071,  1075,  1079,  1083,  1087,  1091,  1097,  1109,  1110,
    1112,  1118,  1121,  1124,  1127,  1130,  1133,  1138,  1139,  1146,
    1147,  1156,  1166,  1167,  1169,  1172,  1175,  1178,  1181,  1184,
    1187,  1190,  1197,  1207,  1208,  1210,  1213,  1216,  1219,  1222,
    1225,  1228,  1231,  1238,  1251,  1252,  1254,  1259,  1264,  1267,
    1270,  1275,  1280,  1285,  1288,  1291,  1298,  1305,  1306,  1311,
    1312,  1317,  1327,  1328,  1332,  1348,  1349,  1350,  1357,  1364,
    1371,  1374,  1380,  1385,  1386,  1387,  1394,  1395,  1396,  1401,
    1407,  1411,  1412,  1413,  1414,  1415,  1416,  1417,  1424,  1431,
    1438,  1445,  1452,  1459,  1460,  1468,  1473,  1479,  1480,  1488,
    1492,  1493,  1495,  1499,  1503,  1507,  1511,  1515,  1521,  1529,
    1530,  1532,  1534,  1539,  1540,  1541,  1542,  1544,  1545,  1546,
    1548,  1549,  1551,  1552,  1554,  1555,  1556,  1558,  1559
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
#line 5364 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

#line 1560 "D:/projects/a2llib/src/xcp/xcpdataparser.y"


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
