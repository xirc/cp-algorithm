#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<int>> G;
vector<int> color;

void dfs(int v, int p) {
    color[v] = !color[p];
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

void build() {
    color.assign(N, 0);
    dfs(0, 0);
}

bool query(int u, int v) {
    return color[u] == color[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> Q;
    G.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    build();

    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        auto same = query(u, v);
        auto ans = same ? "Town" : "Road";
        cout << ans << endl;
    }

    return 0;
}