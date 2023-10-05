# A2L File Parser
ASAM ASAP2 parser for A2L files. The parser reads an ASAP2 file (*.a2l) and parse its content. The file normally only contain description
of one module (ECU). An A2L file consist of 3 basic parts.

1. Measurement and calibration configuration (ASAP2).
2. Communication information (IF_DATA).
3. Meta languange (A2ML).

The measurement and calibration configuration is normally always parsed while the communication data and meta-language are optionally parsed. 
The IF_DATA blocks are needed when communicating with the ECU.
   
