#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;

const int L = 1e5 + 1;
const ll MOD = 1e9 + 7;
vector<ll> factorial(L);

ll solve() {
    if (abs(N - M) > 1) return 0;

    factorial[0] = 1;
    for (int i = 1; i < L; ++i) {
        factorial[i] = factorial[i-1] * i % MOD;
    }

    if (N != M) {
        return factorial[N] * factorial[M] % MOD;
    } else {
        return factorial[N] * factorial[M] * 2 % MOD;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cout << solve() << endl;

    return 0;
}