// Sortest paths of a fixed length

#pragma once

#include <vector>
#include <map>
#include <algorithm>

class Solver {
    using vec = std::vector<int>;
    using mat = std::vector<vec>;
    int m_size;
    mat m_matrix;
public:
    static const int inf = 1e8;
    Solver(int size): m_size(size), m_matrix(size, vec(size, inf)) {}
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_matrix[from][to] = distance;
    }
    // O(V^3 logK)
    mat solve(int length) {
        if (length <= 0) throw "argument exception";
        return power(m_matrix, length);
    }
private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
    mat power(const mat& a, const int k, std::map<int,mat> lookup = {}) {
        const int N = m_size;
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
        const int N = m_size;
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