// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class SqrtDecomposition {
    using T = long long;
    std::vector<T> m_array;
    std::vector<T> m_block;
    int N, S;
public:
    SqrtDecomposition(){}
    int size() { return N; }
    void dump(std::vector<T>& buffer) {
        buffer.resize(m_array.size());
        std::copy(m_array.begin(), m_array.end(), buffer.begin());
    }
    // O(N)
    void build(std::vector<T>& array) {
        N = array.size();
        S = std::ceil(std::sqrt(N));
        m_array.assign(N, 0);
        m_block.assign(S, 0);
        std::copy(array.begin(), array.end(), m_array.begin());
        for (int i = 0; i < N; ++i) {
            m_block[i / S] += array[i];
        }
    }
    // sum of array [l..r)
    // O(sqrt(N))
    T query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        T ans = 0;
        int cl = l / S, cr = (r - 1) / S;
        if (cl == cr) {
            for (int i = l; i < r; ++i) {
                ans += m_array[i];
            }
        } else {
            for (int i = l, M = (cl+1)*S; i < M; ++i) {
                ans += m_array[i];
            }
            for (int i = cl + 1; i < cr; ++i) {
                ans += m_block[i];
            }
            for (int i = cr * S; i < r; ++i) {
                ans += m_array[i];
            }
        }
        return ans;
    }
    // Update value at array[index]
    // O(1)
    void update(int index, T value) {
        if (index < 0 || index > N) return;
        m_block[index/S] -= m_array[index];
        m_array[index] = value;
        m_block[index/S] += value;
    }
};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<long long> array(N, 0);
    SqrtDecomposition solver;
    solver.build(array);

    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            --x;
            int v = solver.query(x, x+1);
            solver.update(x, v + y);
        } else if (c == 1) {
            --x, --y;
            cout << solver.query(x, y+1) << endl;
        } else throw;
    }

    return 0;
}