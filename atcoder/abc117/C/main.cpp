#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<int> X;

ll solve() {
    if (M <= N) return 0;

    ll ans = 0;
    priority_queue<int, vector<int>, greater<int>> Q;
    sort(X.begin(), X.end());
    for (int i = 0; i + 1 < M; ++i) {
        Q.push(X[i+1] - X[i]);
    }
    while (Q.size() >= N) {
        auto dn = Q.top(); Q.pop();
        ans += dn;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    X.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
    }
    cout << solve() << endl;

    return 0;
}