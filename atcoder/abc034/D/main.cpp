#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using lf = long double;

int N, K;
vector<array<int,2>> wp;

bool pass(lf pth) {
    sort(wp.begin(), wp.end(), [&](auto const& l, auto const& r) {
        auto lv = l[0] * (l[1] - pth) / lf(100);
        auto rv = r[0] * (r[1] - pth) / lf(100);
        return lv < rv;
    });
    reverse(wp.begin(), wp.end());

    double u = 0;
    for (int i = 0; i < K; ++i) {
        auto v = wp[i][0] * (wp[i][1] - pth) / lf(100);
        u += v;
    }
    return u - 1e-8 > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    wp.assign(N, { 0, 0});
    for (int i = 0; i < N; ++i) {
        cin >> wp[i][0] >> wp[i][1];
    }

    lf ok = 0.0, ng = 200.0;
    for (int i = 0; i < 400; ++i) {
        lf m = (ok + ng) / 2.0;
        if (pass(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }
    cout << fixed << setprecision(6) << ok << endl;

    return 0;
}