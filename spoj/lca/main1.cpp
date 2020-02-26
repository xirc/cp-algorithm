// https://www.spoj.com/problems/LCA/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


vector<vector<int>> adj;

struct LCA {
    int N, L;
    vector<int> tin, tout;
    vector<vector<int>> up;

    LCA(vector<vector<int>> adj) {
        N = adj.size();
        tin.assign(N, 0);
        tout.assign(N, 0);
        L = ceil(log2(N)) + 1;
        up.assign(N, vector<int>(L, 0));
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
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs(adj, u, v, timer);
        }
        tout[v] = timer++;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int query(int u, int v) {
        if (is_ancestor(u, v)) {
            return u;
        }
        if (is_ancestor(v, u)) {
            return v;
        }
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[u][i], v)) continue;
            u = up[u][i];
        }
        return up[u][0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, Q;
        cin >> N;
        adj.assign(N, vector<int>(0));
        for (int v = 0; v < N; ++v) {
            int M, u;
            cin >> M;
            for (int j = 0; j < M; ++j) {
                cin >> u;
                --u;
                adj[v].push_back(u);
                adj[u].push_back(v);
            }
        }

        LCA lca(adj);
        cout << "Case " << (t +1) << ":" << endl;
        cin >> Q;
        for (int i = 0; i < Q; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            cout << lca.query(u, v) + 1 << endl;
        }
    }

    return 0;
}