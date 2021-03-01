#include <bits/stdc++.h>

inline int64_t binary_search(
    std::function<bool(int64_t)> predicate,
    int64_t ng,
    int64_t ok
) {
    assert(!predicate(ng) && predicate(ok));
    while (abs(ok - ng) > 1) {
        auto m = (ok + ng) / 2;
        if (predicate(m)) ok = m;
        else ng = m;
    }
    return ok;
}

using namespace std;
using ll = int64_t;
using ff = long double;

string S;
vector<vector<int>> DP;

int find_index(int M) {
    if (M < 2) return 0;
    int const N = S.size();
    for (int i = 0; i + M <= N; ++i) {
        int sum = 0;
        int maxi = 0;
        for (int j = 0; j < 26; ++j) {
            int l = i > 0 ? DP[i-1][j] : 0;
            int u = DP[i+M-1][j];
            sum += (u - l);
            maxi = max(maxi, u - l);
        }
        assert(sum == M);
        if (maxi * 2 > sum) {
            return i;
        }
    }
    return -1;
}

array<int,2> solve() {
    int const N = S.size();
    DP.assign(N, vector<int>(26, 0));
    DP[0][S[0]-'a'] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 26; ++j) {
            DP[i][j] = DP[i-1][j];
        }
        DP[i][S[i]-'a'] += 1;
    }

    int m = binary_search([&](auto m) { return find_index(m) >= 0; }, N+1, 0);
    if (m <= 1) return { -1, -1 };
    int idx = find_index(m);
    return { idx + 1, idx + m };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    auto ans = solve();
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}