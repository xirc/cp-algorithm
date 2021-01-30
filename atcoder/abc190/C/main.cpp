#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, K;
    vector<int> A, B;
    vector<int> C, D;

    cin >> N >> M;
    A.assign(M, 0);
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    cin >> K;
    C.assign(K, 0);
    D.assign(K, 0);
    for (int i = 0; i < K; ++i) {
        cin >> C[i] >> D[i];
        --C[i], --D[i];
    }

    int ans = 0;
    int L = 1 << K;
    for (int s = 0; s < L; ++s) {
        bitset<16> bs(s);
        vector<int> ps(N, false);
        for (int i = 0; i < K; ++i) {
            if (bs[i]) {
                ps[D[i]] = true;
            } else {
                ps[C[i]] = true;
            }
        }
        int cc = 0;
        for (int i = 0; i < M; ++i) {
            if (ps[A[i]] && ps[B[i]]) ++cc;
        }
        ans = max(ans, cc);
    }
    cout << ans << endl;

    return 0;
}