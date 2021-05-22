#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> X, Y, Z;

//
vector<vector<int>> G;
vector<bool> done;

void dfs(int v, int p) {
    if (done[v]) return;
    done[v] = true;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
}

int solve() {
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        G[X[i]].push_back(Y[i]);
        G[Y[i]].push_back(X[i]);
    }
    done.assign(N, false);

    int ans = 0;
    for (int v = 0; v < N; ++v) {
        if (done[v]) continue;
        dfs(v, v);
        ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    X.assign(M, 0);
    Y.assign(M, 0);
    Z.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
        --X[i], --Y[i];
    }
    cout << solve() << endl;

    return 0;
}