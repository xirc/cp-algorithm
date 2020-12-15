#include <bits/stdc++.h>

// Topological Sort
// Memory: O(V + E)
// NOTE: directed, multi-edge
class TopologicalSort {
    int N;
    std::vector<std::vector<int>> adj;

public:
    // O(V)
    TopologicalSort(int n = 0): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back(to);
    }
    // O(V + E)
    bool solve(std::vector<int>& ans) {
        std::queue<int> Q;
        std::vector<int> in(N, 0);

        ans.clear();
        ans.reserve(N);

        for (int v = 0; v < N; ++v) {
            for (int u : adj[v]) in[u]++;
        }
        for (int v = 0; v < N; ++v) {
            if (in[v] == 0) Q.push(v);
        }
        while (Q.size()) {
            int v = Q.front(); Q.pop();
            ans.push_back(v);
            for (auto u : adj[v]) {
                in[u]--;
                if (in[u] == 0) Q.push(u);
            }
        }
        return ans.size() == N;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};

using namespace std;

int N, M;
vector<vector<int>> LRD;

vector<vector<pair<int,int>>> G;
vector<bool> done;
vector<int> ds;

bool dfs(int v) {
    if (done[v]) return true;
    done[v] = true;
    for (auto e : G[v]) {
        auto u = e.first, d = e.second;
        int nd = ds[v] + d;
        if (ds[u] == -1) {
            ds[u] = nd;
        }
        if (ds[u] != nd) {
            return false;
        }
        if (!dfs(u)) {
            return false;
        }
    }
    return true;
}

bool solve() {
    TopologicalSort tsort(N);

    G.assign(N, vector<pair<int,int>>());
    for (int i = 0; i < M; ++i) {
        auto l = LRD[i][0], r = LRD[i][1], d = LRD[i][2];
        G[l].push_back({ r, d });
        tsort.add_edge(l, r);
    }

    vector<int> vs;
    auto can_tsort = tsort.solve(vs);
    if (!can_tsort) {
        return false;
    }

    done.assign(N, false);
    ds.assign(N, -1);
    for (int v : vs) {
        if (done[v]) continue;
        ds[v] = 0;
        if (!dfs(v)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    LRD.assign(M, vector<int>(3, 0));
    for (int i = 0; i < M; ++i) {
        cin >> LRD[i][0] >> LRD[i][1] >> LRD[i][2];
        --LRD[i][0], --LRD[i][1];
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}