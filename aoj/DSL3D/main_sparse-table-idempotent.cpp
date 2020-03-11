// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D

#include <vector>
#include <cmath>

// OP::op should be idempotent function OP::op(x,x) = x.
template <class T, class Monoid>
class SparseTable {
    int N, K;
    std::vector<std::vector<T>> table;

public:
    // O(N logN)
    SparseTable(std::vector<T>& array) {
        build(array);
    }
    // [l,r)
    // O(1)
    T query(int l, int r) {
        l = std::max(0, l);
        r = std::min(r, N);
        int w = r - l;
        if (w <= 0) return Monoid::id();
        int j = std::floor(std::log2(w));
        return Monoid::op(table[l][j], table[r - (1 << j)][j]);
    }

private:
    // O(N)
    void build(std::vector<T>& array) {
        N = array.size();
        if (N == 0) return;
        K = std::ceil(std::log2(N)) + 1;
        table.assign(N, std::vector<int>(K, Monoid::id()));
        for (int i = 0; i < N; ++i) {
            table[i][0] = Monoid::op(array[i], Monoid::id());
        }
        for (int j = 1; j < K; ++j) {
            for (int i = 0; i < N; ++i) {
                int w = 1 << (j-1);
                if (i + w >= N) continue;
                table[i][j] = Monoid::op(table[i][j-1], table[i+w][j-1]);
            }
        }
    }
};


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Minimum {
    static int id() {
        return numeric_limits<int>::max();
    }
    static int op(const int& lhs, const int& rhs) {
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

    SparseTable<int,Minimum> table(A);
    for (int i = 0; i + L - 1 < N; ++i) {
        if (i > 0) cout << " ";
        cout << table.query(i, i+L);
    }
    cout << endl;

    return 0;
}