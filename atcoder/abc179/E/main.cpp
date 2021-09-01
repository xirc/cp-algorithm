#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    int X, M;
    cin >> N >> X >> M;

    vector<int> ps;
    unordered_set<int> ss;
    ll a = X;
    while (ss.find(a) == ss.end()) {
        ps.push_back(a);
        ss.insert(a);
        a = a * a % M;
    }

    // [B..., A...]
    int K = ps.size();
    int A = distance(find(ps.begin(), ps.end(), a), ps.end());
    int B = ps.size() - A;
    ll S = 0;
    for (int i = B; i < K; ++i) {
        S += ps[i];
    }

    ll ans = 0;
    for (int i = 0; i < min(N,ll(B)); ++i) {
        ans += ps[i];
    }
    N -= min(N, ll(B));
    ans += (N / A) * S;
    N %= A;
    for (int i = 0; i < N; ++i) {
        ans += ps[B+i];
    }
    cout << ans << endl;

    return 0;
}