#include <bits/stdc++.h>

using namespace std;

// O(N+Q)
void solve(vector<int>& A, vector<int> const& L, vector<int> const& R) {
    assert(A.size() >= 1 && L.size() == R.size());
    const int N = A.size();
    const int Q = L.size();

    long long ans = A[0];
    for (int i = 1; i < N; ++i) {
        ans += max(A[i] - A[i-1], 0);
    }
    cout << ans << endl;

    auto update = [&](int i, int v) {
        ans -= A[0];
        if (i - 1 >= 0) {
            ans -= max(A[i] - A[i-1], 0);
        }
        if (i + 1 < N) {
            ans -= max(A[i+1] - A[i], 0);
        }
        A[i] = v;
        if (i - 1 >= 0) {
            ans += max(A[i] - A[i-1], 0);
        }
        if (i + 1 < N) {
            ans += max(A[i+1] - A[i], 0);
        }
        ans += A[0];
    };
    for (int i = 0; i < Q; ++i) {
        auto li = L[i], ri = R[i];
        auto vl = A[li], vr = A[ri];
        update(li, vr);
        update(ri, vl);
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, Q;
    vector<int> A, L, R;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> Q;
        A.assign(N, 0);
        L.assign(Q, 0);
        R.assign(Q, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < Q; ++i) {
            cin >> L[i] >> R[i];
            --L[i], --R[i];
        }
        solve(A, L, R);
    }

    return 0;
}