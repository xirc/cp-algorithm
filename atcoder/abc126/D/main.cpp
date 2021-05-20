#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<array<int,2>>> G;

vector<int> solve() {
    vector<int> color(N, 0);
    function<void(int,int,ll)> traverse = [&](int v, int p, ll w) {
        if ((w & 1) == 0) {
            color[v] = 1;
        }
        for (auto u : G[v]) {
            if (u[0] == p) continue;
            traverse(u[0], v, w + u[1]);
        }
    };
    traverse(0, 0, 0);
    return color;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<array<int,2>>());
    int u, v, w;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> w;
        --u, --v;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
    }
    auto ans = solve();
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}