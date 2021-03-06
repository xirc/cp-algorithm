#pragma once

#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>

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
// Angle between vectors
double angle(const vector2& a, const vector2& b) {
    return std::acos(dot(a,b) / abs(a) / abs(b));
}

// Vector Projection of 'A' onto 'B'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A
vector2 projectionv(const vector2& a, const vector2& b) {
    return dot(a,b) / abs(b) * b.normalized();
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
bool is_intersect_sp(const vector2& a1, const vector2& a2, const vector2& p) {
    return LQ(abs(a1-p) + abs(p-a2), abs(a1-a2));
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
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
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

// Distance between point 'P' and line 'A'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
double distance_lp(const vector2& a1, const vector2& a2, const vector2& p) {
    return abs(cross(a2-a1, p-a1)) / abs(a2-a1);
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
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
vector2 intersection_ll(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    double A = cross(a2 - a1, b2 - b1);
    double B = cross(b1 - a1, b2 - b1);
    return a1 + (B / A) * (a2 - a1);
}
// Intersection Point of line segments 'A' and 'B'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_C
vector2 intersection_ss(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    return intersection_ll(a1, a2, b1, b2);
}

// Area of Polygon (can handle non-Convex)
// The coordinates of points are given in the order of counter-clockwise visit of them.
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A
double polygon_area(const std::vector<vector2>& G) {
    double ans = 0;
    for (size_t i = 0; i < G.size(); ++i) {
        size_t j = (i + 1) % G.size();
        ans += cross(G[i], G[j]);
    }
    return ans / 2;
}

// Is a polygon convex or not?
// The coordinates of points are given in the order of counter-clockwise visit of them.
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B
bool is_convex_polygon(const std::vector<vector2>& G) {
    for (size_t i = 0; i < G.size(); ++i) {
        size_t p = (i-1+G.size()) % G.size();
        size_t n = (i+1) % G.size();
        int c = ccw(G[p], G[i], G[n]);
        if (c == -1) return false;
    }
    return true;
}

// Does A polygon 'G' contain point 'P'?
// 0: 'P' is on a segment of 'G'
// 1: 'P' is in 'G'
// -1: 'P' is not in 'G'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
int polgygon_contains(const std::vector<vector2> G, const vector2& p) {
    enum { ON = 0, IN = 1, OUT = -1 };
    bool in = false;
    for (size_t i = 0; i < G.size(); ++i) {
        size_t j = (i+1) % G.size();
        auto a = G[i] - p, b = G[j] - p;
        if (EQ(cross(a,b),0) && LQ(dot(a,b), 0)) return ON;
        if (a.y > b.y) {
            std::swap(a, b);
        }
        if (LQ(a.y, 0) && b.y > 0 && cross(a,b) < 0) {
            in = !in;
        }
    }
    return in ? IN : OUT;
}

// Convex Hull
// O(N logN)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A
std::vector<vector2> convex_hull(const std::vector<vector2>& G) {
    const int N = G.size();
    std::vector<vector2> ps(G.begin(), G.end());
    std::sort(ps.begin(), ps.end());

    int K = 0;
    std::vector<vector2> ans(2*N);
    for (int i = 0; i < N; ++i) {
        while (K >= 2 && ccw(ans[K-2], ans[K-1], ps[i]) == -1) K--;
        ans[K++] = ps[i];
    }
    int T = K + 1;
    for (int i = N - 2; i >= 0; --i) {
        while (K >= T && ccw(ans[K-2], ans[K-1], ps[i]) == -1) K--;
        ans[K++] = ps[i];
    }
    ans.resize(K - 1);

    return ans;
}

// Convex Diameter
// - solved by Rotating Calipers
// - O (N logN)
// - tuple(i, j, diameter)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
std::tuple<int,int,double> convex_diameter(const std::vector<vector2>& G) {
    if (G.size() <= 1) throw;

    const int N = G.size();

    // Pick antipodal points
    int is = 0, js = 0;
    for (int i = 1; i < N; ++i) {
        if (G[i].y > G[is].y) is = i;
        if (G[i].y < G[js].y) js = i;
    }

    auto maxd = (G[is]-G[js]).norm();
    int i, maxi, j, maxj;
    i = maxi = is;
    j = maxj = js;
    do {
        int ni = (i+1)%N, nj = (j+1)%N;
        if (GQ(cross(G[ni]-G[i], G[nj]-G[j]), 0)) {
            j = nj;
        } else {
            i = ni;
        }
        auto d = (G[i]-G[j]).norm();
        if (d > maxd) {
            maxd = d, maxi = i, maxj = j;
        }
    } while (i != is || j != js);
    return std::make_tuple(maxi, maxj, std::sqrt(maxd));
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
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C
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

// Are a circle (c1,r1) and a point p1 intersected or not?
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G
bool is_intersect_cp(const vector2& c1, const double r1, const vector2& p) {
    return EQ((p - c1).length(), r1);
}

// Intersection of Circles (c1,r1) and (c2, r2)
// return:
//   4) they do not cross (there are 4 common tangent lines)
//   3) they are circumscribed (there are 3 common tanget lines)
//   2) they are intersect (there are 2 common tanget lines)
//   1) a circle is inscribed in another (there are 1 common tanget line)
//   0) a circle includes another (there are no common tanget line)
//   and intersection points (0 ~ 2 points)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E
int intersection_cc(vector2 c1, double r1, vector2 c2, double r2, std::vector<vector2>& ans) {
    ans.clear();
    ans.reserve(2);

    if (r1 < r2) {
        std::swap(c1, c2);
        std::swap(r1, r2);
    }

    double dd = (c1 - c2).length();
    if (dd > r1 + r2) {
        return 4;
    }
    if (EQ(dd, r1 + r2)) {
        auto v = c1 + (c2 - c1).normalized() * r1;
        ans.push_back(v);
        return 3;
    }
    if (dd < r1 - r2) {
        return 0;
    }
    if (EQ(dd, r1 - r2)) {
        auto v = c1 + (c2 - c1).normalized() * r1;
        ans.push_back(v);
        return 1;
    }

    double x = (dd * dd + r1 * r1 - r2 * r2) / (2 * dd);
    auto v = (c2 - c1).normalized() * x;
    double y = std::sqrt(std::max(r1 * r1 - x * x, 0.0));
    auto u = (c2 - c1).unit_normal() * y;
    ans.push_back(c1 + v + u);
    ans.push_back(c1 + v - u);
    return 2;
}

// Intersection of Circle (c1,r1) and Line (a1,a2)
// return:
//   2) they do not cross
//   1) they are circumscribed
//   0) they are intersected
//   and intersection points (0 ~ 2 points)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
//   (But, intersection points are not verified.)
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

// Find the tangent lines between a point 'P' and a circle 'C'
// return:
//   2) they have 2 tangent lines (2 tangent points)
//   1) a point lies on a circle (1 tangent point)
//   0) a circle includes a point (no tangent point)
//   and tangent points (0 ~ 2 points)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F
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

// Common tangent of two circles (c1,r1) and (c2, r2)
// return:
//   4) they do not cross (there are 4 common tangent lines)
//   3) they are circumscribed (there are 3 common tanget lines)
//   2) they are intersect (there are 2 common tanget lines)
//   1) a circle is inscribed in another (there are 1 common tanget line)
//   0) a circle includes another (there are no common tanget line)
//   and intersection points (0 ~ 8 points)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G
int tangent_on_circles(
    vector2 c1, double r1,
    vector2 c2, double r2,
    std::vector<vector2>& ans
) {
    ans.clear();
    ans.reserve(4);

    if (r1 < r2) {
        std::swap(c1, c2);
        std::swap(r1, r2);
    }

    double d = (c2 - c1).length();
    if (d < r1 - r2) {
        return 0;
    }
    if (EQ(d, r1 - r2)) {
        auto v = c1 + (c2 - c1).normalized() * r1;
        ans.push_back(v);
        return 1;
    }
    
    double theta = std::acos((r1 - r2) / d);
    auto v = (c2 - c1).rotated(theta).normalized();
    auto u = (c2 - c1).rotated(-theta).normalized();
    ans.push_back(c1 + r1 * v);
    ans.push_back(c1 + r1 * u);
    ans.push_back(c2 + r2 * v);
    ans.push_back(c2 + r2 * u);

    if (d < r1 + r2) {
        return 2;
    }

    if (EQ(d, r1 + r2)) {
        auto w = c1 + (c2 - c1).normalized() * r1;
        ans.push_back(w);
        return 3;
    }

    double phi = std::acos((r1 + r2) / d);
    auto x = (c2 - c1).rotated(phi).normalized();
    auto y = (c2 - c1).rotated(-phi).normalized();
    ans.push_back(c1 + r1 * x);
    ans.push_back(c1 + r1 * y);
    ans.push_back(c2 - r2 * x);
    ans.push_back(c2 - r2 * y);
    return 4;
}

// Find the distance of the closest points.
// Solved by line sweep technique.
// O (N logN)
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A
double distance_closest_pair(const std::vector<vector2>& points) {
    if (points.size() <= 1) return 0;

    std::vector<vector2> PS(points.begin(), points.end());
    std::sort(PS.begin(), PS.end());

    const int N = PS.size();
    struct less {
        bool operator()(const vector2& lhs, const vector2& rhs) {
            return lhs.y < rhs.y;
        }
    };
    std::set<vector2, less> box;

    double ans = std::numeric_limits<double>::max();
    int left = 0;
    box.insert(PS[0]);
    for (int i = 1; i < N; ++i) {
        while (left < i && PS[i].x - PS[left].x > ans) {
            box.erase(PS[left]);
            left++;
        }
        for (
            auto it = box.lower_bound(vector2(0, PS[i].y - ans));
            it != box.end() && LQ(it->y, PS[i].y + ans);
            ++it
        ) {
            ans = std::min(ans, abs(PS[i] - *it));
        }
        box.insert(PS[i]);
    }
    return ans;
}

// Find segments' intersections in Manhattan Geometry
// O (N log N + K)
//   where K = number of intersections
// NOTE:
//   if K will be N*N and you only need number of intersections,
//   use ImplicitTreap instead of std::multiset, and don't iterate over intersections.
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/6/CGL_6_A
void intersection_ss_manhattan(
    const std::vector<std::pair<vector2,vector2>>& ss,
    std::vector<vector2>& ans
) {
    enum event_type { HIN=0, VT=1, HOUT=2 };
    struct event {
        event_type type;
        vector2 s, e;
        double key;
        bool operator<(const event& o) const {
            return !EQ(key, o.key) ? key < o.key : type < o.type;
        }
    };

    const int N = ss.size();
    std::vector<event> events;

    events.reserve(2*N);
    for (auto s : ss) {
        auto v = s.first - s.second;
        if (is_parallel(v, vector2(1,0))) {
            // Horizontal Line
            auto lx = std::min(s.first.x, s.second.x);
            auto ux = std::max(s.first.x, s.second.x);
            events.push_back({ HIN, s.first, s.second, lx });
            events.push_back({ HOUT, s.first, s.second, ux });
        } else if (is_orthogonal(v, vector2(1,0))) {
            // Vertical Line
            events.push_back({ VT, s.first, s.second, s.first.x });
        } else throw;
    }
    std::sort(events.begin(), events.end());

    struct less {
        bool operator()(const vector2& lhs, const vector2& rhs) {
            return lhs.y < rhs.y;
        }
    };
    std::multiset<vector2, less> S;

    ans.clear();
    ans.reserve(N * std::log2(N));
    for (auto e : events) {
        if (e.type == HIN) {
            S.insert(e.s);
        } else if (e.type == HOUT) {
            S.erase(S.find(e.s));
        } else if (e.type == VT) {
            auto ly = std::min(e.s.y, e.e.y);
            auto uy = std::max(e.s.y, e.e.y);
            auto bs = S.lower_bound(vector2(0, ly));
            auto es = S.upper_bound(vector2(0, uy));
            for (auto it = bs; it != es; ++it) {
                auto v = vector2(e.s.x, it->y);
                ans.push_back(v);
            }
        } else throw;
    }
}