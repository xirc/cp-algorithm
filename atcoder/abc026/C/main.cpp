#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<int> P;

vector<vector<int>> G;

int dfs(int v, int p) {
    int c = 0;
    int mini = 1, maxi = 1;
    for (int u : G[v]) {
        if (u == p) continue;
        int s = dfs(u, v);
        if (c > 0) {
            mini = min(mini, s);
            maxi = max(maxi, s);
        } else {
            mini = maxi = s;
        }
        ++c;
    }
    if (c == 0) return 1;
    return mini + maxi + 1;
}

int solve() {
    G.assign(N, vector<int>());
    for (int v = 1; v < N; ++v) {
        int p = P[v];
        G[v].push_back(p);
        G[p].push_back(v);
    }
    return dfs(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    P.assign(N, 0);
    for (int i = 1; i < N; ++i) {
        cin >> P[i];
        --P[i];
    }
    cout << solve() << endl;

    return 0;
}