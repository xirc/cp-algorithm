#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 2e9;
    int i = 0, j = 0;
    while (i < N && j < M) {
        ans = min(ans, abs(A[i] - B[j]));
        if (A[i] < B[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    cout << ans << endl;

    return 0;
}