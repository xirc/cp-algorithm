#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll factorial(int n) {
    ll value = 1;
    for (int i = 2; i <= n; ++i) {
        value *= i;
    }
    return value;
}

ll comb(int n, int k) {
    assert(n >= k);
    return factorial(n) / factorial(k) / factorial(n - k);
}

ll circle(int n) {
    return factorial(n - 1);
}

ll solve(int n) {
    assert(n % 2 == 0);
    return comb(n, n / 2) / 2 * circle(n / 2) * circle(n / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}