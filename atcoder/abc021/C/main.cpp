#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll const inf = 1e16;
ll const MOD = 1e9 + 7;
int N, M;
int a, b;
vector<vector<ll>> G;
vector<vector<ll>> C;

ll solve() {
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (G[i][k] == inf) continue;
                if (G[k][j] == inf) continue;
                int w = G[i][k] + G[k][j];
                ll c = C[i][k] * C[k][j] % MOD;
                if (G[i][j] > w) {
                    G[i][j] = w;
                    C[i][j] = c;
                } else if (G[i][j] == w) {
                    C[i][j] = (C[i][j] + c) % MOD;
                }
            }
        }
    }
    return C[a][b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> a >> b;
    --a, --b;
    cin >> M;
    G.assign(N, vector<ll>(N, inf));
    C.assign(N, vector<ll>(N, 0));
    for (int i = 0; i < N; ++i) {
        G[i][i] = 0;
        C[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x][y] = G[y][x] = 1;
        C[x][y] = C[y][x] = 1;
    }
    cout << solve() << endl;

    return 0;
}