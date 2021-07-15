#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<int> P(N, 0);
    for (auto &p : P) cin >> p;

    int M = P[0];
    int ans = 1;
    for (int i = 1; i < N; ++i) {
        M = min(M, P[i]);
        if (M >= P[i]) ++ans;
    }
    cout << ans << endl;

    return 0;
}