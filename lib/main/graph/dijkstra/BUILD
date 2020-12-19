load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

HDRS = [ "template-main-dijkstra-interp.hpp" ]

cc_binary(
    name = "dijkstra-priority-queue",
    srcs = [ "main-dijkstra-priority-queue.cpp" ] + HDRS,
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "dijkstra-set",
    srcs = [ "main-dijkstra-set.cpp" ] + HDRS,
    copts = COPTS,
    deps = DEPS,
)