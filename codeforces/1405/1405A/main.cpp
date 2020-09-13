#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> const& P) {
    // 2 4 3 1 5 -> 6,7,4,6
    // 5 1 3 4 2 -> 6,4,7,6
    vector<int> A = P;
    reverse(A.begin(), A.end());
    return A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> P;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        P.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }
        auto ans = solve(P);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}