#include <iostream>
#include "template-solver-interp.hpp"
#include "cpalgo/tree/lca/lca_segment_tree.hpp"

using namespace std;

using Interp = SolverInterp<LCASegmentTree>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Lowest Common Ancestor using Segment Tree";
    setup(interp, header, commands);
}