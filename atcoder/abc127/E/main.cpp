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

template<std::int64_t MOD = 1000000007>
class modint {
    using i64 = std::int64_t;
    i64 x;

public:
    constexpr modint(i64 const& x = 0) noexcept : x(((x % MOD) + MOD) % MOD) {}
    constexpr i64& value() noexcept { return x; }
    constexpr const i64& value() const noexcept { return x; }
    constexpr i64 modulo() const noexcept { return MOD; }
    constexpr modint operator+(modint const& rhs) const noexcept { return modint(*this) += rhs; }
    constexpr modint operator-(modint const& rhs) const noexcept { return modint(*this) -= rhs; }
    constexpr modint operator*(modint const& rhs) const noexcept { return modint(*this) *= rhs; }
    constexpr modint operator/(modint const& rhs) const noexcept { return modint(*this) /= rhs; }
    constexpr modint& operator+=(modint const& rhs) noexcept {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    constexpr modint& operator-=(modint const& rhs) noexcept {
        if (x < rhs.x) x += MOD;
        x -= rhs.x;
        return *this;
    }
    constexpr modint& operator*=(modint const& rhs) noexcept {
        x = x * rhs.x % MOD;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) noexcept {
        // Use Fermat's little theorem & binary exponentiation
        auto exp = MOD - 2;
        while (exp) {
            if (exp & 1) *this *= rhs;
            rhs *= rhs;
            exp >>= 1;
        }
        return *this;
    }
    constexpr modint operator~() const noexcept { return modint(1) / *this; }
    constexpr bool operator==(modint const& rhs) const noexcept { return x == rhs.value(); }
    constexpr bool operator!=(modint const& rhs) const noexcept { return !(*this == rhs); }
    friend constexpr std::ostream& operator<<(std::ostream& os, const modint& x) noexcept { return os << x.value(); }
};


using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;

    ll const MOD = 1e9+7;
    using mod = modint<MOD>;
    mod ans = 0;
    CombinationBasic comb(N * M, MOD);
    for (ll d = 1; d < M; ++d) {
        auto c = comb(N * M - 2, K - 2);
        ans += mod(d) * N * N * (M - d) * c;
    }
    for (ll d = 1; d < N; ++d) {
        auto c = comb(N * M - 2, K - 2);
        ans += mod(d) * M * M * (N - d) * c;
    }
    cout << ans << endl;

    return 0;
}