#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int solve(ull x) {
    int ans = 0;
    ull base = 1;
    ull n = 0;
    while (true) {
        n = base * base + n * 2;
        base *= 2;
        if (n > x) break;
        x -= n;
        ++ans;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    ull x;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> x;
        cout << solve(x) << endl;
    }

    return 0;
}