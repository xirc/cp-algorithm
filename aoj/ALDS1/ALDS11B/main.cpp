#include <bits/stdc++.h>

using namespace std;

vector<int> D;
vector<int> F;
vector<vector<int>> G;

int dfs(int v, int t) {
    if (D[v] > 0) return t;
    D[v] = ++t;
    for (auto u : G[v]) {
        if (D[u] > 0) continue;
        t = dfs(u, t);
    }
    F[v] = ++t;
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    G.assign(N, vector<int>());
    D.assign(N, 0);
    F.assign(N, 0);

    for (int i = 0; i < N; ++i) {
        int u, K, v;
        cin >> u >> K;
        for (int j = 0; j < K; ++j) {
            cin >> v;
            G[u-1].push_back(v-1);
        }
    }

    int t = 0;
    for (int v = 0; v < N; ++v) {
        t = dfs(v, t);
    }

    for (int v = 0; v < N; ++v) {
        cout << (v+1) << " " << D[v] << " " << F[v] << endl;
    }

    return 0;
}