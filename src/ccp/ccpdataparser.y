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
#include "a2l/xcp/commonparameters.h"


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
%token NONE
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

%nterm <AddressMapping> address_mapping
%nterm <uint16_t> alt_sample_count
%nterm <std::vector<uint16_t>> alt_sample_count_list
%nterm <bool> bit_stim
%nterm <std::optional<BufferReserve>> buffer_reserve
%nterm <CommunicationMode> communication_mode_supported
%nterm <std::string> consistency
%nterm <CoreLoadEp> core_load_ep
%nterm <CoreLoadMax> core_load_max
%nterm <CpuLoadConsumption> cpu_load_consumption_daq
%nterm <CpuLoadConsumption> cpu_load_consumption_stim
%nterm <CpuLoadConsumption> cpu_load_consumption_queue
%nterm <CpuLoadConsumption> cpu_load_consumption_queue_stim
%nterm <Daq> daq
%nterm <DaqEvent> daq_event
%nterm <DaqList> daq_list
%nterm <DaqMemoryConsumption> daq_memory_consumption
%nterm <bool> ecu_switch_to_default
%nterm <Event> d_event
%nterm <std::string> daq_list_type
%nterm <DaqPackedMode> daq_packed_mode
%nterm <std::vector<EcuState>> ecu_states
%nterm <uint16_t> event
%nterm <std::vector<uint16_t>> event_list
%nterm <uint32_t> fixed
%nterm <std::vector<uint32_t>> fixed_list
%nterm <std::string> ident_or_string
%nterm <bool> initial_enum
%nterm <bool> initial_value
%nterm <MemoryAccess> memory_access
%nterm <std::vector<MemoryAccess>> memory_access_list
%nterm <std::optional<uint8_t>> min_st_stim
%nterm <Odt> odt
%nterm <std::vector<Odt>> odt_list
%nterm <OdtEntry> odt_entry
%nterm <std::vector<OdtEntry>> odt_entry_list
%nterm <OdtEntrySizeFactor> odt_entry_size_factor_table
%nterm <Pag> pag
%nterm <Pgm> pgm
%nterm <ProtocolLayer> protocol_layer
%nterm <Sector> sector
%nterm <EcuState> state_block
%nterm <std::vector<EcuState>> state_list
%nterm <Segment> segment
%nterm <DaqStim> stim_struct
%nterm <TimeCorrelation> time_correlation
%nterm <bool> timestamp_fixed
%nterm <Timestamp> timestamp_supported
%nterm <std::string> transport_layer_instance


%start xcp_data_block

%%

xcp_data_block:  BLOCK_BEGIN IF_DATA
			if_data
		 BLOCK_END IF_DATA;

if_data: XCPplus UINT definitions {
       scanner.SetVersion($2);
      } | XCP definitions;

definitions: %empty
             | definitions definition;

definition: common_parameter {
	  scanner.SaveCommonParameters();
	} | transport_protocol;

common_parameter: protocol_layer {
	CommonParameters& common = scanner.GetCommonParameters();
	common.SetProtocolLayer(std::move($1));
    } | daq {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaq(std::move($1));
    } | daq_event {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetDaqEvent(std::move($1));
    } | pag {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPag(std::move($1));
    } | pgm {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetPgm(std::move($1));
    } | segment {
    	CommonParameters& common = scanner.GetCommonParameters();
        common.SetSegment(std::move($1));
    } | time_correlation {
     	CommonParameters& common = scanner.GetCommonParameters();
        common.SetTimeCorrelation(std::move($1));
    };

transport_protocol: xcp_on_can
            | xcp_on_sxi
            | xcp_on_tcp_ip
            | xcp_on_udp_ip
            | xcp_on_usb
            | xcp_on_flx
            | xcp_on_simulink;

protocol_layer: BLOCK_BEGIN PROTOCOL_LAYER
	          UINT UINT UINT UINT UINT UINT UINT UINT UINT UINT IDENT IDENT protocol_optional_items
	        BLOCK_END PROTOCOL_LAYER {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetVersion($3);
	  protocol.SetTimer(ProtocolTimer::T1, $4);
	  protocol.SetTimer(ProtocolTimer::T2, $5);
	  protocol.SetTimer(ProtocolTimer::T3, $6);
	  protocol.SetTimer(ProtocolTimer::T4, $7);
	  protocol.SetTimer(ProtocolTimer::T5, $8);
	  protocol.SetTimer(ProtocolTimer::T6, $9);
	  protocol.SetTimer(ProtocolTimer::T7, $10);
	  protocol.SetMaxCto($11);
	  protocol.SetMaxDto($12);
	  protocol.SetByteOrder($13);
	  $$ = std::move(protocol);
	  protocol.Reset();
	};

protocol_optional_items: %empty
        | protocol_optional_items protocol_optional_item;

protocol_optional_item: OPTIONAL_CMD IDENT {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommand($2);
        } | OPTIONAL_LEVEL1_CMD IDENT {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetOptionalCommandLevel1($2);
	} | communication_mode_supported {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetCommunicationMode(std::move($1));
	} | SEED_AND_KEY_EXTERNAL_FUNCTION STRING {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetSeedAndKeyFunction(std::move($2));
	} | MAX_DTO_STIM UINT {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetMaxDtoStim($2);
	} | ecu_states {
          ProtocolLayer& protocol = scanner.GetProtocolLayer();
	  protocol.SetEcuStates(std::move($1));
	};

ecu_states: BLOCK_BEGIN ECU_STATES
		state_list
	    BLOCK_END ECU_STATES { $$ = std::move($3); };

state_list: %empty { $$.clear(); }
            | state_list state_block {
            	$$ = std::move($1);
            	$$.emplace_back(std::move($2));
            };

state_block: BLOCK_BEGIN STATE
                UINT STRING ecu_switch_to_default IDENT IDENT IDENT IDENT memory_access_list
             BLOCK_END STATE {
             	$$.SetNumber($3);
             	$$.SetName($4);
             	$$.SetEcuSwithedToDefaultPage($5);
             	$$.SetCalPagResource($6);
             	$$.SetDaqResource($7);
              	$$.SetPgmResource($8);
              	$$.SetStimResource($9);
              	$$.SetMemoryAccessList($10);
             };

