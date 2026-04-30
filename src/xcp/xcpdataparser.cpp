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
#line 145 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
       scanner.SetVersion(yystack_[1].value.as < uint64_t > ());
      }
#line 1813 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 7: // definition: common_parameter
#line 152 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  scanner.SaveCommonParameters();
	}
#line 1821 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 9: // common_parameter: protocol_layer
#line 156 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	CommonParameters& common = scanner.GetCommonParameters();
	common.SetProtocolLayer(std::move(yystack_[0].value.as < ProtocolLayer > ()));
    }
#line 1830 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 10: // common_parameter: daq
#line 159 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaq(std::move(yystack_[0].value.as < Daq > ()));
    }
#line 1839 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 11: // common_parameter: daq_event
#line 162 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaqEvent(std::move(yystack_[0].value.as < DaqEvent > ()));
    }
#line 1848 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 12: // common_parameter: pag
#line 165 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPag(std::move(yystack_[0].value.as < Pag > ()));
    }
#line 1857 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 13: // common_parameter: pgm
#line 168 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
            {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPgm(std::move(yystack_[0].value.as < Pgm > ()));
    }
#line 1866 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 14: // common_parameter: segment
#line 171 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetSegment(std::move(yystack_[0].value.as < Segment > ()));
    }
#line 1875 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 15: // common_parameter: time_correlation
#line 174 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	CommonParameters& common = scanner.GetCommonParameters();
        common.SetTimeCorrelation(std::move(yystack_[0].value.as < TimeCorrelation > ()));
    }
#line 1884 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 23: // protocol_layer: BLOCK_BEGIN PROTOCOL_LAYER UINT UINT UINT UINT UINT UINT UINT UINT UINT UINT IDENT IDENT protocol_optional_items BLOCK_END PROTOCOL_LAYER
#line 189 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 1905 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 26: // protocol_optional_item: OPTIONAL_CMD IDENT
#line 209 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommand(yystack_[0].value.as < std::string > ());
        }
#line 1914 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 27: // protocol_optional_item: OPTIONAL_LEVEL1_CMD IDENT
#line 212 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommandLevel1(yystack_[0].value.as < std::string > ());
	}
#line 1923 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 28: // protocol_optional_item: communication_mode_supported
#line 215 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetCommunicationMode(std::move(yystack_[0].value.as < CommunicationMode > ()));
	}
#line 1932 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 29: // protocol_optional_item: SEED_AND_KEY_EXTERNAL_FUNCTION STRING
#line 218 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                  {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetSeedAndKeyFunction(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1941 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 30: // protocol_optional_item: MAX_DTO_STIM UINT
#line 221 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetMaxDtoStim(yystack_[0].value.as < uint64_t > ());
	}
#line 1950 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 31: // protocol_optional_item: ecu_states
#line 224 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetEcuStates(std::move(yystack_[0].value.as < std::vector<EcuState> > ()));
	}
#line 1959 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 32: // ecu_states: BLOCK_BEGIN ECU_STATES state_list BLOCK_END ECU_STATES
#line 231 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::vector<EcuState> > () = std::move(yystack_[2].value.as < std::vector<EcuState> > ()); }
#line 1965 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 33: // state_list: %empty
#line 233 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<EcuState> > ().clear(); }
#line 1971 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 34: // state_list: state_list state_block
#line 234 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
            	yylhs.value.as < std::vector<EcuState> > () = std::move(yystack_[1].value.as < std::vector<EcuState> > ());
            	yylhs.value.as < std::vector<EcuState> > ().emplace_back(std::move(yystack_[0].value.as < EcuState > ()));
            }
#line 1980 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 35: // state_block: BLOCK_BEGIN STATE UINT STRING ecu_switch_to_default IDENT IDENT IDENT IDENT memory_access_list BLOCK_END STATE
#line 241 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 1995 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 36: // ecu_switch_to_default: %empty
#line 252 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < bool > () = false; }
#line 2001 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 37: // ecu_switch_to_default: ECU_SWITCHED_TO_DEFAULT_PAGE
#line 253 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                      { yylhs.value.as < bool > () = true; }
#line 2007 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 38: // memory_access_list: %empty
#line 255 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           { yylhs.value.as < std::vector<MemoryAccess> > ().clear(); }
#line 2013 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 39: // memory_access_list: memory_access_list memory_access
#line 256 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
         		yylhs.value.as < std::vector<MemoryAccess> > () = std::move(yystack_[1].value.as < std::vector<MemoryAccess> > ());
         		yylhs.value.as < std::vector<MemoryAccess> > ().emplace_back(yystack_[0].value.as < MemoryAccess > ());
                    }
#line 2022 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 40: // memory_access: BLOCK_BEGIN MEMORY_ACCESS UINT UINT IDENT IDENT BLOCK_END MEMORY_ACCESS
#line 262 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		yylhs.value.as < MemoryAccess > ().SetSegment(yystack_[5].value.as < uint64_t > ());
		yylhs.value.as < MemoryAccess > ().SetPage(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < MemoryAccess > ().SetReadAccess(yystack_[3].value.as < std::string > ());
		yylhs.value.as < MemoryAccess > ().SetWriteAccess(yystack_[2].value.as < std::string > ());
	}
#line 2033 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 41: // daq: BLOCK_BEGIN DAQ IDENT UINT UINT UINT IDENT IDENT IDENT IDENT UINT IDENT daq_optionals BLOCK_END DAQ
#line 271 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 2053 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 42: // daq: BLOCK_BEGIN DAQ IDENT UINT UINT UINT IDENT IDENT IDENT UINT IDENT daq_optionals BLOCK_END DAQ
#line 287 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 2072 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 45: // daq_optional: DAQ_ALTERNATING_SUPPORTED UINT
#line 305 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqAlternatingSupported(yystack_[0].value.as < uint64_t > ());
      }
#line 2081 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 46: // daq_optional: PRESCALER_SUPPORTED
#line 308 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPrecalerSupported();
      }
#line 2090 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 47: // daq_optional: RESUME_SUPPORTED
#line 311 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
      	Daq& daq = scanner.GetDaq();
      	daq.SetResumeSupported();
      }
#line 2099 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 48: // daq_optional: STORE_DAQ_SUPPORTED
#line 314 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStoreDaqSupported();
      }
#line 2108 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 49: // daq_optional: DTO_CTR_FIELD_SUPPORTED
#line 317 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDtoCtrSupported();
      }
#line 2117 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 50: // daq_optional: OPTIMISATION_TYPE_ODT_STRICT
#line 320 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Daq& daq = scanner.GetDaq();
      	daq.SetOptimisationTypeOdtStrict();
      }
#line 2126 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 51: // daq_optional: stim_struct
#line 323 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStim(yystack_[0].value.as < DaqStim > ());
      }
#line 2135 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 52: // daq_optional: timestamp_supported
#line 326 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
      	Daq& daq = scanner.GetDaq();
      	daq.SetTimestamp(yystack_[0].value.as < Timestamp > ());
      }
#line 2144 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 53: // daq_optional: PID_OFF_SUPPORTED
#line 329 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPidOffSupported();
      }
#line 2153 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 54: // daq_optional: MAX_DAQ_TOTAL UINT
#line 332 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2162 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 55: // daq_optional: MAX_ODT_TOTAL UINT
#line 335 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2171 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 56: // daq_optional: MAX_ODT_DAQ_TOTAL UINT
#line 338 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2180 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 57: // daq_optional: MAX_ODT_STIM_TOTAL UINT
#line 341 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtStimTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2189 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 58: // daq_optional: MAX_ODT_ENTRIES_TOTAL UINT
#line 344 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2198 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 59: // daq_optional: MAX_ODT_ENTRIES_DAQ_TOTAL UINT
#line 347 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesDaqTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2207 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 60: // daq_optional: MAX_ODT_ENTRIES_STIM_TOTAL UINT
#line 350 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesStimTotal(yystack_[0].value.as < uint64_t > ());
      }
#line 2216 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 61: // daq_optional: CPU_LOAD_MAX_TOTAL FLOAT
#line 353 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCpuLoadMaxTotal(yystack_[0].value.as < double > ());
      }
#line 2225 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 62: // daq_optional: CORE_LOAD_MAX_TOTAL FLOAT
#line 356 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCoreLoadMaxTotal(yystack_[0].value.as < double > ());
      }
#line 2234 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 63: // daq_optional: core_load_max
#line 359 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Daq& daq = scanner.GetDaq();
      	daq.AddCoreLoadMax(yystack_[0].value.as < CoreLoadMax > ());
      }
#line 2243 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 64: // daq_optional: daq_memory_consumption
#line 362 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqMemoryConsumption(yystack_[0].value.as < DaqMemoryConsumption > ());
      }
#line 2252 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 65: // daq_optional: daq_list
#line 365 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Daq& daq = scanner.GetDaq();
      	daq.AddDaqList(std::move(yystack_[0].value.as < DaqList > ()));
      }
#line 2261 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 66: // daq_optional: d_event
#line 368 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
      	Daq& daq = scanner.GetDaq();
      	daq.AddEvent(std::move(yystack_[0].value.as < Event > ()));
      }
#line 2270 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 67: // stim_struct: BLOCK_BEGIN STIM IDENT UINT bit_stim min_st_stim BLOCK_END STIM
#line 375 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		yylhs.value.as < DaqStim > ().SetSize(yystack_[5].value.as < std::string > ());
		yylhs.value.as < DaqStim > ().max_odt_entry_size = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < DaqStim > ().bit_stim_supported = yystack_[3].value.as < bool > ();
		yylhs.value.as < DaqStim > ().min_st_stim = yystack_[2].value.as < std::optional<uint8_t> > ();
	  }
#line 2281 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 68: // bit_stim: %empty
#line 382 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < bool > () = false; }
#line 2287 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 69: // bit_stim: BIT_STIM_SUPPORTED
#line 383 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               { yylhs.value.as < bool > () = true; }
#line 2293 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 70: // min_st_stim: %empty
#line 385 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::optional<uint8_t> > ().reset(); }
#line 2299 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 71: // min_st_stim: MIN_ST_STIM UINT
#line 386 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                { yylhs.value.as < std::optional<uint8_t> > () = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ()); }
#line 2305 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 72: // timestamp_supported: BLOCK_BEGIN TIMESTAMP_SUPPORTED UINT IDENT IDENT timestamp_fixed BLOCK_END TIMESTAMP_SUPPORTED
#line 390 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
     		yylhs.value.as < Timestamp > ().SetTicks(yystack_[5].value.as < uint64_t > ());
     		yylhs.value.as < Timestamp > ().SetSize(yystack_[4].value.as < std::string > ());
     		yylhs.value.as < Timestamp > ().SetResolution(yystack_[3].value.as < std::string > ());
     		if (yystack_[2].value.as < bool > ()) {
     		  yylhs.value.as < Timestamp > ().SetFixed();
     		}
          }
