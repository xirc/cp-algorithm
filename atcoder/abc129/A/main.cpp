#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int P, Q, R;
    cin >> P >> Q >> R;
    int all = P + Q + R;
    int maxT = max({ P, Q, R });
    cout << all - maxT << endl;

    return 0;
}