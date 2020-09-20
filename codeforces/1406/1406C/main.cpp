#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;
vector<int> parents;
vector<int> subtree_size;

void dfs(int v, int p) {
    parents[v] = p;
    subtree_size[v] = 1;
    for (int const u : G[v]) {
        if (u == p) continue;
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
    }
}

vector<vector<int>> solve() {
    parents.assign(N, -1);
    subtree_size.assign(N, 0);
    dfs(0, -1);

    int mini = N;
    vector<int> centroids;
    for (int v = 0; v < N; ++v) {
        int size = N - subtree_size[v];
        for (int const u : G[v]) {
            if (u == parents[v]) continue;
            size = max(size, subtree_size[u]);
        }
        if (size > mini) continue;
        if (size < mini) {
            mini = size;
            centroids.clear();
        }
        centroids.push_back(v);
    }
    assert(centroids.size() == 1 || centroids.size() == 2);

    vector<vector<int>> ans;
    if (centroids.size() == 1) {
        const int v = centroids[0];
        const int u = G[v][0];
        ans.push_back({ v, u });
        ans.push_back({ v, u });
    } else if (centroids.size() == 2) {
        const int v = centroids[0], u = centroids[1];
        int w = -1;
        for (int i = 0; i < G[v].size(); ++i) {
            if (G[v][i] != u) {
                w = G[v][i];
                break;
            }
        }
        if (w < 0) throw;
        ans.push_back({ v, w });
        ans.push_back({ u, w });
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, x, y;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        G.assign(N, vector<int>());
        for (int i = 0; i < N - 1; ++i) {
            cin >> x >> y;
            --x, --y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        auto ans = solve();
        for (int i = 0; i < 2; ++i) {
            cout << ans[i][0] + 1 << " " << ans[i][1] + 1 << endl;
        }
    }

    return 0;
}