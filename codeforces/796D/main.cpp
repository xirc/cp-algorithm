// https://codeforces.com/contest/796/problem/D

#include <iostream>
#include <vector>
#include <queue>
#include<set>
#include <tuple>

using namespace std;

int N, K, D;
vector<pair<int,int>> edge;
vector<vector<int>> adj;
vector<int> police;

vector<int> solve() {
    vector<bool> visited(N, false);
    set<pair<int,int>> used_edge;
    priority_queue<tuple<int,int,int>> Q;
    
    for (auto p : police) {
        Q.push({0,p,p});
    }

    while (!Q.empty()){
        auto c = Q.top(); Q.pop();
        int d = -get<0>(c), idx = get<1>(c), prev = get<2>(c);
        if (visited[idx] || d > D) continue;
        visited[idx] = true;
        used_edge.insert({prev,idx});
        for (auto u : adj[idx]) {
            int nd = d + 1;
            Q.push({-nd,u,idx});
        }
    }

    vector<int> ans;
    for (int i = 0; i < edge.size(); ++i) {
        auto u = edge[i].first, v = edge[i].second;
        if (used_edge.find({u,v}) == used_edge.end() &&
            used_edge.find({v,u}) == used_edge.end()) {
                ans.push_back(i);
            }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> D;
    
    for (int i = 0; i < K; ++i) {
        int p;
        cin >> p; --p;
        police.push_back(p);
    }

    adj.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v; --u; --v;
        edge.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto ans = solve();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        if (i > 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;

    return 0;
}