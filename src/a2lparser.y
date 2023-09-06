%require "3.2"
%language "c++"

%define api.prefix {a2l}
%define api.namespace {a2l}
%define api.parser.class {A2lParser}


%code requires {
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "a2l/a2lenums.h"
#include "a2l/a2lstructs.h"
namespace a2l {
class A2lScanner;
class A2lFile;
}

}

%parse-param { a2l::A2lScanner &scanner  }
%parse-param { a2l::A2lFile &file  }

%code  {    #include "a2l/a2lstructs.h"
    #include <sstream>
    #include "a2lscanner.h"
    #include "a2l/a2lfile.h"
    #include <limits>


    #undef yylex
    #define yylex scanner.a2llex
}

%define api.value.type variant

%token A2L_BEGIN
%token A2L_END
%token A2L_INCLUDE

%token <std::string> IDENT
%token <std::string> STRING
%token <int64_t> INT
%token <uint64_t> UINT
%token <uint64_t> HEX
%token <double> FLOAT


%token ASAP2_VERSION
%token A2L_VERSION
%token A2ML_VERSION
%token <std::string> A2ML
%token ADDR_EPK
%token ADDRESS_TYPE
%token ALIGNMENT_BYTE
%token ALIGNMENT_FLOAT16_IEEE
%token ALIGNMENT_FLOAT32_IEEE
%token ALIGNMENT_FLOAT64_IEEE
%token ALIGNMENT_INT64
%token ALIGNMENT_LONG
%token ALIGNMENT_WORD
%token ANNOTATION
%token ANNOTATION_LABEL
%token ANNOTATION_ORIGIN
%token ANNOTATION_TEXT
%token ARRAY_SIZE
%token AR_COMPONENT
%token AR_PROTOTYPE_OF
%token AXIS_DESCR
%token AXIS_PTS
%token AXIS_PTS_REF
%token AXIS_PTS_X
%token AXIS_PTS_Y
%token AXIS_PTS_Z
%token AXIS_PTS_4
%token AXIS_PTS_5
%token AXIS_RESCALE_X
%token BIT_MASK
%token BIT_OPERATION
%token BLOB
%token BYTE_ORDER
%token CALIBRATION_ACCESS
%token CALIBRATION_HANDLE
%token CALIBRATION_HANDLE_TEXT
%token CALIBRATION_METHOD
%token CHARACTERISTIC
%token COEFFS
%token COEFFS_LINEAR
%token COMPARISON_QUANTITY
%token COMPU_METHOD
%token COMPU_TAB
%token COMPU_TAB_REF
%token COMPU_VTAB
%token COMPU_VTAB_RANGE
%token CONSISTENT_EXCHANGE
%token CONVERSION
%token CPU_TYPE
%token CURVE_AXIS_REF
%token CUSTOMER
%token CUSTOMER_NO
%token DATA_SIZE
%token DEF_CHARACTERISTIC
%token DEFAULT_VALUE
%token DEFAULT_VALUE_NUMERIC
%token DEPENDENT_CHARACTERISTIC
%token DEPOSIT
%token DISCRETE
%token DISPLAY_IDENTIFIER
%token DIST_OP_X
%token DIST_OP_Y
%token DIST_OP_Z
%token DIST_OP_4
%token DIST_OP_5
%token ECU
%token ECU_ADDRESS
%token ECU_ADDRESS_EXTENSION
%token ECU_CALIBRATION_OFFSET
%token ENCODING
%token EPK
%token ERROR_MASK
%token EXTENDED_LIMITS
%token FIX_AXIS_PAR
%token FIX_AXIS_PAR_DIST
%token FIX_AXIS_PAR_LIST
%token FIX_NO_AXIS_PTS_X
%token FIX_NO_AXIS_PTS_Y
%token FIX_NO_AXIS_PTS_Z
%token FIX_NO_AXIS_PTS_4
%token FIX_NO_AXIS_PTS_5
%token FNC_VALUES
%token FORMAT
%token FORMULA
%token FORMULA_INV
%token FRAME
%token FRAME_MEASUREMENT
%token FUNCTION
%token FUNCTION_LIST
%token FUNCTION_VERSION
%token GROUP
%token GUARD_RAILS
%token HEADER
%token IDENTIFICATION
%token <std::string> IF_DATA
%token IN_MEASUREMENT
%token INPUT_QUANTITY
%token INSTANCE
%token LAYOUT
%token LEFT_SHIFT
%token LIMITS
%token LOC_MEASUREMENT
%token MAP_LIST
%token MATRIX_DIM
%token MAX_GRAD
%token MAX_REFRESH
%token MEASUREMENT
%token MEMORY_LAYOUT
%token MEMORY_SEGMENT
%token MODULE
%token MOD_COMMON
%token MOD_PAR
%token MODEL_LINK
%token MONOTONY
%token NO_AXIS_PTS_X
%token NO_AXIS_PTS_Y
%token NO_AXIS_PTS_Z
%token NO_AXIS_PTS_4
%token NO_AXIS_PTS_5
%token NO_OF_INTERFACES
%token NO_RESCALE_X
%token NUMBER
%token OFFSET_X
%token OFFSET_Y
%token OFFSET_Z
%token OFFSET_4
%token OFFSET_5
%token OUT_MEASUREMENT
%token OVERWRITE
%token PHONE_NO
%token PHYS_UNIT
%token PROJECT
%token PROJECT_NO
%token READ_ONLY
%token READ_WRITE
%token RECORD_LAYOUT
%token REF_CHARACTERISTIC
%token REF_GROUP
%token REF_MEASUREMENT
%token REF_MEMORY_SEGMENT
%token REF_UNIT
%token RESERVED
%token RIGHT_SHIFT
%token RIP_ADDR_W
%token RIP_ADDR_X
%token RIP_ADDR_Y
%token RIP_ADDR_Z
%token RIP_ADDR_4
%token RIP_ADDR_5
%token ROOT
%token S_REC_LAYOUT
%token SHIFT_OP_X
%token SHIFT_OP_Y
%token SHIFT_OP_Z
%token SHIFT_OP_4
%token SHIFT_OP_5
%token SIGN_EXTEND
%token SI_EXPONENTS
%token SRC_ADDR_X
%token SRC_ADDR_Y
%token SRC_ADDR_Z
%token SRC_ADDR_4
%token SRC_ADDR_5
%token STATIC_ADDRESS_OFFSETS
%token STATIC_RECORD_LAYOUT
%token STATUS_STRING_REF
%token STEP_SIZE
%token STRUCTURE_COMPONENT
%token SUB_FUNCTION
%token SUB_GROUP
%token SUPPLIER
%token SYMBOL_LINK
%token SYMBOL_TYPE_LINK
%token SYSTEM_CONSTANT
%token TRANSFORMER
%token TRANSFORMER_IN_OBJECTS
%token TRANSFORMER_OUT_OBJECTS
%token TYPEDEF_AXIS
%token TYPEDEF_BLOB
%token TYPEDEF_CHARACTERISTIC
%token TYPEDEF_MEASUREMENT
%token TYPEDEF_STRUCTURE
%token UNIT
%token UNIT_CONVERSION
%token USER
%token USER_RIGHTS
%token VAR_ADDRESS
%token VAR_CHARACTERISTIC
%token VAR_CRITERION
%token VAR_FORBIDDEN_COMB
%token VAR_MEASUREMENT
%token VAR_NAMING
%token VAR_SELECTION_CHARACTERISTIC
%token VAR_SEPARATOR
%token VARIANT_CODING
%token VIRTUAL
%token VIRTUAL_CHARACTERISTIC
%token EOL 0

%nterm <uint64_t> any_uint
%nterm <int64_t> any_int
%nterm <double> any_float
%nterm <std::vector<int64_t>> int_list
%nterm <std::vector<uint64_t>> uint_list
%nterm <std::vector<double>> float_list
%nterm <std::map<double, double>> float_pair_list
%nterm <std::map<double, std::string>> float_string_list
%nterm <std::map<std::pair<double, double>, std::string>> float_range_list
%nterm <std::vector<std::string>> string_list
%nterm <std::vector<std::string>> ident_list
%nterm <std::map<std::string, std::string>> key_value_list

