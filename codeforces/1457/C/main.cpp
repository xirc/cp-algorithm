#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, P, K, X, Y;
string A;

ll solve() {
    vector<int> B(N, 0);
    B[N-1] = A[N-1] == '0' ? 1 : 0;
    for (int i = N - 2; i >= 0; --i) {
        if (i + K < N) {
            B[i] = B[i+K];
        }
        B[i] +=  (A[i] == '0' ? 1 : 0);
    }

    ll ans = numeric_limits<ll>::max();
    for (int i = 0; P + i < N; ++i) {
        ans = min(ans, i * ll(Y) + B[P+i] * ll(X));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> P >> K;
        cin >> A;
        cin >> X >> Y;
        --P;
        cout << solve() << endl;
    }

    return 0;
}