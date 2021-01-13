#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, A, B;
vector<int> X;

ll solve() {
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        ll w = X[i] - X[i-1];
        ans += min(w * A, ll(B));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    X.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    cout << solve() << endl;

    return 0;
}