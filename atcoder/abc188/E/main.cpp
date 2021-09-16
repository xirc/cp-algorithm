#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A;
vector<vector<int>> G;

int ans;
vector<bool> done;
vector<int> maxi;
void dfs(int v) {
    if (done[v]) return;
    done[v] = true;
    maxi[v] = A[v];
    for (int u : G[v]) {
        dfs(u);
        ans = max(ans, maxi[u] - A[v]);
        maxi[v] = max(maxi[u], maxi[v]);
    }
}

int solve() {
    ans = numeric_limits<int>::lowest();
    done.assign(N, 0);
    maxi.assign(N, numeric_limits<int>::lowest());
    for (int v = 0; v < N; ++v) {
        if (done[v]) continue;
        dfs(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    G.assign(N, {});
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
    }
    cout << solve() << endl;

    return 0;
}