%nterm <std::string> a2ml
%nterm <uint64_t> addr_epk
%nterm <A2lAddressType> address_type
%nterm <uint64_t> alignment_byte
%nterm <uint64_t> alignment_float16_ieee
%nterm <uint64_t> alignment_float32_ieee
%nterm <uint64_t> alignment_float64_ieee
%nterm <uint64_t> alignment_int64
%nterm <uint64_t> alignment_long
%nterm <uint64_t> alignment_word
%nterm <A2lAnnotation> annotation
%nterm <A2lAnnotation> annotation_attributes
%nterm <std::string> annotation_label
%nterm <std::string> annotation_origin
%nterm <std::vector<std::string>> annotation_text
%nterm <uint64_t> array_size
%nterm <std::string> ar_component_attribute
%nterm <std::string> ar_prototype_of
%nterm <std::string> axis_pts_ref
%nterm <A2lAxisPts> axis_pts_x
%nterm <A2lAxisPts> axis_pts_y
%nterm <A2lAxisPts> axis_pts_z
%nterm <A2lAxisPts> axis_pts_4
%nterm <A2lAxisPts> axis_pts_5
%nterm <A2lAxisRescale> axis_rescale_x
%nterm <A2lByteOrder> byte_order
%nterm <uint64_t> bit_mask
%nterm <A2lBitOperation> bit_operation
%nterm <A2lCalibrationAccess> calibration_access
%nterm <A2lCalibrationHandle> calibration_handle
%nterm <std::string> calibration_handle_attribute
%nterm <std::string> calibration_handle_text
%nterm <A2lCalibrationMethod> calibration_method
%nterm <std::vector<A2lCalibrationHandle>> calibration_method_attributes
%nterm <std::vector<double>> coeffs
%nterm <std::vector<double>> coeffs_linear
%nterm <std::string> comparison_quantity
%nterm <std::string> compu_tab_ref
%nterm <std::string> conversion
%nterm <std::string> cpu_type
%nterm <std::string> curve_axis_ref
%nterm <std::string> customer
%nterm <std::string> customer_no
%nterm <uint64_t> data_size
%nterm <std::vector<std::string>> def_characteristic
%nterm <std::string> default_value
%nterm <double> default_value_numeric
%nterm <A2lDeposit> deposit
%nterm <A2lDependentCharacteristic> dependent_characteristic
%nterm <std::string> display_identifier
%nterm <A2lDistOp> dist_op_x
%nterm <A2lDistOp> dist_op_y
%nterm <A2lDistOp> dist_op_z
%nterm <A2lDistOp> dist_op_4
%nterm <A2lDistOp> dist_op_5
%nterm <std::string> ecu
%nterm <uint64_t> ecu_address
%nterm <int64_t> ecu_address_extension
%nterm <int64_t> ecu_calibration_offset
%nterm <A2lEncoding> encoding
%nterm <std::string> epk
%nterm <uint64_t> error_mask
%nterm <A2lExtendedLimits> extended_limits
%nterm <A2lFixAxisPar> fix_axis_par
%nterm <A2lFixAxisParDist> fix_axis_par_dist
%nterm <std::vector<double>> fix_axis_par_list
%nterm <uint64_t> fix_no_axis_pts_x
%nterm <uint64_t> fix_no_axis_pts_y
%nterm <uint64_t> fix_no_axis_pts_z
%nterm <uint64_t> fix_no_axis_pts_4
%nterm <uint64_t> fix_no_axis_pts_5
%nterm <A2lFncValue>  fnc_values
%nterm <std::string> format
%nterm <std::pair<std::string,std::string>> formula
%nterm <std::string> formula_attribute
%nterm <std::string> formula_inv
%nterm <std::vector<std::string>> frame_measurement
%nterm <std::vector<std::string>> function_list
%nterm <std::string> function_version
%nterm <A2lIdentification> identification
%nterm <std::string> if_data
%nterm <std::string> input_quantity
%nterm <std::vector<std::string>> in_measurement
%nterm <A2lLayout> layout
%nterm <uint64_t> left_shift
%nterm <double> limits
%nterm <std::vector<std::string>> map_list
%nterm <std::vector<uint64_t>> matrix_dim
%nterm <double> max_grad
%nterm <A2lMaxRefresh> max_refresh
%nterm <A2lMemoryLayout> memory_layout
%nterm <std::vector<std::string>> memory_layout_attributes
%nterm <A2lMemorySegment> memory_segment
%nterm <std::vector<std::string>> memory_segment_attributes
%nterm <std::string> model_link
%nterm <A2lMonotony> monotony
%nterm <A2lDistOp> no_axis_pts_x
%nterm <A2lDistOp> no_axis_pts_y
%nterm <A2lDistOp> no_axis_pts_z
%nterm <A2lDistOp> no_axis_pts_4
%nterm <A2lDistOp> no_axis_pts_5
%nterm <A2lDistOp> no_rescale_x
%nterm <uint64_t> no_of_interfaces
%nterm <uint64_t> number
%nterm <A2lDistOp> offset_x
%nterm <A2lDistOp> offset_y
%nterm <A2lDistOp> offset_z
%nterm <A2lDistOp> offset_4
%nterm <A2lDistOp> offset_5
%nterm <std::vector<std::string>> out_measurement
%nterm <std::vector<std::string>> loc_measurement
%nterm <std::string> phone_no
%nterm <std::string> phys_unit
%nterm <A2lSegmentType> prg_type
%nterm <std::string> proj_no
%nterm <std::string> project_no
%nterm <std::vector<std::string>> ref_characteristic
%nterm <std::vector<std::string>> ref_group
%nterm <std::vector<std::string>> ref_measurement
%nterm <std::string> ref_memory_segment
%nterm <std::string> ref_unit
%nterm <A2lDistOp> reserved
%nterm <uint64_t> right_shift
%nterm <A2lDistOp> rip_addr_w
%nterm <A2lDistOp> rip_addr_x
%nterm <A2lDistOp> rip_addr_y
%nterm <A2lDistOp> rip_addr_z
%nterm <A2lDistOp> rip_addr_4
%nterm <A2lDistOp> rip_addr_5
%nterm <A2lDistOp> shift_op_x
%nterm <A2lDistOp> shift_op_y
%nterm <A2lDistOp> shift_op_z
%nterm <A2lDistOp> shift_op_4
%nterm <A2lDistOp> shift_op_5
%nterm <A2lSiExponents> si_exponents
%nterm <A2lDistOp> src_addr_x
%nterm <A2lDistOp> src_addr_y
%nterm <A2lDistOp> src_addr_z
%nterm <A2lDistOp> src_addr_4
%nterm <A2lDistOp> src_addr_5
%nterm <double> step_size
%nterm <std::string> status_string_ref
%nterm <std::vector<std::string>> sub_function
%nterm <std::vector<std::string>> sub_group
%nterm <std::string> supplier
%nterm <A2lSymbolLink> symbol_link
%nterm <std::string> symbol_type_link
%nterm <std::pair<std::string,std::string>> system_constant
%nterm <std::vector<std::string>> transformer_in_objects
%nterm <std::vector<std::string>> transformer_out_objects
%nterm <std::pair<double,double>> unit_conversion
%nterm <std::string> user
%nterm <std::vector<uint64_t>> var_address
%nterm <A2lVarCharacteristic> var_characteristic
%nterm <std::vector<uint64_t>> var_characteristic_attribute
%nterm <A2lVarCriterion> var_criterion
%nterm <std::map<std::string, std::string>> var_forbidden_comb
%nterm <std::string> var_measurement
%nterm <std::string> var_naming
%nterm <std::string> var_selection_characteristic
%nterm <std::string> var_separator
%nterm <std::string> version
%nterm <std::vector<std::string>> virtual
%nterm <A2lDependentCharacteristic> virtual_characteristic

// %right TAG_NS_DESC TAG_CM
%start a2l_file
%%
any_uint: UINT { $$ = $1; }
	| HEX  { $$ = $1; };

any_int:  INT { $$ = $1; }
	| UINT { $$ = static_cast<int64_t>($1); }
	| HEX { $$ = static_cast<int64_t>($1); };

any_float: FLOAT { $$ = $1; }
	| INT { $$ = static_cast<double>($1); }
	| UINT { $$ = static_cast<double>($1); }
	| HEX { $$ = static_cast<double>($1); };

int_list: %empty {}
  | int_list any_int {$$ = $1; $$.emplace_back($2); };

uint_list: %empty {}
  | uint_list any_uint {$$ = $1; $$.emplace_back($2); };

float_list: %empty {}
	| float_list any_float {$$ = $1; $$.emplace_back($2); };

float_pair_list: %empty {}
	| float_pair_list any_float any_float {$$ = $1; $$.emplace($2,$3); };

float_string_list: %empty {}
	| float_string_list any_float STRING {$$ = $1; $$.emplace($2,$3); };

float_range_list: %empty {}
	| float_range_list any_float any_float STRING {
	$$ = $1;
	$$.emplace(std::pair($2,$3),$4); };

string_list: %empty {}
	| string_list STRING ;

ident_list: %empty {}
       	| ident_list IDENT {$$ = $1; $$.emplace_back($2); };

