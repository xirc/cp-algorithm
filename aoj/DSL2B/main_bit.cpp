// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

#include <iostream>
#include <vector>

class BinaryIndexedTree {
    using T = long long;
    std::vector<T> bit;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size+1)
        , bit(size+1) {
    }

    int size() {
        return m_size - 1;
    }

    // Sum of array[0..index)
    // O(logN)
    T sum(int index) {
        if (index >= m_size) index = m_size - 1;
        T ans = 0;
        for (; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

    // Sum of array[l, r)
    // O(logN)
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }

    // Add value to array[index]
    // O(logN)
    void add(int index, T value) {
        if (index < 0 || index >= m_size) throw;
        for (++index; index < m_size; index += index & -index) {
            bit[index] += value;
        }
    }
};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    BinaryIndexedTree bit(N);
    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            --x;
            bit.add(x, y);
        } else if (c == 1) {
            --x, --y;
            cout << bit.sum(x, y+1) << endl;
        } else throw;
    }

    return 0;
}