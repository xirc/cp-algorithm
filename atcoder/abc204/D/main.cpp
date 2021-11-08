#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> T;

int solve() {
    int const M = 2e5;
    vector<bool> DP(2*M, false);
    vector<bool> DPn(2*M, false);
    DP[M] = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2*M; ++j) {
            int p = j - T[i], n = j + T[i];
            if (p >= 0 && DP[p]) {
                DPn[j] = true;
            } else if (n < 2*M && DP[n]) {
                DPn[j] = true;
            } else {
                DPn[j] = false;
            }
        }
        swap(DP, DPn);
    }
    int mini = M;
    for (int i = 0; i < 2*M; ++i) {
        if (DP[i]) {
            mini = min(mini, abs(i-M));
        }
    }
    int const S = accumulate(T.begin(), T.end(), 0, plus<int>());
    return (S + mini) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    T.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    cout << solve() << endl;

    return 0;
}