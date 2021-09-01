#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll solve(int const N) {
    vector<bool> is_prime(N + 1, true);
    vector<int> patterns(N + 1, 1);
    is_prime[0] = is_prime[1] = false;
    patterns[0] = 0;
    for (int p = 2; p <= N; ++p) {
        if (!is_prime[p]) continue;
        patterns[p] *= 2;
        for (int q = 2 * p; q <= N; q += p) {
            is_prime[q] = false;
            int e = 0;
            int m = q;
            while (m % p == 0) {
                ++e;
                m /= p;
            }
            patterns[q] *= e + 1;
        }
    }
    ll all_patterns = 0;
    for (int c = 1; c <= N; ++c) {
        all_patterns += patterns[N - c];
    }
    return all_patterns;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}