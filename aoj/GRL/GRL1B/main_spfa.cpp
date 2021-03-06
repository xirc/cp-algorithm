//https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
#include <bits/stdc++.h>

class SPFA {
private:
    struct edge {
        size_t to;
        int64_t cost;
    };
    size_t N;
    std::vector<std::vector<edge>> edges;
    int64_t inf;

public:
    // Time: O(V)
    SPFA(
        size_t const N = 0,
        int64_t const inf = std::numeric_limits<int64_t>::max() / 2
    )
        : N(N)
        , edges(N)
        , inf(inf)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // Time: O(1)
    int64_t infinity() const {
        return inf;
    }
    // from = [0,N), to = [0,N), cost = (-inf,inf)
    // O(1)
    void add_edge(size_t const from, size_t const to, int64_t const cost) {
        if (from >= N) throw std::out_of_range("from");
        if (to >= N) throw std::out_of_range("to");
        if (std::abs(cost) >= inf) throw std::out_of_range("cost");
        edges[from].push_back({ to, cost });
    }
    // from = [0,N)
    // O (E V)
    bool solve(size_t const from, std::vector<int64_t>& D, std::vector<size_t>& P) const {
        if (from >= N) throw std::out_of_range("from");

        D.assign(N, inf);
        P.assign(N, N);
        std::vector<size_t> count(N, 0);
        std::vector<bool> inqueue(N, false);
        std::queue<size_t> Q;

        D[from] = 0;
        Q.push(from);
        inqueue[from] = true;
        while (!Q.empty()) {
            size_t v = Q.front(); Q.pop();
            inqueue[v] = false;
            for (auto const& edge : edges[v]) {
                if (D[edge.to] <= D[v] + edge.cost) continue;
                D[edge.to] = D[v] + edge.cost;
                P[edge.to] = v;
                if (inqueue[edge.to]) continue;
                Q.push(edge.to);
                inqueue[edge.to] = true;
                count[edge.to]++;
                if (count[edge.to] > N) {
                    // Found a negative cycle
                    return false;
                }
            }
        }
        return true;
    }
};


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E, R;
    cin >> V >> E >> R;

    SPFA solver(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }

    vector<int64_t> D;
    vector<size_t> P;
    bool has_ans = solver.solve(R, D, P);
    if (!has_ans) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < V; ++i) {
        if (D[i] == solver.infinity()) cout << "INF" << endl;
        else cout << D[i] << endl;
    }

    return 0;
}