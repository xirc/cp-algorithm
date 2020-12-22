#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, K;
vector<vector<int>> XY;

ll solve() {
    ll S = numeric_limits<ll>::max();
    for (auto& a : XY) {
        for (auto& b : XY) {
            for (auto& c : XY) {
                for (auto& d : XY) {
                    int lx = min({ a[0], b[0], c[0], d[0] });
                    int hx = max({ a[0], b[0], c[0], d[0] });
                    int ly = min({ a[1], b[1], c[1], d[1] });
                    int hy = max({ a[1], b[1], c[1], d[1] });
                    int count = 0;
                    for (auto& e : XY) {
                        int x = e[0], y = e[1];
                        if (x >= lx && x <= hx && y >= ly && y <= hy) ++count;
                    }
                    if (count >= K) {
                        S = min(S, ll(hx - lx) * ll(hy - ly));
                    }
                }
            }
        }
    }
    return S;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    XY.assign(N, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        cin >> XY[i][0] >> XY[i][1];
    }
    cout << solve() << endl;

    return 0;
}