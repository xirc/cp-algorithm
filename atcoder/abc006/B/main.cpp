#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int const MOD = 1e4 + 7;
    int N;
    cin >> N;
    vector<int> A(N, 0);
    if (N >= 3) {
        A[2] = 1;
    }
    for (int i = 3; i < N; ++i) {
        A[i] = (A[i-1] + A[i-2] + A[i-3]) % MOD;
    }
    cout << A[N-1] << endl;

    return 0;
}