#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max();
int N;
vector<vector<int>> G;
vector<int> D;

void bfs() {
    queue<int> Q;
    D[0] = 0;
    Q.push(0);
    while (Q.size()) {
        int v = Q.front(); Q.pop();
        for (auto u : G[v]) {
            if (D[u] > D[v] + 1) {
                D[u] = D[v] + 1;
                Q.push(u);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    D.assign(N, inf);

    int v, K, u;
    for (int i = 0; i < N; ++i) {
        cin >> v >> K;
        for (int j = 0; j < K; ++j) {
            cin >> u;
            G[v-1].push_back(u-1);
        }
    }

    bfs();
    for (int v = 0; v < N; ++v) {
        int d = D[v] == inf ? -1 : D[v];
        cout << (v+1) << " " << d << endl;
    }

    return 0;
}