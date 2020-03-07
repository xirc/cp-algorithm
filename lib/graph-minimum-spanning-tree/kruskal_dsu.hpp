#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <vector>
#include <set>
#include <algorithm>

class UnionFindTree {
public:
    struct node { int parent, rank; };

private:
    int m_size;
    std::vector<node> m_nodes;

public:
    UnionFindTree(int size)
        : m_size(size)
        , m_nodes(size)
    {
        for (int i = 0; i < size; ++i) {
            m_nodes[i] = { i, 0 };
        }
    }

    node find_set(int v) {
        throw_if_invalid_index(v);

        if (v != m_nodes[v].parent) {
            auto root = find_set(m_nodes[v].parent);
            m_nodes[v].parent = root.parent;
        }
        return m_nodes[v];
    }

    void union_set(int a, int b) {
        throw_if_invalid_index(a);
        throw_if_invalid_index(b);

        a = find_set(a).parent;
        b = find_set(b).parent;

        if (a == b) return;
        if (m_nodes[a].rank < m_nodes[b].rank) {
            std::swap(a, b);
        }
        m_nodes[b].parent = a;
        if (m_nodes[a].rank == m_nodes[b].rank) {
            m_nodes[a].rank++;
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
};

class Kruskal {
    struct edge {
        int u, v;
        long long distance;
        bool operator<(const edge& other) const {
            return distance < other.distance;
        }
    };
    int m_size;
    std::set<std::pair<int,int>> m_uniq_edges;
    std::vector<edge> m_edges;

public:
    Kruskal(int size): m_size(size) {}

    int size() {
        return m_size;
    }

    void add_edge(int u, int v, int distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        
        if (m_uniq_edges.count({ u, v }) > 0 ||
            m_uniq_edges.count({ v, u }) > 0)
        {
            return;
        }
        m_uniq_edges.insert({ u, v });
        m_edges.push_back({ u, v, distance });
    }

    // O (E logV)
    bool solve(long long& out_distance, std::vector<std::pair<int,int>>& out_edges) {
        const int N = m_size;

        out_distance = 0;
        out_edges.clear();

        UnionFindTree tree(N);

        std::sort(m_edges.begin(), m_edges.end());

        for (auto edge : m_edges) {
            if (tree.find_set(edge.u).parent == tree.find_set(edge.v).parent) continue;
            out_distance += edge.distance;
            out_edges.push_back({ edge.u, edge.v });
            tree.union_set(edge.u, edge.v);
        }

        return out_edges.size() == N - 1;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
};