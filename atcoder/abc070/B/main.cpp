#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int L = max(A, C), R = min(B, D);
    int ans = max(0, R - L);
    cout << ans << endl;

    return 0;
}