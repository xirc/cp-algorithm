#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> B;

    cin >> N;
    B.assign(N-1, 0);
    for (auto &b : B) cin >> b;

    vector<int> A(N, 0);
    A[0] = B[0];
    A[N-1] = B[N-2];
    for (int i = 1; i < N - 1; ++i) {
        A[i] = min(B[i], B[i-1]);
    }
    int ans = accumulate(A.begin(), A.end(), 0, plus<int>());
    cout << ans << endl;

    return 0;
}