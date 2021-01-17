#include <bits/stdc++.h>

class Combination {
    size_t N;
    uint64_t MOD;
    std::vector<uint64_t> factorial, inverse, factorial_inverse;

public:
    // O(N)
    // MOD should be a prime number
    Combination(
        size_t const N = 10000000,
        uint64_t const MOD = 1000000007
    )
    {
        build(N, MOD);
    }
    // Time: O(N)
    void build(size_t const N, uint64_t const MOD) {
        this->N = N;
        this->MOD = MOD;

        factorial.assign(N, 0);
        factorial_inverse.assign(N, 0);
        inverse.assign(N, 0);
        factorial[0] = factorial[1] = 1;
        factorial_inverse[0] = factorial_inverse[1] = 1;
        inverse[0] = 0;
        inverse[1] = 1;
        for (size_t i = 2; i < N; ++i) {
            factorial[i] = factorial[i-1] * i % MOD;
            inverse[i] = MOD - inverse[MOD % i] * (MOD / i) % MOD;
            factorial_inverse[i] = factorial_inverse[i-1] * inverse[i] % MOD;
        }
    }
    // nCk
    // Time: O(1)
    uint64_t operator()(size_t const n, size_t const k) const {
        if (k > n) throw std::out_of_range("k");
        if (n >= N) throw std::out_of_range("n");
        return factorial[n] * (factorial_inverse[k] * factorial_inverse[n - k] % MOD) % MOD;
    }
    // Time: O(1)
    size_t size() const {
        return N;
    }
};

inline std::vector<uint64_t> prime_factorization(uint64_t M) {
    std::vector<uint64_t> factors;
    for (uint64_t i = 2; i * i <= M; ++i) {
        while (M % i == 0) {
            factors.push_back(i);
            M /= i;
        }
    }
    if (M > 1) {
        factors.push_back(M);
    }
    return factors;
}


using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
Combination comb(200000, MOD);

ll solve(int N, int M) {
    auto factors = prime_factorization(M);

    map<unsigned long long, int> counter;
    for (auto f : factors) {
        ++counter[f];
    }

    ll ans = 1;
    for (auto f : counter) {
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