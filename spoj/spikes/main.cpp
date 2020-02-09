// https://www.spoj.com/problems/SPIKES/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M, C;
vector<vector<char>> MAP;

struct pos { int x, y; };
bool solve() {
    const int INF = 1e7;
    vector<pos> vert;
    vector<int> entrances;
    vector<int> treasures;
    vector<vector<int>> distance;

    // parse MAP
    {
        static int dx[] = { -1, 0, 1, 0 };
        static int dy[] = { 0, 1, 0, -1 };
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < M; ++y) {
                vert.push_back(pos{x,y});
                int i = vert.size() - 1;
                if (MAP[x][y] == '@') entrances.push_back(i);
                if (MAP[x][y] == 'x') treasures.push_back(i);
            }
        }
        distance.assign(N*M, vector<int>(N*M, INF));
        for (int i = 0; i < vert.size(); ++i) {
            for (int j = 0; j < vert.size(); ++j) {
                if (i == j) {
                    distance[i][j] = 0;
                    continue;
                }
                pos s = vert[i], d = vert[j];
                if (abs(s.x - d.x) + abs(s.y - d.y) != 1) continue;
                if (MAP[s.x][s.y] == '#' || MAP[d.x][d.y] == '#') continue;
                distance[i][j] = MAP[d.x][d.y] == 's' ? 1 : 0;
            }
        }
    }

    // Warshall-Floyd
    for (int k = 0; k < vert.size(); ++k) {
        for (int i = 0; i < vert.size(); ++i) {
            for (int j = 0; j < vert.size(); ++j) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    // Solve
    int cost = 0;
    for (auto treasure : treasures) {
        int min_cost = INF;
        for (auto entrance : entrances) {
            min_cost = min(min_cost, distance[entrance][treasure]);
        }
        if (min_cost == INF) {
            return false;
        } else {
            cost += min_cost * 2; // in-out
        }
    }

    return cost <= C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> C;
    MAP.assign(N, vector<char>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> MAP[i][j];
        }
    }
    cout << (solve() ? "SUCCESS" : "IMPOSSIBLE") << endl;

    return 0;
}