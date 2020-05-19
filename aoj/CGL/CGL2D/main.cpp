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
// Angle between vectors
double angle(const vector2& a, const vector2& b) {
    return std::acos(dot(a,b) / abs(a) / abs(b));
}

static const double EPS = 1e-8;
bool EQ(const double& x, const double& y) {
    return std::abs(x - y) < EPS;
}

// Is point 'P' on line segment 'A'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
bool is_intersect_sp(const vector2& a1, const vector2& a2, const vector2& p) {
    return abs(a1-p) + abs(p-a2) < abs(a1-a2) + EPS;
}
// Are line segments 'A' and 'B' intersected or not?
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B
bool is_intersect_ss(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    auto ca1 = cross(b2-b1,a1-b1), ca2 = cross(b2-b1,a2-b1);
    auto cb1 = cross(a2-a1,b1-a1), cb2 = cross(a2-a1,b2-a1);
    if (EQ(ca1,0) && EQ(ca1, 0)) {
        return is_intersect_sp(b1, b2, a1)
            || is_intersect_sp(b1, b2, a2)
            || is_intersect_sp(a1, a2, b1)
            || is_intersect_sp(a1, a2, b2);
    }
    return (ca1 * ca2 < EPS) && (cb1 * cb2 < EPS);
}

// Distance between point 'P' and line segment 'A'
double distance_sp(const vector2& a1, const vector2& a2, const vector2& p) {
    if (dot(a2-a1, p-a1) < EPS) return abs(p-a1);
    if (dot(a1-a2, p-a2) < EPS) return abs(p-a2);
    return abs(cross(a2-a1, p-a1)) / abs(a2-a1);
}

// Distance between line segments 'A' and 'B'
double distance_ss(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    if (is_intersect_ss(a1, a2, b1, b2)) {
        return 0;
    }
    double d1 = distance_sp(a1, a2, b1);
    double d2 = distance_sp(a1, a2, b2);
    double d3 = distance_sp(b1, b2, a1);
    double d4 = distance_sp(b1, b2, a2);
    return std::min({ d1, d2, d3, d4 });
}

using namespace std;

double solve(vector2 p0, vector2 p1, vector2 p2, vector2 p3) {
    return distance_ss(p0, p1, p2, p3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        vector2 p0, p1, p2, p3;
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        cout << fixed << setprecision(9) << solve(p0, p1, p2, p3) << endl;
    }

    return 0;
}