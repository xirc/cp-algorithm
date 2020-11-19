#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<int> A;

ll solve() {
    vector<ll> B(N, 0);
    B[0] = A[0];
    for (int i = 1; i < N; ++i) {
        B[i] = B[i-1] + A[i];
    }

    ll ans = 0;
    unordered_map<int,int> C;
    for (int i = 0; i < N; ++i) {
        ans += C[B[i]%M];
        if (B[i]%M == 0) ans++;
        ++C[B[i]%M];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << solve() << endl;

    return 0;
}