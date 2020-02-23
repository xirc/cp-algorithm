#pragma once

#include <vector>
#include <set>
#include <algorithm>

class KruskalSimple {
    struct edge {
        int u, v, distance;
        bool operator<(const edge& other) const {
            return distance < other.distance;
        }
    };
    int m_size;
    std::set<std::pair<int,int>> m_uniq_edges;
    std::vector<edge> m_edges;

public:
    KruskalSimple(int size): m_size(size) {}

    int size() {
        return m_size;
    }

    void add_edge(int u, int v, int distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        if (m_uniq_edges.count({ u, v }) > 0 ||
            m_uniq_edges.count({ v, u }) > 0
        ) {
            return;
        }
        m_uniq_edges.insert({ u, v });
        m_edges.push_back({ u, v, distance });
    }

    // O(E logV + V^2)
    bool solve(int& out_distance, std::vector<std::pair<int,int>> &out_edges) {
        const int N = m_size;

        out_distance = 0;
        out_edges.clear();

        std::vector<int> tree_id(N);
        
        for (int i = 0; i < N; ++i) {
            tree_id[i] = i;
        }
        std::sort(m_edges.begin(), m_edges.end());

        for (auto edge : m_edges) {
            if (tree_id[edge.u] == tree_id[edge.v]) continue;

            out_distance += edge.distance;
            out_edges.push_back({ edge.u, edge. v });

            int old_id = tree_id[edge.u], new_id = tree_id[edge.v];
            for (int i = 0; i< N; ++i) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }

        return out_edges.size() == N - 1;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
};