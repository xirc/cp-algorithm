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

// Find segments' intersections in Manhattan Geometry
// O (N log N + K)
//   where K = number of intersections
// NOTE:
//   if K will be N*N and you only need number of intersections,
//   use ImplicitTreap instead of std::multiset, and don't iterate over intersections.
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


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<pair<vector2,vector2>> ss(N);
    for (int i = 0; i < N; ++i) {
        cin >> ss[i].first.x >> ss[i].first.y;
        cin >> ss[i].second.x >> ss[i].second.y;
    }

    vector<vector2> is;
    intersection_ss_manhattan(ss, is);
    cout << is.size() << endl;

    return 0;
}