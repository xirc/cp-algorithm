#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DSU
{
    vector<int> nodes;
    DSU(int n) {
        nodes.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            nodes[i] = i;
        }
    }
    int find(int v) {
        if (v == nodes[v]) {
            return v;
        }
        return nodes[v] = find(nodes[v]);
    }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        nodes[u] = v;
    }
};

int N;
vector<vector<int>> P;

ll solve() {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;

    sort(P.begin(), P.end(), [](auto const& lhs, auto const& rhs) {
        // x-axis
        return lhs[0] < rhs[0];
    });
    for (int i = 0; i + 1 < N; ++i) {
        int x1 = P[i][0], x2 = P[i+1][0];
        int i1 = P[i][2], i2 = P[i+1][2];
        Q.push({ (x2 - x1), i1, i2 });
    }
    sort(P.begin(), P.end(), [](auto const& lhs, auto const& rhs) {
        // y-axis
        return lhs[1] < rhs[1];
    });
    for (int i = 0; i + 1 < N; ++i) {
        int y1 = P[i][1], y2 = P[i+1][1];
        int i1 = P[i][2], i2 = P[i+1][2];
        Q.push({ (y2 - y1), i1, i2 });
    }

    ll cost =0;
    int count_path = 0;
    DSU dsu(N);
    while (count_path < N - 1) {
        auto e = Q.top(); Q.pop();
        int c = e[0], u = e[1], v = e[2];
        if (dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u, v);
        cost += c;
        ++count_path;
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    P.assign(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        cin >> P[i][0] >> P[i][1];
        P[i][2] = i;
    }
    cout << solve() << endl;

    return 0;
}