key_value_list: %empty {}
       	| key_value_list IDENT IDENT {$$ = $1; $$.emplace($2,$3); };

a2l_file: file_version project;

file_version: asap2_version
	| file_version a2ml_version;

annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION { $$ = $3;};
annotation_attributes: %empty {}
     | annotation_attributes annotation_label { $$ = $1; $$.Label = $2;}
     | annotation_attributes annotation_origin { $$ = $1; $$.Origin = $2;}
     | annotation_attributes annotation_text { $$ = $1; $$.Text = $2;};

annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT {$$ = $3;};

ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attribute A2L_END AR_COMPONENT {
	auto& func = scanner.CurrentFunction();
	func.ComponentType($3);
	func.PrototypeOf($4);
 };
ar_component_attribute: %empty { $$ = std::string(); }
	| ar_prototype_of { $$ = $1; };

axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float
	axis_descr_attributes A2L_END AXIS_DESCR {
	auto& descr = scanner.CurrentAxisDescr();
	descr.AxisType(StringToAxisType($3));
	descr.InputQuantity($4);
	descr.Conversion($5);
	descr.MaxAxisPoints($6);
	descr.LowerLimit($7);
	descr.UpperLimit($8);
	};
axis_descr_attributes: %empty
	| axis_descr_attributes axis_descr_attribute;
axis_descr_attribute: annotation { scanner.CurrentAxisDescr().AddAnnotation($1); }
	| axis_pts_ref { scanner.CurrentAxisDescr().AxisPtsRef($1); }
	| byte_order { scanner.CurrentAxisDescr().ByteOrder($1); }
	| curve_axis_ref { scanner.CurrentAxisDescr().CurveAxisRef($1); }
	| deposit { scanner.CurrentAxisDescr().Deposit($1); }
	| extended_limits { scanner.CurrentAxisDescr().ExtendedLimits($1); }
	| fix_axis_par { scanner.CurrentAxisDescr().FixAxisPar($1); }
	| fix_axis_par_dist { scanner.CurrentAxisDescr().FixAxisParDist($1); }
	| fix_axis_par_list { scanner.CurrentAxisDescr().FixAxisParList($1); }
	| format { scanner.CurrentAxisDescr().Format($1); }
	| max_grad { scanner.CurrentAxisDescr().MaxGradient($1); }
	| monotony { scanner.CurrentAxisDescr().Monotony($1); }
	| phys_unit { scanner.CurrentAxisDescr().PhysUnit($1); }
	| read_only { scanner.CurrentAxisDescr().ReadOnly(true); }
	| step_size { scanner.CurrentAxisDescr().StepSize($1); };

axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float
	axis_pts_attributes A2L_END AXIS_PTS {
		auto& pts = scanner.CurrentAxisPts();
		pts.Name($3);
		pts.Description($4);
		pts.Address($5);
		pts.InputQuantity($6);
		pts.RefRecord($7);
		pts.MaxDiff($8);
		pts.Conversion($9);
		pts.MaxAxisPoints($10);
		pts.LowerLimit($11);
		pts.UpperLimit($12);
	};
axis_pts_attributes: %empty
	| axis_pts_attributes axis_pts_attribute;
axis_pts_attribute: annotation { scanner.CurrentAxisPts().AddAnnotation($1); }
	| byte_order { scanner.CurrentAxisPts().ByteOrder($1); }
	| calibration_access { scanner.CurrentAxisPts().CalibrationAccess($1); }
	| deposit { scanner.CurrentAxisPts().Deposit($1); }
	| display_identifier { scanner.CurrentAxisPts().DisplayIdentifier($1); }
	| ecu_address_extension { scanner.CurrentAxisPts().EcuAddressExtension($1); }
	| extended_limits { scanner.CurrentAxisPts().ExtendedLimits($1); }
	| format { scanner.CurrentAxisPts().Format($1); }
	| function_list { scanner.CurrentAxisPts().FunctionList($1); }
	| guard_rails { scanner.CurrentAxisPts().GuardRails(true); }
	| if_data { scanner.CurrentAxisPts().AddIfData($1); }
	| max_refresh { scanner.CurrentAxisPts().MaxRefresh($1); }
	| model_link { scanner.CurrentAxisPts().ModelLink($1); }
	| monotony { scanner.CurrentAxisPts().Monotony($1); }
	| phys_unit { scanner.CurrentAxisPts().PhysUnit($1); }
	| read_only { scanner.CurrentAxisPts().ReadOnly(true); }
	| ref_memory_segment { scanner.CurrentAxisPts().RefMemorySegment($1); }
	| step_size { scanner.CurrentAxisPts().StepSize($1); }
	| symbol_link{ scanner.CurrentAxisPts().SymbolLink($1); };

bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION {
	auto& operation = scanner.CurrentBitOperation();
	$$ = operation;
	operation = {};
};
bit_operation_attributes: %empty
	| bit_operation_attributes bit_operation_attribute;
bit_operation_attribute: left_shift { scanner.CurrentBitOperation().LeftShift = $1; }
	| right_shift { scanner.CurrentBitOperation().RightShift = $1; }
	| sign_extend { scanner.CurrentBitOperation().SignExtended = true; };

blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB {
	auto& blob = scanner.CurrentBlob();
	blob.Name($3);
	blob.Description($4);
	blob.Address($5);
	blob.Size($6);
};
blob_attributes: %empty
	| blob_attributes blob_attribute;
blob_attribute: address_type { scanner.CurrentBlob().AddressType($1); }
	| annotation { scanner.CurrentBlob().AddAnnotation($1); }
	| calibration_access { scanner.CurrentBlob().CalibrationAccess($1); }
	| display_identifier { scanner.CurrentBlob().DisplayIdentifier($1); }
	| ecu_address_extension { scanner.CurrentBlob().EcuAddressExtension($1); }
	| if_data { scanner.CurrentBlob().AddIfData($1); }
	| max_refresh { scanner.CurrentBlob().MaxRefresh($1); }
	| model_link { scanner.CurrentBlob().ModelLink($1); }
	| symbol_link { scanner.CurrentBlob().SymbolLink($1); };

calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE {
	$$.HandleList = $3;
	$$.Comment = $4;
};
calibration_handle_attribute: %empty {}
	| calibration_handle_text { $$ = $1; };

calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint
	calibration_method_attributes A2L_END CALIBRATION_METHOD {
	$$.Method = $3;
	$$.Version = $4;
	$$.CalibrationHandleList = $5;
	};
calibration_method_attributes: %empty {}
	| calibration_method_attributes calibration_handle {
	$$ = $1;
	$$.emplace_back($2);
	};

characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float
	characteristic_attributes A2L_END CHARACTERISTIC {
	auto& object = scanner.CurrentCharacteristic();
	object.Name($3);
	object.Description($4);
	object.Type(StringToCharacteristicType($5));
	object.Address($6);
	object.Deposit($7);
	object.MaxDiff($8);
	object.Conversion($9);
	object.LowerLimit($10);
	object.UpperLimit($11);
	};
characteristic_attributes: %empty
	| characteristic_attributes characteristic_attribute;
characteristic_attribute: annotation { scanner.CurrentCharacteristic().AddAnnotation($1); }
	| axis_descr { auto& object = scanner.CurrentCharacteristic();
		       object.AddAxisDescr(scanner.ReleaseAxisDescr());
		}
	| bit_mask { scanner.CurrentCharacteristic().BitMask($1); }
	| byte_order { scanner.CurrentCharacteristic().ByteOrder($1); }
	| calibration_access { scanner.CurrentCharacteristic().CalibrationAccess($1); }
	| comparison_quantity { scanner.CurrentCharacteristic().ComparisonQuantity($1); }
	| dependent_characteristic { scanner.CurrentCharacteristic().DependentCharacteristic($1); }
	| discrete { scanner.CurrentCharacteristic().Discrete(true); }
	| display_identifier { scanner.CurrentCharacteristic().DisplayIdentifier($1); }
	| ecu_address_extension { scanner.CurrentCharacteristic().EcuAddressExtension($1); }
	| encoding { scanner.CurrentCharacteristic().Encoding($1); }
	| extended_limits { scanner.CurrentCharacteristic().ExtendedLimits($1); }
	| format { scanner.CurrentCharacteristic().Format($1); }
	| function_list { scanner.CurrentCharacteristic().FunctionList($1); }
	| guard_rails { scanner.CurrentCharacteristic().GuardRails(true); }
	| if_data { scanner.CurrentCharacteristic().AddIfData($1); }
	| map_list { scanner.CurrentCharacteristic().MapList($1); }
	| matrix_dim { scanner.CurrentCharacteristic().MatrixDim($1); }
	| max_refresh { scanner.CurrentCharacteristic().MaxRefresh($1); }
	| model_link { scanner.CurrentCharacteristic().ModelLink($1); }
	| number { scanner.CurrentCharacteristic().Number($1); }
	| phys_unit { scanner.CurrentCharacteristic().PhysUnit($1); }
	| read_only { scanner.CurrentCharacteristic().ReadOnly(true); }
	| ref_memory_segment { scanner.CurrentCharacteristic().RefMemorySegment($1); }
	| step_size { scanner.CurrentCharacteristic().StepSize($1); }
	| symbol_link { scanner.CurrentCharacteristic().SymbolLink($1); }
	| virtual_characteristic { scanner.CurrentCharacteristic().VirtualCharacteristic($1); };

compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD {
	auto& method = scanner.CurrentCompuMethod();
	method.Name($3);
	method.Description($4);
	method.Type(StringToConversionType($5));
	method.Format($6);
	method.PhysUnit($7);
};

compu_method_attributes: %empty
	| compu_method_attributes compu_method_attribute;
compu_method_attribute: coeffs { scanner.CurrentCompuMethod().Coeffs($1); }
	| coeffs_linear { scanner.CurrentCompuMethod().CoeffsLinear($1); }
	| compu_tab_ref { scanner.CurrentCompuMethod().CompuTabRef($1); }
	| formula {
		auto& method = scanner.CurrentCompuMethod();
		method.Formula($1.first);
		method.Formula($1.second);
	}
	| ref_unit { scanner.CurrentCompuMethod().RefUnit($1); }
	| status_string_ref { scanner.CurrentCompuMethod().StatusStringRef($1); };

compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list
compu_tab_attributes A2L_END COMPU_TAB {
	auto& tab = scanner.CurrentCompuTab();
	tab.Name($3);
	tab.Description($4);
	tab.Type(StringToConversionType($5));
	tab.Rows($6);
	tab.KeyValueList($7);
	};
compu_tab_attributes: %empty
	| compu_tab_attributes compu_tab_attribute;
compu_tab_attribute: default_value { scanner.CurrentCompuTab().DefaultValue($1); }
	| default_value_numeric { scanner.CurrentCompuTab().DefaultValueNumeric($1); };

compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list
	compu_vtab_attributes A2L_END COMPU_VTAB {
	auto& tab = scanner.CurrentCompuVtab();
	tab.Name($3);
	tab.Description($4);
	tab.Type(StringToConversionType($5));
	tab.Rows($6);
	tab.KeyValueList($7);
	};
compu_vtab_attributes: %empty
	| compu_vtab_attributes compu_vtab_attribute;
compu_vtab_attribute: default_value { scanner.CurrentCompuVtab().DefaultValue($1); };

compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list
	compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE {
       	auto& tab = scanner.CurrentCompuVtabRange();
       	tab.Name($3);
       	tab.Description($4);
       	tab.Rows($5);
        tab.KeyValueList($6);
       	};
compu_vtab_range_attributes: %empty
	| compu_vtab_range_attributes compu_vtab_range_attribute;
compu_vtab_range_attribute: default_value { scanner.CurrentCompuVtab().DefaultValue($1); };

def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC { $$ = $3; };

dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING
	ident_list A2L_END DEPENDENT_CHARACTERISTIC {$$ = {$3, $4}; };

fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST { $$ = $3; };

formula: A2L_BEGIN FORMULA STRING formula_attribute A2L_END FORMULA { $$ = {$3,$4}; };
formula_attribute: %empty {}
	| formula_inv {$$ = $1;};

frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME {
	auto& frame = scanner.CurrentFrame();
	frame.Name($3);
	frame.Description($4);
	frame.ScalingUnit($5);
	frame.Rate($6);
};
frame_attributes: %empty
	| frame_attributes frame_attribute;
frame_attribute: frame_measurement { scanner.CurrentFrame().FrameMeasurement($1); }
	| if_data { scanner.CurrentFrame().AddIfData($1); };

function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION {
	auto& func = scanner.CurrentFunction();
	func.Name($3);
	func.Description($4);
};
function_attributes: %empty
	| function_attributes function_attribute;
function_attribute: annotation { scanner.CurrentFunction().AddAnnotation($1);}
        | ar_component
        | def_characteristic { scanner.CurrentFunction().DefaultCharacteristics($1);}
        | function_version { scanner.CurrentFunction().Version($1);}
        | if_data { scanner.CurrentFunction().AddIfData($1);}
        | in_measurement { scanner.CurrentFunction().InMeasurements($1);}
        | loc_measurement { scanner.CurrentFunction().LocMeasurements($1);}
        | out_measurement { scanner.CurrentFunction().OutMeasurements($1);}
        | ref_characteristic { scanner.CurrentFunction().RefCharacteristics($1);}
        | sub_function { scanner.CurrentFunction().SubFunctions($1);};

function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST { $$ = $3;}
	| FUNCTION_LIST ident_list { $$ = $2; };

group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP {
	auto& group = scanner.CurrentGroup();
	group.Name($3);
	group.Description($4);
};

group_attributes: %empty
	| group_attributes group_attribute;
group_attribute: annotation { scanner.CurrentGroup().AddAnnotation($1); }
	| function_list { scanner.CurrentGroup().FunctionList($1); }
	| if_data { scanner.CurrentGroup().AddIfData($1); }
	| ref_characteristic { scanner.CurrentGroup().RefCharacteristics($1); }
	| ref_measurement { scanner.CurrentGroup().RefMeasurements($1); }
	| root { scanner.CurrentGroup().Root(true); }
	| sub_group { scanner.CurrentGroup().SubGroups($1); };

header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER {
	auto& header = file.Project().Header();
	header.Comment = $3;
};

header_attributes: %empty
    | header_attributes header_attribute;

header_attribute: project_no {
	auto& header = file.Project().Header();
	header.ProjectNo = $1;
}	| version {
	auto& header = file.Project().Header();
	header.VersionNo = $1;
};

in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT { $$ = $3; };

instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE {
	auto& instance = scanner.CurrentInstance();
	instance.Name($3);
	instance.Description($4);
	instance.RefTypeDef($5);
	instance.Address($6);
};
instance_attributes: %empty
	| instance_attributes instance_attribute;
instance_attribute: address_type { scanner.CurrentInstance().AddressType($1); }
	| annotation { scanner.CurrentInstance().AddAnnotation($1); }
	| calibration_access { scanner.CurrentInstance().CalibrationAccess($1); }
	| display_identifier {  scanner.CurrentInstance().DisplayIdentifier($1); }
	| ecu_address_extension {  scanner.CurrentInstance().EcuAddressExtension($1); }
	| if_data { scanner.CurrentInstance().AddIfData($1); }
	| layout {  scanner.CurrentInstance().Layout($1); }
	| matrix_dim {  scanner.CurrentInstance().MatrixDim($1); }
	| max_refresh {  scanner.CurrentInstance().MaxRefresh($1); }
	| model_link {  scanner.CurrentInstance().ModelLink($1); }
	| overwrite { auto& instance = scanner.CurrentInstance();
	              instance.AddOverwrite(scanner.ReleaseOverwrite()); }
	| read_write { scanner.CurrentInstance().ReadWrite(true); }
	| symbol_link { scanner.CurrentInstance().SymbolLink($1); };

loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT { $$ = $3;};

map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST { $$ = $3;};

measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float
	measurement_attributes A2L_END MEASUREMENT {
	auto& meas = scanner.CurrentMeasurement();
	meas.Name($3);
	meas.Description($4);
	meas.DataType(StringToDataType($5));
	meas.Conversion($6);
	meas.Resolution($7);
	meas.Accuracy($8);
	meas.LowerLimit($9);
	meas.UpperLimit($10);
	};
measurement_attributes: %empty
	| measurement_attributes measurement_attribute;
