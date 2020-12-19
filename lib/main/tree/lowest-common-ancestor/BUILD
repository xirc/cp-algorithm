load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")

cc_binary(
    name = "lca-binary-lifting",
    srcs = [ "main-lca-binary-lifting.cpp", "template-solver-interp.hpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "lca-farach-colton-bender",
    srcs = [ "main-lca-farach-colton-bender.cpp", "template-solver-interp.hpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "lca-segment-tree",
    srcs = [ "main-lca-segment-tree.cpp", "template-solver-interp.hpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "lca-tarjan",
    srcs = [ "main-lca-tarjan.cpp" ],
    copts = COPTS,
    deps = DEPS,
)