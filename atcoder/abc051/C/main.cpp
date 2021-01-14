#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int sx, sy, tx, ty;

void transpose(vector<char>& route) {
    if (tx < sx) {
        for (auto &c : route) {
            if (c == 'R') c = 'L';
            else if (c == 'L') c = 'R';
        }
    }
    if (ty < sy) {
        for (auto &c : route) {
            if (c == 'U') c = 'D';
            else if (c == 'D') c = 'U';
        }
    }
}

void rotate(vector<char>& route) {
    for (auto &c : route) {
        if (c == 'U') c = 'R';
        else if (c == 'R') c = 'U';
        else if (c == 'D') c = 'L';
        else if (c == 'L') c = 'U';
    }
}

string solve() {
    int W = abs(tx - sx), H = abs(ty - sy);
    if (W == 0 && H == 0) return "";

    int lx = min(sx, tx), ly = min(sy, ty);
    int rx = max(sx, tx), ry = min(sy, ty);

    vector<char> route;
    if (W == 0 || H == 0) {
        int C = W | H;
        for (int i = 0; i < C; ++i) route.push_back('U');
        route.push_back('R');
        for (int i = 0; i < C; ++i) route.push_back('D');
        route.push_back('L');
        route.push_back('L');
        for (int i = 0; i < C; ++i) route.push_back('U');
        route.push_back('R');
        route.push_back('U');
        route.push_back('R');
        route.push_back('R');
        for (int i = 0; i < C + 2; ++i) route.push_back('D');
        route.push_back('L');
        route.push_back('L');
        route.push_back('U');
        if (H == 0) rotate(route);
    } else {
        for (int x = 0; x < W; ++x) route.push_back('R');
        for (int y = 0; y < H; ++y) route.push_back('U');
        for (int x = 0; x < W; ++x) route.push_back('L');
        for (int y = 0; y < H; ++y) route.push_back('D');
        route.push_back('D');
        for (int x = 0; x < W + 1; ++x) route.push_back('R');
        for (int y = 0; y < H + 1; ++y) route.push_back('U');
        route.push_back('L');
        route.push_back('U');
        for (int x = 0; x < W + 1; ++x) route.push_back('L');
        for (int y = 0; y < H + 1; ++y) route.push_back('D');
        route.push_back('R');
    }
    transpose(route);

    return string(route.begin(), route.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> sx >> sy >> tx >> ty;
    cout << solve() << endl;

    return 0;
}