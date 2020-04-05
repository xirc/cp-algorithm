// http://codeforces.com/contest/22/problem/E

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

using namespace std;

int N;
vector<vector<int>> G;
SCC scc;
vector<vector<int>> H, HT;

vector<bool> vis;
vector<int> iso;

void dfs(int v, int i) {
    vis[v] = true;
    iso[v] = i;
    for (int u : H[v]) {
        if (vis[u]) continue;
        dfs(u, i);
    }
    for (int u : HT[v]) {
        if (vis[u]) continue;
        dfs(u, i);
    }
}

vector<pair<int,int>> solve() {
    vector<int> com;
    int K = scc.solve(com);

    if (K == 1) {
        return {};
    }

    vector<vector<int>> cs(K);

    H.assign(K, vector<int>());
    HT.assign(K, vector<int>());
    for (int v = 0; v < N; ++v) {
        cs[com[v]].push_back(v);
        for (int u : G[v]) {
            if (com[v] == com[u]) continue;
            H[com[v]].push_back(com[u]);
            HT[com[u]].push_back(com[v]);
        }
    }

    int L = 0;
    vis.assign(K, false);
    iso.assign(K, -1);
    for (int v = 0; v < K; ++v) {
        if (vis[v]) continue;
        dfs(v, L++);
    }

    vector<vector<int>> source(L), sink(L);
    for (int v = 0; v < K; ++v) {
        if (HT[v].empty()) source[iso[v]].push_back(v);
        if (H[v].empty()) sink[iso[v]].push_back(v);
    }

    vector<pair<int,int>> ans;
    for (int i = 0; i < L; ++i) {
        int j = (i + 1) % L;
        int e = sink[i][0];
        int s = source[j][0];
        ans.push_back({ cs[e][0], cs[s][0] });
    }
    vector<int> ss, es;
    for (int i = 0; i < L; ++i) {
        for (int j = 1; j < source[i].size(); ++j) ss.push_back(source[i][j]);
        for (int j = 1; j < sink[i].size(); ++j) es.push_back(sink[i][j]);
    }
    if (ss.empty() && es.empty()) {
        return ans;
    }
    if (ss.empty()) ss.push_back(source[0][0]);
    if (es.empty()) es.push_back(sink[0][0]);
    int S = max(ss.size(), es.size());
    for (int i = 0; i < S; ++i) {
        int s = i < ss.size() ? ss[i] : ss[0];
        int e = i < es.size() ? es[i] : es[0];
        ans.push_back({ cs[e][0], cs[s][0] });
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    G.assign(N, vector<int>());
    scc = SCC(N);
    for (int i = 0; i < N; ++i) {
        int j;
        cin >> j;
        --j;
        G[i].push_back(j);
        scc.add_edge(i, j);
    }

    auto ans = solve();
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        int s = ans[i].first + 1;
        int e = ans[i].second + 1;
        cout << s << " " << e << endl;
    }

    return 0;
}