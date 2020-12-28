// https://onlinejudge.u-aizu.ac.jp/challenges/sources/JOI/Final/0600?year=2014

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

int N;
vector<int> A;

// O(N)
bool ok(ll K) {
    ll sum = 0;
    vector<int> rs(2*N, 2*N);
    iterate_with_two_pointers(
        2 * N,
        [&](size_t l, size_t r) {
            return sum < K;
        },
        [&](size_t l, size_t r) {
            sum -= A[l];
        },
        [&](size_t l, size_t r) {
            sum += A[r];
        },
        [&](size_t l, size_t r) {
            if (sum >= K) {
                rs[l] = min(rs[l], (int)r);
            }
        }
    );
    for (int i0 = 0; i0 < N; ++i0) {
        int i1 = rs[i0];
        if (i1 > N + i0) continue;
        int i2 = rs[i1];
        if (i2 > N + i0) continue;
        int i3 = rs[i2];
        if (i3 > N + i0) continue;
        return true;
    }
    return false;
}

ll solve() {
    // make loop
    for (int i = 0; i < N; ++i) {
        A.push_back(A[i]);
    }
    // binary search
    ll l = 0, r = 1e16;
    while (l < r) {
        ll m = (l + r + 1) >> 1;
        if (ok(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}