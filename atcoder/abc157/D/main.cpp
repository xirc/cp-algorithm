#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M, K;
vector<vector<int>> G;
vector<set<int>> E;

vector<bool> done;
void dfs(int v, set<int>& cc) {
    if (done[v]) return;
    done[v] = true;
    cc.insert(v);
    for (int u : G[v]) {
        if (done[u]) continue;
        dfs(u, cc);
    }
}

vector<int> solve() {
    done.assign(N, false);
    vector<int> gr(N, -1);
    vector<set<int>> ccs;
    for (int v = 0; v < N; ++v) {
        if (done[v]) continue;
        set<int> cc;
        dfs(v, cc);
        for (int u : cc) {
            gr[u] = ccs.size();
        }
        ccs.push_back(cc);
    }
    for (int v = 0; v < N; ++v) {
        auto ns = E[v];
        for (int u : E[v]) {
            if (gr[v] != gr[u]) {
                ns.erase(u);
            }
        }
        E[v] = ns;
    }
    vector<int> ans(N, 0);
    for (int v = 0; v < N; ++v) {
        ans[v] = (ccs[gr[v]].size() - 1) - G[v].size() - E[v].size();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    G.assign(N, vector<int>());
    E.assign(N, set<int>());
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 0; i < K; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].insert(v);
        E[v].insert(u);
    }

    auto ans = solve();
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}