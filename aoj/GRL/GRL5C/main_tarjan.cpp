// https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C

#include <bits/stdc++.h>


class UnionFindTree {
public:
    struct node {
        size_t leader;
        size_t rank;
    };

private:
    size_t N;
    std::vector<node> nodes;

public:
    // Time: O(N)
    UnionFindTree(size_t const N = 0)
        : N(N)
        , nodes(N)
    {
        for (size_t i = 0; i < N; ++i) {
            nodes[i] = { i, 0 };
        }
    }
    // Time: O(1)
    size_t size() {
        return N;
    }
    // v = [0,N)
    // Time: O(a(N))
    node find(size_t const v) {
        throw_if_invalid_index(v);
        if (v != nodes[v].leader) {
            // Path Compression
            nodes[v] = find(nodes[v].leader);
        }
        return nodes[v];
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool same(size_t const u, size_t const v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return find(u).leader == find(v).leader;
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool unite(size_t u, size_t v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        u = find(u).leader;
        v = find(v).leader;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
        }
        nodes[v].leader = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        return true;
    }

private:
    void throw_if_invalid_index(size_t const v) {
        if (v >= N) throw std::out_of_range("index out of range");
    }
};


inline std::vector<size_t> lca(
    std::vector<std::vector<size_t>> const& adj,
    std::vector<std::pair<size_t,size_t>> const& queries
)
{
    const size_t N = adj.size(), M = queries.size();

    struct Query { size_t u; size_t idx; };
    std::vector<std::vector<Query>> Q(N);
    for (size_t i = 0; i < M; ++i) {
        const size_t u = queries[i].first, v = queries[i].second;
        Q[u].push_back({ v, i });
        Q[v].push_back({ u, i });
    }

    UnionFindTree dsu(N);
    std::vector<bool> visited(N, false);
    std::vector<size_t> ancestor(N, N);
    std::vector<size_t> answer(M, N);

    std::function<void(size_t)> const dfs = [&](size_t v) {
        visited[v] = true;
        ancestor[v] = v;
        for (auto const& u : adj[v]) {
            if (visited[u]) continue;
            dfs(u);
            dsu.unite(u, v);
            size_t c = dsu.find(v).leader;
            ancestor[c] = v;
        }
        for (auto const& query : Q[v]) {
            if (!visited[query.u]) continue;
            size_t c = dsu.find(query.u).leader;
            answer[query.idx] = ancestor[c];
        }
    };
    dfs(0);

    return answer;
}


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, Q;
    vector<vector<size_t>> adj;
    vector<pair<size_t,size_t>> queries;

    cin >> N;
    adj.assign(N, vector<size_t>());
    for (int i = 0; i < N; ++i) {
        int K, c;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cin >> c;
            adj[i].push_back(c);
            adj[c].push_back(i);
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int u, v;
        cin >> u >> v;
        queries.push_back({u, v});
    }

    auto ans = lca(adj, queries);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}