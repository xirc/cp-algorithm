// https://codeforces.com/problemset/problem/449/B

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M, K;
struct edge { int to, cost, train; };
vector<vector<edge>> adj;

int solve() {
    const long long inf = 1e15;
    using entry = pair<long long, int>;
    priority_queue<entry, vector<entry>, greater<entry>> Q;
    vector<bool> used(N, false);
    vector<long long> distance(N, inf);
    vector<int> parent(N, -1);
    vector<int> train(N, -1);

    distance[0] = 0;
    Q.push(entry{0,0});
    while (!Q.empty()) {
        auto v = Q.top().second; Q.pop();
        if (used[v]) continue;
        used[v] = true;
        for (auto u : adj[v]) {
            if (distance[u.to] > distance[v] + u.cost) {
                distance[u.to] = distance[v] + u.cost;
                parent[u.to] = v;
                train[u.to] = u.train;
                Q.push(entry{distance[u.to],u.to});
            } else if (distance[u.to] == distance[v] + u.cost && u.train == -1){
                parent[u.to] = v;
                train[u.to] = u.train;
            }
        }
    }

    int ans = K;
    for (int i = 0; i < N; ++i) {
        if (train[i] != -1) ans--;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    adj.assign(N, vector<edge>());
    for (int i = 0; i < M; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        adj[u].push_back(edge{v,x,-1});
        adj[v].push_back(edge{u,x,-1});
    }
    for (int i = 0; i < K; ++i) {
        int s, y;
        cin >> s >> y;
        --s;
        adj[0].push_back(edge{s,y,i});
        adj[s].push_back(edge{0,y,i});
    }
    cout << solve() << endl;

    return 0;
}