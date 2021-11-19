#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<int>> G;

void dfs(int v, int p) {
    cout << (v+1);
    for (int u : G[v]) {
        if (u == p) continue;
        cout << " ";
        dfs(u, v);
        cout << " " << (v+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, {});
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int v = 0; v < N; ++v) {
        sort(G[v].begin(), G[v].end());
    }

    dfs(0, 0);
    cout << endl;

    return 0;
}