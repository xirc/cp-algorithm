#include <bits/stdc++.h>

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

    int N, Q;
    cin >> N >> Q;

    auto gr = vector<map<int,int>>(N);
    auto dsu = UnionFindTree(N);

    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        --c;
        gr[i][c] = 1;
    }

    for (int i = 0; i < Q; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        --a, --b;
        if (t == 1) {
            a = dsu.find(a).parent;
            b = dsu.find(b).parent;
            if (a != b) {
                dsu.unite(a, b);
                int r = dsu.find(a).parent;
                if (r != a) swap(a, b);
                for (auto e : gr[b]) gr[a][e.first] += e.second;
            }
        } else if (t == 2) {
            auto r = dsu.find(a).parent;
            cout << (gr[r].count(b) > 0 ? gr[r][b] : 0) << endl;
        } else throw;
    }

    return 0;
}