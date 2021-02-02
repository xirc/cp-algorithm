#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int const inf = 1e8;
int N, M;
vector<vector<vector<int>>> G;

int solve(int s) {
    vector<bool> done(N, false);
    vector<int> D(N, inf);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
    Q.push({ 0, s });
    D[s] = 0;
    while (Q.size()) {
        auto e = Q.top(); Q.pop();
        int v = e[1], w = e[0];
        if (done[v]) continue;
        done[v] = true;
        for (auto const& uw : G[v]) {
            int u = uw[0], dw = uw[1];
            if (w + dw >= D[u]) continue;
            D[u] = w + dw;
            Q.push({ D[u], u });
        }
    }
    int ans = 0;
    for (int u = 0; u < N; ++u) {
        ans = max(ans, D[u]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<vector<int>>());
    for (int i = 0; i < M; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a, --b;
        G[a].push_back({ b, t });
        G[b].push_back({ a, t });
    }

    int ans = inf;
    for (int v = 0; v < N; ++v) {
        int w = solve(v);
        ans = min(ans, w);
    }
    cout << ans << endl;

    return 0;
}