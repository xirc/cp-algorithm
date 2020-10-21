#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<int> A, B;

ll solve() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    for (int i = 0; i < N; ++i) {
        Q.push({ A[i], B [i] });
    }
    ll ans = 0;
    while (M > 0) {
        auto ab = Q.top(); Q.pop();
        auto a = ab.first, b = ab.second;
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