load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

HDRS = ["template-interp.hpp"]

cc_binary(
    name = "dinic",
    srcs = ["main-dinic.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "edmonds-karp",
    srcs = ["main-edmonds-karp.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "mpm",
    srcs = ["main-mpm.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "preflow-push-relabel-generic",
    srcs = ["main-preflow-push-relabel-generic.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "preflow-push-relabel-highest",
    srcs = ["main-preflow-push-relabel-highest.cpp"] + HDRS,
    copts = COPTS,
    deps = DEPS,
)
