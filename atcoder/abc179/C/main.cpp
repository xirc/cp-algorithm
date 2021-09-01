#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(int const N) {
    ll num_patterns = 0;
    for (int A = 1; A < N; ++A) {
        num_patterns += (N - 1) / A;
    }
    return num_patterns;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}