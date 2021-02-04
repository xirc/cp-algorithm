#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

using vector2 = complex<double>;

double const EPS = 1e-5;
double cross(const vector2& a, const vector2& b) {
    return a.real() * b.imag() - a.imag() * b.real();
}
bool is_intersect_ss(
    const vector2& a1, const vector2& a2,
    const vector2& b1, const vector2& b2
) {
    auto ca1 = cross(b2-b1,a1-b1), ca2 = cross(b2-b1,a2-b1);
    auto cb1 = cross(a2-a1,b1-a1), cb2 = cross(a2-a1,b2-a1);
    return (ca1 * ca2 < EPS) && (cb1 * cb2 < EPS);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ax, ay, bx, by;
    int N;
    vector<vector2> A;

    cin >> ax >> ay >> bx >> by;
    cin >> N;

    A.assign(N, vector2(0,0));
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        A[i] = vector2(x, y);
    }

    int ic = 0;
    auto a = vector2(ax, ay), b = vector2(bx, by);
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;
        if (is_intersect_ss(a, b, A[j], A[i])) ++ic;
    }
    assert(ic % 2 == 0);
    cout << (ic / 2 + 1) << endl;

    return 0;
}