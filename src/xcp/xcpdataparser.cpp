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
#line 146 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
       scanner.SetVersion(yystack_[1].value.as < uint64_t > ());
      }
#line 1820 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 7: // definition: common_parameter
#line 153 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  scanner.SaveCommonParameters();
	}
#line 1828 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 9: // common_parameter: protocol_layer
#line 157 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	CommonParameters& common = scanner.GetCommonParameters();
	common.SetProtocolLayer(std::move(yystack_[0].value.as < ProtocolLayer > ()));
    }
#line 1837 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 10: // common_parameter: daq
#line 160 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaq(std::move(yystack_[0].value.as < Daq > ()));
    }
#line 1846 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 11: // common_parameter: daq_event
#line 163 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaqEvent(std::move(yystack_[0].value.as < DaqEvent > ()));
    }
#line 1855 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 12: // common_parameter: pag
#line 166 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPag(std::move(yystack_[0].value.as < Pag > ()));
    }
#line 1864 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 13: // common_parameter: pgm
#line 169 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPgm(std::move(yystack_[0].value.as < Pgm > ()));
    }
#line 1873 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 14: // common_parameter: segment
#line 172 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetSegment(std::move(yystack_[0].value.as < Segment > ()));
    }
#line 1882 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 15: // common_parameter: time_correlation
#line 175 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	CommonParameters& common = scanner.GetCommonParameters();
        common.SetTimeCorrelation(std::move(yystack_[0].value.as < TimeCorrelation > ()));
    }
#line 1891 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 23: // protocol_layer: BLOCK_BEGIN PROTOCOL_LAYER UINT UINT UINT UINT UINT UINT UINT UINT UINT UINT IDENT IDENT protocol_optional_items BLOCK_END PROTOCOL_LAYER
#line 190 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 1912 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 26: // protocol_optional_item: OPTIONAL_CMD IDENT
#line 210 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommand(yystack_[0].value.as < std::string > ());
        }
#line 1921 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 27: // protocol_optional_item: OPTIONAL_LEVEL1_CMD IDENT
#line 213 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommandLevel1(yystack_[0].value.as < std::string > ());
	}
#line 1930 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 28: // protocol_optional_item: communication_mode_supported
#line 216 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetCommunicationMode(std::move(yystack_[0].value.as < CommunicationMode > ()));
	}
#line 1939 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 29: // protocol_optional_item: SEED_AND_KEY_EXTERNAL_FUNCTION STRING
#line 219 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                  {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetSeedAndKeyFunction(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1948 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 30: // protocol_optional_item: MAX_DTO_STIM UINT
#line 222 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetMaxDtoStim(yystack_[0].value.as < uint64_t > ());
	}
#line 1957 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 31: // protocol_optional_item: ecu_states
#line 225 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetEcuStates(std::move(yystack_[0].value.as < std::vector<EcuState> > ()));
	}
#line 1966 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 32: // ecu_states: BLOCK_BEGIN ECU_STATES state_list BLOCK_END ECU_STATES
#line 232 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::vector<EcuState> > () = std::move(yystack_[2].value.as < std::vector<EcuState> > ()); }
#line 1972 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 33: // state_list: %empty
#line 234 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<EcuState> > ().clear(); }
#line 1978 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 34: // state_list: state_list state_block
#line 235 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
            	yylhs.value.as < std::vector<EcuState> > () = std::move(yystack_[1].value.as < std::vector<EcuState> > ());
            	yylhs.value.as < std::vector<EcuState> > ().emplace_back(std::move(yystack_[0].value.as < EcuState > ()));
            }
#line 1987 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 35: // state_block: BLOCK_BEGIN STATE UINT STRING ecu_switch_to_default IDENT IDENT IDENT IDENT memory_access_list BLOCK_END STATE
#line 242 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
             	yylhs.value.as < EcuState > ().SetNumber(yystack_[9].value.as < uint64_t > ());
             	yylhs.value.as < EcuState > ().SetName(yystack_[8].value.as < std::string > ());
             	yylhs.value.as < EcuState > ().SetEcuSwithedToDefaultPage(yystack_[7].value.as < bool > ());
             	yylhs.value.as < EcuState > ().SetCalPagResource(yystack_[6].value.as < std::string > ());
             	yylhs.value.as < EcuState > ().SetDaqResource(yystack_[5].value.as < std::string > ());
              	yylhs.value.as < EcuState > ().SetPgmResource(yystack_[4].value.as < std::string > ());
              	yylhs.value.as < EcuState > ().SetStimResource(yystack_[3].value.as < std::string > ());
              	yylhs.value.as < EcuState > ().SetMemoryAccessList(yystack_[2].value.as < std::vector<MemoryAccess> > ());
             }
#line 2002 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 36: // ecu_switch_to_default: %empty
#line 253 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < bool > () = false; }
#line 2008 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 37: // ecu_switch_to_default: ECU_SWITCHED_TO_DEFAULT_PAGE
#line 254 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                      { yylhs.value.as < bool > () = true; }
#line 2014 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 38: // memory_access_list: %empty
#line 256 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           { yylhs.value.as < std::vector<MemoryAccess> > ().clear(); }
#line 2020 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 39: // memory_access_list: memory_access_list memory_access
#line 257 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
         		yylhs.value.as < std::vector<MemoryAccess> > () = std::move(yystack_[1].value.as < std::vector<MemoryAccess> > ());
         		yylhs.value.as < std::vector<MemoryAccess> > ().emplace_back(yystack_[0].value.as < MemoryAccess > ());
                    }
#line 2029 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 40: // memory_access: BLOCK_BEGIN MEMORY_ACCESS UINT UINT IDENT IDENT BLOCK_END MEMORY_ACCESS
#line 263 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		yylhs.value.as < MemoryAccess > ().SetSegment(yystack_[5].value.as < uint64_t > ());
		yylhs.value.as < MemoryAccess > ().SetPage(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < MemoryAccess > ().SetReadAccess(yystack_[3].value.as < std::string > ());
		yylhs.value.as < MemoryAccess > ().SetWriteAccess(yystack_[2].value.as < std::string > ());
	}
#line 2040 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 41: // daq: BLOCK_BEGIN DAQ IDENT UINT UINT UINT IDENT IDENT IDENT IDENT UINT IDENT daq_optionals BLOCK_END DAQ
#line 272 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 2060 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 42: // daq: BLOCK_BEGIN DAQ IDENT UINT UINT UINT IDENT IDENT IDENT UINT IDENT daq_optionals BLOCK_END DAQ
#line 288 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 2079 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 45: // daq_optional: DAQ_ALTERNATING_SUPPORTED UINT
#line 306 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqAlternatingSupported(yystack_[0].value.as < uint64_t > ());
      }
#line 2088 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 46: // daq_optional: PRESCALER_SUPPORTED
#line 309 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPrecalerSupported();
      }
#line 2097 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 47: // daq_optional: RESUME_SUPPORTED
#line 312 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
      	Daq& daq = scanner.GetDaq();
      	daq.SetResumeSupported();
      }
#line 2106 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 48: // daq_optional: STORE_DAQ_SUPPORTED
#line 315 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStoreDaqSupported();
      }
#line 2115 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 49: // daq_optional: DTO_CTR_FIELD_SUPPORTED
#line 318 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDtoCtrSupported();
      }
#line 2124 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 50: // daq_optional: OPTIMISATION_TYPE_ODT_STRICT
#line 321 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Daq& daq = scanner.GetDaq();
      	daq.SetOptimisationTypeOdtStrict();
      }
#line 2133 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 51: // daq_optional: stim_struct
#line 324 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStim(yystack_[0].value.as < DaqStim > ());
      }
#line 2142 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 52: // daq_optional: timestamp_supported
#line 327 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetTimestamp(yystack_[0].value.as < Timestamp > ());
      }
#line 2151 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 53: // daq_optional: PID_OFF_SUPPORTED
#line 330 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPidOffSupported();
      }
#line 2160 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 54: // daq_optional: MAX_DAQ_TOTAL UINT
#line 333 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2169 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 55: // daq_optional: MAX_ODT_TOTAL UINT
#line 336 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2178 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 56: // daq_optional: MAX_ODT_DAQ_TOTAL UINT
#line 339 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2187 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 57: // daq_optional: MAX_ODT_STIM_TOTAL UINT
#line 342 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtStimTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2196 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 58: // daq_optional: MAX_ODT_ENTRIES_TOTAL UINT
#line 345 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2205 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 59: // daq_optional: MAX_ODT_ENTRIES_DAQ_TOTAL UINT
#line 348 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2214 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 60: // daq_optional: MAX_ODT_ENTRIES_STIM_TOTAL UINT
#line 351 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesStimTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2223 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 61: // daq_optional: CPU_LOAD_MAX_TOTAL FLOAT
#line 354 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCpuLoadMaxTotal(yystack_[0].value.as < double > ());
      }
#line 2232 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 62: // daq_optional: CORE_LOAD_MAX_TOTAL FLOAT
#line 357 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCoreLoadMaxTotal(yystack_[0].value.as < double > ());
      }
#line 2241 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 63: // daq_optional: core_load_max
#line 360 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Daq& daq = scanner.GetDaq();
      	daq.AddCoreLoadMax(yystack_[0].value.as < CoreLoadMax > ());
      }
#line 2250 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 64: // daq_optional: daq_memory_consumption
#line 363 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqMemoryConsumption(yystack_[0].value.as < DaqMemoryConsumption > ());
      }
#line 2259 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 65: // daq_optional: daq_list
#line 366 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Daq& daq = scanner.GetDaq();
      	daq.AddDaqList(std::move(yystack_[0].value.as < DaqList > ()));
      }
#line 2268 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 66: // daq_optional: d_event
#line 369 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
      	Daq& daq = scanner.GetDaq();
      	daq.AddEvent(std::move(yystack_[0].value.as < Event > ()));
      }
#line 2277 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 67: // stim_struct: BLOCK_BEGIN STIM IDENT UINT bit_stim min_st_stim BLOCK_END STIM
#line 376 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		yylhs.value.as < DaqStim > ().SetSize(yystack_[5].value.as < std::string > ());
		yylhs.value.as < DaqStim > ().max_odt_entry_size = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < DaqStim > ().bit_stim_supported = yystack_[3].value.as < bool > ();
		yylhs.value.as < DaqStim > ().min_st_stim = yystack_[2].value.as < std::optional<uint8_t> > ();
	  }
