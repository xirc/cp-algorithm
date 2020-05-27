// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A

#include <bits/stdc++.h>

// Union Find Tree (Disjoint Set Union)
// Memory: O(N)
class UnionFindTree {
public:
    struct node { int parent, rank; };

protected:
    int N;
    std::vector<node> nodes;

public:
    // O(N)
    UnionFindTree(int n = 0)
        : N(n)
        , nodes(n)
    {
        for (int i = 0; i < N; ++i) {
            nodes[i] = { i, 0 };
        }
    }
    // O(1)
    int size() {
        return N;
    }
    // O(a(N))
    node find(int v) {
        throw_if_invalid_index(v);
        if (v != nodes[v].parent) {
            // Path Compression
            nodes[v] = find(nodes[v].parent);
        }
        return nodes[v];
    }
    // O(a(N))
    bool same(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return find(u).parent == find(v).parent;
    }
    // O(a(N))
    bool unite(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        u = find(u).parent;
        v = find(v).parent;
        if (u == v) {
            return false;
        }
        if (nodes[u].rank < nodes[v].rank) {
            std::swap(u, v);
        }
        nodes[v].parent = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        return true;
    }

protected:
    void throw_if_invalid_index(int v) {
        if (v < 0 || v >= N) throw "index out of range";
    }
};

// Minimum Spanning Tree
// Kruskal's Algorithm
// Memory: O(V + E)
// NOTE: undirected, multi-edge, negative-weight
class Kruskal {
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
    Kruskal(int n = 0): N(n) {}
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
            if (tree.find(edge.u).parent == tree.find(edge.v).parent) continue;
            out_distance += edge.distance;
            out_edges.push_back({ edge.u, edge.v });
            tree.unite(edge.u, edge.v);
        }

        return out_edges.size() == N - 1;
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};


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