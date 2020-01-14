// https://codeforces.com/contest/356/problem/A

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Data {
    int value;
    bool lazy;
    int lazy_value;
    Data(): value(0), lazy(false), lazy_value(0) {}
    Data(int value, bool lazy, int lazy_value): value(value), lazy(lazy), lazy_value(lazy_value) {}
};

class SegmentTree {
    int size;
    vector<Data> tree;

public:
    SegmentTree(int size): size(size), tree(size * 4, Data()) {}
    void update(int l, int r, int value) {
        update(0, 0, size, max(l,0), min(r,size), value);
    }
    int query(int index) {
        return query(0, 0, size, index);
    }

private:
    static constexpr int left(int v) { return 2 * v + 1; }
    static constexpr int right(int v) { return 2 * v + 2; }
    void pushdown(int v) {
        if (!tree[v].lazy) {
            return;
        }
        if (left(v) < 4 * size) {
            tree[left(v)] = Data(tree[v].lazy_value, true, tree[v].lazy_value);
        }
        if (right(v) < 4 * size) {
            tree[right(v)] = Data(tree[v].lazy_value, true, tree[v].lazy_value);
        }
        tree[v] = Data(tree[v].lazy_value, false, 0);
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tr - tl <= 0 || r - l <= 0) return;
        pushdown(v);
        if (tl == l && tr == r) {
            tree[v] = Data(value, true, value);
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, min(r,tm), value);
            update(right(v), tm, tr, max(l,tm), r, value);
        }
    }
    int query(int v, int tl, int tr, int index) {
        if (tr - tl <= 0) return 0;
        pushdown(v);
        if (tr - tl == 1) {
            return tree[v].value;
        } else {
            const int tm = (tl + tr) / 2;
            if (index < tm) {
                return query(left(v), tl, tm, index);
            } else {
                return query(right(v), tm, tr, index);
            }
        }
    }
};

void dump(SegmentTree& tree, int n) {
    for (int i = 0; i < n; ++i) {
        if (i > 0) printf(" ");
        printf("%d", tree.query(i));
    }
    printf("\n");
}

struct Query {
    int l, r, x;
    Query(): l(0), r(0), x(0) {}
    Query(int l, int r, int x): l(l), r(r), x(x) {}
};

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    SegmentTree tree(n);
    vector<Query> query(m);

    for (int i = 0; i < m; ++i) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        --l, --r, --x;
        query[i] = Query(l, r, x);
    }

    for (int i = m - 1; i >= 0; --i) {
        Query q = query[i];
        tree.update(q.l, q.x, q.x + 1);
        tree.update(q.x + 1, q.r + 1, q.x + 1);
    }
    dump(tree, n);

    return 0;
}