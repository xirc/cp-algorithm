#include <iostream>
#include "template-interp.hpp"
#include "cpalgo/graph/maximum-flow/edmonds-karp.hpp"

using namespace std;

using Interp = SolverInterp<MaximumFlow>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Maximum Flow using Edmonds&Karp";
    setup(interp, commands);
}