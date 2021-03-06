#pragma once

// Verified
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C

#include <vector>
#include <array>
#include <set>
#include <memory>

// kD Tree
// Memory: O(N)
// NOTE:
//    Use index for avoiding large value copy in search.
//    You should handle indices out of this class.
template <class E = double, size_t N = 2>
class KDTree {
    using T = std::array<E,N>;
    struct Node {
        const int index;
        const T value;
        std::shared_ptr<Node> left, right;
        Node(const int index, const T& value)
        : index(index)
        , value(value)
        , left(nullptr)
        , right(nullptr) {}
    };
    using Tree = std::shared_ptr<Node>;

    Tree root = nullptr;
    int _size = 0;
    std::set<int> indices;

public:
    // O(1)
    int size() {
        return _size;
    }
    // O(logN)
    // only if values are uniformly distributed.
    void insert(const int index, const T& value) {
        if (indices.count(index) > 0) throw;
        root = insert(root, 0, index, value);
    }
    // O(logN + K)
    // only if values are uniformly distributed.
    // where K is number of points in area [lower,upper].
    // range = [lower,upper], both included.
    void search(const T& lower, const T& upper, std::vector<int>& out) {
        out.clear();
        search(root, 0, lower, upper, out);
    }
    // O(N)
    void clear() {
        root = nullptr;
        _size = 0;
        indices.clear();
    }

private:
    static constexpr bool less(int dim, const T& lhs, const T& rhs) {
        return lhs[dim] < rhs[dim];
    }
    static constexpr int next(int dim) {
        return (dim + 1) % N;
    }
    static constexpr bool inbox(const T& value, const T& lower, const T& upper) {
        for (int i = 0; i < N; ++i) {
            if (value[i] < lower[i]) return false;
            if (value[i] > upper[i]) return false;
        }
        return true;
    }
    Tree insert(Tree tree, int dim, const int index, const T& value) {
        if (!tree) {
            _size++;
            indices.insert(index);
            return Tree(new Node(index, value));
        }
        if (less(dim, value, tree->value)) {
            tree->left = insert(tree->left, next(dim), index, value);
        } else {
            tree->right = insert(tree->right, next(dim), index, value);
        }
        return tree;
    }
    void search(Tree tree, int dim, const T& lower, const T& upper, std::vector<int>& out) {
        if (!tree) return;
        const T& value = tree->value;
        if (inbox(value, lower, upper)) {
            out.push_back(tree->index);
        }
        if (!less(dim, value, lower)) {
            search(tree->left, next(dim), lower, upper, out);
        }
        if (!less(dim, upper, value)) {
            search(tree->right, next(dim), lower, upper, out);
        }
    }
};