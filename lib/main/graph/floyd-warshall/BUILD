load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "floyd-warshall",
    srcs = ["main-floyd-warshall.cpp"],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "num-path-of-fixed-length",
    srcs = [
        "main-num-path-of-fixed-length.cpp",
        "num-path-of-fixed-length.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "num-path-with-length-upto",
    srcs = [
        "main-num-path-with-length-upto.cpp",
        "num-path-of-fixed-length.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "shortest-path-of-fixed-length",
    srcs = [
        "main-shortest-path-of-fixed-length.cpp",
        "shortest-path-of-fixed-length.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "shortest-path-with-length-upto",
    srcs = [
        "main-shortest-path-with-length-upto.cpp",
        "shortest-path-of-fixed-length.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)
