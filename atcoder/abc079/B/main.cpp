#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N) {
    if (N == 0) return 2;
    if (N == 1) return 1;
    ll a = 2, b = 1;
    ll c;
    for (int i = 2; i <= N; ++i) {
        c = b + a;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    cout << solve(N) << endl;

    return 0;
}