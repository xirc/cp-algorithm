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
bool LQ(const double& x, const double& y) {
    return x < y || EQ(x,y);
}
bool GQ(const double& x, const double& y) {
    return x > y || EQ(x,y);
}

// Direction
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
int ccw(const vector2& a, const vector2& b, const vector2& c) {
    vector2 x = b - a, y = c - a;
    if (cross(x, y) > 0) return +1;      // counter clockwise
    if (cross(x, y) < 0) return -1;      // clockwise
    if (dot(x, y) < 0) return +2;        // c--a--b on line
    if (x.norm() < y.norm()) return -2;  // a--b--c on line
    return 0;                            // a--c--b on line
}

// Are line 'A' and line segment 'B' intersected or not?
bool is_intersect_ls(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    int ccw1 = ccw(a1, a2, b1);
    int ccw2 = ccw(a1, a2, b2);
    return
        (ccw1 == -1 && ccw2 == 1) ||
        (ccw1 == 1 && ccw2 == -1);
}

// Intersection Point of lines 'A' and 'B'
vector2 intersection_ll(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    double A = cross(a2 - a1, b2 - b1);
    double B = cross(b1 - a1, b2 - b1);
    return a1 + (B / A) * (a2 - a1);
}

// Area of Polygon (can handle non-Convex)
// The coordinates of points are given in the order of counter-clockwise visit of them.
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
double polygon_area(const std::vector<vector2>& G) {
    double ans = 0;
    for (int i = 0; i < G.size(); ++i) {
        int j = (i + 1) % G.size();
        ans += cross(G[i], G[j]);
    }
    return ans / 2;
}

// Convex Cut
// - O(N)
// - require
//   The coordinates of points of a given polygon
//   are given in the order of counter-clockwise visit of them.
// - return
//   a polygon that is left hand side of line.
//   The coordinates of points of a result polygon
//   are given in the order of counter-clockwise visit of them.
std::vector<vector2> convex_cut(
    const std::vector<vector2>& G,
    const vector2& a1, const vector2& a2
) {
    const int N = G.size();
    std::vector<vector2> ans;
    ans.reserve(N);
    for (int i = 0; i < N; ++i) {
        auto &a = G[i], &b = G[(i+1)%N];
        if (ccw(a1, a2, a) != -1) {
            ans.push_back(a);
        }
        if (is_intersect_ls(a1, a2, a, b)) {
            auto c = intersection_ll(a1, a2, a, b);
            ans.push_back(c);
        }
    }
    return ans;
}


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<vector2> G(N);
    for (int i = 0; i < N; ++i) {
        cin >> G[i].x >> G[i].y;
    }

    int Q;
    cin >> Q;
    vector2 p1, p2;
    for (int i = 0; i < Q; ++i) {
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        auto poly = convex_cut(G, p1, p2);
        auto area = polygon_area(poly);
        cout << fixed << setprecision(6) << area << endl;
    }

    return 0;
}