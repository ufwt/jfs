//===----------------------------------------------------------------------===//
//
//                        JFS - The JIT Fuzzing Solver
//
// Copyright 2017 Daniel Liew
//
// This file is distributed under the MIT license.
// See LICENSE.txt for details.
//
//===----------------------------------------------------------------------===//
#ifndef JFS_RUNTIME_SMTLIB_NATIVE_BITVECTOR_H
#define JFS_RUNTIME_SMTLIB_NATIVE_BITVECTOR_H
#include "SMTLIB/BufferRef.h"
#include "SMTLIB/jassert.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t jfs_nr_bitvector_ty;
typedef uint64_t jfs_nr_width_ty;

#define JFS_NR_BITVECTOR_TY_BITWIDTH (sizeof(jfs_nr_bitvector_ty) * 8)

jfs_nr_bitvector_ty jfs_nr_concat(const jfs_nr_bitvector_ty lhs,
                                  const jfs_nr_width_ty lhsBitWidth,
                                  const jfs_nr_bitvector_ty rhs,
                                  const jfs_nr_width_ty rhsBitWidth);

jfs_nr_bitvector_ty jfs_nr_extract(const jfs_nr_bitvector_ty value,
                                   const jfs_nr_width_ty bitWidth,
                                   const jfs_nr_width_ty highBit,
                                   const jfs_nr_width_ty lowBit);

jfs_nr_bitvector_ty jfs_nr_zero_extend(const jfs_nr_bitvector_ty value,
                                       const jfs_nr_width_ty bitWidth,
                                       const jfs_nr_width_ty extraBits);

jfs_nr_bitvector_ty jfs_nr_sign_extend(const jfs_nr_bitvector_ty value,
                                       const jfs_nr_width_ty bitWidth,
                                       const jfs_nr_width_ty extraBits);

jfs_nr_bitvector_ty jfs_nr_make_bitvector(const uint8_t* bufferData,
                                          const uint64_t bufferSize,
                                          const uint64_t lowBit,
                                          const uint64_t highBit);

#ifdef __cplusplus
}
#endif

#endif