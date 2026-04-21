%require "3.2"
%language "c++"


%define api.prefix {xcp}
%define api.namespace {a2l::xcp}
%define api.parser.class {XcpDataParser}


%code requires {
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <utility>

namespace a2l::xcp {
class XcpDataScanner;
}

}

%parse-param { a2l::xcp::XcpDataScanner &scanner  }


%code  {
    #include <sstream>
    #include <limits>
    #include "xcpdatascanner.h"


    #undef yylex
    #define yylex scanner.xcplex
}

%define api.value.type variant

%token ADDRESS ADDRESS_MAPPING ALT_SAMPLE_COUNT ALTERNATE_SETTING_NO ASYNCH_FULL_DUPLEX_MODE AVAILABLE_EVENT_LIST
%token BAUDRATE BIT_STIM_SUPPORTED BLOCK BLOCK_BEGIN BLOCK_END BTL_CYCLES BUFFER_RESERVE
%token BUFFER_RESERVE_EVENT
%token CAN_FD CAN_FD_DATA_TRANSFER_BAUDRATE CAN_ID_BROADCAST CAN_ID_MASTER CAN_ID_MASTER_INCREMENTAL
%token CAN_ID_SLAVE CAN_ID_GET_DAQ_CLOCK_MULTICAST CHANNEL CHECKSUM CLOCK CMD COMMUNICATION_MODE_SUPPORTED
%token CONSISTENCY_EVENT_LIST CONSISTENCY CORE_LOAD_MAX CORE_LOAD_MAX_TOTAL  CORE_LOAD_EP
%token COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER CPU_LOAD_MAX CPU_LOAD_MAX_TOTAL CPU_LOAD_CONSUMPTION_DAQ
%token CPU_LOAD_CONSUMPTION_STIM CPU_LOAD_CONSUMPTION_QUEUE CPU_LOAD_CONSUMPTION_QUEUE_STIM CYCLE_REPETITION
%token DAQ DAQ_ALTERNATING_SUPPORTED DAQ_EVENT DAQ_LIST DAQ_LIST_CAN_ID DAQ_LIST_USB_ENDPOINT DAQ_LIST_TYPE
%token DAQ_MEMORY_CONSUMPTION DAQ_PACKED_MODE DAQ_PACKED_MODE_SUPPORTED DAQ_STIM DEFAULT_EVENT_LIST
%token DEFAULT_PAGE_NUMBER DTO_CTR_DAQ_MODE DTO_CTR_DAQ_MODE_FIXED DTO_CTR_FIELD_SUPPORTED DTO_CTR_STIM_MODE
%token DTO_CTR_STIM_MODE_FIXED
%token ECU_STATES ECU_SWITCHED_TO_DEFAULT_PAGE EV_SERV EVENT EVENT_CAN_ID_LIST EVENT_COUNTER_PRESENT
%token EVENT_FIXED EXTERNAL_FUNCTION
%token FIRST_PID FIXED FIXED_EVENT_LIST FIXED_IN FIXED_OUT FLX_SLOT_ID FRAMING FREEZE_SUPPORTED
%token HOST_NAME
%token IF_DATA IN_EP_ONLY_DAQ IN_EP_ONLY_EVSERV IN_EP_RESERR_DAQ_EVSERV INIT_SEGMENT INITIAL_VALUE
%token INITIAL_CMD_BUFFER INITIAL_RES_ERR_BUFFER INTERFACE_STRING_DESCRIPTOR INTERLEAVED IPV6
%token LPU_ID
%token MASTER MAX_BLOCK_SIZE MAX_DAQ_TOTAL MAX_DLC_REQUIRED MAX_BUS_LOAD MAX_DLC MAX_DTO_STIM MAX_BIT_RATE
%token MAX_FLX_LEN_BUF MAX_ODT MAX_ODT_DAQ_TOTAL MAX_ODT_ENTRIES MAX_ODT_ENTRIES_DAQ_TOTAL
%token MAX_ODT_ENTRIES_STIM_TOTAL MAX_ODT_ENTRIES_TOTAL MAX_ODT_STIM_TOTAL MAX_ODT_TOTAL MEASUREMENT_SPLIT_ALLOWED
%token MEMORY_ACCESS MIN_CYCLE_TIME MIN_ST_STIM MODEL_NAME MTA_BLOCK_SIZE_ALIGN MULTICAST
%token ODT ODT_ENTRY ODT_ENTRY_SIZE_FACTOR_TABLE OPTIMISATION_TYPE_ODT_STRICT OFFSET
%token OPTIONAL_CMD OPTIONAL_LEVEL1_CMD OPTIONAL_TL_SUBCMD OUT_EP_ONLY_STIM OUT_EP_CMD_STIM
%token PACKET_ALIGNMENT PAG PAGE PGM PID_OFF_SUPPORTED POOL_BUFFER PREDEFINED PRESCALER_SUPPORTED PROTOCOL_LAYER
%token RECOMMENDED_HOST_BUFSIZE RELATED_EVENT_CHANNEL_NUMBER RELATED_EVENT_CHANNEL_NUMBER_FIXED
%token RES_ERR RESUME_SUPPORTED
%token SAMPLE_POINT SAMPLE_RATE SECTOR SEGMENT SECONDARY_SAMPLE_POINT SEED_AND_KEY_EXTERNAL_FUNCTION
%token SJW SLAVE STATE STIM STIM_DTO_CTR_COPY_PRESENT STORE_DAQ_SUPPORTED SYNC_EDGE
%token SYNCH_FULL_DUPLEX_MODE_BYTE SYNCH_FULL_DUPLEX_MODE_WORD SYNCH_FULL_DUPLEX_MODE_DWORD
%token SYNCH_FULL_MASTER_MODE_BYTE SYNCH_FULL_MASTER_MODE_WORD SYNCH_FULL_MASTER_MODE_DWORD
%token TIME_CHARACTERIZATION TIME_CORRELATION TIMESTAMP_FIXED TIMESTAMP_SUPPORTED TRANSPORT_LAYER_INSTANCE
%token TRANSCEIVER_DELAY_COMPENSATION
%token VARIABLE
%token XCP XCPplus XCP_ON_CAN XCP_ON_SxI XCP_ON_TCP_IP XCP_ON_UDP_IP XCP_ON_USB XCP_ON_FLX XCP_ON_SIMULINK XCP_PACKET


