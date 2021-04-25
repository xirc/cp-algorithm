#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> ls(3);
    cin >> ls[0] >> ls[1] >> ls[2];
    int ans = 0;
    if (ls[0] == ls[1]) ans = ls[2];
    if (ls[1] == ls[2]) ans = ls[0];
    if (ls[2] == ls[0]) ans = ls[1];
    cout << ans << endl;

    return 0;
}