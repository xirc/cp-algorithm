#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N, M;
vector<string> A, B;

bool solve() {
    assert(M <= N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool match = true;
            for (int k = 0; k < M; ++k) {
                if (i + k >= N) {
                    match = false;
                    break;
                }
                for (int l = 0; l < M; ++l) {
                    if (j + l >= N) {
                        match = false;
                        break;
                    }
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