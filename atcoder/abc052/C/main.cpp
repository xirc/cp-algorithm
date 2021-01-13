#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll const MOD = 1e9+7;
int const M = 1e3+1;

set<int> seive() {
    vector<bool> is_prime(M, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= M; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j < M; j += i) {
            is_prime[j] = false;
        }
    }

    set<int> primes;
    for (int i = 2; i < M; ++i) {
        if (is_prime[i]) {
            primes.insert(i);
        }
    }
    return primes;
}

ll solve(int N) {
    auto primes = seive();
    vector<int> factors(M, 0);
    for (int i = N; i >= 2; --i) {
        int v = i;
        for (auto p : primes) {
            while (v % p == 0) {
                v /= p;
                ++factors[p];
            }
        }
    }

    ll ans = 1;
    for (int i = 0; i < M; ++i) {
        ans = (ans * (factors[i]+1)) % MOD;
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