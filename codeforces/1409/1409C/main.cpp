#include <bits/stdc++.h>

using namespace std;

// O(N)
bool try_fill(int x, int y, int xi, int yi, vector<int>& ans) {
    const int N = ans.size();
    assert(x < y && xi < yi);
    int di = yi - xi;
    if ((y - x) % di != 0) {
        return false;
    }
    ans[xi] = x, ans[yi] = y;
    int dx = (y - x) / di;
    for (int i = xi - 1; i >= 0; --i) {
        ans[i] = ans[i+1] - dx;
        if (ans[i] <= 0) return false;
    }
    for (int i = xi + 1; i < yi; ++i) {
        ans[i] = ans[i-1] + dx;
    }
    for (int i = yi + 1; i < N; ++i) {
        ans[i] = ans[i-1] + dx;
    }
    return true;
}

// O(N^3) == 125_000
// 2 <= n <= 50
// 1 <= x < y <= 50
vector<int> solve(int n, int x, int y) {
    int mini = numeric_limits<int>::max();
    vector<int> ans(n, 0), tmp(n, 0);

    for (int xi = 0; xi < n; ++xi) {
        for (int yi = xi + 1; yi < n; ++yi) {
            if (try_fill(x, y, xi, yi, tmp)) {
                int maxi = tmp[n-1];
                if (maxi < mini) {
                    mini = maxi;
                    ans = tmp;
                }
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, n, x, y;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> n >> x >> y;
        auto ans = solve(n, x, y);
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}