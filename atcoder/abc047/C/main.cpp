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
    for (int i = 1; i < (int)S.size(); ++i) {
        if (S[i] != S[i-1]) ++ans;
    }
    cout << ans << endl;

    return 0;
}