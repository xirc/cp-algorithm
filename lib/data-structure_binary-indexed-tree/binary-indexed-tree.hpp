#pragma once

// Finding Sum in One-Dimensional Array
// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

#include <vector>
#include <functional>

template <class T = long long>
class BinaryIndexedTree {
public:
    using F = std::function<T(const T&, const T&)>;

protected:
    int N;
    std::vector<T> bit;
    T id;
    F plus;
    F minus;

public:
    // O(N)
    BinaryIndexedTree(
        int n,
        T id = T(),
        F plus = std::plus<T>(),
        F minus = std::minus<T>()
    )
        : N(n+1)
        , bit(n+1, id)
        , id(id)
        , plus(plus)
        , minus(minus)
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N - 1;
    }
    // Sum of array[0..index)
    // O(logN)
    // index = [0,N]
    T sum(int index) {
        if (index < 0 || index > N) throw;
        T ans = id;
        for (; index > 0; index -= index & -index) {
            ans = plus(ans, bit[index]);
        }
        return ans;
    }
    // Sum of array[l, r)
    // O(logN)
    T sum(int l, int r) {
        if (l > r) throw;
        return minus(sum(r), sum(l));
    }
    // Add value to array[index]
    // O(logN)
    // index = [0,N)
    void add(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        for (++index; index < N; index += index & -index) {
            bit[index] = plus(bit[index], value);
        }
    }
    // Set value to array[index]
    // O(logN)
    // index = [0,N)
    void set(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        T new_value = minus(value, sum(index, index+1));
        add(index, new_value);
    }
};