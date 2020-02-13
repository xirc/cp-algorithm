// https://codeforces.com/contest/24/problem/A

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct edge { int to, cost; };

int N;
vector<vector<edge>> adj;

vector<bool> used;
int dfs(int s, int v, int c, int n) {
    if (n == N) {
        for (auto e : adj[v]) {
            if (e.to == s) return c + e.cost;
        }
        return 1e8;
    }
    int ans = 1e8;
    for (auto e : adj[v]) {
        if (used[e.to]) continue;
        used[e.to] = true;
        ans = min(ans, dfs(s, e.to, c + e.cost, n+1));
        used[e.to] = false;
    }
    return ans;
}

int solve() {
    used.assign(N, false);
    return dfs(0, 0, 0, 1);
}

int main() {
    cin >> N;
    adj.assign(N, vector<edge>());
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back(edge { b, 0 });
        adj[b].push_back(edge { a, c });
    }
    cout << solve() << endl;

    return 0;
}