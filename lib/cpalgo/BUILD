load("@rules_cc//cc:defs.bzl", "cc_library")
load("//:variables.bzl", "COPTS")


cc_library(
    name = "main",
    hdrs = glob([ "**/*.hpp" ]),
    include_prefix = "cpalgo",
    copts = COPTS,
    visibility = [ "//visibility:public" ],
)