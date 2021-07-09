#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 0; i + 2 < N; ++i) {
        if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}