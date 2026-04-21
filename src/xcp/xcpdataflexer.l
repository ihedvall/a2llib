%top {
    #include <cstdint>
    #include <cctype>

}
%{
    #include "xcpdatascanner.h"
    #undef  YY_DECL
    #define YY_DECL int a2l::xcp::XcpDataScanner::xcplex(a2l::xcp::XcpDataParser::value_type* yy_value)
    using token = a2l::xcp::XcpDataParser::token;
%}

%option prefix="xcp"
%option 8bit
%option nounistd
%option noyywrap
%option debug
%option never-interactive
%option c++
%option yyclass="a2l::xcp::XcpDataScanner"
%option yylineno
%option noinput
%option nounput


ws              [ \t\n\v\f\r]+
signed_number   [-+]?[0-9]+
unsigned_number [0-9]+
hexnumber       0x[0-9a-fA-F]+
float_val       [-+]?[0-9]+(\.[0-9]*)?([eE][-+]?[0-9]+)?
ident           [a-zA-Z_]([_a-zA-Z0-9.-]*)?
string          (\"(\\.|[^\\"])*\")*
            /* \"([^\"\\]|(\\.))*\" */
nl              [\n\r]
keyword         [A-Z_0-9]+


%%
%{
            yylval = yy_value;
%}


"/begin"         { return token::BLOCK_BEGIN; }
"/end"           { return token::BLOCK_END; }

"ADDRESS" { return token::ADDRESS;}
"ADDRESS_MAPPING" { return token::ADDRESS_MAPPING;}
"ALT_SAMPLE_COUNT" { return token::ALT_SAMPLE_COUNT;}
"ALTERNATE_SETTING_NO" { return token::ALTERNATE_SETTING_NO;}

"ASYNCH_FULL_DUPLEX_MODE" { return token::ASYNCH_FULL_DUPLEX_MODE;}

"AVAILABLE_EVENT_LIST" { return token::AVAILABLE_EVENT_LIST;}
"BAUDRATE" { return token::BAUDRATE;}
"BIT_STIM_SUPPORTED" { return token::BIT_STIM_SUPPORTED;}
"BLOCK"          {return token::BLOCK; }
"BTL_CYCLES" { return token::BTL_CYCLES;}
"BUFFER_RESERVE" { return token::BUFFER_RESERVE;}
"BUFFER_RESERVE_EVENT" { return token::BUFFER_RESERVE_EVENT;}
"CAN_FD" { return token::CAN_FD;}
"CAN_FD_DATA_TRANSFER_BAUDRATE" { return token::CAN_FD_DATA_TRANSFER_BAUDRATE;}

"CAN_ID_BROADCAST" { return token::CAN_ID_BROADCAST;}
"CAN_ID_MASTER" { return token::CAN_ID_MASTER;}
"CAN_ID_MASTER_INCREMENTAL" { return token::CAN_ID_MASTER_INCREMENTAL;}
"CAN_ID_SLAVE" { return token::CAN_ID_SLAVE;}
"CAN_ID_GET_DAQ_CLOCK_MULTICAST" { return token::CAN_ID_GET_DAQ_CLOCK_MULTICAST;}
"CHANNEL" { return token::CHANNEL;}
"CHECKSUM" { return token::CHECKSUM;}
"CMD" { return token::CMD;}
"COMMUNICATION_MODE_SUPPORTED" { return token::COMMUNICATION_MODE_SUPPORTED;}
"COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER" { return token::COMPLEMENTARY_BY_PASS_EVENT_CHANNEL_NUMBER;}
"CONSISTENCY" { return token::CONSISTENCY;}
"CONSISTENCY_EVENT_LIST" { return token::CONSISTENCY_EVENT_LIST;}

