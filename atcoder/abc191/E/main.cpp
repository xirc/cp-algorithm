#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int const inf = 1e9;
int N, M;
vector<vector<int>> H;
vector<vector<vector<int>>> G;

void dijkstra(int s, vector<int>& D) {
    D.assign(N, inf);
    priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int,2>>> Q;
    D[s] = 0;
    Q.push({ 0, s });
    while (Q.size()) {
        auto e = Q.top(); Q.pop();
        auto t = e[0], v = e[1];
        if (t > D[v]) continue;
        for (auto const& e2 : G[v]) {
            auto dt = e2[1], u = e2[0];
            if (D[u] > t + dt) {
                D[u] = t + dt;
                Q.push({ t + dt, u });
            }
        }
    }
}

vector<int> solve() {
    vector<int> rs(N, 0);
    vector<int> D;
    for (int v = 0; v < N; ++v) {
        int ans = inf;
        dijkstra(v, D);
        for (int u = 0; u < N; ++u) {
            if (H[u][v] == inf) continue;
            ans = min(ans, D[u] + H[u][v]);
        }
        rs[v] = ans == inf ? -1 : ans;
    }
    return rs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<vector<int>>());
    H.assign(N, vector<int>(N, inf));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a].push_back({ b, c });
        H[a][b] = min(H[a][b], c);
    }
    auto ans = solve();
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}