%token <uint64_t> UINT
%token <uint64_t> HEX
%token <int64_t>  INT
%token <double>   FLOAT
%token <std::string> IDENT
%token <std::string> STRING

%nterm <std::string> daq_list_type
%nterm <std::string> ident_or_string
%nterm <std::string> transport_layer_instance


%start xcp_data_block

%%

xcp_data_block:  BLOCK_BEGIN IF_DATA if_data BLOCK_END IF_DATA;

if_data: XCPplus UINT definitions
         | XCP definitions;
definitions: %empty
             | definitions definition;
definition: common_definition
            | transport_protocol;

common_definition: protocol_layer
            | daq
            | daq_event
            | pag
            | pgm
            | segment
            | time_correlation;

transport_protocol: xcp_on_can
            | xcp_on_sxi
            | xcp_on_tcp_ip
            | xcp_on_udp_ip
            | xcp_on_usb
            | xcp_on_flx
            | xcp_on_simulink;

protocol_layer: BLOCK_BEGIN PROTOCOL_LAYER protocol_fixed_items protocol_optional_items BLOCK_END PROTOCOL_LAYER;
protocol_fixed_items: UINT UINT UINT UINT UINT UINT UINT UINT UINT UINT IDENT IDENT;
protocol_optional_items: %empty
                         | protocol_optional_items protocol_optional_item;
protocol_optional_item: optional_command
                        | optional_level1_command
                        | communication_mode_supported
                        | seed_and_key_function
                        | max_dto_stim
                        | ecu_states;

optional_command: OPTIONAL_CMD IDENT;
optional_level1_command: OPTIONAL_LEVEL1_CMD IDENT;

communication_mode_supported: COMMUNICATION_MODE_SUPPORTED communication_mode_union
            | BLOCK_BEGIN COMMUNICATION_MODE_SUPPORTED
                communication_mode_union
            BLOCK_END COMMUNICATION_MODE_SUPPORTED;
