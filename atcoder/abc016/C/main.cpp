#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<vector<int>> G;

    cin >> N >> M;
    G.assign(N, vector<int>(N, 1e8));
    for (int i = 0; i < N; ++i) G[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a][b] = G[b][a] = 1;
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        int ans = 0;
        for (int j = 0; j < N; ++j) {
            if (j != i && G[i][j] == 2) ++ans;
        }
        cout << ans << endl;
    }

    return 0;
}