#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, X, T;
    cin >> N >> X >> T;

    int m = (N + X - 1) / X;
    cout << (m * T) << endl;

    return 0;
}