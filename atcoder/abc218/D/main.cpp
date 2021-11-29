#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> xs, ys;

ll solve() {
    map<array<int,2>,int> T;
    map<int,map<array<int,2>,int>> D;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (xs[i] != xs[j]) continue;
            int x = xs[i];
            int y = min(ys[i], ys[j]);
            int l = abs(ys[i] - ys[j]);
            T[{y,l}]++;
            D[x][{y,l}]++;
        }
    }
    ll ans = 0;
    for (auto e : D) {
        int x = e.first;
        for (auto r : e.second) {
            int y = r.first[0], l = r.first[1];
            ans += T[{y,l}]-D[x][{y,l}];
        }
    }
    ans /= 2;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    xs.assign(N, 0);
    ys.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i] >> ys[i];
    }
    cout << solve() << endl;

    return 0;
}