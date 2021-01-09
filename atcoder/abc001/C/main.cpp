#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int power(int dis) {
     double v = round(double(dis * 10) / 60);
     vector<int> ps = { 2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326 };
     for (int i = 0; i < 12; ++i) {
         if (v <= ps[i]) return i;
     }
     return 12;
}

string direction(int deg, int wp) {
    if (wp == 0) return "C";
    if (deg <= 112 || deg >= 3488) return "N";
    vector<int> ds = { 337, 562, 787, 1012, 1237, 1462, 1687, 1912, 2137, 2362, 2587, 2812, 3037, 3262, 3487 };
    vector<string> ss = { "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW" };
    assert(ds.size() == ss.size());
    for (int i = 0; i < ds.size(); ++i) {
        if (deg <= ds[i]) return ss[i];
    }
    throw;
}

vector<string> solve(int deg, int dis) {
    string ans;
    int wp = power(dis);
    string dir = direction(deg, wp);
    return { dir, to_string(wp) };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int deg, dis;
    cin >> deg >> dis;
    auto ans = solve(deg, dis);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}