#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

struct edge { int from, to, coin; };
int N, M, P;
vector<edge> edges;

vector<vector<int>> G;
vector<vector<int>> H;
vector<bool> from;
vector<bool> to;

void dfs_from(int v) {
    if (from[v]) return;
    from[v] = true;
    for (auto u :G[v]) {
        dfs_from(u);
    }
}

void dfs_to(int v) {
    if (to[v]) return;
    to[v] = true;
    for (auto u : H[v]) {
        dfs_to(u);
    }
}

ll solve() {
    int const S = 0;
    int const T = N - 1;

    G.assign(N, vector<int>());
    H.assign(N, vector<int>());
    to.assign(N, false);
    from.assign(N, false);
    for (auto const& e : edges) {
        G[e.from].push_back(e.to);
        H[e.to].push_back(e.from);
    }
    dfs_from(S);
    dfs_to(T);

    ll const inf = 1e18;
    vector<ll> D(N, -inf);
    bool any_update = false;
    D[S] = 0;
    for (int i = 0; i < N; ++i) {
        any_update = false;
        for (auto const& e : edges) {
            if (!from[e.from] || !from[e.to]) continue;
            if (!to[e.from] || !to[e.to]) continue;
            if (D[e.from] == -inf) continue;
            if (D[e.to] < D[e.from] + e.coin) {
                D[e.to] = max(-inf, D[e.from] + e.coin);
                any_update = true;
            }
        }
        if (!any_update) break;
    }
    if (any_update || D[T] == -inf) {
        return -1;
    }
    return max(ll(0), D[T]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> P;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        edges.push_back({ a, b, c - P });
    }
    cout << solve() << endl;

    return 0;
}