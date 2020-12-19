#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <vector>
#include <set>

// Minimum Spanning Tree
// Prim's Algorithm for Sparse Graph
// Memory: O(V + E)
// NOTE: undirected, no-multi-edge, negative-weight
class PrimSparse {
    static const long long inf = 1e18;
    struct edge {
        int to;
        long long distance;
    };

    int N;
    std::vector<std::vector<edge>> adj;

public:
    // O(N)
    PrimSparse(int n = 0)
        : N(n)
        , adj(n)
    {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, long long distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back({ v, distance });
        adj[v].push_back({ u, distance });
    }
    // O(E logV)
    bool solve(long long& distance, std::vector<std::pair<int,int>>& edges) {
        struct custom_less {
            bool operator()(const edge& lhs, const edge& rhs) const {
                return lhs.distance != rhs.distance
                    ? lhs.distance < rhs.distance
                    : lhs.to < rhs.to;
            }
        };

        distance = 0;
        edges.clear();

        std::vector<bool> used(N, false);
        std::vector<edge> min_edge(N, { -1, inf });
        std::set<edge,custom_less> Q;

        // Select vertex 0 at first.
        min_edge[0].distance = 0;
        Q.insert({ 0, 0 });

        for (int i = 0; i < N; ++i) {
            if (Q.empty()) {
                return false;
            }

            int v = Q.begin()->to;
            auto d = Q.begin()->distance;
            Q.erase(Q.begin());

            used[v] = true;
            distance += d;
            if (min_edge[v].to != -1) {
                edges.push_back({ min_edge[v].to, v });
            }

            for (auto edge : adj[v]) {
                if (used[edge.to]) continue;
                if (edge.distance < min_edge[edge.to].distance) {
                    Q.erase({ edge.to, min_edge[edge.to].distance });
                    min_edge[edge.to] = { v, edge.distance };
                    Q.insert({ edge.to, edge.distance });
                }
            }
        }
        return true;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};