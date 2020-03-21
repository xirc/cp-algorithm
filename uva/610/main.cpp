// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<pair<int,int>>> G;

int K;
vector<bool> edge;
vector<int> ord, low;
void dfs(int u, int p = -1) {
    ord[u] = low[u] = K++;
    for (auto e : G[u]) {
        int i = e.first, v = e.second;
        if (p == v) continue;
        if (!edge[i]) {
            edge[i] = true;
            cout << u+1 << " " << v+1 << endl;
        }
        if (ord[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (ord[u] < low[v]) {
                // bridge
                cout << v+1 << " " << u+1 << endl;
            }
        } else {
            low[u] = min(low[u], ord[v]);
        }
    }
}

void solve() {
    K = 0;
    edge.assign(M, false);
    ord.assign(N, -1);
    low.assign(N, -1);
    dfs(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int T = 1; true; T++) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        G.assign(N, vector<pair<int,int>>());
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            G[u].push_back({ i, v });
            G[v].push_back({ i, u });
        }
        cout << T << endl << endl;
        solve();
        cout << "#" << endl;
    }

    return 0;
}