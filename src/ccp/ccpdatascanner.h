/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#ifndef yyFlexLexerOnce

#undef yyFlexLexer
#define yyFlexLexer ccpFlexLexer
#include "../FlexLexer.h"

#endif

#include <string>
#include <vector>

#include "ccpdataparser.hpp"
#include "a2l/ccp/tpblob.h"
#include "a2l/ccp/definedpages.h"
#include "a2l/ccp/qpblob.h"
#include "a2l/ccp/source.h"

namespace a2l::ccp {

class CcpDataScanner : public ccpFlexLexer {
public:
  friend class CcpDataBlock;

  CcpDataScanner(std::istream& in);

  int ccplex(CcpDataParser::value_type* yylval);

  void LastError(std::string error) { last_error_ = std::move(error); }
  [[nodiscard]] std::string LastError() const { return last_error_; }

  [[nodiscard]] DefinedPages& GetDefinedPages() {
    return current_defined_pages_;
  }

  [[nodiscard]] TpBlob& GetTpBlob() {
    return current_tp_blob_;
  }

  [[nodiscard]] QpBlob& GetQpBlob() {
    return current_qp_blob_;
  }

  [[nodiscard]] Source& GetSource() {
    return current_source_;
  }

  void AddSource(Source source) {
    source_list_.emplace_back(std::move(source));
  }

  void AddRaster(Raster raster) {
    raster_list_.emplace_back(std::move(raster));
  }

  void AddEventGroup(EventGroup group) {
    event_group_list_.emplace_back(std::move(group));
  }

  void SetSeedKey(SeedKey seed_key) {
    seed_key_ = std::move(seed_key);
  }

  void SetChecksum(std::string checksum) {
    checksum_ = std::move(checksum);
  }

  void SetTpBlob(TpBlob tp_blob) {
    tp_blob_ = std::move(tp_blob);
  }

  void AddAddressMapping(const AddressMapping& address_mapping) {
    address_mapping_list_.emplace_back(address_mapping);
  }

  void SetDpBlob(const DpBlob& dp_blob) {
    dp_blob_ = dp_blob;
  }

  void SetKpBlob(const KpBlob& kp_blob) {
    kp_blob_ = kp_blob;
  }

private:
  CcpDataParser::semantic_type* yylval = nullptr;
  std::string last_error_;

  DefinedPages current_defined_pages_;
  TpBlob current_tp_blob_;
  QpBlob current_qp_blob_;
  Source current_source_;

  std::vector<Source> source_list_;
  std::vector<Raster> raster_list_;
  std::vector<EventGroup> event_group_list_;
  std::optional<SeedKey> seed_key_;
  std::string checksum_;
  std::optional<TpBlob> tp_blob_;
  std::vector<AddressMapping> address_mapping_list_;
  std::optional<DpBlob> dp_blob_;
  std::optional<KpBlob> kp_blob_;

};

}


