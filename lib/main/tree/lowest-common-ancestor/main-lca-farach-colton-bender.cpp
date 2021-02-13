#include <iostream>
#include "template-solver-interp.hpp"
#include "cpalgo/tree/lowest-common-ancestor/lca-farach-colton-bender.hpp"

using namespace std;

using Interp = SolverInterp<LCAFCB>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Lowest Common Ancestor using Segment Tree";
    setup(interp, header, commands);
}