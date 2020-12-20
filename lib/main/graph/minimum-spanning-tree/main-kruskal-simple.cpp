#include <iostream>
#include "template-kruskal-solver-interp.hpp"
#include "cpalgo/graph/minimum-spanning-tree/kruskal-simple.hpp"

using namespace std;

using Interp = SolverInterp<KruskalSimple>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree using Kruskal";
    setup(interp, header, commands);
}