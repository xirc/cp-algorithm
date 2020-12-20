#include <iostream>
#include <numeric>
#include "template/template-main.hpp"
#include "template-sparse-table-interp.hpp"
#include "cpalgo/ds/sparse-table-idempotent.hpp"

using namespace std;

struct minimum {
    const int id = numeric_limits<int>::max();
    int operator()(const int& lhs, const int& rhs) const {
        return min(lhs, rhs);
    }
};
auto interp = new SolverInterp<SparseTable<int>,minimum>();

void setup(string& header, map<string,Command>& commands) {
    header = "Sparse Table for Range Minimum Query";
    setup(interp, header, commands);
}