#line 2288 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 68: // bit_stim: %empty
#line 383 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < bool > () = false; }
#line 2294 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 69: // bit_stim: BIT_STIM_SUPPORTED
#line 384 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               { yylhs.value.as < bool > () = true; }
#line 2300 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 70: // min_st_stim: %empty
#line 386 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::optional<uint8_t> > ().reset(); }
#line 2306 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 71: // min_st_stim: MIN_ST_STIM UINT
#line 387 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                { yylhs.value.as < std::optional<uint8_t> > () = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2312 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 72: // timestamp_supported: BLOCK_BEGIN TIMESTAMP_SUPPORTED UINT IDENT IDENT timestamp_fixed BLOCK_END TIMESTAMP_SUPPORTED
#line 391 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
     		yylhs.value.as < Timestamp > ().SetTicks(yystack_[5].value.as < uint64_t > ());
     		yylhs.value.as < Timestamp > ().SetSize(yystack_[4].value.as < std::string > ());
     		yylhs.value.as < Timestamp > ().SetResolution(yystack_[3].value.as < std::string > ());
     		if (yystack_[2].value.as < bool > ()) {
     		  yylhs.value.as < Timestamp > ().SetFixed();
     		}
          }
#line 2325 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 73: // timestamp_fixed: %empty
#line 400 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        { yylhs.value.as < bool > () = false; }
#line 2331 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 74: // timestamp_fixed: TIMESTAMP_FIXED
#line 401 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {yylhs.value.as < bool > () = true;}
#line 2337 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 75: // core_load_max: BLOCK_BEGIN CORE_LOAD_MAX UINT FLOAT BLOCK_END CORE_LOAD_MAX
#line 405 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
	       	yylhs.value.as < CoreLoadMax > ().number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	       	yylhs.value.as < CoreLoadMax > ().max = static_cast<float>(yystack_[2].value.as < double > ());
	       }
#line 2346 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 76: // daq_memory_consumption: BLOCK_BEGIN DAQ_MEMORY_CONSUMPTION UINT UINT UINT UINT UINT UINT buffer_reserve BLOCK_END DAQ_MEMORY_CONSUMPTION
#line 412 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
              yylhs.value.as < DaqMemoryConsumption > ().limit = static_cast<uint32_t>(yystack_[8].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().daq_size = static_cast<uint16_t>(yystack_[7].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_size = static_cast<uint16_t>(yystack_[6].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_entry_size = static_cast<uint16_t>(yystack_[5].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_daq_buffer_element_size = static_cast<uint16_t>(yystack_[4].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_stim_buffer_element_size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().dto_stim_size = yystack_[2].value.as < std::optional<BufferReserve> > ();
           }
#line 2360 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 77: // buffer_reserve: %empty
#line 422 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::optional<BufferReserve> > ().reset(); }
#line 2366 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 78: // buffer_reserve: BLOCK_BEGIN BUFFER_RESERVE UINT UINT BLOCK_END BUFFER_RESERVE
#line 425 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
	     BufferReserve buffer;
	     buffer.odt_daq_buffer = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
	     buffer.odt_stim_buffer = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
	     yylhs.value.as < std::optional<BufferReserve> > () = buffer;
	   }
#line 2377 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 79: // daq_list: BLOCK_BEGIN DAQ_LIST UINT daq_list_optionals BLOCK_END DAQ_LIST
#line 434 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetNumber(yystack_[3].value.as < uint64_t > ());
	   	yylhs.value.as < DaqList > () = std::move(list);
	   	list.Reset();
          }
#line 2388 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 82: // daq_list_optional: DAQ_LIST_TYPE daq_list_type
#line 444 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetType(yystack_[0].value.as < std::string > ());
           }
#line 2397 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 83: // daq_list_optional: MAX_ODT UINT
#line 447 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdt(yystack_[0].value.as < uint64_t > ());
	   }
#line 2406 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 84: // daq_list_optional: MAX_ODT_ENTRIES UINT
#line 450 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdtEntries(yystack_[0].value.as < uint64_t > ());
	   }
#line 2415 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 85: // daq_list_optional: FIRST_PID UINT
#line 453 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetFirstPid(yystack_[0].value.as < uint64_t > ());
	   }
#line 2424 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 86: // daq_list_optional: EVENT_FIXED UINT
#line 456 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetEventFixed(yystack_[0].value.as < uint64_t > ());
	   }
#line 2433 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 87: // daq_list_optional: DAQ_PACKED_MODE_SUPPORTED
#line 459 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetDaqPackedModeSupported();
	   }
#line 2442 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 88: // daq_list_optional: BLOCK_BEGIN PREDEFINED odt_list BLOCK_END PREDEFINED
#line 464 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetPredefinedList(std::move(yystack_[2].value.as < std::vector<Odt> > ()));
	   }
#line 2451 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 89: // odt_list: %empty
#line 469 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::vector<Odt> > () = {}; }
#line 2457 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 90: // odt_list: odt_list odt
#line 470 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	yylhs.value.as < std::vector<Odt> > () = std::move(yystack_[1].value.as < std::vector<Odt> > ());
     	yylhs.value.as < std::vector<Odt> > ().emplace_back(std::move(yystack_[0].value.as < Odt > ()));
     }
#line 2466 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 91: // odt: BLOCK_BEGIN ODT UINT odt_entry_list BLOCK_END ODT
#line 477 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	yylhs.value.as < Odt > ().number = yystack_[3].value.as < uint64_t > ();
     	yylhs.value.as < Odt > ().odt_entry_list = std::move(yystack_[2].value.as < std::vector<OdtEntry> > ());
     }
#line 2475 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 92: // odt_entry_list: %empty
#line 482 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::vector<OdtEntry> > () = {}; }
#line 2481 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 93: // odt_entry_list: odt_entry_list odt_entry
#line 483 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
         	yylhs.value.as < std::vector<OdtEntry> > () = std::move(yystack_[1].value.as < std::vector<OdtEntry> > ());
         	yylhs.value.as < std::vector<OdtEntry> > ().emplace_back(std::move(yystack_[0].value.as < OdtEntry > ()));
         }
#line 2490 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 94: // odt_entry: ODT_ENTRY UINT UINT UINT UINT UINT
#line 488 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
		yylhs.value.as < OdtEntry > ().number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().address = yystack_[3].value.as < uint64_t > ();
		yylhs.value.as < OdtEntry > ().address_extension = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().size = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().bit_offset = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
	}
#line 2502 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 95: // d_event: BLOCK_BEGIN EVENT ident_or_string ident_or_string UINT daq_list_type UINT UINT UINT UINT d_event_optionals BLOCK_END EVENT
#line 498 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 2520 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 98: // d_event_optional: COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER UINT
#line 513 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
		Event& event = scanner.GetEvent();
                event.SetComplementaryBypassNumber(yystack_[0].value.as < uint64_t > ());
        }
#line 2529 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 99: // d_event_optional: CONSISTENCY consistency
#line 516 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetConsistency(yystack_[0].value.as < std::string > ());
	}
#line 2538 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 100: // d_event_optional: EVENT_COUNTER_PRESENT
#line 519 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
		Event& event = scanner.GetEvent();
                event.SetEventCounterPresent();
	}
#line 2547 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 101: // d_event_optional: RELATED_EVENT_CHANNEL_NUMBER UINT
#line 522 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumber(yystack_[0].value.as < uint64_t > ());
	}
#line 2556 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 102: // d_event_optional: RELATED_EVENT_CHANNEL_NUMBER_FIXED
#line 525 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumberFixed();
	}
#line 2565 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 103: // d_event_optional: DTO_CTR_DAQ_MODE IDENT
#line 528 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqMode(yystack_[0].value.as < std::string > ());
	}
#line 2574 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 104: // d_event_optional: DTO_CTR_DAQ_MODE_FIXED
#line 531 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqModeFixed();
	}
#line 2583 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 105: // d_event_optional: DTO_CTR_STIM_MODE IDENT
#line 534 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimMode(yystack_[0].value.as < std::string > ());
	}
#line 2592 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 106: // d_event_optional: DTO_CTR_STIM_MODE_FIXED
#line 537 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimModeFixed();
	}
#line 2601 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 107: // d_event_optional: STIM_DTO_CTR_COPY_PRESENT
#line 540 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
                event.SetStimDtoCtrCopyPresent();
	}
#line 2610 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 108: // d_event_optional: daq_packed_mode
#line 543 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		Event& event = scanner.GetEvent();
                event.SetDaqPackedMode(std::move(yystack_[0].value.as < DaqPackedMode > ()));
	}
#line 2619 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 109: // d_event_optional: MIN_CYCLE_TIME UINT UINT
#line 546 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		MinCycleTime cycle;
		cycle.time_cycle = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		cycle.time_unit = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetMinCycleTime(std::move(cycle));
	}
#line 2631 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 110: // d_event_optional: BUFFER_RESERVE_EVENT UINT UINT
#line 552 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
		BufferReserveEvent buffer;
		buffer.odt_daq_buffer_element_reserve = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		buffer.odt_stim_buffer_element_reserve = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetBufferReserveEvent(std::move(buffer));
	}
#line 2643 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 111: // d_event_optional: CPU_LOAD_MAX FLOAT
#line 558 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadMax(yystack_[0].value.as < double > ());
	}
#line 2652 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 112: // d_event_optional: cpu_load_consumption_daq
#line 561 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionDaq(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2661 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 113: // d_event_optional: cpu_load_consumption_stim
#line 564 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2670 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 114: // d_event_optional: cpu_load_consumption_queue
#line 567 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueue(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2679 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 115: // d_event_optional: cpu_load_consumption_queue_stim
#line 570 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueueStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2688 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 116: // daq_packed_mode: BLOCK_BEGIN DAQ_PACKED_MODE IDENT IDENT IDENT UINT alt_sample_count_list BLOCK_END DAQ_PACKED_MODE
#line 577 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          	yylhs.value.as < DaqPackedMode > ().SetGroup(yystack_[6].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetTimestampMode(yystack_[5].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetUsage(yystack_[4].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().sample_count = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
          	yylhs.value.as < DaqPackedMode > ().alt_sample_count = std::move(yystack_[2].value.as < std::vector<uint16_t> > ());
          }
