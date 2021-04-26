#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int price = min(N, K) * X + max(0, N - K) * Y;
    cout << price << endl;

    return 0;
}