ecu_switch_to_default: %empty { $$ = false; }
                       | ECU_SWITCHED_TO_DEFAULT_PAGE { $$ = true; };

memory_access_list: %empty { $$.clear(); }
                    | memory_access_list memory_access {
         		$$ = std::move($1);
         		$$.emplace_back($2);
                    };
memory_access: BLOCK_BEGIN MEMORY_ACCESS
		UINT UINT IDENT IDENT
	       BLOCK_END MEMORY_ACCESS {
		$$.SetSegment($3);
		$$.SetPage($4);
		$$.SetReadAccess($5);
		$$.SetWriteAccess($6);
	};

daq:   BLOCK_BEGIN DAQ
         IDENT UINT UINT UINT IDENT IDENT IDENT IDENT UINT IDENT daq_optionals
       BLOCK_END DAQ {
        Daq& daq = scanner.GetDaq();
     	daq.SetType($3);
     	daq.SetMaxDaq($4);
     	daq.SetMaxEvent($5);
     	daq.SetMinDaq($6);
     	daq.SetOptimisationType($7);
     	daq.SetAddressExtension($8);
     	daq.SetIdentificationFieldType($9);
     	daq.SetGranularityOdtEntrySizeDaq($10);
     	daq.SetMaxOdtEntrySize($11);
     	daq.SetOverloadIndicator($12);
     	$$ = std::move(daq);
     	daq.Reset();
       } | BLOCK_BEGIN DAQ
         IDENT UINT UINT UINT IDENT IDENT IDENT UINT IDENT daq_optionals
       BLOCK_END DAQ {
        Daq& daq = scanner.GetDaq();
     	daq.SetType($3);
     	daq.SetMaxDaq($4);
     	daq.SetMaxEvent($5);
     	daq.SetMinDaq($6);
     	daq.SetOptimisationType($7);
     	daq.SetAddressExtension($8);
     	daq.SetIdentificationFieldType($9);
     	daq.SetMaxOdtEntrySize($10);
     	daq.SetOverloadIndicator($11);
     	$$ = std::move(daq);
     	daq.Reset();
     };

daq_optionals: %empty
               | daq_optionals daq_optional;

daq_optional: DAQ_ALTERNATING_SUPPORTED UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqAlternatingSupported($2);
      } | PRESCALER_SUPPORTED {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPrecalerSupported();
      } | RESUME_SUPPORTED {
      	Daq& daq = scanner.GetDaq();
      	daq.SetResumeSupported();
      } | STORE_DAQ_SUPPORTED {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStoreDaqSupported();
      } | DTO_CTR_FIELD_SUPPORTED {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDtoCtrSupported();
      } | OPTIMISATION_TYPE_ODT_STRICT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetOptimisationTypeOdtStrict();
      } | stim_struct {
      	Daq& daq = scanner.GetDaq();
      	daq.SetStim($1);
      } | timestamp_supported {
      	Daq& daq = scanner.GetDaq();
      	daq.SetTimestamp($1);
      } | PID_OFF_SUPPORTED {
      	Daq& daq = scanner.GetDaq();
      	daq.SetPidOffSupported();
      } | MAX_DAQ_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDaqTotal($2);
      } | MAX_ODT_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtTotal($2);
      } | MAX_ODT_DAQ_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtDaqTotal($2);
      } | MAX_ODT_STIM_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxOdtStimTotal($2);
      } | MAX_ODT_ENTRIES_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesTotal($2);
      } | MAX_ODT_ENTRIES_DAQ_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesDaqTotal($2);
      } | MAX_ODT_ENTRIES_STIM_TOTAL UINT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetMaxDtoEntriesStimTotal($2);
      } | CPU_LOAD_MAX_TOTAL FLOAT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCpuLoadMaxTotal($2);
      } | CORE_LOAD_MAX_TOTAL FLOAT {
      	Daq& daq = scanner.GetDaq();
      	daq.SetCoreLoadMaxTotal($2);
      } | core_load_max {
      	Daq& daq = scanner.GetDaq();
      	daq.AddCoreLoadMax($1);
      } | daq_memory_consumption {
      	Daq& daq = scanner.GetDaq();
      	daq.SetDaqMemoryConsumption($1);
      } | daq_list {
      	Daq& daq = scanner.GetDaq();
      	daq.AddDaqList(std::move($1));
      } | d_event {
      	Daq& daq = scanner.GetDaq();
      	daq.AddEvent(std::move($1));
      };

stim_struct: BLOCK_BEGIN STIM
		IDENT UINT bit_stim min_st_stim
	     BLOCK_END STIM {
		$$.SetSize($3);
		$$.max_odt_entry_size = static_cast<uint8_t>($4);
		$$.bit_stim_supported = $5;
		$$.min_st_stim = $6;
	  };

bit_stim: %empty { $$ = false; }
          | BIT_STIM_SUPPORTED { $$ = true; };

min_st_stim: %empty { $$.reset(); }
             | MIN_ST_STIM UINT { $$ = static_cast<uint8_t>($2); };

timestamp_supported: BLOCK_BEGIN TIMESTAMP_SUPPORTED
                        UINT IDENT IDENT timestamp_fixed
                     BLOCK_END TIMESTAMP_SUPPORTED {
     		$$.SetTicks($3);
     		$$.SetSize($4);
     		$$.SetResolution($5);
     		if ($6) {
     		  $$.SetFixed();
     		}
          };

timestamp_fixed: %empty { $$ = false; }
                 | TIMESTAMP_FIXED {$$ = true;};

core_load_max: BLOCK_BEGIN CORE_LOAD_MAX
		UINT FLOAT
	       BLOCK_END CORE_LOAD_MAX {
	       	$$.number = static_cast<uint16_t>($3);
	       	$$.max = static_cast<float>($4);
	       };

daq_memory_consumption: BLOCK_BEGIN DAQ_MEMORY_CONSUMPTION
                            UINT UINT UINT UINT UINT UINT buffer_reserve
                        BLOCK_END DAQ_MEMORY_CONSUMPTION {
              $$.limit = static_cast<uint32_t>($3);
              $$.daq_size = static_cast<uint16_t>($4);
              $$.odt_size = static_cast<uint16_t>($5);
              $$.odt_entry_size = static_cast<uint16_t>($6);
              $$.odt_daq_buffer_element_size = static_cast<uint16_t>($7);
              $$.odt_stim_buffer_element_size = static_cast<uint16_t>($8);
              $$.dto_stim_size = $9;
           };

