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

const ll MOD = 1e9+7;
int N, M;
vector<int> F;

ll solve() {
    set<int> fs;
    vector<int> DP(N+1, 0);
    // ACC[i] = DP[i] + DP[i-1] + ... + DP[1] + DP[0]
    vector<int> ACC(N+1, 0);
    DP[0] = ACC[0] = 1;
    iterate_with_two_pointers(
        N,
        [&](size_t l, size_t r) {
            return fs.count(F[r]) == 0;
        },
        [&](size_t l, size_t r) {
            fs.erase(F[l]);
        },
        [&](size_t l, size_t r) {
            fs.insert(F[r]);
            // DP[r+1] = DP[l] + DP[l+1], ... DP[r]
            DP[r+1] = (ACC[r] - (l > 0 ? ACC[l-1] : 0) + MOD) % MOD;
            ACC[r+1] = (DP[r+1] + ACC[r]) % MOD;
        },
        [&](size_t l, size_t r) {
            // Do nothing
        }
    );
    return DP[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    F.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> F[i];
    }
    cout << solve() << endl;

    return 0;
}