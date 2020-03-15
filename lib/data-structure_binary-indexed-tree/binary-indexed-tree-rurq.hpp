#pragma once

// Range Updates and Range Queries
// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G

#include <vector>

template <class T = long long>
class BinaryIndexedTree {
protected:
    int N;
    std::vector<T> bit1;
    std::vector<T> bit2;

public:
    // O(N)
    BinaryIndexedTree(int size)
        : N(size + 1)
        , bit1(size + 1)
        , bit2(size + 1)
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N - 1;
    }
    // Add the value to array[l,r)
    // O(logN)
    // l = [0,N)
    // r = [0,N]
    void add(int l, int r, T value) {
        if (l > r) throw;
        if (l < 0 || l >= N) throw;
        if (r < 0 || r > N) throw;
        add(bit1, l, value);
        if (r < N) add(bit1, r, -value);
        add(bit2, l, value * (l-1));
        if (r < N) add(bit2, r, -value * (r-1));
    }
    // Sum of array[0,index)
    // O(logN)
    // index = [0,N)
    T sum(int index) {
        if (index < 0 || index >= N) throw;
        return sum(bit1, index) * (index - 1) - sum(bit2, index);
    }
    // Sum of array[l,r)
    // O(logN)
    // l = [0,N)
    // r = [0,N]
    T sum(int l, int r) {
        if (l > r) throw;
        if (l < 0 || l >= N) throw;
        if (r < 0 || r > N) throw;
        return sum(r) - sum(l);
    }

protected:
    void add(std::vector<T>& bit, int index, T value) {
        if (index < 0 || index >= N) throw;
        for (index++; index < N; index += index & -index) {
            bit[index] += value;
        }
    }
    T sum(const std::vector<T>& bit, int index) {
        if (index < 0 || index >= N) throw;
        T ans = 0;
        for (; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }
};