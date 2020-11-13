#include <bits/stdc++.h>

using namespace std;

int solve(int X) {
    int ans = 0;
    for (int i = 1; i < 10; ++i) {
        int xx = i;
        int c = 1;
        while (xx < 10000) {
            ans += c;
            if (xx == X) return ans;
            xx = xx * 10 + i;
            ++c;
        }
    }
    throw;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, X;
    
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> X;
        cout << solve(X) << endl;
    }

    return 0;
}