#line 2700 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 117: // alt_sample_count_list: %empty
#line 585 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < std::vector<uint16_t> > () = {};}
#line 2706 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 118: // alt_sample_count_list: alt_sample_count_list alt_sample_count
#line 586 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                {
                       	yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
                       	yylhs.value.as < std::vector<uint16_t> > ().push_back(static_cast<uint16_t>(yystack_[0].value.as < uint16_t > ()));
                       }
#line 2715 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 119: // alt_sample_count: ALT_SAMPLE_COUNT UINT
#line 591 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > ();}
#line 2721 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 120: // cpu_load_consumption_daq: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_DAQ FLOAT FLOAT FLOAT cpu_load_consumption_daq_options BLOCK_END CPU_LOAD_CONSUMPTION_DAQ
#line 595 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
           }
#line 2734 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 123: // cpu_load_consumption_daq_option: odt_entry_size_factor_table
#line 607 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	   }
#line 2743 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 124: // cpu_load_consumption_daq_option: core_load_ep
#line 610 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
 		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
           }
#line 2752 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 125: // cpu_load_consumption_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_STIM FLOAT FLOAT FLOAT cpu_load_consumption_stim_options BLOCK_END CPU_LOAD_CONSUMPTION_STIM
#line 617 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
           }
#line 2765 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 128: // cpu_load_consumption_stim_option: odt_entry_size_factor_table
#line 629 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	  }
#line 2774 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 129: // cpu_load_consumption_stim_option: core_load_ep
#line 632 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2783 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 130: // odt_entry_size_factor_table: BLOCK_BEGIN ODT_ENTRY_SIZE_FACTOR_TABLE UINT FLOAT BLOCK_END ODT_ENTRY_SIZE_FACTOR_TABLE
#line 639 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                   {
         	yylhs.value.as < OdtEntrySizeFactor > ().size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
         	yylhs.value.as < OdtEntrySizeFactor > ().factor = static_cast<float>(yystack_[2].value.as < double > ());
         }
#line 2792 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 131: // cpu_load_consumption_queue: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE FLOAT FLOAT cpu_load_consumption_queue_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 646 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
         }
#line 2804 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 133: // cpu_load_consumption_queue_option: core_load_ep
#line 655 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2813 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 134: // cpu_load_consumption_queue_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE_STIM FLOAT FLOAT cpu_load_consumption_queue_stim_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 662 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
         }
#line 2825 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 136: // cpu_load_consumption_queue_stim_option: core_load_ep
#line 671 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
	}
#line 2834 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 137: // core_load_ep: BLOCK_BEGIN CORE_LOAD_EP UINT FLOAT BLOCK_END CORE_LOAD_EP
#line 678 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
              yylhs.value.as < CoreLoadEp > ().number = yystack_[3].value.as < uint64_t > ();
              yylhs.value.as < CoreLoadEp > ().max = yystack_[2].value.as < double > ();
              }
#line 2843 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 138: // daq_event: BLOCK_BEGIN DAQ_EVENT daq_event_union BLOCK_END DAQ_EVENT
#line 685 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		DaqEvent& event_list = scanner.GetDaqEvent();
       		yylhs.value.as < DaqEvent > () = std::move(event_list);
       		event_list.Reset();
           }
#line 2853 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 141: // fixed_event_list: FIXED_EVENT_LIST event_list
#line 694 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetFixedEventList(yystack_[0].value.as < std::vector<uint16_t> > ());
	}
#line 2862 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 145: // variable_option: BLOCK_BEGIN AVAILABLE_EVENT_LIST event_list BLOCK_END AVAILABLE_EVENT_LIST
#line 705 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetVariableEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2871 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 146: // variable_option: BLOCK_BEGIN DEFAULT_EVENT_LIST event_list BLOCK_END DEFAULT_EVENT_LIST
#line 710 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetDefaultEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2880 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 147: // variable_option: BLOCK_BEGIN CONSISTENCY_EVENT_LIST event_list BLOCK_END CONSISTENCY_EVENT_LIST
#line 715 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetConsistencyEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2889 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 148: // pag: BLOCK_BEGIN PAG UINT freeze_supported BLOCK_END PAG
#line 720 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
     	Pag& pag = scanner.GetPag();
     	pag.SetMaxSegments(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pag > () = std::move(pag);
     	pag.Reset();
     }
#line 2900 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 150: // freeze_supported: FREEZE_SUPPORTED
#line 728 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
     	Pag& pag = scanner.GetPag();
     	pag.SetFreezeSupported();
     }
#line 2909 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 151: // pgm: BLOCK_BEGIN PGM IDENT UINT UINT pgm_options BLOCK_END PGM
#line 735 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	Pgm& pgm = scanner.GetPgm();
     	pgm.SetType(yystack_[5].value.as < std::string > ());
     	pgm.SetMaxSectors(yystack_[4].value.as < uint64_t > ());
     	pgm.SetMaxCtoPgm(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pgm > () = std::move(pgm);
     	pgm.Reset();
     }
#line 2922 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 154: // pgm_option: sector
#line 747 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.AddSector(std::move(yystack_[0].value.as < Sector > ()));
      }
#line 2931 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 155: // pgm_option: communication_mode_supported
#line 750 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.SetCommunicationModeSupported(yystack_[0].value.as < CommunicationMode > ());
      }
#line 2940 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 156: // communication_mode_supported: COMMUNICATION_MODE_SUPPORTED communication_mode_union
#line 755 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = std::move(mode);
             	mode.Reset();
             }
#line 2950 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 157: // communication_mode_supported: BLOCK_BEGIN COMMUNICATION_MODE_SUPPORTED communication_mode_union BLOCK_END COMMUNICATION_MODE_SUPPORTED
#line 761 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = std::move(mode);
             	mode.Reset();
             }
#line 2960 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 160: // communication_mode_union: INTERLEAVED UINT
#line 771 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
        	CommunicationMode& mode = scanner.GetCommunicationMode();
        	mode.SetInterleavedSupported();
        	mode.SetQueueSize(yystack_[0].value.as < uint64_t > ());
            }
#line 2970 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 163: // slave_item: SLAVE
#line 779 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetSlaveModeSupported();
            }
#line 2979 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 165: // master_item: MASTER UINT UINT
#line 784 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetMasterModeSupported();
       		mode.SetMaxBsPgm(yystack_[1].value.as < uint64_t > ());
       		mode.SetMinStPgm(yystack_[0].value.as < uint64_t > ());
            }
#line 2990 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 166: // sector: BLOCK_BEGIN SECTOR STRING UINT UINT UINT UINT UINT UINT BLOCK_END SECTOR
#line 793 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
        	yylhs.value.as < Sector > ().name = std::move(yystack_[8].value.as < std::string > ());
        	yylhs.value.as < Sector > ().number = static_cast<uint8_t>(yystack_[7].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().address = static_cast<uint32_t>(yystack_[6].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().length = static_cast<uint32_t>(yystack_[5].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().clear_sequence_number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_sequence_number = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_method = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
        }
#line 3004 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 167: // segment: BLOCK_BEGIN SEGMENT UINT UINT UINT UINT UINT segment_options BLOCK_END SEGMENT
#line 805 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3019 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 171: // segment_option: DEFAULT_PAGE_NUMBER UINT
#line 820 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
        Segment& segment = scanner.GetSegment();
        segment.SetDefaultPageNumber(yystack_[0].value.as < uint64_t > ());
      }
#line 3028 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 173: // segment_option: address_mapping
#line 824 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Segment& segment = scanner.GetSegment();
      	segment.AddAddressMapping(std::move(yystack_[0].value.as < AddressMapping > ()));
      }
#line 3037 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 174: // checksum: BLOCK_BEGIN CHECKSUM IDENT checksum_options BLOCK_END CHECKSUM
#line 831 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.SetType(yystack_[3].value.as < std::string > ());
      	Segment& segment = scanner.GetSegment();
      	segment.SetChecksum(std::move(checksum));
      	checksum.Reset();
      }
#line 3049 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 177: // checksum_option: MAX_BLOCK_SIZE UINT
#line 842 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.max_block_size = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3058 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 178: // checksum_option: EXTERNAL_FUNCTION STRING
#line 845 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.external_function = std::move(yystack_[0].value.as < std::string > ());
      }
#line 3067 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 179: // checksum_option: MTA_BLOCK_SIZE_ALIGN UINT
#line 848 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.mta_block_size_align =	static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3076 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 180: // page: BLOCK_BEGIN PAGE UINT IDENT IDENT IDENT init_segment BLOCK_END PAGE
#line 855 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3091 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 181: // address_mapping: BLOCK_BEGIN ADDRESS_MAPPING UINT UINT UINT BLOCK_END ADDRESS_MAPPING
#line 868 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	yylhs.value.as < AddressMapping > ().source_address = static_cast<uint32_t>(yystack_[4].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().destination_address = static_cast<uint32_t>(yystack_[3].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().length = static_cast<uint32_t>(yystack_[2].value.as < uint64_t > ());
      }
#line 3101 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 183: // init_segment: INIT_SEGMENT UINT
#line 875 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Page& page = scanner.GetPage();
      	page.SetInitSegment(yystack_[0].value.as < uint64_t > ());
      }
#line 3110 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 184: // time_correlation: BLOCK_BEGIN TIME_CORRELATION IDENT clock_list BLOCK_END TIME_CORRELATION
#line 882 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
 		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
 		correlation.SetTimestampsRelateTo(yystack_[3].value.as < std::string > ());
		yylhs.value.as < TimeCorrelation > () = std::move(correlation);
 		correlation.Reset();
        }
#line 3121 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 187: // clock: BLOCK_BEGIN CLOCK any_int any_int any_int any_int any_int any_int any_int any_int IDENT IDENT IDENT UINT timestamp_characterization UINT IDENT BLOCK_END CLOCK
#line 895 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3146 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 189: // timestamp_characterization: BLOCK_BEGIN TIME_CHARACTERIZATION UINT IDENT IDENT BLOCK_END TIME_CHARACTERIZATION
#line 919 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                 {
                TimestampCharacteristic characteristic;
                characteristic.SetTicks(yystack_[4].value.as < uint64_t > ());
                characteristic.SetResolution(yystack_[3].value.as < std::string > ());
                characteristic.SetSize(yystack_[2].value.as < std::string > ());
       		Clock& clock = scanner.GetClock();
       		clock.SetCharacteristic(std::move(characteristic));
        }
