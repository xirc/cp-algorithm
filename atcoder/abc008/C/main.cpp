#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> C;

ff solve() {
    ff exp = 0;
    for (int i = 0; i < N; ++i) {
        int M = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (C[i] % C[j] == 0) ++M;
        }
        ff px = ff(M / 2 + 1) / (M + 1);
        exp += px;
    }
    return exp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    C.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    cout << fixed << setprecision(12) << solve() << endl;

    return 0;
}