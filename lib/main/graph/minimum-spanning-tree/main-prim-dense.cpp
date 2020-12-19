#include <iostream>
#include "template-prim-solver-interp.hpp"
#include "cpalgo/graph/minimum-spanning-tree/prim-dense.hpp"

using namespace std;

using Interp = SolverInterp<PrimDense>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree with Prim for Dense Graph";
    setup(interp, header, commands);
}