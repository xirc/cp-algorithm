// Number of paths of a fixed length

#pragma once

#include <vector>
#include <map>

class Solver {
    using vec = std::vector<int>;
    using mat = std::vector<vec>;
    int m_size;
    mat m_matrix;
public:
    Solver(int size): m_size(size), m_matrix(size, vec(size, 0)) {}
    int size() {
        return m_size;
    }
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_matrix[from][to]++;
    }
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
            lookup[k] = product(product(half, half), a);
        } else {
            lookup[k] = product(half, half);
        }
        return lookup[k];
    }
    mat product(const mat& a, const mat&b) {
        const int N = m_size;
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