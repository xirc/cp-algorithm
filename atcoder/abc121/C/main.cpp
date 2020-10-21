#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<int> A, B;

ll solve() {
    vector<pair<int,int>> AB;
    for (int i = 0; i < N; ++i) {
        AB.push_back({ A[i], B[i] });
    }
    sort(AB.begin(), AB.end());
    ll ans = 0;
    for (int i = 0; i < AB.size() && M > 0; ++i) {
        auto a = AB[i].first, b = AB[i].second;
        auto c = min(M, b);
        ans += (ll)a * c;
        M -= c;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    A.assign(N, 0);
    B.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
    }
    cout << solve() << endl;

    return 0;
}