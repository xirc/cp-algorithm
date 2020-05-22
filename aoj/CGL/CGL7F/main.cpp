#include <bits/stdc++.h>

struct vector2 {
    double x, y;
    vector2() {}
    vector2(double x, double y): x(x), y(y) {}
    vector2& operator+=(const vector2& o) {
        x += o.x;
        y += o.y;
        return *this;
    }
    vector2& operator-=(const vector2& o) {
        x -= o.x;
        y -= o.y;
        return *this;
    }
    vector2& operator*=(const double& o) {
        x *= o;
        y *= o;
        return *this;
    }
    vector2& operator/=(const double& o) {
        x /= o;
        y /= o;
        return *this;
    }
    vector2 operator+(const vector2& o) const {
        return vector2(*this) += o;
    }
    vector2 operator-(const vector2& o) const {
        return vector2(*this) -= o;
    }
    vector2 operator*(const double& o) const {
        return vector2(*this) *= o;
    }
    vector2 operator/(const double& o) const {
        return vector2(*this) *= o;
    }
    double norm() const {
        return x * x + y * y;
    }
    double length() const {
        return std::sqrt(norm());
    }
    vector2 normalized() const {
        return vector2(*this) /= length();
    }
    // Rotate (Counter Clockwise)
    vector2 rotated(double rad) const {
        auto o = vector2(std::cos(rad), std::sin(rad));
        return vector2(
            x * o.x - y * o.y,
            x * o.y + y * o.x
        );
    }
    // Unit Normal Vector (Counter Clockwise)
    vector2 unit_normal() const {
        return rotated(M_PI_2).normalized();
    }
    // Unit Normal Vector (Clockwise)
    vector2 unit_normal_cw() const {
        return rotated(-M_PI_2).normalized();
    }
};
vector2 operator*(const double& o, const vector2& v) {
    return v * o;
}
inline bool operator<(const vector2& lhs, const vector2& rhs) {
    return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
}

static const double EPS = 1e-8;
bool EQ(const double& x, const double& y) {
    return std::abs(x - y) < EPS;
}
bool LQ(const double& x, const double& y) {
    return x < y || EQ(x,y);
}
bool GQ(const double& x, const double& y) {
    return x > y || EQ(x,y);
}

// Find the tangent lines between a point 'P' and a circle 'C'
// return:
//   2) they have 2 tangent lines (2 tangent points)
//   1) a point lies on a circle (1 tangent point)
//   0) a circle includes a point (no tangent point)
//   and tangent points (0 ~ 2 points)
int tangent_on_circle(
    const vector2& c1, const double r1,
    const vector2& p,
    std::vector<vector2>& ans
) {
    ans.clear();
    ans.reserve(2);

    const double dd = (p - c1).length();
    if (dd < r1) {
        return 0;
    }
    if (EQ(dd, r1)) {
        ans.push_back(p);
        return 1;
    }

    double theta = std::acos(r1 / dd);
    auto v = (p - c1).rotated(theta).normalized() * r1;
    auto u = (p - c1).rotated(-theta).normalized() * r1;
    ans.push_back(c1 + v);
    ans.push_back(c1 + u);
    return 2;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector2 p, c1;
    double r1;
    
    cin >> p.x >> p.y;
    cin >> c1.x >> c1.y >> r1;
    vector<vector2> tp;
    int ans = tangent_on_circle(c1, r1, p, tp);
    if (ans == 0 || ans == 1) throw;
    sort(tp.begin(), tp.end());

    cout << fixed << setprecision(6)
        << tp[0].x << " " << tp[0].y << endl
        << tp[1].x << " " << tp[1].y << endl;

    return 0;
}