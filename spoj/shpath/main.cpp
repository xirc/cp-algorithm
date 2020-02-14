// https://www.spoj.com/problems/SHPATH/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

int N;
struct edge { int to, cost; };
vector<vector<edge>> adj;

int solve(int from, int to) {
    using pii = pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    vector<bool> used(N, false);
    vector<int> distance(N, 1e6);

    distance[from] = 0;
    Q.push({0,from});
    while (!Q.empty()) {
        auto v = Q.top().second; Q.pop();
        if (used[v]) continue;
        used[v] = true;
        if (v == to) return distance[v];
        for (auto u : adj[v]) {
            if (distance[u.to] > distance[v] + u.cost) {
                distance[u.to] = distance[v] + u.cost;
                Q.push({distance[u.to], u.to});
            }
        }
    }
    return 1e6;
}

int main() {
    int T;

    cin >> T;
    for (int t = 0; t < T; ++t) {
        int R;
        map<string,int> id_by_name;

        cin >> N;
        adj.assign(N, vector<edge>());
        for (int from = 0; from < N; ++from) {
            int M;
            string name;
            cin >> name;
            id_by_name[name]  = from;
            cin >> M;
            for (int j = 0; j < M; ++j) {
                int to, cost;
                cin >> to >> cost;
                --to;
                adj[from].push_back(edge{to,cost});
                adj[to].push_back(edge{from,cost});
            }
        }

        cin >> R;
        for (int i = 0; i < R; ++i) {
            string from, to;
            cin >> from >> to;
            int a = id_by_name[from], b = id_by_name[to];
            cout << solve(a, b) << endl;
        }
    }

    return 0;
}