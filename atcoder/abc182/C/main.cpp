#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(ll N) {
    vector<int> S;
    while (N > 0) {
        S.push_back(N % 10);
        N /= 10;
    }
    const int M = S.size();
    const int L = 1 << M;
    int ans = M;
    for (int b = 0; b < L; ++b) {
        bitset<18> bits(b);
        int c = M - bits.count();
        if (c >= ans) continue;
        int ss = 0;
        for (int i = 0; i < M; ++i) {
            if (!bits[i]) continue;
            ss += S[i];
        }
        if (ss % 3 == 0) {
            ans = min(ans, c);
        }
    }
    if (ans == M) {
        return -1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}