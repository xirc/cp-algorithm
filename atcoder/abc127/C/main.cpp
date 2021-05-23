#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> L, R;

    cin >> N >> M;
    L.assign(M, 0);
    R.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> L[i] >> R[i];
        --L[i], --R[i];
    }

    vector<int> A(N+1, 0);
    for (int i = 0; i < M; ++i) {
        A[L[i]]++;
        A[R[i]+1]--;
    }
    for (int i = 1; i < N; ++i) {
        A[i] += A[i-1];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == M) ++ans;
    }
    cout << ans << endl;

    return 0;
}