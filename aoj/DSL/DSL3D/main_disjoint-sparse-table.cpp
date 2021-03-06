// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

// DisjointSparseTable
// Memory: O(N logN)
// Query: O(loglogN)
template <class T>
class DisjointSparseTable {
public:
    // F should be assosiative.
    // op(op(x,y),z) = op(x,op(y,z))
    using F = std::function<T(const T&, const T&)>;

protected:
    F monoid_op;
    T monoid_id;
    int N, L;
    std::vector<T> array;
    std::vector<std::vector<T>> table;

public:
    // O(N logN)
    DisjointSparseTable(
        const std::vector<T>& array,
        const F& monoid_op,
        const T& monoid_id
    )
        : monoid_op(monoid_op)
        , monoid_id(monoid_id)
        , array(array)
    {
        int S = array.size();
        L = std::ceil(std::log2(std::max(S,2)));
        N = 1 << L;
        table.assign(L, std::vector<T>(N, monoid_id));
        build(0, 0, N);
    }
    // O(N logN)
    template <class Monoid>
    DisjointSparseTable(
        const std::vector<T> array,
        const Monoid& monoid
    )
        : DisjointSparseTable(
            array,
            std::bind(&Monoid::operator(), monoid, std::placeholders::_1, std::placeholders::_2),
            monoid.id
        )
    {
        // Do nothing
    }
    // O(loglogN)
    // [l, r)
    // l = [0,N)
    // r = [0,N]
    T query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        if (r - l <= 0) {
            return monoid_id;
        }
        if (r - l == 1) {
            return array[l];
        }
        int k = msb(l^(r-1));
        int level = L - 1 - k;
        return monoid_op(table[level][l], table[level][r-1]);
    }

protected:
    // O(loglogN)
    int msb(int x) {
        int ans = 0;
        if (x >> 16) {
            x >>= 16; ans += 16;
        }
        if (x >> 8) {
            x >>= 8; ans += 8;
        }
        if (x >> 4) {
            x >>= 4; ans += 4;
        }
        if (x >> 2) {
            x >>= 2; ans += 2;
        }
        ans += x >> 1;
        return ans;
    }
    // O(1)
    T value(int index) {
        if (index >= array.size()) {
            return monoid_id;
        }
        return array[index];
    }
    // O(N logN)
    // [l,r)
    void build(int level, int l, int r) {
        const int m = (l + r) / 2;

        table[level][m-1] = value(m-1);
        for (int i = m-2; i >= l; --i) {
            table[level][i] = monoid_op(value(i), table[level][i+1]);
        }
        table[level][m] = value(m);
        for (int i = m+1; i < r; ++i) {
            table[level][i] = monoid_op(table[level][i-1], value(i));
        }

        if (r - l >= 4) {
            build(level + 1, l, m);
            build(level + 1, m, r);
        }
    }
};


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Minimum {
    const int id =numeric_limits<int>::max();
    int operator()(const int& lhs, const int& rhs) const {
        return min(lhs, rhs);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, L;
    vector<int> A;

    cin >> N >> L;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    DisjointSparseTable<int> table(A, Minimum());
    for (int i = 0; i + L - 1 < N; ++i) {
        if (i > 0) cout << " ";
        cout << table.query(i, i+L);
    }
    cout << endl;

    return 0;
}