#include <bits/stdc++.h>

using namespace std;

// O(N*N)
int solve(int n, int x) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int k = x - i - j;
            if (k >= j + 1 && k <= n) ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    while (cin >> n >> x, n != 0 || x != 0) {
        cout << solve(n, x) << endl;
    }

    return 0;
}