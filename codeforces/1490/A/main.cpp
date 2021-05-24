#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int N, vector<int> const& A) {
    int ans = 0;
    for (int i = 1; i < N; ++i) {
        int maxi = max(A[i], A[i-1]);
        int mini = min(A[i], A[i-1]);
        while (maxi > mini * 2) {
            mini *= 2;
            ++ans;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int N;
        vector<int> A;
        cin >> N;
        A.assign(N, 0);
        for (auto &a : A) cin >> a;
        cout << solve(N, A) << endl;
    }

    return 0;
}