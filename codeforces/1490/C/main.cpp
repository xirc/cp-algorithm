#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;


unordered_set<ll> cubes;
void build() {
    for (int x = 1; x <= 10000; ++x) {
        cubes.insert(ll(x) * x * x);
    }
}

bool solve(ll x) {
    for (auto aaa : cubes) {
        auto bbb = x - aaa;
        if (cubes.find(bbb) != cubes.end()) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    build();

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        ll x;
        cin >> x;
        auto ans = solve(x) ? "YES" : "NO";
        cout << ans << endl;
    }

    return 0;
}