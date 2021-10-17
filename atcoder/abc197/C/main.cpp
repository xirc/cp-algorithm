#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (auto &v : A) cin >> v;

    int ans = numeric_limits<int>::max();
    int const M = 1 << N;
    for (int s = 0; s < M; ++s) {
        int gs = 0;
        int ls = 0;
        for (int i = 0; i < N; ++i) {
            int f = (s >> i) & 1;
            if (f) {
                gs ^= ls;
                ls = 0;
            }
            ls |= A[i];
        }
        gs ^= ls;
        ans = min(ans, gs);
    }
    cout << ans << endl;

    return 0;
}