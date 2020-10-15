#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, vector<int>& A) {
    int zero = 0;
    int neg = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] < 0) ++neg;
        if (A[i] == 0) ++zero;
        A[i] = abs(A[i]);
    }
    if (neg % 2 == 0) return accumulate(A.begin(), A.end(), (ll)0);
    if (neg % 2 == 1 && zero > 0) return accumulate(A.begin(), A.end(), (ll)0);

    sort(A.begin(), A.end());
    ll ans = -A[0];
    for (int i = 1; i < N; ++i) {
        ans += A[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    vector<int> A;

    cin >> N;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve(N, A) << endl;

    return 0;
}