#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll N, vector<ll> const& A) {
    assert(A.size() == 5);
    ll Z = *min_element(A.begin(), A.end());
    ll P = N / Z, Q = N % Z;
    return 4 + P + (Q > 0 ? 1 : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    vector<ll> A(5);
    cin >> N;
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
    }
    cout << solve(N, A) << endl;

    return 0;
}