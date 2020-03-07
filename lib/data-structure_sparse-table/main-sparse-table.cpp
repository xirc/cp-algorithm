#include <iostream>
#include "../template-main.hpp"
#include "./template-sparse-table-interp.hpp"
#include "./sparse-table.hpp"

using namespace std;

struct sum {
    static constexpr int id() { return 0; };
    static int op(const int& lhs, const int& rhs) {
        return lhs + rhs;
    }
};

using Solver = SparseTable<int,sum>;
SolverInterp<Solver>* interp = new SolverInterp<Solver>();

void setup(string& header, map<string,Command>& commands) {
    header = "Sparse Table for Range Sum Query";
    setup(interp, header, commands);
}