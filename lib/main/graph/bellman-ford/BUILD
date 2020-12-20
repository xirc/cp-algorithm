load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

HDRS = ["template-main-bellman-ford-interp.hpp"]

cc_binary(
    name = "bellman-ford",
    srcs = ["main-bellman-ford.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "spfa",
    srcs = ["main-spfa.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)