#line 2318 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 73: // timestamp_fixed: %empty
#line 399 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        { yylhs.value.as < bool > () = false; }
#line 2324 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 74: // timestamp_fixed: TIMESTAMP_FIXED
#line 400 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {yylhs.value.as < bool > () = true;}
#line 2330 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 75: // core_load_max: BLOCK_BEGIN CORE_LOAD_MAX UINT FLOAT BLOCK_END CORE_LOAD_MAX
#line 404 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
	       	yylhs.value.as < CoreLoadMax > ().number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	       	yylhs.value.as < CoreLoadMax > ().max = static_cast<float>(yystack_[2].value.as < double > ());
	       }
#line 2339 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 76: // daq_memory_consumption: BLOCK_BEGIN DAQ_MEMORY_CONSUMPTION UINT UINT UINT UINT UINT UINT buffer_reserve BLOCK_END DAQ_MEMORY_CONSUMPTION
#line 411 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
              yylhs.value.as < DaqMemoryConsumption > ().limit = static_cast<uint32_t>(yystack_[8].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().daq_size = static_cast<uint16_t>(yystack_[7].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_size = static_cast<uint16_t>(yystack_[6].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_entry_size = static_cast<uint16_t>(yystack_[5].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_daq_buffer_element_size = static_cast<uint16_t>(yystack_[4].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().odt_stim_buffer_element_size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
              yylhs.value.as < DaqMemoryConsumption > ().dto_stim_size = yystack_[2].value.as < std::optional<BufferReserve> > ();
           }
#line 2353 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 77: // buffer_reserve: %empty
#line 421 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::optional<BufferReserve> > ().reset(); }
#line 2359 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 78: // buffer_reserve: BLOCK_BEGIN BUFFER_RESERVE UINT UINT BLOCK_END BUFFER_RESERVE
#line 424 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
	     BufferReserve buffer;
	     buffer.odt_daq_buffer = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
	     buffer.odt_stim_buffer = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
	     yylhs.value.as < std::optional<BufferReserve> > () = buffer;
	   }
#line 2370 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 79: // daq_list: BLOCK_BEGIN DAQ_LIST UINT daq_list_optionals BLOCK_END DAQ_LIST
#line 433 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetNumber(yystack_[3].value.as < uint64_t > ());
	   	yylhs.value.as < DaqList > () = std::move(list);
	   	list.Reset();
          }
#line 2381 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 82: // daq_list_optional: DAQ_LIST_TYPE daq_list_type
#line 443 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetType(yystack_[0].value.as < std::string > ());
           }
#line 2390 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 83: // daq_list_optional: MAX_ODT UINT
#line 446 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdt(yystack_[0].value.as < uint64_t > ());
	   }
#line 2399 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 84: // daq_list_optional: MAX_ODT_ENTRIES UINT
#line 449 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdtEntries(yystack_[0].value.as < uint64_t > ());
	   }
#line 2408 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 85: // daq_list_optional: FIRST_PID UINT
#line 452 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetFirstPid(yystack_[0].value.as < uint64_t > ());
	   }
#line 2417 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 86: // daq_list_optional: EVENT_FIXED UINT
#line 455 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetEventFixed(yystack_[0].value.as < uint64_t > ());
	   }
#line 2426 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 87: // daq_list_optional: DAQ_PACKED_MODE_SUPPORTED
#line 458 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetDaqPackedModeSupported();
	   }
#line 2435 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 88: // daq_list_optional: BLOCK_BEGIN PREDEFINED odt_list BLOCK_END PREDEFINED
#line 463 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetPredefinedList(std::move(yystack_[2].value.as < std::vector<Odt> > ()));
	   }
#line 2444 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 89: // odt_list: %empty
#line 468 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::vector<Odt> > () = {}; }
#line 2450 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 90: // odt_list: odt_list odt
#line 469 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	yylhs.value.as < std::vector<Odt> > () = std::move(yystack_[1].value.as < std::vector<Odt> > ());
     	yylhs.value.as < std::vector<Odt> > ().emplace_back(std::move(yystack_[0].value.as < Odt > ()));
     }
#line 2459 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 91: // odt: BLOCK_BEGIN ODT UINT odt_entry_list BLOCK_END ODT
#line 476 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	yylhs.value.as < Odt > ().number = yystack_[3].value.as < uint64_t > ();
     	yylhs.value.as < Odt > ().odt_entry_list = std::move(yystack_[2].value.as < std::vector<OdtEntry> > ());
     }
#line 2468 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 92: // odt_entry_list: %empty
#line 481 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::vector<OdtEntry> > () = {}; }
#line 2474 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 93: // odt_entry_list: odt_entry_list odt_entry
#line 482 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
         	yylhs.value.as < std::vector<OdtEntry> > () = std::move(yystack_[1].value.as < std::vector<OdtEntry> > ());
         	yylhs.value.as < std::vector<OdtEntry> > ().emplace_back(std::move(yystack_[0].value.as < OdtEntry > ()));
         }
#line 2483 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 94: // odt_entry: ODT_ENTRY UINT UINT UINT UINT UINT
#line 487 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
		yylhs.value.as < OdtEntry > ().number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().address = yystack_[3].value.as < uint64_t > ();
		yylhs.value.as < OdtEntry > ().address_extension = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().size = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		yylhs.value.as < OdtEntry > ().bit_offset = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
	}
#line 2495 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 95: // d_event: BLOCK_BEGIN EVENT ident_or_string ident_or_string UINT daq_list_type UINT UINT UINT UINT d_event_optionals BLOCK_END EVENT
#line 497 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 2513 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 98: // d_event_optional: COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER UINT
#line 512 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
		Event& event = scanner.GetEvent();
                event.SetComplementaryBypassNumber(yystack_[0].value.as < uint64_t > ());
        }
#line 2522 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 99: // d_event_optional: CONSISTENCY consistency
#line 515 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetConsistency(yystack_[0].value.as < std::string > ());
	}
#line 2531 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 100: // d_event_optional: EVENT_COUNTER_PRESENT
#line 518 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
		Event& event = scanner.GetEvent();
                event.SetEventCounterPresent();
	}
#line 2540 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 101: // d_event_optional: RELATED_EVENT_CHANNEL_NUMBER UINT
#line 521 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumber(yystack_[0].value.as < uint64_t > ());
	}
#line 2549 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 102: // d_event_optional: RELATED_EVENT_CHANNEL_NUMBER_FIXED
#line 524 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumberFixed();
	}
#line 2558 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 103: // d_event_optional: DTO_CTR_DAQ_MODE IDENT
#line 527 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqMode(yystack_[0].value.as < std::string > ());
	}
#line 2567 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 104: // d_event_optional: DTO_CTR_DAQ_MODE_FIXED
#line 530 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqModeFixed();
	}
#line 2576 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 105: // d_event_optional: DTO_CTR_STIM_MODE IDENT
#line 533 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimMode(yystack_[0].value.as < std::string > ());
	}
#line 2585 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 106: // d_event_optional: DTO_CTR_STIM_MODE_FIXED
#line 536 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimModeFixed();
	}
#line 2594 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 107: // d_event_optional: STIM_DTO_CTR_COPY_PRESENT
#line 539 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
                event.SetStimDtoCtrCopyPresent();
	}
#line 2603 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 108: // d_event_optional: daq_packed_mode
#line 542 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		Event& event = scanner.GetEvent();
                event.SetDaqPackedMode(std::move(yystack_[0].value.as < DaqPackedMode > ()));
	}
#line 2612 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 109: // d_event_optional: MIN_CYCLE_TIME UINT UINT
#line 545 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		MinCycleTime cycle;
		cycle.time_cycle = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		cycle.time_unit = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetMinCycleTime(std::move(cycle));
	}
#line 2624 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 110: // d_event_optional: BUFFER_RESERVE_EVENT UINT UINT
#line 551 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
		BufferReserveEvent buffer;
		buffer.odt_daq_buffer_element_reserve = static_cast<uint8_t>(yystack_[1].value.as < uint64_t > ());
		buffer.odt_stim_buffer_element_reserve = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
		Event& event = scanner.GetEvent();
                event.SetBufferReserveEvent(std::move(buffer));
	}
#line 2636 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 111: // d_event_optional: CPU_LOAD_MAX FLOAT
#line 557 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadMax(yystack_[0].value.as < double > ());
	}
#line 2645 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 112: // d_event_optional: cpu_load_consumption_daq
#line 560 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionDaq(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2654 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 113: // d_event_optional: cpu_load_consumption_stim
#line 563 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2663 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 114: // d_event_optional: cpu_load_consumption_queue
#line 566 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueue(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2672 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 115: // d_event_optional: cpu_load_consumption_queue_stim
#line 569 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueueStim(std::move(yystack_[0].value.as < CpuLoadConsumption > ()));
	}
#line 2681 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 116: // daq_packed_mode: BLOCK_BEGIN DAQ_PACKED_MODE IDENT IDENT IDENT UINT alt_sample_count_list BLOCK_END DAQ_PACKED_MODE
#line 576 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
          	yylhs.value.as < DaqPackedMode > ().SetGroup(yystack_[6].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetTimestampMode(yystack_[5].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().SetUsage(yystack_[4].value.as < std::string > ());
          	yylhs.value.as < DaqPackedMode > ().sample_count = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
          	yylhs.value.as < DaqPackedMode > ().alt_sample_count = std::move(yystack_[2].value.as < std::vector<uint16_t> > ());
          }
#line 2693 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 117: // alt_sample_count_list: %empty
#line 584 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              { yylhs.value.as < std::vector<uint16_t> > () = {};}
#line 2699 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 118: // alt_sample_count_list: alt_sample_count_list alt_sample_count
#line 585 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                {
                       	yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
                       	yylhs.value.as < std::vector<uint16_t> > ().push_back(static_cast<uint16_t>(yystack_[0].value.as < uint16_t > ()));
                       }
#line 2708 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 119: // alt_sample_count: ALT_SAMPLE_COUNT UINT
#line 590 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > ();}
#line 2714 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 120: // cpu_load_consumption_daq: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_DAQ FLOAT FLOAT FLOAT cpu_load_consumption_daq_options BLOCK_END CPU_LOAD_CONSUMPTION_DAQ
#line 594 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
           }
#line 2727 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 123: // cpu_load_consumption_daq_option: odt_entry_size_factor_table
#line 606 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	   }
#line 2736 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 124: // cpu_load_consumption_daq_option: core_load_ep
#line 609 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
 		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
           }
