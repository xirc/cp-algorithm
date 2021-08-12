#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, U, V;
vector<vector<int>> G;

void dfs(vector<int>& D, int v, int p) {
    if (v != p) {
        D[v] = D[p] + 1;
    }
    for (int u : G[v]) {
        if (u == p) continue;
        dfs(D, u, v);
    }
}

int solve() {
    vector<int> DU(N, N), DV(N, N);
    DU[U] = 0;
    DV[V] = 0;
    dfs(DU, U, U);
    dfs(DV, V, V);

    int ans = 0;
    for (int m = 0; m < N; ++m) {
        int vm = DV[m];
        int um = DU[m];
        int d = vm - um;
        if (d <= 0) continue;
        ans = max(ans, um + d - 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> U >> V;
    --U, --V;
    G.assign(N, {});
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << solve() << endl;

    return 0;
}
