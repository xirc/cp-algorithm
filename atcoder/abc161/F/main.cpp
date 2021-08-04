#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

vector<ll> divisors_of(ll N) {
    set<ll> divisors;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            divisors.insert(i);
            divisors.insert(N / i);
        }
    }
    return vector<ll>(divisors.begin(), divisors.end());
}

int solve(ll N) {
    auto divisors = divisors_of(N);
    int ans = divisors_of(N-1).size() - 1;
    for (auto p : divisors) {
        if (p == 1) continue;
        ll M = N;
        while (M >= p && M % p == 0) {
            M /= p;
        }
        M = M % p;
        if (M == 1) ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}