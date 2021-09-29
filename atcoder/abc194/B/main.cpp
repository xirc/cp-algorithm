#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    int mini = 1e6;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int t = (i == j) ? (A[i] + B[j]) : max(A[i], B[j]);
            mini = min(mini, t);
        }
    }
    cout << mini << endl;

    return 0;
}