"CORE_LOAD_MAX" { return token::CORE_LOAD_MAX;}
"CORE_LOAD_MAX_TOTAL" { return token::CORE_LOAD_MAX_TOTAL;}
"CORE_LOAD_EP" { return token::CORE_LOAD_EP;}
"CLOCK" { return token::CLOCK;}
"CYCLE_REPETITION" { return token::CYCLE_REPETITION;}
"CPU_LOAD_CONSUMPTION_DAQ" { return token::CPU_LOAD_CONSUMPTION_DAQ;}
"CPU_LOAD_CONSUMPTION_STIM" { return token::CPU_LOAD_CONSUMPTION_STIM;}
"CPU_LOAD_CONSUMPTION_QUEUE" { return token::CPU_LOAD_CONSUMPTION_QUEUE;}
"CPU_LOAD_CONSUMPTION_QUEUE_STIM" { return token::CPU_LOAD_CONSUMPTION_QUEUE_STIM;}
"CPU_LOAD_MAX" { return token::CPU_LOAD_MAX;}
"CPU_LOAD_MAX_TOTAL" { return token::CPU_LOAD_MAX_TOTAL;}
"DAQ"            { return token::DAQ; }
"DAQ_ALTERNATING_SUPPORTED" { return token::DAQ_ALTERNATING_SUPPORTED;}
"DAQ_EVENT" { return token::DAQ_EVENT;}
"DAQ_LIST" { return token::DAQ_LIST;}
"DAQ_LIST_CAN_ID" { return token::DAQ_LIST_CAN_ID;}
"DAQ_LIST_TYPE" { return token::DAQ_LIST_TYPE;}
"DAQ_LIST_USB_ENDPOINT" { return token::DAQ_LIST_USB_ENDPOINT;}
"DAQ_MEMORY_CONSUMPTION" { return token::DAQ_MEMORY_CONSUMPTION;}
"DAQ_PACKED_MODE" { return token::DAQ_PACKED_MODE;}
"DAQ_PACKED_MODE_SUPPORTED" { return token::DAQ_PACKED_MODE_SUPPORTED;}
"DAQ_STIM" { return token::DAQ_STIM;}
"DEFAULT_EVENT_LIST" { return token::DEFAULT_EVENT_LIST;}
"DEFAULT_PAGE_NUMBER" { return token::DEFAULT_PAGE_NUMBER;}
"DTO_CTR_DAQ_MODE" { return token::DTO_CTR_DAQ_MODE;}
"DTO_CTR_DAQ_MODE_FIXED" { return token::DTO_CTR_DAQ_MODE_FIXED;}
"DTO_CTR_FIELD_SUPPORTED" { return token::DTO_CTR_FIELD_SUPPORTED;}
"DTO_CTR_STIM_MODE" { return token::DTO_CTR_STIM_MODE;}
"DTO_CTR_STIM_MODE_FIXED" { return token::DTO_CTR_STIM_MODE_FIXED;}

"ECU_STATES"     { return token::ECU_STATES;}
"ECU_SWITCHED_TO_DEFAULT_PAGE" { return token::ECU_SWITCHED_TO_DEFAULT_PAGE;}
"EV_SERV" { return token::EV_SERV;}

"EVENT" { return token::EVENT;}
"EVENT_CAN_ID_LIST" { return token::EVENT_CAN_ID_LIST;}
"EVENT_COUNTER_PRESENT" { return token::EVENT_COUNTER_PRESENT;}
"EVENT_FIXED" { return token::EVENT_FIXED;}
"EXTERNAL_FUNCTION" { return token::EXTERNAL_FUNCTION;}
"FIRST_PID" { return token::FIRST_PID;}
"FIXED" { return token::FIXED;}
"FIXED_IN" { return token::FIXED_IN;}
"FIXED_OUT" { return token::FIXED_OUT;}
"FIXED_EVENT_LIST" { return token::FIXED_EVENT_LIST;}
"FLX_SLOT_ID" { return token::FLX_SLOT_ID;}
"FRAMING" { return token::FRAMING;}
"FREEZE_SUPPORTED" { return token::FREEZE_SUPPORTED;}
"HOST_NAME" { return token::HOST_NAME;}
"IF_DATA"        { return token::IF_DATA;}
"IN_EP_ONLY_DAQ" { return token::IN_EP_ONLY_DAQ;}
"IN_EP_ONLY_EVSERV" { return token::IN_EP_ONLY_EVSERV;}

