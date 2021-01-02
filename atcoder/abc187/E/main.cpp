#include <bits/stdc++.h>

class LCA {
public:
    int N, L;
    int root;
    std::vector<int> tin, tout;
    std::vector<std::vector<int>> up;

    // O(N logN)
    LCA(const std::vector<std::vector<int>>& adj = {}, int root = 0): root(root) {
        build(adj, root);
    }
    // O(N logN)
    void build(const std::vector<std::vector<int>>& adj, int root = 0) {
        N = adj.size();
        tin.assign(N, 0);
        tout.assign(N, 0);
        L = std::ceil(std::log2(std::max(1,N))) + 1;
        up.assign(N, std::vector<int>(L, 0));
        if (N > 0) {
            int timer = 0;
            dfs(adj, root, root, timer);
        }
    }
    // O(logN)
    int upper_bound(int  u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);

        if (!is_ancestor(u, v)) {
            return 0;
        }
        for (int i = L - 1; i >= 0; --i) {
            if (is_ancestor(up[v][i], u)) continue;
            v = up[v][i];
        }
        return v;
    }
    // O(1)
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

private:
    // O(N logN)
    void dfs(const std::vector<std::vector<int>>& adj, int v, int p, int &timer) {
        tin[v] = timer++;
        up[v][0] = p;
        for (int i = 1; i < L; ++i) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (int u : adj[v]) {
            if (u == p) continue;
            dfs(adj, u, v, timer);
        }
        tout[v] = timer++;
    }
    void throw_if_invalid_index(int index){ 
        if (index < 0 || index >= N) throw "index out of range";
    }
};


using namespace std;
using ll = long long;


int N;
vector<int> A, B;

LCA lca;
vector<ll> M;

void build() {
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a = A[i], b = B[i];
        G[a].push_back(b);
        G[b].push_back(a);
    }
    lca = LCA(G, 0);
    M.assign(2 * N, 0);
}

void update(int a, int b, int x) {
    if (lca.is_ancestor(b, a)) {
        int c = lca.upper_bound(b, a);
        M[lca.tin[c]] += x;
        M[lca.tout[c]] -= x;
    } else {
        M[lca.tin[0]] += x;
        M[lca.tout[0]] -= x;
        M[lca.tin[b]] -= x;
        M[lca.tout[b]] += x;
    }
}

vector<ll> finalize() {
    for (int i = 1; i < 2 * N; ++i) {
        M[i] += M[i-1];
    }
    vector<ll> cs;
    for (int i = 0; i < N; ++i) {
        cs.push_back(M[lca.tin[i]]);
    }
    return cs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N - 1, 0);
    B.assign(N - 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        cin >> A[i] >> B[i];
        --A[i], --B[i]; // 0-indexed
    }
    build();

    int Q;
    int t, e, x;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> t >> e >> x;
        --e;
        if (t == 1) {
            int a = A[e], b = B[e];
            update(a, b, x);
        } else if (t == 2) {
            int a = A[e], b = B[e];
            update(b, a, x);
        } else throw;
    }

    auto cs = finalize();
    for (int i = 0; i < N; ++i) {
        cout << cs[i] << endl;
    }

    return 0;
}