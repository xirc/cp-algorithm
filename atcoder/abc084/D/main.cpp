#include <bits/stdc++.h>

using namespace std;

set<int> primes;
vector<int> dp;

void build() {
    const int M = 1e5+1;

    vector<bool> is_prime(M, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < M; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j < M; j += i) {
            is_prime[j] = false;
        }
    }

    dp.assign(M, 0);
    for (int i = 0; i < M; ++i) {
        dp[i] = dp[i-1];
        if (i % 2 == 1 && is_prime[i] && is_prime[(i + 1)/2]) {
            ++dp[i];
        }
    }
}

int query(int l, int r) {
    return dp[r] - dp[l-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    build();

    int Q, l, r;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}