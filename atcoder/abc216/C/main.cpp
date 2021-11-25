#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;

    cin >> N;
    vector<char> ops;
    while (N > 0) {
        if (N & 1) {
            ops.push_back('A');
        }
        ops.push_back('B');
        N >>= 1;
    }
    if (ops.back() == 'B') {
        ops.pop_back();
    }
    reverse(ops.begin(), ops.end());

    cout << string(ops.begin(), ops.end()) << endl;

    return 0;
}