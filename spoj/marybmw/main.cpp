// https://www.spoj.com/problems/MARYBMW/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long inf = LONG_LONG_MAX;
int N, M;
struct edge { int to; long long w; };
vector<vector<edge>> adj;

long long solve() {
    using entry = pair<long long,int>;
    priority_queue<entry> Q;
    vector<long long> maxw(N, 0);

    maxw[0] = inf;
    Q.push({ inf, 0 });

    while (!Q.empty()) {
        int u = Q.top().second;
        long long w = Q.top().first;
        Q.pop();

        if (u == N - 1) return maxw[u];
        if (maxw[u] != w) continue;

        for (auto edge : adj[u]) {
            long long nw = min(maxw[u], edge.w);
            if (maxw[edge.to] < nw) {
                maxw[edge.to] = nw;
                Q.push({ nw, edge.to });
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N >> M;
        adj.assign(N, vector<edge>());
        for (int i = 0; i < M; ++i) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            --u, --v;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
        cout << solve() << endl;
    }

    return 0;
}