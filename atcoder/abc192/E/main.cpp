#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M, X, Y;
vector<vector<array<int,3>>> G;

ll solve() {
    using entry = pair<ll,int>;
    priority_queue<entry, vector<entry>, greater<entry>> Q;
    ll const inf = 1e18;
    vector<ll> D(N, inf);
    Q.push({ 0, X });
    D[X] = 0;
    while (Q.size()) {
        ll t; int v;
        tie(t, v) = Q.top(); Q.pop();
        if (v == Y) {
            return t;
        }
        for (auto utk : G[v]) {
            int u = utk[0], T = utk[1], K = utk[2];
            ll tn = t;
            if (tn % K != 0) {
                tn += (K - tn % K);
            }
            if (tn + T < D[u]) {
                D[u] = tn + T;
                Q.push({ D[u], u });
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> X >> Y;
    --X, --Y;

    G.assign(N, vector<array<int,3>>());
    for (int i = 0; i < M; ++i) {
        int A, B, T, K;
        cin >> A >> B >> T >> K;
        --A, --B;
        G[A].push_back({ B, T, K });
        G[B].push_back({ A, T, K });
    }
    cout << solve() << endl;

    return 0;
}