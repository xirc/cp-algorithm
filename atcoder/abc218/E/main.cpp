#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

struct DSU {
    vector<int> _leader;
    vector<int> _size;
    DSU(int n) {
        _leader = vector<int>(n, 0);
        for (int v = 0; v < n; ++v) _leader[v] = v;
        _size = vector<int>(n, 1);
    }
    int size(int v) {
        v = find(v);
        return _size[v];
    }
    int find(int v) {
        if (_leader[v] != v) {
            _leader[v] = find(_leader[v]);
        }
        return _leader[v];
    }
    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        _leader[u] = v;
        _size[v] += _size[u];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<array<int,3>> CAB(M, { 0, 0, 0 });
    for (int i = 0; i < M; ++i) {
        cin >> CAB[i][1] >> CAB[i][2] >> CAB[i][0];
        --CAB[i][1];
        --CAB[i][2];
    }

    ll ans = 0;
    DSU dsu(N);
    sort(CAB.begin(), CAB.end());
    for (int i = 0; i < M; ++i) {
        int c = CAB[i][0], a = CAB[i][1], b = CAB[i][2];
        if (!dsu.unite(a, b)) {
            ans += max(0, c);
        }
    }
    cout << ans << endl;

    return 0;
}