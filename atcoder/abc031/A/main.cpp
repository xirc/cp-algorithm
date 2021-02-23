#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, D;
    cin >> A >> D;
    int ans = max((A+1)*D, A*(D+1));
    cout << ans << endl;

    return 0;
}