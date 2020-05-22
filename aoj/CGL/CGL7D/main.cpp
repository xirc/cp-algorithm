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
bool LQ(const double& x, const double& y) {
    return x < y || EQ(x,y);
}
bool GQ(const double& x, const double& y) {
    return x > y || EQ(x,y);
}

// Distance between point 'P' and line 'A'
double distance_lp(const vector2& a1, const vector2& a2, const vector2& p) {
    return abs(cross(a2-a1, p-a1)) / abs(a2-a1);
}

// Intersection of Circle (c1,r1) and Line (a1,a2)
// return:
//   2) they do not cross
//   1) they are circumscribed
//   0) they are intersected
//   and intersection points (0 ~ 2 points)
int intersection_cl(
    const vector2& c1, const double r1,
    const vector2& a1, const vector2& a2,
    std::vector<vector2>& out
) {
    out.clear();
    out.reserve(2);

    double d = distance_lp(a1, a2, c1);
    if (d > r1) {
        return 2;
    }
    if (EQ(d, r1)) {
        auto v = a1 + projectionv(c1 - a1, a2 - a1);
        out.push_back(v);
        return 1;
    }

    auto v = -1 * rejectionv(c1 - a1, a2 - a1);
    auto y = std::sqrt(std::max(r1 * r1 - v.norm(), 0.0));
    auto u = (a2 - a1).normalized() * y;
    out.push_back(c1 + v + u);
    out.push_back(c1 + v - u);
    return 0;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector2 c1; double r1;
    cin >> c1.x >> c1.y >> r1;
    
    int Q;
    cin >> Q;
    vector<vector2> cp;
    for (int i = 0; i < Q; ++i) {
        vector2 p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        int ans = intersection_cl(c1, r1, p1, p2, cp);
        if (ans == 2) throw;
        if (ans == 1) cp.push_back(cp[0]);
        sort(cp.begin(), cp.end());
        cout << fixed << setprecision(7)
            << cp[0].x << " " << cp[0].y << " " << cp[1].x << " " << cp[1].y << endl;
    }

    return 0;
}