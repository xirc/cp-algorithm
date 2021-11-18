#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M, K;
vector<int> U, V;

ll const MOD = 998244353;
ll modsub(ll a, ll b) {
    return (((a - b) % MOD) + MOD) % MOD;
}
ll solve() {
    vector<ll> cur(N, 0), next(N, 0);
    cur[0] = 1;
    for (int kk = 0; kk < K; ++kk) {
        ll ss = 0;
        for (int i = 0; i < N; ++i) {
            ss += cur[i];
            ss %= MOD;
        }
        for (int i = 0; i < N; ++i) {
            next[i] = modsub(ss, cur[i]);
        }
        for (int i = 0; i < M; ++i) {
            next[V[i]] = modsub(next[V[i]], cur[U[i]]);
            next[U[i]] = modsub(next[U[i]], cur[V[i]]);
        }
        swap(cur, next);
    }
    return cur[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    U.assign(M, 0);
    V.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> U[i] >> V[i];
        --U[i], --V[i];
    }
    cout << solve() << endl;

    return 0;
}