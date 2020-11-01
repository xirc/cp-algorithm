#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll lpow(ll b, ll e) {
    ll ans = 1;
    for (ll i = 0; i < e; ++i) {
        ans *= b;
    }
    return ans;
}

map<ll,ll> dec(ll Q) {
    ll qq = Q;
    map<ll,ll> fs;
    for (int i = 2; i * i <= Q; ++i) {
        while (qq % i == 0) {
            ++fs[i];
            qq /= i;
        }
    }
    if (qq > 1) {
        ++fs[qq];
    }
    return fs;
}

ll solve(ll P, ll Q) {
    if (P % Q != 0) return P;

    auto fs = dec(Q);
    ll ans = 1;
    auto pp = P;
    map<ll,ll> ps;
    for (auto e : fs) {
        auto v = e.first;
        while (pp % v == 0) {
            ++ps[v];
            pp /= v;
        }
        if (ps[v] >= fs[v]) {
            ll c = (ps[v] - fs[v] + 1);
            ll ll = P / lpow(v, c);
            ans = max(ll, ans);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    ll P, Q;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> P >> Q;
        cout << solve(P, Q) << endl;
    }

    return 0;
}