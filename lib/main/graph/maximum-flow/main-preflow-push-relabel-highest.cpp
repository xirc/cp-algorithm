#include <iostream>
#include "template-interp.hpp"
#include "cpalgo/graph/maximum-flow/preflow-push-relabel-highest.hpp"

using namespace std;

using Interp = SolverInterp<MaximumFlow>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    header = "Maximum Flow using Preflow Push-Relabel (HighestLabel)";
    setup(interp, commands);
}