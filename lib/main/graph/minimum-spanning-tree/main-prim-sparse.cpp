#include <iostream>
#include "template-prim-solver-interp.hpp"
#include "cpalgo/graph/minimum-spanning-tree/prim-sparse.hpp"

using namespace std;

using Interp = SolverInterp<PrimSparse>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree with Prim for Sparse Graph";
    setup(interp, header, commands);
}