#line 2745 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 125: // cpu_load_consumption_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_STIM FLOAT FLOAT FLOAT cpu_load_consumption_stim_options BLOCK_END CPU_LOAD_CONSUMPTION_STIM
#line 616 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>(yystack_[5].value.as < double > ());
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_entry_factor = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
           }
#line 2758 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 128: // cpu_load_consumption_stim_option: odt_entry_size_factor_table
#line 628 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                              {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back(yystack_[0].value.as < OdtEntrySizeFactor > ());
	  }
#line 2767 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 129: // cpu_load_consumption_stim_option: core_load_ep
#line 631 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2776 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 130: // odt_entry_size_factor_table: BLOCK_BEGIN ODT_ENTRY_SIZE_FACTOR_TABLE UINT FLOAT BLOCK_END ODT_ENTRY_SIZE_FACTOR_TABLE
#line 638 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                   {
         	yylhs.value.as < OdtEntrySizeFactor > ().size = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
         	yylhs.value.as < OdtEntrySizeFactor > ().factor = static_cast<float>(yystack_[2].value.as < double > ());
         }
#line 2785 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 131: // cpu_load_consumption_queue: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE FLOAT FLOAT cpu_load_consumption_queue_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 645 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
         }
#line 2797 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 133: // cpu_load_consumption_queue_option: core_load_ep
#line 654 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
          }
#line 2806 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 134: // cpu_load_consumption_queue_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE_STIM FLOAT FLOAT cpu_load_consumption_queue_stim_option BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE
#line 661 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                               {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>(yystack_[4].value.as < double > ());
               	cpu_load.odt_element_load = static_cast<float>(yystack_[3].value.as < double > ());
               	yylhs.value.as < CpuLoadConsumption > () = std::move(cpu_load);
               	cpu_load.Reset();
         }
#line 2818 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 136: // cpu_load_consumption_queue_stim_option: core_load_ep
#line 670 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = yystack_[0].value.as < CoreLoadEp > ();
	}
#line 2827 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 137: // core_load_ep: BLOCK_BEGIN CORE_LOAD_EP UINT FLOAT BLOCK_END CORE_LOAD_EP
#line 677 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
              yylhs.value.as < CoreLoadEp > ().number = yystack_[3].value.as < uint64_t > ();
              yylhs.value.as < CoreLoadEp > ().max = yystack_[2].value.as < double > ();
              }
#line 2836 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 138: // daq_event: BLOCK_BEGIN DAQ_EVENT daq_event_union BLOCK_END DAQ_EVENT
#line 684 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		DaqEvent& event_list = scanner.GetDaqEvent();
       		yylhs.value.as < DaqEvent > () = std::move(event_list);
       		event_list.Reset();
           }
#line 2846 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 141: // fixed_event_list: FIXED_EVENT_LIST event_list
#line 693 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetFixedEventList(yystack_[0].value.as < std::vector<uint16_t> > ());
	}
#line 2855 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 145: // variable_option: BLOCK_BEGIN AVAILABLE_EVENT_LIST event_list BLOCK_END AVAILABLE_EVENT_LIST
#line 704 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetVariableEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2864 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 146: // variable_option: BLOCK_BEGIN DEFAULT_EVENT_LIST event_list BLOCK_END DEFAULT_EVENT_LIST
#line 709 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetDefaultEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2873 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 147: // variable_option: BLOCK_BEGIN CONSISTENCY_EVENT_LIST event_list BLOCK_END CONSISTENCY_EVENT_LIST
#line 714 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetConsistencyEventList(yystack_[2].value.as < std::vector<uint16_t> > ());
      }
#line 2882 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 148: // pag: BLOCK_BEGIN PAG UINT freeze_supported BLOCK_END PAG
#line 719 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                         {
     	Pag& pag = scanner.GetPag();
     	pag.SetMaxSegments(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pag > () = std::move(pag);
     	pag.Reset();
     }
#line 2893 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 150: // freeze_supported: FREEZE_SUPPORTED
#line 727 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
     	Pag& pag = scanner.GetPag();
     	pag.SetFreezeSupported();
     }
#line 2902 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 151: // pgm: BLOCK_BEGIN PGM IDENT UINT UINT pgm_options BLOCK_END PGM
#line 734 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
     	Pgm& pgm = scanner.GetPgm();
     	pgm.SetType(yystack_[5].value.as < std::string > ());
     	pgm.SetMaxSectors(yystack_[4].value.as < uint64_t > ());
     	pgm.SetMaxCtoPgm(yystack_[3].value.as < uint64_t > ());
     	yylhs.value.as < Pgm > () = std::move(pgm);
     	pgm.Reset();
     }
#line 2915 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 154: // pgm_option: sector
#line 746 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.AddSector(std::move(yystack_[0].value.as < Sector > ()));
      }
#line 2924 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 155: // pgm_option: communication_mode_supported
#line 749 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.SetCommunicationModeSupported(yystack_[0].value.as < CommunicationMode > ());
      }
#line 2933 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 156: // communication_mode_supported: COMMUNICATION_MODE_SUPPORTED communication_mode_union
#line 754 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = std::move(mode);
             	mode.Reset();
             }
#line 2943 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 157: // communication_mode_supported: BLOCK_BEGIN COMMUNICATION_MODE_SUPPORTED communication_mode_union BLOCK_END COMMUNICATION_MODE_SUPPORTED
#line 760 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                    {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	yylhs.value.as < CommunicationMode > () = std::move(mode);
             	mode.Reset();
             }
#line 2953 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 160: // communication_mode_union: INTERLEAVED UINT
#line 770 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
        	CommunicationMode& mode = scanner.GetCommunicationMode();
        	mode.SetInterleavedSupported();
        	mode.SetQueueSize(yystack_[0].value.as < uint64_t > ());
            }
#line 2963 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 163: // slave_item: SLAVE
#line 778 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetSlaveModeSupported();
            }
#line 2972 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 165: // master_item: MASTER UINT UINT
#line 783 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetMasterModeSupported();
       		mode.SetMaxBsPgm(yystack_[1].value.as < uint64_t > ());
       		mode.SetMinStPgm(yystack_[0].value.as < uint64_t > ());
            }
#line 2983 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 166: // sector: BLOCK_BEGIN SECTOR STRING UINT UINT UINT UINT UINT UINT BLOCK_END SECTOR
#line 792 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
        	yylhs.value.as < Sector > ().name = std::move(yystack_[8].value.as < std::string > ());
        	yylhs.value.as < Sector > ().number = static_cast<uint8_t>(yystack_[7].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().address = static_cast<uint32_t>(yystack_[6].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().length = static_cast<uint32_t>(yystack_[5].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().clear_sequence_number = static_cast<uint8_t>(yystack_[4].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_sequence_number = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
        	yylhs.value.as < Sector > ().program_method = static_cast<uint8_t>(yystack_[2].value.as < uint64_t > ());
        }
#line 2997 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 167: // segment: BLOCK_BEGIN SEGMENT UINT UINT UINT UINT UINT segment_options BLOCK_END SEGMENT
#line 804 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3012 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 171: // segment_option: DEFAULT_PAGE_NUMBER UINT
#line 819 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
        Segment& segment = scanner.GetSegment();
        segment.SetDefaultPageNumber(yystack_[0].value.as < uint64_t > ());
      }
#line 3021 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 173: // segment_option: address_mapping
#line 823 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                        {
      	Segment& segment = scanner.GetSegment();
      	segment.AddAddressMapping(std::move(yystack_[0].value.as < AddressMapping > ()));
      }
#line 3030 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 174: // checksum: BLOCK_BEGIN CHECKSUM IDENT checksum_options BLOCK_END CHECKSUM
#line 830 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.SetType(yystack_[3].value.as < std::string > ());
      	Segment& segment = scanner.GetSegment();
      	segment.SetChecksum(std::move(checksum));
      	checksum.Reset();
      }
#line 3042 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 177: // checksum_option: MAX_BLOCK_SIZE UINT
#line 841 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.max_block_size = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3051 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 178: // checksum_option: EXTERNAL_FUNCTION STRING
#line 844 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.external_function = std::move(yystack_[0].value.as < std::string > ());
      }
#line 3060 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 179: // checksum_option: MTA_BLOCK_SIZE_ALIGN UINT
#line 847 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.mta_block_size_align =	static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
      }
#line 3069 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 180: // page: BLOCK_BEGIN PAGE UINT IDENT IDENT IDENT init_segment BLOCK_END PAGE
#line 854 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3084 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 181: // address_mapping: BLOCK_BEGIN ADDRESS_MAPPING UINT UINT UINT BLOCK_END ADDRESS_MAPPING
#line 867 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
      	yylhs.value.as < AddressMapping > ().source_address = static_cast<uint32_t>(yystack_[4].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().destination_address = static_cast<uint32_t>(yystack_[3].value.as < uint64_t > ());
      	yylhs.value.as < AddressMapping > ().length = static_cast<uint32_t>(yystack_[2].value.as < uint64_t > ());
      }
#line 3094 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 183: // init_segment: INIT_SEGMENT UINT
#line 874 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
      	Page& page = scanner.GetPage();
      	page.SetInitSegment(yystack_[0].value.as < uint64_t > ());
      }
#line 3103 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 184: // time_correlation: BLOCK_BEGIN TIME_CORRELATION IDENT clock_list BLOCK_END TIME_CORRELATION
#line 881 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
 		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
 		correlation.SetTimestampsRelateTo(yystack_[3].value.as < std::string > ());
		yylhs.value.as < TimeCorrelation > () = std::move(correlation);
 		correlation.Reset();
        }
#line 3114 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 187: // clock: BLOCK_BEGIN CLOCK INT INT INT INT INT INT INT INT IDENT IDENT IDENT UINT timestamp_characterization UINT IDENT BLOCK_END CLOCK
#line 894 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3139 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 189: // timestamp_characterization: BLOCK_BEGIN TIME_CHARACTERIZATION UINT IDENT IDENT BLOCK_END TIME_CHARACTERIZATION
#line 918 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                 {
                TimestampCharacteristic characteristic;
                characteristic.SetTicks(yystack_[4].value.as < uint64_t > ());
                characteristic.SetResolution(yystack_[3].value.as < std::string > ());
                characteristic.SetSize(yystack_[2].value.as < std::string > ());
       		Clock& clock = scanner.GetClock();
       		clock.SetCharacteristic(std::move(characteristic));
        }
#line 3152 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 190: // event_list: %empty
#line 927 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint16_t> > ().clear(); }
#line 3158 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 191: // event_list: event_list event
#line 928 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            yylhs.value.as < std::vector<uint16_t> > () = std::move(yystack_[1].value.as < std::vector<uint16_t> > ());
            yylhs.value.as < std::vector<uint16_t> > ().push_back(yystack_[0].value.as < uint16_t > ());
            }
