#pragma once

#include <vector>
#include <functional>
#include <stdexcept>


// Union Find Tree
// (aka Disjoint Set Union)
//
// NOTE:
// typename T should be group.
//
// Space: O(N)
//
// Verified
//  - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
//
template <typename T>
class UnionFindTree {
public:
    using F = std::function<T(T const& lhs, T const& rhs)>;
    struct node {
        size_t leader;
        size_t rank;
        T weight;
    };

private:
    size_t N;
    std::vector<node> nodes;
    F group_plus;
    F group_minus;
    T group_id;

public:
    // Time: O(N)
    UnionFindTree(
        size_t const N = 0,
        F const& group_plus = std::plus<T>(),
        F const& group_minus = std::minus<T>(),
        T const& group_id = T()
    )
        : N(N)
        , nodes(N)
        , group_plus(group_plus)
        , group_minus(group_minus)
        , group_id(group_id)
    {
        for (size_t i = 0; i < N; ++i) {
            nodes[i] = { i, 0, group_id };
        }
    }
    // Time: O(1)
    size_t size() {
        return N;
    }
    // u = [0,N)
    // Time: O(a(N))
    node find(size_t const v) {
        throw_if_invalid_index(v);
        if (v != nodes[v].leader) {
            // Path Compression
            auto root = find(nodes[v].leader);
            nodes[v].leader = root.leader;
            nodes[v].rank = root.rank;
            nodes[v].weight = group_plus(
                nodes[v].weight,
                root.weight
            );
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
    // weight(u) - weight(v) = w;
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool unite(size_t u, size_t v, T w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        w = group_minus(w, find(u).weight);
        w = group_plus(w, find(v).weight);
        u = find(u).leader;
        v = find(v).leader;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
            w = group_minus(group_id, w);
        }
        nodes[v].leader = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        nodes[v].weight = group_minus(group_id, w);
        return true;
    }
    // u = [0,N), v = [0,N)
    // Time: O(a(N))
    bool diff(size_t const u, size_t const v, T& w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        if (!same(u,v)) {
            return false;
        }
        w = group_minus(find(u).weight, find(v).weight);
        return true;
    }

private:
    void throw_if_invalid_index(size_t const v) {
        if (v >= N) throw std::out_of_range("index out of range");
    }
};