// https://codeforces.com/problemset/problem/1234/D

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>

using namespace std;
using set = bitset<26>;

class SegmentTree {
    int size;
    vector<set> tree;

public:
    SegmentTree(): size(0), tree() {}
    void build(string value) {
        size = value.length();
        tree = vector<set>(size * 4);
        build(value, 0, 0, size);
    }
    void update(int index, char value) {
        update(0, 0, size, index, value);
    }
    int query(int l, int r) {
        l = max(0, l);
        r = min(r, size);
        return query(0, 0, size, l, r).count();
    }

private:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(string value, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v].set(value[tl] - 'a');
        } else {
            const int tm = (tl + tr) / 2;
            build(value, left(v), tl, tm);
            build(value, right(v), tm, tr);
            tree[v] = tree[left(v)] | tree[right(v)];
        }
    }
    void update(int v, int tl, int tr, int index, char value) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v].reset();
            tree[v].set(value - 'a');
        } else {
            const int tm = (tl + tr) / 2;
            if (index < tm) {
                update(left(v), tl, tm, index, value);
            } else {
                update(right(v), tm, tr, index, value);
            }
            tree[v] = tree[left(v)] | tree[right(v)];
        }
    }
    set query(int v, int tl, int tr, int l, int r) {
        if (tr - tl <= 0 || r - l <= 0) return 0;
        if (tl == l && tr == r) {
            return tree[v];
        } else {
            const int tm = (tl + tr) / 2;
            const set lhs = query(left(v), tl, tm, l, min(r,tm));
            const set rhs = query(right(v), tm, tr, max(l,tm), r);
            return lhs | rhs;
        }
    }
};

int main() {
    string value;
    SegmentTree tree;
    int q;

    cin >> value;
    cin >> q;

    tree.build(value);
    for (int i = 0; i < q; ++i) {
        int t, p, l, r;
        char c;
        scanf("%d", &t);
        switch(t) {
            case 1:
                scanf("%d %c", &p, &c);
                --p;
                tree.update(p, c);
                break;
            case 2:
                scanf("%d %d", &l, &r);
                --l, --r;
                int ans = tree.query(l, r + 1);
                printf("%d\n", ans);
                break;
        }
    }

    return 0;
}