buffer_reserve: %empty { $$.reset(); }
           | BLOCK_BEGIN BUFFER_RESERVE
		UINT UINT
	     BLOCK_END BUFFER_RESERVE {
	     BufferReserve buffer;
	     buffer.odt_daq_buffer = static_cast<uint8_t>($3);
	     buffer.odt_stim_buffer = static_cast<uint8_t>($4);
	     $$ = buffer;
	   };

daq_list: BLOCK_BEGIN DAQ_LIST
            UINT daq_list_optionals
          BLOCK_END DAQ_LIST {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetNumber($3);
	   	$$ = std::move(list);
	   	list.Reset();
          };

daq_list_optionals: %empty
                    | daq_list_optionals daq_list_optional;

daq_list_optional: DAQ_LIST_TYPE daq_list_type {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetType($2);
           } | MAX_ODT UINT {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdt($2);
	   } | MAX_ODT_ENTRIES UINT {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetMaxOdtEntries($2);
	   } | FIRST_PID UINT {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetFirstPid($2);
	   } | EVENT_FIXED UINT {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetEventFixed($2);
	   } | DAQ_PACKED_MODE_SUPPORTED {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetDaqPackedModeSupported();
	   } | BLOCK_BEGIN PREDEFINED
		odt_list
	     BLOCK_END PREDEFINED {
	   	DaqList& list = scanner.GetDaqList();
	   	list.SetPredefinedList(std::move($3));
	   };

odt_list: %empty { $$ = {}; }
          | odt_list odt {
     	$$ = std::move($1);
     	$$.emplace_back(std::move($2));
     };

odt: BLOCK_BEGIN ODT
	UINT odt_entry_list
     BLOCK_END ODT {
     	$$.number = $3;
     	$$.odt_entry_list = std::move($4);
     };

odt_entry_list: %empty { $$ = {}; }
                | odt_entry_list odt_entry {
         	$$ = std::move($1);
         	$$.emplace_back(std::move($2));
         };

odt_entry: ODT_ENTRY UINT UINT UINT UINT UINT {
		$$.number = static_cast<uint8_t>($2);
		$$.address = $3;
		$$.address_extension = static_cast<uint8_t>($4);
		$$.size = static_cast<uint8_t>($5);
		$$.bit_offset = static_cast<uint8_t>($6);
	};

d_event: BLOCK_BEGIN EVENT
         ident_or_string ident_or_string UINT daq_list_type UINT UINT UINT UINT d_event_optionals
       BLOCK_END EVENT {
		Event& event = scanner.GetEvent();
                event.SetName($3);
                event.SetShortName($4);
                event.SetNumber($5);
                event.SetType($6);
                event.SetMaxDaqList($7);
                event.SetTimeCycle($8);
                event.SetTimeUnit($9);
                event.SetPriority($10);
                $$ = std::move(event);
                event.Reset();
       };
d_event_optionals: %empty
                 | d_event_optionals d_event_optional;
d_event_optional: COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER UINT {
		Event& event = scanner.GetEvent();
                event.SetComplementaryBypassNumber($2);
        } | CONSISTENCY consistency {
		Event& event = scanner.GetEvent();
                event.SetConsistency($2);
	} | EVENT_COUNTER_PRESENT {
		Event& event = scanner.GetEvent();
                event.SetEventCounterPresent();
	} | RELATED_EVENT_CHANNEL_NUMBER UINT {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumber($2);
	} | RELATED_EVENT_CHANNEL_NUMBER_FIXED {
		Event& event = scanner.GetEvent();
                event.SetRelatedNumberFixed();
	} | DTO_CTR_DAQ_MODE IDENT {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqMode($2);
	} | DTO_CTR_DAQ_MODE_FIXED {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrDaqModeFixed();
	} | DTO_CTR_STIM_MODE IDENT {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimMode($2);
	} | DTO_CTR_STIM_MODE_FIXED {
		Event& event = scanner.GetEvent();
                event.SetDtoCtrStimModeFixed();
	} | STIM_DTO_CTR_COPY_PRESENT {
		Event& event = scanner.GetEvent();
                event.SetStimDtoCtrCopyPresent();
	} | daq_packed_mode {
		Event& event = scanner.GetEvent();
                event.SetDaqPackedMode(std::move($1));
	} | MIN_CYCLE_TIME UINT UINT {
		MinCycleTime cycle;
		cycle.time_cycle = static_cast<uint8_t>($2);
		cycle.time_unit = static_cast<uint8_t>($3);
		Event& event = scanner.GetEvent();
                event.SetMinCycleTime(std::move(cycle));
	} | BUFFER_RESERVE_EVENT UINT UINT {
		BufferReserveEvent buffer;
		buffer.odt_daq_buffer_element_reserve = static_cast<uint8_t>($2);
		buffer.odt_stim_buffer_element_reserve = static_cast<uint8_t>($3);
		Event& event = scanner.GetEvent();
                event.SetBufferReserveEvent(std::move(buffer));
	} | CPU_LOAD_MAX FLOAT {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadMax($2);
	} | cpu_load_consumption_daq {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionDaq(std::move($1));
	} | cpu_load_consumption_stim {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionStim(std::move($1));
	} | cpu_load_consumption_queue {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueue(std::move($1));
	} | cpu_load_consumption_queue_stim {
		Event& event = scanner.GetEvent();
		event.SetCpuLoadConsumptionQueueStim(std::move($1));
	};

daq_packed_mode: BLOCK_BEGIN DAQ_PACKED_MODE
                    IDENT IDENT IDENT UINT alt_sample_count_list
                 BLOCK_END DAQ_PACKED_MODE {
          	$$.SetGroup($3);
          	$$.SetTimestampMode($4);
          	$$.SetUsage($5);
          	$$.sample_count = static_cast<uint16_t>($6);
          	$$.alt_sample_count = std::move($7);
          };

