// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/providers/rocm/rocm_common.h"

namespace onnxruntime {
namespace rocm {
template <typename T>
class MatMul final : public RocmKernel {
  using Base = RocmKernel;

 public:
  MatMul(const OpKernelInfo& info)
      : RocmKernel(info),
        alpha_{info.GetAttrOrDefault<float>("alpha", 1.0f)},
        trans_A_{info.GetAttrOrDefault<int64_t>("transA", 0) != 0},
        trans_B_{info.GetAttrOrDefault<int64_t>("transB", 0) != 0} {
  }

  Status ComputeInternal(OpKernelContext* context) const override;

 private:
  const float alpha_;
  const bool trans_A_;
  const bool trans_B_;
};
}  // namespace rocm
}  // namespace onnxruntime