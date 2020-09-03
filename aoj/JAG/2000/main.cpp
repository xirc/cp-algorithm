#include <bits/stdc++.h>

using namespace std;

const int K = 21;
int N, M;
vector<vector<bool>> G;
vector<pair<char,int>> OPS;

vector<int> DXs = { 0, 1, 0, -1 };
vector<int> DYs = { 1, 0, -1, 0 };

int to_index(char c) {
    switch (c)
    {
    case 'N':
        return 0;
    case 'E':
        return 1;
    case 'S':
        return 2;
    case 'W':
        return 3;
    default:
        throw;
    }
}

bool solve() {
    int nn = 0;
    int cx = 10, cy = 10;
    for (auto op : OPS) {
        auto dir = to_index(op.first);
        auto distance = op.second;
        auto dx = DXs[dir], dy = DYs[dir];
        for (int d = 0; d < distance; ++d) {
            cx += dx, cy += dy;
            if (G[cy][cx]) {
                G[cy][cx] = false;
                nn++;
            }
        }
    }
    return nn == N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> N, N != 0) {
        G.assign(K, vector<bool>(K, false));
        for (int i = 0; i < N; ++i) {
            int x, y;
            cin >> x >> y;
            G[y][x] = true;
        }
        cin >> M;
        OPS.clear();
        for (int i = 0; i < M; ++i) {
            char direction; int distance;
            cin >> direction >> distance;
            OPS.push_back({ direction, distance });
        }
        auto ans = solve() ? "Yes" : "No";
        cout << ans << endl;
    }

    return 0;
}