communication_mode_union: BLOCK block_struct
                          | BLOCK_BEGIN BLOCK
                             block_struct
                            BLOCK_END BLOCK
                           | INTERLEAVED UINT;
block_struct: slave_item master_item;
slave_item: %empty
            | SLAVE;
master_item: %empty
            | MASTER UINT UINT;

seed_and_key_function: SEED_AND_KEY_EXTERNAL_FUNCTION STRING;

max_dto_stim: MAX_DTO_STIM UINT;

ecu_states: BLOCK_BEGIN ECU_STATES state_list BLOCK_END ECU_STATES;

state_list: %empty
            | state_list state_block;

state_block: BLOCK_BEGIN STATE
                UINT STRING ecu_switch_to_default IDENT IDENT IDENT IDENT memory_access_list
             BLOCK_END STATE;
ecu_switch_to_default: %empty
                       | ECU_SWITCHED_TO_DEFAULT_PAGE;
memory_access_list: %empty
                    | memory_access_list memory_access;
memory_access: BLOCK_BEGIN MEMORY_ACCESS UINT UINT IDENT IDENT BLOCK_END MEMORY_ACCESS;

daq: BLOCK_BEGIN DAQ
       IDENT UINT UINT UINT IDENT IDENT IDENT IDENT UINT IDENT daq_optionals
     BLOCK_END DAQ
     | BLOCK_BEGIN DAQ
         IDENT UINT UINT UINT IDENT IDENT IDENT UINT IDENT daq_optionals
       BLOCK_END DAQ;
daq_optionals: %empty
               | daq_optionals daq_optional;
daq_optional: DAQ_ALTERNATING_SUPPORTED UINT
              | PRESCALER_SUPPORTED
              | RESUME_SUPPORTED
              | STORE_DAQ_SUPPORTED
              | DTO_CTR_FIELD_SUPPORTED
              | OPTIMISATION_TYPE_ODT_STRICT
              | stim_struct
              | timestamp_supported
              | PID_OFF_SUPPORTED
              | MAX_DAQ_TOTAL UINT
              | MAX_ODT_TOTAL UINT
              | MAX_ODT_DAQ_TOTAL UINT
              | MAX_ODT_STIM_TOTAL UINT
              | MAX_ODT_ENTRIES_TOTAL UINT
              | MAX_ODT_ENTRIES_DAQ_TOTAL UINT
              | MAX_ODT_ENTRIES_STIM_TOTAL UINT
              | CPU_LOAD_MAX_TOTAL FLOAT
              | CORE_LOAD_MAX_TOTAL FLOAT
              | core_load_max
              | daq_memory_consumption
              | daq_list
              | d_event;

stim_struct: BLOCK_BEGIN STIM IDENT UINT bit_stim min_st_stim BLOCK_END STIM;
bit_stim: %empty
          | BIT_STIM_SUPPORTED;
min_st_stim: %empty
             | MIN_ST_STIM UINT;

timestamp_supported: BLOCK_BEGIN TIMESTAMP_SUPPORTED
                        UINT IDENT IDENT timestamp_fixed
                     BLOCK_END TIMESTAMP_SUPPORTED;
timestamp_fixed: %empty
                 | TIMESTAMP_FIXED;

core_load_max: BLOCK_BEGIN CORE_LOAD_MAX UINT FLOAT BLOCK_END CORE_LOAD_MAX;

daq_memory_consumption: BLOCK_BEGIN DAQ_MEMORY_CONSUMPTION
                            UINT UINT UINT UINT UINT UINT daq_memory_consumption_optional
                        BLOCK_END DAQ_MEMORY_CONSUMPTION;
daq_memory_consumption_optional: BLOCK_BEGIN BUFFER_RESERVE UINT UINT BLOCK_END BUFFER_RESERVE;

daq_list: BLOCK_BEGIN DAQ_LIST
            UINT daq_list_optionals
          BLOCK_END DAQ_LIST;

daq_list_optionals: %empty
                    | daq_list_optionals daq_list_optional;

daq_list_optional: DAQ_LIST_TYPE daq_list_type
                   | MAX_ODT UINT
                   | MAX_ODT_ENTRIES UINT
                   | FIRST_PID UINT
                   | EVENT_FIXED UINT
                   | DAQ_PACKED_MODE_SUPPORTED
                   | BLOCK_BEGIN PREDEFINED odt_list BLOCK_END PREDEFINED;
