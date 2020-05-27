#include <iostream>
#include "../template-main.hpp"
#include "./template-prim-solver-interp.hpp"
#include "./prim-dense.hpp"

using namespace std;

using Interp = SolverInterp<PrimDense>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree with Prim for Dense Graph";
    setup(interp, header, commands);
}