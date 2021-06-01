#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            ans += i * 100 + j;
        }
    }
    cout << ans << endl;

    return 0;
}