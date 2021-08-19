#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A, B;

    cin >> N;
    A.assign(N, 0);
    B.assign(N ,0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    if (N % 2 == 0) {
        int cmin_x2 = (A[N/2-1] + A[N/2]);
        int cmax_x2 = (B[N/2-1] + B[N/2]);
        ans = cmax_x2 - cmin_x2 + 1;
    } else {
        int cmin = A[(N+1)/2-1];
        int cmax = B[(N+1)/2-1];
        ans = cmax - cmin + 1;
    }
    cout << ans << endl;

    return 0;
}