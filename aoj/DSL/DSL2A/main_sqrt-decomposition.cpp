// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>

// SqrtDecomposition
// Memory: O(N)
// Query: O(sqrt(N))
// Update: O(sqrt(N))
template <class T>
class SqrtDecomposition {
public:
    using value_type_T = T;
    using F = std::function<T(const T&, const T&)>;

protected:
    int N, S;
    std::vector<T> array;
    std::vector<T> block;
    F monoid_op;
    T monoid_id;

public:
    // O(N)
    SqrtDecomposition(
        const std::vector<T>& array,
        const F& monoid_op,
        const T& monoid_id
    )
        : monoid_op(monoid_op)
        , monoid_id(monoid_id)
    {
        build(array);
    }
    // O(N)
    template <class Monoid>
    SqrtDecomposition(
        const std::vector<T>& array,
        const Monoid& monoid
    )
        : SqrtDecomposition(
            array,
            std::bind(&Monoid::operator(), monoid, std::placeholders::_1, std::placeholders::_2),
            monoid.id
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
        buffer.resize(array.size());
        std::copy(array.begin(), array.end(), buffer.begin());
    }
    // O(N)
    void build(const std::vector<T>& array) {
        N = array.size();
        S = std::ceil(std::sqrt(N));
        this->array = array;
        block.assign(S, monoid_id);
        for (int i = 0; i < N; ++i) {
            block[i/S] = monoid_op(block[i/S], array[i]);
        }
    }
    // O(sqrt(N))
    // [l..r)
    // l = [0,N), r = [0,N]
    T query(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, N);
        T ans = monoid_id;
        int cl = l / S, cr = (r - 1) / S;
        if (cl == cr) {
            for (int i = l; i < r; ++i) {
                ans = monoid_op(ans, array[i]);
            }
        } else {
            for (int i = l, M = (cl+1)*S; i < M; ++i) {
                ans = monoid_op(ans, array[i]);
            }
            for (int i = cl + 1; i < cr; ++i) {
                ans = monoid_op(ans, block[i]);
            }
            for (int i = cr * S; i < r; ++i) {
                ans = monoid_op(ans, array[i]);
            }
        }
        return ans;
    }
    // O(sqrt(N))
    // index = [0,N)
    void update(int index, const T& value) {
        if (index < 0 || index > N) return;
        array[index] = value;
        int bi = index / S;
        block[bi] = monoid_id;
        for (int i = bi * S; i < (bi+1)*S; ++i) {
            block[bi] = monoid_op(block[bi], array[i]);
        }
    }
};


#include <iostream>
#include <numeric>

using namespace std;

struct Minimum {
    const long long id = numeric_limits<long long>::max();
    int operator()(const long long& lhs, const long long& rhs) const {
        return min(lhs, rhs);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<long long> array(N);
    for (int i = 0; i < N; ++i) {
        array[i] = (1LL << 31) - 1;
    }

    SqrtDecomposition<long long> solver(array, Minimum());

    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            solver.update(x, y);
        } else if (c == 1) {
            cout << solver.query(x, y+1) << endl;
        } else throw;
    }

    return 0;
}