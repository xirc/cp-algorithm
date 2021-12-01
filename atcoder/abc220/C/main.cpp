#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<int> A;
ll X;

ll solve() {
    ll const S = accumulate(A.begin(), A.end(), ll(0), plus<ll>());
    ll ans = 0;
    if (X >= S) {
        ans += (X / S) * N;
        X %= S;
    }
    for (int i = 0; i < N && X >= 0; ++i) {
        X -= A[i];
        ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (auto &a : A) cin >> a;
    cin >> X;

    cout << solve() << endl;

    return 0;
}