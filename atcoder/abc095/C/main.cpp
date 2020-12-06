#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int A, B, C, X, Y;

ll solve() {
    ll ans = numeric_limits<ll>::max();
    ans = min(ans, ll(C) * 2 * X + max(Y - X, 0) * B);
    ans = min(ans, ll(C) * 2 * Y + max(X - Y, 0) * A);
    ans = min(ans, ll(C) * 2 * min(X,Y) + (X - min(X,Y)) * A + (Y - min(X,Y)) * B);
    ans = min(ans, ll(A) * X + ll(B) * Y);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> C >> X >> Y;
    cout << solve() << endl;

    return 0;
}