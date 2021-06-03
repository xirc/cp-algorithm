#include <bits/stdc++.h>

template<std::uint64_t MOD>
class modint {
    using u64 = std::uint64_t;
    u64 x;

public:
    constexpr modint(u64 const& x = 0) noexcept : x(x % MOD) {}
    constexpr u64& value() noexcept { return x; }
    constexpr const u64& value() const noexcept { return x; }
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
        u64 exp = MOD - 2;
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

const int MOD = 1e9 + 7;
using mint = modint<MOD>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    for (auto &s : S) cin >> s;
    for (auto &t : T) cin >> t;
    vector<vector<mint>> DP(N+1, vector<mint>(M+1, 0));

    DP[0][0] = 1;
    for (int s = 0; s < N + 1; ++s) {
        for (int t = 0; t < M + 1; ++t) {
            if (s > 0) DP[s][t] += DP[s-1][t];
            if (t > 0) DP[s][t] += DP[s][t-1];
            if (s > 0 && t > 0 && S[s-1] != T[t-1]) DP[s][t] -= DP[s-1][t-1];
        }
    }
    cout << DP[N][M] << endl;

    return 0;
}