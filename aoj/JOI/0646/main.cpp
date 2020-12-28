// https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Prelim/0646?year=2018

#include <bits/stdc++.h>


inline void iterate_with_two_pointers(
    size_t N,
    // O(K), [l,r), l = [0,N), r = [0, N)
    std::function<bool(size_t, size_t)> should_move_right,
    // O(K), [l,r), l = [0,N), r = [0, N)
    std::function<void(size_t, size_t)> pre_move_left,
    // O(K), [l,r), l = [0,N), r = [0, N)
    std::function<void(size_t, size_t)> pre_move_right,
    // O(K), [l,r), l = [0,N), r = [0, N)
    std::function<void(size_t, size_t)> update
) {
    size_t r = 0;
    for (size_t l = 0; l < N; ++l) {
        while (r < N && should_move_right(l,r)) {
            pre_move_right(l, r);
            ++r;
        }
        update(l, r);
        if (l == r) ++r;
        else pre_move_left(l, r);
    }
}


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
        int n = 0,
        T id = T(),
        F plus = std::plus<T>(),
        F minus = std::minus<T>()
    )
        : N(n+1)
        , bit(n+1, id)
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
    // Sum of array[0..index)
    // O(logN)
    // index = [0,N]
    T sum(int index) {
        if (index < 0 || index > N) throw;
        T ans = id;
        for (; index > 0; index -= index & -index) {
            ans = plus(ans, bit[index]);
        }
        return ans;
    }
    // Sum of array[l, r)
    // O(logN)
    T sum(int l, int r) {
        if (l > r) throw;
        return minus(sum(r), sum(l));
    }
    // Add value to array[index]
    // O(logN)
    // index = [0,N)
    void add(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        for (++index; index < N; index += index & -index) {
            bit[index] = plus(bit[index], value);
        }
    }
    // Set value to array[index]
    // O(logN)
    // index = [0,N)
    void set(int index, const T& value) {
        if (index < 0 || index >= N) throw;
        T new_value = minus(value, sum(index, index+1));
        add(index, new_value);
    }
};


using namespace std;
using ll = long long;

int N, K;
ll L;
vector<int> A;

bool pass(int X) {
    X = min(X, N);
    BinaryIndexedTree<int> bit(N+1);
    ll count = 0;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return bit.sum(X+1) < K;
        },
        [&](size_t l, size_t r) {
            bit.add(A[l], -1);
        },
        [&](size_t l, size_t r) {
            bit.add(A[r], +1);
        },
        [&](size_t l, size_t r) {
            if (bit.sum(X+1) >= K) {
                count += (N - r + 1);
            }
        }
    );
    return count >= L;
}

int solve() {
    ll l = 1, r = 1e8;
    while (l < r) {
        ll m = (l + r) / 2;
        if (pass(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> L;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}