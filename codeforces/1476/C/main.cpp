#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<ll> C;
vector<int> A, B;

ll solve() {
    ll ans = 0;
    ll S = ll(2) * abs(A[1]-B[1]);
    for (int i = 1; i < N; ++i) {
        if (A[i] == B[i]) {
            if (i > 1) ans = max(ans, S);
            S = 0;
        }
        S += 2 + (C[i]-1) - abs(A[i]-B[i]);
        S = max(S, abs(A[i] - B[i]) + 2 + C[i] - 1);
        ans = max(ans, S);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        C.assign(N, 0);
        A.assign(N, 0);
        B.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> C[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            --A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
            --B[i];
        }
        cout << solve() << endl;
    }

    return 0;
}