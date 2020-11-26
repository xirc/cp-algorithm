#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;
vector<int> A;

ll solve() {
    ll ans = 0;
    int L = N - (N+1) / 2 + 1;
    for (int kk = 0; kk < K; ++kk) {
        int i = N * K - L * (kk+1);
        ans += A[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        A.assign(N * K, 0);
        for (int i = 0; i < N * K; ++i) {
            cin >> A[i];
        }
        cout << solve() << endl;
    }

    return 0;
}