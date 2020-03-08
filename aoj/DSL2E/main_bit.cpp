// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E

#include <iostream>
#include <vector>

class BinaryIndexedTree {
    using T = long long;
    std::vector<T> bit;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size + 1)
        , bit(size + 1)
    {
        // Do nothing
    }

    int size() {
        return m_size - 1;
    }

    // Add value to array[l,r)
    // O(logN)
    void add(int l, int r, T value) {
        add(l, value);
        add(r, -value);
    }

    // Get value at array[index]
    // O(logN)
    T query(int index) {
        T ans = 0;
        for (++index; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
    }

private:
    void add(int index, T value) {
        if (index < 0) return;
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
        int c, s, t, x;
        cin >> c;
        if (c == 0) {
            cin >> s >> t >> x;
            --s, --t;
            bit.add(s, t+1, x);
        } else if (c == 1) {
            cin >> t;
            --t;
            cout << bit.query(t) << endl;
        } else throw;
    }

    return 0;
}