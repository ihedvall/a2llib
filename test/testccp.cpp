/*
* Copyright 2026 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */

#include "testccp.h"

#include <array>
#include <filesystem>
#include <map>
#include <string>
#include <string_view>

#include "a2l/a2lfile.h"
#include "a2l/ccp/ccpdatablock.h"

using namespace a2l;
using namespace a2l::ccp;
using A2lList = std::map<std::string, std::string>;
using namespace std::filesystem;

namespace {
constexpr std::string_view kA2lSourceDir = "k:/test/a2l";
A2lList kA2lList;

std::string GetA2lFile(const std::string &name) {
  const auto itr = kA2lList.find(name);
  return itr == kA2lList.cend() ? std::string() : itr->second;
}

}  // namespace

namespace a2l::test {
void TestCcp::SetUpTestSuite() {
  kA2lList.clear();
  try {
    for (const auto &entry : recursive_directory_iterator(kA2lSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() &&
        (p.extension().string() == ".a2l" || p.extension().string() == ".A2L") ) {
        kA2lList.emplace(p.stem().string(), p.string());
        }
    }
    std::cout << "A2L: " << kA2lList.size() << " files found." << std::endl;
  } catch (const std::exception &error) {
    std::cout << "Failed to fetch the AML test files. Error: "
                << error.what();
  }
}

void TestCcp::TearDownTestSuite() {
}

TEST_F(TestCcp, TestDemoFile) {
  constexpr std::array<std::string_view, 1> demo_files = {
    "IFData_test",
  };
  for (const auto& name : demo_files ) {
    const std::string a2l_file = GetA2lFile(std::string(name));
    if (a2l_file.empty() ) {
      continue;
    }
    A2lFile file;
    file.Filename(a2l_file);
    const bool parse = file.ParseFile();
    if (!parse) {
      continue;
    }
    const A2lProject& project = file.Project();
    for (const auto& [module_name, module] :
      project.Modules()) {
      if (!module) {
        continue;
      }
      size_t test_count = 0;
      for (const auto& [protocol, if_data] : module->IfDatas()) {
        if (protocol != "ASAP1B_CCP") {
          continue;
        }

        CcpDataBlock block(if_data);
        const bool ccp_parse = block.IsOk();
        ASSERT_TRUE(ccp_parse) << a2l_file << ": Error: " << block.LastError() << std::endl;
        std::cout << "CCP: " << a2l_file << "/" << module_name
          << (ccp_parse ? " OK" : " FAIL") << std::endl;

        const auto&source_list = block.GetSourceList();
        EXPECT_EQ(source_list.size(), 3);
        uint16_t qp_blob_number = 0;
        for (const auto& source : source_list) {
          EXPECT_EQ(source.GetName(), "DAQ List");
          EXPECT_EQ(source.GetScalingUnit(), 0);
          EXPECT_EQ(source.GetRate(), 0);
          const QpBlob* qp_blob = source.GetQpBlob();
          ASSERT_TRUE(qp_blob != nullptr);
          EXPECT_EQ(qp_blob->GetNumber(), qp_blob_number);
          EXPECT_GT(qp_blob->GetLength(), 0);

          EXPECT_FALSE(qp_blob->GetCanIdVariable());
          EXPECT_EQ(qp_blob->GetCanIdFixed().value_or(0), 0x7C5 + qp_blob_number);
          EXPECT_EQ(qp_blob->GetMessageIdFixed().value_or(0), 0x7C5 + qp_blob_number);

          const auto& qp_raster_list = qp_blob->GetRasterList();
          ASSERT_EQ(qp_raster_list.size(), 1);
          EXPECT_EQ(qp_raster_list[0], qp_blob_number);
          EXPECT_TRUE(qp_blob->GetFirstPid().has_value());
          ++qp_blob_number;
        }
        uint8_t raster_number = 0;
        const auto& raster_list = block.GetRasterList();
        EXPECT_EQ(raster_list.size(), 3);
        for (const auto& raster : raster_list) {
          EXPECT_GT(raster.GetName().size(), 3);
          EXPECT_GT(raster.GetShortName().size(), 3);
          EXPECT_EQ(raster.GetNumber(), raster_number);
          EXPECT_EQ(raster.GetPeriod(), 3);
          EXPECT_GT(raster.GetSampleRate(), 0);
          ++raster_number;
        }

        const SeedKey* seed_key = block.GetSeedKey();
        ASSERT_TRUE(seed_key != nullptr);
        EXPECT_EQ(seed_key->GetCalDll(), "INTERNAL.DLL");
        EXPECT_EQ(seed_key->GetDaqDll(), "INTERNAL.DLL");
        EXPECT_EQ(seed_key->GetPgmDll(), "INTERNAL.DLL");

        const TpBlob* tp_blob = block.GetTpBlob();
        ASSERT_TRUE(tp_blob != nullptr);
        EXPECT_EQ(tp_blob->GetVersion(), 0x201);
        EXPECT_EQ(tp_blob->GetBlobVersion(), 0x206);
        EXPECT_EQ(tp_blob->GetTransmitMessageId(), 0x7C3);
        EXPECT_EQ(tp_blob->GetTransmitCanId(), 0x7C3);
        EXPECT_EQ(tp_blob->GetReceiveMessageId(), 0x7C4);
        EXPECT_EQ(tp_blob->GetReceiveCanId(), 0x7C4);
        EXPECT_EQ(tp_blob->GetAddress(), 0x01);
        EXPECT_EQ(tp_blob->GetByteOrder(), 0x01);
        EXPECT_EQ(tp_blob->GetBaudrate().value(), 0x7A120);
        EXPECT_EQ(tp_blob->GetSamplePoint().value(), 0x44);
        EXPECT_EQ(tp_blob->GetSampleRate().value(), 0x01);
        EXPECT_EQ(tp_blob->GetBtlCycles().value(), 0x10);
        EXPECT_EQ(tp_blob->GetSjw().value(), 0x02);
        EXPECT_EQ(tp_blob->GetSyncEdge().value(), SyncEdge::SINGLE);
        EXPECT_EQ(tp_blob->GetDaqMode().value(), DaqMode::BURST);
        EXPECT_TRUE(tp_blob->GetBytesOnly());
        EXPECT_TRUE(tp_blob->GetResumeSupported());
        EXPECT_EQ(tp_blob->GetConsistency().value(), Consistency::ODT);
        EXPECT_EQ(tp_blob->GetAddressExtension().value(), AddressExtension::DAQ);

        const ChecksumParam* checksum = tp_blob->GetChecksumParam();
        ASSERT_TRUE(checksum != nullptr);
        EXPECT_EQ(checksum->GetType(),0xD001);
        EXPECT_EQ(checksum->GetMaxBlockLength(),0x200);

        const auto& defined_pages_list =
          tp_blob->GetDefinedPages();
        EXPECT_EQ(defined_pages_list.size(), 3);
        uint16_t page_number = 0;
        for (const auto& page : defined_pages_list) {
          EXPECT_EQ(page.GetNumber(), page_number);
          EXPECT_GT(page.GetName().size(), 2);
          EXPECT_EQ(page.GetAddressExtension(), 0);
          EXPECT_GE(page.GetBaseAddress(), 0x20000100);
          if (page_number == 2) {
            EXPECT_EQ(page.GetLength(), 0x03D26C);
            EXPECT_TRUE(page.GetRam());
          }
          ++page_number;
        }

        const auto& optional_cmd_list = tp_blob->GetOptionalCmds();
        EXPECT_EQ(optional_cmd_list.size(), 11);
        ++test_count;
      }

      EXPECT_EQ(test_count, 1);
    }
  }
}

TEST_F(TestCcp, TestModules) {
  for (const auto& [name, path] : kA2lList ) {

    A2lFile file;
    file.Filename(path);
    const bool parse = file.ParseFile();
    if (!parse) {
      continue;
    }
    const A2lProject& project = file.Project();
    for (const auto& [module_name, module] :
      project.Modules()) {
      if (!module) {
        continue;
      }
      for (const auto& [protocol, if_data] : module->IfDatas()) {
        if (protocol == "ASAP1B_CCP" ) {
          CcpDataBlock block(if_data);
          const bool ccp_parse = block.IsOk();
          if (!ccp_parse) {
            std::cout << name << ": Error: " << block.LastError() << std::endl;
            std::cout << if_data << std::endl;
          }
          std::cout << "CCP: " << name << "/" << module_name
            << (ccp_parse ? " OK" : " FAIL") << std::endl;
          EXPECT_TRUE(ccp_parse) << name << "/" << module_name << " CCP parsing failed";
        }
      }
    }
  }
}

}
