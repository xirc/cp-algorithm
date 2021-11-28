#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T;
    cin >> S >> T;
    assert(S != T);
    auto ans = (S < T) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}