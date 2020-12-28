#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    ll x = A[0];
    ll y = 0;
    for (int i = 1; i < N; ++i) {
        y += A[i];
    }

    ll ans = abs(x - y);
    for (int i = 1; i < N - 1; ++i) {
        x += A[i];
        y -= A[i];
        ans = min(ans, abs(x - y));
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