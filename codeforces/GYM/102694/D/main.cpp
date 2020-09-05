#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> G;

const int inf = numeric_limits<int>::max();
const int L = 30;
vector<int> tin, tout;
vector<vector<int>> parents;
vector<vector<int>> maxflows;

int dfs(int u, int p, int w, int timer) {
    tin[u] = ++timer;
    parents[u][0] = p;
    maxflows[u][0] = w;
    for (int exp = 1; exp < L; ++exp) {
        int ancestor = parents[u][exp-1];
        parents[u][exp] = parents[ancestor][exp-1];
        maxflows[u][exp] = min(maxflows[u][exp-1], maxflows[ancestor][exp-1]);
    }
    for (auto e : G[u]) {
        int v = e.first, c = e.second;
        if (v == p) continue;
        timer = dfs(v, u, c, timer);
    }
    tout[u] = ++timer;
    return timer;
}

bool is_ancestor(int u, int p) {
    return (tin[p] <= tin[u] && tout[u] <= tout[p]);
}

void build() {
    tin.assign(N, 0);
    tout.assign(N, 0);
    parents.assign(N, vector<int>(L, -1));
    maxflows.assign(N, vector<int>(L, inf));
    dfs(0, 0, inf, 0);
}

int query(int u, int v) {
    int maxflow = inf;
    for (int exp = L - 1; exp >= 0; --exp) {
        if (!is_ancestor(u, parents[v][exp])) {
            maxflow = min(maxflow, maxflows[v][exp]);
            v = parents[v][exp];
        }
        if (!is_ancestor(v, parents[u][exp])) {
            maxflow = min(maxflow, maxflows[u][exp]);
            u = parents[u][exp];
        }
    }
    if (u == parents[v][0]) {
        return min(maxflow, maxflows[v][0]);
    } else if (v == parents[u][0]) {
        return min(maxflow, maxflows[u][0]);
    } else {
        return min({ maxflow, maxflows[u][0], maxflows[v][0] });
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<pair<int,int>>());
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
    }

    build();

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << query(u, v) << endl;
    }

    return 0;
}