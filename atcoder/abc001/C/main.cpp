#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int power(int dis) {
     vector<int> ps = { 24, 154, 334, 544, 794, 1074, 1384, 1714, 2074, 2444, 2844, 3264 };
     assert(ps.size() == 12);
     for (int i = 0; i < 12; ++i) {
         if (dis * 100 <= ps[i] * 60) return i;
     }
     return 12;
}

string direction(int deg) {
    vector<int> ds = {
        112, 337, 562, 787, 1012, 1237, 1462, 1687, 1912, 2137, 2362, 2587, 2812, 3037, 3262, 3487
    };
    vector<string> ss = {
        "N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"
    };
    assert(ds.size() == ss.size());
    for (int i = 0; i < ds.size(); ++i) {
        if (deg <= ds[i]) return ss[i];
    }
    return "N";
}

vector<string> solve(int deg, int dis) {
    string ans;
    int wp = power(dis);
    string dir = wp > 0 ? direction(deg) : "C";
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