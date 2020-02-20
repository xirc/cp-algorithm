// https://www.spoj.com/problems/ROHAAN/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int inf = 1e8;
int N, R;
vector<vector<int>> D;
vector<pair<int,int>> orders;

int solve() {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    int ans = 0;
    for (auto p : orders) {
        ans += D[p.first][p.second];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        D.assign(N, vector<int>(N, inf));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> D[i][j];
            }
        }
        cin >> R;
        orders.assign(R, {});
        for (int i = 0; i < R; ++i) {
            int s, d;
            cin >> s >> d;
            --s, --d;
            orders[i] = { s, d };
        }
        auto ans = solve();
        cout << "Case #" << (t+1) << ": " << ans << endl;
    }

    return 0;
}