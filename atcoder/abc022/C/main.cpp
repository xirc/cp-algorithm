#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int const inf = 1e8;
int N, M;
vector<vector<int>> G;

ll solve() {
    vector<int> T(N, inf);
    for (int v = 0; v < N; ++v) {
        T[v] = G[0][v];
        G[0][v] = inf;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int ans = inf;
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ans = min(ans, T[i] + G[i][j] + T[j]);
        }
    }

    return ans == inf ? -1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>(N, inf));
    for (int i = 0; i < N; ++i) G[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        --u, --v;
        G[u][v] = G[v][u] = l;
    }
    cout << solve() << endl;

    return 0;
}