#include <bits/stdc++.h>

class MaximumFlow {
    static const long long inf = 1e18;
    struct edge {
        int from, to;
        long long capacity, flow;
    };

    int N;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;
    // Temporal
    std::vector<int> level, ptr;

public:
    // O(V)
    MaximumFlow(int n = 0): N(n), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long capacity) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (capacity < 0) throw;
        edges.push_back({ from, to, capacity, 0 });
        edges.push_back({ to, from, 0, 0 });
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }
    // O(E)
    void clear_flow() {
        for (auto& e : edges) {
            e.flow = 0;
        }
    }
    // O(V^2)
    std::vector<std::vector<long long>> get_flow() {
        std::vector<std::vector<long long>> flow(N, std::vector<long long>(N, 0));
        for (int i = 0; i < edges.size(); i += 2) {
            auto e = edges[i];
            flow[e.from][e.to] += e.flow;
        }
        return flow;
    }
    // O(V^2 E)
    // NOTE: This memorizes the residual network.
    long long solve(int s, int t) {
        level.assign(N, 0);
        ptr.assign(N, 0);

        long long ans = 0;
        while (true) {
            if (!bfs(s, t)) break;
            std::fill(ptr.begin(), ptr.end(), 0);
            while (long long push = dfs(t, s, inf)) {
                ans += push;
            }
        }

        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
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


using namespace std;
using ll = int64_t;

int N, G, E;
vector<int> ps;
vector<int> as, bs;

int solve() {
    MaximumFlow mf(N+1);
    for (int i = 0; i < E; ++i) {
        int a = as[i], b = bs[i];
        mf.add_edge(a, b, 1);
        mf.add_edge(b, a, 1);
    }
    for (int i = 0; i < G; ++i) {
        int p = ps[i];
        mf.add_edge(p, N, 1);
    }
    return mf.solve(0, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> G >> E;
    ps.assign(G, 0);
    as.assign(E, 0);
    bs.assign(E, 0);
    for (int i = 0; i < G; ++i) {
        cin >> ps[i];
    }
    for (int i = 0; i < E; ++i) {
        cin >> as[i] >> bs[i];
    }

    cout << solve() << endl;

    return 0;
}