odt_list: %empty
          | odt_list odt;

odt: BLOCK_BEGIN ODT UINT odt_entry_list BLOCK_END ODT;

odt_entry_list: %empty
                | odt_entry_list odt_entry;

odt_entry: ODT_ENTRY UINT UINT UINT UINT UINT;

d_event: BLOCK_BEGIN EVENT
         ident_or_string ident_or_string UINT daq_list_type UINT UINT UINT UINT d_event_optionals
       BLOCK_END EVENT;
d_event_optionals: %empty
                 | d_event_optionals d_event_optional;
d_event_optional: COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER UINT
                | CONSISTENCY IDENT
                | EVENT_COUNTER_PRESENT
                | RELATED_EVENT_CHANNEL_NUMBER UINT
                | RELATED_EVENT_CHANNEL_NUMBER_FIXED
                | DTO_CTR_DAQ_MODE IDENT
                | DTO_CTR_DAQ_MODE_FIXED
                | DTO_CTR_STIM_MODE IDENT
                | DTO_CTR_STIM_MODE_FIXED
                | STIM_DTO_CTR_COPY_PRESENT
                | daq_packed_mode
                | MIN_CYCLE_TIME UINT UINT
                | BUFFER_RESERVE_EVENT UINT UINT
                | CPU_LOAD_MAX FLOAT
                | cpu_load_consumption_daq
                | cpu_load_consumption_stim
                | cpu_load_consumption_queue
                | cpu_load_consumption_queue_stim;

daq_packed_mode: BLOCK_BEGIN DAQ_PACKED_MODE
                    IDENT IDENT IDENT UINT alt_sample_count_list
                 BLOCK_END DAQ_PACKED_MODE;
alt_sample_count_list: %empty
                       | alt_sample_count_list alt_sample_count;
alt_sample_count: ALT_SAMPLE_COUNT UINT;

cpu_load_consumption_daq: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_DAQ
                            FLOAT FLOAT FLOAT cpu_load_consumption_daq_options
                          BLOCK_END CPU_LOAD_CONSUMPTION_DAQ;
cpu_load_consumption_daq_options: cpu_load_consumption_daq_option
                              | cpu_load_consumption_daq_options cpu_load_consumption_daq_option;

cpu_load_consumption_daq_option: odt_entry_size_factor_table
                             | core_load_ep;

cpu_load_consumption_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_STIM
                            FLOAT FLOAT FLOAT cpu_load_consumption_stim_options
                          BLOCK_END CPU_LOAD_CONSUMPTION_STIM;
cpu_load_consumption_stim_options: cpu_load_consumption_stim_option
                              | cpu_load_consumption_stim_options cpu_load_consumption_stim_option;

cpu_load_consumption_stim_option: odt_entry_size_factor_table
                             | core_load_ep;

odt_entry_size_factor_table: BLOCK_BEGIN ODT_ENTRY_SIZE_FACTOR_TABLE
                               UINT FLOAT
                             BLOCK_END ODT_ENTRY_SIZE_FACTOR_TABLE;

cpu_load_consumption_queue: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE
                            FLOAT FLOAT FLOAT cpu_load_consumption_queue_options
                          BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE;

cpu_load_consumption_queue_options: cpu_load_consumption_queue_option
                              | cpu_load_consumption_queue_options cpu_load_consumption_queue_option;
cpu_load_consumption_queue_option: core_load_ep;

cpu_load_consumption_queue_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE_STIM
                            FLOAT FLOAT FLOAT cpu_load_consumption_queue_stim_options
                          BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE;
cpu_load_consumption_queue_stim_options: cpu_load_consumption_queue_stim_option
                              | cpu_load_consumption_queue_stim_options cpu_load_consumption_queue_stim_option;
cpu_load_consumption_queue_stim_option: core_load_ep;

core_load_ep: BLOCK_BEGIN CORE_LOAD_EP
                UINT FLOAT
              BLOCK_END CORE_LOAD_EP;

daq_event: BLOCK_BEGIN DAQ_EVENT
             daq_event_union
           BLOCK_END DAQ_EVENT;
daq_event_union: fixed_event_list
                 | variable;

