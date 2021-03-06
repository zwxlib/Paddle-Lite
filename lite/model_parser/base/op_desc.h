// Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include <string>
#include <vector>
#include "lite/utils/string.h"

namespace paddle {
namespace lite {

// The AttrType is used to make the proto::AttrType portable.
enum class OpAttrType {
  INT = 0,
  FLOAT = 1,
  STRING = 2,
  INTS = 3,
  FLOATS = 4,
  STRINGS = 5,
  BOOLEAN = 6,
  BOOLEANS = 7,
  BLOCK = 8,
  LONG = 9,
  BLOCKS = 10,
  LONGS = 11,
  UNK,
};

template <OpAttrType Type>
struct OpAttrTypeTrait;

template <typename T>
struct OpDataTypeTrait;

#define TYPE_TRAIT_IMPL(T, type__)                  \
  template <>                                       \
  struct OpAttrTypeTrait<OpAttrType::T> {           \
    typedef type__ DT;                              \
  };                                                \
  template <>                                       \
  struct OpDataTypeTrait<type__> {                  \
    static constexpr OpAttrType AT = OpAttrType::T; \
    static constexpr const char* ATN = #T;          \
  };

TYPE_TRAIT_IMPL(INT, int32_t);
TYPE_TRAIT_IMPL(FLOAT, float);
TYPE_TRAIT_IMPL(STRING, std::string);
TYPE_TRAIT_IMPL(BOOLEAN, bool);
TYPE_TRAIT_IMPL(LONG, int64_t);
TYPE_TRAIT_IMPL(INTS, std::vector<int>);
TYPE_TRAIT_IMPL(FLOATS, std::vector<float>);
TYPE_TRAIT_IMPL(STRINGS, std::vector<std::string>);
TYPE_TRAIT_IMPL(LONGS, std::vector<int64_t>);
#undef TYPE_TRAIT_IMPL

class OpDescReadAPI {
 public:
  virtual std::string Type() const = 0;
  virtual std::vector<std::string> Input(const std::string& param) const = 0;
  virtual std::vector<std::string> InputArgumentNames() const = 0;
  virtual std::vector<std::string> Output(const std::string& param) const = 0;
  virtual std::vector<std::string> OutputArgumentNames() const = 0;
  virtual bool HasAttr(const std::string& name) const = 0;
  virtual OpAttrType GetAttrType(const std::string& name) const = 0;
  virtual std::vector<std::string> AttrNames() const = 0;

  template <typename T>
  T GetAttr(const std::string& name) const;

  std::string Repr() const {
    STL::stringstream ss;
    ss << Type();
    ss << "(";
    for (auto& arg : InputArgumentNames()) {
      ss << arg << ":";
      for (auto val : Input(arg)) {
        ss << val << " ";
      }
    }
    ss << ") -> (";
    for (auto& arg : OutputArgumentNames()) {
      ss << arg << ":";
      for (auto val : Output(arg)) {
        ss << val << " ";
      }
    }
    ss << ")";
    return ss.str();
  }

  virtual ~OpDescReadAPI() = default;
};

class OpDescWriteAPI {
 public:
  virtual void SetType(const std::string& type) = 0;
  virtual void SetInput(const std::string& param,
                        const std::vector<std::string>& args) = 0;
  virtual void SetOutput(const std::string& param,
                         const std::vector<std::string>& args) = 0;

  template <typename T>
  void SetAttr(const std::string& name, const T& v);

  virtual ~OpDescWriteAPI() = default;
};

// The reading and writing of the model are one-time and separate.
// This interface is a combination of reading and writing interfaces,
// which is used to support legacy interfaces.

class OpDescAPI : public OpDescReadAPI, public OpDescWriteAPI {
 public:
  using AttrType = OpAttrType;
  virtual ~OpDescAPI() = default;
};

}  // namespace lite
}  // namespace paddle
