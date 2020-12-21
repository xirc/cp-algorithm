#include <iostream>
#include <algorithm>
#include <random>
#include <string>
#include "template/template-main.hpp"
#include "cpalgo/util/two-pointers.hpp"

using namespace std;

// Find the smallest sub-array size
// where the sum of the sub-array is greater than or equal to S.
class Solver : public TwoPointers<int> {
    vector<long long> A;
    long long S;
    long long sum;
public:
    Solver(const vector<long long>& array, long long S)
        : TwoPointers(array.size())
        , A(array), S(S), sum(0) {}
protected:
    int id() override {
        return N + 1;
    }
    bool should_move_right(int l, int r) override {
        return sum >= S;
    }
    void move_left(int l, int r) override {
        sum -= A[l];
    }
    void move_right(int l, int r) override {
        sum += A[r];
    }
    void update(int& ans, int l, int r) override {
        ans = min(ans, r - l);
    }
};

vector<long long> buffer;

void action_init() {
    int size; long long min, max;
    cin >> size >> min >> max;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    buffer.assign(size, 0);
    mt19937_64 random;
    for (int i = 0; i < size; ++i) {
        buffer[i] = random() % (max - min) + min;
    }
    cout << "true" << endl;
}

void action_query() {
    int S;
    cin >> S;
    Solver solver(buffer, S);
    cout << solver.solve() << endl;
}

void action_dump() {
    for (int i = 0; i < buffer.size(); ++i) {
        if (i > 0) cout << " ";
        cout << buffer[i];
    }
    cout << endl;
}

void setup(string& header, map<string,Command>& commands) {
    header =
        string("Find the Find the smallest sub-array size\n")
        + string("where the sum of the sub-array is greater than or equal to S");
    commands["init"] = { "init {size} {min} {max}", action_init };
    commands["query"] = { "query {S}", action_query };
    commands["dump"] = { "dump", action_dump };
}