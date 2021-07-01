#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> xs, ys;

    cin >> N;
    xs.assign(N, 0);
    ys.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i];
    }

    vector<int> ps(N, 0);
    for (int i = 0; i < N; ++i) ps[i] = i;

    vector<ff> distances;
    do {
        vector<ff> ds(N-1, 0);
        for (int i = 0; i + 1 < N; ++i) {
            auto dx = xs[ps[i]] - xs[ps[i+1]];
            auto dy = ys[ps[i]] - ys[ps[i+1]];
            ds[i] = sqrtl(dx * dx + dy * dy);
        }
        sort(ds.begin(), ds.end());
        auto distance = accumulate(ds.begin(), ds.end(), ff(0), plus<ff>());
        distances.push_back(distance);
    } while (next_permutation(ps.begin(), ps.end()));

    sort(distances.begin(), distances.end());
    auto avg_distance = accumulate(distances.begin(), distances.end(), ff(0), plus<ff>()) / distances.size();

    cout << fixed << setprecision(7) << avg_distance << endl;

    return 0;
}