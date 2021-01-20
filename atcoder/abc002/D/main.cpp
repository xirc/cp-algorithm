#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<vector<bool>> G;

int solve() {
    int ans = 0;
    int K = 1 << N;
    for (int s = 0; s < K; ++s) {
        vector<int> ps;
        for (int i = 0; i < N; ++i) {
            if ((s >> i) & 1) {
                ps.push_back(i);
            }
        }
        bool pass = true;
        for (auto u : ps) {
            for (auto v : ps) {
                if (!G[u][v]) {
                    pass = false;
                    break;
                }
            }
        }
        if (pass) {
            ans = max(ans, (int)ps.size());
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; ++i) G[i][i] = true;
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x][y] = G[y][x] = true;
    }
    cout << solve() << endl;

    return 0;
}