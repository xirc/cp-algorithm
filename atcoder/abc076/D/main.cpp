#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> ts;
vector<int> vs;

double solve() {
    int T = 0;
    vector<vector<int>> cs(N);
    for (int i = 0; i < N; ++i) {
        int l = T, r = T + ts[i], v = vs[i];
        cs[i] = { l, r, v };
        T += ts[i];
    }
    cs.push_back({ 0, 0, 0 });
    cs.push_back({ T, T, 0 });
    const auto minv = [&](double t) {
        double res = 100;
        for (auto const& c : cs) {
            auto l = c[0], r = c[1], v = c[2];
            if (t < l) {
                res = min(res, v + (l - t));
            } else if (t > r) {
                res = min(res, v + (t - r));
            } else {
                res = min(res, double(v));
            }
        }
        return res;
    };

    double S = 0;
    for (int tt = 0; tt < 2 * T; ++tt) {
        double t = tt * 0.5, nt = (tt + 1) * 0.5;
        double v = minv(t), nv = minv(nt);
        S += 0.5 * (v + nv) * 0.5;
    }
    return S;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    ts.assign(N, 0);
    vs.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> ts[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> vs[i];
    }
    cout << fixed << setprecision(3) << solve() << endl;

    return 0;
}