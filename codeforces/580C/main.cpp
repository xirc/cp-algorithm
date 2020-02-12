// https://codeforces.com/problemset/problem/580/C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<bool> cat;
vector<vector<int>> adj;

vector<bool> used;
int dfs(int v, int m) {
    int ans = 0;
    int childs = 0;

    if (m > M) return 0;

    for (auto u : adj[v]) {
        if (used[u]) continue;
        used[u] = true;
        childs++;
        int lm = cat[u] ? (m + 1) : 0;
        int la = dfs(u, lm);
        ans += la;
    }
    if (childs == 0) {
        return 1;
    } else {
        return ans;
    }
}

int solve() {
    used.assign(N, false);
    used[0] = true;
    return dfs(0, cat[0] ? 1 : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cat.assign(N, 0);
    adj.assign(N, vector<int>());
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        cat[i] = a == 1;
    }
    for (int i = 0; i < N-1; ++i) {
        int x, y;
        cin >> x >> y; --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << solve() << endl;

    return 0;
}