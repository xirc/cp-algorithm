#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<vector<int>> G;
ll const MOD = 1e9 + 7;

ll dfs(int v, int p) {
    if (G[v].size() > K) return 0;
    ll ans = 1;
    int c = v == p ? K - 1 : K - 2;
    for (auto u : G[v]) {
        if (u == p) continue;
        ans *= c;
        ans %= MOD;
        ans *= dfs(u, v);
        ans %= MOD;
        --c;
    }
    return ans;
}

ll solve() {
    return K * dfs(0, 0) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    G.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a); 
    }
    cout << solve() << endl;

    return 0;
}