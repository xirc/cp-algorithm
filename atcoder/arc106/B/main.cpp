#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<int> A, B;
vector<vector<int>> G;

vector<bool> done;

ll dfs(int v) {
    if (done[v]) return 0;
    done[v] = true;
    ll w = A[v];
    for (auto u : G[v]) {
        w += dfs(u);
    }
    return w;
}

bool solve() {
    for (int i = 0; i < N; ++i) {
        A[i] -= B[i];
    }
    done.assign(N, false);
    for (int i = 0; i < N; ++i) {
        if (done[i]) continue;
        auto w = dfs(i);
        if (w != 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    B.assign(N, 0);
    G.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}