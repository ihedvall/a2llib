%require "3.2"
%language "c++"


%define api.prefix {ccp}
%define api.namespace {a2l::ccp}
%define api.parser.class {CcpDataParser}


%code requires {
#include <cstdint>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/ccp/kpblob.h"
#include "a2l/ccp/dpblob.h"
#include "a2l/ccp/addressmapping.h"
#include "a2l/ccp/definedpages.h"
#include "a2l/ccp/checksumparam.h"
#include "a2l/ccp/canparam.h"
#include "a2l/ccp/tpblob.h"
#include "a2l/ccp/seedkey.h"
#include "a2l/ccp/eventgroup.h"
#include "a2l/ccp/raster.h"
#include "a2l/ccp/qpblob.h"
#include "a2l/ccp/source.h"

namespace a2l::ccp {
class CcpDataScanner;
}

}

%parse-param { a2l::ccp::CcpDataScanner &scanner  }


%code  {
    #include <sstream>
    #include <limits>
    #include "ccpdatascanner.h"


    #undef yylex
    #define yylex scanner.ccplex
}

%define api.value.type variant



%token <uint64_t> UINT
%token <uint64_t> HEX
%token <int64_t>  INT
%token <double>   FLOAT
%token <std::string> IDENT
%token <std::string> STRING

%token ADDRESS_EXTENSION ADDR_MAPPING ADDRESS_MAPPING
%token ALTERNATING ASAP1B_CCP AUTO_FLASH_BACK
%token BAUDRATE BLOCK_BEGIN BLOCK_END BTL_CYCLES BYTES_ONLY
%token CAN_ID_FIXED CAN_ID_VARIABLE CAN_PARAM CHECKSUM CHECKSUM_CALCULATION CHECKSUM_PARAM CONSISTENCY
%token DAQ_MODE DEFINED_PAGES DEFAULT DISPLAY_IDENTIFIER DP_BLOB DP_BLOB_VERSION
%token ECU_RASTER EEPROM EVENT_GROUP EXCLUSIVE
%token FIRST_PID FLASH FLASH_BACK
%token IF_DATA
%token KP_BLOB
%token LENGTH
%token OPTIONAL_CMD
%token QP_BLOB
%token RAM RAM_INIT_BY_ECU RAM_INIT_BY_TOOL RASTER REDUCTION_ALLOWED RESUME_SUPPORTED ROM
%token SAMPLE_POINT SAMPLE_RATE SEED_KEY SINGLE SJW SOURCE STORE_SUPPORTED SYNC_EDGE
%token TP_BLOB

%nterm <AddressMapping> addr_mapping
// %nterm <double> any_float
%nterm <int64_t> any_int
%nterm <CanParam> can_param
%nterm <std::string> checksum
%nterm <std::string> checksum_calculation
%nterm <ChecksumParam> checksum_param
%nterm <DefinedPages> defined_pages
%nterm <DpBlob> dp_blob
%nterm <EventGroup> event_group
%nterm <int64_t> exclusive
%nterm <std::vector<uint8_t>> exclusive_list
%nterm <std::string> ident_or_string
%nterm <KpBlob> kp_blob
%nterm <QpBlob> qp_blob
%nterm <Raster> raster
%nterm <std::vector<uint8_t>> raster_list
%nterm <uint8_t> raster_value
%nterm <SeedKey> seed_key
%nterm <Source> source
%nterm <TpBlob> tp_blob

%start ccp_data_block

%%

ccp_data_block:  BLOCK_BEGIN IF_DATA
			if_data
		 BLOCK_END IF_DATA;

if_data: ASAP1B_CCP definitions;

definitions: %empty
             | definitions definition;

definition: source { scanner.AddSource(std::move($1)); }
	| raster { scanner.AddRaster(std::move($1)); }
	| event_group { scanner.AddEventGroup(std::move($1)); }
	| seed_key { scanner.SetSeedKey(std::move($1)); }
	| checksum { scanner.SetChecksum(std::move($1)); }
	| tp_blob { scanner.SetTpBlob(std::move($1)); }
	| addr_mapping { scanner.AddAddressMapping(std::move($1)); }
	| dp_blob { scanner.SetDpBlob(std::move($1)); }
	| kp_blob { scanner.SetKpBlob(std::move($1)); };

