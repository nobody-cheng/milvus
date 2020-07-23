// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "knowhere/index/vector_index/VecIndex.h"
#include "storage/FSHandler.h"

namespace milvus {
namespace codec {

class SSVectorIndexFormat {
 public:
    SSVectorIndexFormat() = default;

    std::string
    FilePostfix();

    void
    ReadRaw(const storage::FSHandlerPtr& fs_ptr, const std::string& file_path, knowhere::BinaryPtr& data);

    void
    ReadIndex(const storage::FSHandlerPtr& fs_ptr, const std::string& file_path, knowhere::BinarySet& data);

    void
    ReadCompress(const storage::FSHandlerPtr& fs_ptr, const std::string& file_path, knowhere::BinaryPtr& data);

    void
    ConvertRaw(const std::vector<uint8_t>& raw, knowhere::BinaryPtr& data);

    void
    ConstructIndex(const std::string& index_name, knowhere::BinarySet& index_data, knowhere::BinaryPtr& raw_data,
                   knowhere::BinaryPtr& compress_data, knowhere::VecIndexPtr& index);

    void
    WriteIndex(const storage::FSHandlerPtr& fs_ptr, const std::string& file_path, const knowhere::VecIndexPtr& index);

    void
    WriteCompress(const storage::FSHandlerPtr& fs_ptr, const std::string& file_path,
                  const knowhere::VecIndexPtr& index);

    // No copy and move
    SSVectorIndexFormat(const SSVectorIndexFormat&) = delete;
    SSVectorIndexFormat(SSVectorIndexFormat&&) = delete;

    SSVectorIndexFormat&
    operator=(const SSVectorIndexFormat&) = delete;
    SSVectorIndexFormat&
    operator=(SSVectorIndexFormat&&) = delete;
};

using SSVectorIndexFormatPtr = std::shared_ptr<SSVectorIndexFormat>;

}  // namespace codec
}  // namespace milvus