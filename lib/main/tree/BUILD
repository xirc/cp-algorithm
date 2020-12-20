load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "diameter",
    srcs = ["main-diameter.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "euler-tour",
    srcs = ["main-euler-tour.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "heavy-light-decomposition",
    srcs = ["main-heavy-light-decomposition.cpp"],
    copts = COPTS,
    deps = DEPS,
)