measurement_attribute: address_type { scanner.CurrentMeasurement().AddressType($1); }
	| annotation { scanner.CurrentMeasurement().AddAnnotation($1); }
	| array_size { scanner.CurrentMeasurement().ArraySize($1); }
	| bit_mask { scanner.CurrentMeasurement().BitMask($1); }
	| bit_operation { scanner.CurrentMeasurement().BitOperation($1); }
	| byte_order { scanner.CurrentMeasurement().ByteOrder($1); }
	| discrete { scanner.CurrentMeasurement().Discrete(true); }
	| display_identifier { scanner.CurrentMeasurement().DisplayIdentifier($1); }
	| ecu_address { scanner.CurrentMeasurement().EcuAddress($1); }
	| ecu_address_extension { scanner.CurrentMeasurement().EcuAddressExtension($1); }
	| error_mask { scanner.CurrentMeasurement().ErrorMask($1); }
	| format { scanner.CurrentMeasurement().Format($1); }
	| function_list { scanner.CurrentMeasurement().FunctionList($1); }
	| if_data { scanner.CurrentMeasurement().AddIfData($1); }
	| layout { scanner.CurrentMeasurement().Layout($1); }
	| matrix_dim { scanner.CurrentMeasurement().MatrixDim($1); }
	| max_refresh { scanner.CurrentMeasurement().MaxRefresh($1); }
	| model_link { scanner.CurrentMeasurement().ModelLink($1); }
	| phys_unit { scanner.CurrentMeasurement().PhysUnit($1); }
	| read_write { scanner.CurrentMeasurement().ReadWrite(true); }
	| ref_memory_segment { scanner.CurrentMeasurement().RefMemorySegment($1); }
	| symbol_link { scanner.CurrentMeasurement().SymbolLink($1); }
	| virtual { scanner.CurrentMeasurement().Virtuals($1); };

memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list
	memory_layout_attributes A2L_END MEMORY_LAYOUT {
	$$.Type = StringToPrgType($3);
	$$.Address = $4;
	$$.Size = $5;
	$$.OffsetList = $6;
	};
memory_layout_attributes: %empty {}
	| memory_layout_attributes if_data { $$ = $1; $$.emplace_back($2); };

prg_type: RESERVED {$$ = A2lSegmentType::RESERVED; }
	| IDENT {$$ = StringToSegmentType($1); };

memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list
	memory_segment_attributes A2L_END MEMORY_SEGMENT {
	$$.Name = $3;
	$$.Description = $4;
	$$.SegmentType = $5;
	$$.MemoryType = StringToMemoryType($6);
	$$.Attribute = StringToMemoryAttribute($7);
	$$.Address = $8;
	$$.Size = $9;
	$$.OffsetList = $10;
	$$.IfDataList = $11;
	};
memory_segment_attributes: %empty {}
	| memory_segment_attributes if_data {$$ = $1; $$.emplace_back($2);};
mod_common : A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON {
	auto& common = scanner.CurrentModule().ModCommon();
	common.Comment = $3;
};

mod_common_attributes: %empty
	| mod_common_attributes mod_common_attribute;
mod_common_attribute: alignment_byte { scanner.CurrentModule().ModCommon().AlignmentByte = $1; }
	| alignment_float16_ieee { scanner.CurrentModule().ModCommon().AlignmentFloat16 = $1; }
	| alignment_float32_ieee { scanner.CurrentModule().ModCommon().AlignmentFloat32 = $1; }
	| alignment_float64_ieee { scanner.CurrentModule().ModCommon().AlignmentFloat64 = $1; }
	| alignment_int64 { scanner.CurrentModule().ModCommon().AlignmentInt64 = $1; }
	| alignment_long { scanner.CurrentModule().ModCommon().AlignmentLong = $1; }
	| alignment_word { scanner.CurrentModule().ModCommon().AlignmentWord = $1; }
	| byte_order { scanner.CurrentModule().ModCommon().ByteOrder = $1; }
	| data_size { scanner.CurrentModule().ModCommon().DataSize = $1; }
	| deposit { scanner.CurrentModule().ModCommon().Deposit = $1; }
	| s_rec_layout; // Not in use anymore

mod_par : A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR {
	auto& par = scanner.CurrentModule().ModPar();
	par.Comment = $3;
};
mod_par_attributes: %empty
	| mod_par_attributes mod_par_attribute;
mod_par_attribute: addr_epk { scanner.CurrentModule().ModPar().AddressEpkList.emplace_back($1); }
	| calibration_method { scanner.CurrentModule().ModPar().CalibrationMethodList.emplace_back($1); }
	| cpu_type { scanner.CurrentModule().ModPar().CpuType = $1; }
	| customer { scanner.CurrentModule().ModPar().Customer = $1; }
	| customer_no { scanner.CurrentModule().ModPar().CustomerNo = $1; }
	| ecu { scanner.CurrentModule().ModPar().Ecu = $1; }
	| ecu_calibration_offset { scanner.CurrentModule().ModPar().EcuCalibrationOffset = $1; }
	| epk { scanner.CurrentModule().ModPar().Epk = $1; }
	| memory_layout { scanner.CurrentModule().ModPar().MemoryLayoutList.emplace_back($1); }
	| memory_segment { scanner.CurrentModule().ModPar().MemorySegmentList.emplace_back($1); }
	| no_of_interfaces { scanner.CurrentModule().ModPar().NoOfInterfaces = $1; }
	| phone_no { scanner.CurrentModule().ModPar().PhoneNo = $1; }
	| supplier { scanner.CurrentModule().ModPar().Supplier = $1; }
	| system_constant { scanner.CurrentModule().ModPar().SystemConstantList.emplace($1.first, $1.second); }
	| user { scanner.CurrentModule().ModPar().User = $1; }
	| version { scanner.CurrentModule().ModPar().Version = $1; };

module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE {
	auto& module = scanner.CurrentModule();
	module.Name($3);
	module.Description($4);
};

module_attributes: %empty
    | module_attributes module_attribute;
module_attribute : a2ml { scanner.CurrentModule().A2ml($1); }
    	| axis_pts {
    		auto& module = scanner.CurrentModule();
    		module.AddAxisPts(scanner.ReleaseAxisPts()); }
    	| blob {
                auto& module = scanner.CurrentModule();
                module.AddBlob(scanner.ReleaseBlob()); }
    	| characteristic {
                auto& module = scanner.CurrentModule();
                module.AddCharacteristic(scanner.ReleaseCharacteristic()); }
    	| compu_method {
                auto& module = scanner.CurrentModule();
                module.AddCompuMethod(scanner.ReleaseCompuMethod()); }
    	| compu_tab {
                auto& module = scanner.CurrentModule();
                module.AddCompuTab(scanner.ReleaseCompuTab()); }
    	| compu_vtab {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtab(scanner.ReleaseCompuVtab()); }
    	| compu_vtab_range {
                auto& module = scanner.CurrentModule();
                module.AddCompuVtabRange(scanner.ReleaseCompuVtabRange()); }
    	| frame {
                auto& module = scanner.CurrentModule();
                module.AddFrame(scanner.ReleaseFrame()); }
    	| function {
                auto& module = scanner.CurrentModule();
                module.AddFunction(scanner.ReleaseFunction()); }
    	| group {
                auto& module = scanner.CurrentModule();
                module.AddGroup(scanner.ReleaseGroup()); }
    	| if_data {
                auto& module = scanner.CurrentModule();
                module.AddIfData($1); }
    	| instance {
                auto& module = scanner.CurrentModule();
                module.AddInstance(scanner.ReleaseInstance()); }
    	| measurement {
                auto& module = scanner.CurrentModule();
                module.AddMeasurement(scanner.ReleaseMeasurement()); }
    	| mod_common
   	| mod_par
   	| record_layout {
	       auto& module = scanner.CurrentModule();
	       module.AddRecordLayout(scanner.ReleaseRecordLayout()); }
   	| transformer {
	       auto& module = scanner.CurrentModule();
	       module.AddTransformer(scanner.ReleaseTransformer()); }
   	| typedef_axis {
	       auto& module = scanner.CurrentModule();
	       module.AddTypedefAxis(scanner.ReleaseTypedefAxis()); }
   	| typedef_blob {
           auto& module = scanner.CurrentModule();
           module.AddTypedefBlob(scanner.ReleaseTypedefBlob()); }
   	| typedef_characteristic {
           auto& module = scanner.CurrentModule();
           module.AddTypedefCharacteristic(scanner.ReleaseTypedefCharacteristic()); }
   	| typedef_measurement {
            auto& module = scanner.CurrentModule();
            module.AddTypedefMeasurement(scanner.ReleaseTypedefMeasurement()); }
   	| typedef_structure {
           auto& module = scanner.CurrentModule();
           module.AddTypedefStructure(scanner.ReleaseTypedefStructure()); }
   	| unit {
         auto& module = scanner.CurrentModule();
         module.AddUnit(scanner.ReleaseUnit()); }
   	| user_rights {
          auto& module = scanner.CurrentModule();
          module.AddUserRight(scanner.ReleaseUserRight()); }
   	| variant_coding;

out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT { $$ = $3; };

overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE {
	auto& overwrite = scanner.CurrentOverwrite();
	overwrite.Name($3);
	overwrite.AxisNo($4);
};
overwrite_attributes: %empty
	| overwrite_attributes overwrite_attribute;
