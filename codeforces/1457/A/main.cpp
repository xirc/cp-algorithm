#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        int N, M, R, C;
        cin >> N >> M >> R >> C;
        long long ans = 0;
        ans += max(N - R, R - 1);
        ans += max(M - C, C - 1);
        cout << ans << endl;
    }

    return 0;
}