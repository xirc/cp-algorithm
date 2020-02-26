// https://www.spoj.com/problems/LCASQ/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct LCA {
    int N, L;
    vector<int> tin, tout;
    vector<vector<int>> up;
    LCA(vector<vector<int>>& adj) {
        N = adj.size();
        L = ceil(log2(N)) + 1;
        tin.assign(N, 0);
        tout.assign(N, 0);
        up.assign(N, vector<int>(L));
        int timer = 0;
        dfs(adj, 0, 0, timer);
    }
    void dfs(vector<vector<int>>& adj, int v, int p, int& timer) {
        tin[v] = timer++;
        up[v][0] = p;
        for (int i = 1; i < L; ++i) {
            int u = up[v][i-1];
            up[v][i] = up[u][i-1];
        }
        for (auto u : adj[v]) {
            if (u == p) continue;
            dfs(adj, u, v, timer);
        }
        tout[v] = timer++;
    }
    int is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int query(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[u][i], v)) continue;
            u = up[u][i];
        }
        return up[u][0];
    }
};

vector<vector<int>> adj;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    adj.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int u;
            cin >> u;
            adj[i].push_back(u);
            adj[u].push_back(i);
        }
    }

    LCA lca(adj);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }

    return 0;
}