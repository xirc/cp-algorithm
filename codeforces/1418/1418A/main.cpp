#include <bits/stdc++.h>

using namespace std;

long long solve(int X, int Y, int K) {
    long long sticks = K + (long long)Y * K;
    long long ans = 0;
    ans += K;
    ans += (sticks - 1) / (X - 1);
    if ((sticks - 1) % (X - 1) > 0) {
        ans += 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, X, Y, K;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> X >> Y >> K;
        cout << solve(X, Y, K) << endl;
    }

    return 0;
}