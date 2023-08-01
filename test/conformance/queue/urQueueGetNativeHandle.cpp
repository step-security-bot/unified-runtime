// Copyright (C) 2023 Intel Corporation
// Part of the Unified-Runtime Project, under the Apache License v2.0 with LLVM Exceptions.
// See LICENSE.TXT
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#include <uur/fixtures.h>

using urQueueGetNativeHandleTest = uur::urQueueTest;
UUR_INSTANTIATE_DEVICE_TEST_SUITE_P(urQueueGetNativeHandleTest);

TEST_P(urQueueGetNativeHandleTest, Success) {
    ur_native_handle_t native_handle = nullptr;
    if (auto error = urQueueGetNativeHandle(queue, nullptr, &native_handle)) {
        ASSERT_EQ_RESULT(UR_RESULT_ERROR_UNSUPPORTED_FEATURE, error);
    }
}

TEST_P(urQueueGetNativeHandleTest, InvalidNullHandleQueue) {
    ur_native_handle_t native_handle = nullptr;
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_HANDLE,
                     urQueueGetNativeHandle(nullptr, nullptr, &native_handle));
}

TEST_P(urQueueGetNativeHandleTest, InvalidNullPointerNativeHandle) {
    ASSERT_EQ_RESULT(UR_RESULT_ERROR_INVALID_NULL_POINTER,
                     urQueueGetNativeHandle(queue, nullptr, nullptr));
}
