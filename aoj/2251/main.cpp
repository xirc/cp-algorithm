// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251&lang=en

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct FloydWarshall {
    static const int inf = 1e8;
    int N;
    vector<vector<int>> D;
    FloydWarshall(int n): N(n), D(n, vector<int>(n, inf)) {}
    void edge(int from, int to, int w) {
        D[from][to] = w;
    }
    void solve() {
        for (int i = 0; i < N; ++i) D[i][i] = 0;
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }
};

struct BipartiteMaximumMatching {
    int N;
    vector<vector<int>> G;
    vector<int> match;
    vector<bool> used;
    BipartiteMaximumMatching(int n): N(n), G(n) {}
    void edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int solve() {
        int ans = 0;
        match.assign(N, -1);
        for (int v = 0; v < N; ++v) {
            if (match[v] != -1) continue;
            used.assign(N, false);
            if (dfs(v)) ans += 1;
        }
        return ans;
    }
    bool dfs(int v) {
        used[v] = true;
        for (int u : G[v]) {
            int w = match[u];
            if (w == -1 || (!used[w] && dfs(w))) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        int N, M, L;
        cin >> N >> M >> L;
        if (N == 0 && M == 0 && L == 0) break;

        FloydWarshall fw(N);
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            fw.edge(u, v, d);
            fw.edge(v, u, d);
        }
        fw.solve();

        vector<pair<int,int>> R(L);
        for (int i = 0; i < L; ++i) {
            cin >> R[i].first >> R[i].second;
        }

        BipartiteMaximumMatching bmm(2*L);
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                if (i == j) continue;
                int pi, ti, pj, tj;
                tie(pi, ti) = R[i];
                tie(pj, tj) = R[j];
                int w = fw.D[pi][pj];
                if (w == FloydWarshall::inf) continue;
                if (ti + w <= tj) {
                    bmm.edge(i, j + L);
                }
            }
        }
        int ans = L - bmm.solve();
        cout << ans << endl;
    }

    return 0;
}