#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

string X;
ll M;

bool pass(ll n) {
    if (n == 0) return true;
    ll v = 0;
    for (int i = 0; i < X.size(); ++i) {
        int x = X[i] - '0';
        if (v > M / n) return false;
        v *= n;
        if (v > M - x) return false;
        v += x;
    }
    return true;
}

int minbase() {
    int n = 0;
    for (int i = 0; i < X.size(); ++i) {
        n = max(n, X[i] - '0');
    }
    return n + 1;
}

ll maxbase() {
    ll ok = 0, ng = 2e18;
    while (abs(ok - ng) > 1) {
        auto m = (ok + ng) / 2;
        if (pass(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }
    return ok;
}

ll solve() {
    if (X.size() == 1) {
        return (X[0]-'0' <= M) ? 1 : 0;
    }
    ll mini = minbase();
    ll maxi = maxbase();
    if (maxi < mini) return 0;
    return maxi - mini + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> X >> M;
    cout << solve() << endl;

    return 0;
}
