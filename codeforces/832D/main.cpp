// https://codeforces.com/contest/832/problem/D

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct LCA
{
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
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs(adj, u, v, timer);
        }
        tout[v] = timer++;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int query_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[u][i], v)) continue;
            u = up[u][i];
        }
        return up[u][0];
    }
    int height(int u, int v) {
        if (!is_ancestor(u, v) || u == v) return 0;
        int h = 0;
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[v][i], u)) continue;
            v = up[v][i];
            h += 1 << i;
        }
        return h + 1;
    }
    int query(int s, int f, int t) {
        int ans = 0;
        int sf = query_lca(s, f);
        int tf = query_lca(t, f);
        if (sf == tf) {
            int st = query_lca(s, t);
            int stf = query_lca(st, f);
            ans = height(stf,st) + height(stf,f) + 1;
        } else if (is_ancestor(sf,tf)) {
            ans = height(tf,f) + 1;
        } else {
            ans = height(sf,f) + 1;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> adj(N);
    for (int i = 1; i < N; ++i) {
        int j;
        cin >> j;
        --j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    LCA lca(adj);
    for (int i = 0; i < Q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b, -- c;
        int ans = 0;
        ans = max(ans, lca.query(a, b, c));
        ans = max(ans, lca.query(a, c, b));
        ans = max(ans, lca.query(b, a, c));
        ans = max(ans, lca.query(b, c, a));
        ans = max(ans, lca.query(c, a, b));
        ans = max(ans, lca.query(c, b, a));
        cout << ans << endl;
    }

    return 0;
}