#line 3159 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 190: // event_list: %empty
#line 928 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint16_t> > ().clear(); }
#line 3165 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 191: // event_list: event_list event
#line 929 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
            yylhs.value.as < std::vector<uint16_t> > ().push_back(yystack_[0].value.as < uint16_t > ());
            }
#line 3174 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 192: // event: EVENT UINT
#line 933 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3180 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 193: // xcp_on_can: BLOCK_BEGIN XCP_ON_CAN UINT can_parameter_options transport_layer_instance BLOCK_END XCP_ON_CAN
#line 937 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetVersion(yystack_[4].value.as < uint64_t > ());
		can.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
		scanner.SaveXcpOnCan();
       }
#line 3191 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 196: // can_parameter_option: CAN_ID_BROADCAST UINT
#line 947 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdBroadcast(yystack_[0].value.as < uint64_t > ());
        }
#line 3200 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 197: // can_parameter_option: CAN_ID_MASTER UINT
#line 950 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMaster(yystack_[0].value.as < uint64_t > ());
        }
#line 3209 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 198: // can_parameter_option: CAN_ID_MASTER_INCREMENTAL
#line 953 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMasterIncremental();
        }
#line 3218 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 199: // can_parameter_option: CAN_ID_SLAVE UINT
#line 956 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdSlave(yystack_[0].value.as < uint64_t > ());
        }
#line 3227 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 200: // can_parameter_option: CAN_ID_GET_DAQ_CLOCK_MULTICAST UINT
#line 959 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdGetDaqClockMulticast(yystack_[0].value.as < uint64_t > ());
        }
#line 3236 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 201: // can_parameter_option: BAUDRATE UINT
#line 962 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBaudrate(yystack_[0].value.as < uint64_t > ());
        }
#line 3245 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 202: // can_parameter_option: SAMPLE_POINT UINT
#line 965 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSamplePoint(yystack_[0].value.as < uint64_t > ());
        }
#line 3254 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 203: // can_parameter_option: SAMPLE_RATE IDENT
#line 968 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSampleRate(yystack_[0].value.as < std::string > ());
        }
#line 3263 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 204: // can_parameter_option: BTL_CYCLES UINT
#line 971 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBtlCycles(yystack_[0].value.as < uint64_t > ());
        }
#line 3272 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 205: // can_parameter_option: SJW UINT
#line 974 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSjw(yystack_[0].value.as < uint64_t > ());
        }
#line 3281 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 206: // can_parameter_option: SYNC_EDGE IDENT
#line 977 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSyncEdge(yystack_[0].value.as < std::string > ());
        }
#line 3290 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 207: // can_parameter_option: MAX_DLC_REQUIRED
#line 980 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxDlcRequired();
        }
#line 3299 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 210: // can_parameter_option: MAX_BUS_LOAD UINT
#line 985 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
        }
#line 3308 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 211: // can_parameter_option: MEASUREMENT_SPLIT_ALLOWED
#line 989 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMeasurementSplitAllowed();
        }
#line 3317 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 213: // can_parameter_option: OPTIONAL_TL_SUBCMD IDENT
#line 993 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.AddSubCmd(yystack_[0].value.as < std::string > ());
        }
#line 3326 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 214: // can_parameter_option: common_parameter
#line 996 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		CommonParameters& common_parameters = scanner.GetCommonParameters();
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetOverrulingParameters(common_parameters);
		common_parameters.Reset();
        }
#line 3337 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 215: // daq_list_can_id: BLOCK_BEGIN DAQ_LIST_CAN_ID UINT daq_list_can_id_options BLOCK_END DAQ_LIST_CAN_ID
#line 1005 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddDaqList();
        }
#line 3346 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 218: // daq_list_can_id_option: VARIABLE
#line 1013 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.variable = true;
        }
#line 3356 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 219: // daq_list_can_id_option: fixed
#line 1017 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.fixed = static_cast<uint32_t>(yystack_[0].value.as < uint32_t > ());
        }
#line 3366 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 220: // event_can_id_list: BLOCK_BEGIN EVENT_CAN_ID_LIST UINT fixed_list BLOCK_END EVENT_CAN_ID_LIST
#line 1025 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   EventCanIdList list;
	   list.number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	   list.fixed_list = std::move(yystack_[2].value.as < std::vector<uint32_t> > ());
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddCanIdEventList(list);
        }
#line 3378 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 221: // fixed_list: %empty
#line 1033 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint32_t> > () = {};}
#line 3384 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 222: // fixed_list: fixed_list fixed
#line 1034 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
       	yylhs.value.as < std::vector<uint32_t> > () = std::move(yystack_[1].value.as < std::vector<uint32_t> > ());
       	yylhs.value.as < std::vector<uint32_t> > ().push_back(yystack_[0].value.as < uint32_t > ());
       }
#line 3393 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 223: // fixed: FIXED UINT
#line 1038 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint32_t > () = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ()); }
#line 3399 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 224: // can_fd: BLOCK_BEGIN CAN_FD can_fd_options BLOCK_END CAN_FD
#line 1042 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
      	XcpOnCan& can = scanner.GetXcpOnCan();
      	can.SetCanFd();
     }
#line 3408 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 227: // can_fd_option: MAX_DLC UINT
#line 1050 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc = static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3418 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 228: // can_fd_option: CAN_FD_DATA_TRANSFER_BAUDRATE UINT
#line 1054 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.baudrate = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3428 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 229: // can_fd_option: SAMPLE_POINT UINT
#line 1058 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3438 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 230: // can_fd_option: BTL_CYCLES UINT
#line 1062 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.btl_cycles = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3448 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 231: // can_fd_option: SJW UINT
#line 1066 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sjw = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3458 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 232: // can_fd_option: SYNC_EDGE IDENT
#line 1070 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetSyncEdge(yystack_[0].value.as < std::string > ());
     }
#line 3468 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 233: // can_fd_option: MAX_DLC_REQUIRED
#line 1074 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc_required = true;
     }
#line 3478 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 234: // can_fd_option: SECONDARY_SAMPLE_POINT UINT
#line 1078 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.secondary_sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3488 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 235: // can_fd_option: TRANSCEIVER_DELAY_COMPENSATION IDENT
#line 1082 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetTransceiverDelayCompensation(yystack_[0].value.as < std::string > ());
     }
#line 3498 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 236: // xcp_on_sxi: BLOCK_BEGIN XCP_ON_SxI UINT UINT sxi_parameter_options IDENT IDENT sxi_option transport_layer_instance BLOCK_END XCP_ON_SxI
#line 1090 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetVersion(yystack_[8].value.as < uint64_t > ());
               sxi.SetBaudrate(yystack_[7].value.as < uint64_t > ());
               sxi.SetHeaderLength(yystack_[5].value.as < std::string > ());
               sxi.SetChecksum(yystack_[4].value.as < std::string > ());
               sxi.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnSxi();
            }
#line 3512 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 239: // sxi_parameter_option: ASYNCH_FULL_DUPLEX_MODE IDENT IDENT framing
#line 1103 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               AsynchFullDuplexMode& asynch = sxi.GetAsynch();
               asynch.SetParity(yystack_[2].value.as < std::string > ());
               asynch.SetStopBits(yystack_[1].value.as < std::string > ());
               sxi.SetAsynchFullDuplexMode();
	    }
#line 3524 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 240: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_BYTE
#line 1109 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeByte();
            }
#line 3533 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 241: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_WORD
#line 1112 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeWord();
            }
#line 3542 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 242: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_DWORD
#line 1115 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeDword();
            }
#line 3551 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 243: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_BYTE
#line 1118 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeByte();
            }
#line 3560 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 244: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_WORD
#line 1121 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeWord();
            }
#line 3569 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 245: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_DWORD
#line 1124 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeDword();
            }
#line 3578 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 247: // sxi_option: common_parameter
#line 1130 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
           CommonParameters& common_parameters = scanner.GetCommonParameters();
           XcpOnSxi& sxi = scanner.GetXcpOnSxi();
           sxi.SetOverrulingParameters(common_parameters);
           common_parameters.Reset();
         }
#line 3589 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 249: // framing: BLOCK_BEGIN FRAMING UINT UINT BLOCK_END FRAMING
#line 1140 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
             XcpOnSxi& sxi = scanner.GetXcpOnSxi();
             Framing& framing = sxi.GetFraming();
             framing.sync = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
             sxi.SetFraming();
           }
#line 3600 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 250: // xcp_on_tcp_ip: BLOCK_BEGIN XCP_ON_TCP_IP UINT UINT tcp_ip_options transport_layer_instance BLOCK_END XCP_ON_TCP_IP
#line 1149 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetVersion(yystack_[5].value.as < uint64_t > ());
               tcp.SetPort(yystack_[4].value.as < uint64_t > ());
               tcp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnTcpIp();
            }
#line 3612 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 253: // tcp_ip_option: HOST_NAME STRING
#line 1160 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetHostName(yystack_[0].value.as < std::string > ());
	     }
#line 3621 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 254: // tcp_ip_option: ADDRESS STRING
#line 1163 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetAddress(yystack_[0].value.as < std::string > ());
	     }
#line 3630 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 255: // tcp_ip_option: IPV6 STRING
#line 1166 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetIpv6(yystack_[0].value.as < std::string > ());
	     }
#line 3639 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 256: // tcp_ip_option: MAX_BUS_LOAD UINT
#line 1169 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
	     }
#line 3648 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 257: // tcp_ip_option: MAX_BIT_RATE UINT
#line 1172 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
	     }
#line 3657 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 258: // tcp_ip_option: PACKET_ALIGNMENT IDENT
#line 1175 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
	     }
#line 3666 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 259: // tcp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1178 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.AddTcpSubCmd(yystack_[0].value.as < std::string > ());
	     }
#line 3675 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 260: // tcp_ip_option: common_parameter
#line 1181 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
	     }
#line 3686 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 261: // xcp_on_udp_ip: BLOCK_BEGIN XCP_ON_UDP_IP UINT UINT udp_ip_options transport_layer_instance BLOCK_END XCP_ON_UDP_IP
#line 1190 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetVersion(yystack_[5].value.as < uint64_t > ());
               udp.SetPort(yystack_[4].value.as < uint64_t > ());
               udp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnUdpIp();
             }
