#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> ls;

ll solve() {
    int const LMAX = 2000;
    vector<int> acc(LMAX+1, 0);
    for (int i = 0; i < N; ++i) {
        acc[ls[i]]++;
    }
    for (int i = 1; i < LMAX+1; ++i) {
        acc[i] += acc[i-1];
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            int a = ls[i], b = ls[j];
            // [cmin,cmax]
            int cmin = abs(a - b) + 1;
            int cmax = a + b -1;
            auto m = acc[cmax];
            m -= acc[cmin-1];
            if (a >= cmin && a <= cmax) --m;
            if (b >= cmin && b <= cmax) --m;
            ans += m;
        }
    }
    return ans / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    ls.assign(N, 0);
    for (auto &l : ls) cin >> l;
    cout << solve() << endl;

    return 0;
}