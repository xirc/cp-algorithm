#include "../template-main.hpp"
#include "./template-main-bellman-ford-interp.hpp"
#include "./spfa.hpp"

using namespace std;

using Interp = SolverInterp<SPFA>;
Interp *interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}