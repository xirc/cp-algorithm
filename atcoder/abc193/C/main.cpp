#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;

    unordered_set<ll> powers;
    for (ll a = 2; a * a <= N; ++a) {
        ll c = a * a;
        if (powers.count(c) > 0) continue;
        while (c <= N) {
            powers.insert(c);
            c *= a;
        }
    }
    cout << (N - powers.size()) << endl;

    return 0;
}