#line 3167 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 192: // event: EVENT UINT
#line 932 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint16_t > () = yystack_[0].value.as < uint64_t > (); }
#line 3173 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 193: // xcp_on_can: BLOCK_BEGIN XCP_ON_CAN UINT can_parameter_options transport_layer_instance BLOCK_END XCP_ON_CAN
#line 936 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetVersion(yystack_[4].value.as < uint64_t > ());
		can.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
		scanner.SaveXcpOnCan();
       }
#line 3184 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 196: // can_parameter_option: CAN_ID_BROADCAST UINT
#line 946 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdBroadcast(yystack_[0].value.as < uint64_t > ());
        }
#line 3193 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 197: // can_parameter_option: CAN_ID_MASTER UINT
#line 949 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMaster(yystack_[0].value.as < uint64_t > ());
        }
#line 3202 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 198: // can_parameter_option: CAN_ID_MASTER_INCREMENTAL
#line 952 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMasterIncremental();
        }
#line 3211 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 199: // can_parameter_option: CAN_ID_SLAVE UINT
#line 955 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdSlave(yystack_[0].value.as < uint64_t > ());
        }
#line 3220 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 200: // can_parameter_option: CAN_ID_GET_DAQ_CLOCK_MULTICAST UINT
#line 958 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdGetDaqClockMulticast(yystack_[0].value.as < uint64_t > ());
        }
#line 3229 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 201: // can_parameter_option: BAUDRATE UINT
#line 961 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBaudrate(yystack_[0].value.as < uint64_t > ());
        }
#line 3238 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 202: // can_parameter_option: SAMPLE_POINT UINT
#line 964 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSamplePoint(yystack_[0].value.as < uint64_t > ());
        }
#line 3247 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 203: // can_parameter_option: SAMPLE_RATE IDENT
#line 967 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSampleRate(yystack_[0].value.as < std::string > ());
        }
#line 3256 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 204: // can_parameter_option: BTL_CYCLES UINT
#line 970 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBtlCycles(yystack_[0].value.as < uint64_t > ());
        }
#line 3265 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 205: // can_parameter_option: SJW UINT
#line 973 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSjw(yystack_[0].value.as < uint64_t > ());
        }
#line 3274 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 206: // can_parameter_option: SYNC_EDGE IDENT
#line 976 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSyncEdge(yystack_[0].value.as < std::string > ());
        }
#line 3283 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 207: // can_parameter_option: MAX_DLC_REQUIRED
#line 979 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxDlcRequired();
        }
#line 3292 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 210: // can_parameter_option: MAX_BUS_LOAD UINT
#line 984 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
        }
#line 3301 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 211: // can_parameter_option: MEASUREMENT_SPLIT_ALLOWED
#line 988 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMeasurementSplitAllowed();
        }
#line 3310 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 213: // can_parameter_option: OPTIONAL_TL_SUBCMD IDENT
#line 992 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.AddSubCmd(yystack_[0].value.as < std::string > ());
        }
#line 3319 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 214: // can_parameter_option: common_parameter
#line 995 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
		CommonParameters& common_parameters = scanner.GetCommonParameters();
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetOverrulingParameters(common_parameters);
		common_parameters.Reset();
        }
#line 3330 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 215: // daq_list_can_id: BLOCK_BEGIN DAQ_LIST_CAN_ID UINT daq_list_can_id_options BLOCK_END DAQ_LIST_CAN_ID
#line 1004 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddDaqList();
        }
#line 3339 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 218: // daq_list_can_id_option: VARIABLE
#line 1012 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.variable = true;
        }
#line 3349 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 219: // daq_list_can_id_option: fixed
#line 1016 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.fixed = static_cast<uint32_t>(yystack_[0].value.as < uint32_t > ());
        }
#line 3359 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 220: // event_can_id_list: BLOCK_BEGIN EVENT_CAN_ID_LIST UINT fixed_list BLOCK_END EVENT_CAN_ID_LIST
#line 1024 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
	   EventCanIdList list;
	   list.number = static_cast<uint16_t>(yystack_[3].value.as < uint64_t > ());
	   list.fixed_list = std::move(yystack_[2].value.as < std::vector<uint32_t> > ());
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddCanIdEventList(list);
        }
#line 3371 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 221: // fixed_list: %empty
#line 1032 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::vector<uint32_t> > () = {};}
#line 3377 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 222: // fixed_list: fixed_list fixed
#line 1033 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
       	yylhs.value.as < std::vector<uint32_t> > () = std::move(yystack_[1].value.as < std::vector<uint32_t> > ());
       	yylhs.value.as < std::vector<uint32_t> > ().push_back(yystack_[0].value.as < uint32_t > ());
       }
#line 3386 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 223: // fixed: FIXED UINT
#line 1037 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  { yylhs.value.as < uint32_t > () = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ()); }
#line 3392 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 224: // can_fd: BLOCK_BEGIN CAN_FD can_fd_options BLOCK_END CAN_FD
#line 1041 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
      	XcpOnCan& can = scanner.GetXcpOnCan();
      	can.SetCanFd();
     }
#line 3401 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 227: // can_fd_option: MAX_DLC UINT
#line 1049 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc = static_cast<uint16_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3411 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 228: // can_fd_option: CAN_FD_DATA_TRANSFER_BAUDRATE UINT
#line 1053 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.baudrate = static_cast<uint32_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3421 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 229: // can_fd_option: SAMPLE_POINT UINT
#line 1057 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3431 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 230: // can_fd_option: BTL_CYCLES UINT
#line 1061 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.btl_cycles = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3441 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 231: // can_fd_option: SJW UINT
#line 1065 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                  {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sjw = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3451 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 232: // can_fd_option: SYNC_EDGE IDENT
#line 1069 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetSyncEdge(yystack_[0].value.as < std::string > ());
     }
#line 3461 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 233: // can_fd_option: MAX_DLC_REQUIRED
#line 1073 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc_required = true;
     }
#line 3471 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 234: // can_fd_option: SECONDARY_SAMPLE_POINT UINT
#line 1077 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                     {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.secondary_sample_point = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
     }
#line 3481 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 235: // can_fd_option: TRANSCEIVER_DELAY_COMPENSATION IDENT
#line 1081 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                              {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetTransceiverDelayCompensation(yystack_[0].value.as < std::string > ());
     }
#line 3491 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 236: // xcp_on_sxi: BLOCK_BEGIN XCP_ON_SxI UINT UINT sxi_parameter_options IDENT IDENT sxi_option transport_layer_instance BLOCK_END XCP_ON_SxI
#line 1089 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetVersion(yystack_[8].value.as < uint64_t > ());
               sxi.SetBaudrate(yystack_[7].value.as < uint64_t > ());
               sxi.SetHeaderLength(yystack_[5].value.as < std::string > ());
               sxi.SetChecksum(yystack_[4].value.as < std::string > ());
               sxi.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnSxi();
            }
#line 3505 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 239: // sxi_parameter_option: ASYNCH_FULL_DUPLEX_MODE IDENT IDENT framing
#line 1102 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                                  {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               AsynchFullDuplexMode& asynch = sxi.GetAsynch();
               asynch.SetParity(yystack_[2].value.as < std::string > ());
               asynch.SetStopBits(yystack_[1].value.as < std::string > ());
               sxi.SetAsynchFullDuplexMode();
	    }
#line 3517 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 240: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_BYTE
#line 1108 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeByte();
            }
#line 3526 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 241: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_WORD
#line 1111 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeWord();
            }
#line 3535 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 242: // sxi_parameter_option: SYNCH_FULL_DUPLEX_MODE_DWORD
#line 1114 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeDword();
            }
#line 3544 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 243: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_BYTE
#line 1117 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeByte();
            }
#line 3553 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 244: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_WORD
#line 1120 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeWord();
            }
#line 3562 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 245: // sxi_parameter_option: SYNCH_FULL_MASTER_MODE_DWORD
#line 1123 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                             {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeDword();
            }
#line 3571 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 247: // sxi_option: common_parameter
#line 1129 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
           CommonParameters& common_parameters = scanner.GetCommonParameters();
           XcpOnSxi& sxi = scanner.GetXcpOnSxi();
           sxi.SetOverrulingParameters(common_parameters);
           common_parameters.Reset();
         }
#line 3582 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 249: // framing: BLOCK_BEGIN FRAMING UINT UINT BLOCK_END FRAMING
#line 1139 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
             XcpOnSxi& sxi = scanner.GetXcpOnSxi();
             Framing& framing = sxi.GetFraming();
             framing.sync = static_cast<uint8_t>(yystack_[3].value.as < uint64_t > ());
             sxi.SetFraming();
           }
#line 3593 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 250: // xcp_on_tcp_ip: BLOCK_BEGIN XCP_ON_TCP_IP UINT UINT tcp_ip_options transport_layer_instance BLOCK_END XCP_ON_TCP_IP
#line 1148 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetVersion(yystack_[5].value.as < uint64_t > ());
               tcp.SetPort(yystack_[4].value.as < uint64_t > ());
               tcp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnTcpIp();
            }
#line 3605 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 253: // tcp_ip_option: HOST_NAME STRING
#line 1159 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetHostName(yystack_[0].value.as < std::string > ());
	     }
#line 3614 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 254: // tcp_ip_option: ADDRESS STRING
#line 1162 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetAddress(yystack_[0].value.as < std::string > ());
	     }
#line 3623 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 255: // tcp_ip_option: IPV6 STRING
#line 1165 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetIpv6(yystack_[0].value.as < std::string > ());
	     }
#line 3632 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 256: // tcp_ip_option: MAX_BUS_LOAD UINT
#line 1168 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
	     }
#line 3641 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 257: // tcp_ip_option: MAX_BIT_RATE UINT
#line 1171 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
	     }
#line 3650 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 258: // tcp_ip_option: PACKET_ALIGNMENT IDENT
#line 1174 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                        {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
	     }
#line 3659 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 259: // tcp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1177 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.AddTcpSubCmd(yystack_[0].value.as < std::string > ());
	     }
#line 3668 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 260: // tcp_ip_option: common_parameter
#line 1180 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
	     }
#line 3679 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 261: // xcp_on_udp_ip: BLOCK_BEGIN XCP_ON_UDP_IP UINT UINT udp_ip_options transport_layer_instance BLOCK_END XCP_ON_UDP_IP
#line 1189 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetVersion(yystack_[5].value.as < uint64_t > ());
               udp.SetPort(yystack_[4].value.as < uint64_t > ());
               udp.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
               scanner.SaveXcpOnUdpIp();
             }
#line 3691 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 264: // udp_ip_option: HOST_NAME STRING
#line 1200 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetHostName(yystack_[0].value.as < std::string > ());
	    }
