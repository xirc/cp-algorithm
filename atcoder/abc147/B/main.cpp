#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0, j = S.size() - 1; i < j; ++i, --j) {
        if (S[i] != S[j]) ++ans;
    }
    cout << ans << endl;

    return 0;
}