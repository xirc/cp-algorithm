#include <bits/stdc++.h>

// Area of Union Rectangles
// O (N^2)
template <class T = long long>
T union_rectangle_area(const std::vector<std::array<std::complex<T>,2>>& rs) {
    if (rs.size() == 0) return T();

    enum code { LL = 0, UR = 1 };
    struct event {
        int index;
        code type;
    };
    const auto less_x = [&](const event& l, const event& r) {
        return rs[l.index][l.type].real() < rs[r.index][r.type].real();
    };
    const auto less_y = [&](const event& l, const event& r) {
        return rs[l.index][l.type].imag() < rs[r.index][r.type].imag();
    };

    std::vector<event> ves, hes;
    for (int i = 0; i < rs.size(); ++i) {
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


using namespace std;

using vector2 = complex<long long>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<array<vector2,2>> rs(N);
    for (int i = 0; i < N; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rs[i][0] = vector2(x1, y1);
        rs[i][1] = vector2(x2, y2);
    }
    auto ans = union_rectangle_area(rs);
    cout << ans << endl;

    return 0;
}