#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
ll H;
vector<ll> A, B;

ll solve() {
    const int ma = *max_element(A.begin(), A.end());
    vector<vector<ll>> AB;
    for (int i = 0; i < N; ++i) {
        AB.push_back({ B[i], A[i] });
    }
    sort(AB.begin(), AB.end());
    reverse(AB.begin(), AB.end());

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll a = AB[i][1], b = AB[i][0];
        if (b <= ma) break;
        if (H <= 0) break;
        H -= b;
        ++ans;
    }
    if (H > 0) {
        ans += (H + ma -1) / ma;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> H;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}