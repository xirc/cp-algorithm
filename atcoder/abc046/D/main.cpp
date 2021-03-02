#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    
    int gn, pn;
    gn = 0, pn = 0;
    for (auto c : s) {
        if (c == 'g') ++gn;
        else if (c == 'p') ++pn;
        else throw;
    }
    int ans = (gn - pn) / 2;
    cout << ans << endl;

    return 0;
}