#include <iostream>
#include "../template-main.hpp"
#include "./template-maximum-flow-interp.hpp"
#include "./maximum-flow-dinic.hpp"

using namespace std;

using Interp = SolverInterp<MaximumFlow>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Maximum Flow using Dinic";
    setup(interp, commands);
}