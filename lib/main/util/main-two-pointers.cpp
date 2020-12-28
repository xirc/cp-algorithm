#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "cpalgo/util/two_pointers.hpp"

using namespace std;

// Find the smallest sub-array size
// where the sum of the sub-array is greater than or equal to S.
size_t solve(vector<int> const& A, long long const S) {
    const size_t N = A.size();
    long long sum = 0;
    size_t ans = N + 1;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return sum < S;
        },
        [&](size_t l, size_t r) {
            sum -= A[l];
        },
        [&](size_t l, size_t r) {
            sum += A[r];
        },
        [&](size_t l, size_t r) {
            if (sum >= S) {
                ans = min(ans, r - l);
            }
        }
    );
    return ans;
}

vector<int> buffer;

void action_init() {
    size_t size;
    int min, max;
    cin >> size >> min >> max;
    if (size < 0) {
        cout << "false" << endl;
        return;
    }
    buffer.assign(size, 0);
    mt19937_64 random;
    for (size_t i = 0; i < size; ++i) {
        buffer[i] = random() % (max - min) + min;
    }
    cout << "true" << endl;
}

void action_query() {
    long long S;
    cin >> S;
    cout << solve(buffer, S) << endl;
}

void action_dump() {
    for (size_t i = 0; i < buffer.size(); ++i) {
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