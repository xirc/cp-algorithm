#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<int>> G;

int solve() {
    int const M = N * N;
    vector<int> in(M, 0);
    queue<int> Q;
    vector<int> D(M, 1);
    for (int u = 0; u < M; ++u) {
        for (auto v : G[u]) {
            ++in[v];
        }
    }
    for (int u = 0; u < M; ++u) {
        if (in[u] == 0) Q.push(u);
    }
    while (Q.size()) {
        auto u = Q.front(); Q.pop();
        for (auto v : G[u]) {
            D[v] = max(D[v], D[u] + 1);
            --in[v];
            if (in[v] == 0) Q.push(v);
        }
    }
    for (int u = 0; u < M; ++u) {
        if (in[u] > 0) return -1;
    }
    return *max_element(D.begin(), D.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N * N, vector<int>());
    for (int i = 0; i < N; ++i) {
        vector<int> es;
        for (int j = 0; j < N - 1; ++j) {
            int a;
            cin >> a;
            --a;
            assert(i != a);
            int u = min(i, a), v = max(i, a);
            es.push_back(u * N + v);
        }
        for (int j = 1; j < es.size(); ++j) {
            G[es[j-1]].push_back(es[j]);
        }
    }
    cout << solve() << endl;

    return 0;
}