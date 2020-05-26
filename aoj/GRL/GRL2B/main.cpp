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

// Heap (Randomized Heap)
// Memory: O(N)
// NOTE: You can merge other Heap which has same update operator.
template <class T, class E = T, class less = std::less<T>>
class Heap {
public:
    using value_type_T = T;
    using value_type_E = E;
    using G = std::function<T(const T&, const E&)>;
    using H = std::function<E(const E&, const E&)>;

protected:
    struct node {
        using tree = std::shared_ptr<node>;
        T value;
        E lazy;
        tree left;
        tree right;
        node(T value, E lazy)
            : value(value)
            , lazy(lazy)
            , left(nullptr)
            , right(nullptr) {}
    };
    using tree = std::shared_ptr<node>;

    tree root = nullptr;
    std::mt19937 random;
    less op;

    G update_op;
    H lazy_op;
    E lazy_id;

public:
    Heap(
        G update_op = [](const T& l, const E& r) { return l + r; },
        H lazy_op = [](const E& l, const E& r) { return l + r; },
        E lazy_id = E()
    )
        : update_op(update_op)
        , lazy_op(lazy_op)
        , lazy_id(lazy_id)
    {
        // Do nothing
    }
    // O(logN)
    bool empty() {
        return root == nullptr;
    }
    // O(logN)
    T top() {
        if (root == nullptr) throw;
        pushdown(root);
        return root->value;
    }
    // O(logN)
    void pop() {
        if (root == nullptr) throw;
        pushdown(root);
        root = merge(root->left, root->right);
    }
    // O(logN)
    void insert(T value) {
        root = merge(root, tree(new node(value, lazy_id)));
    }
    // O(logN)
    void merge(Heap<T,E,less>& other) {
        if (root == other.root) {
            return;
        }
        root = merge(root, other.root);
        other.root = nullptr;
    }
    // O(1)
    void update(E value) {
        if (root == nullptr) return;
        root->lazy =
            lazy_op(root->lazy, value);
    }

protected:
    // O(logN)
    tree merge(tree u, tree v) {
        if (u == nullptr || v == nullptr) {
            return u ? u : v;
        }
        pushdown(u);
        pushdown(v);
        if (op(v->value, u->value)) {
            std::swap(u, v);
        }
        if (random() & 1) {
            std::swap(u->left, u->right);
        }
        u->left = merge(u->left, v);
        return u;
    };
    // O(1)
    void pushdown(tree v) {
        if (v == nullptr) return;
        if (v->left != nullptr) {
            v->left->lazy =
                lazy_op(v->left->lazy, v->lazy);
        }
        if (v->right != nullptr) {
            v->right->lazy =
                lazy_op(v->right->lazy, v->lazy);
        }
        v->value = update_op(v->value, v->lazy);
        v->lazy = lazy_id;
    }
};

// Minimum Cost Arborescence
// Memory: O(V + E)
// NOTE: directed, multi-edge
class MinimumCostArborescence {
    struct edge {
        int index;
        int from, to;
        long long cost;
        bool operator<(const edge& o) const {
            return cost < o.cost;
        }
        edge operator+(const long long value) const {
            return { index, from, to, cost + value };
        }
    };
    int N;
    std::vector<edge> edges;

public:
    static const long long inf;
    // O(1)
    MinimumCostArborescence(int n = 0): N(n) {
        // Do nothing
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    void add_edge(int index, int from, int to, long long cost) {
        throw_if_invalid_index(from);
        throw_if_invalid_index(to);
        if (cost < 0) throw;
        edges.push_back({ index, from, to, cost });
    }
    // O(E logV)
    long long solve(int root, std::vector<int>& out_edges) {
        throw_if_invalid_index(root);

        enum Processing { BEFORE = 0, PROCESSING = 1, DONE = 2 };
        UnionFindTree uftree(N);
        std::vector<Processing> processing(N, BEFORE);
        std::vector<Heap<edge, long long>> come(N);
        std::vector<int> from(N);
        std::vector<long long> from_cost(N);

        out_edges.clear();
        processing[root] = DONE;
        for (auto& e : edges) {
            come[e.to].insert(e);
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            if (processing[i] != BEFORE) continue;
            int c = i;
            std::vector<int> nodes;

            while (processing[c] != DONE) {
                processing[c] = PROCESSING;
                nodes.push_back(c);

                if (come[c].empty()) return inf;
                auto e = come[c].top(); come[c].pop();
                auto fc = uftree.find(e.from).parent;
                if (fc == c) continue;

                from[c] = fc;
                from_cost[c] = e.cost;
                ans += from_cost[c];
                out_edges.push_back(e.index);

                if (processing[from[c]] != PROCESSING) {
                    c = from[c];
                    continue;
                }
                // When we found a cycle, compress the cycle.
                int p = c;
                do {
                    come[p].update(-from_cost[p]);
                    if (p != c) {
                        uftree.unite(p, c);
                        int n = uftree.find(c).parent;
                        come[c].merge(come[p]);
                        come[n].merge(come[c]);
                        c = n;
                    }
                    p = uftree.find(from[p]).parent;
                } while (p != c);
            }
            for (auto v : nodes) {
                processing[v] = DONE;
            }
        }

        return ans;
    }

protected:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
};
const long long MinimumCostArborescence::inf = std::numeric_limits<long long>::max();


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int V, E, r;
    cin >> V >> E >> r;

    MinimumCostArborescence mca(V);
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        mca.add_edge(i, s, t, w);
    }
    vector<int> edge_indices;
    auto ans = mca.solve(r, edge_indices);
    cout << ans << endl;

    return 0;
}