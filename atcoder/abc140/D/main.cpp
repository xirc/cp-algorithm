#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int N, int K, string const& S) {
    if (N == 1) return 0;

    int X = 0, Y = 0;
    for (int i = 0; i + 1 < N; ++i) {
        if (S[i] == 'R' && S[i+1] == 'L') ++X;
    }
    if (S[0] == 'L') ++Y;
    if (S[N-1] == 'R') ++Y;

    int a = min(X, K);
    X -= a, K -= a;
    int b = min(Y, K);
    Y -= b, K -= b;

    return min(N - Y - 2 * X, N -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    string S;

    cin >> N >> K >> S;
    cout << solve(N, K, S) << endl;

    return 0;
}