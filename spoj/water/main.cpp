// https://www.spoj.com/problems/WATER/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
    int x, y;
};
bool operator<(const pos& lhs, const pos& rhs) {
    return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
}

int solve(vector<vector<int>>& field) {
    const int N = field.size(), M = field[0].size();
    
    int ans = 0;
    vector<vector<bool>> fix(N, vector<bool>(M));
    priority_queue<pair<int,pos>> Q;

    for (int x = 0; x < N; ++x) {
        fix[x][0] = fix[x][M-1] = true;
        Q.push({-field[x][0], pos{x,0}});
        Q.push({-field[x][M-1], pos{x,M-1}});
    }
    for (int y = 0; y < M; ++y) {
        fix[0][y] = fix[N-1][y] = true;
        Q.push({-field[0][y], pos{0,y}});
        Q.push({-field[N-1][y], pos{N-1,y}});
    }

    while (!Q.empty()) {
        auto c = Q.top(); Q.pop();
        static int dx[] = { 0, 1, 0, -1 };
        static int dy[] = { 1, 0, -1, 0 };
        for (int i = 0; i < 4; ++i) {
            int nx = c.second.x + dx[i];
            int ny = c.second.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (fix[nx][ny]) continue;

            fix[nx][ny] = true;
            const int h = field[c.second.x][c.second.y];
            if (field[nx][ny] < h) {
                int volume = h - field[nx][ny];
                ans += volume;
                field[nx][ny] = h;
            }
            Q.push({-field[nx][ny], pos{nx,ny}});
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N, M;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        vector<vector<int>> field(N, vector<int>(M));
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < M; ++y) {
                cin >> field[x][y];
            }
        }
        cout << solve(field) << endl;
    }

    return 0;
}