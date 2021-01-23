#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
vector<string> S;

ll solve() {
    vector<ll> t(N+1), f(N+1);
    t[0] = 1;
    f[0] = 1;
    for (int i = 0; i < N; ++i) {
        if (S[i] == "AND") {
            t[i+1] = t[i];
            f[i+1] = f[i] * 2 + t[i];
        } else if (S[i] == "OR") {
            t[i+1] = t[i] * 2 + f[i];
            f[i+1] = f[i];
        } else throw;
    }
    return t[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    cout << solve() << endl;

    return 0;
}