#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for (int x = a; x <= b; ++x) {
        if (c % x == 0) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}