alt_sample_count_list: %empty { $$ = {};}
                       | alt_sample_count_list alt_sample_count {
                       	$$ = std::move($1);
                       	$$.push_back(static_cast<uint16_t>($2));
                       };

alt_sample_count: ALT_SAMPLE_COUNT UINT { $$ = $2;};

cpu_load_consumption_daq: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_DAQ
                            FLOAT FLOAT FLOAT cpu_load_consumption_daq_options
                          BLOCK_END CPU_LOAD_CONSUMPTION_DAQ {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>($3);
               	cpu_load.odt_factor = static_cast<float>($4);
               	cpu_load.odt_entry_factor = static_cast<float>($5);
               	$$ = std::move(cpu_load);
               	cpu_load.Reset();
           };

cpu_load_consumption_daq_options: cpu_load_consumption_daq_option
                              | cpu_load_consumption_daq_options cpu_load_consumption_daq_option;

cpu_load_consumption_daq_option: odt_entry_size_factor_table {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back($1);
	   } | core_load_ep {
 		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
 		cpu_load.core_load_ep = $1;
           };

cpu_load_consumption_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_STIM
                            FLOAT FLOAT FLOAT cpu_load_consumption_stim_options
                          BLOCK_END CPU_LOAD_CONSUMPTION_STIM {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.daq_factor = static_cast<float>($3);
               	cpu_load.odt_factor = static_cast<float>($4);
               	cpu_load.odt_entry_factor = static_cast<float>($5);
               	$$ = std::move(cpu_load);
               	cpu_load.Reset();
           };

cpu_load_consumption_stim_options: cpu_load_consumption_stim_option
                              | cpu_load_consumption_stim_options cpu_load_consumption_stim_option;

cpu_load_consumption_stim_option: odt_entry_size_factor_table {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.odt_entry_size_factors.push_back($1);
	  } | core_load_ep {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = $1;
          };

odt_entry_size_factor_table: BLOCK_BEGIN ODT_ENTRY_SIZE_FACTOR_TABLE
                               UINT FLOAT
                             BLOCK_END ODT_ENTRY_SIZE_FACTOR_TABLE {
         	$$.size = static_cast<uint16_t>($3);
         	$$.factor = static_cast<float>($4);
         };

cpu_load_consumption_queue: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE
                            FLOAT FLOAT cpu_load_consumption_queue_option
                          BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>($3);
               	cpu_load.odt_element_load = static_cast<float>($4);
               	$$ = std::move(cpu_load);
               	cpu_load.Reset();
         };

cpu_load_consumption_queue_option: %empty
                              | core_load_ep {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = $1;
          };

cpu_load_consumption_queue_stim: BLOCK_BEGIN CPU_LOAD_CONSUMPTION_QUEUE_STIM
                            FLOAT FLOAT cpu_load_consumption_queue_stim_option
                          BLOCK_END CPU_LOAD_CONSUMPTION_QUEUE {
               	CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
               	cpu_load.odt_factor = static_cast<float>($3);
               	cpu_load.odt_element_load = static_cast<float>($4);
               	$$ = std::move(cpu_load);
               	cpu_load.Reset();
         };

cpu_load_consumption_queue_stim_option: %empty
         | core_load_ep {
		CpuLoadConsumption& cpu_load = scanner.GetCpuLoadConsumption();
		cpu_load.core_load_ep = $1;
	};

core_load_ep: BLOCK_BEGIN CORE_LOAD_EP
                UINT FLOAT
              BLOCK_END CORE_LOAD_EP {
              $$.number = $3;
              $$.max = $4;
              };

daq_event: BLOCK_BEGIN DAQ_EVENT
             daq_event_union
           BLOCK_END DAQ_EVENT {
       		DaqEvent& event_list = scanner.GetDaqEvent();
       		$$ = std::move(event_list);
       		event_list.Reset();
           };

daq_event_union: fixed_event_list
                 | variable;

fixed_event_list: FIXED_EVENT_LIST event_list {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetFixedEventList($2);
	};

variable: VARIABLE variable_options;
variable_options: %empty
                  | variable_options variable_option;

variable_option: BLOCK_BEGIN AVAILABLE_EVENT_LIST
		event_list
		 BLOCK_END AVAILABLE_EVENT_LIST {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetVariableEventList($3);
      } | BLOCK_BEGIN DEFAULT_EVENT_LIST
      		event_list
      	  BLOCK_END DEFAULT_EVENT_LIST {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetDefaultEventList($3);
      } | BLOCK_BEGIN CONSISTENCY_EVENT_LIST
           event_list
          BLOCK_END CONSISTENCY_EVENT_LIST {
      	DaqEvent& event_list = scanner.GetDaqEvent();
      	event_list.SetConsistencyEventList($3);
      };

pag: BLOCK_BEGIN PAG UINT freeze_supported BLOCK_END PAG {
     	Pag& pag = scanner.GetPag();
     	pag.SetMaxSegments($3);
     	$$ = std::move(pag);
     	pag.Reset();
     };

freeze_supported: %empty
                | FREEZE_SUPPORTED {
     	Pag& pag = scanner.GetPag();
     	pag.SetFreezeSupported();
     };

pgm: BLOCK_BEGIN PGM
       IDENT UINT UINT pgm_options
     BLOCK_END PGM {
     	Pgm& pgm = scanner.GetPgm();
     	pgm.SetType($3);
     	pgm.SetMaxSectors($4);
     	pgm.SetMaxCtoPgm($5);
     	$$ = std::move(pgm);
     	pgm.Reset();
     };

pgm_options: %empty
             | pgm_options pgm_option;

pgm_option: sector {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.AddSector(std::move($1));
      } | communication_mode_supported {
      	Pgm& pgm = scanner.GetPgm();
      	pgm.SetCommunicationModeSupported($1);
      };

