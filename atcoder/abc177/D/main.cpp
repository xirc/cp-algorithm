#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<vector<int>> G;

vector<bool> done;
int dfs(int v) {
    if (done[v]) return 0;
    int nodes = 1;
    done[v] = true;
    for (auto u : G[v]) {
        if (done[u]) continue;
        nodes += dfs(u);
    }
    return nodes;
}

int solve() {
    done.assign(N, false);
    int max_members = 0;
    for (int v = 0; v < N; ++v) {
        if (done[v]) continue;
        int members = dfs(v);
        max_members = max(max_members, members);
    }
    return max_members;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, {});
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    cout << solve() << endl;

    return 0;
}