#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    int R, S, P;
    string T;

    cin >> N >> K >> R >> S >> P >> T;

    vector<bool> A(N, false);
    for (int o = 0; o < K; ++o) {
        A[o] = true;
        for (int i = o + K; i < N; i += K) {
            if (T[i] == T[i-K]) {
                if (!A[i-K]) A[i] = true;
            } else {
                A[i] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i]) {
            if (T[i] == 'r') ans += P;
            else if (T[i] == 's') ans += R;
            else if (T[i] == 'p') ans += S;
        }
    }
    cout << ans << endl;

    return 0;
}