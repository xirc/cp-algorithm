#include <iostream>
#include "template-solver-interp.hpp"
#include "cpalgo/tree/lca/lca_binary_lifting.hpp"

using namespace std;

using Interp = SolverInterp<LCABinaryLifting>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Lowest Common Ancestor using Binary Lifting";
    setup(interp, header, commands);
}