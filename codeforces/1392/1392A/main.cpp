#include <bits/stdc++.h>

using namespace std;

int solve(int N, vector<int> const& A) {
    bool same = all_of(A.begin(), A.end(), [&](const int v) { return v == A[0]; });
    if (same) return N;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(N, A) << endl;
    }

    return 0;
}