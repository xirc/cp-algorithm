#include <iostream>
#include "../template-main.hpp"
#include "./template-kruskal-solver-interp.hpp"
#include "./kruskal_simple.hpp"

using namespace std;

using Interp = SolverInterp<KruskalSimple>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Minimum Spanning Tree using Kruskal";
    setup(interp, header, commands);
}