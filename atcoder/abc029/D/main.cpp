#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

ll powi(int e) {
    ll n = 1;
    while (e) {
        n *= 10;
        --e;
    }
    return n;
}

vector<vector<ll>> ds(10, vector<ll>(10, 0));
void build() {
    // 1
    ds[0][1] = 1;
    // 2 ~ 9
    for (int i = 2; i < 10; ++i) ds[0][i] += ds[0][i-1];
    for (int i = 1; i < 10; ++i) {
        // 1*10^ 1 ~ 2*10^1 -1
        ds[i][1] = powi(i) + ds[i-1][9] * 2;
        for (int j = 2; j < 10; ++j) {
            // j*10^ 1 ~ (j+1)*10^1 -1
            ds[i][j] = ds[i][j-1] + ds[i-1][9];
        }
    }
}

int solve(int N) {
    ll ans = 0;
    for (int i = 9; i > 0; --i) {
        ll v = powi(i);
        if (v > N) continue;
        int j = N / v;
        ans += ds[i][j-1];
        if (j == 1) {
            ans += (N % v + 1);
            ans += ds[i-1][9];
        }
        N %= v;
    }
    ans += ds[0][N];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    build();
    cout << solve(N) << endl;

    return 0;
}