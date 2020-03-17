#include <iostream>
#include "../template-main.hpp"
#include "./template-sparse-table-interp.hpp"
#include "./sparse-table.hpp"

using namespace std;

struct sum {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};
auto interp = new SolverInterp<SparseTable<int>,sum>();

void setup(string& header, map<string,Command>& commands) {
    header = "Sparse Table for Range Sum Query";
    setup(interp, header, commands);
}