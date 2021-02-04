#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<vector<bool>> G;

    cin >> N >> M;
    G.assign(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a][b] = G[b][a] = true;
    }

    vector<int> T(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            bool pass = false;
            for (int k = 0; k < N; ++k) {
                if (i == k || j == k) continue;
                if (G[i][j]) continue;
                if (G[i][k] && G[k][j]) {
                    pass = true;
                    break;
                }
            }
            if (pass) {
                T[i]++;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << T[i] << endl;
    }

    return 0;
}