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

// Direction
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
int ccw(const vector2& a, const vector2& b, const vector2& c) {
    vector2 x = b - a, y = c - a;
    if (cross(x, y) > 0) return +1;      // counter clockwise
    if (cross(x, y) < 0) return -1;      // clockwise
    if (dot(x,y) < 0) return +2;         // c--a--b on line
    if (x.norm() < y.norm()) return -2;  // a--b--c on line
    return 0;                                  // a--c--b on line
}

// Does A polygon 'G' contain point 'P'?
// 0: 'P' is on a segment of 'G'
// 1: 'P' is in 'G'
// -1: 'P' is not in 'G'
// Verified https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
int polgygon_contains(const std::vector<vector2> G, const vector2& p) {
    enum { ON = 0, IN = 1, OUT = -1 };
    bool in = false;
    for (int i = 0; i < G.size(); ++i) {
        int j = (i+1) % G.size();
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

    auto ans = convex_hull(G);
    int s = 0;
    for (int i = 1; i < ans.size(); ++i) {
        bool less = ans[i].y != ans[s].y ? ans[i].y < ans[s].y : ans[i].x < ans[s].x;
        if (less) {
            s = i;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        int j = (s + i) % ans.size();
        cout << ans[j].x << " " << ans[j].y << endl;
    }

    return 0;
}