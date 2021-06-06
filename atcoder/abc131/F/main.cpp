#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<array<int,2>> ps;

int const M = 1e5+10;
vector<vector<int>> G(2*M);
vector<bool> done(2*M, false);

void dfs(int v, set<int>& xs, set<int>& ys) {
    if (done[v]) return;
    done[v] = true;
    if (v < M) {
        xs.insert(v);
    } else {
        ys.insert(v - M);
    }
    for (auto u : G[v]) {
        if (done[u]) continue;
        dfs(u, xs, ys);
    }
}

ll solve() {
    for (auto &p : ps) {
        int x = p[0], y = p[1];
        G[x].push_back(M+y);
        G[M+y].push_back(x);
    }

    ll ans = 0;
    for (int v = 0; v < M; ++v) {
        if (done[v]) continue;
        set<int> xs, ys;
        dfs(v, xs, ys);
        for (auto x : xs) {
            ans += ys.size() - G[x].size();
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    ps.assign(N, { 0, 0 });
    for (auto &p : ps) {
        cin >> p[0] >> p[1];
    }
    cout << solve() << endl;

    return 0;
}