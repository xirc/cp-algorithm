load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "bipartite-check",
    srcs = ["main-bipartite-check.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "bipartite-maximum-matching",
    srcs = ["main-bipartite-maximum-matching.cpp"],
    copts = COPTS,
    deps = DEPS,
)
