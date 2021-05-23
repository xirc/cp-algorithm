#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<int> A;
vector<int> B, C;

ll solve() {
    map<int,int,greater<int>> mp;
    for (auto a: A) mp[a]++;
    for (int i = 0; i < M; ++i) {
        mp[C[i]] += B[i];
    }

    int n = 0;
    ll ans = 0;
    for (auto const& e : mp) {
        int m = min(e.second, N - n);
        n += m;
        ans += ll(e.first) * m;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    B.assign(M, 0);
    C.assign(M, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i] >> C[i];
    }
    cout << solve() << endl;

    return 0;
}