source: BLOCK_BEGIN SOURCE
	  STRING any_int any_int source_options
        BLOCK_END SOURCE {
          Source& source = scanner.GetSource();
          source.SetName($3);
          source.SetScalingUnit($4);
          source.SetRate($5);

          $$ = std::move(source);
          source.Reset();
        };

source_options: %empty
	| source_options source_option;

source_option: DISPLAY_IDENTIFIER ident_or_string {
          Source& source = scanner.GetSource();
          source.SetDisplayIdentifier(std::move($2));
        } | qp_blob {
          Source& source = scanner.GetSource();
          source.SetQpBlob(std::move($1));
        };

qp_blob: BLOCK_BEGIN QP_BLOB
           UINT qp_blob_options
         BLOCK_END QP_BLOB {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetNumber($3);
  	  $$ = std::move(blob);
  	  blob.Reset();
        };

qp_blob_options: %empty
	| qp_blob_options qp_blob_option;

qp_blob_option: LENGTH UINT {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetNumber($2);
        } |  CAN_ID_VARIABLE {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetCanIdVariable();
        } | CAN_ID_FIXED UINT {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetCanIdFixed($2);
        } | raster_value {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.AddRaster($1);
        } | exclusive {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.AddExclusive($1);
        } | REDUCTION_ALLOWED {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetReductionAllowed();
        } | FIRST_PID UINT {
  	  QpBlob& blob = scanner.GetQpBlob();
  	  blob.SetFirstPid($2);
        };

raster: BLOCK_BEGIN RASTER
	  STRING STRING UINT any_int any_int exclusive_list
        BLOCK_END RASTER {
          $$.SetName($3);
          $$.SetShortName($4);
          $$.SetNumber($5);
          $$.SetPeriod($6);
          $$.SetSampleRate($7);
          $$.SetExclusiveList($8);
        };

event_group: BLOCK_BEGIN EVENT_GROUP
               STRING STRING raster_list
             BLOCK_END EVENT_GROUP {
          $$.SetName($3);
          $$.SetShortName($4);
          $$.SetRasterList($5);
        };

seed_key: BLOCK_BEGIN SEED_KEY
            STRING STRING STRING
          BLOCK_END SEED_KEY {
          $$.SetCalDll($3);
          $$.SetDaqDll($4);
          $$.SetPgmDll($5);
        };

checksum: BLOCK_BEGIN CHECKSUM
            STRING
          BLOCK_END CHECKSUM { $$ = std::move($3); };

tp_blob: BLOCK_BEGIN TP_BLOB
           UINT UINT UINT UINT UINT UINT tp_blob_options
         BLOCK_END TP_BLOB {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetVersion($3);
          blob.SetBlobVersion($4);
          blob.SetTransmitMessageId($5);
          blob.SetReceiveMessageId($6);
          blob.SetAddress($7);
          blob.SetByteOrder($8);

          $$ = std::move(blob);
          blob.Reset();
        };

tp_blob_options: %empty
	| tp_blob_options tp_blob_option;

tp_blob_option: can_param {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetCanParam($1);
        } | BAUDRATE UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBaudrate($2);
        } | SAMPLE_POINT UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSamplePoint($2);
        } | SAMPLE_RATE UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSampleRate($2);
        } | BTL_CYCLES UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBtlCycles($2);
        } | SJW UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSjw($2);
        } | SYNC_EDGE IDENT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSyncEdge($2);
        } | SYNC_EDGE UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetSyncEdge($2);
        } | DAQ_MODE IDENT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetDaqMode($2);
        } | BYTES_ONLY {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetBytesOnly();
        } | RESUME_SUPPORTED {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetResumeSupported();
        } | STORE_SUPPORTED {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetStoreSupported();
        } | CONSISTENCY IDENT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetConsistency($2);
        } | ADDRESS_EXTENSION IDENT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetAddressExtension($2);
        } | checksum_param {
          TpBlob& blob = scanner.GetTpBlob();
          blob.SetChecksumParam($1);
        } | defined_pages {
          TpBlob& blob = scanner.GetTpBlob();
          blob.AddDefinedPages($1);
        } | OPTIONAL_CMD UINT {
          TpBlob& blob = scanner.GetTpBlob();
          blob.AddOptionalCmd($2);
        };

