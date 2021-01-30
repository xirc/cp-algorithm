#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int N;
string S;

vector<vector<int>> G;
vector<bool> done;

void dfs(int v, vector<int>& c) {
    if (done[v]) return;
    done[v] = true;
    c.push_back(v);
    for (int u : G[v]) {
        if (done[u]) continue;
        dfs(u, c);
    }
}

vector<int> solve() {
    ++N;

    G.assign(2*N, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] == 'L') {
            int a = i + N, b = i + 1;
            G[a].push_back(b);
            G[b].push_back(a);
        } else if (S[i] == 'R') {
            int a = i, b = i + 1 + N;
            G[a].push_back(b);
            G[b].push_back(a);
        } else throw;
    }

    vector<int> ans(N, 0);
    done.assign(2*N, false);
    for (int i = 0; i < N; ++i) {
        if (done[i]) continue;
        vector<int> c;
        dfs(i, c);
        for (auto j : c) {
            if (j < N) ans[j] = c.size();
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tt = 0; tt < T; ++tt) {
        cin >> N >> S;
        auto ans = solve();
        for (int i = 0; i < ans.size(); ++i) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }

    return 0;
}