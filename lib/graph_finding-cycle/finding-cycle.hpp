#pragma once

// Verified
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A

#include <vector>
#include <algorithm>

class Solver {
    int m_size;
    std::vector<std::vector<int>> adj;
public:
    Solver(int size): m_size(size), adj(size) {}
    int size() {
        return m_size;
    }
    void add_edge(int from, int to) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        adj[from].push_back(to);
    }
    // O(E)
    bool solve(std::vector<int>& cycle) {
        const int N = m_size;

        std::vector<int> color(N, 0);
        std::vector<int> parent(N, -1);
        std::pair<int,int> be;
        
        bool found = false;
        for (int v = 0; v < N; ++v) {
            if (color[v] != 0) continue;
            if (dfs(v, color, parent, be)) {
                found = true;
                break;
            }
        }

        if (!found) {
            return false;
        }

        cycle.clear();
        cycle.push_back(be.first);
        for (int v = be.second; v != be.first; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(be.first);
        reverse(cycle.begin(), cycle.end());
        return true;
    }
private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= m_size) throw "index out of range";
    }
    bool dfs(int v, std::vector<int>& color, std::vector<int>& parent, std::pair<int,int>& be) {
        color[v] = 1;
        for (int u : adj[v]) {
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u, color, parent, be)) {
                    return true;
                }
            } else if (color[u] == 1) {
                be.first = u; // cycle begin
                be.second = v; // cycle end
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
};