#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;
vector<int> const nothing = {};

vector<int> solve() {
    N = min(N, 8);
    int const M = 1 << N;
    vector<int> hole(200, 0);
    for (int s = 1; s < M; ++s) {
        ll m = 0;
        for (int i = 0; i < N; ++i) {
            if ((s >> i) & 1) {
                m += A[i];
            }
        }
        m %= 200;
        if (hole[m]) {
            return { hole[m], s };
        }
        hole[m] = s;
    }
    return nothing;
}

void dump(int s) {
    bitset<8> bs(s);
    cout << bs.count();
    for (auto i = 0; i < 8; ++i) {
        if (bs[i]) cout << " " << (i+1);
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    auto ans = solve();
    if (ans == nothing) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        dump(ans[0]);
        dump(ans[1]);
    }

    return 0;
}