load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")


cc_library(
    name = "main",
    copts = COPTS,
    hdrs = [ "template-main.hpp" ],
    include_prefix = "template",
    visibility = [ "//visibility:public" ],
)