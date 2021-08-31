#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<ll> xs = { a * c, a * d, b * c, b * d };
    ll maxi = *max_element(xs.begin(), xs.end());
    cout << maxi << endl;

    return 0;
}