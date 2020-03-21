#include <vector>
#include <algorithm>

// Bridge of a Graph
// Memory: O(V + E)
// NOTE: allow multi-edge, but no self-loop
class Bridge {
    struct edge { int id, to; };

    int N, M;
    std::vector<std::vector<edge>> adj;
    // Temporary
    int K;
    std::vector<int> ord;
    std::vector<int> low;
    std::vector<std::pair<int,int>> ans;

public:
    // O(V)
    Bridge(int n): N(n), M(0), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back({ M, v });
        adj[v].push_back({ M, u });
        M++;
    }
    // O(V + E)
    std::vector<std::pair<int,int>> solve() {
        K = 0;
        ord.assign(N, -1);
        low.assign(N, -1);
        ans.clear();
        for (int u = 0; u < N; ++u) {
            if (ord[u] != -1) continue;
            dfs(u);
        }
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index > N) throw "index out of range";
    }
    void dfs(int u, const edge& ein = { -1, 0 }) {
        ord[u] = low[u] = K++;
        for (auto& e : adj[u]) {
            if (ord[e.to] == -1) {
                dfs(e.to, e);
                low[u] = std::min(low[u], low[e.to]);
                if (ord[u] < low[e.to]) {
                    ans.push_back({ u, e.to });
                }
            } else if (e.id != ein.id) {
                low[u] = std::min(low[u], ord[e.to]);
            }
        }
    }
};


#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E;
    cin >> V >> E;

    Bridge solver(V);

    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        solver.add_edge(s, t);
    }

    auto bridges = solver.solve();
    for_each(bridges.begin(), bridges.end(), [&](auto& e) {
        if (e.first > e.second) swap(e.first, e.second);
    });
    sort(bridges.begin(), bridges.end());
    for (auto e : bridges) {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}