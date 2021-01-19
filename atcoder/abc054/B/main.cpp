#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<string> A, B;

bool solve() {
    assert(M <= N);
    for (int i = 0; i < N; ++i) {
        if (i + M - 1 >= N) continue;
        for (int j = 0; j < N; ++j) {
            if (j + M - 1 >= N) continue;
            bool match = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (A[i+k][j+l] != B[k][l]) {
                        match = false;
                        break;
                    }
                }
            }
            if (match) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    B.assign(M, "");
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}