#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<vector<int>> A;

vector<vector<int>> solve() {
    vector<vector<int>> ans;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if ((A[y][x] & 1) == 0) continue;
            if (x + 1 < W) {
                --A[y][x];
                ++A[y][x+1];
                ans.push_back({ y, x, y, x + 1 });
            } else if (y + 1 < H) {
                --A[y][x];
                ++A[y+1][x];
                ans.push_back({ y, x, y + 1, x });
            }
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    A.assign(H, vector<int>(W, 0));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }
    auto ans = solve();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i][0] + 1 << " " << ans[i][1] + 1
            << " " << ans[i][2] + 1 << " " << ans[i][3] + 1 << endl;
    }

    return 0;
}