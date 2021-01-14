#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int inf = 1e7;
int N, M;
vector<vector<int>> G;
vector<vector<int>> P;
vector<vector<bool>> U;

void fill(int i, int j) {
    if (P[i][j] == N) {
        U[j][j] = U[i][j] = true;
        return;
    }
    int k = P[i][j];
    fill(i, k);
    fill(k, j);
}

int solve() {
    P.assign(N, vector<int>(N, N));
    U.assign(N, vector<bool>(N, false));

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] == inf || G[k][j] == inf) continue;
                if (G[i][k] + G[k][j] < G[i][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                    P[i][j] = k;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fill(i, j);
        }
    }

    int e = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j && U[i][j]) ++e;
        }
    }
    return M - (e / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>(N, inf));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a][b] = G[b][a] = c;
    }
    cout << solve() << endl;

    return 0;
}