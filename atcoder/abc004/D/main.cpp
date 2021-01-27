#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

const int inf = 1e8;
const int N = 2000;
const int M = 1000;
const int KR = 1, KG = 2, KB = 3;
vector<int> AR(N, 0), AG(N, 0), AB(N, 0);

int solve(int R, int G, int B) {
    for (int i = 0; i < N; ++i) {
        int j = i - M;
        for (int k = 0; k < R; ++k) {
            AR[i] += abs(-100 - (j+k));
        }
        for (int k = 0; k < G; ++k) {
            AG[i] += abs(j+k);
        }
        for (int k = 0; k < B; ++k) {
            AB[i] += abs(100 - (j+k));
        }
    }
    for (int i = 1; i < N; ++i) {
        AR[i] = min(AR[i], AR[i-1]);
    }
    for (int i = N-2; i >= 0; --i) {
        AB[i] = min(AB[i], AB[i+1]);
    }

    int ans = inf;
    for (int i = R; i + G < N; ++i) {
        int res = AR[i-R] + AG[i] + AB[i+G];
        ans = min(ans, res);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int R, G, B;
    cin >> R >> G >> B;
    cout << solve(R, G, B) << endl;

    return 0;
}