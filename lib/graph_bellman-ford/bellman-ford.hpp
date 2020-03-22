#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B

#include <vector>
#include <algorithm>

// Bellman Ford Algorith
// Memory: O(V + E)
// NOTE: directed, multi-edge, self-loop, negative-weight
class BellmanFord {
    struct edge { int from, to; long long cost; };
    int N;
    std::vector<edge> edges;

public:
    static const long long inf = 1e18;
    // O(1)
    BellmanFord(int n = 0): N(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges.push_back({ from, to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<long long>& D, std::vector<int>& P) {
        throw_if_invalid_index(from);
        D.assign(N, inf);
        P.assign(N, -1);

        bool any_update = false;
        D[from] = 0;
        for (int i = 0; i < N; ++i) {
            any_update = false;
            for (int j = 0; j < edges.size(); ++j) {
                auto e = edges[j];
                if (D[e.from] >= inf) continue;
                if (D[e.to] > D[e.from] + e.cost) {
                    // suppress negative overflow
                    D[e.to] = std::max(-inf, D[e.from] + e.cost);
                    P[e.to] = e.from;
                    any_update = true;
                }
            }
            if (!any_update) break;
        }

        // if any_update == true, a negative cycle is found.
        return !any_update;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index of of range";
    }
};