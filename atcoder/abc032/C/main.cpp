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

int N, K;
vector<int> S;

int solve() {
    for (int i = 0; i < N; ++i) {
        if (S[i] == 0) return N;
    }

    int ans = 0;
    ll pr = 1;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return pr * S[r] <= K;
        },
        [&](size_t l, size_t r) {
            pr /= S[l];
        },
        [&](size_t l, size_t r) {
            pr *= S[r];
        },
        [&](size_t l, size_t r) {
            ans = max(ans, int(r - l));
        }
    );
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    S.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}