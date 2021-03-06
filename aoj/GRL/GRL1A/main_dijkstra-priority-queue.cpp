// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A

#include <vector>
#include <queue>

// Use Dijkstra(ver: priority_queue<>) in most case.
// This has better performance than Dijkstra(ver: set<>).
class Dijkstra {
    struct edge { int to; long long distance; };
    int N;
    std::vector<std::vector<edge>> adj;

public:
    static const long long inf = 1e18;
    // O(V)
    Dijkstra(int size) : N(size), adj(size) {
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int from, int to, long long distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (distance < 0) throw;
        adj[from].push_back({ to, distance });
    }
    // O(V logV + E)
    void solve(int s, std::vector<long long>& D, std::vector<int>& P) {
        D.assign(N, inf);
        P.assign(N, -1);

        using pii = std::pair<int,int>;
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> Q;
        std::vector<bool> used(N, false);

        D[s] = 0;
        Q.push({0, s});

        while (!Q.empty()) {
            int v = Q.top().second; Q.pop();

            if (used[v]) continue;
            used[v] = true;

            for (auto edge : adj[v]) {
                int to = edge.to; long long len = edge.distance;
                if (D[v] + len < D[to]) {
                    D[to] = D[v] + len;
                    P[to] = v;
                    Q.push({D[to], to});
                }
            }
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};


#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E, R;
    cin >> V >> E >> R;

    Dijkstra solver(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }

    vector<long long> D;
    vector<int> P;
    solver.solve(R, D, P);
    for (int i = 0; i < V; ++i) {
        if (D[i] == Dijkstra::inf) cout << "INF" << endl;
        else cout << D[i] << endl;
    }

    return 0;
}