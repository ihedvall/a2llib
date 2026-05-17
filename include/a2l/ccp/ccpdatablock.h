/*
* Copyright 2026 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */

#pragma once

#include <string>
#include <vector>
#include <optional>

#include "a2l/ccp/source.h"
#include "a2l/ccp/raster.h"
#include "a2l/ccp/eventgroup.h"
#include "a2l/ccp/seedkey.h"
#include "a2l/ccp/tpblob.h"
#include "a2l/ccp/addressmapping.h"
#include "a2l/ccp/dpblob.h"
#include "a2l/ccp/kpblob.h"

namespace a2l::ccp {

class CcpDataScanner;

class CcpDataBlock {
 public:
  CcpDataBlock() = delete;
  explicit CcpDataBlock(std::string if_data);

  [[nodiscard]] bool IsOk() const { return parse_; }
  [[nodiscard]] const std::string& LastError() const { return last_error_; }

  [[nodiscard]] const std::vector<Source>& GetSourceList() const {
    return source_list_;
  }

  [[nodiscard]] const std::vector<Raster>& GetRasterList() const {
    return raster_list_;
  }

  [[nodiscard]] const std::vector<EventGroup>& GetEventGroupList() const {
    return event_group_list_;
  }

  [[nodiscard]] const SeedKey* GetSeedKey() const {
    return seed_key_.has_value() ? &seed_key_.value() : nullptr;
  }

  [[nodiscard]] const std::string& GetChecksum() const { return checksum_; }

  [[nodiscard]] const TpBlob* GetTpBlob() const {
    return tp_blob_.has_value() ? &tp_blob_.value() : nullptr;
  }

  [[nodiscard]] const std::vector<AddressMapping>& GetAddressMappingList() const {
    return address_mapping_list_;
  }

  [[nodiscard]] const DpBlob* GetDpBlob() const {
    return dp_blob_.has_value() ? &dp_blob_.value() : nullptr;
  }

  [[nodiscard]] const KpBlob* GetKpBlob() const {
    return kp_blob_.has_value() ? &kp_blob_.value() : nullptr;
  }

  private:
    bool parse_ = false;
    std::string last_error_;

    std::vector<Source> source_list_;
    std::vector<Raster> raster_list_;
    std::vector<EventGroup> event_group_list_;

    std::optional<SeedKey> seed_key_;

    std::string checksum_;
    std::optional<TpBlob> tp_blob_;
    std::vector<AddressMapping> address_mapping_list_;
    std::optional<DpBlob> dp_blob_;
    std::optional<KpBlob> kp_blob_;

    void TransferData(CcpDataScanner& scanner);


};

}

