#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> C, S, F;

vector<ll> solve() {
    vector<ll> ans(N, 0);

    for (int i = 0; i < N; ++i) {
        ll t = 0;
        for (int j = i; j < N - 1; ++j) {
            if (t < S[j]) {
                t = S[j];
                t += C[j];
            } else {
                ll r = (F[j] - (t - S[j]) % F[j]) % F[j];
                t += r;
                t += C[j];
            }
        }
        ans[i] = t;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    C.assign(N - 1, 0);
    S.assign(N - 1, 0);
    F.assign(N - 1, 0);
    for (int i = 0; i < N - 1; ++i) {
        cin >> C[i] >> S[i] >> F[i];
    }
    auto ans = solve();
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}