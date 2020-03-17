// Number of paths of a fixed length

#pragma once

#include <vector>
#include <map>

class Solver {
    using vec = std::vector<long long>;
    using mat = std::vector<vec>;
    int N;
    mat matrix;

public:
    // O(V^2)
    Solver(int size): N(size), matrix(size, vec(size, 0)) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        matrix[from][to]++;
    }
    // O(V^3 logK)
    mat solve(int length) {
        if (length <= 0) throw "argument exception";
        return power(matrix, length);
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    mat power(const mat& a, const int k, std::map<int,mat> lookup = {}) {
        if (lookup.count(k)) {
            return lookup[k];
        }
        if (k == 0) {
            return lookup[0] = id(N);
        }
        auto half = power(a, k/2, lookup);
        if (k % 2) {
            lookup[k] = product(product(half, half), a);
        } else {
            lookup[k] = product(half, half);
        }
        return lookup[k];
    }
    mat product(const mat& a, const mat&b) {
        mat ans(N, vec(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int p = 0; p < N; ++p) {
                    ans[i][j] += a[i][p] * b[p][j];
                }
            }
        }
        return ans;
    }
    mat id(int n) {
        auto ans = mat(n, vec(n, 0));
        for (int i = 0; i < n; ++i) ans[i][i] = 1;
        return ans;
    }
};