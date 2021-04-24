#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<string> S;
vector<int> P;

string solve() {
    int sumP = 0;
    for (int i = 0; i < N; ++i) {
        sumP += P[i];
    }
    for (int i = 0; i < N; ++i) {
        if (P[i] * 2 > sumP) {
            return S[i];
        }
    }
    return "atcoder";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, "");
    P.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> P[i];
    }

    auto ans = solve();
    cout << ans << endl;

    return 0;
}