#line 3698 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 264: // udp_ip_option: HOST_NAME STRING
#line 1201 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetHostName(yystack_[0].value.as < std::string > ());
	    }
#line 3707 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 265: // udp_ip_option: ADDRESS STRING
#line 1204 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetAddress(yystack_[0].value.as < std::string > ());
            }
#line 3716 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 266: // udp_ip_option: IPV6 STRING
#line 1207 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetIpv6(yystack_[0].value.as < std::string > ());
            }
#line 3725 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 267: // udp_ip_option: MAX_BUS_LOAD UINT
#line 1210 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
            }
#line 3734 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 268: // udp_ip_option: MAX_BIT_RATE UINT
#line 1213 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
            }
#line 3743 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 269: // udp_ip_option: PACKET_ALIGNMENT IDENT
#line 1216 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
            }
#line 3752 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 270: // udp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1219 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.AddUdpSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3761 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 271: // udp_ip_option: common_parameter
#line 1222 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
            }
#line 3772 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 272: // xcp_on_usb: BLOCK_BEGIN XCP_ON_USB UINT UINT UINT UINT IDENT usb_options transport_layer_instance BLOCK_END XCP_ON_USB
#line 1231 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3787 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 275: // usb_option: BLOCK_BEGIN OUT_EP_CMD_STIM ep_parameters BLOCK_END OUT_EP_CMD_STIM
#line 1247 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetOutEpCmdStim();
            }
#line 3796 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 276: // usb_option: BLOCK_BEGIN IN_EP_RESERR_DAQ_EVSERV ep_parameters BLOCK_END IN_EP_RESERR_DAQ_EVSERV
#line 1252 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetInEpReserrDaqEvserv();
            }
#line 3805 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 277: // usb_option: ALTERNATE_SETTING_NO UINT
#line 1255 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetAlternateSettingNo(yystack_[0].value.as < uint64_t > ());
            }
#line 3814 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 278: // usb_option: INTERFACE_STRING_DESCRIPTOR STRING
#line 1258 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetInterfaceStringDescriptor(yystack_[0].value.as < std::string > ());
            }
#line 3823 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 279: // usb_option: BLOCK_BEGIN OUT_EP_ONLY_STIM ep_parameters BLOCK_END OUT_EP_ONLY_STIM
#line 1263 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddOutEpOnlyStim();
            }
#line 3832 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 280: // usb_option: BLOCK_BEGIN IN_EP_ONLY_DAQ ep_parameters BLOCK_END IN_EP_ONLY_DAQ
#line 1268 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddInEpOnlyDaq();
            }
#line 3841 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 281: // usb_option: BLOCK_BEGIN IN_EP_ONLY_EVSERV ep_parameters BLOCK_END IN_EP_ONLY_EVSERV
#line 1273 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddDaqListUsbEndpoint();
            }
#line 3850 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 282: // usb_option: daq_list_usb_endpoint
#line 1276 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
            	XcpOnUsb& usb = scanner.GetXcpOnUsb();
            	usb.AddDaqListUsbEndpoint();
            }
#line 3859 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 283: // usb_option: OPTIONAL_TL_SUBCMD IDENT
#line 1279 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
  		XcpOnUsb& usb = scanner.GetXcpOnUsb();
  		usb.AddUsbSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3868 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 284: // usb_option: common_parameter
#line 1282 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               CommonParameters& common_parameters = scanner.GetCommonParameters();
               XcpOnUsb& usb = scanner.GetXcpOnUsb();
               usb.SetOverrulingParameters(common_parameters);
               common_parameters.Reset();
          }
#line 3879 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 285: // daq_list_usb_endpoint: BLOCK_BEGIN DAQ_LIST_USB_ENDPOINT UINT fixed_in fixed_out BLOCK_END DAQ_LIST_USB_ENDPOINT
#line 1291 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.number = yystack_[4].value.as < uint64_t > ();
          }
#line 3889 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 287: // fixed_in: FIXED_IN UINT
#line 1297 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_in = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3899 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 289: // fixed_out: FIXED_OUT UINT
#line 1303 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_out = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3909 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 290: // ep_parameters: UINT IDENT UINT UINT IDENT IDENT recommended_host_bufsize
#line 1308 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3924 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 292: // recommended_host_bufsize: RECOMMENDED_HOST_BUFSIZE UINT
#line 1319 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {

           }
#line 3932 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 293: // xcp_on_flx: BLOCK_BEGIN XCP_ON_FLX UINT UINT STRING STRING UINT IDENT IDENT flx_options transport_layer_instance BLOCK_END XCP_ON_FLX
#line 1325 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3950 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 296: // flx_option: BLOCK_BEGIN INITIAL_CMD_BUFFER buffer BLOCK_END INITIAL_CMD_BUFFER
#line 1343 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.SetInitialCmdBuffer(buffer);
            buffer.Reset();
       	  }
#line 3961 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 297: // flx_option: BLOCK_BEGIN INITIAL_RES_ERR_BUFFER buffer BLOCK_END INITIAL_RES_ERR_BUFFER
#line 1350 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.SetInitialResErrBuffer(buffer);
            buffer.Reset();
          }
#line 3972 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 298: // flx_option: BLOCK_BEGIN POOL_BUFFER buffer BLOCK_END POOL_BUFFER
#line 1357 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.AddPoolBuffer(buffer);
            buffer.Reset();
          }
#line 3983 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 299: // flx_option: OPTIONAL_TL_SUBCMD IDENT
#line 1362 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            flx.AddFlxSubCmd(yystack_[0].value.as < std::string > ());
          }
#line 3992 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 300: // flx_option: common_parameter
#line 1365 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            CommonParameters& common_parameters = scanner.GetCommonParameters();
            scanner.GetXcpOnFlx().SetOverrulingParameters(common_parameters);
            common_parameters.Reset();
         }
#line 4002 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 301: // buffer: UINT buffer_options
#line 1371 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  buffer.SetBufferNo(yystack_[1].value.as < uint64_t > ());
	}
#line 4012 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 304: // buffer_option: MAX_FLX_LEN_BUF max_flx_len_buf_union
#line 1378 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                     {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetMaxFlxLenBuffer(var_fixed);
	  var_fixed.Reset();
	}
#line 4024 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 307: // max_flx_len_buf_union: FIXED UINT
#line 1387 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4035 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 308: // max_flx_len_buf_union: VARIABLE UINT
#line 1392 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = yystack_[0].value.as < uint64_t > ();
	}
#line 4046 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 316: // flx_slot_id_union: FLX_SLOT_ID lpu_id_union
#line 1408 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetFlxSlotId(var_fixed);
	  var_fixed.Reset();
	}
#line 4058 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 317: // offset_union: OFFSET lpu_id_option
#line 1415 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetOffset(var_fixed);
	  var_fixed.Reset();
	}
#line 4070 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 318: // cycle_repetition: CYCLE_REPETITION lpu_id_union
#line 1422 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetCycleRepetition(var_fixed);
	  var_fixed.Reset();
	}
#line 4082 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 319: // channel: CHANNEL channel_union
#line 1429 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetChannel(var_fixed);
	  var_fixed.Reset();
	}
#line 4094 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 320: // channel_union: FIXED IDENT
#line 1436 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel(yystack_[0].value.as < std::string > ());
	  var_fixed.fixed = static_cast<uint64_t>(
               	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4107 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 321: // channel_union: VARIABLE initial_enum
#line 1443 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = static_cast<uint64_t>(
	  	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4119 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 322: // initial_enum: %empty
#line 1450 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < bool > () = false; }
#line 4125 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 323: // initial_enum: INITIAL_VALUE IDENT
#line 1451 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel(yystack_[0].value.as < std::string > ());
	  yylhs.value.as < bool > () = true;
        }
#line 4137 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 324: // lpu_id_union: FIXED UINT
#line 1459 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4148 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 325: // lpu_id_union: VARIABLE initial_value
#line 1464 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = var_fixed.initial_value.value_or(0);
	}
#line 4159 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 326: // initial_value: %empty
#line 1470 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < bool > () = false;}
#line 4165 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 327: // initial_value: INITIAL_VALUE UINT
#line 1471 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.initial_value = yystack_[0].value.as < uint64_t > ();
	  yylhs.value.as < bool > () = true;
       }
#line 4177 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 331: // xcp_packet_option: CMD IDENT
#line 1486 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetCmd(yystack_[0].value.as < std::string > ());
 	}
#line 4187 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 332: // xcp_packet_option: RES_ERR IDENT
#line 1490 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetResErr(yystack_[0].value.as < std::string > ());
 	}
#line 4197 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 333: // xcp_packet_option: EV_SERV IDENT
#line 1494 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetEvServ(yystack_[0].value.as < std::string > ());
 	}
#line 4207 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 334: // xcp_packet_option: DAQ IDENT
#line 1498 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetDaq(yystack_[0].value.as < std::string > ());
 	}
#line 4217 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 335: // xcp_packet_option: STIM IDENT
#line 1502 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
 	  	FlxBuffer& buffer = flx.GetFlxBuffer();
 	  	buffer.SetStim(yystack_[0].value.as < std::string > ());
 	}
#line 4227 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 336: // xcp_packet_option: MULTICAST IDENT
#line 1506 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
  	  	FlxBuffer& buffer = flx.GetFlxBuffer();
  	  	buffer.SetMulticast(yystack_[0].value.as < std::string > ());
 	}
#line 4237 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 337: // xcp_on_simulink: BLOCK_BEGIN XCP_ON_SIMULINK simulink_options transport_layer_instance BLOCK_END XCP_ON_SIMULINK
#line 1514 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
                   XcpOnSimulink& simulink = scanner.GetXcpOnSimulink();
                   simulink.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
                   scanner.SaveXcpOnSimulink();
                 }
#line 4247 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 340: // simulink_option: MODEL_NAME STRING
#line 1523 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		   scanner.GetXcpOnSimulink().SetModelName(yystack_[0].value.as < std::string > ());
		 }
#line 4255 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 341: // simulink_option: common_parameter
#line 1525 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
                    CommonParameters& common_parameters = scanner.GetCommonParameters();
                    scanner.GetXcpOnSimulink().SetOverrulingParameters(common_parameters);
                 }
