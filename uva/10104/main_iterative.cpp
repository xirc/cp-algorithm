#include <bits/stdc++.h>

inline unsigned long long extgcd(unsigned long long a, unsigned long long b, long long &x, long long &y) {
    x = 1, y = 0;
    long long x1 = 0, y1 = 1;
    unsigned long long a1 = a, b1 = b;
    // a * x  + b * y  = a1
    // a * x1 + b * y1 = b1
    while (b1 > 0) {
        unsigned long long q = a1 / b1;
        std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
        std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
    }
    return a1;
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