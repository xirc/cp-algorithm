#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N, A, Y, X;
    cin >> N >> A >> X >> Y;
    int ans = min(N, A) * X + max(0, N - A) * Y;
    cout << ans << endl;

    return 0;
}