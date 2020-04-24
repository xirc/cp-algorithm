#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include "../template-main.hpp"
#include "./disjoint-sparse-table.hpp"

using namespace std;

struct Monoid {
    long long id = 0;
    long long operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};
using Solver = DisjointSparseTable<long long>;
using SolverPtr = shared_ptr<Solver>;

vector<long long> buffer;
SolverPtr solver = nullptr;

void action_init() {
    int size; long long min, max;
    cin >> size >> min >> max;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    mt19937_64 random;
    solver = nullptr;
    buffer.assign(size, 0);
    for (int i = 0; i < size; ++i) {
        buffer[i] = random() % (max - min) + min;
    }
    cout << "true" << endl;
}

void action_query() {
    int l, r;
    cin >> l >> r;
    if (solver == nullptr) {
        solver = SolverPtr(new Solver(buffer, Monoid()));
    }
    cout << solver->query(l, r) << endl;
}

void action_dump() {
    for (int i = 0; i < buffer.size(); ++i) {
        if (i > 0) cout << " ";
        cout << buffer[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header = "Range Sum Query with Disjoint Sparse Table";
    commands["init"] = { "init {size} {min} {max}", action_init };
    commands["query"] = { "query {l} {r}", action_query };
    commands["dump"] = { "dump", action_dump };
}