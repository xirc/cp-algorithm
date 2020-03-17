// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B

#include <vector>
#include <queue>

// More faster than Bellman-Ford on average.
class SPFA {
    struct edge { int to; long long cost; };
    int N;
    std::vector<std::vector<edge>> edges;

public:
    static const long long inf = 1e18;
    // O(V)
    SPFA(int size): N(size), edges(size) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        edges[from].push_back({ to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<long long>& D, std::vector<int>& P) {
        D.assign(N, inf);
        P.assign(N, -1);
        std::vector<int> count(N, 0);
        std::vector<bool> inqueue(N, false);
        std::queue<int> Q;

        D[from] = 0;
        Q.push(from);
        inqueue[from] = true;
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            inqueue[v] = false;

            for (auto edge : edges[v]) {
                if (D[edge.to] <= D[v] + edge.cost) continue;
                D[edge.to] = D[v] + edge.cost;
                P[edge.to] = v;
                if (inqueue[edge.to]) continue;
                Q.push(edge.to);
                inqueue[edge.to] = true;
                count[edge.to]++;
                if (count[edge.to] > N) {
                    // Found a negative cycle
                    return false;
                }
            }
        }
        return true;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index of of range";
    }
};


#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E, R;
    cin >> V >> E >> R;

    SPFA solver(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }

    vector<long long> D;
    vector<int> P;
    bool has_ans = solver.solve(R, D, P);
    if (!has_ans) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (int i = 0; i < V; ++i) {
        if (D[i] == SPFA::inf) cout << "INF" << endl;
        else cout << D[i] << endl;
    }

    return 0;
}