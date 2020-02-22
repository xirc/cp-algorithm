// https://www.spoj.com/problems/ZSUM/

#include <iostream>

using namespace std;

// (a ** b) % m
long long powmod(long long a, long long b, long long m) {
    long long ans = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

long long solve(long long N, long long K) {
    const long long M = 1e7+7;
    long long ans = 0;
    ans = (ans + powmod(N, K, M)) % M;
    ans = (ans + powmod(N-1, K, M) * 2) % M;
    ans = (ans + powmod(N, N, M)) % M;
    ans = (ans + powmod(N-1, N-1, M) * 2) % M;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        long long N, K;
        cin >> N >> K;
        if (N == 0 && K == 0) {
            break;
        }
        cout << solve(N, K) << endl;
    }

    return 0;
}