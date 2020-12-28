#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/util/two_pointers.hpp"


TEST(TwoPointersTest, ShouldComputeIntervalCounts) {
    size_t const N = 100000;
    size_t num_of_call_pre_move_l = 0;
    size_t num_of_call_pre_move_r = 0;
    size_t num_of_call_update = 0;
    unsigned long long num_of_intervals = 0;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return true;
        },
        [&](size_t l, size_t r) {
            ++num_of_call_pre_move_l;
        },
        [&](size_t l, size_t r) {
            ++num_of_call_pre_move_r;
        },
        [&](size_t l, size_t r) {
            ++num_of_call_update;
            num_of_intervals += (r - l);
        }
    );
    EXPECT_EQ(N, num_of_call_pre_move_l);
    EXPECT_EQ(N, num_of_call_pre_move_r);
    EXPECT_EQ(N, num_of_call_update);
    unsigned long long const expect_num_of_intervals =
        (unsigned long long)(N) * (N + 1) / 2;
    EXPECT_EQ(expect_num_of_intervals, num_of_intervals);
}


TEST(TwoPointersTest, ShouldCompute) {
    size_t const N = 1000000;
    size_t num_of_call_pre_move_l = 0;
    size_t num_of_call_pre_move_r = 0;
    size_t num_of_call_update = 0;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return false;
        },
        [&](size_t l, size_t r) {
            ++num_of_call_pre_move_l;
        },
        [&](size_t l, size_t r) {
            ++num_of_call_pre_move_r;
        },
        [&](size_t l, size_t r) {
            ++num_of_call_update;
        }
    );
    EXPECT_EQ(size_t(0), num_of_call_pre_move_l);
    EXPECT_EQ(size_t(0), num_of_call_pre_move_r);
    EXPECT_EQ(N, num_of_call_update);
}