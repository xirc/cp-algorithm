#include <bits/stdc++.h>

using namespace std;

void solve(int N, int K, vector<int> const& A, vector<bool>& B) {
    unordered_map<int, int> L, R;
    B.assign(N, false);
    for (int i = 0; i < N; ++i) {
        auto v = A[i];
        auto u = K - v;
        auto lc = L[u], rc = R[u];
        if (lc < rc) {
            B[i] = false;
            ++L[v];
        } else {
            B[i] = true;
            ++R[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, K;
    vector<int> A;
    vector<bool> B;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        solve(N, K, A, B);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << (B[i] ? 1 : 0);
        }
        cout << endl;
    }

    return 0;
}