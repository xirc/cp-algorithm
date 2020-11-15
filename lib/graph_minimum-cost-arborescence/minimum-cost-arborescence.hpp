#pragma

// Verified
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_B

#include <vector>
#include <limits>
#include "../data-structure_union-find-tree/union-find-tree.hpp"
#include "../data-structure_heap/randomized-heap.hpp"

// Minimum Cost Arborescence
// Memory: O(V + E)
// NOTE: directed, multi-edge
class MinimumCostArborescence {
    struct edge {
        int index;
        int from, to;
        long long cost;
        bool operator<(const edge& o) const {
            return cost < o.cost;
        }
        edge operator+(const long long value) const {
            return { index, from, to, cost + value };
        }
    };
    int N;
    std::vector<edge> edges;

public:
    static const long long inf;
    // O(1)
    MinimumCostArborescence(int n = 0): N(n) {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int index, int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (cost < 0) throw;
        edges.push_back({ index, from, to, cost });
    }
    // O(E logV)
    long long solve(int root, std::vector<int>& out_edges) {
        throw_if_invalid_index(root);

        enum Processing { BEFORE = 0, PROCESSING = 1, DONE = 2 };
        UnionFindTree uftree(N);
        std::vector<Processing> processing(N, BEFORE);
        std::vector<Heap<edge, long long>> come(N);
        std::vector<int> from(N);
        std::vector<long long> from_cost(N);

        out_edges.clear();
        processing[root] = DONE;
        for (auto& e : edges) {
            come[e.to].insert(e);
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            if (processing[i] != BEFORE) continue;
            int c = i;
            std::vector<int> nodes;

            while (processing[c] != DONE) {
                processing[c] = PROCESSING;
                nodes.push_back(c);

                if (come[c].empty()) return inf;
                auto e = come[c].top(); come[c].pop();
                auto fc = uftree.find(e.from).leader;
                if (fc == c) continue;

                from[c] = fc;
                from_cost[c] = e.cost;
                ans += from_cost[c];
                out_edges.push_back(e.index);

                if (processing[from[c]] != PROCESSING) {
                    c = from[c];
                    continue;
                }
                // When we found a cycle, compress the cycle.
                int p = c;
                do {
                    come[p].update(-from_cost[p]);
                    if (p != c) {
                        uftree.unite(p, c);
                        int n = uftree.find(c).leader;
                        come[c].merge(come[p]);
                        come[n].merge(come[c]);
                        c = n;
                    }
                    p = uftree.find(from[p]).leader;
                } while (p != c);
            }
            for (auto v : nodes) {
                processing[v] = DONE;
            }
        }

        return ans;
    }

protected:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};
const long long MinimumCostArborescence::inf = std::numeric_limits<long long>::max();