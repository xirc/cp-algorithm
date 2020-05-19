#pragma once

#include <cmath>
#include <algorithm>
#include <vector>

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

// Scalar Projection of 'A' onto 'B'
double projection(const vector2& a, const vector2& b) {
    return dot(a,b) / abs(b);
}
// Vector Projection of 'A' onto 'B'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
vector2 projectionv(const vector2& a, const vector2& b) {
    return projection(a, b) * b.normalized();
}
// Vector Rejection of 'A' from 'B'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
vector2 rejectionv(const vector2& a, const vector2& b) {
    return a - projectionv(a, b);
}

static const double EPS = 1e-8;
bool EQ(const double& x, const double& y) {
    return std::abs(x - y) < EPS;
}

// Are line 'A' and 'B' orthogonal or not?
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
bool is_orthogonal(const vector2& a, const vector2& b) {
    return EQ(dot(a, b), 0.0);
}
// Are line 'A' and 'B' parallel or not?
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
bool is_parallel(const vector2& a, const vector2& b) {
    return EQ(cross(a,b), 0.0);
}

// Is point 'P' on line 'A'
bool is_intersect_lp(const vector2& a1, const vector2& a2, const vector2& p) {
    return EQ(cross(a2-a1,p), 0.0);
}
// Is point 'P' on line segment 'A'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
bool is_intersect_sp(const vector2& a1, const vector2& a2, const vector2& p) {
    return abs(a1-p) + abs(p-a2) < abs(a1-a2) + EPS;
}
// Are lines 'A' and 'B' intersected or not?
bool is_intersect_ll(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    auto a = a2 - a1, b = b2 - b1;
    return !EQ(cross(a,b), 0.0);
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
// Are line 'A' and line segment 'B' intersected or not?
bool is_intersect_ls(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    const auto cb1 = cross(a2 - a1, b1 - a1);
    const auto cb2 = cross(a2 - a1, b2 - a1);
    return cb1 * cb2 < EPS;
}

// Distance between point 'P' and line 'A'
double distance_lp(const vector2& a1, const vector2& a2, const vector2& p) {
    return abs(rejectionv(a2 - a1, p));
}
// Distance between point 'P' and line segment 'A'
double distance_sp(const vector2& a1, const vector2& a2, const vector2& p) {
    if (dot(a2-a1, p-a1) < EPS) return abs(p-a1);
    if (dot(a1-a2, p-a2) < EPS) return abs(p-a2);
    return abs(cross(a2-a1, p-a1)) / abs(a2-a1);
}
// Distance between lines 'A' and 'B'
double distance_ll(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    if (is_intersect_ll(a1, a2, b1, b2)) {
        return 0;
    }
    return distance_lp(a1, a2, b1);
}
// Distance between line segments 'A' and 'B'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D
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
// Distance between line 'A' and line segment 'B'
double distance_ls(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    if (is_intersect_ls(a1, a2, b1, b2)) {
        return 0;
    }
    double d1 = distance_lp(a1, a2, b1);
    double d2 = distance_lp(a1, a2, b2);
    return std::min(d1, d2);
}

// Intersection Point of lines 'A' and 'B'
vector2 intersection_ll(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    auto a = a2 - a1, b = b2 - b1;
    return a1 + a * cross(b, b1-a1) / cross(b, a);
}
// Intersection Point of line segments 'A' and 'B'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
vector2 intersection_ss(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    double d1 = abs(cross(b2 - b1, a1-b1));
    double d2 = abs(cross(b2 - b1, a2-b1));
    double t = d1 / (d1 + d2);
    return a1 + (a2 - a1) * t;
}

// Area of Polygon (can handle non-Convex)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
double polygon_area(const std::vector<vector2>& G) {
    // The coordinates of points are given in the order of counter-clockwise visit of them.
    double ans = 0;
    for (int i = 0; i < G.size(); ++i) {
        int j = (i + 1) % G.size();
        ans += cross(G[i], G[j]);
    }
    return ans / 2;
}