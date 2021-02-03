#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int W;
int N, K;
vector<int> A, B;

int solve() {
    vector<vector<int>> T(K+1, vector<int>(W+1, 0));
    for (int i = 0; i < N; ++i) {
        for (int k = K; k > 0; --k) {
            for (int w = W; w >= 0; --w) {
                int nw = w + A[i];
                if (nw > W) continue;
                T[k][nw] = max(T[k][nw], T[k-1][w] + B[i]);
            }
        }
    }

    int ans = 0;
    for (int k = 0; k <= K; ++k) {
        for (int w = 0; w <= W; ++w) {
            ans = max(ans, T[k][w]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> W >> N >> K;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}