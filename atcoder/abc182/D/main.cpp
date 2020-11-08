#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    vector<ll> M(N, 0), C(N, 0);
    M[0] = max(0, A[0]);
    C[0] = A[0];
    for (int i = 1; i < N; ++i) {
        C[i] = C[i-1] + A[i];
        M[i] = max({ M[i], M[i-1], C[i] });
    }

    ll cur = 0;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ans = max(ans, cur + M[i]);
        cur += C[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}