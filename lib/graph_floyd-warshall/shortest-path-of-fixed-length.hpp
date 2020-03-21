#pragma once

#include <vector>
#include <map>
#include <algorithm>

// Sortest paths of a fixed length
// Memory: O(V^2)
// NOTE: directed, no-multi-edge, no-self-loop
class Solver {
    using vec = std::vector<long long>;
    using mat = std::vector<vec>;
    int N;
    mat matrix;

public:
    static const long long inf = 1e18;
    // O(V^2)
    Solver(int size): N(size), matrix(size, vec(size, inf)) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, int distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        matrix[from][to] = distance;
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
            lookup[k] = op(op(half, half), a);
        } else {
            lookup[k] = op(half, half);
        }
        return lookup[k];
    }
    mat op(const mat& a, const mat&b) {
        mat ans(N, vec(N, inf));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int p = 0; p < N; ++p) {
                    ans[i][j] = std::min(ans[i][j], a[i][p] + b[p][j]);
                }
            }
        }
        return ans;
    }
    mat id(int n) {
        auto ans = mat(n, vec(n, inf));
        for (int i = 0; i < n; ++i) ans[i][i] = 0;
        return ans;
    }
};