communication_mode_supported: COMMUNICATION_MODE_SUPPORTED communication_mode_union {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	$$ = std::move(mode);
             	mode.Reset();
             } | BLOCK_BEGIN COMMUNICATION_MODE_SUPPORTED
                 communication_mode_union
             BLOCK_END COMMUNICATION_MODE_SUPPORTED {
             	CommunicationMode& mode = scanner.GetCommunicationMode();
             	$$ = std::move(mode);
             	mode.Reset();
             };

 communication_mode_union: BLOCK block_struct
            | BLOCK_BEGIN BLOCK
                block_struct
              BLOCK_END BLOCK
            | INTERLEAVED UINT {
        	CommunicationMode& mode = scanner.GetCommunicationMode();
        	mode.SetInterleavedSupported();
        	mode.SetQueueSize($2);
            };

block_struct: slave_item master_item;
slave_item: %empty
            | SLAVE {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetSlaveModeSupported();
            };
master_item: %empty
            | MASTER UINT UINT {
       		CommunicationMode& mode = scanner.GetCommunicationMode();
       		mode.SetMasterModeSupported();
       		mode.SetMaxBsPgm($2);
       		mode.SetMinStPgm($3);
            };

sector: BLOCK_BEGIN SECTOR
          STRING UINT UINT UINT UINT UINT UINT
        BLOCK_END SECTOR {
        	$$.name = std::move($3);
        	$$.number = static_cast<uint8_t>($4);
        	$$.address = static_cast<uint32_t>($5);
        	$$.length = static_cast<uint32_t>($6);
        	$$.clear_sequence_number = static_cast<uint8_t>($7);
        	$$.program_sequence_number = static_cast<uint8_t>($8);
        	$$.program_method = static_cast<uint8_t>($9);
        };

segment: BLOCK_BEGIN SEGMENT
           UINT UINT UINT UINT UINT segment_options
         BLOCK_END SEGMENT {
      	Segment& segment = scanner.GetSegment();
      	segment.SetNumber($3);
      	segment.SetNumberOfPages($4);
      	segment.SetAddressExtension($5);
      	segment.SetCompressionMethod($6);
      	segment.SetEncryptionMethod($7);
      	$$ = std::move(segment);
      	segment.Reset();
      };

segment_options: %empty
                 | segment_options segment_option;

segment_option: checksum
      | DEFAULT_PAGE_NUMBER UINT {
        Segment& segment = scanner.GetSegment();
        segment.SetDefaultPageNumber($2);
      } | page
      | address_mapping {
      	Segment& segment = scanner.GetSegment();
      	segment.AddAddressMapping(std::move($1));
      };

checksum: BLOCK_BEGIN CHECKSUM
            IDENT checksum_options
          BLOCK_END CHECKSUM {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.SetType($3);
      	Segment& segment = scanner.GetSegment();
      	segment.SetChecksum(std::move(checksum));
      	checksum.Reset();
      };

checksum_options: %empty
                  | checksum_options checksum_option;

checksum_option: MAX_BLOCK_SIZE UINT {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.max_block_size = static_cast<uint32_t>($2);
      } | EXTERNAL_FUNCTION STRING {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.external_function = std::move($2);
      } | MTA_BLOCK_SIZE_ALIGN UINT {
      	Checksum& checksum = scanner.GetChecksum();
      	checksum.mta_block_size_align =	static_cast<uint16_t>($2);
      };

page: BLOCK_BEGIN PAGE
        UINT IDENT IDENT IDENT init_segment
      BLOCK_END PAGE {
      	Page& page = scanner.GetPage();
      	page.SetNumber($3);
      	page.SetEcuAccessType($4);
      	page.SetReadAccessType($5);
      	page.SetWriteAccessType($6);
      	Segment& segment = scanner.GetSegment();
      	segment.AddPage(std::move(page));
      	page.Reset();
      };

address_mapping: BLOCK_BEGIN ADDRESS_MAPPING
                   UINT UINT UINT
                 BLOCK_END ADDRESS_MAPPING {
      	$$.source_address = static_cast<uint32_t>($3);
      	$$.destination_address = static_cast<uint32_t>($4);
      	$$.length = static_cast<uint32_t>($5);
      };

init_segment: %empty
             | INIT_SEGMENT UINT {
      	Page& page = scanner.GetPage();
      	page.SetInitSegment($2);
      };

time_correlation: BLOCK_BEGIN TIME_CORRELATION
                    IDENT clock_list
                  BLOCK_END TIME_CORRELATION {
 		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
 		correlation.SetTimestampsRelateTo($3);
		$$ = std::move(correlation);
 		correlation.Reset();
        };

clock_list: %empty
            | clock_list clock;

clock: BLOCK_BEGIN CLOCK
         INT INT INT INT INT INT INT INT
         IDENT IDENT IDENT UINT timestamp_characterization UINT IDENT
       BLOCK_END CLOCK {
       		Clock& clock = scanner.GetClock();
		clock.SetUuid($3, 0);
		clock.SetUuid($4, 1);
		clock.SetUuid($5, 2);
		clock.SetUuid($6, 3);
		clock.SetUuid($7, 4);
		clock.SetUuid($8, 5);
		clock.SetUuid($9, 6);
		clock.SetUuid($10, 7);
		clock.SetType($11);
		clock.SetReadability($12);
		clock.SetSynchronization($13);
		clock.SetClockQuality($14);
		clock.SetMaxTimestampValueBeforeWrapAround($16);
		clock.SetEpoch($17);
		TimeCorrelation& correlation = scanner.GetTimeCorrelation();
		correlation.AddClock(std::move(clock));
		clock.Reset();
       };

timestamp_characterization: %empty
               | BLOCK_BEGIN TIME_CHARACTERIZATION
                   UINT IDENT IDENT
                 BLOCK_END TIME_CHARACTERIZATION {
                TimestampCharacteristic characteristic;
                characteristic.SetTicks($3);
                characteristic.SetResolution($4);
                characteristic.SetSize($5);
       		Clock& clock = scanner.GetClock();
       		clock.SetCharacteristic(std::move(characteristic));
        };

event_list: %empty { $$.clear(); }
            | event_list event {
            $$ = std::move($1);
            $$.push_back($2);
            };
event: EVENT UINT { $$ = $2; };

xcp_on_can: BLOCK_BEGIN XCP_ON_CAN
              UINT can_parameter_options transport_layer_instance
            BLOCK_END XCP_ON_CAN {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetVersion($3);
		can.SetTransportLayerInstance($5);
		scanner.SaveXcpOnCan();
       };

