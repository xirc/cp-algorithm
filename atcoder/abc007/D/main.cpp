#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int const M = 19;
vector<vector<ll>> DP(M, vector<ll>(10, 0));

int log10(ll n) {
    int e = 0;
    while (n >= 10) {
        n /= 10;
        ++e;
    }
    return e;
}

ll pow10(int e) {
    ll ans = 1;
    for (int i = 0; i < e; ++i) {
        ans *= 10;
    }
    return ans;
}

void build() {
    DP[0][4] = 1;
    DP[0][9] = 1;
    for (int i = 1; i < 10; ++i) {
        DP[0][i] += DP[0][i-1];
    }
    for (int i = 1; i < M - 1; ++i) {
        DP[i][0] += DP[i-1][9];
        for (int j = 1; j < 10; ++j) {
            DP[i][j] += DP[i][j-1];
            if (j == 4 || j == 9) {
                DP[i][j] += pow10(i);
            } else {
                DP[i][j] += DP[i-1][9];
            }
        }
    }
    DP[M-1][0] = DP[M-2][9];
}

ll query(ll N) {
    if (N == 0) return 0;
    int K = log10(N);
    ll E = pow10(K);
    ll b = N / E;
    if (b == 4 || b == 9) {
        if (E == 1) return DP[0][b];
        return DP[K][b-1] + (N % E) + 1;
    }
    return DP[K][b-1] + query(N % E);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    ll A, B;
    cin >> A >> B;

    build();
    ll ans = query(B) - query(A-1);
    cout << ans << endl;

    return 0;
}