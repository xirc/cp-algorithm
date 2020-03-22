// http://codeforces.com/contest/919/problem/D

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, M;
string S;
vector<vector<int>> G, GT;

bool tsort(vector<int>& ans) {
    queue<int> Q;
    vector<int> in(N, 0);

    for (int v = 0; v < N; ++v) {
        for (int u : G[v]) in[u]++;
    }
    for (int v = 0; v < N; ++v) {
        if (in[v] == 0) Q.push(v);
    }
    ans.clear();
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        ans.push_back(u);
        for (int v : G[u]) {
            in[v]--;
            if (in[v] == 0) Q.push(v);
        }
    }
    return ans.size() == N;
}

int solve() {
    vector<vector<int>> DP(N, vector<int>(26, 0));
    vector<int> vs;
    if (!tsort(vs)) {
        return -1;
    }
    for (int v = 0; v < N; ++v) {
        DP[v][S[v] - 'a'] = 1;
    }
    for (int u : vs) {
        int c = S[u] - 'a';
        for (int v : GT[u]) {
            for (int i = 0; i < 26; ++i) {
                if (c == i) {
                    DP[u][i] = max(DP[u][i], DP[v][i] + 1);
                } else {
                    DP[u][i] = max(DP[u][i], DP[v][i]);
                }
            }
        }
    }
    int ans = 0;
    for (int v = 0; v < N; ++v) {
        for (int i = 0; i < 26; ++i) {
            ans = max(ans, DP[v][i]);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> S;
    G.assign(N, vector<int>());
    GT.assign(N, vector<int>());
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    cout << solve() << endl;

    return 0;
}
