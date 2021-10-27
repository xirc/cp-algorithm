#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> C;
vector<vector<int>> G;

void dfs(int v, int p, vector<int> &colors, vector<int>& goods) {
    if (colors[C[v]] == 0) {
        goods.push_back(v);
    }
    colors[C[v]]++;
    for (auto u : G[v]) {
        if (u == p) continue;
        dfs(u, v, colors, goods);
    }
    colors[C[v]]--;
}

vector<int> solve() {
    int const M = 100000;
    vector<int> colors(M, 0);
    vector<int> goods;
    dfs(0, 0, colors, goods);
    sort(goods.begin(), goods.end());
    return goods;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    C.assign(N, 0);
    G.assign(N, {});
    for (auto &ci : C) {
        cin >> ci;
        --ci;
    }
    for (int i = 0; i < N - 1; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    auto goods = solve();
    for (auto v : goods) {
        cout << (v+1) << endl;
    }

    return 0;
}