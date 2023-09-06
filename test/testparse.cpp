/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "testparse.h"

#include <chrono>
#include <filesystem>
#include <map>
#include <string>

#include "a2l/a2lfile.h"

using namespace std::filesystem;
using namespace std::chrono_literals;
using A2lList = std::map<std::string, std::string>;

namespace {
constexpr std::string_view kSourceDir = "k:/test/a2l";
constexpr std::string_view kDemoFile = "k:/test/a2l/asap2_demo_v171.a2l";

bool kDemoFileExist = false;
A2lList kA2lList;

std::string GetA2lFile(const std::string &name) {
  const auto itr = kA2lList.find(name);
  return itr == kA2lList.cend() ? std::string() : itr->second;
}

}  // namespace

namespace a2l::test {

void TestParse::SetUpTestSuite() {
  kA2lList.clear();
  try {
    kDemoFileExist = exists(kDemoFile);

    for (const auto &entry : recursive_directory_iterator(kSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() && (p.extension().string() == ".a2l" || p.extension().string() == ".A2L") ) {
        kA2lList.emplace(p.stem().string(), p.string());

      }
    }
  } catch (const std::exception &error) {
    std::cout << "Failed to fetch the A2l test files. Error: "
                << error.what();
  }
}

void TestParse::TearDownTestSuite() {
}

TEST_F(TestParse, ParseDemoFile)
{
  if (!kDemoFileExist) {
    GTEST_SKIP();
  }

  a2l::A2lFile file;
  file.Filename(kDemoFile.data());
  const auto parse = file.ParseFile();
  EXPECT_TRUE(parse) << file.LastError() << " : " << kDemoFile;
  std::cout << file.Name() << (parse ? " : OK" : " : FAIL") << std::endl;

  EXPECT_EQ(file.A2lVersion().VersionNo, 1);
  EXPECT_EQ(file.A2lVersion().UpgradeNo, 71);

  const auto& project = file.Project();

  const auto& header = project.Header();
  EXPECT_FALSE(header.Comment.empty());
  EXPECT_FALSE(header.ProjectNo.empty());
  EXPECT_FALSE(header.VersionNo.empty());

  const auto& module_list = project.Modules();
  ASSERT_EQ(module_list.size(), 1);

  const auto& module = module_list.cbegin()->second;
  ASSERT_TRUE(module);

  EXPECT_STREQ(module->Name().c_str(), "Example");
  EXPECT_FALSE(module->A2ml().empty());

  const auto& axis_list = module->AxisPtss();
  EXPECT_GT(axis_list.size(), 1);
  std::cout << "\t\tAXIS PTS" << std::endl;
  for (const auto& [pts_name, pts] : axis_list) {
    std::cout << pts_name << std::endl;
  }
  std::cout << std::endl;

  const auto& blob_list = module->Blobs();
  EXPECT_GT(blob_list.size(), 0);
  std::cout << "\t\tBLOB" << std::endl;
  for (const auto& [blob_name, blob] : blob_list) {
    std::cout << blob_name << " " << blob->Address() << std::endl;
  }
  std::cout << std::endl;

  const auto& characteristic_list = module->Characteristics();
  EXPECT_GT(characteristic_list.size(), 0);
  std::cout << "\t\tCHARACTERISTIC" << std::endl;
  for (const auto& [char_name, characteristic] : characteristic_list) {
    std::cout << char_name << " " << characteristic->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& compu_method_list = module->CompuMethods();
  EXPECT_GT(compu_method_list.size(), 0);
  std::cout << "\t\tCOMPU METHOD" << std::endl;
  for (const auto& [method_name, method] : compu_method_list) {
    std::cout << method_name << " " << method->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& compu_tab_list = module->CompuTabs();
  EXPECT_GT(compu_tab_list.size(), 0);
  std::cout << "\t\tCOMPU TAB" << std::endl;
  for (const auto& [tab_name, tab] : compu_tab_list) {
    std::cout << tab_name << " " << tab->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& compu_vtab_list = module->CompuVtabs();
  EXPECT_GT(compu_vtab_list.size(), 0);
  std::cout << "\t\tCOMPU VTAB" << std::endl;
  for (const auto& [vtab_name, vtab] : compu_vtab_list) {
    std::cout << vtab_name << " " << vtab->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& compu_vtab_range_list = module->CompuVtabRanges();
  EXPECT_GT(compu_vtab_range_list.size(), 0);
  std::cout << "\t\tCOMPU VTAB RANGE" << std::endl;
  for (const auto& [range_name, range] : compu_vtab_range_list) {
    std::cout << range_name << " " << range->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& frame_list = module->Frames();
  // EXPECT_GT(frame_list.size(), 0); No frames in file
  std::cout << "\t\tFRAME" << std::endl;
  for (const auto& [frame_name, frame] : frame_list) {
    std::cout << frame_name << " " << frame->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& func_list = module->Functions();
  EXPECT_GT(func_list.size(), 0);
  std::cout << "\t\tFUNCTION" << std::endl;
  for (const auto& [func_name, func] : func_list) {
    std::cout << func_name << " " << func->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& group_list = module->Groups();
  EXPECT_GT(group_list.size(), 0);
  std::cout << "\t\tGROUP" << std::endl;
  for (const auto& [group_name, group] : group_list) {
    std::cout << group_name << " " << group->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& instance_list = module->Instances();
  EXPECT_GT(instance_list.size(), 0);
  std::cout << "\t\tINSTANCE" << std::endl;
  for (const auto& [instance_name, instance] : instance_list) {
    std::cout << instance_name << " " << instance->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& meas_list = module->Measurements();
  EXPECT_GT(meas_list.size(), 0);
  std::cout << "\t\tMEASUREMENT" << std::endl;
  for (const auto& [meas_name, meas] : meas_list) {
    std::cout << meas_name << " " << meas->Description() << std::endl;
  }
  std::cout << std::endl;

  const auto& rec_list = module->RecordLayouts();
  EXPECT_GT(rec_list.size(), 0);
  std::cout << "\t\tRECORD LAYOUT" << std::endl;
  for (const auto& [rec_name, rec] : rec_list) {
    std::cout << rec_name << std::endl;
  }
  std::cout << std::endl;

  const auto& trans_list = module->Transformers();
  EXPECT_GT(trans_list.size(), 0);
  std::cout << "\t\tTRANSFORMER" << std::endl;
  for (const auto& [trans_name, trans] : trans_list) {
    std::cout << trans_name << std::endl;
  }
  std::cout << std::endl;

  const auto& taxis_list = module->TypedefAxiss();
  EXPECT_GT(taxis_list.size(), 0);
  std::cout << "\t\tTYPEDEF AXIS" << std::endl;
  for (const auto& [taxis_name, taxis] : taxis_list) {
    std::cout << taxis_name << std::endl;
  }
  std::cout << std::endl;

  const auto& tblob_list = module->TypedefBlobs();
  //EXPECT_GT(tblob_list.size(), 0);
  std::cout << "\t\tTYPEDEF BLOB" << std::endl;
  for (const auto& [tblob_name, tblob] : tblob_list) {
    std::cout << tblob_name << std::endl;
  }
  std::cout << std::endl;

  const auto& tchar_list = module->TypedefCharacteristics();
  EXPECT_GT(tchar_list.size(), 0);
  std::cout << "\t\tTYPEDEF CHARACTERISTIC" << std::endl;
  for (const auto& [tchar_name, tchar] : tchar_list) {
    std::cout << tchar_name << std::endl;
  }
  std::cout << std::endl;

  const auto& tmeas_list = module->TypedefMeasurements();
  //EXPECT_GT(tmeas_list.size(), 0);
  std::cout << "\t\tTYPEDEF MEASUREMENT" << std::endl;
  for (const auto& [tmeas_name, tmeas] : tmeas_list) {
    std::cout << tmeas_name << std::endl;
  }

  std::cout << std::endl;
  const auto& tstruct_list = module->TypedefStructures();
  EXPECT_GT(tstruct_list.size(), 0);
  std::cout << "\t\tTYPEDEF STRUCTURE" << std::endl;
  for (const auto& [tstruct_name, tstruct] : tstruct_list) {
    std::cout << tstruct_name << std::endl;
  }
  std::cout << std::endl;

  std::cout << std::endl;
  const auto& unit_list = module->Units();
  //EXPECT_GT(unit_list.size(), 0);
  std::cout << "\t\tUNIT" << std::endl;
  for (const auto& [unit_name, unit] : unit_list) {
    std::cout << unit_name << std::endl;
  }
  std::cout << std::endl;
}

TEST_F(TestParse, ParseAllFiles)
{
  if (kA2lList.empty() ) {
    GTEST_SKIP();
  }

  for (const auto &itr : kA2lList) {
    a2l::A2lFile file;
    file.Filename(itr.second);
    const auto parse = file.ParseFile();
    EXPECT_TRUE(parse) << file.LastError() << " : " << itr.first;
    std::cout << itr.second << (parse ? " : OK" : " : FAIL") << std::endl;

  }
}


}  // namespace a2l::test
