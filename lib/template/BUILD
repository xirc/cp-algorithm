load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")

cc_library(
    name = "main",
    hdrs = ["template-main.hpp"],
    copts = COPTS,
    include_prefix = "template",
    visibility = ["//visibility:public"],
)
