#include <bits/stdc++.h>

using namespace std;

int solve(int N, int X) {
    int f = 1;
    while ((f - 1) * X + 2 < N) {
        f++;
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, X;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> X;
        cout << solve(N, X) << endl;
    }

    return 0;
}