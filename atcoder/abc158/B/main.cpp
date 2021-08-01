#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, A, B;
    cin >> N >> A >> B;
    ll S = N / (A + B);
    ll R = N % (A + B);
    ll C = A * S + min(R, A);
    cout << C << endl;

    return 0;
}