fixed_event_list: FIXED_EVENT_LIST event_list;
variable: VARIABLE variable_options;
variable_options: %empty
                  | variable_options variable_option;
variable_option: BLOCK_BEGIN AVAILABLE_EVENT_LIST event_list BLOCK_END AVAILABLE_EVENT_LIST
                 | BLOCK_BEGIN DEFAULT_EVENT_LIST event_list BLOCK_END DEFAULT_EVENT_LIST
                 | BLOCK_BEGIN CONSISTENCY_EVENT_LIST event_list BLOCK_END CONSISTENCY_EVENT_LIST;

pag: BLOCK_BEGIN PAG UINT freeze_supported BLOCK_END PAG;
freeze_supported: %empty
                | FREEZE_SUPPORTED;

pgm: BLOCK_BEGIN PGM
       IDENT UINT UINT pgm_options
     BLOCK_END PGM;
pgm_options: %empty
             | pgm_options pgm_option;
pgm_option: sector
            | communication_mode_supported;
sector: BLOCK_BEGIN SECTOR
          STRING UINT UINT UINT UINT UINT UINT
        BLOCK_END SECTOR;

segment: BLOCK_BEGIN SEGMENT
           UINT UINT UINT UINT UINT segment_options
         BLOCK_END SEGMENT;
segment_options: %empty
                 | segment_options segment_option;
segment_option: checksum
                | DEFAULT_PAGE_NUMBER UINT
                | page
                | address_mapping;

checksum: BLOCK_BEGIN CHECKSUM
            IDENT checksum_options
          BLOCK_END CHECKSUM;
checksum_options: %empty
                  | checksum_options checksum_option;
checksum_option: MAX_BLOCK_SIZE UINT
                 | EXTERNAL_FUNCTION STRING
                 | MTA_BLOCK_SIZE_ALIGN UINT;

page: BLOCK_BEGIN PAGE
        UINT IDENT IDENT IDENT init_segment
      BLOCK_END PAGE;

address_mapping: BLOCK_BEGIN ADDRESS_MAPPING
                   UINT UINT UINT
                 BLOCK_END ADDRESS_MAPPING;

init_segment: %empty
             | INIT_SEGMENT UINT;

time_correlation: BLOCK_BEGIN TIME_CORRELATION
                    IDENT clock_list
                  BLOCK_END TIME_CORRELATION;
clock_list: %empty
            | clock_list clock;
clock: BLOCK_BEGIN CLOCK
         UINT UINT UINT UINT UINT UINT UINT UINT
         IDENT IDENT IDENT UINT timestamp_characterization UINT IDENT
       BLOCK_END CLOCK;
timestamp_characterization: %empty
               | BLOCK_BEGIN TIME_CHARACTERIZATION
                   UINT IDENT IDENT
                 BLOCK_END TIME_CHARACTERIZATION;

event_list: %empty
            | event_list event;
event: EVENT UINT;

xcp_on_can: BLOCK_BEGIN XCP_ON_CAN
              can_parameters transport_layer_instance
            BLOCK_END XCP_ON_CAN;

can_parameters: UINT can_parameter_options;
can_parameter_options: %empty
                       | can_parameter_options can_parameter_option;
can_parameter_option: CAN_ID_BROADCAST UINT
                      | CAN_ID_MASTER UINT
                      | CAN_ID_MASTER_INCREMENTAL
                      | CAN_ID_SLAVE UINT
                      | CAN_ID_GET_DAQ_CLOCK_MULTICAST UINT
                      | BAUDRATE UINT
                      | SAMPLE_POINT UINT
                      | SAMPLE_RATE IDENT
                      | BTL_CYCLES UINT
                      | SJW UINT
                      | SYNC_EDGE IDENT
                      | MAX_DLC_REQUIRED
                      | daq_list_can_id
                      | event_can_id_list
                      | MAX_BUS_LOAD UINT
                      | MEASUREMENT_SPLIT_ALLOWED
                      | can_fd
                      | OPTIONAL_TL_SUBCMD IDENT
                      | common_definition;

daq_list_can_id: BLOCK_BEGIN DAQ_LIST_CAN_ID
                   UINT daq_list_can_id_options
                 BLOCK_END DAQ_LIST_CAN_ID;
