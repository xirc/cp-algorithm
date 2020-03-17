// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>

// UnionFindTree
// Memory O(N)
// T should be group.
template <class T>
class UnionFindTree {
public:
    using F = std::function<T(const T&, const T&)>;

    struct node {
        int parent, rank;
        T weight;
    };

protected:
    int N;
    std::vector<node> nodes;
    F group_plus;
    F group_minus;
    T group_id;

public:
    // O(N)
    UnionFindTree(
        int n,
        const F& group_plus = std::plus<T>(),
        const F& group_minus = std::minus<T>(),
        const T& group_id = T()
    )
        : N(n)
        , nodes(n)
        , group_plus(group_plus)
        , group_minus(group_minus)
        , group_id(group_id)
    {
        for (int i = 0; i < N; ++i) {
            nodes[i] = { i, 0, group_id };
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
            auto root = find(nodes[v].parent);
            nodes[v].parent = root.parent;
            nodes[v].rank = root.rank;
            nodes[v].weight = group_plus(
                nodes[v].weight,
                root.weight
            );
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
    // weight(u) - weight(v) = w;
    bool unite(int u, int v, T w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        w = group_minus(w, weight(u));
        w = group_plus(w, weight(v));
        u = find(u).parent;
        v = find(v).parent;
        if (u == v) {
            return false;
        }
        static const auto less = std::less<int>(); // NOTE: a < b raise compile error ;(
        if (less(nodes[u].rank, nodes[v].rank)) {
            std::swap(u, v);
            w = group_minus(group_id, w);
        }
        nodes[v].parent = u;
        if (nodes[u].rank == nodes[v].rank) {
            nodes[u].rank++;
        }
        nodes[v].weight = group_minus(group_id, w);
        return true;
    }
    // O(a(N))
    T weight(int v) {
        throw_if_invalid_index(v);
        return find(v).weight;
    }
    // O(a(N))
    bool diff(int u, int v, T& w) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        if (!same(u,v)) {
            return false;
        }
        w = group_minus(weight(u), weight(v));
        return true;
    }

protected:
    void throw_if_invalid_index(int v) {
        if (v < 0 || v >= N) throw "index out of range";
    }
};


#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    UnionFindTree<long long> tree(N);

    for (int i = 0; i < Q; ++i) {
        int c;
        cin >> c;
        if (c == 0) {
            int x, y, z;
            cin >> x >> y >> z;
            tree.unite(y, x, z);
        } else if (c == 1) {
            int x, y; long long w;
            cin >> x >> y;
            if (tree.diff(y, x, w)) {
                cout << w << endl;
            } else {
                cout << "?" << endl;
            }
        } else throw;
    }

    return 0;
}