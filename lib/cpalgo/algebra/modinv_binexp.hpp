#pragma once

#include "binexp.hpp"


// Modular Multiplicative Inverse
//
// (a ** -1) mod m
//   where `m` is an prime number
// undefined behavior if `m` is not an prime number
//
// Complexity:
//   Time: O(log(m))
//   Space: O(1)
//
// Algorithm:
//   Fermat's little theorem and Binary Exponentation
// { a ** (m - 1) = 1 } mod m
// { a ** (m - 2) = a ** -1 } mod m
//
// NOTE:
//   If `m` is not an prime but `a` and `m` is coprime,
//   there is the Modular Multiplicative Inverse of `a`.
//   Use an another solution using Extended Euclidean Algorithm.
//
//   We can solve it using Euler's theorem and Binary Exponentation, but it might be hard.
//   Because we have to calculate Euler's Totient function that requires prime factorization of `m`.
//   { a ** phi(m) = 1 } mod m
//   { a ** (phi(m) - 1) = a ** -1 } mod m
//     where phi(m) is Euler's Totient function.
//
int64_t modinv_binexp(int64_t a, int64_t m) {
    return binexp<int64_t>(a, m - 2, 1, [&](auto const& lhs, auto const& rhs){
        return lhs * rhs % m;
    });
}
