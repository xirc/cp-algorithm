load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "binexp-fibonacci",
    srcs = ["main-binexp-fibonacci.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "binexp-mulmod",
    srcs = ["main-binexp-mulmod.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "binexp-pow",
    srcs = ["main-binexp-pow.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "binexp-powmod",
    srcs = ["main-binexp-powmod.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "combination-basic",
    srcs = [
        "main-combination-basic.cpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "combination-pascal",
    srcs = [
        "main-combination-pascal.cpp",
        "template-combination-interp.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "gcd",
    srcs = ["main-gcd.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "lcm",
    srcs = ["main-lcm.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "prime-factorization-basic",
    srcs = ["main-prime-factorization-basic.cpp"],
    copts = COPTS,
    deps = DEPS,
)
