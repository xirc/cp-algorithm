// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C

#include <bits/stdc++.h>

// Union Find Tree (Disjoint Set Union)
// Memory: O(N)
class UnionFindTree {
public:
    struct node { int parent, rank; };

protected:
    int N;
    std::vector<node> nodes;

public:
    // O(N)
    UnionFindTree(int n = 0)
        : N(n)
        , nodes(n)
    {
        for (int i = 0; i < N; ++i) {
            nodes[i] = { i, 0 };
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(N))
    node find(int v) {
        throw_if_invalid_index(v);
        if (v != nodes[v].parent) {
            // Path Compression
            nodes[v] = find(nodes[v].parent);
        }
        return nodes[v];
    }
    // O(a(N))
    bool same(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return find(u).parent == find(v).parent;
    }
    // O(a(N))
    bool unite(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        u = find(u).parent;
        v = find(v).parent;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
        }
        nodes[v].parent = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        return true;
    }

protected:
    void throw_if_invalid_index(int v) {
        if (v < 0 || v >= N) throw "index out of range";
    }
};

// LCA: Lowest Common Ancestor
// Memory: O(V + E + Q)
class LCA {
    struct Query { int u, idx; };

    UnionFindTree dsu;
    std::vector<bool> visited;
    std::vector<int> ancestor;
    std::vector<int> answer;

public:
    // O(V + Q)
    std::vector<int> solve(
        const std::vector<std::vector<int>>& adj,
        const std::vector<std::pair<int,int>>& queries
    ) {
        const int N = adj.size(), M = queries.size();
        std::vector<std::vector<Query>> Q(N);
        for (int i = 0; i < M; ++i) {
            const int u = queries[i].first, v = queries[i].second;
            Q[u].push_back({ v, i });
            Q[v].push_back({ u, i });
        }
        dsu = UnionFindTree(N);
        visited.assign(N, false);
        ancestor.assign(N, -1);
        answer.assign(M, -1);
        dfs(adj, Q, 0);
        return answer;
    }

private:
    void dfs(
        const std::vector<std::vector<int>>& adj,
        const std::vector<std::vector<Query>>& queries,
        int v
    ) {
        visited[v] = true;
        ancestor[v] = v;
        for (int u : adj[v]) {
            if (visited[u]) continue;
            dfs(adj, queries, u);
            dsu.unite(u, v);
            int c = dsu.find(v).parent;
            ancestor[c] = v;
        }
        for (auto query : queries[v]) {
            if (!visited[query.u]) continue;
            int c = dsu.find(query.u).parent;
            answer[query.idx] = ancestor[c];
        }
    }
};


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, Q;
    vector<vector<int>> adj;
    vector<pair<int,int>> queries;

    cin >> N;
    adj.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        int K, c;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> c;
            adj[i].push_back(c);
            adj[c].push_back(i);
        }
    }

    LCA solver;

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        queries.push_back({u, v});
    }

    auto ans = solver.solve(adj, queries);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}