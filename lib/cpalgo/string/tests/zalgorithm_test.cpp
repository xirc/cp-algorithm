#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "cpalgo/string/zalgorithm.hpp"

using namespace std;

TEST(ZalgorithmTest, EmptyString) {

    auto zvalue = zalgorithm("");
    EXPECT_EQ(size_t(0), zvalue.size());

}

TEST(ZalgorithmTest, Example1) {

    auto zvalue = zalgorithm("aabcaabdaabc");
    vector<size_t> expected_zvalue = { 0, 1, 0, 0, 3, 1, 0, 0, 4, 1, 0, 0 };
    EXPECT_EQ(expected_zvalue, zvalue);

}

TEST(ZalgorithmTest, Example2) {

    auto zvalue = zalgorithm("aaaaa");
    vector<size_t> expected_zvalue = { 0, 4, 3, 2, 1 };
    EXPECT_EQ(expected_zvalue, zvalue);

}

TEST(ZalgorithmTest, Example3) {

    auto zvalue = zalgorithm("ababab");
    vector<size_t> expected_zvalue = { 0, 0, 4, 0, 2, 0 };
    EXPECT_EQ(expected_zvalue, zvalue);

}

TEST(ZalgorithmTest, Example4) {

    auto zvalue = zalgorithm("aabaacaad");
    vector<size_t> expected_zvalue = { 0, 1, 0, 2, 1, 0, 2, 1, 0 };
    EXPECT_EQ(expected_zvalue, zvalue);

}