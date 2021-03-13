#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

using Graph = vector<vector<int>>;

void dfs(Graph const& G, int v, unordered_set<int>& cs) {
    cs.insert(v);
    for (auto u : G[v]) {
        if (cs.count(u) > 0) continue;
        dfs(G, u, cs);
    }
}

int connected_components(Graph const& G, vector<int>& group) {
    const int N = G.size();
    int M = 0;
    group.assign(N, 0);
    vector<int> done(N, false);

    for (int v = 0; v < N; ++v) {
        if (done[v]) continue;
        unordered_set<int> cs;
        dfs(G, v, cs);
        for (auto u : cs) {
            done[u] = true;
            group[u] = M;
        }
        ++M;
    }
    return M;
}

int N, K, L;
vector<vector<int>> G;
vector<vector<int>> H;

vector<int> solve() {
    vector<int> groupG;
    vector<int> groupH;
    int P = connected_components(G, groupG);
    int Q = connected_components(H, groupH);

    map<array<int,2>,int> groupCount;
    for (int v = 0; v < N; ++v) {
        groupCount[{ groupG[v], groupH[v] }] += 1;
    }

    vector<int> connectedCount(N, 0);
    for (int v = 0; v < N; ++v) {
        connectedCount[v] = groupCount[{ groupG[v], groupH[v] }];
    }
    return connectedCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> L;

    G.assign(N, {});
    for (int i = 0; i < K; ++i) {
        int p, q;
        cin >> p >> q;
        --p, --q;
        G[p].push_back(q);
        G[q].push_back(p);
    }

    H.assign(N, {});
    for (int i = 0; i < L; ++i) {
        int r, s;
        cin >> r >> s;
        --r, --s;
        H[r].push_back(s);
        H[s].push_back(r);
    }

    auto cs = solve();
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << cs[i];
    }
    cout << endl;

    return 0;
}