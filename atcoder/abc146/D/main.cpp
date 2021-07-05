#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

using edge = array<int,2>;

int N;
vector<vector<edge>> edges;

set<int> colors;
vector<int> nodeToColor;

void dfs(int v, int p) {
    set<int> as;
    for (auto const& e : edges[v]) {
        if (nodeToColor[e[1]] == 0) continue;
        as.insert(nodeToColor[e[1]]);
    }
    int c = 1;
    for (auto const& e : edges[v]) {
        if (nodeToColor[e[1]] != 0) continue;
        while (as.count(c) != 0) ++c;
        nodeToColor[e[1]] = c;
        as.insert(c);
    }
    for (auto const& e : edges[v]) {
        int u = e[0];
        if (u == p) continue;
        dfs(u, v);
    }
}

void solve() {
    nodeToColor.assign(N - 1, 0);
    dfs(0, 0);
    colors.clear();
    for (auto c : nodeToColor) {
        colors.insert(c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    edges.assign(N, vector<edge>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        edges[a].push_back({ b, i });
        edges[b].push_back({ a, i });
    }
    solve();
    cout << colors.size() << endl;
    for (int i = 0; i < N - 1; ++i) {
        cout << nodeToColor[i] << endl;
    }

    return 0;
}