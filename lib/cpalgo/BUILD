load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

cc_library(
    name = "main",
    hdrs = glob(["**/*.hpp"]),
    copts = COPTS,
    include_prefix = "cpalgo",
    visibility = ["//visibility:public"],
)
