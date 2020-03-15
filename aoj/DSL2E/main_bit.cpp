// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E

#include <vector>
#include <functional>

// BinaryIndexedTree
// Memory O(N)
// Update O(logN)
// Query O(logN)
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
        : N(n + 1)
        , bit(n + 1, id)
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
    // Add value to array[l,r)
    // O(logN)
    // l = [0,N)
    // r = [0,N]
    void add(int l, int r, const T& value) {
        if (l > r) throw;
        if (l < 0 || l >= N) throw;
        if (r < 0 || r > N) throw;
        add(l, value);
        if (r < N) add(r, minus(id, value));
    }
    // Get value at array[index]
    // O(logN)
    // index = [0,N)
    T get(int index) {
        if (index < 0 || index >= N) throw;
        T ans = id;
        for (++index; index > 0; index -= index & -index) {
            ans = plus(ans, bit[index]);
        }
        return ans;
    }

protected:
    // index = [0,N)
    void add(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        for (++index; index < N; index += index & -index) {
            bit[index] = plus(bit[index], value);
        }
    }
};


#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    BinaryIndexedTree<long long> bit(N);
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
            cout << bit.get(t) << endl;
        } else throw;
    }

    return 0;
}