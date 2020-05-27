#include <iostream>
#include "../template-main.hpp"
#include "./template-kruskal-solver-interp.hpp"
#include "./kruskal_dsu.hpp"

using namespace std;

using Interp = SolverInterp<Kruskal>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree using Kruskal with DSU";
    setup(interp, header, commands);
}