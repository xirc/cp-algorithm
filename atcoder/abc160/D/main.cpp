#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<int> bfs(vector<vector<int>> const& G, int s) {
    int N = G.size();
    vector<int> D(N, N);
    vector<bool> done(N, false);
    queue<int> Q;
    Q.push(s);
    D[s] = 0;
    while (Q.size()) {
        auto v = Q.front(); Q.pop();
        if (done[v]) continue;
        done[v] = true;
        for (auto u : G[v]) {
            if (done[u]) continue;
            if (D[u] <= D[v] + 1) continue;
            D[u] = D[v] + 1;
            Q.push(u);
        }
    }
    return D;
}

vector<int> solve(int N, int X, int Y) {
    vector<vector<int>> G(N);
    for (int i = 0; i + 1 < N; ++i) {
        G[i].push_back(i + 1);
        G[i+1].push_back(i);
    }
    G[X].push_back(Y);
    G[Y].push_back(X);

    vector<int> ans(N - 1, 0);
    for (int v = 0; v < N; ++v) {
        auto D = bfs(G, v);
        for (int u = 0; u < N; ++u) {
            if (u == v) continue;
            ans[D[u]-1]++;
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        ans[i] /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, X, Y;
    cin >> N >> X >> Y;
    --X, --Y;
    auto ans = solve(N, X, Y);
    for (auto p : ans) {
        cout << p << endl;
    }

    return 0;
}