"IN_EP_RESERR_DAQ_EVSERV" { return token::IN_EP_RESERR_DAQ_EVSERV;}
"INIT_SEGMENT" { return token::INIT_SEGMENT;}
"INITIAL_VALUE" { return token::INITIAL_VALUE;}
"INITIAL_CMD_BUFFER" { return token::INITIAL_CMD_BUFFER;}
"INITIAL_RES_ERR_BUFFER" { return token::INITIAL_RES_ERR_BUFFER;}
"INTERFACE_STRING_DESCRIPTOR" { return token::INTERFACE_STRING_DESCRIPTOR;}
"INTERLEAVED"    { return token::INTERLEAVED;}
"IPV6" { return token::IPV6;}
"LPU_ID" { return token::LPU_ID;}
"MASTER"         { return token::MASTER;}
"MAX_BIT_RATE" { return token::MAX_BIT_RATE;}
"MAX_BLOCK_SIZE" { return token::MAX_BLOCK_SIZE;}
"MAX_BUS_LOAD" { return token::MAX_BUS_LOAD;}
"MAX_DAQ_TOTAL" { return token::MAX_DAQ_TOTAL;}
"MAX_DLC" { return token::MAX_DLC;}
"MAX_DLC_REQUIRED" { return token::MAX_DLC_REQUIRED;}
"MAX_DTO_STIM" { return token::MAX_DTO_STIM;}
"MAX_FLX_LEN_BUF" { return token::MAX_FLX_LEN_BUF;}
"MAX_ODT" { return token::MAX_ODT;}
"MAX_ODT_DAQ_TOTAL" { return token::MAX_ODT_DAQ_TOTAL;}
"MAX_ODT_ENTRIES" { return token::MAX_ODT_ENTRIES;}
"MAX_ODT_ENTRIES_DAQ_TOTAL" { return token::MAX_ODT_ENTRIES_DAQ_TOTAL;}
"MAX_ODT_ENTRIES_STIM_TOTAL" { return token::MAX_ODT_ENTRIES_STIM_TOTAL;}
"MAX_ODT_ENTRIES_TOTAL" { return token::MAX_ODT_ENTRIES_TOTAL;}
"MAX_ODT_STIM_TOTAL" { return token::MAX_ODT_STIM_TOTAL;}
"MAX_ODT_TOTAL" { return token::MAX_ODT_TOTAL;}
"MEASUREMENT_SPLIT_ALLOWED" { return token::MEASUREMENT_SPLIT_ALLOWED;}
"MEMORY_ACCESS"  { return token::MEMORY_ACCESS;}
"MIN_CYCLE_TIME" { return token::MIN_CYCLE_TIME;}
"MIN_ST_STIM" { return token::MIN_ST_STIM;}
"MODEL_NAME" { return token::MODEL_NAME;}
"MTA_BLOCK_SIZE_ALIGN" { return token::MTA_BLOCK_SIZE_ALIGN;}
"MULTICAST" { return token::MULTICAST;}
"ODT" { return token::ODT;}
"ODT_ENTRY" { return token::ODT_ENTRY;}
"ODT_ENTRY_SIZE_FACTOR_TABLE" { return token::ODT_ENTRY_SIZE_FACTOR_TABLE;}
"OFFSET" { return token::OFFSET;}

