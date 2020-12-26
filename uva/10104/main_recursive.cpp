#include <bits/stdc++.h>

inline unsigned long long extgcd(unsigned long long a, unsigned long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    long long x1, y1;
    unsigned long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}


using namespace std;
using ll = long long;

vector<ll> solve(ll A, ll B) {
    ll X, Y, D;
    D = extgcd(A, B, X, Y);
    return { X, Y, D };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    ll A, B;
    while (true) {
        cin >> A >> B;
        if (cin.eof()) break;
        auto ans = solve(A, B);
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    }

    return 0;
}