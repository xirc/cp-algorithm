#include <bits/stdc++.h>

using namespace std;

long long solve(int N, int K, vector<int>& A) {
    if (N <= 1) return 0;

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    long long ans = 0;
    for (int i = 0; i < K + 1 && i < N; ++i) {
        ans += A[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, K;
    vector<int> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        auto ans = solve(N, K, A);
        cout << ans << endl;
    }

    return 0;
}