can_parameter_options: %empty
                       | can_parameter_options can_parameter_option;

can_parameter_option: CAN_ID_BROADCAST UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdBroadcast($2);
        } | CAN_ID_MASTER UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMaster($2);
        } | CAN_ID_MASTER_INCREMENTAL {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdMasterIncremental();
        } | CAN_ID_SLAVE UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdSlave($2);
        } | CAN_ID_GET_DAQ_CLOCK_MULTICAST UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetCanIdGetDaqClockMulticast($2);
        } | BAUDRATE UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBaudrate($2);
        } | SAMPLE_POINT UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSamplePoint($2);
        } | SAMPLE_RATE IDENT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSampleRate($2);
        } | BTL_CYCLES UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetBtlCycles($2);
        } | SJW UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSjw($2);
        } | SYNC_EDGE IDENT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetSyncEdge($2);
        } | MAX_DLC_REQUIRED {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxDlcRequired();
        } | daq_list_can_id
        | event_can_id_list
        | MAX_BUS_LOAD UINT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMaxBusLoad($2);
        }
        | MEASUREMENT_SPLIT_ALLOWED {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetMeasurementSplitAllowed();
        } | can_fd
        | OPTIONAL_TL_SUBCMD IDENT {
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.AddSubCmd($2);
        } | common_parameter {
		CommonParameters& common_parameters = scanner.GetCommonParameters();
		XcpOnCan& can = scanner.GetXcpOnCan();
		can.SetOverrulingParameters(common_parameters);
		common_parameters.Reset();
        };

daq_list_can_id: BLOCK_BEGIN DAQ_LIST_CAN_ID
                   UINT daq_list_can_id_options
                 BLOCK_END DAQ_LIST_CAN_ID {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddDaqList();
        };

daq_list_can_id_options: %empty
                         | daq_list_can_id_options daq_list_can_id_option;

daq_list_can_id_option: VARIABLE {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.variable = true;
        } | fixed {
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   DaqListCanId& daq_list = can.GetCurrentDaqList();
	   daq_list.fixed = static_cast<uint32_t>($1);
        };

event_can_id_list: BLOCK_BEGIN EVENT_CAN_ID_LIST
                     UINT fixed_list
                   BLOCK_END EVENT_CAN_ID_LIST {
	   EventCanIdList list;
	   list.number = static_cast<uint16_t>($3);
	   list.fixed_list = std::move($4);
	   XcpOnCan& can = scanner.GetXcpOnCan();
	   can.AddCanIdEventList(list);
        };

fixed_list: %empty { $$ = {};}
       | fixed_list fixed {
       	$$ = std::move($1);
       	$$.push_back($2);
       };
fixed: FIXED UINT { $$ = static_cast<uint32_t>($2); };

can_fd: BLOCK_BEGIN CAN_FD
          can_fd_options
        BLOCK_END CAN_FD {
      	XcpOnCan& can = scanner.GetXcpOnCan();
      	can.SetCanFd();
     };

can_fd_options: %empty
                | can_fd_options can_fd_option;

can_fd_option: MAX_DLC UINT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc = static_cast<uint16_t>($2);
     } | CAN_FD_DATA_TRANSFER_BAUDRATE UINT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.baudrate = static_cast<uint32_t>($2);
     } | SAMPLE_POINT UINT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sample_point = static_cast<uint8_t>($2);
     } | BTL_CYCLES UINT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.btl_cycles = static_cast<uint8_t>($2);
     } | SJW UINT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.sjw = static_cast<uint8_t>($2);
     } | SYNC_EDGE IDENT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetSyncEdge($2);
     } | MAX_DLC_REQUIRED {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.max_dlc_required = true;
     } | SECONDARY_SAMPLE_POINT UINT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.secondary_sample_point = static_cast<uint8_t>($2);
     } | TRANSCEIVER_DELAY_COMPENSATION IDENT {
     	XcpOnCan& can = scanner.GetXcpOnCan();
     	CanFd& can_fd = can.GetCurrentFd();
     	can_fd.SetTransceiverDelayCompensation($2);
     };

xcp_on_sxi: BLOCK_BEGIN XCP_ON_SxI
              UINT UINT sxi_parameter_options IDENT IDENT sxi_option transport_layer_instance
            BLOCK_END XCP_ON_SxI {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetVersion($3);
               sxi.SetBaudrate($4);
               sxi.SetHeaderLength($6);
               sxi.SetChecksum($7);
               sxi.SetTransportLayerInstance($9);
               scanner.SaveXcpOnSxi();
            };

sxi_parameter_options: %empty
                       | sxi_parameter_options sxi_parameter_option;

sxi_parameter_option: ASYNCH_FULL_DUPLEX_MODE IDENT IDENT framing {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               AsynchFullDuplexMode& asynch = sxi.GetAsynch();
               asynch.SetParity($2);
               asynch.SetStopBits($3);
               sxi.SetAsynchFullDuplexMode();
	    } | SYNCH_FULL_DUPLEX_MODE_BYTE {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeByte();
            } | SYNCH_FULL_DUPLEX_MODE_WORD {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeWord();
            } | SYNCH_FULL_DUPLEX_MODE_DWORD {
               XcpOnSxi& sxi = scanner.GetXcpOnSxi();
               sxi.SetSynchFullDuplexModeDword();
            } | SYNCH_FULL_MASTER_MODE_BYTE {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeByte();
            } | SYNCH_FULL_MASTER_MODE_WORD {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeWord();
            } | SYNCH_FULL_MASTER_MODE_DWORD {
              XcpOnSxi& sxi = scanner.GetXcpOnSxi();
              sxi.SetSynchMasterSlaveModeDword();
            };

sxi_option: %empty
            | common_parameter {
           CommonParameters& common_parameters = scanner.GetCommonParameters();
           XcpOnSxi& sxi = scanner.GetXcpOnSxi();
           sxi.SetOverrulingParameters(common_parameters);
           common_parameters.Reset();
         };

framing: %empty
         | BLOCK_BEGIN FRAMING
             UINT UINT
           BLOCK_END FRAMING {
             XcpOnSxi& sxi = scanner.GetXcpOnSxi();
             Framing& framing = sxi.GetFraming();
             framing.sync = static_cast<uint8_t>($3);
             sxi.SetFraming();
           };

