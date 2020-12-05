#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, M;
vector<vector<ll>> xyz;

ll solve() {
    ll ans = 0;
    for (int k = 0; k < 8; ++k) {
        auto const less = [&](auto& lhs, auto& rhs) {
            ll ls = 0, rs = 0;
            for (int i = 0; i < 3; ++i) {
                if ((k >> i) & 1) {
                    ls += lhs[i];
                    rs += rhs[i];
                } else {
                    ls -= lhs[i];
                    rs -= rhs[i];
                }
            }
            return ls < rs;
        };
        sort(xyz.begin(), xyz.end(), less);
        reverse(xyz.begin(), xyz.end());
        ll xx = 0, yy = 0, zz = 0;
        for (int i = 0; i < M; ++i) {
            xx += xyz[i][0];
            yy += xyz[i][1];
            zz += xyz[i][2];
        }
        ans = max(ans, abs(xx) + abs(yy) + abs(zz));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    xyz.assign(N, vector<ll>(3, 0));
    for (int i = 0; i < N; ++i) {
        cin >> xyz[i][0] >> xyz[i][1] >> xyz[i][2]; 
    }
    cout << solve() << endl;

    return 0;
}