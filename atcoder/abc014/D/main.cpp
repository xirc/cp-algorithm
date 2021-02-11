#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<vector<int>> G;

int L;
vector<int> tin, tout;
vector<int> H;
vector<vector<int>> up;

void dfs(int v, int p, int h, int& t) {
    tin[v] = t++;
    H[v] = h;
    up[v][0] = p;
    for (int i = 1; i < L; ++i) {
        int u = up[v][i-1];
        up[v][i] = up[u][i-1];
    }
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(u, v, h + 1, t);
    }
    tout[v] = t++;
}

void build() {
    L = ceil(log2(N)) + 1;

    tin.assign(N, 2*N);
    tout.assign(N, 2*N);
    H.assign(N, 0);
    up.assign(N, vector<int>(L, 0));

    int t = 0;
    dfs(0, 0, 0, t);
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = L - 1; i >= 0; --i) {
        if (is_ancestor(up[u][i], v)) continue;
        u = up[u][i];
    }
    return up[u][0];
}

int query(int x, int y) {
    int u = lca(x, y);
    return H[x] - H[u] + H[y] - H[u] + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    build();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << query(a, b) << endl;
    }

    return 0;
}