xcp_on_tcp_ip: BLOCK_BEGIN XCP_ON_TCP_IP
                 UINT UINT tcp_ip_options transport_layer_instance
               BLOCK_END XCP_ON_TCP_IP {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetVersion($3);
               tcp.SetPort($4);
               tcp.SetTransportLayerInstance($6);
               scanner.SaveXcpOnTcpIp();
            };

tcp_ip_options: %empty
                | tcp_ip_options tcp_ip_option;

tcp_ip_option: HOST_NAME STRING {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetHostName($2);
	     } | ADDRESS STRING {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetAddress($2);
	     } | IPV6 STRING {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetIpv6($2);
	     } | MAX_BUS_LOAD UINT {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBusLoad($2);
	     } | MAX_BIT_RATE UINT {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetMaxBitRate($2);
	     } | PACKET_ALIGNMENT IDENT {
               XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
               tcp.SetPacketAlignment($2);
	     } | OPTIONAL_TL_SUBCMD IDENT {
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.AddTcpSubCmd($2);
	     } | common_parameter {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnTcpIp& tcp = scanner.GetXcpOnTcpIp();
              tcp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
	     };

xcp_on_udp_ip: BLOCK_BEGIN XCP_ON_UDP_IP
                 UINT UINT udp_ip_options transport_layer_instance
               BLOCK_END XCP_ON_UDP_IP {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetVersion($3);
               udp.SetPort($4);
               udp.SetTransportLayerInstance($6);
               scanner.SaveXcpOnUdpIp();
             };

udp_ip_options: %empty
                | udp_ip_options udp_ip_option;

udp_ip_option: HOST_NAME STRING {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetHostName($2);
	    } | ADDRESS STRING {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetAddress($2);
            } | IPV6 STRING {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetIpv6($2);
            } | MAX_BUS_LOAD UINT {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBusLoad($2);
            } | MAX_BIT_RATE UINT {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetMaxBitRate($2);
            } | PACKET_ALIGNMENT IDENT {
               XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
               udp.SetPacketAlignment($2);
            } | OPTIONAL_TL_SUBCMD IDENT {
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.AddUdpSubCmd($2);
            } | common_parameter {
              CommonParameters& common_parameters = scanner.GetCommonParameters();
              XcpOnUdpIp& udp = scanner.GetXcpOnUdpIp();
              udp.SetOverrulingParameters(common_parameters);
              common_parameters.Reset();
            };

xcp_on_usb: BLOCK_BEGIN XCP_ON_USB
              UINT UINT UINT UINT IDENT usb_options transport_layer_instance
            BLOCK_END XCP_ON_USB {
                XcpOnUsb& usb = scanner.GetXcpOnUsb();
                usb.SetVersion($3);
                usb.SetVendorId($4);
                usb.SetProductId($5);
                usb.SetNumberOfInterfaces($6);
                usb.SetHeaderLength($7);
                usb.SetTransportLayerInstance($9);
            	scanner.SaveXcpOnUsb();
            };

usb_options: %empty
             | usb_options usb_option;

usb_option: BLOCK_BEGIN OUT_EP_CMD_STIM
             ep_parameters
            BLOCK_END OUT_EP_CMD_STIM {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetOutEpCmdStim();
            } | BLOCK_BEGIN IN_EP_RESERR_DAQ_EVSERV
                ep_parameters
              BLOCK_END IN_EP_RESERR_DAQ_EVSERV {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.SetInEpReserrDaqEvserv();
            } | ALTERNATE_SETTING_NO UINT {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetAlternateSettingNo($2);
            } | INTERFACE_STRING_DESCRIPTOR STRING {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
              	usb.SetInterfaceStringDescriptor($2);
            } | BLOCK_BEGIN OUT_EP_ONLY_STIM
                ep_parameters
              BLOCK_END OUT_EP_ONLY_STIM {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddOutEpOnlyStim();
            } | BLOCK_BEGIN IN_EP_ONLY_DAQ
                ep_parameters
              BLOCK_END IN_EP_ONLY_DAQ {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddInEpOnlyDaq();
            } | BLOCK_BEGIN IN_EP_ONLY_EVSERV
                ep_parameters
              BLOCK_END IN_EP_ONLY_EVSERV {
              	XcpOnUsb& usb = scanner.GetXcpOnUsb();
               	usb.AddDaqListUsbEndpoint();
            } | daq_list_usb_endpoint {
            	XcpOnUsb& usb = scanner.GetXcpOnUsb();
            	usb.AddDaqListUsbEndpoint();
            } | OPTIONAL_TL_SUBCMD IDENT {
  		XcpOnUsb& usb = scanner.GetXcpOnUsb();
  		usb.AddUsbSubCmd($2);
            } | common_parameter {
               CommonParameters& common_parameters = scanner.GetCommonParameters();
               XcpOnUsb& usb = scanner.GetXcpOnUsb();
               usb.SetOverrulingParameters(common_parameters);
               common_parameters.Reset();
          };

daq_list_usb_endpoint: BLOCK_BEGIN DAQ_LIST_USB_ENDPOINT
                         UINT fixed_in fixed_out
                       BLOCK_END DAQ_LIST_USB_ENDPOINT {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.number = $3;
          };
fixed_in: %empty
          | FIXED_IN UINT {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_in = static_cast<uint8_t>($2);
          };
fixed_out: %empty
          | FIXED_OUT UINT {
          XcpOnUsb& usb = scanner.GetXcpOnUsb();
          DaqListUsbEndpoint& endpoint = usb.GetDaqListUsbEndpoint();
          endpoint.fixed_out = static_cast<uint8_t>($2);
          };
ep_parameters: UINT IDENT UINT UINT IDENT IDENT recommended_host_bufsize {
	XcpOnUsb& usb = scanner.GetXcpOnUsb();
        EpParameters& ep_par = usb.GetEpParameters();
        ep_par.SetEndpointNumber($1);
        ep_par.SetTransferType($2);
        ep_par.SetMaxPacketSize($3);
        ep_par.SetInterval($4);
        ep_par.SetMessagePacking($5);
        ep_par.SetUsbAlignment($6);
	};
