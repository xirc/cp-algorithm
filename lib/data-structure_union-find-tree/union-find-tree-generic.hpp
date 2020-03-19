#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B

#include <vector>
#include <functional>
#include <algorithm>

// Union Find Tree (Disjoint Set Union)
// Memory: O(N)
template <class T>
class UnionFindTree {
public:
    using F = std::function<void(T&, const T&)>;
    using G = std::function<void(T&, const T&, const T&)>;
    using H = std::function<void(T&, T&, const T&, const T&)>;

    struct node {
        int parent, rank;
        T value;
    };

protected:
    int N;
    std::vector<node> nodes;
    F compress;
    G unite_same;
    H unite_diff;

public:
    // O(N)
    UnionFindTree(
        int n,
        const F& compress = &T::compress,
        const G& unite_same = &T::unite_same,
        const H& unite_diff = &T::unite_diff
    )
        : N(n)
        , compress(compress)
        , unite_same(unite_same)
        , unite_diff(unite_diff)
    {
        nodes.reserve(N);
        for (int i = 0; i < N; ++i) {
            nodes.push_back({ i, 0, T(i) });
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(N))
    node find(int v) {
        throw_if_invalid_index(v);
        auto& node = nodes[v];
        if (v != node.parent) {
            // Path Compression
            auto root = find(node.parent);
            node.parent = root.parent;
            node.rank = root.rank;
            compress(node.value, root.value);
        }
        return node;
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
        auto nu = find(u);
        auto nv = find(v);
        u = nu.parent;
        v = nv.parent;
        if (u == v) {
            unite_same(nodes[u].value, nu.value, nv.value);
            return false;
        } else {
            static const auto less = std::less<int>(); // NOTE: a < b raise compile error ;(
            if (less(nodes[u].rank, nodes[v].rank)) {
                std::swap(u, v);
                std::swap(nu, nv);
            }
            nodes[v].parent = u;
            if (nodes[u].rank == nodes[v].rank) {
                nodes[u].rank++;
            }
            unite_diff(nodes[u].value, nodes[v].value, nu.value, nv.value);
            return true;
        }
    }

protected:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};