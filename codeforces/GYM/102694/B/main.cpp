#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

const int inf = numeric_limits<int>::max();

int farther(int from, vector<int>& distances, vector<int>& parents) {
    queue<int> Q;
    distances.assign(N, inf);
    parents.assign(N, -1);

    int distance = 0;
    int to = from;
    Q.push(from);
    distances[from] = 0;
    parents[from] = from;
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        int dist = distances[u] + 1;
        for (int v : G[u]) {
            if (dist >= distances[v]) continue;
            distances[v] = dist;
            parents[v] = u;
            Q.push(v);
            if (distance < dist) {
                distance = dist;
                to = v;
            }
        }
    }
    return to;
}

unordered_set<int> build_roots(int from, int to, const vector<int>& parents) {
    unordered_set<int> roots;
    for (auto u = to; u != parents[u]; u = parents[u]) {
        roots.insert(u);
    }
    roots.insert(from);
    return roots;
}

vector<int> bfs_depth(const unordered_set<int>& roots) {
    vector<int> depths(N, inf);
    queue<int> Q;

    for (auto v : roots) {
        depths[v] = 0;
        Q.push(v);
    }

    while (Q.size()) {
        int u = Q.front(); Q.pop();
        int depth = depths[u] + 1;
        for (int v : G[u]) {
            if (depths[v] < depth) continue;
            depths[v] = depth;
            Q.push(v);
        }
    }
    return depths;
}

vector<int> solve() {
    vector<int> distances(N);
    vector<int> parents(N);

    int from = farther(0, distances, parents);
    int to = farther(from, distances, parents);
    auto roots = build_roots(from, to, parents);
    auto depths = bfs_depth(roots);

    vector<int> ans;
    ans.reserve(N);
    int diameter = distances[to];
    for (int u = 0; u < N; ++u) {
        if (u == from || u == to) {
            ans.push_back(diameter + 1);
            continue;
        }
        int distance_rootU = distances[u] - depths[u];
        int min_distance_rootU =
            min(distance_rootU, diameter - distance_rootU);
        if (depths[u] + 1 > min_distance_rootU) {
            ans.push_back(diameter + 1);
        } else {
            ans.push_back(diameter);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    auto ans = solve();
    for (auto dia : ans) {
        cout << dia << endl;
    }

    return 0;
}