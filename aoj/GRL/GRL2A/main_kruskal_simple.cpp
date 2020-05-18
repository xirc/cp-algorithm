// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <vector>
#include <set>
#include <algorithm>

class KruskalSimple {
    struct edge {
        int u, v;
        long long distance;
        bool operator<(const edge& other) const {
            return distance < other.distance;
        }
    };

    int N;
    std::vector<edge> edges;

public:
    // O(1)
    KruskalSimple(int size): N(size) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, long long distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        edges.push_back({ u, v, distance });
    }
    // O(E logV + V^2)
    bool solve(long long& out_distance, std::vector<std::pair<int,int>> &out_edges) {
        out_distance = 0;
        out_edges.clear();

        std::vector<int> tree_id(N);
        
        for (int i = 0; i < N; ++i) {
            tree_id[i] = i;
        }
        std::sort(edges.begin(), edges.end());

        for (auto edge : edges) {
            if (tree_id[edge.u] == tree_id[edge.v]) continue;

            out_distance += edge.distance;
            out_edges.push_back({ edge.u, edge. v });

            int old_id = tree_id[edge.u], new_id = tree_id[edge.v];
            for (int i = 0; i< N; ++i) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }

        return out_edges.size() == N - 1;
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

    int V, E;
    cin >> V >> E;

    KruskalSimple solver(V);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.add_edge(u, v, w);
    }
    long long distance;
    vector<pair<int,int>> edges;
    solver.solve(distance, edges);
    cout << distance << endl;

    return 0;
}