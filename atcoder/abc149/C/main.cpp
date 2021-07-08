#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;

    int const N = 1e6;
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (!is_prime[i]) continue;
        for (int j = 2 * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
    for (int i = X; i < N; ++i) {
        if (is_prime[i]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}