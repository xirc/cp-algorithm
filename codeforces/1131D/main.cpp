// https://codeforces.com/contest/1131/problem/D

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct DSU {
    int N;
    vector<int> size;
    vector<int> parent;
    DSU(int n): N(n), parent(n), size(n, 0) {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
    }
    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }
    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (size[a] < size[b]) swap(a,b);
        parent[b] = a;
        if (size[a] == size[b]) {
            size[a]++;
        }
    }
};

vector<int> tsort(const vector<vector<int>>& G) {
    vector<int> ans;
    vector<int> in(G.size(), 0);
    for (int v = 0; v < G.size(); ++v) {
        for (int u : G[v]) {
            in[u]++;
        }
    }
    queue<int> Q;
    for (int v = 0; v < G.size(); ++v) {
        if (in[v] == 0) Q.push(v);
    }
    while (Q.size()) {
        int v = Q.front(); Q.pop();
        ans.push_back(v);
        for (int u : G[v]) {
            in[u]--;
            if (in[u] == 0) Q.push(u);
        }
    }
    return ans;
}

int N, M;
vector<string> R;

void solve() {
    DSU dsu(N + M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (R[i][j] == '=') dsu.unite(i, j+N);
        }
    }

    vector<vector<int>> G(N + M);
    vector<vector<bool>> H(N + M, vector<bool>(N + M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int vi = dsu.find(i), vj = dsu.find(j+N);
            if (R[i][j] == '<') {
                G[vi].push_back(vj);
                H[vi][vj] = true;
            }
            if (R[i][j] == '>') {
                G[vj].push_back(vi);
                H[vj][vi] = true;
            }
        }
    }

    auto ts = tsort(G);
    if (ts.size() != N + M) {
        cout << "No" << endl;
        return;
    }
    vector<int> vs(N + M);
    vector<int> ord(N + M);
    for (int i = 0; i < N + M; ++i) {
        vs[i] = i;
        ord[ts[i]] = i;
    }
    sort(vs.begin(), vs.end(), [&](int l, int r) {
        int dl = dsu.find(l), dr = dsu.find(r);
        return ord[dl] < ord[dr];
    });

    vector<int> DP(N + M, 1);
    for (auto v : vs) {
        for (int u = 0; u < N + M; ++u) {
            int du = dsu.find(u), dv = dsu.find(v);
            if (H[dv][du]) {
                DP[u] = max(DP[u], DP[v] + 1);
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << DP[i];
    }
    cout << endl;
    for (int i = 0; i < M; ++i) {
        if (i > 0) cout << " ";
        cout << DP[N+i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    R.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }
    solve();

    return 0;
}