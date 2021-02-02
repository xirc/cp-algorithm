#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int const inf = 1e8;
int N, M;
vector<vector<int>> G;

int solve() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < N; ++i) {
        int w = 0;
        for (int j = 0; j < N; ++j) {
            w = max(w, G[i][j]);
        }
        ans = min(ans, w);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>(N, inf));
    for (int i = 0; i < N; ++i) G[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a, --b;
        G[a][b] = G[b][a] = t;
    }
    cout << solve() << endl;

    return 0;
}