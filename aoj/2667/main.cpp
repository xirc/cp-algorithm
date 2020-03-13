// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2667

#include <vector>
#include <algorithm>
#include <functional>

class HeavyLightDecomposition {
    using mat = const std::vector<std::vector<int>>;
    using func = std::function<void(int,int)>;
    int N;
    std::vector<int> index, inverse, out, head, heavy, parent, depth, subsize;

public:
    // O(N)
    HeavyLightDecomposition(mat& adj, std::vector<int> R = std::vector<int>({0}))
        : N(adj.size())
        , index(N,-1)
        , inverse(N,-1)
        , out(N,-1)
        , head(N,-1)
        , heavy(N,-1)
        , parent(N,-1)
        , depth(N,0)
        , subsize(N,0)
    {
        build(adj, R);
    }
    // O(1)
    int size() {
        return N;
    }
    // O(1)
    int get_index(int v) {
        return index[v];
    }
    // O(1)
    int get_vertex(int index) {
        return inverse[index];
    }
    // O(1)
    int get_parent(int v) {
        return parent[v];
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_node(int u, const func& f) {
        throw_if_invalid_index(u);
        f(index[u], out[u]);
    }
    // O(1)
    // f [l,r)
    void for_each_subtree_edge(int u, const func& f) {
        throw_if_invalid_index(u);
        f(index[u]+1, out[u]);
    }
    // O(logN)
    // f [l,r)
    void for_each_vertex(int u, int v, const func& f) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            f(index[head[v]], index[v]+1);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
        }
        f(index[u], index[v]+1);
    }
    // O(logN)
    // f [l,r)
    void for_each_edge(int u, int v, const func& f) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        for (; head[u] != head[v]; v = parent[head[v]]) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            f(index[head[v]], index[v]+1);
        }
        if (index[u] > index[v]) {
            std::swap(u, v);
        }
        f(index[u]+1, index[v]+1);
    }
    // O(logN)
    int lca(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        while (true) {
            if (index[u] > index[v]) {
                std::swap(u, v);
            }
            if (head[u] == head[v]) {
                return u;
            }
            v = parent[head[v]];
        }
    }
    // O(logN)
    int distance(int u, int v) {
        throw_if_invalid_index(u);
        throw_if_invalid_index(v);
        return depth[u] + depth[v] - 2 * depth[lca(u,v)];
    }

private:
    void throw_if_invalid_index(int index) {
        if (index < 0 || index >= N) throw "index out of range";
    }
    // O(N)
    void build(mat& adj, const std::vector<int>& R) {
        int pos = 0;
        for (auto v : R) {
            dfs_prepare(adj, v);
            dfs_decompose(adj, v, v, pos);
        }
    }
    // O(N)
    void dfs_prepare(const mat& adj, int v) {
        int max_size = 0;
        subsize[v] = 1;
        for (int u : adj[v]) {
            if (u == parent[v]) continue;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            dfs_prepare(adj, u);
            subsize[v] += subsize[u];
            if (subsize[u] > max_size) {
                max_size = subsize[u];
                heavy[v] = u;
            }
        }
    }
    // O(N)
    void dfs_decompose(mat& adj, int v, int h, int& pos) {
        head[v] = h;
        index[v] = pos;
        inverse[pos] = v;
        pos++;
        if (heavy[v] != -1) {
            dfs_decompose(adj, heavy[v], h, pos);
        }
        for (int u : adj[v]) {
            if (parent[v] == u) continue;
            if (heavy[v] == u) continue;
            dfs_decompose(adj, u, u, pos);
        }
        out[v] = pos;
    }
};

#include <vector>
#include <algorithm>

