#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<string> ss;
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        ss.insert(s);
    }
    auto ans = ss.size() == 4 ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}