"OPTIMISATION_TYPE_ODT_STRICT" { return token::OPTIMISATION_TYPE_ODT_STRICT;}
"OPTIONAL_CMD"   { return token::OPTIONAL_CMD;}
"OPTIONAL_LEVEL1_CMD" { return token::OPTIONAL_LEVEL1_CMD;}
"OPTIONAL_TL_SUBCMD" { return token::OPTIONAL_TL_SUBCMD;}
"OUT_EP_CMD_STIM" { return token::OUT_EP_CMD_STIM;}
"OUT_EP_ONLY_STIM" { return token::OUT_EP_ONLY_STIM;}
"PACKET_ALIGNMENT" { return token::PACKET_ALIGNMENT;}
"PAG" { return token::PAG;}
"PAGE" { return token::PAGE;}
"PGM" { return token::PGM;}
"PID_OFF_SUPPORTED" { return token::PID_OFF_SUPPORTED;}
"POOL_BUFFER" { return token::POOL_BUFFER;}
"PREDEFINED" { return token::PREDEFINED;}
"PRESCALER_SUPPORTED" { return token::PRESCALER_SUPPORTED;}
"PROTOCOL_LAYER" { return token::PROTOCOL_LAYER;}
"RECOMMENDED_HOST_BUFSIZE" { return token::RECOMMENDED_HOST_BUFSIZE;}
"RELATED_EVENT_CHANNEL_NUMBER" { return token::RELATED_EVENT_CHANNEL_NUMBER;}
"RELATED_EVENT_CHANNEL_NUMBER_FIXED" { return token::RELATED_EVENT_CHANNEL_NUMBER_FIXED;}
"RES_ERR" { return token::RES_ERR;}
"RESUME_SUPPORTED" { return token::RESUME_SUPPORTED;}
"SAMPLE_POINT" { return token::SAMPLE_POINT;}
"SAMPLE_RATE" { return token::SAMPLE_RATE;}
"SEGMENT" { return token::SEGMENT;}
"SECONDARY_SAMPLE_POINT" { return token::SECONDARY_SAMPLE_POINT;}
"SECTOR" { return token::SECTOR;}
"SEED_AND_KEY_EXTERNAL_FUNCTION" { return token::SEED_AND_KEY_EXTERNAL_FUNCTION;}
"SJW" { return token::SJW;}
"SLAVE" { return token::SLAVE; }
"STATE" { return token::STATE;}
"STIM" { return token::STIM;}
"STIM_DTO_CTR_COPY_PRESENT" { return token::STIM_DTO_CTR_COPY_PRESENT;}
"STORE_DAQ_SUPPORTED" { return token::STORE_DAQ_SUPPORTED;}
"SYNC_EDGE" { return token::SYNC_EDGE;}
"SYNCH_FULL_DUPLEX_MODE_BYTE" { return token::SYNCH_FULL_DUPLEX_MODE_BYTE;}
"SYNCH_FULL_DUPLEX_MODE_WORD" { return token::SYNCH_FULL_DUPLEX_MODE_WORD;}
"SYNCH_FULL_DUPLEX_MODE_DWORD" { return token::SYNCH_FULL_DUPLEX_MODE_DWORD;}
"SYNCH_FULL_MASTER_MODE_BYTE" { return token::SYNCH_FULL_MASTER_MODE_BYTE; }
"SYNCH_FULL_MASTER_MODE_WORD" { return token::SYNCH_FULL_MASTER_MODE_WORD;}
"SYNCH_FULL_MASTER_MODE_DWORD" { return token::SYNCH_FULL_MASTER_MODE_DWORD;}
"TIME_CHARACTERIZATION" { return token::TIME_CHARACTERIZATION;}
"TIME_CORRELATION" { return token::TIME_CORRELATION;}
"TIMESTAMP_FIXED" { return token::TIMESTAMP_FIXED;}
"TIMESTAMP_SUPPORTED" { return token::TIMESTAMP_SUPPORTED;}
"TRANSCEIVER_DELAY_COMPENSATION" { return token::TRANSCEIVER_DELAY_COMPENSATION;}
"TRANSPORT_LAYER_INSTANCE" { return token::TRANSPORT_LAYER_INSTANCE;}
"VARIABLE" { return token::VARIABLE;}
"XCP"            { return token::XCP;}
"XCPplus"        { return token::XCPplus;}
"XCP_ON_CAN" { return token::XCP_ON_CAN;}
"XCP_ON_SxI" { return token::XCP_ON_SxI;}
"XCP_ON_TCP_IP" { return token::XCP_ON_TCP_IP;}
"XCP_ON_UDP_IP" { return token::XCP_ON_UDP_IP;}
"XCP_ON_USB" { return token::XCP_ON_USB;}
"XCP_ON_FLX" { return token::XCP_ON_FLX;}
"XCP_ON_SIMULINK" { return token::XCP_ON_SIMULINK;}
"XCP_PACKET" { return token::XCP_PACKET;}
{ident}          {
                   if (yylval != nullptr) {
                     std::string temp(yytext);
                     yylval->emplace<std::string>(temp);
                   }
                   return token::IDENT;
                 }

"100_ms_task" { yylval->emplace<std::string>("100_ms_task");
                return token::STRING;
                }
"1000_ms_task" { yylval->emplace<std::string>("1000_ms_task");
                 return token::STRING;
                 }

{string}         {
                   const size_t len = strlen(yytext);
                   std::string temp;
                   if (len > 2) {
                     temp = yytext + 1;
                     temp.pop_back();
                   }
                   yylval->emplace<std::string>(temp);
                   return token::STRING;
                 }

{hexnumber}      {
		uint64_t address = 0;
		for ( size_t index = 0; yytext[ index ] != '\0'; ++index ) {
			if ( index < 2 ) continue;
			const char token = yytext[index];
			switch ( token ) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				address *= 16;
				address += token - '0';
				break;

			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				address *= 16;
				address += token - 'A' + 10;
				break;

			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				address *= 16;
				address += token - 'a' + 10;
				break;

			default:
				break;
			}
		}

		yylval->emplace<uint64_t>(address);
	    return token::UINT;
    }
 {unsigned_number}  {
                    uint64_t temp = 0;
                    try {
                      temp = std::stoull(yytext);
                    } catch (const std::exception& ) {

                    }
                    yylval->emplace<uint64_t>(temp);
                    return token::UINT;
                  }
 {signed_number}  {
                     int64_t temp = 0;
                     try {
                       temp = std::stoll(yytext);
                     } catch (const std::exception& ) {

                     }
                     yylval->emplace<int64_t>(temp);
                     return token::INT;
                   }
{float_val}     {
                   double temp = 0.0;
                   try {
                     temp = std::stod(yytext);
                   } catch (const std::exception&) {

                   }
                   yylval->emplace<double>(temp);
                   return token::FLOAT;
                 }

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]       { } /* Multi line comments */
"//".*                                    { /* Single line comment  */ }
{ws}             {}
.                {}
%%

