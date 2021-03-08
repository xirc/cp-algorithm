#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;


int N;
vector<vector<int>> G;

ll const MOD = 1e9 + 7;
vector<ll> B, W;
void dfs(int v, int p) {
    B[v] = W[v] = 1;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        W[v] = W[v] * ((W[u] + B[u]) % MOD) % MOD;
        B[v] = B[v] * W[u] % MOD;
    }
}

ll solve() {
    B.assign(N, 0);
    W.assign(N, 0);
    dfs(0, 0);
    return (B[0] + W[0]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << solve() << endl;

    return 0;
}