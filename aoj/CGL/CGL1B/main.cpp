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
vector2 rejectionv(const vector2& a, const vector2& b) {
    return a - projectionv(a, b);
}

using namespace std;

vector2 solve(vector2 p0, vector2 p1, vector2 p2) {
    auto r = rejectionv(p0 - p1, p2 - p1);
    return p0 - 2 * r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector2 p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        vector2 p0;
        cin >> p0.x >> p0.y;
        auto ans = solve(p0, p1, p2);
        cout << fixed << setprecision(9) << ans.x << " " << ans.y << endl;
    }

    return 0;
}