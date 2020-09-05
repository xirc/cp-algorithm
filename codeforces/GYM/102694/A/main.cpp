#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> G;

pair<int,int> farthest(int from) {
    const int inf = numeric_limits<int>::max();
    queue<int> Q;
    vector<int> distances(N, inf);
    Q.push(from);
    distances[from] = 0;
    int to = from;
    int distance = 0;
    while (Q.size()) {
        int v = Q.front(); Q.pop();
        for (int u : G[v]) {
            int dist = distances[v] + 1;
            if (dist < distances[u]) {
                distances[u] = dist;
                Q.push(u);
                if (dist > distance) {
                    to = u;
                    distance = dist;
                }
            }
        }
    }
    return { to, distance };
}

int circumference() {
    int u, d1, v, diameter;
    tie(u,d1) = farthest(0);
    tie(v,diameter) = farthest(u);
    return diameter * 3;
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
    cout << circumference() << endl;

    return 0;
}