# A2L File Parser
ASAM ASAP2 parser for A2L files. The parser reads a ASAP2 file (*a2l) and parse the content. An A2L file consist of 3 basic parts.

1. Measurement and calibration configuration.
2. Communication information (IF_DATA).
3. Meta data kanguange (A2ML).

The measurement and calibration confuguration is normally always parsed while the communication data is optionlly parsed. The meta language is currently ignored. Only the XCP configuration is currently supported.
   
