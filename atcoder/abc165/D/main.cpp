#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll A, B, N;
    cin >> A >> B >> N;
    ll x = min(N, B-1);
    ll g = (A * x) / B - A * (x / B);
    cout << g << endl;

    return 0;
}