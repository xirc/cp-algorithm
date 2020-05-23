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

// Find the distance of the closest points.
// Solved by line sweep technique.
// O (N logN)
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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<vector2> PS(N);
    for (int i = 0 ; i < N; ++i) {
        cin >> PS[i].x >> PS[i].y;
    }
    double ans = distance_closest_pair(PS);
    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}