#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// More faster than Bellman-Ford on average.
class SPFA {
    const int inf = 1e8;
    struct edge { int to, cost; };
    int m_size;
    std::vector<std::vector<edge>> m_edges;
public:
    SPFA(int size): m_size(size), m_edges(size) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index of of range";
    }
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges[from].push_back(edge{ to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<int>& D, std::vector<int>& P) {
        const int N = m_size;
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

            for (auto edge : m_edges[v]) {
                int c = max(D[v], edge.cost);
                if (c >= D[edge.to]) continue;
                D[edge.to] = c;
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int id, N;
    vector<pair<int,int>> pos;

    id = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;

        pos.assign(N, {0, 0});
        for (int i = 0; i < N; ++i) {
            cin>> pos[i].first >> pos[i].second;
        }

        SPFA solver(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                auto a = pos[i], b = pos[j];
                double mag =
                    (a.first - b.first) * (a.first - b.first) +
                    (a.second - b.second) * (a.second - b.second);
                solver.add_edge(i, j, mag);
            }
        }

        vector<int> D, P;
        solver.solve(0, D, P);
        cout << "Scenario #" << id << endl;
        cout << "Frog Distance = " << fixed <<  setprecision(3) << sqrt(D[1]) << endl;
        cout << endl;

        id++;
    }

    return 0;
}