#line 3700 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 265: // udp_ip_option: ADDRESS STRING
#line 1203 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetAddress(yystack_[0].value.as < std::string > ());
            }
#line 3709 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 266: // udp_ip_option: IPV6 STRING
#line 1206 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetIpv6(yystack_[0].value.as < std::string > ());
            }
#line 3718 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 267: // udp_ip_option: MAX_BUS_LOAD UINT
#line 1209 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBusLoad(yystack_[0].value.as < uint64_t > ());
            }
#line 3727 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 268: // udp_ip_option: MAX_BIT_RATE UINT
#line 1212 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBitRate(yystack_[0].value.as < uint64_t > ());
            }
#line 3736 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 269: // udp_ip_option: PACKET_ALIGNMENT IDENT
#line 1215 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetPacketAlignment(yystack_[0].value.as < std::string > ());
            }
#line 3745 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 270: // udp_ip_option: OPTIONAL_TL_SUBCMD IDENT
#line 1218 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.AddUdpSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3754 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 271: // udp_ip_option: common_parameter
#line 1221 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
            }
#line 3765 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 272: // xcp_on_usb: BLOCK_BEGIN XCP_ON_USB UINT UINT UINT UINT IDENT usb_options transport_layer_instance BLOCK_END XCP_ON_USB
#line 1230 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3780 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 275: // usb_option: BLOCK_BEGIN OUT_EP_CMD_STIM ep_parameters BLOCK_END OUT_EP_CMD_STIM
#line 1246 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetOutEpCmdStim();
            }
#line 3789 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 276: // usb_option: BLOCK_BEGIN IN_EP_RESERR_DAQ_EVSERV ep_parameters BLOCK_END IN_EP_RESERR_DAQ_EVSERV
#line 1251 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetInEpReserrDaqEvserv();
            }
#line 3798 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 277: // usb_option: ALTERNATE_SETTING_NO UINT
#line 1254 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetAlternateSettingNo(yystack_[0].value.as < uint64_t > ());
            }
#line 3807 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 278: // usb_option: INTERFACE_STRING_DESCRIPTOR STRING
#line 1257 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                   {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetInterfaceStringDescriptor(yystack_[0].value.as < std::string > ());
            }
#line 3816 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 279: // usb_option: BLOCK_BEGIN OUT_EP_ONLY_STIM ep_parameters BLOCK_END OUT_EP_ONLY_STIM
#line 1262 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddOutEpOnlyStim();
            }
#line 3825 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 280: // usb_option: BLOCK_BEGIN IN_EP_ONLY_DAQ ep_parameters BLOCK_END IN_EP_ONLY_DAQ
#line 1267 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddInEpOnlyDaq();
            }
#line 3834 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 281: // usb_option: BLOCK_BEGIN IN_EP_ONLY_EVSERV ep_parameters BLOCK_END IN_EP_ONLY_EVSERV
#line 1272 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                          {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddDaqListUsbEndpoint();
            }
#line 3843 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 282: // usb_option: daq_list_usb_endpoint
#line 1275 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
            	XcpOnUsb& usb = scanner.GetXcpOnUsb();
            	usb.AddDaqListUsbEndpoint();
            }
#line 3852 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 283: // usb_option: OPTIONAL_TL_SUBCMD IDENT
#line 1278 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
  		XcpOnUsb& usb = scanner.GetXcpOnUsb();
  		usb.AddUsbSubCmd(yystack_[0].value.as < std::string > ());
            }
#line 3861 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 284: // usb_option: common_parameter
#line 1281 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 {
               CommonParameters& common_parameters = scanner.GetCommonParameters();
               XcpOnUsb& usb = scanner.GetXcpOnUsb();
               usb.SetOverrulingParameters(common_parameters);
               common_parameters.Reset();
          }
#line 3872 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 285: // daq_list_usb_endpoint: BLOCK_BEGIN DAQ_LIST_USB_ENDPOINT UINT fixed_in fixed_out BLOCK_END DAQ_LIST_USB_ENDPOINT
#line 1290 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                       {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.number = yystack_[4].value.as < uint64_t > ();
          }
#line 3882 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 287: // fixed_in: FIXED_IN UINT
#line 1296 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_in = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3892 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 289: // fixed_out: FIXED_OUT UINT
#line 1302 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_out = static_cast<uint8_t>(yystack_[0].value.as < uint64_t > ());
          }
#line 3902 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 290: // ep_parameters: UINT IDENT UINT UINT IDENT IDENT recommended_host_bufsize
#line 1307 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3917 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 292: // recommended_host_bufsize: RECOMMENDED_HOST_BUFSIZE UINT
#line 1318 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {

           }
#line 3925 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 293: // xcp_on_flx: BLOCK_BEGIN XCP_ON_FLX UINT UINT STRING STRING UINT IDENT IDENT flx_options transport_layer_instance BLOCK_END XCP_ON_FLX
#line 1324 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
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
#line 3943 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 296: // flx_option: BLOCK_BEGIN INITIAL_CMD_BUFFER buffer BLOCK_END INITIAL_CMD_BUFFER
#line 1342 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                         {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.SetInitialCmdBuffer(buffer);
            buffer.Reset();
       	  }
#line 3954 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 297: // flx_option: BLOCK_BEGIN INITIAL_RES_ERR_BUFFER buffer BLOCK_END INITIAL_RES_ERR_BUFFER
#line 1349 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                               {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.SetInitialResErrBuffer(buffer);
            buffer.Reset();
          }
#line 3965 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 298: // flx_option: BLOCK_BEGIN POOL_BUFFER buffer BLOCK_END POOL_BUFFER
#line 1356 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                    {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.AddPoolBuffer(buffer);
            buffer.Reset();
          }
#line 3976 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 299: // flx_option: OPTIONAL_TL_SUBCMD IDENT
#line 1361 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                       {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            flx.AddFlxSubCmd(yystack_[0].value.as < std::string > ());
          }
#line 3985 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 300: // flx_option: common_parameter
#line 1364 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
            CommonParameters& common_parameters = scanner.GetCommonParameters();
            scanner.GetXcpOnFlx().SetOverrulingParameters(common_parameters);
            common_parameters.Reset();
         }
#line 3995 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 301: // buffer: UINT buffer_options
#line 1370 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  buffer.SetBufferNo(yystack_[1].value.as < uint64_t > ());
	}
#line 4005 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 304: // buffer_option: MAX_FLX_LEN_BUF max_flx_len_buf_union
#line 1377 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                     {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetMaxFlxLenBuffer(var_fixed);
	  var_fixed.Reset();
	}
#line 4017 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 307: // max_flx_len_buf_union: FIXED UINT
#line 1386 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4028 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 308: // max_flx_len_buf_union: VARIABLE UINT
#line 1391 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = yystack_[0].value.as < uint64_t > ();
	}
#line 4039 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 316: // flx_slot_id_union: FLX_SLOT_ID lpu_id_union
#line 1407 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetFlxSlotId(var_fixed);
	  var_fixed.Reset();
	}
#line 4051 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 317: // offset_union: OFFSET lpu_id_option
#line 1414 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetOffset(var_fixed);
	  var_fixed.Reset();
	}
#line 4063 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 318: // cycle_repetition: CYCLE_REPETITION lpu_id_union
#line 1421 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetCycleRepetition(var_fixed);
	  var_fixed.Reset();
	}
#line 4075 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 319: // channel: CHANNEL channel_union
#line 1428 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                               {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetChannel(var_fixed);
	  var_fixed.Reset();
	}
#line 4087 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 320: // channel_union: FIXED IDENT
#line 1435 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                           {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel(yystack_[0].value.as < std::string > ());
	  var_fixed.fixed = static_cast<uint64_t>(
               	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4100 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 321: // channel_union: VARIABLE initial_enum
#line 1442 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                  {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = static_cast<uint64_t>(
	  	var_fixed.initial_channel.value_or(FlxChannel::A));
	}
#line 4112 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 322: // initial_enum: %empty
#line 1449 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < bool > () = false; }
#line 4118 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 323: // initial_enum: INITIAL_VALUE IDENT
#line 1450 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                              {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel(yystack_[0].value.as < std::string > ());
	  yylhs.value.as < bool > () = true;
        }
#line 4130 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 324: // lpu_id_union: FIXED UINT
#line 1458 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                         {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = yystack_[0].value.as < uint64_t > ();
	}
#line 4141 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 325: // lpu_id_union: VARIABLE initial_value
#line 1463 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = var_fixed.initial_value.value_or(0);
	}
#line 4152 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 326: // initial_value: %empty
#line 1469 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < bool > () = false;}
#line 4158 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 327: // initial_value: INITIAL_VALUE UINT
#line 1470 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.initial_value = yystack_[0].value.as < uint64_t > ();
	  yylhs.value.as < bool > () = true;
       }
#line 4170 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 331: // xcp_packet_option: CMD IDENT
#line 1485 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                             {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetCmd(yystack_[0].value.as < std::string > ());
 	}
#line 4180 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 332: // xcp_packet_option: RES_ERR IDENT
#line 1489 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetResErr(yystack_[0].value.as < std::string > ());
 	}
#line 4190 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 333: // xcp_packet_option: EV_SERV IDENT
#line 1493 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetEvServ(yystack_[0].value.as < std::string > ());
 	}
#line 4200 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 334: // xcp_packet_option: DAQ IDENT
#line 1497 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetDaq(yystack_[0].value.as < std::string > ());
 	}
#line 4210 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 335: // xcp_packet_option: STIM IDENT
#line 1501 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
 	  	FlxBuffer& buffer = flx.GetFlxBuffer();
 	  	buffer.SetStim(yystack_[0].value.as < std::string > ());
 	}
#line 4220 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 336: // xcp_packet_option: MULTICAST IDENT
#line 1505 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                            {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
  	  	FlxBuffer& buffer = flx.GetFlxBuffer();
  	  	buffer.SetMulticast(yystack_[0].value.as < std::string > ());
 	}
#line 4230 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 337: // xcp_on_simulink: BLOCK_BEGIN XCP_ON_SIMULINK simulink_options transport_layer_instance BLOCK_END XCP_ON_SIMULINK
#line 1513 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                           {
                   XcpOnSimulink& simulink = scanner.GetXcpOnSimulink();
                   simulink.SetTransportLayerInstance(yystack_[2].value.as < std::string > ());
                   scanner.SaveXcpOnSimulink();
                 }
#line 4240 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 340: // simulink_option: MODEL_NAME STRING
#line 1522 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                   {
		   scanner.GetXcpOnSimulink().SetModelName(yystack_[0].value.as < std::string > ());
		 }
