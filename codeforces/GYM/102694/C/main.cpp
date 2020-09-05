#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

int M = 20;
vector<int> tin, tout;
vector<vector<int>> parents;
vector<vector<int>> edges;

int dfs(int u, int p, int timer) {
    tin[u] = ++timer;
    parents[u][0] = p;
    edges[u][0] = 1;
    for (int e = 1; e < M; ++e) {
        int ancestor = parents[u][e-1];
        parents[u][e] = parents[ancestor][e-1];
        edges[u][e] = edges[u][e-1] + edges[ancestor][e-1];
    }
    for (int v : G[u]) {
        if (v == p) continue;
        timer = dfs(v, u, timer);
    }
    tout[u] = ++timer;
    return timer;
}

bool is_ancestor(int u, int p) {
    return (tin[p] <= tin[u] && tout[u] <= tout[p]);
}

int ancestor(int u, int move) {
    for (int e = M - 1; e >= 0; e--) {
        int n = 1 << e;
        if (n <= move) {
            move -= n;
            u = parents[u][e];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (u == v) return u;
    for (int e = M - 1; e >= 0; e--) {
        if (!is_ancestor(v, parents[u][e])) {
            u = parents[u][e];
        }
        if (!is_ancestor(u, parents[v][e])) {
            v = parents[v][e];
        }
    }
    return parents[u][0];
}

int edge_count(int u, int v) {
    if (u == v) return 0;
    int ans = 0;
    for (int e = M - 1; e >= 0; e--) {
        if (!is_ancestor(v, parents[u][e])) {
            ans += edges[u][e];
            u = parents[u][e];
        }
        if (!is_ancestor(u, parents[v][e])) {
            ans += edges[v][e]; 
            v = parents[v][e];
        }
    }
    if (parents[u][0] == v) {
        return ans + 1;
    } else if (parents[v][0] == u) {
        return ans + 1;
    } else {
        return ans + 2;
    }
}

void build() {
    tin.assign(N, 0);
    tout.assign(N, 0);
    parents.assign(N, vector<int>(M, -1));
    edges.assign(N, vector<int>(M, 0));
    dfs(0, 0, 0);
}

int query(int from, int to, int energy) {
    int ec = edge_count(from, to);
    if (ec <= energy) {
        return to;
    }
    int subroot = lca(from, to);
    int ecf = edge_count(from, subroot);
    if (energy <= ecf) {
        return ancestor(from, energy);
    }
    return ancestor(to, ec - energy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    build();

    int Q;
    int u, v, c;

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> u >> v >> c;
        --u, --v;
        cout << query(u, v, c) + 1 << endl;
    }

    return 0;
}