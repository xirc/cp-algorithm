#include <bits/stdc++.h>

using namespace std;

const int MAX = 128;
vector<pair<int,int>> solve(const int W, const int H, const int sx, const int sy) {
    vector<pair<int,int>> ans;
    vector<bitset<MAX>> visited(MAX, bitset<MAX>(0));
    
    ans.reserve(MAX * MAX);
    int x = sx, y = sy;
    while (true) {
        // push all columns in row y
        ans.push_back({ x, y });
        visited[y][x] = true;
        int lx;
        for (int nx = 0; nx < W; ++nx) {
            if (x == nx) continue;
            lx = nx;
            ans.push_back({ nx, y });
            visited[y][nx] = true;
        }
        x = lx;

        // pick next row
        int ny;
        for (ny = 0; ny < H; ++ny) {
            if (visited[ny].count() == W) {
                continue;
            }
            break;
        }
        if (ny == H) {
            return ans;
        }
        y = ny;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, sx, sy;
    cin >> N >> M >> sx >> sy;
    --sx, -- sy;
    auto ans = solve(N, M, sx, sy);
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    return 0;
}