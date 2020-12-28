// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_C

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


using namespace std;
using ll = long long;

int N, Q;
vector<int> A;

ll solve(ll X) {
    ll sum = 0;
    ll ans = 0;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return sum + A[r] <= X;
        },
        [&](size_t l, size_t r) {
            sum -= A[l];
        },
        [&](size_t l, size_t r) {
            sum += A[r];
        },
        [&](size_t l, size_t r) {
            ans += ll(r - l);
        }
    );
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < Q; ++i) {
        ll X;
        cin >> X;
        cout << solve(X) << endl;
    }

    return 0;
}