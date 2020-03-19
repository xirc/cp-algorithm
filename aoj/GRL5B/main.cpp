#include <vector>
#include <queue>
#include <tuple>

class TreeHeight {
    struct edge {
        int to;
        long long w;
    };
    int N;
    std::vector<std::vector<edge>> adj;

public:
    static const long long inf = 1e18;
    // O(V)
    TreeHeight(int size): N(size), adj(size){}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, long long w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        if (w < 0) throw;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    // O(V + E)
    std::vector<long long> solve(int s = 0) {
        int u, v;
        long long w;

        std::tie(u, v, w) = diameter(s);
        auto Du = distance(u);
        auto Dv = distance(v);

        std::vector<long long> ans(N, 0);
        for (int i = 0; i < N; ++i) {
            if (i == u || i == v) {
                ans[i] = w;
            } else {
                ans[i] = std::max(Du[i], Dv[i]);
            }
        }
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    std::tuple<int, int, long long> diameter(int s) {
        int u, v;
        long long w;
        std::tie(u, w) = farther(s);
        std::tie(v, w) = farther(u);
        return std::make_tuple(u, v, w);
    }
    std::vector<long long> distance(int s) {
        std::vector<long long> D(N, inf);
        std::queue<int> Q;
        Q.push(s);
        D[s] = 0;
        while (Q.size()) {
            int u = Q.front(); Q.pop();
            for (auto& e : adj[u]) {
                if (D[e.to] == inf) {
                    D[e.to] = D[u] + e.w;
                    Q.push(e.to);
                }
            }
        }
        return D;
    }
    std::pair<int, long long> farther(int s) {
        auto D = distance(s);
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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    TreeHeight solver(0);

    cin >> N;
    solver = TreeHeight(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }

    auto height = solver.solve();
    for (int i = 0; i < height.size(); ++i) {
        cout << height[i] << endl;
    }

    return 0;
}