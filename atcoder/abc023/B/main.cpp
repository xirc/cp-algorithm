#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int const N, string const& S) {
    if (N % 2 == 0) {
        return -1;
    }
    int const M = N / 2;
    if (S[M] != 'b') return -1;

    int l = M - 1, r = M + 1;
    int n = 1;
    vector<string> pairs = {
        "bb",
        "ac",
        "ca",
    };
    while (l >= 0 && r < N) {
        if (pairs[n%3][0] != S[l]) return -1;
        if (pairs[n%3][1] != S[r]) return -1;
        ++n;
        --l;
        ++r;
    }
    return n-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    string S;
    cin >> N >> S;
    cout << solve(N, S) << endl;

    return 0;
}