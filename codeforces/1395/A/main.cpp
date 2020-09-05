#include <bits/stdc++.h>

using namespace std;

bool solve(int r, int g, int b, int w) {
    auto count_odds = [&]() {
        int ans = 0;
        ans += r & 1;
        ans += g & 1;
        ans += b & 1;
        ans += w & 1;
        return ans;
    };

    if (r == 0 || g == 0 || b == 0) {
        return count_odds() <= 1;
    }

    int odds = 0;
    odds += r & 1;
    odds += g & 1;
    odds += b & 1;
    if (odds >= 2) {
        --r;
        --g;
        --b;
        ++w;
    }
    return count_odds() <= 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, r, g, b, w;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> r >> g >> b >> w;
        auto ans = solve(r,g,b,w) ? "Yes" : "No";
        cout << ans << endl;
    }

    return 0;
}