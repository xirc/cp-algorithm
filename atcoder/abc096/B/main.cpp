#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int mx = max({ A, B, C });
    int ans = (mx << K) - mx + A + B + C;
    cout << ans << endl;

    return 0;
}