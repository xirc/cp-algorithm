// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B

#include <vector>
#include <algorithm>

// Topological Sort
// This algorithm cannot detect a cycle.
class TopologicalSort {
    int N;
    std::vector<std::vector<int>> adj;
    // Temporal
    std::vector<int> ans;
    std::vector<bool> visited;

public:
    TopologicalSort(int n): N(n), adj(n) {}
    int size() {
        return N;
    }
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back(to);
    }
    std::vector<int> solve() {
        std::vector<int> in(N, 0);

        ans.clear();
        visited.assign(N, false);

        for (int v = 0; v < N; ++v) {
            for (int u : adj[v]) {
                in[u]++;
            }
        }
        for (int v = 0; v < N; ++v) {
            if (in[v] > 0) continue;
            if (visited[v]) continue;
            dfs(v);
        }
        std::reverse(ans.begin(), ans.end());

        return ans;
    }
private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    void dfs(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
        ans.push_back(v);
    }
};

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E;
    cin >> V >> E;

    TopologicalSort solver(V);
    
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s>> t;
        solver.add_edge(s, t);
    }

    auto ans = solver.solve();
    for (int v : ans) {
        printf("%d\n", v);
    }

    return 0;
}