#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char solve(string const& S, ll K) {
    const int N = S.size();
    int i;
    for (i = 0; i < N; ++i) {
        if (S[i] != '1') break;
    }
    if (i == N) return '1';
    if (i > K - 1) return '1';
    return S[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    ll K;
    cin >> S >> K;
    cout << solve(S, K) << endl;

    return 0;
}