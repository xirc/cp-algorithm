#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, K;
    cin >> N >> K;
    ll z0 = N % K;
    ll z1 = K - z0;
    ll z = min(z0, z1);
    cout << z << endl;

    return 0;
}