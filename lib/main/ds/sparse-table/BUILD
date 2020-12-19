load("@rules_cc//cc:defs.bzl", "cc_binary")
load("//:variables.bzl", "COPTS")
load("//main:variables.bzl", "DEPS")


cc_binary(
    name = "sparse-table-idempotent",
    srcs = [ "main-sparse-table-idempotent.cpp", "template-sparse-table-interp.hpp" ],
    copts = COPTS,
    deps = DEPS,
)

cc_binary(
    name = "main-sparse-table",
    srcs = [ "main-sparse-table.cpp", "template-sparse-table-interp.hpp" ],
    copts = COPTS,
    deps = DEPS,
)