#line 4264 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 342: // consistency: DAQ
#line 1530 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::string > () = "DAQ"; }
#line 4270 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 343: // consistency: EVENT
#line 1531 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < std::string > () = "EVENT"; }
#line 4276 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 344: // consistency: ODT
#line 1532 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "ODT"; }
#line 4282 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 345: // consistency: NONE
#line 1533 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::string > () = "NONE"; }
#line 4288 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 346: // daq_list_type: DAQ
#line 1535 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "DAQ"; }
#line 4294 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 347: // daq_list_type: STIM
#line 1536 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < std::string > () = "STIM"; }
#line 4300 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 348: // daq_list_type: DAQ_STIM
#line 1537 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = "DAQ_STIM"; }
#line 4306 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 349: // transport_layer_instance: %empty
#line 1539 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::string > ().clear(); }
#line 4312 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 350: // transport_layer_instance: TRANSPORT_LAYER_INSTANCE STRING
#line 1540 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4318 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 351: // ident_or_string: IDENT
#line 1542 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4324 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 352: // ident_or_string: STRING
#line 1543 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4330 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 353: // any_int: INT
#line 1545 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
             { yylhs.value.as < int64_t > () = yystack_[0].value.as < int64_t > (); }
#line 4336 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 354: // any_int: UINT
#line 1546 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                { yylhs.value.as < int64_t > () = static_cast<int64_t>(yystack_[0].value.as < uint64_t > ()); }
#line 4342 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;


