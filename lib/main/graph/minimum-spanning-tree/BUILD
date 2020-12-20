load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "kruskal-dsu",
    srcs = [
        "main-kruskal-dsu.cpp",
        "template-kruskal-solver-interp.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "kruskal-simple",
    srcs = [
        "main-kruskal-simple.cpp",
        "template-kruskal-solver-interp.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "prim-dense",
    srcs = [
        "main-prim-dense.cpp",
        "template-prim-solver-interp.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "prim-sparse",
    srcs = [
        "main-prim-sparse.cpp",
        "template-prim-solver-interp.hpp",
    ],
    copts = COPTS,
    deps = DEPS,
)
