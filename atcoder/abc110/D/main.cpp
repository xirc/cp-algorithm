#include <bits/stdc++.h>

// Binomial Coefficient (Combination)
// Time: O(N)
// Memory: O(N)
// N <= 10^7
class Combination {
    int N;
    long long MOD;
    std::vector<long long> factorial, inverse, factorial_inverse;

public:
    // O(N)
    // MOD should be a prime number
    Combination(int N = 10000000, long long MOD = 1000000007) {
        if (N < 2) throw;
        this->N = N;
        this->MOD = MOD;
        build();
    }

    // nCk
    // O(1)
    long long operator()(int n, int k) {
        if (n < 0 || k < 0) throw;
        if (n < k || n >= N) throw;
        return factorial[n] * (factorial_inverse[k] * factorial_inverse[n - k] % MOD) % MOD;
    }

    // O(1)
    int size() {
        return N;
    }

private:
    void build() {
        factorial.assign(N, 0);
        factorial_inverse.assign(N, 0);
        inverse.assign(N, 0);
        factorial[0] = factorial[1] = 1;
        factorial_inverse[0] = factorial_inverse[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;
        for (int i = 2; i < N; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
            inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
            factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
        }
    }
};

// Prime Factorization
// Time: O(sqrt(N))
// Memory: O(1)
std::unordered_map<long long, int> prime_factorization(long long M) {
    std::unordered_map<long long, int> factors;
    long long mm = M;
    for (long long i = 2; i * i < M; ++i) {
        while (mm % i == 0) {
            ++factors[i];
            mm /= i;
        }
    }
    if (mm > 1) {
        ++factors[mm];
    }
    return factors;
}


using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
Combination comb(200000, MOD);

ll solve(int N, int M) {
    auto factors = prime_factorization(M);
    ll ans = 1;
    for (auto f : factors) {
        auto e = f.second;
        ans *= comb(e + N - 1, e);
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    cout << solve(N, M) << endl;

    return 0;
}