/*
* Copyright 2023 Ingemar Hedvall
* SPDX-License-Identifier: MIT
 */
#include "a2l/instance.h"
namespace a2l {

void Instance::AddOverwrite(std::unique_ptr<Overwrite>& overwrite) {
  overwrite_list_.emplace_back( std::move(overwrite) );
}

}