#line 4248 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 341: // simulink_option: common_parameter
#line 1524 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                      {
                    CommonParameters& common_parameters = scanner.GetCommonParameters();
                    scanner.GetXcpOnSimulink().SetOverrulingParameters(common_parameters);
                 }
#line 4257 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 342: // consistency: DAQ
#line 1529 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                 { yylhs.value.as < std::string > () = "DAQ"; }
#line 4263 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 343: // consistency: EVENT
#line 1530 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                     { yylhs.value.as < std::string > () = "EVENT"; }
#line 4269 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 344: // consistency: ODT
#line 1531 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "ODT"; }
#line 4275 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 345: // consistency: NONE
#line 1532 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                    { yylhs.value.as < std::string > () = "NONE"; }
#line 4281 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 346: // daq_list_type: DAQ
#line 1534 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                   { yylhs.value.as < std::string > () = "DAQ"; }
#line 4287 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 347: // daq_list_type: STIM
#line 1535 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                      { yylhs.value.as < std::string > () = "STIM"; }
#line 4293 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 348: // daq_list_type: DAQ_STIM
#line 1536 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = "DAQ_STIM"; }
#line 4299 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 349: // transport_layer_instance: %empty
#line 1538 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                 { yylhs.value.as < std::string > ().clear(); }
#line 4305 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 350: // transport_layer_instance: TRANSPORT_LAYER_INSTANCE STRING
#line 1539 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                                                            { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4311 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 351: // ident_or_string: IDENT
#line 1541 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                       { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4317 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;

  case 352: // ident_or_string: STRING
#line 1542 "D:/projects/a2llib/src/xcp/xcpdataparser.y"
                          { yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ()); }
#line 4323 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"
    break;


