#include <bits/stdc++.h>

bool tsort(std::vector<std::vector<int>> const& G, std::vector<int>& ans) {
    size_t const N = G.size();
    std::queue<int> Q;
    std::vector<int> in(N, 0);

    ans.clear();
    ans.reserve(N);

    for (int v = 0; v < N; ++v) {
        for (int u : G[v]) in[u]++;
    }
    for (int v = 0; v < N; ++v) {
        if (in[v] == 0) Q.push(v);
    }
    while (Q.size()) {
        int v = Q.front(); Q.pop();
        ans.push_back(v);
        for (auto u : G[v]) {
            in[u]--;
            if (in[u] == 0) Q.push(u);
        }
    }
    return ans.size() == N;
}

using namespace std;
using ll = int64_t;

ll const MOD = 1e9 + 7;
int H, W;
vector<vector<int>> A;

int N;
vector<vector<int>> G, GT;


ll solve() {
    N = H * W;
    G.assign(N, vector<int>());
    GT.assign(N, vector<int>());
    vector<int> dx = { 1, -1, 0, 0 };
    vector<int> dy = { 0, 0, 1, -1 };
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            for (int i = 0; i < 4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= H) continue;
                if (nx < 0 || nx >= W) continue;
                if (A[ny][nx] > A[y][x]) {
                    int u = y * W + x;
                    int v = ny * W + nx;
                    G[u].push_back(v);
                    GT[v].push_back(u);
                }
            }
        }
    }

    vector<int> vs;
    bool pass = tsort(G, vs);
    assert(pass);

    ll ans = 0;
    vector<ll> DP(N, 0);
    for (int v : vs) {
        for (int u : GT[v]) {
            DP[v] += DP[u];
            DP[v] %= MOD;
        }
        DP[v] += 1;
        DP[v] %= MOD;
        ans += DP[v];
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W;
    A.assign(H, vector<int>(W));
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            cin >> A[y][x];
        }
    }
    cout << solve() << endl;

    return 0;
}