daq_list_can_id_options: %empty
                         | daq_list_can_id_options daq_list_can_id_option;
daq_list_can_id_option: VARIABLE
                        | fixed;
event_can_id_list: BLOCK_BEGIN EVENT_CAN_ID_LIST
                     UINT fixed_list
                   BLOCK_END EVENT_CAN_ID_LIST;
fixed_list: %empty
       | fixed_list fixed;
fixed: FIXED UINT;

can_fd: BLOCK_BEGIN CAN_FD
          can_fd_options
        BLOCK_END CAN_FD;
can_fd_options: %empty
                | can_fd_options can_fd_option;
can_fd_option: MAX_DLC UINT
               | CAN_FD_DATA_TRANSFER_BAUDRATE UINT
               | SAMPLE_POINT UINT
               | BTL_CYCLES UINT
               | SJW UINT
               | SYNC_EDGE IDENT
               | MAX_DLC_REQUIRED
               | SECONDARY_SAMPLE_POINT UINT
               | TRANSCEIVER_DELAY_COMPENSATION IDENT
               | common_definition;

xcp_on_sxi: BLOCK_BEGIN XCP_ON_SxI
              sxi_parameter transport_layer_instance
            BLOCK_END XCP_ON_SxI;
sxi_parameter: UINT UINT sxi_parameter_options IDENT IDENT sxi_option;
sxi_parameter_options: %empty
                       | sxi_parameter_options sxi_parameter_option;
sxi_parameter_option: ASYNCH_FULL_DUPLEX_MODE IDENT IDENT framing
                      | SYNCH_FULL_DUPLEX_MODE_BYTE
                      | SYNCH_FULL_DUPLEX_MODE_WORD
                      | SYNCH_FULL_DUPLEX_MODE_DWORD
                      | SYNCH_FULL_MASTER_MODE_BYTE
                      | SYNCH_FULL_MASTER_MODE_WORD
                      | SYNCH_FULL_MASTER_MODE_DWORD;
sxi_option: %empty
            | common_definition;

framing: %empty
         | BLOCK_BEGIN FRAMING
             UINT UINT
           BLOCK_END FRAMING;

xcp_on_tcp_ip: BLOCK_BEGIN XCP_ON_TCP_IP
                 tcp_ip_parameter transport_layer_instance
               BLOCK_END XCP_ON_TCP_IP;
tcp_ip_parameter: UINT UINT tcp_ip_options;
tcp_ip_options: %empty
                | tcp_ip_options tcp_ip_option;
tcp_ip_option: HOST_NAME STRING
               | ADDRESS STRING
               | IPV6 STRING
               | MAX_BUS_LOAD UINT
               | MAX_BIT_RATE UINT
               | PACKET_ALIGNMENT IDENT
               | OPTIONAL_TL_SUBCMD IDENT
               | common_definition;

xcp_on_udp_ip: BLOCK_BEGIN XCP_ON_UDP_IP
                 udp_ip_parameter transport_layer_instance
               BLOCK_END XCP_ON_UDP_IP;
udp_ip_parameter: UINT UINT udp_ip_options;
udp_ip_options: %empty
                | udp_ip_options udp_ip_option;
udp_ip_option: HOST_NAME STRING
               | ADDRESS STRING
               | IPV6 STRING
               | MAX_BUS_LOAD UINT
               | MAX_BIT_RATE UINT
               | PACKET_ALIGNMENT IDENT
               | OPTIONAL_TL_SUBCMD IDENT
               | common_definition;

xcp_on_usb: BLOCK_BEGIN XCP_ON_USB
              UINT UINT UINT UINT IDENT usb_options
            BLOCK_END XCP_ON_USB;
usb_options: %empty
             | usb_options usb_option;
