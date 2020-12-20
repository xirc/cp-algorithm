#include "template-main-bellman-ford-interp.hpp"
#include "cpalgo/graph/bellman-ford.hpp"

using namespace std;

using Interp = SolverInterp<BellmanFord>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}