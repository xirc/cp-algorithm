load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")


cc_binary(
    name = "offline-rmq",
    srcs = [ "main-offline-rmq.cpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "union-find-tree-generic",
    srcs = [ "main-union-find-tree-generic.cpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "union-find-tree-group",
    srcs = [ "main-union-find-tree-group.cpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "union-find-tree",
    srcs = [ "main-union-find-tree.cpp" ],
    copts = COPTS,
    deps = DEPS,
)