#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(ll a, ll b, ll c, ll d) {
    if (a == c && b == d) return 0;
    //
    if (a + b == c + d) return 1;
    if (a - b == c - d) return 1;
    if (abs(a-c) + abs(b - d) <= 3) return 1;
    //
    if ((a + b) % 2 == (c + d) % 2) return 2;
    if (abs(a-c) + abs(b -d) <= 6)  return 2;
    if (abs((a + b) - (c + d)) <= 3) return 2;
    if (abs((a - b) - (c - d)) <= 3) return 2;

    return 3;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << solve(r1, c1, r2, c2) << endl;

    return 0;
}