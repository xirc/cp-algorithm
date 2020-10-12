#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, vector<int>& A) {
    assert(N >= 1);

    int H = *max_element(A.begin(), A.end());
    if (A[N-1] < H) {
        A.push_back(H);
        ++N;
    }

    int maxi = A[0];
    ll ans = 0;
    for (int i = 1; i < N; ++i) {
        ans += max(0, min(A[i],maxi) - A[i-1]);
        maxi = max(maxi, A[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    vector<int> A;

    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        A.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << solve(N, A) << endl;
    }

    return 0;
}