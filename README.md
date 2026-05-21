# A2L File Parser
This library parses ASAM ASAP2 files (*.a2l) and convert its content into C++ objects.
The development was done in C++ and compiles both in Windows and Linux C++ project.
The A2L file describe the software and memory layout of an automotive ECU. 

The file consists of three basic parts.

- Measurement and calibration configuration (ASAP2).
- Communication information (IF_DATA).
- Meta language (A2ML).

The repository include two applications.
The unit test application is based upon the Google Unit Test tool.
The A2L Explorer GUI application shows the contents of one or more A2L files.

## The ASAP2 Parser
The main parser only parse the ASAP2 part of the file keeping the communication and meta sections as raw strings.
It supports the 1.71 and later versions of the file format.
The ASAP2 format is complex, so the user needs to understand the ASAP2 contents to use the library.

Example of parsing a file:

```c++
  A2lFile file;
  file.Filename(kDemoFile.data()); // Full path to the A2L file
  const auto parse = file.ParseFile(); // Parse the file
  std::cout << file.Name() << (parse ? " : OK" : " : FAIL") << std::endl;

  std::cout << "Version No: " << file.A2lVersion().VersionNo << std::endl;
  std::cout << "Upgrade No: " << file.A2lVersion().UpgradeNo << std::endl;

  const A2lProject& project = file.Project();
  std::cout << "Project Name: " << project.Name() << std::endl;
  std::cout << "Project Description: " << project.Description() << std::endl;

  const A2lHeader& header = project.Header();
  std::cout << "Header Description: " << header.Comment << std::endl;
  std::cout << "Header Version: " << header.VersionNo << std::endl;
  std::cout << "Header Project: " << header.ProjectNo << std::endl;

  // Note that the nomally only include one module i.e. ECU
  const ModuleList& module_list = project.Modules();
  for ( const auto& [name, module]: module_list ) {
    std::cout << "Module Name: " << name << std::endl;
    std::cout << "ECU Name: " << module->Name() << std::endl;
    std::cout << "ECU Description: " << module->Description() << std::endl;
    std::cout << "Characteristics: " << module->Characteristics().size() << std::endl;
    std::cout << "Measurements: " << module->Measurements().size() << std::endl;

    // The function parse the IF_DATA section if it exist.
    // The parser output is kept in memory so the next call only
    // returns the parser output object.
    // Note that this function may return a null pointer.
    const xcp::XcpDataBlock* xcp_data = module->GetXcpDataBlock();
    if (xcp_data != nullptr) {
      const auto& can_list = xcp_data->GetXcpOnCans();
      for (const xcp::XcpOnCan& can : can_list) {
        std::cout << "XCP Version: " << can.GetVersionAsString() << std::endl;
        std::cout << "XCP Broadcast ID: " << can.GetCanIdBroadcast().value_or(0) << std::endl;
        std::cout << "XCP Master ID: " << can.GetCanIdMaster().value_or(0) << std::endl;
        std::cout << "XCP Slave ID: " << can.GetCanIdSlave().value_or(0) << std::endl;
      }
    }
  }
```
## The AML Parser
The AML parser parses the AML sections of the A2L file.
The output of the parser is normally not of any use but in theory the IF_DATA section can be interpreted.
Normal user should skip this parser.

## The IF_DATA Parsers
It exist three IF_DATA parsers in this library. 

- Generic IF_DATA parser.
- CCP parser.
- XCP parser.

The generic parser can be used on all IF_DATA sections but the output data is difficult to use.
The CCP and XCP parsers have more useful output data. 
Other parsers as Vector xETK protocols can be made upon request.
The above example shows how to use the XCP IF_DATA parser.

## The A2L Explorer
The A2L explorer is a GUI application that show the contents of one or more A2L files.
![A2L Explorer](img\a2lexplorer.png)

## Building the Library and applications.
The A2L library is dependent on the Boost C++ Library.
It also uses the Flex and Bison tool for parsing but they are not
needed for compiling the C++ code.

The unit test application uses the Google Unit Test tools.

The A2L Explorer requires both the wxWidgets and the Util C++ libraries. 
The application is pre-built for Windows in the release area.

CMake is used to build the library and the applications. 
The following build options exists:

- **CMAKE_TOOLCHAIN_FILE="Path to VCPKG"**. Use VCPKG for external libraries.
- **COMP_DIR="Path to pre-built libraries"**. Alternative to VCPKG.
- **BUILD_SHARED_LIB=OFF/ON**. Building static or DLL library.
- **A2L_DOC=OFF/ON**. Building documentations.
- **A2L_TOOLS=OFF/ON**. Building (GUI) applications.
- **A2L_TEST=OFF/ON**. Building unit tests.
- **A2L_FLEX=OFF/ON**. Building Flex/Bison files.


   
