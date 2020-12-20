load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "dice",
    srcs = ["main-dice.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "two-pointers",
    srcs = ["main-two-pointers.cpp"],
    copts = COPTS,
    deps = DEPS,
)
