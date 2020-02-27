#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include "../template-main.hpp"
#include "./cartesian-tree-construction.hpp"

using namespace std;

vector<int> ary;

void action_init() {
    mt19937 random;
    int size, min, max;
    cin >> size >> min >> max;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    ary.assign(size, 0);
    for (int i = 0; i < size; ++i) {
        ary[i] = random() % (max - min) + min;
    }
    cout << "true" << endl;
}

void action_update() {
    int index, value;
    cin >> index >> value;
    if (index < 0 || index >= ary.size()) {
        cout << "false" << endl;
        return;
    }
    ary[index] = value;
}

void dump_array(string prefix, vector<int> array, int cw) {
    cout << prefix;
    for (int i = 0; i < array.size(); ++i) {
        if (i > 0) cout << " ";
        cout << setw(cw) << setfill(' ');
        cout << array[i];
    }
    cout << endl;
}

void action_construct() {
    auto parent = construct(ary);

    const int N = ary.size();
    int M = N;
    if (N > 0) {
        auto minmax = minmax_element(ary.begin(), ary.end());
        M = max(M, abs(*minmax.first));
        M = max(M, abs(*minmax.second));
    }
    int cw = ceil(log10(M)) + 1;

    vector<int> indice(N);
    for (int i = 0; i < N; ++i) {
        indice[i] = i;
    }
    dump_array("i: ", indice, cw + 1);
    dump_array("a: ", ary, cw + 1);
    dump_array("p: ", parent, cw + 1);
}

void setup(string& header, map<string,Command>& commands) {
    header = "Cartesian Tree Construction O(N)";
    commands["init"] =
        Command { "init {size} {min} {max}", action_init };
    commands["update"] =
        Command { "update {index} {value}", action_update };
    commands["construct"] =
        Command { "construct", action_construct };
}