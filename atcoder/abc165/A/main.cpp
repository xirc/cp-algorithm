#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, K;
    cin >> K >> A >> B;

    int lb = (A + K - 1) / K;
    int ub = B / K;
    bool possible = lb <= ub;
    cout << (possible ? "OK" : "NG") << endl;

    return 0;
}