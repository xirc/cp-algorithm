#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M, P, Q, R;
vector<int> xs, ys, zs;

int solve() {
    int const L = 1 << N;
    int ans = 0;
    for (int s = 0; s < L; ++s) {
        bitset<18> bs(s);
        if (bs.count() > P) continue;
        vector<int> A(M, 0);
        for (int i = 0; i < R; ++i) {
            int x = xs[i], y = ys[i], z = zs[i];
            if (bs[x]) {
                A[y] += z;
            }
        }
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        int la = 0;
        for (int i = 0; i < Q; ++i) {
            la += A[i];
        }
        ans = max(ans, la);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> P >> Q >> R;
    xs.assign(R, 0);
    ys.assign(R, 0);
    zs.assign(R, 0);
    for (int i = 0; i < R; ++i) {
        cin >> xs[i] >> ys[i] >> zs[i];
        --xs[i], --ys[i];
    }
    cout << solve() << endl;

    return 0;
}