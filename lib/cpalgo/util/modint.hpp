#pragma once

#include <cstdint>
#include <iostream>


/**
 * Arithmetic in Modulo
 * 
 * - Modulo should be a prime number
 * - addition (+, +=)
 * - subtraction (-, -=)
 * - multiplication (*, *=)
 * - division (/, /=)
 * - inverse (~)
 * - compare (==, !=)
 * - ostream (<<)
 * 
 * Verified:
 * - [E - Cell Distance](https://atcoder.jp/contests/abc127/tasks/abc127_e)
 * 
 */
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