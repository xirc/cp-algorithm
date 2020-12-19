#pragma once

#include <cmath>

struct vector3 {
    double x, y, z;
    vector3() {}
    vector3(double x, double y, double z): x(x), y(y), z(z) {}
    vector3& operator+=(const vector3& o) {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
    vector3& operator-=(const vector3& o) {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        return *this;
    }
    vector3& operator*=(const double& o) {
        x *= o;
        y *= o;
        z *= o;
        return *this;
    }
    vector3& operator/=(const double& o) {
        x /= o;
        y /= o;
        z /= o;
        return *this;
    }
    vector3 operator+(const vector3& o) const {
        return vector3(*this) += o;
    }
    vector3 operator-(const vector3& o) const {
        return vector3(*this) -= o;
    }
    vector3 operator*(const double& o) const {
        return vector3(*this) *= o;
    }
    vector3 operator/(const double& o) const {
        return vector3(*this) /= o;
    }
    double norm() const {
        return x * x + y * y + z * z;
    }
    double length() const {
        return std::sqrt(norm());
    }
    vector3 normalized() const {
        return vector3(*this) /= length();
    }
};
vector3 operator*(double o, const vector3& v) {
    return v * o;
}

// dot(A,B) = dot(B,A)
// dot(k * A,B) = k * dot(A,B)
// dot(A + B, C) = dot(A, C) + dot(B, C)
double dot(const vector3& a, const vector3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
// A x B = -B x A
// (kA) x B = k (A x B)
// A (B x C) = B (C x A) = -A (C x B)
// |A x B| = |A||B|sin() = Area of parallelogram formed by A and B.
vector3 cross(const vector3& a, const vector3& b) {
    return vector3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}
// Volume of parallelepiped formed by A, B, and C.
double triple(const vector3& a, const vector3& b, const vector3& c) {
    return dot(a, cross(b, c));
}
// Angle between vectors
double angle(const vector3& a, const vector3& b) {
    return std::acos(dot(a,b) / a.length() / b.length());
}
// Scalar Projection of 'A' onto 'B'
double projection(const vector3& a, const vector3& b) {
    return dot(a,b) / b.length();
}
// Vector Projection of 'A' onto 'B'
vector3 projectionv(const vector3& a, const vector3& b) {
    return projection(a, b) * b.normalized();
}
// Vector Rejection of 'A' from 'B'
vector3 rejectionv(const vector3& a, const vector3& b) {
    return a - projectionv(a, b);
}