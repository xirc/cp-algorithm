#include <bits/stdc++.h>

template <class T = int64_t>
class BinaryIndexedTree {
public:
    using F = std::function<T(T const&, T const&)>;

protected:
    size_t N;
    std::vector<T> bit;
    T empty;
    F combine_func;
    F remove_func;

public:
    // Time: O(N)
    BinaryIndexedTree(
        size_t n = 0,
        T empty = T(),
        F combine = std::plus<T>(),
        F remove = std::minus<T>()
    )
        : N(n+1)
        , bit(n+1, empty)
        , empty(empty)
        , combine_func(combine)
        , remove_func(remove)
    {
        // Do nothing
    }
    // Time: O(1)
    size_t size() const {
        return N - 1;
    }
    // Fold elements of array[0..index)
    // index = [0,N]
    // Time: O(logN)
    T fold(size_t index) const {
        if (index > N) throw std::out_of_range("index");
        T ans = empty;
        for (; index > 0; index -= index & -index) {
            ans = combine_func(ans, bit[index]);
        }
        return ans;
    }
    // Fold elements of array[l, r)
    // l = [0,N]
    // r = [l,N]
    // Time: O(logN)
    T fold(size_t l, size_t r) const {
        if (l > N) throw std::out_of_range("l");
        if (r < l || r > N) throw std::out_of_range("r");
        return remove_func(fold(r), fold(l));
    }
    // Combine given value to array[index]
    // index = [0,N)
    // Time: O(logN)
    void combine(size_t index, T const& value) {
        if (index >= N) throw std::out_of_range("index");
        for (++index; index < N; index += index & -index) {
            bit[index] = combine_func(bit[index], value);
        }
    }
};


using namespace std;
using ll = int64_t;
using ff = long double;

// inputs
int N, K;
vector<int> L, R;

// solution
int const MOD = 998244353;
ll plusf(ll lhs, ll rhs) {
    ll value = (lhs + rhs) % MOD;
    if (value < 0) value += MOD;
    return value;
}
ll minusf(ll lhs, ll rhs) {
    ll value = (lhs - rhs) % MOD;
    if (value < 0) value += MOD;
    return value;
}
ll solve() {
    BinaryIndexedTree<> bit(N, 0, plusf, minusf);
    bit.combine(0, 1);
    bit.combine(1, -1);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            int l = i + L[j], r = i + R[j] + 1;
            if (l >= N) continue;
            r = min(r, N);
            ll p = bit.fold(i+1);
            bit.combine(l, p);
            bit.combine(r, -p);
        }
    }
    return bit.fold(N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    L.assign(K, 0);
    R.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> L[i] >> R[i];
    }
    cout << solve() << endl;

    return 0;
}