// SegmentTree (RangeUpdate,RangeQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class QueryMonoid, class UpdateMonoid, class Push>
class SegmentTree {
protected:
    int m_size;
    std::vector<T> m_tree;

public:
    SegmentTree(int n)
    {
        build(std::vector<T>(n,UpdateMonoid::id()));
    }
    // O(1)
    int size() {
        return m_size;
    }
    // O(N log N)
    void dump(std::vector<T>& buffer) {
        if (buffer.capacity() < m_size) {
            buffer.reserve(m_size);
        }
        buffer.clear();
        for (int i = 0; i < m_size; ++i) {
            buffer.push_back(query(i,i+1));
        }
    }
    // O(N)
    void build(const std::vector<T>& array) {
        m_size = array.size();
        m_tree.resize(m_size * 4);
        std::fill(m_tree.begin(), m_tree.end(), UpdateMonoid::id());
        build(array, 0, 0, m_size);
    }
    // O(log N)
    T query(int l, int r) {
        return query(0, 0, m_size, std::max(l,0), std::min(r,m_size));
    }
    // O(log N)
    void update(int l, int r, T value) {
        update(0, 0, m_size, l, r, value);
    }

protected:
    static constexpr int left(int v) {
        return v * 2 + 1;
    }
    static constexpr int right(int v) {
        return v * 2 + 2;
    }
    void build(const std::vector<T>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) {
            return;
        }
        if (tr - tl == 1) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            m_tree[v] = QueryMonoid::op(m_tree[left(v)], m_tree[right(v)]);
        }
    }
    T query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return QueryMonoid::id();
        }
        if (l == tl && r == tr) {
            return m_tree[v];
        }
        Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
        const int tm = (tl + tr) / 2;
        const auto lhs = query(left(v), tl, tm, l, std::min(r,tm));
        const auto rhs = query(right(v), tm, tr, std::max(l,tm), r);
        return QueryMonoid::op(lhs, rhs);
    }
    void update(int v, int tl, int tr, int l, int r, T value) {
        if (l >= r) {
            return;
        }
        if (l == tl && r == tr) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], value);
        } else {
            Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, std::min(r, tm), value);
            update(right(v), tm, tr, std::max(l,tm), r, value);
            m_tree[v] = QueryMonoid::op(m_tree[left(v)], m_tree[right(v)]);
        }
    }
};

#include <iostream>
#include <vector>

using namespace std;

struct Data {
    long long value, lazy;
    int count;
    Data() {}
    Data(long long value): value(value), lazy(0), count(1) {}
};
struct Query {
    static Data id() {
        return Data(0);
    }
    static Data op(const Data& lhs, const Data& rhs) {
        Data ans;
        ans.count = lhs.count + rhs.count;
        ans.value = lhs.value + rhs.value;
        ans.lazy = 0;
        return ans;
    }
};
struct Update {
    static Data id() {
        return Data(0);
    }
    static Data op(const Data& lhs, const Data& rhs) {
        Data ans;
        ans.count = lhs.count;
        ans.value = lhs.value + (rhs.value + rhs.lazy) * lhs.count;
        ans.lazy = lhs.lazy + (rhs.value + rhs.lazy);
        return ans;
    }
};
struct Push {
    static void pushdown(Data& node, Data& lhs, Data& rhs) {
        lhs.value += lhs.count * node.lazy;
        lhs.lazy += node.lazy;
        rhs.value += rhs.count * node.lazy;
        rhs.lazy += node.lazy;
        node.lazy = 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    vector<vector<int>> adj;

    cin >> N >> Q;
    adj.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HeavyLightDecomposition hld(adj, {0});
    SegmentTree<Data,Query,Update,Push> tree(N);

    for (int i = 0; i < Q; ++i) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0) {
            long long ans = 0;
            hld.for_each_edge(x, y, [&](int l, int r) {
                ans += tree.query(l, r).value;
            });
            cout << ans << endl;
        } else if (c == 1) {
            hld.for_each_subtree_edge(x, [&](int l, int r) {
                tree.update(l, r, Data(y));
            });
        } else throw;
    }

    return 0;
}