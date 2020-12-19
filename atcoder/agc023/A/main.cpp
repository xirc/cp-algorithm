#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
vector<int> A;

ll solve() {
    vector<ll> T(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        T[i+1] = T[i] + A[i];
    }
    map<ll,ll> M;
    for (int i = 0; i < N + 1; ++i) {
        ++M[T[i]];
    }
    ll ans = 0;
    for (auto e : M) {
        auto c = e.second;
        ans += c * (c - 1) / 2;
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