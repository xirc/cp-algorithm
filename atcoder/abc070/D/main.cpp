#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct edge { int to; int w; };
int N, K;
vector<vector<edge>> G;

vector<bool> done;
vector<ll> ds;
void dfs(int v) {
    if (done[v]) return;
    done[v] = true;
    for (auto const& e : G[v]) {
        ds[e.to] = min(ds[e.to], ds[v] + e.w);
        if (!done[e.to]) dfs(e.to);
    }
}

void build() {
    const ll inf = numeric_limits<ll>::max() / 2;
    done.assign(N, false);
    ds.assign(N, inf);
    ds[K] = 0;
    dfs(K);
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