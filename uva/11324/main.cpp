// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2299

#include <vector>
#include <stack>
#include <algorithm>

// Strongly Connected Components
// Memory: O(E + V)
// NOTE: directed, multi-edge
class SCC {
    int N;
    std::vector<std::vector<int>> G;
    std::vector<std::vector<int>> GT;

public:
    // O(N)
    SCC(int n = 0): N(n), G(n), GT(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        G[from].push_back(to);
        GT[to].push_back(from);
    }
    // O(V + E)
    // Kosaraju's Algorithm
    // ans[u] = Component ID of vertex 'u'.
    // Component ID is assigned in topological order.
    int solve(std::vector<int>& ans) {
        std::stack<std::pair<int,int>> S;
        std::vector<bool> used(N, false);
        std::vector<int> order;

        order.reserve(N);
        for (int s = 0; s < N; ++s) {
            if (used[s]) continue;
            S.push({s,-1});
            while (S.size()) {
                int u = S.top().first;
                int& i = S.top().second;
                if (i < 0) {
                    used[u] = true;
                } else if (i < G[u].size()) {
                    int v = G[u][i];
                    if (!used[v]) {
                        S.push({ v, -1 });
                    }
                } else {
                    order.push_back(u);
                    S.pop();
                }
                ++i;
            }
        }
        std::reverse(order.begin(), order.end());

        int K = 0;
        ans.assign(N, -1);
        for (int i = 0; i < N; ++i) {
            int s = order[i];
            if (ans[s] != -1) continue;
            S.push({ s, -1 });
            while (S.size()) {
                int u = S.top().first;
                int& j = S.top().second;
                if (j < 0) {
                    ans[u] = K;
                } else if (j < GT[u].size()) {
                    int v = GT[u][j];
                    if (ans[v] == -1) {
                        S.push({ v, -1 });
                    }
                } else {
                    S.pop();
                }
                ++j;
            }
            ++K;
        }

        return K;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> G;
SCC scc;
vector<vector<int>> H;
vector<int> S;

int dfs(int v) {
    int ans = 0;
    for (int u : H[v]) {
        ans = max(ans, dfs(u));
    }
    return ans + S[v];
}

int solve() {
    vector<int> com;
    int K = scc.solve(com);

    H.assign(K, vector<int>());
    for (int v = 0; v <  N; ++v) {
        for (int u : G[v]) {
            if (com[v] == com[u]) continue;
            H[com[v]].push_back(com[u]);
        }
    }

    S.assign(K, 0);
    for (int i = 0; i < N; ++i) {
        S[com[i]]++;
    }

    int ans = 0;
    for (int v = 0; v < K; ++v) {
        ans = max(ans, dfs(v));
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> N >> M;
        scc = SCC(N);
        G.assign(N, vector<int>());
        for (int j = 0; j < M; ++j) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            G[a].push_back(b);
            scc.add_edge(a, b);
        }
        cout << solve() << endl;
    }

    return 0;
}