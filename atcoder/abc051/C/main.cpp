#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int sx, sy, tx, ty;

string solve() {
    int W = tx - sx, H = ty - sy;
    assert(W > 0 && H > 0);

    vector<char> route;
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

    return string(route.begin(), route.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> sx >> sy >> tx >> ty;
    cout << solve() << endl;

    return 0;
}