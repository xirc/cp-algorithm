#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e7;
int N, M;
vector<vector<int>> G;
vector<vector<int>> O;

int solve() {
    // COPY
    O = G;

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] == inf || G[k][j] == inf) continue;
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (i == j || O[i][j] == inf) continue;
            bool use = false;
            for (int s = 0; s < N; ++s) {
                if (G[s][i] + O[i][j] == G[s][j]) use = true;
            }
            if (!use) ++ans;
        }
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
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a][b] = G[b][a] = c;
    }
    cout << solve() << endl;

    return 0;
}