#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, X;
    cin >> T >> X;
    double ans = (double) T / X;
    cout << fixed << setprecision(4) << ans << endl;

    return 0;
}