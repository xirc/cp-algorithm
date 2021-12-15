#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<int>> G;

vector<int> parent;
vector<int> num_nodes;

ll dfs(int v, int p) {
    ll edges = 0;
    parent[v] = p;
    num_nodes[v] = 1;
    for (auto u : G[v]) {
        if (u == p) continue;
        edges += dfs(u, v);
        edges += num_nodes[u];
        num_nodes[v] += num_nodes[u];
    }
    return edges;
}

vector<ll> num_edges;
ll solve(int v) {
    if (num_edges[v] > 0) {
        return num_edges[v];
    }
    int p = parent[v];
    ll edges = solve(p);
    edges += N - num_nodes[v];
    edges -= num_nodes[v];
    return num_edges[v] = edges;
}

vector<ll> solve() {
    parent.assign(N, 0);
    num_nodes.assign(N, 0);
    num_edges.assign(N, 0);

    num_edges[0] = dfs(0, 0);
    vector<ll> edges(N, 0);
    for (int v = 0; v < N; ++v) {
        edges[v] = solve(v);
    }
    return edges;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, {});
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto ans = solve();
    for (auto e : ans) {
        cout << e << endl;
    }

    return 0;
}