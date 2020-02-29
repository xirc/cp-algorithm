#pragma

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A

#include <vector>
#include <queue>
#include <algorithm>

class MaximumFlow {
    static const long long inf = 1e18;
    struct edge { int from, to; long long capacity, flow; };
    int m_size;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;
    // Temporal
    std::vector<int> level, ptr;

public:
    MaximumFlow(int size): m_size(size), adj(size) {}
    void add_edge(int from, int to, long long capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges.push_back({ from, to, capacity });
        edges.push_back({ to, from, 0 });
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }
    // O(V^2 E)
    long long solve(int s, int t, std::vector<std::vector<long long>>& flow) {
        const int N = m_size;

        long long ans = 0;
        level.assign(N, 0);
        ptr.assign(N, 0);
        while (true) {
            if (!bfs(s, t)) break;
            std::fill(ptr.begin(), ptr.end(), 0);
            while (long long push = dfs(t, s, inf)) {
                ans += push;
            }
        }

        flow.assign(N, std::vector<long long>(N, 0));
        for (int i = 0; i < edges.size(); i += 2) {
            auto e = edges[i];
            flow[e.from][e.to] += e.flow;
        }

        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
    bool bfs(int s, int t) {
        std::queue<int> Q;
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int id : adj[v]) {
                auto e = edges[id];
                if (e.capacity - e.flow <= 0) continue;
                if (level[e.to] != -1) continue;
                level[e.to] = level[v] + 1;
                Q.push(e.to);
            }
        }
        return level[t] != -1;
    }
    long long dfs(int t, int v, long long push) {
        if (push == 0) return 0;
        if (v == t) return push;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            auto& e = edges[id];
            if (level[v] + 1 != level[e.to]) continue;
            if (e.capacity - e.flow <= 0) continue;
            auto new_push = std::min(push, e.capacity - e.flow);
            auto f = dfs(t, e.to, new_push);
            if (f == 0) continue;
            edges[id].flow += f;
            edges[id ^ 1].flow -= f;
            return f;
        }
        return 0;
    }
};