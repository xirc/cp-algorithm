#include <bits/stdc++.h>

using namespace std;
using tile = array<array<int, 2>, 2>;

bool solve(int N, int M, vector<tile> const& A) {
    if (M % 2) return false;

    bool has_diag = false;
    for (int i = 0; i < N; ++i) {
        auto const& tile = A[i];
        if (tile[0][1] == tile[1][0]) {
            has_diag = true;
        }
    }
    if (!has_diag) return false;
    if (M == 2) return true;

    for (auto const& t1 : A) {
        for (auto const& t2 : A) {
            if (t1[0][1] != t2[1][0]) continue;
            if (t1[1][0] != t2[0][1]) continue;
            if (t1[0][0] != t2[0][0]) continue;
            if (t1[1][1] != t2[1][1]) continue;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, M;
    vector<tile> A;

    cin >> T;

    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> M;
        A.assign(N, {});
        for (int i = 0; i < N; ++i) {
            auto& tile = A[i];
            cin >> tile[0][0] >> tile[0][1];
            cin >> tile[1][0] >> tile[1][1];
        }
        auto ans = solve(N, M, A) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}