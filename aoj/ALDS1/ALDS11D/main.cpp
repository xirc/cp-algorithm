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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, Q;
    int u, v;

    cin >> N >> M;
    
    UnionFindTree uftree(N);

    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        uftree.unite(u, v);
    }

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> u >> v;
        auto ans = uftree.same(u, v) ? "yes" : "no";
        cout << ans << endl;
    }

    return 0;
}