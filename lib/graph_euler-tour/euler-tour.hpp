#pragma once

#include <vector>
#include <stack>

class EulerTrour {
    int N;
    std::vector<std::vector<int>> adj;

public:
    // O(V)
    EulerTrour(int size): N(size), adj(size) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // O(E)
    void solve(int r, std::vector<int>& tour, std::vector<int>& tin, std::vector<int>& tout) {
        throw_if_invalid_index(r);

        std::stack<std::pair<int,int>> S;
        std::vector<bool> visited(N, false);

        tour.clear();
        tin.assign(N, -1);
        tout.assign(N, -1);

        S.push({r,-1});
        while (S.size()) {
            int v = S.top().first;
            int& i = S.top().second;
            if (i < 0) {
                visited[v] = true;
                tour.push_back(v);
                tin[v] = tour.size() - 1;
            } else if (i < adj[v].size()) {
                int u = adj[v][i];
                if (!visited[u]) S.push({u,-1});
            } else {
                tour.push_back(v);
                tout[v] = tour.size() - 1;
                S.pop();
            }
            i++;
        }
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};