#pragma once

#include <functional>
#include <map>
#include <stdexcept>

// BinaryIndexedTree
//
// Space: O(NM)
// Time:
//   Query: O(logN logM logNM)
//   Update: O(logN logM logNM)
//
template<class T = int64_t>
class BinaryIndexedTree2D {
public:
    using F = std::function<T(T const&, T const&)>;

protected:
    size_t N, M;
    std::map<std::pair<size_t,size_t>,T> bit;
    T empty;
    F combine_func;
    F remove_func;

public:
    // Time: O(1)
    BinaryIndexedTree2D(
        size_t n = 0,
        size_t m = 0,
        T empty = T(),
        F combine = std::plus<T>(),
        F remove = std::minus<T>()
    )
        : N(n + 1)
        , M(m + 1)
        , bit()
        , empty(empty)
        , combine_func(combine)
        , remove_func(remove)
    {
        // Do nothing
    }
    // Time: O(1)
    std::pair<size_t,size_t> size() const {
        return { N - 1, M - 1 };
    }
    // Fold elements of array[[0,x),[0,y)]
    // x = [0,N], y = [0,M]
    // Time: O(logN logM logNM)
    T fold(size_t x, size_t y) const {
        if (x > N) throw std::out_of_range("x");
        if (y > M) throw std::out_of_range("y");
        T ans = empty;
        for (size_t i = x; i > 0; i -= i & -i) {
            for (size_t j = y; j > 0; j -= j & -j) {
                if (bit.count({i,j})) {
                    ans = combine_func(ans, bit.at({i,j}));
                }
            }
        }
        return ans;
    }
    // Fold elements of array[[xl,xr),[yl,yr)]
    // xl = [0,N), xr = [xl,N]
    // yl = [0,M), yr = [yl,M]
    // Time: O(logN logM logNM)
    T fold(size_t xl, size_t xr, size_t yl, size_t yr) const {
        if (xl >= N) throw std::out_of_range("xl");
        if (xr < xl || xr > N) throw std::out_of_range("xr");
        if (yl >= M) throw std::out_of_range("yl");
        if (yr < yl || yr > M) std::out_of_range("yr");
        T ans = empty;
        ans = combine_func(ans, fold(xr, yr));
        ans = remove_func(ans, fold(xl, yr));
        ans = remove_func(ans, fold(xr, yl));
        ans = combine_func(ans, fold(xl, yl));
        return ans;
    }
    // Combine given value at array[x,y]
    // x = [0,N), y = [0,M)
    // Time: O(logN logN logNM)
    void combine(size_t x, size_t y, T const& value) {
        if (x >= N) throw std::out_of_range("x");
        if ( y >= M) throw std::out_of_range("y");
        for (size_t i = x + 1; i < N; i += i & -i) {
            for (size_t j = y + 1; j < M; j += j & -j) {
                if (!bit.count({i,j})) {
                    bit[{i,j}] = empty;
                }
                bit[{i,j}] = combine_func(bit[{i,j}], value);
            }
        }
    }
};