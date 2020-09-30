#include <bits/stdc++.h>

using namespace std;

// O(N)
long long solve(vector<int> const& A) {
    const int N = A.size();
    if (N == 0) return 0;
    long long ans = A[0];
    for (int i = 1; i < N; ++i) {
        ans += max(A[i] - A[i-1], 0);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, Q;
    vector<int> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> Q;
        assert(Q == 0);
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(A) << endl;
    }

    return 0;
}