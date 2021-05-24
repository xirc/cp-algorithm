#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int N, vector<int> const& A) {
    vector<int> c(3, 0);
    for (int i = 0; i < N; ++i) {
        c[A[i]%3]++;
    }

    int const M = N / 3;
    int ans = 0;
    for (int j = 0; j < 2; ++j) {
        for (int i = 0; i < 3; ++i) {
            int delta = max(0, c[i] - M);
            ans += delta;
            c[i] -= delta;
            c[(i+1)%3] += delta;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        int N;
        vector<int> A;
        cin >> N;
        A.assign(N, 0);
        for (auto &a : A) cin >> a;
        cout << solve(N, A) << endl;
    }


    return 0;
}