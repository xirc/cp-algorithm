#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int N;
vector<complex<int>> A, B;

lf metric(vector<complex<int>> ps) {
    ll sx = 0, sy = 0;
    for (int i = 0; i < N; ++i) {
        sx += ps[i].real();
        sy += ps[i].imag();
    }
    complex<lf> cp = complex<lf>(lf(sx) / N, lf(sy) / N);
    vector<lf> ds(N, 0);
    for (int i = 0; i < N; ++i) {
        auto p = complex<lf>(ps[i].real(), ps[i].imag());
        ds[i] = abs(p - cp);
    }
    sort(ds.begin(), ds.end());
    lf m = 0;
    for (auto d : ds) m += d;
    return m;
}

lf solve() {
    auto am = metric(A);
    auto bm = metric(B);
    return bm / am;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int x, y;
    A.assign(N, { 0, 0 });
    B.assign(N, { 0, 0 });
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        A[i] = complex<int>(x, y);
    }
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        B[i] = complex<int>(x, y);
    }
    cout << fixed << setprecision(6) << solve() << endl;

    return 0;
}