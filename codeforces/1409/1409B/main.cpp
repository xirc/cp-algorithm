#include <bits/stdc++.h>

using namespace std;

long long solve(int a, int b, int x, int y, int n) {
    long long ans = numeric_limits<long long>::max();
    {
        int da = min(a - x, n);
        int db = min(b - y, n - da);
        ans = min(ans, (long long)(a - da) * (b - db));
    }
    {
        int db = min(b - y, n);
        int da = min(a - x, n - db);
        ans = min(ans, (long long)(a - da) * (b - db));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    int a, b, x, y, n;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> a >> b >> x >> y >> n;
        cout << solve(a, b, x, y, n) << endl;
    }

    return 0;
}