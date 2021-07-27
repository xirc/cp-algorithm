#include <bits/stdc++.h>

class CombinationBasic {
    size_t N;
    uint64_t MOD;
    std::vector<uint64_t> factorial, inverse, factorial_inverse;

public:
    // Time: O(N)
    // MOD should be a prime number
    CombinationBasic(
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
    // n = [0,N), k = [0,n]
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

using namespace std;
using ll = int64_t;
using ff = long double;

int const MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    CombinationBasic comb(1000000, MOD);

    int N, K;
    cin >> N >> K;

    int ans = 0;
    for (int z = 0; z <= min(K, N-1); ++z) {
        // (n-z)H(z)
        ans += comb(N, z) * comb(N - 1, z) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
