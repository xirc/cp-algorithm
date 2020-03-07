// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MaximumFlow {
    static const long long inf = 1e18;
    static const int inf_int = 1e8;
    struct edge { int from, to; long long capacity; };
    int m_size;
    std::vector<edge> m_edges;
    // Temporal
    std::vector<std::vector<long long>> capacity, flow;
    std::vector<int> height;
    std::vector<long long> excess;

public:
    MaximumFlow(int size): m_size(size) {}
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, long long capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges.push_back({ from, to, capacity });
        m_edges.push_back({ to, from, 0 });
    }
    // O(VE + V^2 sqrt(E))
    long long solve(int s, int t, std::vector<std::vector<long long>>& out_flow) {
        throw_if_invalid_index(s);
        throw_if_invalid_index(t);

        const int N = m_size;
        capacity.assign(m_size, std::vector<long long>(m_size, 0));
        flow.assign(N, std::vector<long long>(N, 0));
        height.assign(N, 0);
        excess.assign(N, 0);

        for (auto e : m_edges) {
            capacity[e.from][e.to] += e.capacity;
        }
        height[s] = N;
        excess[s] = inf;
        for (int u = 0; u < N; ++u) {
            push(s, u);
        }

        while (true) {
            auto verts = find_max_height_verts(s, t);
            if (verts.empty()) break;
            for (int v : verts) {
                bool pushed = false;
                for (int u = 0; u < N; u++) {
                    if (excess[v] == 0) break;
                    if (capacity[v][u] - flow[v][u] <= 0) continue;
                    if (height[v] != height[u] + 1) continue;
                    push(v, u);
                    pushed = true;
                }
                if (!pushed) {
                    relabel(v);
                    break;
                }
            }
        }

        out_flow = flow;
        long long max_flow = 0;
        for (int u = 0; u < N; ++u) {
            max_flow += flow[s][u];
        }
        return max_flow;
    }

private:
    void throw_if_invalid_index(int i) {
        if (i < 0 || i >= m_size) throw "index out of range";
    }
    void push(int u, int v) {
        auto d = std::min(excess[u], capacity[u][v] - flow[u][v]);
        flow[u][v] += d;
        flow[v][u] -= d;
        excess[u] -= d;
        excess[v] += d;
    }
    void relabel(int u) {
        const int N = m_size;
        auto h = inf_int;
        for (int v = 0; v < N; ++v) {
            if (capacity[u][v] - flow[u][v] > 0) {
                h = std::min(h, height[v]);
            }
        }
        if (h < inf_int) {
            height[u] = h + 1;
        }
    }
    std::vector<int> find_max_height_verts(int s, int t) {
        const int N = m_size;
        std::vector<int> ans;
        for (int i = 0; i < N; ++i) {
            if (i == s || i == t || excess[i] == 0) continue;
            if (!ans.empty() && height[i] > height[ans[0]]) {
                ans.clear();
            }
            if (ans.empty() || height[i] == height[ans[0]]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E;
    cin >> V >> E;
    MaximumFlow solver(V);
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        solver.add_edge(u, v, c);
    }
    vector<vector<long long>> flow;
    cout << solver.solve(0, V-1, flow) << endl;

    return 0;
}