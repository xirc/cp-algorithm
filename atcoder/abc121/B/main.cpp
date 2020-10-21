#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, C;
    vector<int> A, B;

    cin >> N >> M >> C;
    B.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    int ans = 0;
    for (int tt = 0; tt < N; ++tt) {
        A.assign(M, 0);
        for (int i = 0; i < M; ++i) {
            cin >> A[i];
        }
        int score = C;
        for (int i = 0; i < M; ++i) {
            score += A[i] * B[i];
        }
        if (score > 0) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}