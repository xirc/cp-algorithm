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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<int> cs;
    vector<array<int,3>> qs;

    cin >> N >> Q;
    cs.assign(N, 0);
    qs.assign(Q, { 0, 0, 0 });
    for (auto &c : cs) {
        cin >> c;
        --c;
    }
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qs[i] = { r+1, l, i };
    }
    sort(qs.begin(), qs.end());

    BinaryIndexedTree<int> bit(N, 0);
    vector<int> rightmost(N, -1);
    vector<int> answers(Q, 0);
    int r = 0;
    for (int i = 0; i < Q; ++i) {
        auto tl = qs[i][1], tr = qs[i][0], ti = qs[i][2];
        while (r < tr) {
            int c = cs[r];
            int j = rightmost[c];
            if (j >= 0) bit.combine(j, -1);
            bit.combine(r, 1);
            rightmost[c] = r;
            ++r;
        }
        answers[ti] = bit.fold(tl, tr);
    }

    for (int i = 0; i < Q; ++i) {
        cout << answers[i] << endl;
    }

    return 0;
}