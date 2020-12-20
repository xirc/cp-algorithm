load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "bellman-ford",
    srcs = ["main-bellman-ford.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "floyd-warshall",
    srcs = ["main-floyd-warshall.cpp"],
    copts = COPTS,
    deps = DEPS,
)
