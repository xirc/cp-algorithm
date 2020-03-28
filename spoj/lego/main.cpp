// https://www.spoj.com/problems/LEGO/

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

        ans.assign(N, -1);
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
struct block { int id, sx, sy, ex, ey; };
vector<block> blocks;

bool is_connect(const block& a, const block& b) {
    if (a.ey != b.sy && b.ey != a.sy) return false;
    return (a.sx >= b.sx && a.sx < b.ex) || (a.ex > b.sx && a.ex <= b.ex);
}

int solve() {
    SCC scc(N);

    sort(blocks.begin(), blocks.end(), [&](auto& a, auto& b) {
        return a.sy < b.sy;
    });
    for (int i = 0; i < N; ++i) {
        block val = { 0, 0, blocks[i].ey, 0, 0 };
        auto p = equal_range(blocks.begin(), blocks.end(), val, [&](auto& a, auto& b) {
            return a.sy < b.sy;
        });
        for (; p.first != p.second; p.first++) {
            if (is_connect(blocks[i], *p.first)) {
                scc.add_edge(blocks[i].id, p.first->id);
                scc.add_edge(p.first->id, blocks[i].id);
            }
        }
    }

    vector<int> com;
    return scc.solve(com);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        blocks.push_back({ i, sx, sy, ex, ey });
    }

    cout << solve() << endl;

    return 0;
}