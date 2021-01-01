// https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A

#include <bits/stdc++.h>


class TreeDiameter {
private:
    struct edge {
        size_t to;
        unsigned long long weight;
    };

    size_t N;
    std::vector<std::vector<edge>> adj;
    unsigned long long inf;

public:
    // Time: O(V)
    TreeDiameter(
        size_t const N = 0,
        unsigned long long const inf = std::numeric_limits<unsigned long long>::max()
    )
      : N(N)
      , adj(N)
      , inf(inf)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N), w = [0,inf)
    // Time: O(1)
    void add_edge(size_t const u, size_t const v, unsigned long long const w) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("u");
        if (w >= inf) throw std::out_of_range("w");
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    // s = [0,N)
    // Time: O(E)
    std::tuple<size_t, size_t, unsigned long long> solve(size_t s = 0) const {
        size_t u, v;
        unsigned long long w;
        std::tie(u, w) = bfs(s);
        std::tie(v, w) = bfs(u);
        if (u > v) std::swap(u, v);
        return std::make_tuple(u, v, w);
    }

private:
    std::pair<size_t, unsigned long long> bfs(size_t s) const {
        std::vector<unsigned long long> D(N, inf);
        std::queue<size_t> Q;
        Q.push(s);
        D[s] = 0;
        while (Q.size()) {
            size_t u = Q.front(); Q.pop();
            for (auto const& e : adj[u]) {
                if (D[e.to] == inf) {
                    D[e.to] = D[u] + e.weight;
                    Q.push(e.to);
                }
            }
        }
        size_t v = N;
        for (size_t i = 0; i < N; ++i) {
            if (D[i] == inf) continue;
            if (v == N || D[i] > D[v]) {
                v = i;
            }
        }
        return std::make_pair(v, D[v]);
    }
};


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    TreeDiameter solver(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }

    int u, v;
    long long w;
    tie(u, v, w) = solver.solve();
    cout << w << endl;

    return 0;
}