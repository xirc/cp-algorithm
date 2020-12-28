#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> solve(ll K) {
    const int N = 50;
    vector<ll> A(N, 0);
    for (int i = 0; i < N; ++i) {
        A[i] = i + K / N;
    }
    for (int i = 0; i < K % N; ++i) {
        A[N-1-i] += 1;
    }
    return A;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll K;
    cin >> K;
    auto ans = solve(K);
    const int N = ans.size();
    cout << N << endl;
    for (int i = 0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}