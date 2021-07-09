#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

ll gcd(ll a, ll b) {
    while (b > 0) {
        ll c = a % b;
        a = b, b = c;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a,b) * b;
}

ll solve(int N, int M, vector<int> const& A) {
    ll Y = 1;
    for (auto a : A) {
        if (a % 2 != 0) return 0;
        Y = lcm(Y, a / 2);
    }
    for (auto a : A) {
        if ((Y / (a / 2)) % 2 == 0) return 0;
    }
    return (M / Y + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M;
    vector<int> A;

    cin >> N >> M;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cout << solve(N, M, A) << endl;

    return 0;
}