#line 4327 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

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









  const short XcpDataParser::yypact_ninf_ = -671;

  const signed char XcpDataParser::yytable_ninf_ = -1;

  const short
  XcpDataParser::yypact_[] =
  {
      19,    23,    84,  -100,  -671,  -671,   -83,    97,   101,  -671,
      52,   225,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,   101,
    -671,   -38,   -51,   -47,   -36,   -30,   -11,     5,     4,    24,
      31,    55,    57,    60,  -671,    64,  -671,  -671,   159,  -671,
    -671,   172,    74,    85,    86,  -671,  -671,    94,    98,   102,
     103,   104,    -2,   105,   144,   268,   238,  -671,   270,   118,
     119,   120,    62,    14,  -671,  -671,  -671,   122,   125,   247,
     127,   128,  -671,  -671,   295,   135,   136,  -671,    39,  -671,
    -671,   186,  -671,   138,   141,   291,   161,  -671,   147,    72,
     148,   151,   156,  -671,   160,   164,  -671,   165,  -671,   166,
     168,   169,   174,   173,  -671,  -671,  -671,  -671,  -671,   316,
      -5,     0,     1,   179,   167,  -671,  -671,   171,   180,  -671,
    -671,  -671,  -671,  -671,    41,   181,   182,   183,  -671,  -671,
    -671,   187,   193,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,   202,   192,  -671,  -671,  -671,  -671,
    -671,  -671,   195,  -671,   190,   197,   198,   201,   204,   203,
     207,  -671,  -671,   352,   205,   210,   211,   212,   213,   220,
     221,  -671,  -671,   367,   222,   227,  -671,   226,     7,    27,
      35,   -21,   255,    18,  -671,  -671,  -671,   228,  -671,   232,
      38,  -671,  -671,  -671,   234,   391,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,   242,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,   244,  -671,   236,   239,   407,   389,   366,    18,   241,
    -671,   276,   411,   249,  -671,   250,    32,   251,   409,   254,
     256,  -671,   257,   258,   259,   260,   261,   262,  -671,    -8,
      11,   417,  -671,   274,  -671,  -671,    10,   263,  -107,  -671,
    -671,  -671,   423,   264,  -671,  -671,   348,   276,  -671,   269,
       2,   303,   271,  -671,  -671,  -671,  -671,   272,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,   400,   273,  -671,
    -671,  -671,   385,  -671,   376,  -671,   438,   278,   284,   275,
     277,  -671,  -671,  -671,   440,  -671,   279,   282,   430,   285,
     286,  -671,   448,   288,   289,   287,   290,  -671,  -671,   292,
    -671,  -671,  -671,   293,   299,  -671,   296,   297,   297,   297,
     297,   297,  -671,  -671,   302,    -4,  -671,   298,  -671,   300,
     301,   458,   304,   305,  -671,   306,   307,   308,  -671,   402,
     309,   464,   467,   468,   472,   473,  -671,   191,   310,  -671,
    -671,   476,   153,  -671,   317,  -671,  -671,   312,   318,    66,
     315,   319,   481,   322,   425,   324,   421,   422,   420,   380,
     381,   329,   329,   329,  -671,   334,    -6,   465,   331,   332,
     336,  -671,   337,   338,   339,   340,   341,   342,   343,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,   196,   344,   328,   506,   495,   345,   347,   349,  -671,
     350,   346,   451,  -671,   353,   513,   355,  -671,  -671,  -671,
    -671,  -671,  -671,   517,   518,   519,  -671,   359,   360,   361,
     -97,   358,   363,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,   496,   365,  -671,   536,  -671,  -671,
    -671,  -671,   460,   364,  -671,  -671,   497,   368,    29,   462,
     459,   418,   371,  -671,   375,  -671,  -671,   -97,   377,   372,
    -671,   539,    50,  -671,   379,   541,   378,  -671,   382,   -74,
     -60,  -671,  -671,  -671,  -671,  -671,  -671,   542,   237,   383,
     384,   549,   386,   426,    45,   429,   388,   387,   390,   392,
    -671,  -671,  -671,  -671,   437,   394,   434,  -671,  -671,   395,
     396,  -671,   543,   443,   530,   -10,  -671,   403,   404,   405,
     406,  -671,   408,   -10,  -671,   474,   427,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,   410,   413,  -671,    42,   224,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,   414,   415,   416,   563,  -671,   568,   126,
     573,  -671,   503,   -54,   -52,   -52,    61,  -671,  -671,  -671,
    -671,  -671,   419,   424,   428,   431,   432,   433,   435,  -671,
     155,   441,   442,  -671,   446,   436,   449,   534,  -671,   444,
     445,  -671,   439,   515,  -671,   447,   516,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,   485,   470,  -671,
     591,   450,  -671,  -671,   452,  -671,   453,   454,  -671,   455,
    -671,  -671,   456,  -671,   457,  -671,   589,   592,   461,   463,
     466,   594,  -671,  -671,  -671,   469,   559,  -671,   551,   471,
     588,     8,   477,  -671,   206,  -671,   475,   605,  -671,   508,
     478,  -671,   607,   177,   560,   480,   132,   482,   483,   479,
    -671,   484,  -671,  -671,   487,   489,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,   486,   488,  -671,   491,   610,   490,
     492,   493,   494,   498,  -671,   499,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,   500,  -671,   501,  -671,   504,
    -671,   505,   507,   509,   510,   502,  -671,  -671,   511,   514,
     520,   521,   616,   616,   512,  -671,   522,   617,   617,   601,
     623,  -671,   624,  -671,   525,   178,  -671,   -15,   199,  -671,
    -671,  -671,   208,  -671,  -671,  -671,   526,   599,   600,  -671,
     533,   529,  -671,   527,   604,  -671,   608,  -671,   528,  -671,
    -671,    33,   532,  -671,   531,  -671,  -671,   634,   535,   598,
    -671,   537,   637,   622,  -671,  -671,   524,   550,  -671,   538,
    -671,   645,   552,  -671
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
       0,     0,     0,     0,   153,   155,   154,     0,   168,     0,
       0,   216,   221,   193,     0,   246,   254,   253,   255,   256,
     257,   259,   258,     0,   265,   264,   266,   267,   268,   270,
     269,     0,   273,     0,     0,     0,     0,     0,     0,     0,
     151,   162,     0,     0,   156,     0,     0,     0,     0,     0,
       0,   233,     0,     0,     0,     0,     0,     0,   226,     0,
       0,   248,   247,   349,   250,   261,   349,     0,     0,   145,
     147,   146,     0,     0,   163,   158,   164,   162,   160,     0,
       0,     0,     0,   169,   170,   172,   173,     0,   224,   230,
     228,   227,   229,   234,   231,   232,   235,     0,     0,   218,
     217,   219,     0,   222,     0,   239,     0,     0,     0,     0,
       0,   284,   274,   282,     0,   294,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,     0,   167,   171,     0,
     215,   223,   220,     0,     0,   277,     0,     0,     0,     0,
       0,     0,   278,   283,     0,   349,    43,     0,   157,     0,
       0,     0,     0,     0,   175,     0,     0,     0,   236,   286,
       0,     0,     0,     0,     0,     0,   272,     0,     0,   300,
     295,     0,     0,    43,     0,   165,   159,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    50,
      53,    46,    47,    48,    44,    51,    52,    63,    64,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,   176,
       0,     0,     0,   287,     0,     0,     0,   280,   281,   276,
     279,   275,   302,     0,     0,     0,   293,     0,     0,     0,
       0,     0,     0,    42,    62,    61,    45,    54,    56,    59,
      60,    58,    57,    55,     0,     0,    24,     0,   174,   178,
     177,   179,   182,     0,   249,   289,     0,     0,   301,     0,
       0,     0,     0,    80,     0,   351,   352,     0,     0,     0,
      41,     0,     0,   181,     0,     0,     0,   285,     0,     0,
       0,   303,   305,   306,   296,   297,   298,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
      25,    31,    28,   183,     0,     0,   291,   310,   329,     0,
       0,   304,     0,     0,     0,     0,    87,     0,     0,     0,
       0,    81,     0,     0,    69,    70,    73,   166,    33,    23,
      30,    26,    27,    29,   180,     0,     0,   290,     0,     0,
     307,   308,    75,    89,    79,   346,   348,   347,    82,    86,
      85,    83,    84,     0,     0,     0,     0,    74,     0,     0,
     188,   292,     0,     0,     0,     0,     0,   311,   312,   313,
     314,   315,     0,     0,     0,     0,     0,     0,     0,   330,
       0,     0,     0,    71,     0,     0,     0,     0,    34,     0,
       0,   309,     0,   322,   319,     0,   326,   318,   316,   317,
     328,   331,   334,   333,   336,   332,   335,     0,     0,    90,
      77,     0,    67,    72,     0,    32,     0,     0,   320,     0,
     321,   324,     0,   325,     0,    88,     0,     0,     0,     0,
       0,     0,   323,   327,    92,     0,     0,    96,    36,     0,
       0,     0,     0,    76,     0,    37,     0,     0,   187,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,   106,   100,     0,     0,   102,   107,    97,   108,
     112,   113,   114,   115,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,    95,     0,   342,   343,   345,   344,
      99,    98,   111,   103,   105,     0,   101,     0,   189,     0,
      78,     0,     0,     0,     0,     0,   110,   109,     0,     0,
       0,     0,   132,   135,     0,    38,     0,     0,     0,     0,
       0,   133,     0,   136,     0,     0,    94,     0,     0,   121,
     123,   124,     0,   126,   128,   129,     0,     0,     0,   117,
       0,     0,    39,     0,     0,   122,     0,   127,     0,   131,
     134,     0,     0,    35,     0,   120,   125,     0,     0,     0,
     118,     0,     0,     0,   119,   116,     0,     0,   137,     0,
     130,     0,     0,    40
  };

  const short
  XcpDataParser::yypgoto_[] =
  {
    -671,  -671,  -671,   659,  -671,   -62,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,   314,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,   -66,  -671,  -671,   -61,  -670,  -671,  -671,  -671,
    -671,  -536,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,   209,   523,   540,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,    71,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,   544,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
    -671,  -671,  -671,  -105,  -671,  -671,  -671,  -671,  -140,  -671,
    -671,  -671,  -671,  -671,   107,  -671,  -671,  -671,  -671,  -671,
    -671,   110,  -671,  -671,  -671,  -671,  -671,  -671,  -671,  -671,
     162,   -72,   215
  };

  const short
  XcpDataParser::yydefgoto_[] =
  {
       0,     2,     7,     8,    12,    13,    14,    15,   482,   510,
     511,   569,   598,   656,   735,   752,    16,   362,   404,   405,
     535,   566,   406,   568,   407,   408,   637,   409,   498,   531,
     590,   619,   651,   661,   410,   654,   678,   679,   761,   770,
     680,   738,   739,   681,   742,   743,   740,   682,   730,   683,
     732,   741,    17,    48,    49,    50,    65,    89,    18,    68,
      19,   134,   194,   195,   234,   265,   266,   311,   196,    20,
     236,   273,   274,   369,   419,   275,   276,   485,    21,    72,
      97,   600,    64,    87,    22,    73,   115,   116,   249,   290,
     117,   250,   291,   118,   200,   248,    23,   120,   163,   253,
     295,    24,   121,   172,    25,   122,   182,    26,   256,   302,
     303,   374,   425,   351,   547,    27,   335,   360,   433,   468,
     491,   521,   492,   548,   577,   578,   579,   580,   581,   604,
     630,   607,   633,   493,   549,   589,    28,    62,    83,   700,
     558,    84,   477
  };

  const short
  XcpDataParser::yytable_[] =
  {
      82,   119,   155,   164,   174,   287,   314,   228,   357,   519,
      79,   114,    79,    79,   517,   602,   297,   605,   746,    46,
     225,   659,   298,    98,   292,   437,    99,   315,   100,   231,
     232,     1,   555,   101,   102,   103,   104,   105,   768,   438,
     226,   489,   556,   439,   270,   271,   769,   130,   227,   173,
     183,   238,   239,   191,   192,   572,   240,   440,   744,   171,
     181,   288,   504,   505,     5,     6,   573,   306,   131,   193,
      86,   307,   744,   228,    95,    96,   165,   175,   193,   415,
     288,   475,   476,   574,     4,   573,   272,   166,   176,   140,
      86,     9,   132,   167,   177,   299,   168,   178,    86,   518,
       3,   753,   574,   520,   233,   538,   106,   107,    80,   603,
      10,   606,    47,    11,    31,   575,    32,   358,   141,   229,
     108,   169,   179,   660,   170,   180,   490,    51,   316,    30,
     241,   300,   242,   416,   575,   109,   142,   557,   596,   597,
      45,   441,    52,   252,    53,   506,   156,   157,   158,   159,
     160,   161,   110,   111,   442,   289,   417,    81,   112,    81,
     576,    81,    81,    54,   113,   386,   387,   617,   618,   507,
     508,    81,    66,   162,   696,    81,   243,   418,    56,   576,
     244,   296,   245,    55,   304,   388,   731,   733,   246,   389,
     750,   751,   745,   509,   301,   697,   390,    33,    57,    34,
     247,   188,   189,   190,    35,    58,   745,    86,   386,   454,
     391,   737,   754,    36,   689,   690,   691,   692,   663,   664,
     737,   756,   665,   352,   353,   354,   355,   693,   388,    59,
      37,    60,   389,    31,    61,    32,   666,   582,    63,   390,
     667,   668,   434,   435,   392,   698,   699,    67,    69,   523,
     524,   583,   393,   391,   394,   395,   396,   397,   398,    70,
      71,   669,   670,   361,   671,   672,   584,    31,    74,    32,
     399,   673,    75,   359,   381,   382,    76,    77,    78,    85,
      88,   400,    90,    91,   401,   525,   585,   392,   526,    31,
     402,    32,    92,    93,    94,   393,   123,   394,   395,   396,
     397,   398,   403,   527,   124,   528,   125,   126,   127,   128,
     129,   133,   135,   399,   674,   136,    33,   137,    34,   138,
     383,   139,   143,    35,   400,   144,    31,   401,    32,   154,
     145,   326,    36,   402,   146,   529,   586,   530,   147,   148,
     675,   676,   150,   186,   149,   403,   185,   151,   152,    37,
      33,   153,    34,   184,   677,   197,   198,    35,   187,   199,
     587,   201,   327,   328,   329,   213,    36,   202,   203,   206,
     204,   588,    33,   205,    34,   209,   207,   208,   210,    35,
     221,   211,   230,    37,   214,   212,   217,   218,    36,   215,
     216,    38,    39,    40,    41,    42,    43,    44,   219,   220,
     222,   223,   235,    79,   224,    37,   330,   331,   237,    33,
     254,    34,   251,   255,   257,   259,    35,   258,   260,   261,
     263,   264,   267,   268,   269,    36,   278,   277,   279,   294,
     280,   281,   282,   283,   284,    81,   308,   310,   309,   285,
     286,   305,    37,   313,   317,   318,   320,   321,   319,   322,
     323,   324,   325,   334,   332,   333,   337,   336,   338,   339,
     340,   341,   342,   343,   345,   344,   348,   347,   346,   366,
     349,   350,   356,   373,   364,   365,   363,   376,   367,   368,
     377,   378,   372,   371,   370,   379,   380,   375,   384,   385,
     413,   412,   414,   420,   422,   421,   423,   424,   426,   427,
     429,   428,   430,   432,   431,   436,   456,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   455,   457,
     458,   460,   463,   461,   459,   464,   466,   465,   462,   467,
     469,   470,   471,   472,   473,   474,   478,   479,   480,   481,
     483,   484,   486,   495,   487,   494,   488,   496,   497,   499,
     502,   501,   503,   513,   514,   522,   515,   532,   533,   534,
     516,   539,   540,   544,   536,   541,   537,   546,   542,   550,
     551,   543,   545,   553,   552,   554,   594,   559,   560,   561,
     562,   595,   563,   565,   570,   599,   567,   571,   591,   592,
     593,   601,   610,   622,   625,   624,   623,   629,   632,   634,
     635,   626,   611,   636,   645,   646,   612,   650,   653,   613,
     614,   615,   655,   616,   658,   620,   621,   628,   685,   627,
     688,   631,   686,   694,   638,   710,   639,   640,   729,   737,
     643,   644,   641,   642,   746,   647,   747,   748,   759,   760,
     762,   765,   648,   652,   649,   708,   766,   773,   775,   657,
     777,   662,   687,   684,   695,   778,   701,   703,   782,   783,
     702,   705,   704,   706,   707,   709,   780,   711,    29,   712,
     713,   714,   755,   716,   717,   763,   715,   411,   719,   718,
     724,   757,   720,   609,   721,   608,   722,   723,   726,   725,
     734,   512,   500,     0,     0,   564,   736,   727,   728,   749,
     758,   764,   779,     0,     0,   767,   771,     0,   772,   774,
       0,   776,     0,     0,     0,     0,   781,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   312
  };

  const short
  XcpDataParser::yycheck_[] =
  {
      62,    73,     7,     3,     3,    13,     4,    28,    12,    69,
      12,    73,    12,    12,    88,    69,     6,    69,    33,    70,
      13,    13,    12,     9,    13,    31,    12,    25,    14,    11,
      12,    12,    42,    19,    20,    21,    22,    23,     5,    45,
      13,    12,    52,    49,    12,    13,    13,     8,    13,   121,
     122,    13,    14,    12,    13,    13,    18,    63,   728,   121,
     122,    69,    12,    13,   164,   165,    24,   174,    29,    28,
      63,   178,   742,    28,    12,    13,    76,    76,    28,    13,
      69,   178,   179,    41,     0,    24,    54,    87,    87,    17,
      63,   174,    53,    93,    93,    85,    96,    96,    63,   173,
      77,   116,    41,   163,    86,    60,    92,    93,   110,   163,
      13,   163,   163,    12,    42,    73,    44,   121,    46,   140,
     106,   121,   121,   115,   124,   124,    97,   174,   126,    77,
      92,   121,    94,    67,    73,   121,    64,   147,    12,    13,
     178,   147,   178,   205,   174,    95,   151,   152,   153,   154,
     155,   156,   138,   139,   160,   163,    90,   161,   144,   161,
     118,   161,   161,   174,   150,    12,    13,    12,    13,   119,
     120,   161,    13,   178,    42,   161,   138,   111,   174,   118,
     142,   253,   144,   178,   256,    32,   722,   723,   150,    36,
      12,    13,   728,   143,   256,    63,    43,   125,   174,   127,
     162,   130,   131,   132,   132,   174,   742,    63,    12,    13,
      57,    12,    13,   141,    37,    38,    39,    40,    12,    13,
      12,    13,    16,   328,   329,   330,   331,    50,    32,   174,
     158,   174,    36,    42,   174,    44,    30,    13,   174,    43,
      34,    35,   382,   383,    91,   113,   114,    75,   174,    12,
      13,    27,    99,    57,   101,   102,   103,   104,   105,   174,
     174,    55,    56,   335,    58,    59,    42,    42,   174,    44,
     117,    65,   174,   335,    83,    84,   174,   174,   174,   174,
      12,   128,    44,    13,   131,    48,    62,    91,    51,    42,
     137,    44,   174,   174,   174,    99,   174,   101,   102,   103,
     104,   105,   149,    66,   179,    68,   179,   179,    13,   174,
     174,   125,   174,   117,   108,   174,   125,    26,   127,   158,
     129,   174,   174,   132,   128,   174,    42,   131,    44,    13,
     174,    47,   141,   137,   174,    98,   112,   100,   174,   174,
     134,   135,   174,   172,   178,   149,   179,   178,   174,   158,
     125,   178,   127,   174,   148,   174,   174,   132,   178,   176,
     136,   174,    78,    79,    80,    13,   141,   174,   166,   179,
     178,   147,   125,   178,   127,   174,   179,   179,   174,   132,
      13,   178,   127,   158,   179,   178,   174,   174,   141,   179,
     179,   166,   167,   168,   169,   170,   171,   172,   178,   178,
     178,   174,   174,    12,   178,   158,   122,   123,   176,   125,
     168,   127,   178,   169,   178,     8,   132,   178,    29,    53,
     179,   145,    11,   174,   174,   141,    17,   176,   174,    12,
     174,   174,   174,   174,   174,   161,    13,    89,   174,   178,
     178,   178,   158,   174,   141,   174,    46,   174,   176,    64,
      74,    13,   174,    13,   179,   178,   174,   178,    28,   174,
     174,    13,   174,   174,   174,   178,   167,   174,   176,    11,
     174,   174,   170,    71,   174,   174,   178,    13,   174,   174,
      13,    13,   174,   176,   178,    13,    13,   178,   178,    13,
     178,   174,   174,   178,    13,   176,   174,    72,   174,    78,
      80,    79,   122,   174,   123,   171,   178,    42,   177,   177,
     174,   174,   174,   174,   174,   174,   174,   174,   174,    13,
      25,   174,   176,   174,   179,    74,    13,   174,   178,   174,
      13,    13,    13,   174,   174,   174,   178,   174,    42,   174,
       4,    81,   178,    84,    47,    83,   178,   129,   177,   174,
     178,   174,    13,   174,    13,    13,   178,   174,   174,    10,
     178,   132,   174,   126,   178,   178,   140,   133,   178,   174,
     174,   179,   178,   130,    31,    45,    13,   174,   174,   174,
     174,    13,   174,   109,   174,    12,   159,   174,   174,   174,
     174,    88,   173,   147,    60,   146,   160,    82,    82,   114,
     130,   157,   178,    12,    15,    13,   178,    13,    49,   178,
     178,   178,    61,   178,    26,   174,   174,   178,    13,   174,
      13,   174,   114,    63,   174,    15,   174,   174,    12,    12,
     174,   174,   178,   178,    33,   174,    13,    13,    39,    39,
     107,    37,   179,   174,   178,   157,    38,    13,    50,   178,
      13,   174,   174,   178,   174,    33,   174,   178,    13,   107,
     177,   174,   178,   174,   178,   174,   116,   177,     9,   177,
     177,   177,   738,   174,   174,   146,   178,   363,   174,   178,
     178,   742,   177,   576,   177,   575,   177,   177,   174,   178,
     178,   482,   477,    -1,    -1,   533,   174,   177,   177,   174,
     174,   174,   178,    -1,    -1,   177,   174,    -1,   177,   174,
      -1,   174,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   267
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
     262,    12,    13,    28,   242,   243,   248,   174,   174,   176,
     274,   174,   174,   166,   178,   178,   179,   179,   179,   174,
     174,   178,   178,    13,   179,   179,   179,   174,   174,   178,
     178,    13,   178,   174,   178,    13,    13,    13,    28,   140,
     127,    11,    12,    86,   244,   174,   250,   176,    13,    14,
      18,    92,    94,   138,   142,   144,   150,   162,   275,   268,
     271,   178,   185,   279,   168,   169,   288,   178,   178,     8,
      29,    53,   244,   179,   145,   245,   246,    11,   174,   174,
      12,    13,    54,   251,   252,   255,   256,   176,    17,   174,
     174,   174,   174,   174,   174,   178,   178,    13,    69,   163,
     269,   272,    13,   272,    12,   280,   321,     6,    12,    85,
     121,   185,   289,   290,   321,   178,   174,   178,    13,   174,
      89,   247,   245,   174,     4,    25,   126,   141,   174,   176,
      46,   174,    64,    74,    13,   174,    47,    78,    79,    80,
     122,   123,   179,   178,    13,   296,   178,   174,    28,   174,
     174,    13,   174,   174,   178,   174,   176,   174,   167,   174,
     174,   293,   293,   293,   293,   293,   170,    12,   121,   185,
     297,   321,   197,   178,   174,   174,    11,   174,   174,   253,
     178,   176,   174,    71,   291,   178,    13,    13,    13,    13,
      13,    83,    84,   129,   178,    13,    12,    13,    32,    36,
      43,    57,    91,    99,   101,   102,   103,   104,   105,   117,
     128,   131,   137,   149,   198,   199,   202,   204,   205,   207,
     214,   197,   174,   178,   174,    13,    67,    90,   111,   254,
     178,   176,    13,   174,    72,   292,   174,    78,    79,    80,
     122,   123,   174,   298,   298,   298,   171,    31,    45,    49,
      63,   147,   160,    42,   177,   177,   174,   174,   174,   174,
     174,   174,   174,   174,    13,   174,   178,    13,    25,   179,
     174,   174,   178,   176,    74,   174,    13,   174,   299,    13,
      13,    13,   174,   174,   174,   178,   179,   322,   178,   174,
      42,   174,   188,     4,    81,   257,   178,    47,   178,    12,
      97,   300,   302,   313,    83,    84,   129,   177,   208,   174,
     322,   174,   178,    13,    12,    13,    95,   119,   120,   143,
     189,   190,   243,   174,    13,   178,   178,    88,   173,    69,
     163,   301,    13,    12,    13,    48,    51,    66,    68,    98,
     100,   209,   174,   174,    10,   200,   178,   140,    60,   132,
     174,   178,   178,   179,   126,   178,   133,   294,   303,   314,
     174,   174,    31,   130,    45,    42,    52,   147,   320,   174,
     174,   174,   174,   174,   320,   109,   201,   159,   203,   191,
     174,   174,    13,    24,    41,    73,   118,   304,   305,   306,
     307,   308,    13,    27,    42,    62,   112,   136,   147,   315,
     210,   174,   174,   174,    13,    13,    12,    13,   192,    12,
     261,    88,    69,   163,   309,    69,   163,   311,   311,   304,
     173,   178,   178,   178,   178,   178,   178,    12,    13,   211,
     174,   174,   147,   160,   146,    60,   157,   174,   178,    82,
     310,   174,    82,   312,   114,   130,    12,   206,   174,   174,
     174,   178,   178,   174,   174,    15,    13,   174,   179,   178,
      13,   212,   174,    49,   215,    61,   193,   178,    26,    13,
     115,   213,   174,    12,    13,    16,    30,    34,    35,    55,
      56,    58,    59,    65,   108,   134,   135,   148,   216,   217,
     220,   223,   227,   229,   178,    13,   114,   174,    13,    37,
      38,    39,    40,    50,    63,   174,    42,    63,   113,   114,
     319,   174,   177,   178,   178,   174,   174,   178,   157,   174,
      15,   177,   177,   177,   177,   178,   174,   174,   178,   174,
     177,   177,   177,   177,   178,   178,   174,   177,   177,    12,
     228,   231,   230,   231,   178,   194,   174,    12,   221,   222,
     226,   231,   224,   225,   226,   231,    33,    13,    13,   174,
      12,    13,   195,   116,    13,   222,    13,   225,   174,    39,
      39,   218,   107,   146,   174,    37,    38,   177,     5,    13,
     219,   174,   177,    13,   174,    50,   174,    13,    33,   178,
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
     321,   322,   322
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
       2,     1,     1
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
  "daq_list_type", "transport_layer_instance", "ident_or_string", YY_NULLPTR
  };
