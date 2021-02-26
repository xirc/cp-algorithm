#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int sqrti(int X) {
    for (int r = 1; ll(r) * r <= X; ++r) {
        if (r * r == X) return r;
    }
    throw;
}

int solve(int X) {
    return sqrti(sqrti(X));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;
    cout << solve(X) << endl;

    return 0;
}