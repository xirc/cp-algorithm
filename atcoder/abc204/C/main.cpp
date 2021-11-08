#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<vector<int>> G;

vector<bool> done;
int dfs(int v) {
    if (done[v]) return 0;
    done[v] = true;
    int ans = 1;
    for (auto u : G[v]) {
        ans += dfs(u);
    }
    return ans;
}

int solve() {
    int ans = 0;
    for (int v = 0; v < N; ++v) {
        done.assign(N, false);
        ans += dfs(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    cout << solve() << endl;

    return 0;
}