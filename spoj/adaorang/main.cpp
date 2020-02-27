// https://www.spoj.com/problems/ADAORANG/

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

struct Solver {
    int N, L;
    vector<int> tval, tin, tout;
    vector<vector<int>> up;
    vector<bitset<250>> set;

    Solver(vector<int>& ary, vector<vector<int>>& adj, int root) {
        N = ary.size();
        L = ceil(log2(N)) + 1;
        tval = ary;
        tin.assign(N, 0);
        tout.assign(N, 0);
        up.assign(N, vector<int>(L, 0));
        set.assign(N, bitset<250>());
        int timer = 0;
        dfs(adj, root, root, timer);
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
            set[v] |= set[u];
        }
        set[v].set(tval[v]-1);
        tout[v] = timer++;
    }
    inline bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u,v)) return u;
        if (is_ancestor(v,u)) return v;
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[u][i], v)) continue;
            u = up[u][i];
        }
        return up[u][0];
    }
    int query(int u, int v) {
        return set[lca(u,v)].count();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, Q, R;
        cin >> N >> Q >> R;
        vector<int> value(N);
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            cin >> value[i];
        }
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solver solver(value, adj, R);
        for (int i = 0; i < Q; ++i) {
            int u, v;
            cin >> u >> v;
            cout << solver.query(u, v) << endl;
        }
    }

    return 0;
}