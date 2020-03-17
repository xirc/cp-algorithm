// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <vector>
#include <set>
#include <algorithm>

class Kruskal {
    struct UnionFindTree {
        struct node { int parent, rank; };
        int N;
        std::vector<node> nodes;
        UnionFindTree(int size)
            : N(size)
            , nodes(size)
        {
            for (int i = 0; i < size; ++i) {
                nodes[i] = { i, 0 };
            }
        }
        node find_set(int v) {
            if (v != nodes[v].parent) {
                nodes[v] = find_set(nodes[v].parent);
            }
            return nodes[v];
        }
        void union_set(int a, int b) {
            a = find_set(a).parent;
            b = find_set(b).parent;

            if (a == b) return;
            if (nodes[a].rank < nodes[b].rank) {
                std::swap(a, b);
            }
            nodes[b].parent = a;
            if (nodes[a].rank == nodes[b].rank) {
                nodes[a].rank++;
            }
        }
    };
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
    Kruskal(int size): N(size) {}
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int u, int v, int distance) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        edges.push_back({ u, v, distance });
    }
    // O (E logV)
    bool solve(long long& out_distance, std::vector<std::pair<int,int>>& out_edges) {
        out_distance = 0;
        out_edges.clear();

        UnionFindTree tree(N);

        std::sort(edges.begin(), edges.end());

        for (auto edge : edges) {
            if (tree.find_set(edge.u).parent == tree.find_set(edge.v).parent) continue;
            out_distance += edge.distance;
            out_edges.push_back({ edge.u, edge.v });
            tree.union_set(edge.u, edge.v);
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

    Kruskal solver(V);
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