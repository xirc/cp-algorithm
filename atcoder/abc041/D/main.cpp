#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N, M;
vector<array<int,2>> es;

ll solve() {
    int const K = 1 << N;
    vector<ll> DP(K, 0);
    DP[0] = 1;
    for (int s = 1; s < K; ++s) {
        bitset<16> bs(s);
        for (int v = 0; v < N; ++v) {
            if (!bs[v]) continue;
            bool pass = true;
            for (auto const& e : es) {
                int x = e[0], y = e[1];
                if (x == v && bs[y]) pass = false;
            }
            if (pass) {
                int ps = s ^ (1 << v);
                DP[s] += DP[ps];
            }
        }
    }
    return DP[K-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    es.assign(M, { 0, 0 });
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        es[i] = { x, y };
    }
    cout << solve() << endl;

    return 0;
}