overwrite_attribute: conversion { scanner.CurrentOverwrite().Conversion($1); }
	| extended_limits { scanner.CurrentOverwrite().ExtendedLimits($1); }
	| format { scanner.CurrentOverwrite().Format($1); }
	| input_quantity { scanner.CurrentOverwrite().InputQuantity($1); }
	| limits { scanner.CurrentOverwrite().Limits($1); }
	| monotony { scanner.CurrentOverwrite().Monotony($1); }
	| phys_unit { scanner.CurrentOverwrite().PhysUnit($1); };

project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT {
	auto& project = file.Project();
	project.Name($3);
	project.Description($4);
};
project_attributes : project_attribute
    | project_attributes project_attribute;
project_attribute: header
    | module {
    	auto& project = file.Project();
        project.AddModule(scanner.ReleaseModule());
    };

record_layout: A2L_BEGIN RECORD_LAYOUT IDENT record_layout_attributes A2L_END RECORD_LAYOUT {
	auto& rec = scanner.CurrentRecordLayout();
	rec.Name($3);
};
record_layout_attributes: %empty
	| record_layout_attributes record_layout_attribute;
record_layout_attribute: alignment_byte { scanner.CurrentRecordLayout().AlignmentByte($1); }
	| alignment_float16_ieee { scanner.CurrentRecordLayout().AlignmentFloat16($1); }
	| alignment_float32_ieee { scanner.CurrentRecordLayout().AlignmentFloat32($1); }
	| alignment_float64_ieee { scanner.CurrentRecordLayout().AlignmentFloat64($1); }
	| alignment_int64 { scanner.CurrentRecordLayout().AlignmentInt64($1); }
	| alignment_long { scanner.CurrentRecordLayout().AlignmentLong($1); }
	| alignment_word { scanner.CurrentRecordLayout().AlignmentWord($1); }
	| axis_pts_x { scanner.CurrentRecordLayout().AxisPtsX($1); }
	| axis_pts_y { scanner.CurrentRecordLayout().AxisPtsY($1); }
	| axis_pts_z { scanner.CurrentRecordLayout().AxisPtsZ($1); }
	| axis_pts_4 { scanner.CurrentRecordLayout().AxisPts4($1); }
	| axis_pts_5 { scanner.CurrentRecordLayout().AxisPts5($1); }
	| axis_rescale_x { scanner.CurrentRecordLayout().AxisRescaleX($1); }
	| dist_op_x { scanner.CurrentRecordLayout().DistOpX($1); }
	| dist_op_y { scanner.CurrentRecordLayout().DistOpY($1); }
	| dist_op_z { scanner.CurrentRecordLayout().DistOpZ($1); }
	| dist_op_4 { scanner.CurrentRecordLayout().DistOp4($1); }
	| dist_op_5 { scanner.CurrentRecordLayout().DistOp5($1); }
	| fix_no_axis_pts_x { scanner.CurrentRecordLayout().FixNoAxisPtsX($1); }
	| fix_no_axis_pts_y { scanner.CurrentRecordLayout().FixNoAxisPtsY($1); }
	| fix_no_axis_pts_z { scanner.CurrentRecordLayout().FixNoAxisPtsZ($1); }
	| fix_no_axis_pts_4 { scanner.CurrentRecordLayout().FixNoAxisPts4($1); }
	| fix_no_axis_pts_5 { scanner.CurrentRecordLayout().FixNoAxisPts5($1); }
	| fnc_values { scanner.CurrentRecordLayout().FncValues($1); }
	| identification { scanner.CurrentRecordLayout().Identification($1); }
	| no_axis_pts_x { scanner.CurrentRecordLayout().NoAxisPtsX($1); }
	| no_axis_pts_y { scanner.CurrentRecordLayout().NoAxisPtsY($1); }
	| no_axis_pts_z { scanner.CurrentRecordLayout().NoAxisPtsZ($1); }
	| no_axis_pts_4 { scanner.CurrentRecordLayout().NoAxisPts4($1); }
	| no_axis_pts_5 { scanner.CurrentRecordLayout().NoAxisPts5($1); }
	| no_rescale_x { scanner.CurrentRecordLayout().NoRescaleX($1); }
	| offset_x { scanner.CurrentRecordLayout().OffsetX($1); }
	| offset_y { scanner.CurrentRecordLayout().OffsetY($1); }
	| offset_z { scanner.CurrentRecordLayout().OffsetZ($1); }
	| offset_4 { scanner.CurrentRecordLayout().Offset4($1); }
	| offset_5 { scanner.CurrentRecordLayout().Offset5($1); }
	| reserved { scanner.CurrentRecordLayout().AddReserved($1); }
	| rip_addr_w { scanner.CurrentRecordLayout().RipAddrW($1); }
	| rip_addr_x { scanner.CurrentRecordLayout().RipAddrX($1); }
	| rip_addr_y { scanner.CurrentRecordLayout().RipAddrY($1); }
	| rip_addr_z { scanner.CurrentRecordLayout().RipAddrZ($1); }
	| rip_addr_4 { scanner.CurrentRecordLayout().RipAddr4($1); }
	| rip_addr_5 { scanner.CurrentRecordLayout().RipAddr5($1); }
	| src_addr_x { scanner.CurrentRecordLayout().SrcAddrX($1); }
	| src_addr_y { scanner.CurrentRecordLayout().SrcAddrY($1); }
	| src_addr_z { scanner.CurrentRecordLayout().SrcAddrZ($1); }
	| src_addr_4 { scanner.CurrentRecordLayout().SrcAddr4($1); }
	| src_addr_5 { scanner.CurrentRecordLayout().SrcAddr5($1); }
	| shift_op_x { scanner.CurrentRecordLayout().ShiftOpX($1); }
	| shift_op_y { scanner.CurrentRecordLayout().ShiftOpY($1); }
	| shift_op_z { scanner.CurrentRecordLayout().ShiftOpZ($1); }
	| shift_op_4 { scanner.CurrentRecordLayout().ShiftOp4($1); }
	| shift_op_5 { scanner.CurrentRecordLayout().ShiftOp5($1); }
	| static_address_offsets { scanner.CurrentRecordLayout().StaticAddressOffsets(true); }
	| static_record_layout { scanner.CurrentRecordLayout().StaticRecordLayout(true); };

ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC { $$ = $3; };
ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP { $$ = $3; };
ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT { $$ = $3; };

structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint
    structure_component_attributes A2L_END STRUCTURE_COMPONENT {
        auto& structure = scanner.CurrentStructureComponent();
        structure.Name = $3;
        structure.Type = StringToTypedefType($4);
        structure.AddressOffset = $5;
    };
structure_component_attributes: %empty
	| structure_component_attributes structure_component_attribute;
structure_component_attribute: address_type { scanner.CurrentStructureComponent().AddressType = $1; }
	| layout { scanner.CurrentStructureComponent().Layout = $1; }
	| matrix_dim { scanner.CurrentStructureComponent().MatrixDim = $1; }
	| symbol_type_link { scanner.CurrentStructureComponent().SymbolTypeLink = $1; };

sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION { $$ = $3; };
sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP { $$ = $3; };

transformer: A2L_BEGIN TRANSFORMER IDENT STRING STRING STRING any_uint IDENT IDENT
	transformer_attributes A2L_END TRANSFORMER {
	auto& transformer = scanner.CurrentTransformer();
	transformer.Name($3);
	transformer.Version($4);
	transformer.Executable32($5);
	transformer.Executable64($6);
	transformer.Timeout($7);
	transformer.Trigger(StringToTrigger($8));
	transformer.InverseTransformer($9);
	};
transformer_attributes: %empty
	| transformer_attributes transformer_attribute;
transformer_attribute: transformer_in_objects { scanner.CurrentTransformer().TransformerInObjects($1); }
	| transformer_out_objects { scanner.CurrentTransformer().TransformerOutObjects($1); } ;

transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS { $$ = $3; };
transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS { $$ = $3; };

typedef_axis: A2L_BEGIN TYPEDEF_AXIS IDENT STRING IDENT IDENT any_float IDENT any_uint any_float any_float
	typedef_axis_attributes A2L_END TYPEDEF_AXIS {
		auto& pts = scanner.CurrentTypedefAxis();
		pts.Name($3);
		pts.Description($4);
		pts.InputQuantity($5);
		pts.RefRecord($6);
		pts.MaxDiff($7);
		pts.Conversion($8);
		pts.MaxAxisPoints($9);
		pts.LowerLimit($10);
		pts.UpperLimit($11);
	};
typedef_axis_attributes: %empty
	| typedef_axis_attributes typedef_axis_attribute;
