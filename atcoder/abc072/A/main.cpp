#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, t;
    cin >> X >> t;
    cout << max(X - t, 0) << endl;

    return 0;
}