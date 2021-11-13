#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int const inf = 1e9;
int N, M;
vector<vector<int>> G;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>(N, inf));
    for (int i = 0; i < N; ++i) {
        G[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        --A, --B;
        G[A][B] = C;
    }

    ll ans = 0;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                if (G[i][j] < inf) {
                    ans += G[i][j];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}