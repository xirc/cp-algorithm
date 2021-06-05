#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
int S, T;
vector<vector<int>> G;

int solve() {
    int const inf = 1e8;
    queue<int> Q;
    vector<int> D(N * 3, inf);
    Q.push(3*S);
    D[3*S] = 0;
    while (Q.size()) {
        auto u = Q.front(); Q.pop();
        if (u == 3*T) return D[u] / 3;
        for (auto v : G[u]) {
            if (D[v] <= D[u] + 1) continue;
            D[v] = D[u] + 1;
            Q.push(v);
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(3*N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[3*u].push_back(3*v+1);
        G[3*u+1].push_back(3*v+2);
        G[3*u+2].push_back(3*v);
    }
    cin >> S >> T;
    --S, --T;
    cout << solve() << endl;

    return 0;
}