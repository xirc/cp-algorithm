#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<int>> G;
vector<ll> vs;

void dfs(int v, int p, ll x) {
    vs[v] += x;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v, vs[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> N >> Q;
    G.assign(N, vector<int>());
    vs.assign(N, 0);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 0; i < Q; ++i) {
        int p, x;
        cin >> p >> x;
        --p;
        vs[p] += x;
    }

    dfs(0, 0, 0);
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << vs[i];
    }
    cout << endl;

    return 0;
}