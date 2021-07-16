#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int H, N;
vector<int> A, B;

int solve() {
    vector<int> DP(H + 1, 1e8);
    DP[0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int h = 0; h < H; ++h) {
            int nh = min(H, h + A[i]);
            int c = DP[h] + B[i];
            DP[nh] = min(DP[nh], c);
        }
    }
    return DP[H];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> N;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}