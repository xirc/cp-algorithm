// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

// SegmentTree (RangeUpdate,PointQuery)
// Memory O(N)
// Build  O(N)
// Query O(log N)
// Update O(log N)
template<class T, class UpdateMonoid, class Push>
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
            buffer.push_back(query(i));
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
    T query(int index) {
        if (index < 0 || index >= m_size) {
            throw;
        }
        return query(0, 0, m_size, index);
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
        }
    }
    T query(int v, int tl, int tr, int index) {
        if (tr - tl == 1) {
            return m_tree[v];
        }
        Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
        const int tm = (tl + tr) / 2;
        if (index < tm) {
            return query(left(v), tl, tm, index);
        } else {
            return query(right(v), tm, tr, index);;
        }
    }
    void update(int v, int tl, int tr, int l, int r, T value) {
        if (l >= r) {
            return;
        }
        if (l == tl && r == tr) {
            m_tree[v] = UpdateMonoid::op(m_tree[v], value);
        } else {
            const int tm = (tl + tr) / 2;
            Push::pushdown(m_tree[v], m_tree[left(v)], m_tree[right(v)]);
            update(left(v), tl, tm, l, std::min(r,tm), value);
            update(right(v), tm, tr, std::max(l,tm), r, value);
        }
    }
};

using namespace std;

struct Option {
    bool active;
    int value;
    Option(): active(false), value(0) {}
    Option(int value): active(true), value(value) {}
};
struct Update {
    static Option id() {
        return Option(numeric_limits<int>::max());
    }
    static Option op(const Option& lhs, const Option& rhs) {
        return rhs;
    }
};
struct Push {
    static void pushdown(Option& node, Option& lhs, Option& rhs) {
        if (!node.active) {
            return;
        }
        lhs = rhs = node;
        node = Option();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    SegmentTree<Option,Update,Push> tree(N);
    for (int i = 0; i < Q; ++i) {
        int c, s, t, x;
        cin >> c;
        if (c == 0) {
            cin >> s >> t >> x;
            tree.update(s, t+1, Option(x));
        } else if (c == 1) {
            cin >> s;
            cout << tree.query(s).value << endl;
        } else throw;
    }

    return 0;
}