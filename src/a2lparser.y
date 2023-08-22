%require "3.2"
%language "c++"

%define api.prefix {a2l}
%define api.namespace {a2l}
%define api.parser.class {A2lParser}


%code requires {
    namespace a2l {
        class A2lScanner;
    }
}

%parse-param { a2l::A2lScanner &scanner  }

%code  {
    #include <sstream>
    #include "a2lscanner.h"
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
%token INT
%token UINT
%token HEX
%token FLOAT


%token ASAP2_VERSION
%token A2L_VERSION
%token A2ML_VERSION
%token A2ML
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
%token IF_DATA
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
/*
%nterm <std::string> attribute_value
%nterm <double> double_val
%nterm <AttributeType> object_type
%nterm <AttributeType> object_rel_type
%nterm <AttributeType> attribute_object_type
%nterm <bool> attribute_definition_object_or_relation
%nterm <std::string> mux_info
%nterm <bool> little_endian
%nterm <SignalDataType> signedness
*/

// %right TAG_NS_DESC TAG_CM
%start a2l_file
%%

a2l_file: file_version project;

file_version: asap2_version
	| file_version a2ml_version;

annotation: A2L_BEGIN ANNOTATION annotation_attributes A2L_END ANNOTATION;
annotation_attributes: %empty
    | annotation_attributes annotation_attribute;
annotation_attribute: annotation_label
     | annotation_origin
     | annotation_text;

annotation_text: A2L_BEGIN ANNOTATION_TEXT string_list A2L_END ANNOTATION_TEXT;

ar_component: A2L_BEGIN AR_COMPONENT STRING ar_component_attributes A2L_END AR_COMPONENT
ar_component_attributes: %empty
	| ar_component_attributes ar_component_attribute;
ar_component_attribute: ar_prototype_of;

axis_descr: A2L_BEGIN AXIS_DESCR IDENT IDENT IDENT any_uint any_float any_float
	axis_descr_attributes A2L_END AXIS_DESCR;
axis_descr_attributes: %empty
	| axis_descr_attributes axis_descr_attribute;
axis_descr_attribute: annotation
	| axis_pts_ref
	| byte_order
	| curve_axis_ref
	| deposit
	| extended_limits
	| fix_axis_par
	| fix_axis_par_dist
	| fix_axis_par_list
	| format
	| max_grad
	| monotony
	| phys_unit
	| read_only
	| step_size;

axis_pts: A2L_BEGIN AXIS_PTS IDENT STRING any_uint IDENT IDENT any_float IDENT any_uint any_float any_float
	axis_pts_attributes A2L_END AXIS_PTS;
axis_pts_attributes: %empty
	| axis_pts_attributes axis_pts_attribute;
axis_pts_attribute: annotation
	| byte_order
	| calibration_access
	| deposit
	| display_identifier
	| ecu_address_extension
	| extended_limits
	| format
	| function_list
	| guard_rails
	| if_data
	| max_refresh
	| model_link
	| monotony
	| phys_unit
	| read_only
	| ref_memory_segment
	| step_size
	| symbol_link;

bit_operation: A2L_BEGIN BIT_OPERATION bit_operation_attributes A2L_END BIT_OPERATION;
bit_operation_attributes: %empty
	| bit_operation_attributes bit_operation_attribute;
bit_operation_attribute: left_shift
	| right_shift
	| sign_extend;

blob: A2L_BEGIN BLOB IDENT STRING any_uint any_uint blob_attributes A2L_END BLOB;

blob_attributes: %empty
	| blob_attributes blob_attribute;
blob_attribute: address_type
	| annotation
	| calibration_access
	| display_identifier
	| ecu_address_extension
	| if_data
	| max_refresh
	| model_link
	| symbol_link;

calibration_handle: A2L_BEGIN CALIBRATION_HANDLE int_list calibration_handle_attribute A2L_END CALIBRATION_HANDLE;
calibration_handle_attribute: %empty
	| calibration_handle_text;

calibration_method: A2L_BEGIN CALIBRATION_METHOD STRING any_uint
	calibration_method_attributes A2L_END CALIBRATION_METHOD;
calibration_method_attributes: %empty
	| calibration_method_attributes calibration_handle;

characteristic: A2L_BEGIN CHARACTERISTIC IDENT STRING IDENT any_uint IDENT any_float IDENT any_float any_float characteristic_attributes A2L_END CHARACTERISTIC;
characteristic_attributes: %empty
	| characteristic_attributes characteristic_attribute;
characteristic_attribute: annotation
	| axis_descr
	| bit_mask
	| byte_order
	| calibration_access
	| comparison_quantity
	| dependent_characteristic
	| discrete
	| display_identifier
	| ecu_address_extension
	| encoding
	| extended_limits
	| format
	| function_list
	| guard_rails
	| if_data
	| map_list
	| matrix_dim
	| max_refresh
	| model_link
	| number
	| phys_unit
	| read_only
	| ref_memory_segment
	| step_size
	| symbol_link
	| virtual_characteristic;

compu_method: A2L_BEGIN COMPU_METHOD IDENT STRING IDENT STRING STRING compu_method_attributes A2L_END COMPU_METHOD;
compu_method_attributes: %empty
	| compu_method_attributes compu_method_attribute;
compu_method_attribute: coeffs
	| coeffs_linear
	| compu_tab_ref
	| formula
	| ref_unit
	| status_string_ref;

compu_tab: A2L_BEGIN COMPU_TAB IDENT STRING IDENT any_uint float_pair_list compu_tab_attributes A2L_END COMPU_TAB;
compu_tab_attributes: %empty
	| compu_tab_attributes compu_tab_attribute;
compu_tab_attribute: default_value
	| default_value_numeric;

compu_vtab: A2L_BEGIN COMPU_VTAB IDENT STRING IDENT any_uint float_string_list compu_vtab_attributes A2L_END COMPU_VTAB;
compu_vtab_attributes: %empty
	| compu_vtab_attributes compu_vtab_attribute;
compu_vtab_attribute: default_value;

compu_vtab_range: A2L_BEGIN COMPU_VTAB_RANGE IDENT STRING any_uint float_range_list
	compu_vtab_range_attributes A2L_END COMPU_VTAB_RANGE;
compu_vtab_range_attributes: %empty
	| compu_vtab_range_attributes compu_vtab_range_attribute;
compu_vtab_range_attribute: default_value;

def_characteristic: A2L_BEGIN DEF_CHARACTERISTIC ident_list A2L_END DEF_CHARACTERISTIC;

dependent_characteristic: A2L_BEGIN DEPENDENT_CHARACTERISTIC STRING ident_list A2L_END DEPENDENT_CHARACTERISTIC;

fix_axis_par_list: A2L_BEGIN FIX_AXIS_PAR_LIST float_list A2L_END FIX_AXIS_PAR_LIST;

formula: A2L_BEGIN FORMULA STRING formula_attributes A2L_END FORMULA;
formula_attributes: %empty
	| formula_attributes formula_attribute;
formula_attribute: formula_inv;

frame: A2L_BEGIN FRAME IDENT STRING any_uint any_uint frame_attributes A2L_END FRAME;
frame_attributes: %empty
	| frame_attributes frame_attribute;
frame_attribute: frame_measurement
	| if_data;

function: A2L_BEGIN FUNCTION IDENT STRING function_attributes A2L_END FUNCTION;
function_attributes: %empty
	| function_attributes function_attribute;
function_attribute: annotation
        | ar_component
        | def_characteristic
        | function_version
        | if_data
        | in_measurement
        | loc_measurement
        | out_measurement
        | ref_characteristic
        | sub_function;

function_list: A2L_BEGIN FUNCTION_LIST ident_list A2L_END FUNCTION_LIST
	| FUNCTION_LIST ident_list;

group: A2L_BEGIN GROUP IDENT STRING group_attributes A2L_END GROUP;
group_attributes: %empty
	| group_attributes group_attribute;
group_attribute: annotation
	| function_list
	| if_data
	| ref_characteristic
	| ref_measurement
	| root
	| sub_group;

header: A2L_BEGIN HEADER STRING header_attributes A2L_END HEADER;
header_attributes: %empty
    | header_attributes header_attribute;
header_attribute: project_no
    | version;

in_measurement: A2L_BEGIN IN_MEASUREMENT ident_list A2L_END IN_MEASUREMENT;

instance: A2L_BEGIN INSTANCE IDENT STRING IDENT any_uint instance_attributes A2L_END INSTANCE;
instance_attributes: %empty
	| instance_attributes instance_attribute;
instance_attribute: address_type
	| annotation
	| calibration_access
	| display_identifier
	| ecu_address_extension
	| if_data
	| layout
	| matrix_dim
	| max_refresh
	| model_link
	| overwrite
	| read_write
	| symbol_link;

loc_measurement: A2L_BEGIN LOC_MEASUREMENT ident_list A2L_END LOC_MEASUREMENT;

map_list: A2L_BEGIN MAP_LIST ident_list A2L_END MAP_LIST;

measurement: A2L_BEGIN MEASUREMENT IDENT STRING IDENT IDENT any_uint any_float any_float any_float
	measurement_attributes A2L_END MEASUREMENT;
measurement_attributes: %empty
	| measurement_attributes measurement_attribute;
measurement_attribute: address_type
	| annotation
	| array_size
	| bit_mask
	| bit_operation
	| byte_order
	| discrete
	| display_identifier
	| ecu_address
	| ecu_address_extension
	| error_mask
	| format
	| function_list
	| if_data
	| layout
	| matrix_dim
	| max_refresh
	| model_link
	| phys_unit
	| read_write
	| ref_memory_segment
	| symbol_link
	| virtual;

memory_layout: A2L_BEGIN MEMORY_LAYOUT IDENT any_uint any_uint int_list
	memory_layout_attributes A2L_END MEMORY_LAYOUT;
memory_layout_attributes: %empty
	| memory_layout_attributes if_data;

prg_type: RESERVED | IDENT;
memory_segment: A2L_BEGIN MEMORY_SEGMENT IDENT STRING prg_type IDENT IDENT any_uint any_uint int_list
	memory_segment_attributes A2L_END MEMORY_SEGMENT;
memory_segment_attributes: %empty
	| memory_segment_attributes if_data;
mod_common : A2L_BEGIN MOD_COMMON STRING mod_common_attributes A2L_END MOD_COMMON;
mod_common_attributes: %empty
	| mod_common_attributes mod_common_attribute;
mod_common_attribute: alignment_byte
	| alignment_float16_ieee
	| alignment_float32_ieee
	| alignment_float64_ieee
	| alignment_int64
	| alignment_long
	| alignment_word
	| byte_order
	| data_size
	| deposit
	| s_rec_layout;

mod_par : A2L_BEGIN MOD_PAR STRING mod_par_attributes A2L_END MOD_PAR;
mod_par_attributes: %empty
	| mod_par_attributes mod_par_attribute;
mod_par_attribute: addr_epk
	| calibration_method
	| cpu_type
	| customer
	| customer_no
	| ecu
	| ecu_calibration_offset
	| epk
	| memory_layout
	| memory_segment
	| no_of_interfaces
	| phone_no
	| supplier
	| system_constant
	| user
	| version;

module: A2L_BEGIN MODULE IDENT STRING module_attributes A2L_END MODULE;
module_attributes: %empty
    | module_attributes module_attribute;
module_attribute : a2ml
    	| axis_pts
    	| blob
    	| characteristic
    	| compu_method
    	| compu_tab
    	| compu_vtab
    	| compu_vtab_range
    	| frame
    	| function
    	| group
    	| if_data
    	| instance
    	| measurement
    	| mod_common
   	| mod_par
   	| record_layout
   	| transformer
   	| typedef_axis
   	| typedef_blob
   	| typedef_characteristic
   	| typedef_measurement
   	| typedef_structure
   	| unit
   	| user_rights
   	| variant_coding;

out_measurement: A2L_BEGIN OUT_MEASUREMENT ident_list A2L_END OUT_MEASUREMENT;

overwrite: A2L_BEGIN OVERWRITE IDENT any_uint overwrite_attributes A2L_END OVERWRITE;
overwrite_attributes: %empty
	| overwrite_attributes overwrite_attribute;
overwrite_attribute: conversion
	| extended_limits
	| format
	| input_quantity
	| limits
	| monotony
	| phys_unit;

project: A2L_BEGIN PROJECT IDENT STRING project_attributes A2L_END PROJECT;
project_attributes : project_attribute
    | project_attributes project_attribute;
project_attribute: header
    | module;

record_layout: A2L_BEGIN RECORD_LAYOUT IDENT record_layout_attributes A2L_END RECORD_LAYOUT;
record_layout_attributes: %empty
	| record_layout_attributes record_layout_attribute;
record_layout_attribute: alignment_byte
	| alignment_float16_ieee
	| alignment_float32_ieee
	| alignment_float64_ieee
	| alignment_int64
	| alignment_long
	| alignment_word
	| axis_pts_x
	| axis_pts_y
	| axis_pts_z
	| axis_pts_4
	| axis_pts_5
	| axis_rescale_x
	| dist_op_x
	| dist_op_y
	| dist_op_z
	| dist_op_4
	| dist_op_5
	| fix_no_axis_pts_x
	| fix_no_axis_pts_y
	| fix_no_axis_pts_z
	| fix_no_axis_pts_4
	| fix_no_axis_pts_5
	| fnc_values
	| identification
	| no_axis_pts_x
	| no_axis_pts_y
	| no_axis_pts_z
	| no_axis_pts_4
	| no_axis_pts_5
	| no_rescale_x
	| offset_x
	| offset_y
	| offset_z
	| offset_4
	| offset_5
	| reserved
	| rip_addr_w
	| rip_addr_x
	| rip_addr_y
	| rip_addr_z
	| rip_addr_4
	| rip_addr_5
	| src_addr_x
	| src_addr_y
	| src_addr_z
	| src_addr_4
	| src_addr_5
	| shift_op_x
	| shift_op_y
	| shift_op_z
	| shift_op_4
	| shift_op_5
	| static_address_offsets
	| static_record_layout;

ref_characteristic: A2L_BEGIN REF_CHARACTERISTIC ident_list A2L_END REF_CHARACTERISTIC;
ref_group: A2L_BEGIN REF_GROUP ident_list A2L_END REF_GROUP;
ref_measurement: A2L_BEGIN REF_MEASUREMENT ident_list A2L_END REF_MEASUREMENT;

structure_component: A2L_BEGIN STRUCTURE_COMPONENT IDENT IDENT any_uint structure_component_attributes A2L_END STRUCTURE_COMPONENT;
structure_component_attributes: %empty
	| structure_component_attributes structure_component_attribute;
structure_component_attribute: address_type
	| layout
	| matrix_dim
	| symbol_type_link;

sub_function: A2L_BEGIN SUB_FUNCTION ident_list A2L_END SUB_FUNCTION;
sub_group: A2L_BEGIN SUB_GROUP ident_list A2L_END SUB_GROUP;

transformer: A2L_BEGIN TRANSFORMER IDENT STRING STRING STRING any_uint IDENT IDENT transformer_attributes A2L_END TRANSFORMER;
transformer_attributes: %empty
	| transformer_attributes transformer_attribute;
transformer_attribute: transformer_in_objects
	| transformer_out_objects;

transformer_in_objects: A2L_BEGIN TRANSFORMER_IN_OBJECTS ident_list A2L_END TRANSFORMER_IN_OBJECTS;
transformer_out_objects: A2L_BEGIN TRANSFORMER_OUT_OBJECTS ident_list A2L_END TRANSFORMER_OUT_OBJECTS;

typedef_axis: A2L_BEGIN TYPEDEF_AXIS IDENT STRING IDENT IDENT any_float IDENT any_uint any_float any_float typedef_axis_attributes A2L_END TYPEDEF_AXIS;
typedef_axis_attributes: %empty
	| typedef_axis_attributes typedef_axis_attribute;
typedef_axis_attribute: byte_order
	| deposit
	| extended_limits
	| format
	| monotony
	| phys_unit
	| step_size;

typedef_blob: A2L_BEGIN TYPEDEF_BLOB IDENT STRING any_uint typedef_blob_attributes A2L_END TYPEDEF_BLOB;
typedef_blob_attributes: %empty
	| typedef_blob_attributes typedef_blob_attribute;
typedef_blob_attribute: address_type;

typedef_characteristic: A2L_BEGIN TYPEDEF_CHARACTERISTIC IDENT STRING IDENT IDENT any_float IDENT any_float any_float
	typedef_characteristic_attributes A2L_END TYPEDEF_CHARACTERISTIC;
typedef_characteristic_attributes: %empty
	| typedef_characteristic_attributes typedef_characteristic_attribute;
typedef_characteristic_attribute: axis_descr
	| bit_mask
	| byte_order
	| discrete
	| encoding
	| extended_limits
	| format
	| matrix_dim
	| number
	| phys_unit
	| step_size;

typedef_measurement: A2L_BEGIN TYPEDEF_MEASUREMENT IDENT STRING IDENT IDENT UINT any_float any_float any_float
			typedef_measurement_attributes A2L_END TYPEDEF_MEASUREMENT;
typedef_measurement_attributes: %empty
	| typedef_measurement_attributes typedef_measurement_attribute;
typedef_measurement_attribute: address_type
	| bit_mask
	| bit_operation
	| byte_order
	| discrete
	| error_mask
	| format
	| layout
	| matrix_dim
	| phys_unit;

typedef_structure: A2L_BEGIN TYPEDEF_STRUCTURE IDENT STRING UINT
		typedef_structure_attributes A2L_END TYPEDEF_STRUCTURE;
typedef_structure_attributes: %empty
	| typedef_structure_attributes typedef_structure_attribute;
typedef_structure_attribute: address_type
	| consistent_exchange
	| structure_component
	| symbol_type_link;

unit: A2L_BEGIN UNIT IDENT STRING STRING IDENT unit_attributes A2L_END UNIT;
unit_attributes: %empty
	| unit_attributes unit_attribute;
unit_attribute: ref_unit
	| si_exponents
	| unit_conversion;

user_rights: A2L_BEGIN USER_RIGHTS IDENT user_rights_attributes A2L_END USER_RIGHTS;
user_rights_attributes: %empty
	| user_rights_attributes user_rights_attribute;
user_rights_attribute: read_only
	| ref_group;

var_address: A2L_BEGIN VAR_ADDRESS ident_list A2L_END VAR_ADDRESS;

var_characteristic: A2L_BEGIN VAR_CHARACTERISTIC IDENT ident_list var_characteristic_attribute A2L_END VAR_CHARACTERISTIC;
var_characteristic_attribute: %empty
	| var_address;

var_criterion: A2L_BEGIN VAR_CRITERION IDENT STRING var_criterion_attributes A2L_END VAR_CRITERION;
var_criterion_attributes: %empty
	| var_criterion_attributes var_criterion_attribute;
var_criterion_attribute: var_measurement
	| var_selection_characteristic;

var_forbidden_comb: A2L_BEGIN VAR_FORBIDDEN_COMB key_value_list A2L_END VAR_FORBIDDEN_COMB;

variant_coding: A2L_BEGIN VARIANT_CODING variant_coding_attributes A2L_END VARIANT_CODING;
variant_coding_attributes: %empty
	| variant_coding_attributes variant_coding_attribute;
variant_coding_attribute: var_characteristic
	| var_criterion
	| var_forbidden_comb
	| var_naming
	| var_separator;

virtual: A2L_BEGIN VIRTUAL ident_list A2L_END VIRTUAL;
virtual_characteristic: A2L_BEGIN VIRTUAL_CHARACTERISTIC STRING ident_list A2L_END VIRTUAL_CHARACTERISTIC;

any_uint: UINT | HEX;
any_int:  INT | UINT | HEX;
any_float: FLOAT | INT | UINT | HEX;

int_list: %empty
  | int_list any_int;

uint_list: %empty
  | uint_list any_uint;

float_list: %empty
	| float_list any_float;

float_pair_list: %empty
	| float_pair_list any_float any_float;

float_string_list: %empty
	| float_string_list any_float STRING;

float_range_list: %empty
	| float_range_list any_float any_float STRING;

string_list: %empty
	| string_list STRING;

ident_list: %empty
       	| ident_list IDENT;

key_value_list: %empty
       	| key_value_list IDENT IDENT;

a2ml : A2ML;
a2ml_version: any_uint any_uint;
asap2_version : ASAP2_VERSION any_uint any_uint
	| ASAP2_VERSION STRING;
addr_epk: ADDR_EPK any_uint;
address_type: ADDRESS_TYPE IDENT;
alignment_byte: ALIGNMENT_BYTE any_uint;
alignment_float16_ieee: ALIGNMENT_FLOAT16_IEEE any_uint;
alignment_float32_ieee: ALIGNMENT_FLOAT32_IEEE any_uint;
alignment_float64_ieee: ALIGNMENT_FLOAT64_IEEE any_uint;
alignment_int64: ALIGNMENT_INT64 any_uint;
alignment_long: ALIGNMENT_LONG any_uint;
alignment_word: ALIGNMENT_WORD any_uint;
annotation_label: ANNOTATION_LABEL STRING;
annotation_origin: ANNOTATION_ORIGIN STRING;
array_size: ARRAY_SIZE any_uint;
ar_prototype_of: AR_PROTOTYPE_OF IDENT;
axis_pts_ref: AXIS_PTS_REF IDENT;
axis_pts_x: AXIS_PTS_X any_uint IDENT IDENT IDENT;
axis_pts_y: AXIS_PTS_Y any_uint IDENT IDENT IDENT;
axis_pts_z: AXIS_PTS_Z any_uint IDENT IDENT IDENT;
axis_pts_4: AXIS_PTS_4 any_uint IDENT IDENT IDENT;
axis_pts_5: AXIS_PTS_5 any_uint IDENT IDENT IDENT;
axis_rescale_x: AXIS_RESCALE_X any_uint IDENT any_uint IDENT IDENT;
bit_mask: BIT_MASK any_uint;
byte_order: BYTE_ORDER IDENT;
calibration_access: CALIBRATION_ACCESS IDENT;
calibration_handle_text: CALIBRATION_HANDLE_TEXT STRING;
coeffs: COEFFS any_float any_float any_float any_float any_float any_float;
coeffs_linear: COEFFS_LINEAR any_float any_float;
comparison_quantity: COMPARISON_QUANTITY IDENT;
compu_tab_ref: COMPU_TAB_REF IDENT;
consistent_exchange: CONSISTENT_EXCHANGE;
conversion: CONVERSION IDENT;
cpu_type: CPU_TYPE STRING;
curve_axis_ref: CURVE_AXIS_REF IDENT;
customer: CUSTOMER STRING;
customer_no: CUSTOMER_NO STRING;
data_size: DATA_SIZE any_uint;
default_value: DEFAULT_VALUE STRING;
default_value_numeric: DEFAULT_VALUE_NUMERIC any_float;
deposit: DEPOSIT IDENT;
discrete: DISCRETE;
display_identifier: DISPLAY_IDENTIFIER IDENT
	| A2L_BEGIN DISPLAY_IDENTIFIER IDENT A2L_END DISPLAY_IDENTIFIER;
dist_op_x: DIST_OP_X any_uint IDENT;
dist_op_y: DIST_OP_Y any_uint IDENT;
dist_op_z: DIST_OP_Z any_uint IDENT;
dist_op_4: DIST_OP_4 any_uint IDENT;
dist_op_5: DIST_OP_5 any_uint IDENT;
ecu: ECU STRING;
ecu_address: ECU_ADDRESS any_uint;
ecu_address_extension: ECU_ADDRESS_EXTENSION any_int;
ecu_calibration_offset: ECU_CALIBRATION_OFFSET any_int;
encoding: ENCODING IDENT;
epk: EPK STRING;
error_mask: EPK any_uint;
extended_limits: EXTENDED_LIMITS any_float any_float;
fix_axis_par: FIX_AXIS_PAR any_float any_float any_uint;
fix_axis_par_dist: FIX_AXIS_PAR_DIST any_float any_float any_uint;
fix_no_axis_pts_x: FIX_NO_AXIS_PTS_X any_uint;
fix_no_axis_pts_y: FIX_NO_AXIS_PTS_Y any_uint;
fix_no_axis_pts_z: FIX_NO_AXIS_PTS_Z any_uint;
fix_no_axis_pts_4: FIX_NO_AXIS_PTS_4 any_uint;
fix_no_axis_pts_5: FIX_NO_AXIS_PTS_5 any_uint;
fnc_values: FNC_VALUES any_uint IDENT IDENT IDENT;
format: FORMAT STRING;
formula_inv: FORMULA_INV STRING;
frame_measurement: FRAME_MEASUREMENT ident_list;
function_version: FUNCTION_VERSION STRING;
guard_rails: GUARD_RAILS;
identification: IDENTIFICATION any_uint IDENT;
if_data : IF_DATA;
input_quantity: INPUT_QUANTITY IDENT;
layout: LAYOUT IDENT;
left_shift: LEFT_SHIFT any_uint;
limits: LIMITS FLOAT any_float;
matrix_dim: MATRIX_DIM uint_list;
max_grad: MAX_GRAD any_float;
max_refresh: MAX_REFRESH any_uint any_uint;
model_link: MODEL_LINK STRING;
monotony: MONOTONY IDENT;
no_axis_pts_x: NO_AXIS_PTS_X any_uint IDENT;
no_axis_pts_y: NO_AXIS_PTS_Y any_uint IDENT;
no_axis_pts_z: NO_AXIS_PTS_Z any_uint IDENT;
no_axis_pts_4: NO_AXIS_PTS_4 any_uint IDENT;
no_axis_pts_5: NO_AXIS_PTS_5 any_uint IDENT;
no_of_interfaces: NO_OF_INTERFACES any_uint;
no_rescale_x: NO_RESCALE_X any_uint IDENT;
number: NUMBER any_uint;
offset_x: OFFSET_X any_uint IDENT;
offset_y: OFFSET_Y any_uint IDENT;
offset_z: OFFSET_Z any_uint IDENT;
offset_4: OFFSET_4 any_uint IDENT;
offset_5: OFFSET_5 any_uint IDENT;
phone_no: PHONE_NO STRING;
phys_unit: PHYS_UNIT STRING;
proj_no: IDENT | UINT; /* Fix so the number may be a number as well */
project_no: PROJECT_NO proj_no;
read_only: READ_ONLY;
read_write: READ_WRITE;
ref_memory_segment: REF_MEMORY_SEGMENT IDENT;
ref_unit: REF_UNIT IDENT;
reserved: RESERVED any_uint IDENT;
right_shift: RIGHT_SHIFT any_uint;
rip_addr_w: RIP_ADDR_W any_uint IDENT;
rip_addr_x: RIP_ADDR_X any_uint IDENT;
rip_addr_y: RIP_ADDR_Y any_uint IDENT;
rip_addr_z: RIP_ADDR_Z any_uint IDENT;
rip_addr_4: RIP_ADDR_4 any_uint IDENT;
rip_addr_5: RIP_ADDR_5 any_uint IDENT;
root: ROOT;
s_rec_layout: S_REC_LAYOUT IDENT;
shift_op_x: SHIFT_OP_X any_uint IDENT;
shift_op_y: SHIFT_OP_Y any_uint IDENT;
shift_op_z: SHIFT_OP_Z any_uint IDENT;
shift_op_4: SHIFT_OP_4 any_uint IDENT;
shift_op_5: SHIFT_OP_5 any_uint IDENT;
sign_extend: SIGN_EXTEND;
si_exponents: SI_EXPONENTS any_int any_int any_int any_int any_int any_int any_int;
src_addr_x: SRC_ADDR_X any_uint IDENT;
src_addr_y: SRC_ADDR_Y any_uint IDENT;
src_addr_z: SRC_ADDR_Z any_uint IDENT;
src_addr_4: SRC_ADDR_4 any_uint IDENT;
src_addr_5: SRC_ADDR_5 any_uint IDENT;
static_address_offsets: STATIC_ADDRESS_OFFSETS;
static_record_layout: STATIC_RECORD_LAYOUT;
status_string_ref: STATUS_STRING_REF IDENT;
step_size: STEP_SIZE any_float;
supplier: SUPPLIER STRING;
symbol_link: SYMBOL_LINK STRING any_int;
symbol_type_link: SYMBOL_TYPE_LINK STRING;
system_constant: SYSTEM_CONSTANT STRING STRING;
unit_conversion: UNIT_CONVERSION any_float any_float;
user: USER STRING;
var_measurement: VAR_MEASUREMENT IDENT;
var_naming: VAR_NAMING IDENT;
var_selection_characteristic: VAR_SELECTION_CHARACTERISTIC IDENT;
var_separator: VAR_SEPARATOR STRING;
version: A2L_VERSION STRING;

%%


void a2l::A2lParser::error(const std::string& err) {
    const auto line = scanner.lineno();
    const auto column = scanner.YYLeng();
    const std::string near = scanner.YYText() != nullptr ? scanner.YYText() : "";
    std::ostringstream error;
    error << "Parser error: " << err
          << ", Line: " << line
          << ", Column: " << column
          << ", Near: " << near;
    scanner.LastError(error.str());
}
