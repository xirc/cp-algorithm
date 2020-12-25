#pragma once

#include <vector>
#include <array>
#include <complex>
#include <algorithm>

// Area of Union Rectangles
// O (N^2)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/4/DSL_4_A
template <class T = long long>
T union_rectangle_area(const std::vector<std::array<std::complex<T>,2>>& rs) {
    if (rs.size() == 0) return T();

    enum code { LL = 0, UR = 1 };
    struct event {
        size_t index;
        code type;
    };
    const auto less_x = [&](const event& l, const event& r) {
        return rs[l.index][l.type].real() < rs[r.index][r.type].real();
    };
    const auto less_y = [&](const event& l, const event& r) {
        return rs[l.index][l.type].imag() < rs[r.index][r.type].imag();
    };

    std::vector<event> ves, hes;
    for (size_t i = 0; i < rs.size(); ++i) {
        ves.push_back({ i, LL });
        ves.push_back({ i, UR });
        hes.push_back({ i, LL });
        hes.push_back({ i, UR });
    }
    std::sort(ves.begin(), ves.end(), less_x);
    std::sort(hes.begin(), hes.end(), less_y);

    const int N = rs.size(), E = rs.size() * 2;
    T ans = 0;
    std::vector<bool> inset(N, false);
    inset[ves[0].index] = true;
    // Vertical Sweep Line
    for (
        int i = 1;
        i < E;
        inset[ves[i].index] = (ves[i].type == LL), ++i
    ) {
        auto ux = rs[ves[i].index][ves[i].type].real();
        auto lx = rs[ves[i-1].index][ves[i-1].type].real();
        auto dx = ux - lx;
        if (dx == 0) {
            continue;
        }

        // Horizontal Sweep Line
        int count = 0;
        T ly;
        for (int j = 0; j < E; ++j) {
            if (!inset[hes[j].index]) continue;
            if (hes[j].type == LL) {
                if (count == 0) {
                    ly = rs[hes[j].index][hes[j].type].imag();
                }
                ++count;
            } else {
                --count;
                if (count == 0) {
                    auto uy = rs[hes[j].index][hes[j].type].imag();
                    auto dy = uy - ly;
                    ans += dx * dy;
                }
            }
        }
    }

    return ans;
}