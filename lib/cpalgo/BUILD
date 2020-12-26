load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//:variables.bzl", "COPTS")

COPTS_TEST = COPTS + ["-Iexternal/gtest/include/"]

cc_library(
    name = "main",
    hdrs = glob(["**/*.hpp"]),
    copts = COPTS,
    include_prefix = "cpalgo",
    visibility = ["//visibility:public"],
)

cc_test(
    name = "main_test",
    srcs = glob(["**/*_test.cpp"]),
    copts = COPTS_TEST,
    deps = [
        ":main",
        "@gtest//:main",
    ],
)
