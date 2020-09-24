#include <bits/stdc++.h>

using namespace std;

int solve(int N) {
    assert(N >= 1);
    return (N - 1) / 2 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}