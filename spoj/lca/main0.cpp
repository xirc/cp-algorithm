// https://www.spoj.com/problems/LCA/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> adj;

static const int inf = 1e6;

struct LCA {
    int N, M;
    vector<int> first, height, euler, segtree;

    LCA(vector<vector<int>>& adj) {
        N = adj.size();
        first.assign(N, 0);
        height.assign(N, 0);
        euler.reserve(2 * N);
        dfs_euler(0);

        M = euler.size();
        segtree.assign(4 * M, inf);
        build_segtree(0, 0, M);
    }
    int query(int u, int v) {
        int l = first[u], r = first[v];
        if (l > r) swap(l, r);
        return query_segtree(0, 0, M, l, r + 1);
    }
    void dfs_euler(int v, int p = -1, int h = 0) {
        euler.push_back(v);
        first[v] = euler.size() - 1;
        height[v] = h;
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs_euler(u, v, h + 1);
            euler.push_back(v);
        }
    }
    static constexpr int left(int v) { return 2 * v + 1; }
    static constexpr int right(int v) { return 2 * v + 2; }
    void build_segtree(int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            segtree[v] = euler[tl];
        } else {
            const int tm = (tl + tr) / 2;
            build_segtree(left(v), tl, tm);
            build_segtree(right(v), tm, tr);
            segtree[v] = min(segtree[left(v)], segtree[right(v)]);
        }
    }
    // [l,r) exclusive
    int query_segtree(int v, int tl, int tr, int l, int r) {
        if (tr - tl <= 0 || r - l <= 0) {
            return inf;
        }
        if (tl == l && tr == r) {
            return segtree[v];
        }
        const int tm = (tl + tr) / 2;
        const int lhs = query_segtree(left(v), tl, tm, l, min(r, tm));
        const int rhs = query_segtree(right(v), tm, tr, max(l,tm), r);
        return min(lhs, rhs);
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