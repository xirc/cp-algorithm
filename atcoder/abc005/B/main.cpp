#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    int ans = 100;
    for (int i = 0; i < N; ++i) {
        int ai;
        cin >> ai;
        ans = min(ans, ai);
    }
    cout << ans << endl;

    return 0;
}