#include <bits/stdc++.h>

using namespace std;

int D, G;
vector<int> P, C;

int solve() {
    vector<int> DP(1010, -1);
    DP[0] = 0;
    for (int i = 0; i < D; ++i) {
        for (int j = DP.size() - 1; j >= 0; --j) {
            if (DP[j] < 0) continue;
            for (int k = 1; k <= P[i]; ++k) {
                if (j + k >= DP.size()) break;
                int score = k * 100 * (i+1);
                if (k == P[i]) score += C[i];
                DP[j+k] = max(DP[j+k], DP[j] + score);
            }
        }
    }
    for (int i = 0; i < DP.size(); ++i) {
        if (DP[i] >= G) return i;
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> D >> G;
    P.assign(D, 0);
    C.assign(D, 0);
    for (int i = 0; i < D; ++i) {
        cin >> P[i] >> C[i];
    }
    cout << solve() << endl;

    return 0;
}