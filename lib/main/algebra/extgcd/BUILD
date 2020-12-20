load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "extgcd-iterative",
    srcs = [
        "main-extgcd-iterative.cpp",
        "template-extgcd-interop.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "extgcd-recursive",
    srcs = [
        "main-extgcd-recursive.cpp",
        "template-extgcd-interop.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)
