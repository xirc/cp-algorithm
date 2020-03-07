// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class FloydWarshall {
    int m_size;
    std::vector<std::vector<long long>> m_adjmat;
public:
    static const long long inf = 1e18;
    FloydWarshall(int size)
        : m_size(size)
        , m_adjmat(size, std::vector<long long>(size, inf)) {}
    int size() {
        return m_size;
    }
    void define_edge(int from, int to, long long distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_adjmat[from][to] = distance;
    }
    // O(V^3)
    bool solve(std::vector<std::vector<long long>>& D, std::vector<std::vector<int>> &P) {
        const int N = m_size;
        // Initialize
        D.assign(N, std::vector<long long>(N, inf));
        P.assign(N, std::vector<int>(N, -1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    D[i][j] = 0;
                } else {
                    D[i][j] = m_adjmat[i][j];
                }
            }
        }
        // Floyd-Warshall
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (D[i][k] >= inf || D[k][j] >= inf) continue;
                    const auto distance = std::max(D[i][k] + D[k][j], -inf);
                    if (distance < D[i][j]) {
                        D[i][j] = distance;
                        P[i][j] = k;
                    }
                }
            }
        }
        // Is there no negative cycle?
        for (int i = 0; i < N; ++i) {
            if (D[i][i] < 0) return false;
        }
        return true;
    }
    std::vector<int> retrieve_path(
        std::vector<std::vector<long long>>& D,
        std::vector<std::vector<int>>& P,
        int from, int to
    ) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (D[from][to] == inf) {
            return {};
        }
        std::deque<int> tmp;
        retrieve_path(P, from, to, false, tmp);
        auto path = std::vector<int>(tmp.begin(), tmp.end());
        path.push_back(to);
        return path;
    }
private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "Index out of range";
    }
    void retrieve_path
    (
        std::vector<std::vector<int>>& P,
        int from, int to, bool front,
        std::deque<int>& path
    ) {
        if (P[from][to] == -1 || P[from][to] == from || P[from][to] == to) {
            if (front) {
                path.push_front(from);
            } else {
                path.push_back(from);
            }
        } else {
            retrieve_path(P, from, P[from][to], true, path);
            retrieve_path(P, P[from][to], to, false, path);
        }
    }
};

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E;
    cin >> V >> E;

    FloydWarshall solver(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.define_edge(u, v, w);
    }
    
    vector<vector<long long>> D;
    vector<vector<int>> P;
    bool has_ans = solver.solve(D, P);
    if (!has_ans) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (j > 0) cout << " ";
            if (D[i][j] == FloydWarshall::inf) cout << "INF";
            else cout << D[i][j];
        }
        cout << endl;
    }

    return 0;
}