// https://www.spoj.com/problems/NAKANJ/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos {
    int x, y;
    bool operator==(const pos& other) {
        return x == other.x && y == other.y;
    }
    pos operator+(const pos& other) {
        return pos { x + other.x, y + other.y };
    }
    static pos from_chess(string& str) {
        int x = str[0] - 'a';
        int y = str[1] - '1';
        return pos { x, y };
    }
};

int solve(pos s, pos d) {
    queue<pair<pos,int>> Q;
    Q.push({s,0});
    static int dx[] = { -2, -1, 1, 2,  2,  1, -1, -2 };
    static int dy[] = {  1,  2, 2, 1, -1, -2, -2, -1 };
    while (!Q.empty()) {
        auto c = Q.front(); Q.pop();
        if (c.first == d) {
            return c.second;
        }
        for (int i = 0; i < 8; ++i) {
            auto n = c.first + pos { dx[i], dy[i] };
            if (n.x < 0 || n.x >= 8 || n.y < 0 || n.y >= 8) continue;
            Q.push({n,c.second+1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s, d;
        cin >> s >> d;
        int ans = solve(pos::from_chess(s), pos::from_chess(d));
        cout << ans << endl;
    }

    return 0;
}