#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int X) {
    int const N = 200;
    for (int i = 1; i < N; ++i) {
        if (ll(i) * i * i * i == X) {
            return i;
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;
    cout << solve(X) << endl;

    return 0;
}