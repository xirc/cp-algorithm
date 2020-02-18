// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=364

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BellmanFord {
    const int inf = 1e8;
    struct edge { int from, to, cost; };
    int m_size;
    std::vector<edge> m_edges;
public:
    BellmanFord(int size): m_size(size) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index of of range";
    }
    int size() {
        return m_size;
    }
    void add_edge(int from, int to, int cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_edges.push_back(edge{ from, to, cost });
    }
    // O (E V)
    bool solve(int from, std::vector<int>& D, std::vector<int>& P) {
        throw_if_invalid_index(from);
        D.assign(m_size, inf);
        P.assign(m_size, -1);

        bool any_update = false;
        D[from] = 0;
        for (int i = 0; i < m_size; ++i) {
            any_update = false;
            for (int j = 0; j < m_edges.size(); ++j) {
                edge e = m_edges[j];
                if (D[e.from] >= inf) continue;
                if (D[e.to] > D[e.from] + e.cost) {
                    // suppress negative overflow
                    D[e.to] = std::max(-inf, D[e.from] + e.cost);
                    P[e.to] = e.from;
                    any_update = true;
                }
            }
            if (!any_update) break;
        }

        // if any_update == true, a negative cycle is found.
        return !any_update;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    BellmanFord solver(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            string s;
            cin >> s;
            if (s == "x") continue;
            int cost;
            stringstream stream(s);
            stream >> cost;
            solver.add_edge(i, j, cost);
            solver.add_edge(j, i, cost);
        }
    }

    vector<int> D, P;
    solver.solve(0, D, P);
    int ans = *max_element(D.begin(), D.end());
    cout << ans << endl;

    return 0;
}