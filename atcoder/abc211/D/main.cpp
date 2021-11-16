#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<vector<int>> G;

ll solve() {
    int const inf = 1e8;
    ll const MOD = 1e9+7;
    vector<int> D(N, inf);
    vector<ll> C(N, 0);
    queue<int> Q;
    D[0] = 0;
    C[0] = 1;
    Q.push(0);
    while (Q.size()) {
        auto v = Q.front(); Q.pop();
        for (int u : G[v]) {
            if (D[u] == D[v] + 1) {
                C[u] += C[v];
                C[u] %= MOD;
            } else if (D[u] > D[v] + 1) {
                D[u] = D[v] + 1;
                C[u] = C[v];
                Q.push(u);
            }
        }
    }
    return C[N-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << solve() << endl;

    return 0;
}