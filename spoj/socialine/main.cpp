// https://www.spoj.com/problems/SOCIALNE/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FloydWarshall {
    int m_size;
    std::vector< std::vector<int> > m_adjmat;
public:
    static const int inf = 1e8;
    FloydWarshall(int size)
        : m_size(size)
        , m_adjmat(size, std::vector<int>(size, inf)) {}
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "Index out of range";
    }
    int size() {
        return m_size;
    }
    void define_edge(int from, int to, int distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        m_adjmat[from][to] = distance;
    }
    bool solve(std::vector< std::vector<int> >& D, std::vector< std::vector<int> > &P) {
        const int N = m_size;
        // Initialize
        D.assign(N, std::vector<int>(N, inf));
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
                    const int distance = std::max(D[i][k] + D[k][j], -inf);
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
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string line;
        cin >> line;
        const int M = line.size();

        FloydWarshall solver(M);
        for (int j = 0; j < M; ++j) {
            if (line[j] == 'Y') {
                solver.define_edge(0, j, 1);
            }
        }
        for (int i = 1; i < M; ++i) {
            cin >> line;
            for (int j = 0; j < line.size(); ++j) {
                if (line[j] == 'Y') {
                    solver.define_edge(i, j, 1);
                }
            }
        }

        vector< vector<int> > D, P;
        solver.solve(D, P);
        int id = -1, ans = 0;
        for (int i = 0; i < M; ++i) {
            int ffr = 0;
            for (int j = 0; j < M; ++j) {
                if (D[i][j] == 2) ffr++;
            }
            if (id == -1 || ans < ffr) {
                id = i;
                ans = ffr;
            }
        }
        cout << id << " " << ans << endl;
    }

    return 0;
}