can_param: BLOCK_BEGIN CAN_PARAM
             UINT UINT UINT
           BLOCK_END CAN_PARAM {
           $$.SetFrequency($3);
           $$.SetBtr0($4);
           $$.SetBtr1($5);
         };

checksum_param: BLOCK_BEGIN CHECKSUM_PARAM
                  UINT UINT checksum_calculation
                BLOCK_END CHECKSUM_PARAM {
          $$.SetType($3);
          $$.SetMaxBlockLength($4);
          $$.SetCalculation($5);
        };

checksum_calculation: %empty { $$.clear(); }
        | CHECKSUM_CALCULATION IDENT { $$ = std::move($2); };

defined_pages: BLOCK_BEGIN DEFINED_PAGES
                 UINT STRING UINT UINT UINT defined_pages_options
               BLOCK_END DEFINED_PAGES {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetNumber($3);
	  page.SetName(std::move($4));
	  page.SetAddressExtension($5);
	  page.SetBaseAddress($6);
	  page.SetLength($7);

	  $$ = std::move(page);
	  page.Reset();
        };

defined_pages_options: %empty
        | defined_pages_options defined_pages_option;

defined_pages_option: RAM {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetRam();
        } | ROM {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetRom();
        } | FLASH {
	  DefinedPages& page = scanner.GetDefinedPages();
	  page.SetFlash();
        } | EEPROM {
 	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetEeprom();
        } | RAM_INIT_BY_ECU {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetRamInitByEcu();
        } | RAM_INIT_BY_TOOL {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetRamInitByTool();
        } | AUTO_FLASH_BACK {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetAutoFlashBack();
        } | FLASH_BACK {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetFlashBack();
        } | DEFAULT {
	  DefinedPages& page = scanner.GetDefinedPages();
 	  page.SetDefault();
        };

addr_mapping: ADDR_MAPPING UINT UINT UINT {
	  $$.SetFromAddress($2);
	  $$.SetToAddress($3);
	  $$.SetLength($4);
 	} | ADDRESS_MAPPING UINT UINT UINT {
          $$.SetFromAddress($2);
          $$.SetToAddress($3);
          $$.SetLength($4);
       	};


dp_blob: DP_BLOB UINT UINT UINT {
	  $$.SetAddressExtension($2);
	  $$.SetBaseAddress($3);
	  $$.SetNofBytes($4);
	};

kp_blob: BLOCK_BEGIN KP_BLOB
           UINT UINT UINT raster_list
         BLOCK_END KP_BLOB {
           $$.SetAddressExtension($3);
           $$.SetBaseAddress($4);
           $$.SetNofBytes($5);
           $$.SetRaster(std::move($6));
         } | KP_BLOB UINT UINT UINT raster_list {
            $$.SetAddressExtension($2);
            $$.SetBaseAddress($3);
            $$.SetNofBytes($4);
            $$.SetRaster(std::move($5));
         };

exclusive_list: %empty { $$.clear();}
	| exclusive_list exclusive {
	  $$ = std::move($1);
	  $$.push_back(static_cast<uint8_t>($2));
	};

exclusive: EXCLUSIVE any_int { $$ = $2;};

raster_list: %empty { $$.clear(); }
	| raster_list raster_value {
	  $$ = std::move($1);
	  $$.push_back($2);
	};

raster_value: RASTER UINT {
          $$ = static_cast<uint8_t>($2);
        } | ECU_RASTER UINT {
           $$ = static_cast<uint8_t>($2);
        };
/*
any_float: FLOAT { $$ = $1; }
           | INT { $$ = static_cast<double>($1); }
           | UINT { $$ = static_cast<double>($1); };
*/
any_int: INT { $$ = $1; }
         | UINT { $$ = static_cast<int64_t>($1); };

ident_or_string: STRING { $$ = std::move($1); }
         | IDENT { $$ = std::move($1); };

%%

void a2l::ccp::CcpDataParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
