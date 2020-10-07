#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans += S[i] == '1';
    }
    cout << ans << endl;

    return 0;
}