#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

struct DSU {
    int N;
    vector<int> leader;
    vector<int> size;
    DSU(int N) {
        this->N = N;
        leader.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            leader[i] = i;
        }
        size.assign(N, 1);
    }
    int find(int u) {
        if (leader[u] != u) {
            leader[u] = find(leader[u]);
        }
        return leader[u];
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        leader[u] = v;
        int sz = size[v] + size[u];
        size[v] = size[u] = sz;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<array<int,3>> es;

    cin >> N;
    es.assign(N-1, { 0, 0, 0 });
    for (int i = 0; i < N - 1; ++i) {
        cin >> es[i][1] >> es[i][2] >> es[i][0];
        --es[i][1]; --es[i][2];
    }
    sort(es.begin(), es.end());

    DSU dsu(N);
    ll ans = 0;
    for (auto e : es) {
        int u = e[1], v = e[2], w = e[0];
        u = dsu.find(u);
        v = dsu.find(v);
        int su = dsu.size[u], sv = dsu.size[v];
        ans += ll(w) * su * sv;
        dsu.unite(u, v);
    }
    cout << ans << endl;

    return 0;
}