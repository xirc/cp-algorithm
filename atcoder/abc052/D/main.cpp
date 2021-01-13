#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, A, B;
vector<int> X;

ll solve() {
    vector<vector<int>> es;
    for (int i = 1; i < N; ++i) {
        int w = X[i] - X[i-1];
        es.push_back({ w, i - 1, i });
    }

    vector<bool> has_next(N, false);
    ll ans = 0;
    sort(es.begin(), es.end());
    for (auto const& e : es) {
        ll w = e[0];
        int u = e[1];
        if (w * A >= B) continue;
        ans += w * A;
        has_next[u] = true;
    }
    for (int i = 0; i < N - 1; ++i) {
        if (has_next[i]) continue;
        ans += B;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> A >> B;
    X.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    cout << solve() << endl;

    return 0;
}