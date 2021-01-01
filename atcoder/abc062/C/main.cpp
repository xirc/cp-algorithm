#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll diff(vector<ll> const& ss) {
    auto mini = *min_element(ss.begin(), ss.end());
    auto maxi = *max_element(ss.begin(), ss.end());
    assert(mini >= 0 && maxi >= 0);
    return abs(maxi - mini);
}

ll solve(ll H, ll W) {
    vector<ll> s1 = { W * (H / 3), W * (H - H / 3 * 2) };
    vector<ll> s2 = { W * ((H+2) / 3), W * (H - (H+2) / 3 * 2) };
    vector<ll> s3 = { (W / 2) * (H - H / 3), (W - W / 2) * (H - H / 3), W * (H / 3) };
    vector<ll> s4 = { (W / 2) * (H - (H+2) / 3), (W - W / 2) * (H - (H+2) / 3), W * ((H+2) / 3) };

    return min({
        diff(s1), diff(s2), diff(s3), diff(s4)
    });
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W;
    cin >> H >> W;
    cout << min(solve(H,W), solve(W,H)) << endl;

    return 0;
}