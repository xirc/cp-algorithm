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

static const double EPS = 1e-8;
bool EQ(const double& x, const double& y) {
    return std::abs(x - y) < EPS;
}
// Is point 'P' on line segment ('A','B')
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
bool is_point_on_line_segment(const vector2& a, const vector2& b, const vector2& p) {
    return abs(a-p) + abs(p-b) < abs(a-b) + EPS;
}
// Are line segments 'A' and 'B' intersected or not?
bool is_intersect_line_segments(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    auto ca1 = cross(b2-b1,a1-b1), ca2 = cross(b2-b1,a2-b1);
    auto cb1 = cross(a2-a1,b1-a1), cb2 = cross(a2-a1,b2-a1);
    if (EQ(ca1,0) && EQ(ca1, 0)) {
        return is_point_on_line_segment(b1, b2, a1)
            || is_point_on_line_segment(b1, b2, a2)
            || is_point_on_line_segment(a1, a2, b1)
            || is_point_on_line_segment(a1, a2, b2);
    }
    return (ca1 * ca2 < EPS) && (cb1 * cb2 < EPS);
}

using namespace std;

bool solve(vector2 p0, vector2 p1, vector2 p2, vector2 p3) {
    return is_intersect_line_segments(p0, p1, p2, p3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        vector2 p0, p1, p2, p3;
        cin >> p0.x >> p0.y >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
        cout << (solve(p0, p1, p2, p3) ? "1" : "0") << endl;
    }

    return 0;
}