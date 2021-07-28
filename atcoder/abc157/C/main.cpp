#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> S, C;

int solve() {
    for (int v = 0; v <= 1000; ++v) {
        string vs = to_string(v);
        if (vs.size() != N) continue;
        bool pass = true;
        for (int i = 0; i < M; ++i) {
            if (vs[S[i]] != '0' + C[i]) {
                pass = false;
                break;
            }
        }
        if (pass) return v;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    S.assign(M, 0);
    C.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> S[i] >> C[i];
        --S[i];
    }
    cout << solve() << endl;

    return 0;
}