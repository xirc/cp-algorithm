#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, K;
vector<int> A;

ll solve() {
    ll S = 0;
    map<int,int,greater<int>> M;
    for (int i = 0; i < N; ++i) {
        M[A[i]]++;
    }
    while (K > 0 && M.size() > 0 && M.begin()->first > 0) {
        auto it = M.begin();
        ll u = it->first, m = it->second;
        ll v = ++it != M.end() ? it->first : 0;
        if (K >= (u - v) * m) {
            ll const n = u - v;
            ll const ss = (u + v + 1) * n / 2 * m;
            S += ss;
            K -= n * m;
            M.erase(u);
            M[v] += m;
        } else {
            ll const n = K / m;
            ll ss1 = (u + u - (n - 1)) * n / 2 * m;
            S += ss1;
            K -= n * m;
            ll ss2 = (u - n) * K;
            S += ss2;
            K -= K;
        }
    }
    return S;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;

    cout << solve() << endl;

    return 0;
}