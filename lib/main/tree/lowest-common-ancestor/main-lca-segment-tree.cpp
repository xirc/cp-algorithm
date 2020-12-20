#include <iostream>
#include "template-solver-interp.hpp"
#include "cpalgo/tree/lowest-common-ancestor/lca-segment-tree.hpp"

using namespace std;

using Interp = SolverInterp<LCA>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Lowest Common Ancestor using Segment Tree";
    setup(interp, header, commands);
}