#line 4346 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

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









  const short XcpDataParser::yypact_ninf_ = -676;

  const signed char XcpDataParser::yytable_ninf_ = -1;

  const short
  XcpDataParser::yypact_[] =
  {
      27,   -33,    57,  -117,  -676,  -676,  -101,    86,   116,  -676,
      56,   192,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,   116,
    -676,   -39,   -57,   -28,   -30,   -18,    -3,    -5,    10,    36,
      48,    51,    66,    74,  -676,    89,  -676,  -676,   165,  -676,
    -676,   112,    90,    93,    95,  -676,  -676,    97,   100,   102,
     103,   104,     5,   106,   130,   179,   189,  -676,   240,   107,
     108,   109,    55,    88,  -676,  -676,  -676,   111,    83,   224,
      91,   115,  -676,  -676,   266,   117,   121,  -676,    22,  -676,
    -676,   161,  -676,   125,   134,   288,   160,  -676,   147,    96,
     148,   149,   151,  -676,   152,   154,  -676,   155,  -676,   159,
     168,   169,   172,   174,  -676,  -676,  -676,  -676,  -676,   325,
      -1,     0,     2,   183,   187,  -676,  -676,   181,   190,  -676,
    -676,  -676,  -676,  -676,    33,   193,   195,   -40,  -676,  -676,
    -676,   196,   197,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,   206,   198,  -676,  -676,  -676,  -676,
    -676,  -676,   201,  -676,   194,   202,   204,   200,   211,   208,
     213,  -676,  -676,   364,   210,   215,   220,   227,   228,   226,
     229,  -676,  -676,   367,   230,   231,  -676,   235,    16,    18,
      19,   -20,   282,    41,  -676,  -676,  -676,   241,  -676,  -676,
    -676,   -40,    20,  -676,  -676,  -676,   236,   404,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,   249,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,   250,  -676,   242,   243,   410,   393,   373,
      41,   251,  -676,   283,   420,   258,  -676,   259,    30,   -40,
     417,   261,   262,  -676,   263,   264,   267,   268,   269,   270,
    -676,    -6,     8,   427,  -676,   279,  -676,  -676,    -2,   272,
    -150,  -676,  -676,  -676,   430,   275,  -676,  -676,   355,   283,
    -676,   277,    11,   304,   278,  -676,  -676,  -676,  -676,   -40,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,   400,
     280,  -676,  -676,  -676,   389,  -676,   381,  -676,   443,   284,
     265,   281,   285,  -676,  -676,  -676,   444,  -676,   286,   287,
     431,   291,   292,  -676,   449,   293,   294,   295,   296,  -676,
    -676,   -40,  -676,  -676,  -676,   297,   302,  -676,   298,   300,
     300,   300,   300,   300,  -676,  -676,   305,     4,  -676,   299,
    -676,   306,   307,   465,   308,   309,  -676,   301,   -40,   310,
    -676,   407,   311,   472,   473,   474,   475,   477,  -676,   271,
     313,  -676,  -676,   479,   156,  -676,   319,  -676,  -676,   316,
     321,   128,   318,   -40,   484,   324,   428,   328,   421,   422,
     423,   382,   383,   331,   331,   331,  -676,   336,    25,   466,
     332,   333,   337,  -676,   338,   339,   340,   341,   342,   343,
     344,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,   199,   345,   346,   507,   496,   347,   348,
     349,  -676,   350,   -40,   451,  -676,   353,   516,   356,  -676,
    -676,  -676,  -676,  -676,  -676,   518,   519,   520,  -676,   360,
     361,   362,   -35,   359,   365,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,   498,   368,  -676,   534,
    -676,  -676,  -676,  -676,   460,   366,  -676,  -676,   499,   369,
       7,   462,   459,   419,   372,  -676,   376,  -676,  -676,   -35,
     377,   374,  -676,   540,   177,  -676,   380,   542,   378,  -676,
     379,   -68,   -60,  -676,  -676,  -676,  -676,  -676,  -676,   545,
     327,   385,   386,   551,   384,   424,    34,   433,   392,   390,
     391,   388,  -676,  -676,  -676,  -676,   437,   394,   438,  -676,
    -676,   396,   399,  -676,   543,   445,   531,   -17,  -676,   403,
     405,   406,   408,  -676,   409,   -17,  -676,   469,   425,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,   411,   412,  -676,
      13,   105,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,   413,   414,   415,   568,  -676,
     577,    79,   579,  -676,   504,   -47,   -46,   -46,    17,  -676,
    -676,  -676,  -676,  -676,   426,   416,   418,   429,   432,   434,
     435,  -676,   163,   440,   441,  -676,   446,   442,   452,   535,
    -676,   447,   448,  -676,   439,   515,  -676,   450,   521,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,   486,
     471,  -676,   593,   453,  -676,  -676,   454,  -676,   455,   456,
    -676,   457,  -676,  -676,   458,  -676,   463,  -676,   591,   595,
     464,   461,   467,   596,  -676,  -676,  -676,   468,   562,  -676,
     555,   470,   592,    14,   476,  -676,   276,  -676,   478,   606,
    -676,   506,   480,  -676,   608,   164,   560,   481,   137,   483,
     482,   485,  -676,   487,  -676,  -676,   488,   490,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,   489,   492,  -676,   494,
     610,   493,   495,   497,   500,   491,  -676,   501,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,   502,  -676,   503,
    -676,   505,  -676,   508,   509,   510,   511,   512,  -676,  -676,
     513,   522,   517,   523,   614,   614,   514,  -676,   524,   618,
     618,   598,   620,  -676,   623,  -676,   525,   185,  -676,   -15,
     203,  -676,  -676,  -676,   207,  -676,  -676,  -676,   527,   600,
     602,  -676,   536,   532,  -676,   528,   607,  -676,   609,  -676,
     526,  -676,  -676,    59,   530,  -676,   529,  -676,  -676,   633,
     533,   601,  -676,   537,   639,   625,  -676,  -676,   538,   544,
    -676,   539,  -676,   640,   554,  -676
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
       0,     0,     0,     0,   153,   155,   154,     0,   168,   354,
     353,     0,     0,   216,   221,   193,     0,   246,   254,   253,
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
       0,     0,     0,     0,     0,    42,    62,    61,    45,    54,
      56,    59,    60,    58,    57,    55,     0,     0,    24,     0,
     174,   178,   177,   179,   182,     0,   249,   289,     0,     0,
     301,     0,     0,     0,     0,    80,     0,   351,   352,     0,
       0,     0,    41,     0,     0,   181,     0,     0,     0,   285,
       0,     0,     0,   303,   305,   306,   296,   297,   298,     0,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    31,    28,   183,     0,     0,   291,   310,
     329,     0,     0,   304,     0,     0,     0,     0,    87,     0,
       0,     0,     0,    81,     0,     0,    69,    70,    73,   166,
      33,    23,    30,    26,    27,    29,   180,     0,     0,   290,
       0,     0,   307,   308,    75,    89,    79,   346,   348,   347,
      82,    86,    85,    83,    84,     0,     0,     0,     0,    74,
       0,     0,   188,   292,     0,     0,     0,     0,     0,   311,
     312,   313,   314,   315,     0,     0,     0,     0,     0,     0,
       0,   330,     0,     0,     0,    71,     0,     0,     0,     0,
      34,     0,     0,   309,     0,   322,   319,     0,   326,   318,
     316,   317,   328,   331,   334,   333,   336,   332,   335,     0,
       0,    90,    77,     0,    67,    72,     0,    32,     0,     0,
     320,     0,   321,   324,     0,   325,     0,    88,     0,     0,
       0,     0,     0,     0,   323,   327,    92,     0,     0,    96,
      36,     0,     0,     0,     0,    76,     0,    37,     0,     0,
     187,     0,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,   104,     0,   106,   100,     0,     0,   102,   107,
      97,   108,   112,   113,   114,   115,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,    95,     0,   342,   343,
     345,   344,    99,    98,   111,   103,   105,     0,   101,     0,
     189,     0,    78,     0,     0,     0,     0,     0,   110,   109,
       0,     0,     0,     0,   132,   135,     0,    38,     0,     0,
       0,     0,     0,   133,     0,   136,     0,     0,    94,     0,
       0,   121,   123,   124,     0,   126,   128,   129,     0,     0,
       0,   117,     0,     0,    39,     0,     0,   122,     0,   127,
       0,   131,   134,     0,     0,    35,     0,   120,   125,     0,
       0,     0,   118,     0,     0,     0,   119,   116,     0,     0,
     137,     0,   130,     0,     0,    40
  };

  const short
  XcpDataParser::yypgoto_[] =
  {
    -676,  -676,  -676,   657,  -676,   -62,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,   315,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,   -69,  -676,  -676,   -71,  -675,  -676,  -676,  -676,
    -676,  -659,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,   205,   541,   436,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,    76,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,   546,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
    -676,  -676,  -676,   -87,  -676,  -676,  -676,  -676,  -155,  -676,
    -676,  -676,  -676,  -676,   119,  -676,  -676,  -676,  -676,  -676,
    -676,   118,  -676,  -676,  -676,  -676,  -676,  -676,  -676,  -676,
     158,   -72,   233,  -199
  };

  const short
  XcpDataParser::yydefgoto_[] =
  {
       0,     2,     7,     8,    12,    13,    14,    15,   484,   512,
     513,   571,   600,   658,   737,   754,    16,   364,   406,   407,
     537,   568,   408,   570,   409,   410,   639,   411,   500,   533,
     592,   621,   653,   663,   412,   656,   680,   681,   763,   772,
     682,   740,   741,   683,   744,   745,   742,   684,   732,   685,
     734,   743,    17,    48,    49,    50,    65,    89,    18,    68,
      19,   134,   194,   195,   236,   267,   268,   313,   196,    20,
     238,   275,   276,   371,   421,   277,   278,   487,    21,    72,
      97,   602,    64,    87,    22,    73,   115,   116,   251,   292,
     117,   252,   293,   118,   202,   250,    23,   120,   163,   255,
     297,    24,   121,   172,    25,   122,   182,    26,   258,   304,
     305,   376,   427,   353,   549,    27,   337,   362,   435,   470,
     493,   523,   494,   550,   579,   580,   581,   582,   583,   606,
     632,   609,   635,   495,   551,   591,    28,    62,    83,   702,
     560,    84,   479,   201
  };

  const short
  XcpDataParser::yytable_[] =
  {
      82,   119,   239,   164,   299,   174,   155,   289,   230,   521,
     300,   114,    79,    46,    79,   316,   359,    79,   748,   491,
     519,   294,   604,   607,   308,   557,   574,   661,   309,   227,
     130,   228,   229,   240,   241,   558,   317,   575,   242,     1,
     279,   575,   272,   273,     3,   191,   192,     5,     6,   173,
     183,   131,   233,   234,   576,   746,   439,     4,   576,   171,
     181,   193,   230,   290,   770,   733,   735,    95,    96,   746,
     440,   747,   771,     9,   441,   132,   165,   290,   175,    86,
     321,    86,    86,   301,   274,   747,   577,   166,   442,   176,
     577,   598,   599,   167,   540,   177,   168,    98,   178,    10,
      99,   755,   100,   522,   492,   520,    47,   101,   102,   103,
     104,   105,   243,   140,   244,    80,   605,   608,   584,   302,
     231,   169,   348,   179,   170,   360,   180,   235,    11,   662,
     559,   578,   585,    30,   199,   578,   200,   318,    31,    45,
      32,   417,   141,   477,   478,   254,    51,   586,    52,   373,
     156,   157,   158,   159,   160,   161,    53,   291,   245,    81,
     142,    81,   246,    81,   247,    81,    81,   587,   388,   389,
     248,    54,   443,    55,   423,   619,   620,   162,    66,   698,
     106,   107,   249,   298,    56,   444,   306,    67,   390,   506,
     507,    88,   391,    86,   108,   418,   303,   752,   753,   392,
     699,   691,   692,   693,   694,   193,   188,   189,   190,   109,
      57,   388,   456,   393,   695,   739,   756,   588,   419,   739,
     758,    33,    58,    34,   465,    59,   110,   111,    35,   436,
     437,   390,   112,    90,    31,   391,    32,    36,   113,   420,
      60,   589,   392,   354,   355,   356,   357,   394,    61,    81,
     700,   701,   590,    91,    37,   395,   393,   396,   397,   398,
     399,   400,   124,    63,    69,   363,    31,    70,    32,    71,
     125,    74,   508,   401,    75,   361,    76,    77,    78,   127,
      85,    92,    93,    94,   402,   123,   133,   403,   665,   666,
     394,   128,   667,   404,   126,   129,   509,   510,   395,   135,
     396,   397,   398,   399,   400,   405,   668,    31,   136,    32,
     669,   670,   328,    31,   137,    32,   401,    33,   138,    34,
     511,   139,   143,   144,    35,   145,   146,   402,   147,   148,
     403,   671,   672,    36,   673,   674,   404,   149,   154,   525,
     526,   675,   150,   329,   330,   331,   152,   151,   405,    33,
      37,    34,   153,   186,   383,   384,    35,   184,    38,    39,
      40,    41,    42,    43,    44,    36,   185,   197,   187,   198,
     203,   204,   205,   208,   211,   527,   206,   215,   528,   207,
     223,   209,    37,   210,   676,   212,   213,   332,   333,   216,
      33,   214,    34,   529,   217,   530,    33,    35,    34,   218,
     385,   219,   220,    35,   221,   225,    36,   222,   224,   232,
     677,   678,    36,   226,   253,   237,    79,   256,   261,   257,
     259,   260,   262,    37,   679,   531,   263,   532,   266,    37,
     265,   269,   270,   271,   280,   281,   282,   283,   284,   296,
      81,   285,   286,   310,   312,   319,   322,   287,   288,   311,
     307,   315,   320,   324,   323,   325,   326,   336,   327,   340,
     334,   339,   343,   335,   338,   341,   342,   344,   345,   350,
     347,   349,   351,   346,   352,   358,   368,   365,   375,   372,
     366,   367,   369,   370,   374,   378,   379,   380,   381,   377,
     382,   386,   387,   414,   415,   416,   422,   424,   425,   429,
     426,   430,   428,   431,   432,   434,   433,   438,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   457,
     459,   460,   462,   463,   458,   466,   461,   467,   464,   468,
     469,   471,   472,   473,   474,   475,   476,   480,   485,   481,
     482,   486,   483,   497,   488,   496,   489,   490,   498,   499,
     501,   503,   504,   505,   515,   516,   517,   518,   524,   534,
     535,   536,   538,   546,   539,   541,   542,   545,   543,   544,
     552,   548,   547,   553,   554,   555,   556,   561,   567,   562,
     563,   596,   564,   565,   569,   572,   573,   593,   594,   595,
     597,   601,   603,   624,   613,   627,   614,   631,   626,   612,
     636,   637,   625,   634,   628,   638,   647,   615,   648,   652,
     616,   655,   617,   618,   622,   623,   657,   630,   660,   687,
     688,   690,   629,   696,   633,   712,   731,   640,   641,   642,
     739,   748,   645,   749,   643,   644,   750,   646,   649,   761,
     650,   762,   654,   764,   767,   651,   775,   768,   659,   710,
     664,   777,   779,   784,   689,   697,   686,   703,   780,   704,
     782,   785,   707,   705,   708,   706,    29,   709,   711,   717,
     713,   757,   714,   759,   715,   718,   719,   716,   765,   721,
     413,   720,     0,     0,     0,   722,   723,   724,   725,   514,
     726,   727,   736,   566,   729,   610,   728,   611,   738,   751,
     730,   760,   766,   769,   773,   314,   774,   776,     0,     0,
       0,   778,   502,     0,     0,     0,   781,   783,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295
  };

  const short
  XcpDataParser::yycheck_[] =
  {
      62,    73,   201,     3,     6,     3,     7,    13,    28,    69,
      12,    73,    12,    70,    12,     4,    12,    12,    33,    12,
      88,    13,    69,    69,   174,    42,    13,    13,   178,    13,
       8,    13,    13,    13,    14,    52,    25,    24,    18,    12,
     239,    24,    12,    13,    77,    12,    13,   164,   165,   121,
     122,    29,    11,    12,    41,   730,    31,     0,    41,   121,
     122,    28,    28,    69,     5,   724,   725,    12,    13,   744,
      45,   730,    13,   174,    49,    53,    76,    69,    76,    63,
     279,    63,    63,    85,    54,   744,    73,    87,    63,    87,
      73,    12,    13,    93,    60,    93,    96,     9,    96,    13,
      12,   116,    14,   163,    97,   173,   163,    19,    20,    21,
      22,    23,    92,    17,    94,   110,   163,   163,    13,   121,
     140,   121,   321,   121,   124,   121,   124,    86,    12,   115,
     147,   118,    27,    77,   174,   118,   176,   126,    42,   178,
      44,    13,    46,   178,   179,   207,   174,    42,   178,   348,
     151,   152,   153,   154,   155,   156,   174,   163,   138,   161,
      64,   161,   142,   161,   144,   161,   161,    62,    12,    13,
     150,   174,   147,   178,   373,    12,    13,   178,    13,    42,
      92,    93,   162,   255,   174,   160,   258,    75,    32,    12,
      13,    12,    36,    63,   106,    67,   258,    12,    13,    43,
      63,    37,    38,    39,    40,    28,   130,   131,   132,   121,
     174,    12,    13,    57,    50,    12,    13,   112,    90,    12,
      13,   125,   174,   127,   423,   174,   138,   139,   132,   384,
     385,    32,   144,    44,    42,    36,    44,   141,   150,   111,
     174,   136,    43,   330,   331,   332,   333,    91,   174,   161,
     113,   114,   147,    13,   158,    99,    57,   101,   102,   103,
     104,   105,   179,   174,   174,   337,    42,   174,    44,   174,
     179,   174,    95,   117,   174,   337,   174,   174,   174,    13,
     174,   174,   174,   174,   128,   174,   125,   131,    12,    13,
      91,   174,    16,   137,   179,   174,   119,   120,    99,   174,
     101,   102,   103,   104,   105,   149,    30,    42,   174,    44,
      34,    35,    47,    42,    26,    44,   117,   125,   158,   127,
     143,   174,   174,   174,   132,   174,   174,   128,   174,   174,
     131,    55,    56,   141,    58,    59,   137,   178,    13,    12,
      13,    65,   174,    78,    79,    80,   174,   178,   149,   125,
     158,   127,   178,   172,    83,    84,   132,   174,   166,   167,
     168,   169,   170,   171,   172,   141,   179,   174,   178,   174,
     174,   174,   166,   179,   174,    48,   178,    13,    51,   178,
      13,   179,   158,   179,   108,   174,   178,   122,   123,   179,
     125,   178,   127,    66,   179,    68,   125,   132,   127,   179,
     129,   174,   174,   132,   178,   174,   141,   178,   178,   127,
     134,   135,   141,   178,   178,   174,    12,   168,     8,   169,
     178,   178,    29,   158,   148,    98,    53,   100,   145,   158,
     179,    11,   174,   174,    17,   174,   174,   174,   174,    12,
     161,   174,   174,    13,    89,   141,    46,   178,   178,   174,
     178,   174,   174,    64,   174,    74,    13,    13,   174,    28,
     179,   174,    13,   178,   178,   174,   174,   174,   174,   167,
     174,   174,   174,   178,   174,   170,    11,   178,    71,   178,
     174,   174,   174,   174,   174,    13,    13,    13,    13,   178,
      13,   178,    13,   174,   178,   174,   178,    13,   174,    78,
      72,    79,   174,    80,   122,   174,   123,   171,    42,   177,
     177,   174,   174,   174,   174,   174,   174,   174,   174,   174,
      13,    25,   174,   174,   178,    74,   179,   174,   178,    13,
     174,    13,    13,    13,   174,   174,   174,   178,     4,   174,
      42,    81,   174,    84,   178,    83,    47,   178,   129,   177,
     174,   174,   178,    13,   174,    13,   178,   178,    13,   174,
     174,    10,   178,   126,   140,   132,   174,   179,   178,   178,
     174,   133,   178,   174,    31,   130,    45,   174,   109,   174,
     174,    13,   174,   174,   159,   174,   174,   174,   174,   174,
      13,    12,    88,   147,   178,    60,   178,    82,   146,   173,
     114,   130,   160,    82,   157,    12,    15,   178,    13,    13,
     178,    49,   178,   178,   174,   174,    61,   178,    26,    13,
     114,    13,   174,    63,   174,    15,    12,   174,   174,   174,
      12,    33,   174,    13,   178,   178,    13,   174,   174,    39,
     179,    39,   174,   107,    37,   178,    13,    38,   178,   157,
     174,    50,    13,    13,   174,   174,   178,   174,    33,   177,
     116,   107,   174,   178,   174,   178,     9,   178,   174,   178,
     177,   740,   177,   744,   177,   174,   174,   177,   146,   174,
     365,   178,    -1,    -1,    -1,   177,   177,   177,   177,   484,
     178,   178,   178,   535,   177,   577,   174,   578,   174,   174,
     177,   174,   174,   177,   174,   269,   177,   174,    -1,    -1,
      -1,   174,   479,    -1,    -1,    -1,   178,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252
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
     176,   323,   274,   174,   174,   166,   178,   178,   179,   179,
     179,   174,   174,   178,   178,    13,   179,   179,   179,   174,
     174,   178,   178,    13,   178,   174,   178,    13,    13,    13,
      28,   140,   127,    11,    12,    86,   244,   174,   250,   323,
      13,    14,    18,    92,    94,   138,   142,   144,   150,   162,
     275,   268,   271,   178,   185,   279,   168,   169,   288,   178,
     178,     8,    29,    53,   244,   179,   145,   245,   246,    11,
     174,   174,    12,    13,    54,   251,   252,   255,   256,   323,
      17,   174,   174,   174,   174,   174,   174,   178,   178,    13,
      69,   163,   269,   272,    13,   272,    12,   280,   321,     6,
      12,    85,   121,   185,   289,   290,   321,   178,   174,   178,
      13,   174,    89,   247,   245,   174,     4,    25,   126,   141,
     174,   323,    46,   174,    64,    74,    13,   174,    47,    78,
      79,    80,   122,   123,   179,   178,    13,   296,   178,   174,
      28,   174,   174,    13,   174,   174,   178,   174,   323,   174,
     167,   174,   174,   293,   293,   293,   293,   293,   170,    12,
     121,   185,   297,   321,   197,   178,   174,   174,    11,   174,
     174,   253,   178,   323,   174,    71,   291,   178,    13,    13,
      13,    13,    13,    83,    84,   129,   178,    13,    12,    13,
      32,    36,    43,    57,    91,    99,   101,   102,   103,   104,
     105,   117,   128,   131,   137,   149,   198,   199,   202,   204,
     205,   207,   214,   197,   174,   178,   174,    13,    67,    90,
     111,   254,   178,   323,    13,   174,    72,   292,   174,    78,
      79,    80,   122,   123,   174,   298,   298,   298,   171,    31,
      45,    49,    63,   147,   160,    42,   177,   177,   174,   174,
     174,   174,   174,   174,   174,   174,    13,   174,   178,    13,
      25,   179,   174,   174,   178,   323,    74,   174,    13,   174,
     299,    13,    13,    13,   174,   174,   174,   178,   179,   322,
     178,   174,    42,   174,   188,     4,    81,   257,   178,    47,
     178,    12,    97,   300,   302,   313,    83,    84,   129,   177,
     208,   174,   322,   174,   178,    13,    12,    13,    95,   119,
     120,   143,   189,   190,   243,   174,    13,   178,   178,    88,
     173,    69,   163,   301,    13,    12,    13,    48,    51,    66,
      68,    98,   100,   209,   174,   174,    10,   200,   178,   140,
      60,   132,   174,   178,   178,   179,   126,   178,   133,   294,
     303,   314,   174,   174,    31,   130,    45,    42,    52,   147,
     320,   174,   174,   174,   174,   174,   320,   109,   201,   159,
     203,   191,   174,   174,    13,    24,    41,    73,   118,   304,
     305,   306,   307,   308,    13,    27,    42,    62,   112,   136,
     147,   315,   210,   174,   174,   174,    13,    13,    12,    13,
     192,    12,   261,    88,    69,   163,   309,    69,   163,   311,
     311,   304,   173,   178,   178,   178,   178,   178,   178,    12,
      13,   211,   174,   174,   147,   160,   146,    60,   157,   174,
     178,    82,   310,   174,    82,   312,   114,   130,    12,   206,
     174,   174,   174,   178,   178,   174,   174,    15,    13,   174,
     179,   178,    13,   212,   174,    49,   215,    61,   193,   178,
      26,    13,   115,   213,   174,    12,    13,    16,    30,    34,
      35,    55,    56,    58,    59,    65,   108,   134,   135,   148,
     216,   217,   220,   223,   227,   229,   178,    13,   114,   174,
      13,    37,    38,    39,    40,    50,    63,   174,    42,    63,
     113,   114,   319,   174,   177,   178,   178,   174,   174,   178,
     157,   174,    15,   177,   177,   177,   177,   178,   174,   174,
     178,   174,   177,   177,   177,   177,   178,   178,   174,   177,
     177,    12,   228,   231,   230,   231,   178,   194,   174,    12,
     221,   222,   226,   231,   224,   225,   226,   231,    33,    13,
      13,   174,    12,    13,   195,   116,    13,   222,    13,   225,
     174,    39,    39,   218,   107,   146,   174,    37,    38,   177,
       5,    13,   219,   174,   177,    13,   174,    50,   174,    13,
      33,   178,   116,   178,    13,   107
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
     321,   322,   322,   323,   323
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
       2,     1,     1,     1,     1
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
  "any_int", YY_NULLPTR
  };
