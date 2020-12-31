#pragma once

#include <vector>
#include <functional>
#include <stdexcept>


// Union Find Tree
// (aka Disjoint Set Union)
//
// Space: O(N)
//
// Verified
//  - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
//
template <typename T, typename U>
class UnionFindTree {
public:
    using D = std::function<T(size_t const idx)>;
    using E = std::function<U(U const& w)>;
    using F = std::function<void(T& node, T const& leader)>;
    using G = std::function<void(T& leader, T const& u, T const& v, U const& w)>;
    using H = std::function<void(T& leader, T& follower, T const& u, T const& v, U const& w)>;
    struct node {
        size_t leader;
        size_t rank;
        T value;
    };

private:
    size_t N;
    std::vector<node> nodes;
    D apply;
    E inverse;
    F compress;
    G unite_same;
    H unite_diff;

public:
    // Time: O(N)
    UnionFindTree(
        size_t const N = 0,
        D const& apply = [](size_t const idx) { return T(idx); },
        E const& inverse = std::negate<U>(),
        F const& compress = &T::compress,
        G const& unite_same = &T::unite_same,
        H const& unite_diff = &T::unite_diff
    )
        : N(N)
        , apply(apply)
        , inverse(inverse)
        , compress(compress)
        , unite_same(unite_same)
        , unite_diff(unite_diff)
    {
        nodes.reserve(N);
        for (size_t i = 0; i < N; ++i) {
            nodes.push_back({ i, 0, apply(i) });
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
        auto& node = nodes[v];
        if (v != node.leader) {
            // Path Compression
            auto root = find(node.leader);
            node.leader = root.leader;
            node.rank = root.rank;
            compress(node.value, root.value);
        }
        return node;
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
    bool unite(size_t u, size_t v, U w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        auto lu = find(u).leader;
        auto lv = find(v).leader;
        if (lu == lv) {
            unite_same(nodes[lu].value, nodes[u].value, nodes[v].value, w);
            return false;
        }
        if (nodes[lu].rank < nodes[lv].rank) {
            std::swap(lu, lv);
            std::swap(u, v);
            w = inverse(w);
        }
        nodes[lv].leader = lu;
        if (nodes[lu].rank == nodes[lv].rank) {
            nodes[lu].rank++;
        }
        unite_diff(nodes[lu].value, nodes[lv].value, nodes[u].value, nodes[v].value, w);
        return true;
    }

private:
    void throw_if_invalid_index(size_t const index) {
        if (index >= N) throw std::out_of_range("index out of range");
    }
};