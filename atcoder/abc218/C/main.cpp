#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int N;
vector<string> S;
vector<string> T;

vector<string> compress(vector<string> const& g) {
    int lx = g[0].size() - 1, ux = 0;
    int ly = g.size() - 1, uy = 0;
    for (int y = 0; y < g.size(); ++y) {
        for (int x = 0; x < g[0].size(); ++x) {
            if (g[y][x] == '#') {
                ly = min(ly, y);
                uy = max(uy, y);
                lx = min(lx, x);
                ux = max(ux, x);
            }
        }
    }
    int const H = uy - ly + 1, W = ux - lx + 1;
    vector<string> r(H, string(W, '.'));
    for (int y = 0; y < g.size(); ++y) {
        for (int x = 0; x < g[0].size(); ++x) {
            if (g[y][x] == '#') {
                int yy = y - ly;
                int xx = x - lx;
                r[yy][xx] = '#';
            }
        }
    }
    return r;
}

vector<string> rotate(vector<string> const& g) {
    int const H = g[0].size(), W = g.size();
    vector<string> r(H, string(W, ' '));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            r[y][x] = g[W-1-x][y];
        }
    }
    return r;
}

bool solve() {
    auto s = compress(S), t = compress(T);
    for (int i = 0; i < 4; ++i) {
        if (s == t) return true;
        t = rotate(t);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    S.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    T.assign(N, "");
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    auto ans = solve() ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}