#endif


#if XCPDEBUG
  const short
  XcpDataParser::yyrline_[] =
  {
       0,   142,   142,   146,   148,   150,   151,   153,   155,   157,
     160,   163,   166,   169,   172,   175,   180,   181,   182,   183,
     184,   185,   186,   188,   207,   208,   210,   213,   216,   219,
     222,   225,   230,   234,   235,   240,   253,   254,   256,   257,
     261,   270,   286,   303,   304,   306,   309,   312,   315,   318,
     321,   324,   327,   330,   333,   336,   339,   342,   345,   348,
     351,   354,   357,   360,   363,   366,   369,   374,   383,   384,
     386,   387,   389,   400,   401,   403,   410,   422,   423,   432,
     441,   442,   444,   447,   450,   453,   456,   459,   462,   469,
     470,   475,   482,   483,   488,   496,   511,   512,   513,   516,
     519,   522,   525,   528,   531,   534,   537,   540,   543,   546,
     552,   558,   561,   564,   567,   570,   575,   585,   586,   591,
     593,   604,   605,   607,   610,   615,   626,   627,   629,   632,
     637,   644,   654,   655,   660,   670,   671,   676,   683,   691,
     692,   694,   699,   700,   701,   703,   708,   713,   720,   727,
     728,   733,   744,   745,   747,   750,   755,   759,   767,   768,
     771,   777,   778,   779,   783,   784,   791,   803,   816,   817,
     819,   820,   823,   824,   829,   839,   840,   842,   845,   848,
     853,   866,   874,   875,   880,   889,   890,   892,   916,   917,
     928,   929,   933,   935,   944,   945,   947,   950,   953,   956,
     959,   962,   965,   968,   971,   974,   977,   980,   983,   984,
     985,   989,   992,   993,   996,  1003,  1010,  1011,  1013,  1017,
    1023,  1033,  1034,  1038,  1040,  1047,  1048,  1050,  1054,  1058,
    1062,  1066,  1070,  1074,  1078,  1082,  1088,  1100,  1101,  1103,
    1109,  1112,  1115,  1118,  1121,  1124,  1129,  1130,  1137,  1138,
    1147,  1157,  1158,  1160,  1163,  1166,  1169,  1172,  1175,  1178,
    1181,  1188,  1198,  1199,  1201,  1204,  1207,  1210,  1213,  1216,
    1219,  1222,  1229,  1242,  1243,  1245,  1250,  1255,  1258,  1261,
    1266,  1271,  1276,  1279,  1282,  1289,  1296,  1297,  1302,  1303,
    1308,  1318,  1319,  1323,  1339,  1340,  1341,  1348,  1355,  1362,
    1365,  1371,  1376,  1377,  1378,  1385,  1386,  1387,  1392,  1398,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1415,  1422,  1429,
    1436,  1443,  1450,  1451,  1459,  1464,  1470,  1471,  1479,  1483,
    1484,  1486,  1490,  1494,  1498,  1502,  1506,  1512,  1520,  1521,
    1523,  1525,  1530,  1531,  1532,  1533,  1535,  1536,  1537,  1539,
    1540,  1542,  1543,  1545,  1546
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
#line 5324 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

#line 1547 "D:/projects/a2llib/src/xcp/xcpdataparser.y"


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
