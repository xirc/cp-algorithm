#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N, C;
vector<vector<int>> DD, CC;

ll solve() {
    vector<vector<ll>> SC(3, vector<ll>(C, 0));
    for (int color = 0; color < C; ++color) {
        for (int k = 0; k < 3; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if ((i + 1 + j + 1) % 3 != k) continue;
                    int fromColor = CC[i][j];
                    SC[k][color] += DD[fromColor][color];
                }
            }
        }
    }
    
    ll ans = numeric_limits<ll>::max();
    for (int c0 = 0; c0 < C; ++c0) {
        for (int c1 = 0; c1 < C; ++c1) {
            if (c1 == c0) continue;
            for (int c2 = 0; c2 < C; ++c2) {
                if (c2 == c1 || c2 == c0) continue;
                ll score = SC[0][c0] + SC[1][c1] + SC[2][c2];
                ans = min(ans, score);
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;
    DD.assign(C, vector<int>(C, 0));
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> DD[i][j];
        }
    }
    CC.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> CC[i][j];
            --CC[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}