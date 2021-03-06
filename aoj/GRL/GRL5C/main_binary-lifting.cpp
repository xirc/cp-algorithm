// https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C

#include <bits/stdc++.h>


class LCA {
private:
    size_t N, L;
    std::vector<size_t> tin, tout;
    std::vector<std::vector<size_t>> up;

public:
    // root = [0,N)
    // Time: O(N logN)
    LCA(
        std::vector<std::vector<size_t>> const& adj = {},
        size_t const root = 0
    )
    {
        build(adj, root);
    }
    // root = [0,N)
    // O(N logN)
    void build(
        std::vector<std::vector<size_t>> const& adj,
        size_t const root = 0
    )
    {
        N = adj.size();
        L = std::ceil(std::log2(std::max(size_t(1),N))) + 1;

        tin.assign(N, 2 * N);
        tout.assign(N, 2 * N);
        up.assign(N, std::vector<size_t>(L, 0));

        if (N > 0) {
            size_t timer = 0;
            if (root >= N) throw std::out_of_range("root");
            dfs_euler(adj, root, root, timer);
        }
    }
    // A LCA node of both the node 'u' and the node 'v'
    // Time: O(logN)
    size_t query(size_t u, size_t v) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");

        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (size_t i = 0; i < L; ++i) {
            if (is_ancestor(up[u][L-1-i], v)) continue;
            u = up[u][L-1-i];
        }
        return up[u][0];
    }
    // A highest ancestor node of the node 'u'
    // where the ancestor is not an ancestor of the node 'v'.
    // If 'u' is an ancestor of 'v', return 'N'.
    // Time: O(logN)
    size_t upper_bound(size_t u, size_t const v) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");

        if (is_ancestor(u, v)) return N;
        for (size_t i = 0; i < L; ++i) {
            if (is_ancestor(up[u][L-1-i], v)) continue;
            u = up[u][L-1-i];
        }
        return u;
    }
    // True if the node 'u' is an ancestor of the node 'v'
    // u = [0,N), v = [0,N)
    // Time: O(1)
    bool is_ancestor(size_t const u, size_t const v) const {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    // The In Index of the Euler Tour
    // u = [0,N)
    // The In Index = [0,2*N)
    size_t euler_in(size_t const u) const {
        if (u >= N) throw std::out_of_range("u");
        return tin[u];
    }
    // The Out Index of the Euler Tour
    // u = [0,N)
    // The Out Index = [0, 2*N)
    size_t euler_out(size_t const u) const {
        if (u >= N) throw std::out_of_range("u");
        return tout[u];
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }

private:
    // Time: O(N logN)
    void dfs_euler(std::vector<std::vector<size_t>> const& adj, size_t v, size_t p, size_t& timer) {
        tin[v] = timer++;
        up[v][0] = p;
        for (size_t i = 1; i < L; ++i) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (auto const& u : adj[v]) {
            if (u == p) continue;
            dfs_euler(adj, u, v, timer);
        }
        tout[v] = timer++;
    }
};


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, Q;
    vector<vector<size_t>> adj;

    cin >> N;
    adj.assign(N, vector<size_t>());
    for (int i = 0; i < N; ++i) {
        int K, c;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> c;
            adj[i].push_back(c);
            adj[c].push_back(i);
        }
    }

    LCA solver(adj);

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << solver.query(u, v) << endl;
    }

    return 0;
}