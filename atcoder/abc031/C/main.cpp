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
    for (auto &a : A) cin >> a;

    int ans = -3000;  // > 50 * -50
    for (int i = 0; i < N; ++i) {
        int best_aoki = -3000;
        int score_taka = -3000;
        for (int j = i + 1; j < N; j += 1) {
            int aoki = 0, taka = 0;
            for (int k = i; k <= j; ++k) {
                if ((k - i) % 2 == 0) {
                    taka += A[k];
                } else {
                    aoki += A[k];
                }
            }
            if (aoki > best_aoki) {
                best_aoki = aoki;
                score_taka = taka;
            }
        }
        for (int j = i - 1; j >= 0; j -= 1) {
            int aoki = 0, taka = 0;
            for (int k = j; k <= i; ++k) {
                if ((k - j) % 2 == 0) {
                    taka += A[k];
                } else {
                    aoki += A[k];
                }
            }
            if (aoki >= best_aoki) {
                best_aoki = aoki;
                score_taka = taka;
            }
        }
        ans = max(ans, score_taka);
    }
    cout << ans << endl;

    return 0;
}