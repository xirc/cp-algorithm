#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O(N)
int solve(int X, int Y, int Z) {
    for (int n = X; n >= 2; --n) {
        ll w = ll(n) * Y + ll(n + 1) * Z;
        if (w <= X) return n;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, Y, Z;

    cin >> X >> Y >> Z;
    cout << solve(X, Y, Z) << endl;

    return 0;
}