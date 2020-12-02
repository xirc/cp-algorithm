#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> P;
vector<vector<int>> XY;

vector<vector<int>> G;
vector<bool> done;
set<int> components;

void dfs(int v) {
    if (done[v]) return;
    done[v] = true;
    components.insert(v);
    for (int u : G[v]) {
        dfs(u);
    }
}

// O(N logN)
int solve() {
    G.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int x = XY[i][0], y = XY[i][1];
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = 0;
    done.assign(N, false);
    for (int v = 0; v < N; ++v) {
        components.clear();
        dfs(v);
        for (auto u : components) {
            if (components.count(P[u])) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    P.assign(N, 0);
    XY.assign(M, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        --P[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> XY[i][0] >> XY[i][1];
        --XY[i][0]; --XY[i][1];
    }
    cout << solve() << endl;

    return 0;
}