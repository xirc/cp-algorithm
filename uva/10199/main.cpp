// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1140

#include <vector>
#include <algorithm>

// Articulation Points of a Graph
// Memory: O(V + E)
// NOTE: undirected, multi-edge, no-self-loop
class ArticulationPoints {
    struct edge { int id, to; };

    int N, M;
    std::vector<std::vector<edge>> adj;
    // Temporary
    int K;
    std::vector<int> ord;
    std::vector<int> low;
    std::vector<int> ans;

public:
    // O(V)
    ArticulationPoints(int n): N(n), M(0), adj(n) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back({ M, v });
        adj[v].push_back({ M, u });
        M++;
    }
    // O(V + E)
    std::vector<int> solve() {
        K = 0;
        ord.assign(N, -1);
        low.assign(N, -1);
        ans.clear();
        for (int u = 0; u < N; ++u) {
            if (ord[u] != -1) continue;
            dfs(u);
        }
        return ans;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index > N) throw "index out of range";
    }
    void dfs(int u, const edge& ein = { -1, -1 }) {
        bool is_cutpoint = false;
        int childlen = 0;
        ord[u] = low[u] = K++;
        for (auto& e : adj[u]) {
            if (ord[e.to] == -1) {
                dfs(e.to, e);
                low[u] = std::min(low[u], low[e.to]);
                ++childlen;
                if (ein.id != -1 && ord[u] <= low[e.to]) {
                    is_cutpoint = true;
                }
            } else if (e.id != ein.id) {
                low[u] = std::min(low[u], ord[e.to]);
            }
        }
        if (ein.id == -1 && childlen > 1) {
            is_cutpoint = true;
        }
        if (is_cutpoint) {
            ans.push_back(u);
        }
    }
};

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

vector<string> cities;
map<string,int> id_by_name;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int T = 1; true; T++) {
        int N, M;

        cin >> N;
        if (N == 0) break;

        cities.assign(N, "");
        id_by_name.clear();
        for (int i = 0; i < N; ++i) {
            string name;
            cin >> name;
            cities[i] = name;
            id_by_name[name] = i;
        }

        ArticulationPoints solver(N);

        cin >> M;
        for (int i = 0; i < M; ++i) {
            string a, b;
            cin >> a >> b;
            int u = id_by_name[a], v = id_by_name[b];
            solver.add_edge(u, v);
        }

        auto ids = solver.solve();
        auto ans = vector<string>();
        for (int id : ids) {
            ans.push_back(cities[id]);
        }
        sort(ans.begin(), ans.end());

        if (T > 1) cout << endl;
        cout << "City map #" << T << ": " << ans.size() << " camera(s) found" << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << endl;
        }
    }

    return 0;
}