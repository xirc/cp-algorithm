// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>

template <class T>
class SqrtDecomposition {
public:
    using value_type_T = T;
    using F = std::function<T(const T&, const T&)>;
    using G = std::function<T(const T&)>;

protected:
    int N, S;
    std::vector<T> m_array;
    std::vector<T> m_block;
    F group_operator;
    G group_inverse;
    T group_id;

public:
    // O(N)
    SqrtDecomposition(
        const std::vector<T>& array,
        const F& group_operator,
        const G& group_inverse,
        const T& group_id
    )
        : group_operator(group_operator)
        , group_inverse(group_inverse)
        , group_id(group_id)
    {
        build(array);
    }
    // O(N)
    template <class Group>
    SqrtDecomposition(const std::vector<T>& array, const Group& group)
        : SqrtDecomposition(
            array,
            std::bind(&Group::operator(), group, std::placeholders::_1, std::placeholders::_2),
            std::bind(&Group::operator-, group, std::placeholders::_1),
            group.id
        )
    {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(N)
    void dump(std::vector<T>& buffer) {
        buffer.resize(m_array.size());
        std::copy(m_array.begin(), m_array.end(), buffer.begin());
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        S = std::ceil(std::sqrt(N));
        m_array.assign(N, group_id);
        m_block.assign(S, group_id);
        std::copy(array.begin(), array.end(), m_array.begin());
        for (int i = 0; i < N; ++i) {
            m_block[i/S] = group_operator(m_block[i/S], array[i]);
        }
    }
    // O(sqrt(N))
    // [l,r)
    // l = [0,N), r = [0,N]
    T query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        T ans = group_id;
        int cl = l / S, cr = (r - 1) / S;
        if (cl == cr) {
            for (int i = l; i < r; ++i) {
                ans = group_operator(ans, m_array[i]);
            }
        } else {
            for (int i = l, M = (cl+1)*S; i < M; ++i) {
                ans = group_operator(ans, m_array[i]);
            }
            for (int i = cl + 1; i < cr; ++i) {
                ans = group_operator(ans, m_block[i]);
            }
            for (int i = cr * S; i < r; ++i) {
                ans = group_operator(ans, m_array[i]);
            }
        }
        return ans;
    }
    // O(1)
    // index = [0,N)
    void update(int index, const T& value) {
        if (index < 0 || index > N) return;
        m_block[index/S] = group_operator(m_block[index/S], group_inverse(m_array[index]));
        m_array[index] = value;
        m_block[index/S] = group_operator(m_block[index/S], value);
    }
};


#include <iostream>

using namespace std;

struct Sum {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
    int operator-(const int& value) const {
        return -value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> array(N, 0);
    SqrtDecomposition<int> solver(array, Sum());

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