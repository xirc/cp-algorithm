#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// O(N)
void solve(int N, ll K, vector<ll>& A) {
    assert(N >= 1 && K >= 1);

    auto const& next = [&]() {
        ll D = *max_element(A.begin(), A.end());
        for (int i = 0; i < N; ++i) {
            A[i] = D - A[i];
        }
    };

    --K;
    next();

    if (K == 0) return;

    -- K;
    next();

    if (K % 2) {
        next();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    ll K;
    vector<ll> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> K;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        solve(N, K, A);
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << A[i];
        }
        cout << endl;
    }

    return 0;
}