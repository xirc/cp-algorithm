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

// Length of Vector
double abs(const vector2& a) {
    return a.length();
}
// dot(A,B) = dot(B,A)
// dot(k * A,B) = k * dot(A,B)
// dot(A + B, C) = dot(A, C) + dot(B, C)
double dot(const vector2& a, const vector2& b) {
    return a.x * b.x + a.y * b.y;
}
// Area of parallelogram formed by 'A' and 'B'
// The value will be positive if rotation from A to B is counter-clockwise and negative otherwise.
double cross(const vector2& a, const vector2& b) {
    return a.x * b.y - a.y * b.x;
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

// Intersection of Circles (c1,r1) and (c2, r2)
// return:
//   4) they do not cross (there are 4 common tangent lines)
//   3) they are circumscribed (there are 3 common tanget lines)
//   2) they are intersect (there are 2 common tanget lines)
//   1) a circle is inscribed in another (there are 1 common tanget line)
//   0) a circle includes another (there are no common tanget line)
//   and intersection points (0 ~ 2)
int intersect_cc(vector2 c1, double r1, vector2 c2, double r2, std::vector<vector2>& ans) {
    ans.clear();

    if (r1 < r2) {
        std::swap(c1, c2);
        std::swap(r1, r2);
    }

    int dd = (c1 - c2).length();
    if (dd > r1 + r2) return 4;
    if (EQ(dd, r1 + r2)) {
        auto v = c1 + (c2 - c1).normalized() * r1;
        ans.push_back(v);
        return 3;
    }
    if (dd < r1 - r2) {
        return 0;
    }
    if (EQ(dd, r1 - r2)) {
        auto v = (c2 - c1).normalized() * r1;
        ans.push_back(v);
        return 1;
    }

    double x = (dd * dd + r1 * r1 - r2 * r2) / (2 * dd);
    auto v = (c2 - c1).normalized() * x;
    double y = std::sqrt(std::max(r1 * r1 - x * x, 0.0));
    auto u = (c2 - c1).rotated(M_PI_2).normalized() * y;
    ans.push_back(c1 + v + u);
    ans.push_back(c1 + v - u);
    return 2;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector2 c1, c2;
    double r1, r2;
    cin >> c1.x >> c1.y >> r1;
    cin >> c2.x >> c2.y >> r2;

    vector<vector2> cp;
    int ans = intersect_cc(c1, r1, c2, r2, cp);
    cout << ans << endl;

    return 0;
}