usb_option: BLOCK_BEGIN OUT_EP_CMD_STIM
             ep_parameters
            BLOCK_END OUT_EP_CMD_STIM
            | BLOCK_BEGIN IN_EP_RESERR_DAQ_EVSERV
                ep_parameters
              BLOCK_END IN_EP_RESERR_DAQ_EVSERV
            | ALTERNATE_SETTING_NO UINT
            | INTERFACE_STRING_DESCRIPTOR STRING
            | BLOCK_BEGIN OUT_EP_ONLY_STIM
                ep_parameters
              BLOCK_END OUT_EP_ONLY_STIM
            | BLOCK_BEGIN IN_EP_ONLY_DAQ
                ep_parameters
              BLOCK_END IN_EP_ONLY_DAQ
            | BLOCK_BEGIN IN_EP_ONLY_EVSERV
                ep_parameters
              BLOCK_END IN_EP_ONLY_EVSERV
            | daq_list_usb_endpoint
            | OPTIONAL_TL_SUBCMD IDENT
            | common_definition;
daq_list_usb_endpoint: BLOCK_BEGIN DAQ_LIST_USB_ENDPOINT
                         UINT fixed_in fixed_out
                       BLOCK_END DAQ_LIST_USB_ENDPOINT;
fixed_in: %empty
          | FIXED_IN UINT;
fixed_out: %empty
          | FIXED_OUT UINT;
ep_parameters: UINT IDENT UINT UINT IDENT IDENT recommended_host_bufsize;
recommended_host_bufsize: %empty
                          | RECOMMENDED_HOST_BUFSIZE UINT;

xcp_on_flx: BLOCK_BEGIN XCP_ON_FLX
              UINT UINT STRING STRING UINT IDENT IDENT flx_options
            BLOCK_END XCP_ON_FLX;

flx_options: %empty
             | flx_options flx_option;
flx_option: BLOCK_BEGIN INITIAL_CMD_BUFFER
              buffer
            BLOCK_END INITIAL_CMD_BUFFER
            | BLOCK_BEGIN INITIAL_RES_ERR_BUFFER
                buffer
              BLOCK_END INITIAL_RES_ERR_BUFFER
            | BLOCK_BEGIN POOL_BUFFER
                buffer
              BLOCK_END POOL_BUFFER
            | OPTIONAL_TL_SUBCMD IDENT
            | common_definition;

buffer: UINT buffer_options;
buffer_options: %empty
                | buffer_options buffer_option;
buffer_option: MAX_FLX_LEN_BUF max_flx_len_buf_union
               | lpu_id
               | xcp_packet;
max_flx_len_buf_union: FIXED UINT
                       | VARIABLE UINT;
lpu_id: BLOCK_BEGIN LPU_ID
          lpu_id_options
        BLOCK_END LPU_ID;
lpu_id_options: %empty
                | lpu_id_options lpu_id_option;
lpu_id_option: flx_slot_id_union
               | offset_union
               | cycle_repetition
               | channel;
flx_slot_id_union: FLX_SLOT_ID lpu_id_union;
offset_union: OFFSET lpu_id_option;
cycle_repetition: CYCLE_REPETITION lpu_id_union;
channel: CHANNEL channel_union;
channel_union: FIXED IDENT
               | VARIABLE initial_enum;
initial_enum: %empty
             | INITIAL_VALUE IDENT;

lpu_id_union: FIXED UINT
              | VARIABLE initial_value;
initial_value: %empty
               | INITIAL_VALUE UINT;

xcp_packet: BLOCK_BEGIN XCP_PACKET
              xcp_packet_options
            BLOCK_END XCP_PACKET;
xcp_packet_options: %empty
             | xcp_packet_options xcp_packet_option;
xcp_packet_option: CMD IDENT
            | RES_ERR IDENT
            | EV_SERV IDENT
            | DAQ IDENT
            | STIM IDENT
            | MULTICAST IDENT;

xcp_on_simulink: BLOCK_BEGIN XCP_ON_SIMULINK
                   simulink_options
                 BLOCK_END XCP_ON_SIMULINK;
simulink_options: %empty
                  | simulink_options simulink_option;
simulink_option: MODEL_NAME STRING
                 | common_definition;

daq_list_type: DAQ { $$ = "DAQ"; }
               | STIM { $$ = "STIM"; }
               | DAQ_STIM { $$ = "DAQ_STIM"; };
transport_layer_instance: %empty { $$.clear(); }
                          | TRANSPORT_LAYER_INSTANCE STRING { $$ = std::move($2); }
ident_or_string: IDENT { $$ = std::move($1); }
                 | STRING { $$ = std::move($1); }

%%

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
