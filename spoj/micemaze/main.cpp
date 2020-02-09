// https://www.spoj.com/problems/MICEMAZE/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

int N, E, T;
struct edge { int to, dist; };
vector<vector<edge>> graph;

int solve() {
    // Dijkstra
    priority_queue<pair<int,int>> Q;
    vector<long long> distance(N, LONG_LONG_MAX/2);
    Q.push({0, E});
    distance[E] = 0;
    while (!Q.empty()) {
        auto c = Q.top(); Q.pop();
        int index = c.second, dist = c.first;
        for (auto edge : graph[index]) {
            const int new_dist = distance[index] + edge.dist;
            if (new_dist < distance[edge.to]) {
                distance[edge.to] = new_dist;
                Q.push({new_dist, edge.to});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (distance[i] <= T) ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M;
    cin >> N >> E >> T >> M;
    --E;
    graph.assign(N, vector<edge>());
    for (int i = 0; i < M; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        --a, --b;
        graph[b].push_back(edge {a, d});
    }
    cout << solve() << endl;

    return 0;
}