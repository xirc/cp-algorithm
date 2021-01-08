#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<ll> T;

ll gcd(ll a, ll b) {
    while (b > 0) {
        ll c = a % b;
        a = b, b = c;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll solve() {
    ll ans = 1;
    for (auto t : T) {
        ans = lcm(ans, t);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    T.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    cout << solve() << endl;

    return 0;
}