recommended_host_bufsize: %empty
           | RECOMMENDED_HOST_BUFSIZE UINT {

           } ;

xcp_on_flx: BLOCK_BEGIN XCP_ON_FLX
              UINT UINT STRING STRING UINT IDENT IDENT flx_options transport_layer_instance
            BLOCK_END XCP_ON_FLX {
              XcpOnFlx& flx = scanner.GetXcpOnFlx();
              flx.SetVersion($3);
              flx.SetT1Flx($4);
              flx.SetFibexFile($5);
              flx.SetClusterId($6);
              flx.SetNax($7);
              flx.SetHeaderNax($8);
              flx.SetPacketAlignment($9);
              flx.SetTransportLayerInstance($11);
              scanner.SaveXcpOnFlx();
              flx.Reset();
        };

flx_options: %empty
             | flx_options flx_option;
flx_option: BLOCK_BEGIN INITIAL_CMD_BUFFER
              buffer
            BLOCK_END INITIAL_CMD_BUFFER {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.SetInitialCmdBuffer(buffer);
            buffer.Reset();
       	  } | BLOCK_BEGIN INITIAL_RES_ERR_BUFFER
                buffer
              BLOCK_END INITIAL_RES_ERR_BUFFER {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.SetInitialResErrBuffer(buffer);
            buffer.Reset();
          } | BLOCK_BEGIN POOL_BUFFER
                buffer
              BLOCK_END POOL_BUFFER {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            FlxBuffer& buffer = flx.GetFlxBuffer();
            flx.AddPoolBuffer(buffer);
            buffer.Reset();
          } | OPTIONAL_TL_SUBCMD IDENT {
            XcpOnFlx& flx = scanner.GetXcpOnFlx();
            flx.AddFlxSubCmd($2);
          } | common_parameter {
            CommonParameters& common_parameters = scanner.GetCommonParameters();
            scanner.GetXcpOnFlx().SetOverrulingParameters(common_parameters);
            common_parameters.Reset();
         };

buffer: UINT buffer_options {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  buffer.SetBufferNo($1);
	};
buffer_options: %empty
                | buffer_options buffer_option;
buffer_option: MAX_FLX_LEN_BUF max_flx_len_buf_union {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetMaxFlxLenBuffer(var_fixed);
	  var_fixed.Reset();
	}
               | lpu_id
               | xcp_packet;
max_flx_len_buf_union: FIXED UINT {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = $2;
	} | VARIABLE UINT {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = $2;
	};
lpu_id: BLOCK_BEGIN LPU_ID
          lpu_id_options
        BLOCK_END LPU_ID;

lpu_id_options: %empty
                | lpu_id_options lpu_id_option;
lpu_id_option: flx_slot_id_union
               | offset_union
               | cycle_repetition
               | channel;
flx_slot_id_union: FLX_SLOT_ID lpu_id_union {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetFlxSlotId(var_fixed);
	  var_fixed.Reset();
	};
offset_union: OFFSET lpu_id_option {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetOffset(var_fixed);
	  var_fixed.Reset();
	};
cycle_repetition: CYCLE_REPETITION lpu_id_union {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetCycleRepetition(var_fixed);
	  var_fixed.Reset();
	};
channel: CHANNEL channel_union {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  buffer.SetChannel(var_fixed);
	  var_fixed.Reset();
	};
channel_union: FIXED IDENT {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel($2);
	  var_fixed.fixed = static_cast<uint64_t>(
               	var_fixed.initial_channel.value_or(FlxChannel::A));
	} | VARIABLE initial_enum {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = static_cast<uint64_t>(
	  	var_fixed.initial_channel.value_or(FlxChannel::A));
	};
initial_enum: %empty { $$ = false; }
        | INITIAL_VALUE IDENT {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.InitialChannel($2);
	  $$ = true;
        };

lpu_id_union: FIXED UINT {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.fixed = $2;
	} | VARIABLE initial_value {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.variable = var_fixed.initial_value.value_or(0);
	};
initial_value: %empty { $$ = false;}
       | INITIAL_VALUE UINT {
	  XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  FlxBuffer& buffer = flx.GetFlxBuffer();
	  FlxVariableFixed& var_fixed = buffer.GetVariableFixed();
	  var_fixed.initial_value = $2;
	  $$ = true;
       };

xcp_packet: BLOCK_BEGIN XCP_PACKET
              xcp_packet_options
            BLOCK_END XCP_PACKET;

xcp_packet_options: %empty
             | xcp_packet_options xcp_packet_option;

xcp_packet_option: CMD IDENT {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetCmd($2);
 	} | RES_ERR IDENT {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetResErr($2);
 	} | EV_SERV IDENT {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetEvServ($2);
 	} | DAQ IDENT {
	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
	  	FlxBuffer& buffer = flx.GetFlxBuffer();
	  	buffer.SetDaq($2);
 	} | STIM IDENT {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
 	  	FlxBuffer& buffer = flx.GetFlxBuffer();
 	  	buffer.SetStim($2);
 	} | MULTICAST IDENT {
 	  	XcpOnFlx& flx = scanner.GetXcpOnFlx();
  	  	FlxBuffer& buffer = flx.GetFlxBuffer();
  	  	buffer.SetMulticast($2);
 	};

xcp_on_simulink: BLOCK_BEGIN XCP_ON_SIMULINK
                   simulink_options transport_layer_instance
                 BLOCK_END XCP_ON_SIMULINK {
                   XcpOnSimulink& simulink = scanner.GetXcpOnSimulink();
                   simulink.SetTransportLayerInstance($4);
                   scanner.SaveXcpOnSimulink();
                 };

simulink_options: %empty
                  | simulink_options simulink_option;

simulink_option: MODEL_NAME STRING {
		   scanner.GetXcpOnSimulink().SetModelName($2);
		 } | common_parameter {
                    CommonParameters& common_parameters = scanner.GetCommonParameters();
                    scanner.GetXcpOnSimulink().SetOverrulingParameters(common_parameters);
                 };

consistency: DAQ { $$ = "DAQ"; }
             | EVENT { $$ = "EVENT"; }
             | ODT { $$ = "ODT"; }
             | NONE { $$ = "NONE"; };

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
