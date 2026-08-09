/*
 * Copyright 2023 Ingemar Hedvall
 * SPDX-License-Identifier: MIT
 */
#include "testlabelfile.h"

#include <filesystem>
#include <map>
#include <string>
#include <string_view>
#include <fstream>

#include "a2l/a2llogstream.h"
#include "labelscanner.h"

using namespace std::filesystem;
using LabelList = std::map<std::string, path>;

namespace {
constexpr std::string_view kSourceDir = "k:/test/lab";
constexpr std::string_view kRefFile = "label_v13";

LabelList kLabelList;

path GetLabelFile(const std::string& name) {
  const auto itr = kLabelList.find(name);
  return itr == kLabelList.cend() ? path() : itr->second;
}

}  // namespace

namespace a2l::test {

void TestLabelFile::SetUpTestSuite() {
  A2lLogStream::SetLogFunction(A2lLogStream::LogToConsole);
  A2lLogStream::ShowLocation(false);
  kLabelList.clear();
  try {
    for (const auto &entry : recursive_directory_iterator(kSourceDir)) {
      if (!entry.is_regular_file()) {
        continue;
      }
      const auto &p = entry.path();

      if (p.has_extension() && (p.extension().string() == ".lab" ||
          p.extension().string() == ".LAB") ) {
        kLabelList.emplace(p.stem().string(), p.string());
      }
    }
    A2L_TRACE() << "Label file count: " << kLabelList.size() << std::endl;
  } catch (const std::exception &error) {
    A2L_ERROR() << "Failed to fetch the Label test files. Error: "
                << error.what();
  }
}

void TestLabelFile::TearDownTestSuite() {
  A2lLogStream::ResetLogFunction();
}

TEST_F(TestLabelFile, TestScanner) {
  for (const auto& [name, filename] : kLabelList) {
    try {
      std::ifstream file(filename, std::ios::in);
      SelectionList selection_list;
      LabelScanner scanner(file, selection_list);
      LabelParser parser(scanner,selection_list);
      // scanner.set_debug(2);
      const int result = parser.parse();
      file.close();
      EXPECT_EQ(result,0) << "File: " << name << ", Error: " << scanner.LastError();
    } catch (const std::exception &error) {
      A2L_ERROR() << "Parser error. Error: " << error.what();
      GTEST_FAIL();
    }
  }
}

TEST_F(TestLabelFile, TestRefFile) {
  path ref_file = GetLabelFile(std::string(kRefFile));
  if (ref_file.empty()) {
    GTEST_SKIP_("Ref file not found");
  }
  SelectionList list;
  list.SetFileName(ref_file.wstring());
  const bool read = list.ReadLabFile();
  EXPECT_TRUE(read) << kRefFile;

  EXPECT_EQ(list.GetName(), kRefFile);
  EXPECT_EQ(list.GetLabelVersion(), LabelVersion::V13);
  EXPECT_EQ(list.GetRasterSeparator(), '&');
  EXPECT_EQ(list.GetFileName(), ref_file.wstring());

  const auto& object_list = list.GetObjectList();
  EXPECT_EQ(object_list.size(), 16);

  const SortedObjectList ramcell_list = list.GetSortedList(ObjectType::RAMCELL);
  EXPECT_EQ(ramcell_list.size(), 8);
  for (const auto& [meas_name, meas]:
    ramcell_list) {
    std::ostringstream raster_text;
    for (const std::string& raster : meas.GetRasterList()) {
      if (raster_text.str().empty()) {
        raster_text << raster;
      } else {
        raster_text << "," << raster;
      }
    }
    A2L_TRACE() << "Name: " << meas_name
                << ", Raster: " << raster_text.str()
                << ", Display: " << meas.GetDisplayTypeAsString()
                << ", Order: " << meas.GetOrder()
                << ", Device: " << meas.GetDevice()
                << ", Comment: " << meas.GetComment();
  }
  const SortedObjectList label_list = list.GetSortedList(ObjectType::LABEL);
  EXPECT_EQ(label_list.size(), 2);

  const SortedObjectList function_list = list.GetSortedList(ObjectType::FUNCTION);
  EXPECT_EQ(function_list.size(), 3);

  const SortedObjectList group_list = list.GetSortedList(ObjectType::GROUP);
  EXPECT_EQ(group_list.size(), 3);
}
}