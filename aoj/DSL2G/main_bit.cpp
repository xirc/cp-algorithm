// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G

#include <iostream>
#include <vector>

class BinaryIndexedTree {
    using T = long long;
    std::vector<T> bit1;
    std::vector<T> bit2;
    int m_size;

public:
    BinaryIndexedTree(int size)
        : m_size(size + 1)
        , bit1(size + 1)
        , bit2(size + 1)
    {
        // Do nothing
    }

    int size() {
        return m_size - 1;
    }

    // Add the value to array[l,r)
    // O(logN)
    void add(int l, int r, T value) {
        add(bit1, l, value);
        add(bit1, r, -value);
        add(bit2, l, value * (l-1));
        add(bit2, r, -value * (r-1));
    }

    // Sum of array[0,index)
    // O(logN)
    T sum(int index) {
        return sum(bit1, index) * (index - 1) - sum(bit2, index);
    }

    // Sum of array[l,r)
    // O(logN)
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }

private:
    void add(std::vector<T>& bit, int index, T value) {
        for (index++; index < m_size; index += index & -index) {
            bit[index] += value;
        }
    }
    T sum(std::vector<T>& bit, int index) {
        T ans = 0;
        for (; index > 0; index -= index & -index) {
            ans += bit[index];
        }
        return ans;
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
            cin >> s >> t;
            --s, --t;
            cout << bit.sum(s, t+1) << endl;
        } else throw;
    }

    return 0;
}