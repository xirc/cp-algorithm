#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C

#include <vector>
#include <queue>
#include <algorithm>

// Floyd Warshall Algorithm
// Memory: O(V^3)
// NOTE: directed, no-multi-edge, no-self-loop
class FloydWarshall {
    int N;
    std::vector<std::vector<long long>> adjmat;

public:
    static const long long inf;
    // O(V^2)
    FloydWarshall(int n = 0)
        : N(n)
        , adjmat(n, std::vector<long long>(n, inf)) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void define_edge(int from, int to, long long distance) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adjmat[from][to] = distance;
    }
    // O(V^3)
    bool solve(std::vector<std::vector<long long>>& D, std::vector<std::vector<int>> &P) {
        // Initialize
        D.assign(N, std::vector<long long>(N, inf));
        P.assign(N, std::vector<int>(N, -1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    D[i][j] = 0;
                } else {
                    D[i][j] = adjmat[i][j];
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
    // O(V)
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
        if (index < 0 || index >= N) throw "Index out of range";
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
const long long FloydWarshall::inf = 1e18;