#endif


#if XCPDEBUG
  const short
  XcpDataParser::yyrline_[] =
  {
       0,   141,   141,   145,   147,   149,   150,   152,   154,   156,
     159,   162,   165,   168,   171,   174,   179,   180,   181,   182,
     183,   184,   185,   187,   206,   207,   209,   212,   215,   218,
     221,   224,   229,   233,   234,   239,   252,   253,   255,   256,
     260,   269,   285,   302,   303,   305,   308,   311,   314,   317,
     320,   323,   326,   329,   332,   335,   338,   341,   344,   347,
     350,   353,   356,   359,   362,   365,   368,   373,   382,   383,
     385,   386,   388,   399,   400,   402,   409,   421,   422,   431,
     440,   441,   443,   446,   449,   452,   455,   458,   461,   468,
     469,   474,   481,   482,   487,   495,   510,   511,   512,   515,
     518,   521,   524,   527,   530,   533,   536,   539,   542,   545,
     551,   557,   560,   563,   566,   569,   574,   584,   585,   590,
     592,   603,   604,   606,   609,   614,   625,   626,   628,   631,
     636,   643,   653,   654,   659,   669,   670,   675,   682,   690,
     691,   693,   698,   699,   700,   702,   707,   712,   719,   726,
     727,   732,   743,   744,   746,   749,   754,   758,   766,   767,
     770,   776,   777,   778,   782,   783,   790,   802,   815,   816,
     818,   819,   822,   823,   828,   838,   839,   841,   844,   847,
     852,   865,   873,   874,   879,   888,   889,   891,   915,   916,
     927,   928,   932,   934,   943,   944,   946,   949,   952,   955,
     958,   961,   964,   967,   970,   973,   976,   979,   982,   983,
     984,   988,   991,   992,   995,  1002,  1009,  1010,  1012,  1016,
    1022,  1032,  1033,  1037,  1039,  1046,  1047,  1049,  1053,  1057,
    1061,  1065,  1069,  1073,  1077,  1081,  1087,  1099,  1100,  1102,
    1108,  1111,  1114,  1117,  1120,  1123,  1128,  1129,  1136,  1137,
    1146,  1156,  1157,  1159,  1162,  1165,  1168,  1171,  1174,  1177,
    1180,  1187,  1197,  1198,  1200,  1203,  1206,  1209,  1212,  1215,
    1218,  1221,  1228,  1241,  1242,  1244,  1249,  1254,  1257,  1260,
    1265,  1270,  1275,  1278,  1281,  1288,  1295,  1296,  1301,  1302,
    1307,  1317,  1318,  1322,  1338,  1339,  1340,  1347,  1354,  1361,
    1364,  1370,  1375,  1376,  1377,  1384,  1385,  1386,  1391,  1397,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1414,  1421,  1428,
    1435,  1442,  1449,  1450,  1458,  1463,  1469,  1470,  1478,  1482,
    1483,  1485,  1489,  1493,  1497,  1501,  1505,  1511,  1519,  1520,
    1522,  1524,  1529,  1530,  1531,  1532,  1534,  1535,  1536,  1538,
    1539,  1541,  1542
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
#line 5306 "D:/projects/a2llib/src/xcp/xcpdataparser.cpp"

#line 1544 "D:/projects/a2llib/src/xcp/xcpdataparser.y"


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
