// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I

#include <iostream>
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

using namespace std;

struct Data {
    bool active;
    int value;
    long long sum;
    int count;
};
struct Query {
    static Data id() {
        return { false, 0, 0, 0 };
    }
    static Data op(const Data& lhs, const Data& rhs) {
        return { false, 0, lhs.sum + rhs.sum, lhs.count + rhs.count };
    }
};
struct Update {
    static Data id() {
        return { false, 0, 0, 1 };
    }
    static Data op(const Data& lhs, const Data& rhs) {
        return { true, rhs.value, rhs.value * lhs.count, lhs.count };
    }
};
struct Push {
    static void pushdown(Data& node, Data& lhs, Data& rhs) {
        if (!node.active) {
            return;
        }
        node.active = false;
        lhs.active = rhs.active = true;
        lhs.value = rhs.value = node.value;
        lhs.sum = lhs.value * lhs.count;
        rhs.sum = rhs.value * rhs.count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<Data> array(N, Update::id());
    SegmentTree<Data,Query,Update,Push> tree(N);
    tree.build(array);

    for (int i = 0; i < Q; ++i) {
        int c, s, t, x;
        cin >> c;
        if (c == 0) {
            cin >> s >> t >> x;
            tree.update(s, t+1, { true, x, 0, 1 });
        } else if (c == 1) {
            cin >> s >> t;
            cout << tree.query(s, t+1).sum << endl;
        } else throw;
    }

    return 0;
}