#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge { int to; int w; };
int N, K;
vector<vector<edge>> G;

vector<ll> ds;
void dfs(int v, int p) {
    for (auto const& e : G[v]) {
        if (e.to == p) continue;
        ds[e.to] = ds[v] + e.w;
        dfs(e.to, v);
    }
}

void build() {
    ds.assign(N, 0);
    dfs(K, K);
}

ll query(int x, int y) { 
    return ds[x] + ds[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<edge>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        G[a].push_back({ b, c });
        G[b].push_back({ a, c });
    }

    int Q;
    cin >> Q >> K;
    --K;
    build();
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << query(x, y) << endl;
    }

    return 0;
}