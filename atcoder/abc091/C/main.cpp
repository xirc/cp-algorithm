#include <bits/stdc++.h>

class BipartiteMaximumMatching {
    size_t N;
    std::vector<std::vector<size_t>> adj;

public:
    // Time: O(N)
    BipartiteMaximumMatching(size_t n = 0)
        : N(n)
        , adj(n)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N)
    // Time: O(1)
    void add_edge(size_t u, size_t v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Time: O( V(V+E) )
    size_t solve(std::vector<size_t>& match) {
        size_t ans = 0;
        std::vector<bool> used(N, false);
        match = std::vector<size_t>(N, N);
        for (size_t v = 0; v < N; ++v) {
            if (match[v] != N) continue;
            used.assign(N, false);
            if (dfs(match, used, v)) ans++;
        }
        return ans;
    }

private:
    bool dfs(
        std::vector<size_t>& match,
        std::vector<bool>& used,
        size_t v
    ) {
        used[v] = true;
        for (size_t u : adj[v]) {
            size_t w = match[u];
            if (w == N || (!used[w] && dfs(match, used, w))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
};


using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<pair<int,int>> rs, bs;

int solve() {
    BipartiteMaximumMatching solver(2*N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (rs[i].first < bs[j].first && rs[i].second < bs[j].second) {
                solver.add_edge(i, N + j);
            }
        }
    }
    vector<size_t> match;
    return solver.solve(match);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    rs.assign(N, { 0, 0 });
    bs.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> rs[i].first >> rs[i].second;
    }
    for (int i = 0; i < N; ++i) {
        cin >> bs[i].first >> bs[i].second;
    }
    cout << solve() << endl;

    return 0;
}