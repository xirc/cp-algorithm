#include <bits/stdc++.h>

inline int64_t binary_search(
    std::function<bool(int64_t)> const& predicate,
    int64_t ng,
    int64_t ok
) {
    assert(!predicate(ng) && predicate(ok));
    while (abs(ok - ng) > 1) {
        auto m = (ok + ng) / 2;
        if (predicate(m)) ok = m;
        else ng = m;
    }
    return ok;
}

using namespace std;
using ll = int64_t;
using ff = long double;

int H, W, T;
vector<string> M;
int sX, sY, gX, gY;

vector<int> dx = { 1, -1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };
bool pass(ll XX) {
    priority_queue<array<ll,3>> Q;
    vector<vector<bool>> done(H, vector<bool>(W, false));
    Q.push({ 0, sX, sY });
    while (Q.size()) {
        auto entry = Q.top(); Q.pop();
        ll t = -entry[0];
        int x = entry[1], y = entry[2];
        if (done[y][x]) continue;
        done[y][x] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= W) continue;
            if (ny < 0 || ny >= H) continue;
            if (done[ny][nx]) continue;
            if (nx == gX && ny == gY) {
                return t + 1 <= T;
            }
            ll nt = t + (M[ny][nx] == '.' ? 1 : XX);
            Q.push({ -nt, nx, ny });
        }
    }
    return false;
}

ll solve() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (M[y][x] == 'S') {
                sX = x, sY = y;
            }
            if (M[y][x] == 'G') {
                gX = x, gY = y;
            }
        }
    }
    ll ng = T + 1, ok = 1;
    return binary_search(pass, ng, ok);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> T;
    M.assign(H, "");
    for (int y = 0; y < H; ++y) {
        cin >> M[y];
    }
    cout << solve() << endl;

    return 0;
}