#pragma once

#include <stack>
#include <stdexcept>
#include <vector>


// Euler Tour in Tree
//
// Space: O(V + E)
//
// NOTE:
//  - undirected
//  - non-loop
//  - non-multi-edge
//  - it can handle a forest
//
// Verified:
//  - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
//
class EulerTour {
private:
    size_t N;
    std::vector<std::vector<size_t>> adj;

public:
    // Time: O(V)
    EulerTour(size_t const N = 0): N(N), adj(N) {}
    // Time: O(1)
    size_t size() const {
        return N;
    }
    // u = [0,N), v = [0,N)
    // Time: O(1)
    void add_edge(size_t const u, size_t const v) {
        if (u >= N) throw std::out_of_range("u");
        if (v >= N) throw std::out_of_range("v");
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // r = [0,N)
    // Time: O(E)
    void solve(size_t r, std::vector<size_t>& tour, std::vector<size_t>& tin, std::vector<size_t>& tout) const {
        if (r >= N) throw std::out_of_range("r");

        std::stack<std::pair<size_t,int>> S;
        std::vector<bool> visited(N, false);

        tour.clear();
        tin.assign(N, 2 * N);
        tout.assign(N, 2 * N);

        S.push({r,-1});
        while (S.size()) {
            size_t v = S.top().first;
            int& i = S.top().second;
            if (i < 0) {
                visited[v] = true;
                tour.push_back(v);
                tin[v] = tour.size() - 1;
            } else if (size_t(i) < adj[v].size()) {
                auto u = adj[v][i];
                if (!visited[u]) S.push({u,-1});
            } else {
                tour.push_back(v);
                tout[v] = tour.size() - 1;
                S.pop();
            }
            i++;
        }
    }
};