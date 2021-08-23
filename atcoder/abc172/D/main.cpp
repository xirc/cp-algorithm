#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int count(int N, int b) {
    int c = 0;
    while (N % b == 0) {
        ++c;
        N /= b;
    }
    return c;
}

ll solve(int const N) {
    vector<int> divisors(N + 1, 1);
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p <= N; ++p) {
        if (!is_prime[p]) continue;
        divisors[p] = 2;
        for (int q = 2 * p; q <= N; q += p) {
            is_prime[q] = false;
            divisors[q] *= count(q, p) + 1;
        }
    }
    ll ans = 0;
    for (int x = 1; x <= N; ++x) {
        ans += ll(x) * divisors[x];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}