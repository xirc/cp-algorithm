#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 1e6;
const ll MOD = 998244353;
vector<ll> fact(M), fact_inv(M), inv(M);

// O(N)
void build_nCk() {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 2; i < M; ++i) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
    }
}

// O(1)
ll nCk(int n, int k) {
    assert(n >= k);
    assert(n >= 0 && k >= 0);
    return fact[n] * (fact_inv[k] * fact_inv[n-k] % MOD) % MOD;
}

// O( N logN )
ll solve(int N, int K, vector<int> const& L, vector<int> const& R) {
    using event = pair<int,bool>;
    vector<event> events;
    events.reserve(2 * N);
    for (int i = 0; i < N; ++i) {
        events.push_back({ L[i], false });
        events.push_back({ R[i], true });
    }
    sort(events.begin(), events.end());

    build_nCk();
    int nn = 0;
    ll ans = 0;
    for (auto const& event : events) {
        auto start = !event.second;
        if (start) {
            ++nn;
        } else {
            if (nn >= K) {
                ans = (ans + nCk(nn - 1, K - 1)) % MOD;
            }
            --nn;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    vector<int> L, R;

    cin >> N >> K;
    L.assign(N, 0);
    R.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> L[i] >> R[i];
    }
    auto ans = solve(N, K, L, R);
    cout << ans << endl;

    return 0;
}