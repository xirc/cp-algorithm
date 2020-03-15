#pragma once

// Finding Sum in Two-Dimensional Array

#include <vector>
#include <functional>

template<class T = long long>
class BinaryIndexedTree {
public:
    using F = std::function<T(const T&, const T&)>;

protected:
    int N, M;
    std::vector<std::vector<T>> bit;
    T id;
    F plus;
    F minus;

public:
    // O(N)
    BinaryIndexedTree(
        int n,
        int m,
        T id = T(),
        F plus = std::plus<T>(),
        F minus = std::minus<T>()
    )
        : N(n + 1)
        , M(m + 1)
        , bit(n + 1, std::vector<T>(m + 1, id))
        , id(id)
        , plus(plus)
        , minus(minus)
    {
        // Do nothing
    }
    // O(1)
    std::pair<int,int> size() {
        return { N - 1, M - 1 };
    }
    // Sum of array[[0,x),[0,y)]
    // O(logN logM)
    // x = [0,N], y = [0,M]
    T sum(int x, int y) {
        if (x < 0 || x > N) throw;
        if (y < 0 || y > M) throw;
        T ans = id;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                ans = plus(ans, bit[i][j]);
            }
        }
        return ans;
    }
    // Sum of array[[xl,xr),[yl,yr)]
    // O(logN logM)
    // xl = [0,N], xr = [0,N]
    // yl = [0,M], yr = [0,M]
    T sum(int xl, int xr, int yl, int yr) {
        if (xl > xr || yl > yr) throw;
        if (xl < 0 || xl > N || xr < 0 || xr > N) throw;
        if (yl < 0 || yl > M || yr < 0 || yr > M) throw;
        T ans = id;
        ans = plus(ans, sum(xr, yr));
        ans = minus(ans, sum(xl, yr));
        ans = minus(ans, sum(xr, yl));
        ans = plus(ans, sum(xl, yl));
        return ans;
    }
    // Add value at array[x,y]
    // O(logN logN)
    // x = [0,N), y = [0,M)
    void add(int x, int y, const T& value) {
        if (x < 0 || x >= N) throw;
        if (y < 0 || y >= M) throw;
        for (int i = x + 1; i < N; i += i & -i) {
            for (int j = y + 1; j < M; j += j & -j) {
                bit[i][j] = plus(bit[i][j], value);
            }
        }
    }
    // Set value at array[x,y]
    // O(logN logN)
    // x = [0,N), y = [0,M)
    void set(int x, int y, const T& value) {
        if (x < 0 || x >= N) throw;
        if (y < 0 || y >= M) throw;
        int new_value = value - sum(x,x+1,y,y+1);
        for (int i = x + 1; i < N; i += i & -i) {
            for (int j = y + 1; j < M; j += j & -j) {
                bit[i][j] = plus(bit[i][j], new_value);
            }
        }
    }
};