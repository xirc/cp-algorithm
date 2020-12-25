#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max();
int N, M, R;
vector<int> rs;
vector<vector<int>> G;

int solve() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][k] < inf && G[k][j] < inf) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
    }

    int ans = inf;
    sort(rs.begin(), rs.end());
    do {
        int dist = 0;
        for (int i = 0; i + 1 < R; ++i) {
            int u = rs[i], v = rs[i+1];
            dist += G[u][v];
        }
        ans = min(ans, dist);
    } while (next_permutation(rs.begin(), rs.end()));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> R;
    rs.assign(R, 0);
    for (int i = 0; i < R; ++i) {
        cin >> rs[i];
        --rs[i];
    }
    G.assign(N, vector<int>(N, inf));
    for (int i = 0; i < N; ++i) {
        G[i][i] = 0;
    }
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a][b] = G[b][a] = c;
    }
    cout << solve() << endl;

    return 0;
}