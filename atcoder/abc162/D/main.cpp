#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;

    cin >> N >> S;
    int R = 0, G = 0, B = 0;
    for (auto c : S) {
        if (c == 'R') ++R;
        if (c == 'G') ++G;
        if (c == 'B') ++B;
    }
    ll ans = ll(R) * G * B;
    for (int l = 1; l < N; ++l) {
        for (int i = 0; i < N; ++i) {
            int j = i + l; if (j >= N) continue;
            int k = j + l; if (k >= N) continue;
            if (S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) --ans;
        }
    }
    cout << ans << endl;

    return 0;
}