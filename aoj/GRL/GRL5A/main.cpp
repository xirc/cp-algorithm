#include <vector>
#include <queue>
#include <tuple>

class TreeDiameter {
    struct edge {
        int to;
        long long weight;
    };

    int N;
    std::vector<std::vector<edge>> adj;

public:
    static const long long inf = 1e18;
    // O(V)
    TreeDiameter(int size): N(size), adj(size) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, long long weight) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back({ v, weight });
        adj[v].push_back({ u, weight });
    }
    // O(E)
    std::tuple<int, int, long long> solve(int s = 0) {
        int u, v, w;
        std::tie(u, w) = bfs(s);
        std::tie(v, w) = bfs(u);
        if (u > v) std::swap(u, v);
        return std::make_tuple(u, v, w);
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    std::pair<int, long long> bfs(int s) {
        std::vector<long long> D(N, inf);
        std::queue<int> Q;
        Q.push(s);
        D[s] = 0;
        while (Q.size()) {
            int u = Q.front(); Q.pop();
            for (auto& e : adj[u]) {
                if (D[e.to] == inf) {
                    D[e.to] = D[u] + e.weight;
                    Q.push(e.to);
                }
            }
        }
        int v = -1;
        for (int i = 0; i < N; ++i) {
            if (D[i] == inf) continue;
            if (v == -1 || D[i] > D[v]) {
                v = i;
            }
        }
        return std::make_pair(v, D[v]);
    }
};


#include <iostream>
#include <tuple>

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