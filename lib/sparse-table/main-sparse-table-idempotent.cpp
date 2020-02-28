#include <iostream>
#include <climits>
#include "../template-main.hpp"
#include "./template-sparse-table-interp.hpp"
#include "./sparse-table-idempotent.hpp"

using namespace std;

struct minimum {
    static constexpr int id() { return INT_MAX; };
    static int op(const int& lhs, const int& rhs) {
        return std::min(lhs, rhs);
    }
};

using Solver = SparseTable<int,minimum>;
SolverInterp<Solver>* interp = new SolverInterp<Solver>();

void setup(string& header, map<string,Command>& commands) {
    header = "Sparse Table for Range Minimum Query";
    setup(interp, header, commands);
}