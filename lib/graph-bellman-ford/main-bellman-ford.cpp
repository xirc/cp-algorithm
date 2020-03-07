#include "../template-main.hpp"
#include "./template-main-bellman-ford-interp.hpp"
#include "./bellman-ford.hpp"

using namespace std;

using Interp = SolverInterp<BellmanFord>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}