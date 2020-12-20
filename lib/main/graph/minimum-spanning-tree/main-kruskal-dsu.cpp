#include <iostream>
#include "template-kruskal-solver-interp.hpp"
#include "cpalgo/graph/minimum-spanning-tree/kruskal-dsu.hpp"

using namespace std;

using Interp = SolverInterp<Kruskal>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree using Kruskal with DSU";
    setup(interp, header, commands);
}