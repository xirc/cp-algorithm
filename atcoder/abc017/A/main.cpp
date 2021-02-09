#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> s(3), e(3);
    for (int i = 0; i < 3; ++i) {
        cin >> s[i] >> e[i];
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans += s[i] / 10 * e[i];
    }
    cout << ans << endl;

    return 0;
}