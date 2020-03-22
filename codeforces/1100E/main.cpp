// https://codeforces.com/contest/1100/problem/E

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct edge { int from, to, cost; };

int N, M;
vector<edge> edges;
vector<vector<int>> G;

vector<int> tsort(int c) {
    vector<int> ans;
    queue<int> Q;
    vector<int> in(N, 0);
    for (int i = 0; i < M; ++i) {
        auto& e = edges[i];
        if (e.cost <= c) continue;
        in[e.to]++;
    }
    for (int v = 0; v < N; ++v) {
        if (in[v] == 0) Q.push(v);
    }
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        ans.push_back(u);
        for (int i : G[u]) {
            auto& e = edges[i];
            if (e.cost <= c) continue;
            in[e.to]--;
            if (in[e.to] == 0) Q.push(e.to);
        }
    }
    return ans;
}

int binsearch() {
    long long min = 0, max = 1e9 + 1;
    while (min < max) {
        int mid = (min + max) / 2;
        auto vs = tsort(mid);
        if (vs.size() < N) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }
    return min;
}

int solve(vector<int>& ans) {
    int c = binsearch();
    auto us = tsort(c);

    vector<int> order(N, 0);
    for (int i = 0; i < N; ++i) {
        order[us[i]] = i;
    }

    for (int i = 0; i < M; ++i) {
        auto& e = edges[i];
        if (e.cost > c) continue;
        if (order[e.from] > order[e.to]) {
            ans.push_back(i);
        }
    }

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        edges.push_back({ u, v, c });
        G[u].push_back(i);
    }

    vector<int> edges;
    int ans = solve(edges);
    cout << ans << " " << edges.size() << endl;
    for (int i = 0; i < edges.size(); ++i) {
        if (i > 0) cout << " ";
        cout << edges[i] + 1;
    }
    cout << endl;

    return 0;
}