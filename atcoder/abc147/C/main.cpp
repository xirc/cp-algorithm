#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<vector<array<int,2>>> A;

int solve() {
    int ans = 0;
    int const S = 1 << N;
    for (int s = 0; s < S; ++s) {
        bitset<15> bs(s);
        bool pass = true;
        for (int i = 0; i < N && pass; ++i) {
            if (!bs[i]) continue;
            for (int j = 0; j < A[i].size() && pass; ++j) {
                int x = A[i][j][0], y = A[i][j][1];
                if (bs[x] != y) {
                    pass = false;
                }
            }
        }
        if (pass) {
            ans = max(ans, (int)bs.count());
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, {});
    for (int i = 0; i < N; ++i) {
        int m;
        cin >> m;
        A[i].assign(m, { 0, 0 });
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j][0] >> A[i][j][1];
            --A[i][j][0];
        }
    }
    cout << solve() << endl;

    return 0;
}