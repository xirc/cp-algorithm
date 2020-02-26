// https://www.spoj.com/problems/DISQUERY/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct edge { int to, length; };

const int inf = 1e8;
struct Solver {
    int N, L;
    vector<int> tin, tout;
    vector<vector<int>> up, shortest, longest;

    Solver(vector<vector<edge>>& adj) {
        N = adj.size();
        tin.assign(N, 0);
        tout.assign(N, 0);
        L = ceil(log2(N)) + 1;
        up.assign(N, vector<int>(L));
        shortest.assign(N, vector<int>(L, inf));
        longest.assign(N, vector<int>(L, 0));
        int timer = 0;
        dfs_euler(adj, 0, 0, 0, true, timer);
    }
    void dfs_euler(vector<vector<edge>>& adj, int v, int p, int l, bool root, int& timer) {
        tin[v] = timer++;
        up[v][0] = p;
        shortest[v][0] = root ? inf : l;
        longest[v][0] = root ? 0 : l;
        for (int i = 1; i < L; ++i) {
            int u = up[v][i-1];
            up[v][i] = up[u][i-1];
            shortest[v][i] = min(shortest[v][i-1], shortest[u][i-1]);
            longest[v][i] = max(longest[v][i-1], longest[u][i-1]);
        }
        for (auto u : adj[v]) {
            if (u.to == p) continue;
            dfs_euler(adj, u.to, v, u.length, false, timer);
        }
        tout[v] = timer++;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    pair<int,int> query(int u, int v) {
        int ans_short = inf, ans_long = 0;
        for (int i = L - 1; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                ans_short = min(ans_short, shortest[u][i]);
                ans_long = max(ans_long, longest[u][i]);
                u = up[u][i];
            }
            if (!is_ancestor(up[v][i], u)) {
                ans_short = min(ans_short, shortest[v][i]);
                ans_long = max(ans_long, longest[v][i]);
                v = up[v][i];
            }
        }
        if (up[u][0] == v) {
            ans_short = min(ans_short, shortest[u][0]);
            ans_long = max(ans_long, longest[u][0]);
        } else if (up[v][0] == u) {
            ans_short = min(ans_short, shortest[v][0]);
            ans_long = max(ans_long, longest[v][0]);
        } else {
            ans_short = min({ans_short, shortest[u][0], shortest[v][0] });
            ans_long = max({ans_long, longest[u][0], longest[v][0] });
        }
        return { ans_short, ans_long };
    }
};

vector<vector<edge>> adj;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    adj.assign(N, vector<edge>());
    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    Solver solver(adj);

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        auto ans = solver.query(a, b);
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}