typedef_axis_attribute: byte_order { scanner.CurrentTypedefAxis().ByteOrder($1); }
	| deposit { scanner.CurrentTypedefAxis().Deposit($1); }
	| extended_limits { scanner.CurrentTypedefAxis().ExtendedLimits($1); }
	| format { scanner.CurrentTypedefAxis().Format($1); }
	| monotony { scanner.CurrentTypedefAxis().Monotony($1); }
	| phys_unit { scanner.CurrentTypedefAxis().PhysUnit($1); }
	| step_size { scanner.CurrentTypedefAxis().StepSize($1); };

typedef_blob: A2L_BEGIN TYPEDEF_BLOB IDENT STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB {
    auto& blob = scanner.CurrentTypedefBlob();
    blob.Name($3);
    blob.Description($4);
    blob.Size($5);
   };
typedef_blob_attributes: %empty
	| typedef_blob_attributes typedef_blob_attribute;
typedef_blob_attribute: address_type { scanner.CurrentTypedefBlob().AddressType($1); };

typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC IDENT STRING IDENT IDENT any_float IDENT any_float any_float
	typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.Name($3);
        object.Description($4);
        object.Type(StringToCharacteristicType($5));
        object.Deposit($6);
        object.MaxDiff($7);
        object.Conversion($8);
        object.LowerLimit($9);
        object.UpperLimit($10);
        };
typedef_characteristic_attributes: %empty
	| typedef_characteristic_attributes typedef_characteristic_attribute;
typedef_characteristic_attribute: axis_descr {
        auto& object = scanner.CurrentTypedefCharacteristic();
        object.AddAxisDescr(scanner.ReleaseAxisDescr());
        }
	| bit_mask { scanner.CurrentTypedefCharacteristic().BitMask($1); }
	| byte_order { scanner.CurrentTypedefCharacteristic().ByteOrder($1); }
	| discrete { scanner.CurrentTypedefCharacteristic().Discrete(true); }
	| encoding { scanner.CurrentTypedefCharacteristic().Encoding($1); }
	| extended_limits { scanner.CurrentTypedefCharacteristic().ExtendedLimits($1); }
	| format { scanner.CurrentTypedefCharacteristic().Format($1); }
	| matrix_dim { scanner.CurrentTypedefCharacteristic().MatrixDim($1); }
	| number { scanner.CurrentTypedefCharacteristic().Number($1); }
	| phys_unit { scanner.CurrentTypedefCharacteristic().PhysUnit($1); }
	| step_size { scanner.CurrentTypedefCharacteristic().StepSize($1); };

typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT IDENT STRING IDENT IDENT UINT any_float any_float any_float
			typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT {
    auto& meas = scanner.CurrentTypedefMeasurement();
    meas.Name($3);
    meas.Description($4);
    meas.DataType(StringToDataType($5));
    meas.Conversion($6);
    meas.Resolution($7);
    meas.Accuracy($8);
    meas.LowerLimit($9);
    meas.UpperLimit($10);
    };
typedef_measurement_attributes: %empty
	| typedef_measurement_attributes typedef_measurement_attribute;
typedef_measurement_attribute: address_type { scanner.CurrentTypedefMeasurement().AddressType($1); }
	| bit_mask { scanner.CurrentTypedefMeasurement().BitMask($1); }
	| bit_operation { scanner.CurrentTypedefMeasurement().BitOperation($1); }
	| byte_order { scanner.CurrentTypedefMeasurement().ByteOrder($1); }
	| discrete { scanner.CurrentTypedefMeasurement().Discrete(true); }
	| error_mask { scanner.CurrentTypedefMeasurement().ErrorMask($1); }
	| format { scanner.CurrentTypedefMeasurement().Format($1); }
	| layout { scanner.CurrentTypedefMeasurement().Layout($1); }
	| matrix_dim { scanner.CurrentTypedefMeasurement().MatrixDim($1); }
	| phys_unit { scanner.CurrentTypedefMeasurement().PhysUnit($1); };

typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE IDENT STRING UINT
		typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE {
		auto& structure = scanner.CurrentTypedefStructure();
		structure.Name($3);
		structure.Description($4);
		structure.Size($5);
		};
typedef_structure_attributes: %empty
	| typedef_structure_attributes typedef_structure_attribute;
typedef_structure_attribute: address_type { scanner.CurrentTypedefStructure().AddressType($1); }
	| consistent_exchange{ scanner.CurrentTypedefStructure().ConsistentExchange(true); }
	| structure_component{
	    auto& structure = scanner.CurrentTypedefStructure();
	    structure.AddStructureComponent(scanner.ReleaseStructureComponent()); }
	| symbol_type_link{ scanner.CurrentTypedefStructure().SymbolTypeLink($1); };

unit: A2L_BEGIN UNIT IDENT STRING STRING IDENT unit_attributes A2L_END UNIT {
        auto& unit = scanner.CurrentUnit();
        unit.Name($3);
        unit.Description($4);
        unit.DisplayIdentifier($5);
        unit.Type(StringToUnitType($6));
        };
unit_attributes: %empty
	| unit_attributes unit_attribute;
unit_attribute: ref_unit { scanner.CurrentUnit().RefUnit($1); }
	| si_exponents { scanner.CurrentUnit().SiExponents($1); }
	| unit_conversion {
	    scanner.CurrentUnit().Gradient($1.first);
	    scanner.CurrentUnit().Offset($1.second);
	    };

user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS {
       auto& user_right = scanner.CurrentUserRight();
       user_right.UserLevelId = $3;
       };
user_rights_attributes: %empty
	| user_rights_attributes user_rights_attribute;
user_rights_attribute: read_only { scanner.CurrentUserRight().ReadOnly = true; }
	| ref_group { scanner.CurrentUserRight().RefGroupList.emplace_back($1); } ;

var_address: A2L_BEGIN VAR_ADDRESS uint_list A2L_END VAR_ADDRESS { $$ = $3; };

var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list
    var_characteristic_attribute A2L_END VAR_CHARACTERISTIC {
    $$.Name = $3;
    $$.CriterionNameList = $4;
    $$.AddressList = $5;
    };
var_characteristic_attribute: %empty {}
	| var_address { $$ = $1; };

var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION {
    $$ = scanner.VarCriterion();
    scanner.VarCriterion() = {};
    $$.Name = $3;
    $$.Description = $4;
};

var_criterion_attributes: %empty
	| var_criterion_attributes var_criterion_attribute;
var_criterion_attribute: var_measurement { scanner.VarCriterion().Measurement = $1; }
	| var_selection_characteristic { scanner.VarCriterion().SelectionCharacteristic = $1; };

var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB { $$= $3; };

variant_coding: A2L_BEGIN VARIANT_CODING variant_coding_attributes A2L_END VARIANT_CODING;
variant_coding_attributes: %empty
	| variant_coding_attributes variant_coding_attribute;
variant_coding_attribute: var_characteristic {
        auto& coding = scanner.CurrentModule().VariantCoding();
        coding.CharacteristicList.emplace($1.Name, $1);
        }
	| var_criterion{
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.CriterionList.emplace($1.Name, $1);
       }
	| var_forbidden_comb{
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.ForbiddenCombList.emplace_back($1);
       }
	| var_naming{
       auto& coding = scanner.CurrentModule().VariantCoding();
       coding.Naming = $1;
       }
	| var_separator{
      auto& coding = scanner.CurrentModule().VariantCoding();
      coding.Separator = $1;
      };

virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL { $$ = $3; };
virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING
	ident_list A2L_END VIRTUAL_CHARACTERISTIC {$$ = {$3, $4}; };


a2ml : A2ML { $$ = $1; };
a2ml_version: A2ML_VERSION any_uint any_uint {
	file.A2mlVersion().VersionNo = $2;
	file.A2mlVersion().VersionNo = $3;
};

asap2_version : ASAP2_VERSION any_uint any_uint {
	file.A2lVersion().VersionNo = $2;
	file.A2lVersion().UpgradeNo = $3;
} | ASAP2_VERSION STRING {
	file.A2lVersion().FromString($2);
};

addr_epk: ADDR_EPK any_uint { $$ = $2; };
address_type: ADDRESS_TYPE IDENT {$$ = StringToAddressType($2); };
alignment_byte: ALIGNMENT_BYTE any_uint { $$ = $2; };
alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint { $$ = $2; };
alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint { $$ = $2; };
alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint { $$ = $2; };
alignment_int64: ALIGNMENT_INT64 any_uint { $$ = $2; };
alignment_long: ALIGNMENT_LONG any_uint { $$ = $2; };
alignment_word: ALIGNMENT_WORD any_uint { $$ = $2; };
annotation_label: ANNOTATION_LABEL STRING { $$ = $2; };
annotation_origin: ANNOTATION_ORIGIN STRING { $$ = $2; };
array_size: ARRAY_SIZE any_uint { $$ = $2; };
ar_prototype_of: AR_PROTOTYPE_OF IDENT {$$ = $2;};
axis_pts_ref: AXIS_PTS_REF IDENT { $$ = $2; };
axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.IndexOrder = StringToIndexOrder($4);
	$$.AddressType = StringToAddressType($5);
	};
axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.IndexOrder = StringToIndexOrder($4);
	$$.AddressType = StringToAddressType($5);
	};
axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.IndexOrder = StringToIndexOrder($4);
	$$.AddressType = StringToAddressType($5);
	};
axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.IndexOrder = StringToIndexOrder($4);
	$$.AddressType = StringToAddressType($5);
	};
axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.IndexOrder = StringToIndexOrder($4);
	$$.AddressType = StringToAddressType($5);
	};
axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.MaxNoRescalePairs = $4;
	$$.IndexOrder = StringToIndexOrder($5);
	$$.AddressType = StringToAddressType($6);
	};
bit_mask: BIT_MASK any_uint { $$ = $2; };
byte_order: BYTE_ORDER IDENT { $$ = StringToByteOrder($2); };
calibration_access: CALIBRATION_ACCESS IDENT { $$ = StringToCalibrationAccess($2); };
calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING { $$ = $2; };
coeffs: COEFFS any_float any_float any_float any_float any_float any_float {
	std::vector<double> list;
	list.push_back($2);
	list.push_back($3);
	list.push_back($4);
	list.push_back($5);
    list.push_back($6);
    list.push_back($7);
    $$ = list;
};
coeffs_linear: COEFFS_LINEAR any_float any_float {
	std::vector<double> list;
	list.push_back($2);
	list.push_back($3);
        $$ = list;
};
comparison_quantity: COMPARISON_QUANTITY IDENT { $$ = $2; };
compu_tab_ref: COMPU_TAB_REF IDENT { $$ = $2; };
consistent_exchange: CONSISTENT_EXCHANGE;
conversion: CONVERSION IDENT { $$ = $2; };
cpu_type: CPU_TYPE STRING { $$ = $2; };
curve_axis_ref: CURVE_AXIS_REF IDENT { $$ = $2; };
customer: CUSTOMER STRING { $$ = $2; };
customer_no: CUSTOMER_NO STRING { $$ = $2; };
data_size: DATA_SIZE any_uint { $$ = $2; };
default_value: DEFAULT_VALUE STRING { $$ = $2; };
default_value_numeric: DEFAULT_VALUE_NUMERIC any_float { $$ = $2; };
deposit: DEPOSIT IDENT { $$ = StringToDeposit($2); };
discrete: DISCRETE;
display_identifier: DISPLAY_IDENTIFIER IDENT { $$ = $2; }
	| A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER {$$ = $3;};
dist_op_x: DIST_OP_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
dist_op_y: DIST_OP_Y any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
dist_op_z: DIST_OP_Z any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
dist_op_4: DIST_OP_4 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
dist_op_5: DIST_OP_5 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
ecu: ECU STRING { $$ = $2; };
ecu_address: ECU_ADDRESS any_uint { $$ = $2; };
ecu_address_extension: ECU_ADDRESS_EXTENSION any_int { $$ = $2; };
ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int { $$ = $2; };
encoding: ENCODING IDENT { $$ = StringToEncoding($2); };
epk: EPK STRING { $$ = $2; };
error_mask: ERROR_MASK any_uint { $$ = $2; };
extended_limits: EXTENDED_LIMITS any_float any_float { $$ = A2lExtendedLimits($2,$3); };
fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint { $$ = {$2, $3, $4}; };
fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint { $$ = {$2, $3, $4}; };
fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint { $$ = $2; };
fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint { $$ = $2; };
fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint { $$ = $2; };
fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint { $$ = $2; };
fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint { $$ = $2; };
fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	$$.IndexMode = StringToIndexMode($4);
	$$.AddressType = StringToAddressType($5);
};
format: FORMAT STRING { $$ = $2; };
formula_inv: FORMULA_INV STRING { $$ = $2; };
frame_measurement: FRAME_MEASUREMENT ident_list { $$ = $2; };
function_version: FUNCTION_VERSION STRING { $$ = $2; };
guard_rails: GUARD_RAILS;
identification: IDENTIFICATION any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
};
if_data : IF_DATA;
input_quantity: INPUT_QUANTITY IDENT { $$ = $2; };
layout: LAYOUT IDENT {$$ = StringToLayout($2); };
left_shift: LEFT_SHIFT any_uint { $$ = $2; };
limits: LIMITS FLOAT any_float {$$ = $2;};
matrix_dim: MATRIX_DIM uint_list { $$ = $2; }
max_grad: MAX_GRAD any_float { $$ = $2; }
max_refresh: MAX_REFRESH any_uint any_uint { $$ = {$2,$3}; };
model_link: MODEL_LINK STRING { $$ = $2; };
monotony: MONOTONY IDENT { $$ = StringToMonotony($2); };
no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
   	};
no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
   	};
no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
    	};
no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
      	};
no_of_interfaces: NO_OF_INTERFACES any_uint { $$ = $2; };
no_rescale_x: NO_RESCALE_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
number: NUMBER any_uint { $$ = $2; };
offset_x: OFFSET_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
offset_y: OFFSET_Y any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
offset_z: OFFSET_Z any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
offset_4: OFFSET_4 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
offset_5: OFFSET_5 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
phone_no: PHONE_NO STRING { $$ = $2; };
phys_unit: PHYS_UNIT STRING { $$ = $2; };
proj_no: IDENT {$$ = $1;}
	| UINT {$$ = std::to_string($1);}; /* Fix so the number may be a number as well */
project_no: PROJECT_NO proj_no { $$ = $2;};

read_only: READ_ONLY;
read_write: READ_WRITE;
ref_memory_segment: REF_MEMORY_SEGMENT IDENT { $$ = $2; };
ref_unit: REF_UNIT IDENT { $$ = $2; };
reserved: RESERVED any_uint IDENT {
	$$.Position = $2;
        $$.DataType = StringToDataType($3);
        };
right_shift: RIGHT_SHIFT any_uint { $$ = $2; };
rip_addr_w: RIP_ADDR_W any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
rip_addr_x: RIP_ADDR_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
rip_addr_y: RIP_ADDR_Y any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
rip_addr_z: RIP_ADDR_Z any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
rip_addr_4: RIP_ADDR_4 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
rip_addr_5: RIP_ADDR_5 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
root: ROOT;
s_rec_layout: S_REC_LAYOUT IDENT;
shift_op_x: SHIFT_OP_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
shift_op_y: SHIFT_OP_Y any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
shift_op_z: SHIFT_OP_Z any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
shift_op_4: SHIFT_OP_4 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
shift_op_5: SHIFT_OP_5 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
sign_extend: SIGN_EXTEND;
si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int {
    $$.Length = $2;
    $$.Mass = $3;
    $$.Time = $4;
    $$.ElectricCurrent = $5;
    $$.Temperature = $6;
    $$.AmountOfSubstance = $7;
    $$.LuminousIntensity = $8;
};
src_addr_x: SRC_ADDR_X any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
src_addr_y: SRC_ADDR_Y any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
src_addr_z: SRC_ADDR_Z any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
src_addr_4: SRC_ADDR_4 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
src_addr_5: SRC_ADDR_5 any_uint IDENT {
	$$.Position = $2;
	$$.DataType = StringToDataType($3);
	};
static_address_offsets: STATIC_ADDRESS_OFFSETS;
static_record_layout: STATIC_RECORD_LAYOUT;
status_string_ref: STATUS_STRING_REF IDENT { $$ = $2;};
step_size: STEP_SIZE any_float { $$ = $2; };
supplier: SUPPLIER STRING { $$ = $2;};
symbol_link: SYMBOL_LINK STRING any_int { $$ = {$2,$3}; };
symbol_type_link: SYMBOL_TYPE_LINK STRING { $$ = $2;};
system_constant: SYSTEM_CONSTANT STRING STRING { $$ = {$2,$3};};
unit_conversion: UNIT_CONVERSION any_float any_float { $$ = {$2,$3};};
user: USER STRING { $$ = $2;};
var_measurement: VAR_MEASUREMENT IDENT { $$ = $2; };
var_naming: VAR_NAMING IDENT { $$ = $2; };
var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT { $$ = $2; };
var_separator: VAR_SEPARATOR STRING { $$ = $2; };
version: A2L_VERSION STRING { $$ = $2;};

%%

void a2l::A2lParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    // const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Near: " << near;
    scanner.LastError(error.str());
}
