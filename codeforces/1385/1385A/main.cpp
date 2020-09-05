#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int x, int y, int z) {
    if (x == y) {
        if (x < z) return {};
        return { x, z, z };
    } else if (y == z) {
        if (y < x) return {};
        return { x, x, y };
    } else if (x == z) {
        if (x < y) return  {};
        return { y, x, y };
    } else {
        return {};
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        int x, y, z;
        cin >> x >> y >> z;
        auto ans = solve(x, y, z);
        if (ans.size() == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        }
    }

    return 0;
}