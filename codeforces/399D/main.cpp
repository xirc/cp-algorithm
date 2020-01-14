// https://codeforces.com/problemset/problem/339/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
    int rank;
    int value;
    Data() : rank(0), value(0) {}
    Data(int value) : rank(0), value(value) {}
    static Data combine(Data lhs, Data rhs) {
        if (lhs.rank != rhs.rank) throw;
        Data ans;
        ans.rank = lhs.rank + 1;
        ans.value = (ans.rank & 1) ? lhs.value | rhs.value : lhs.value ^ rhs.value;
        return ans;
    }
};

class SegmentTree {
    int size;
    vector<Data> tree;

public:
    SegmentTree(): size(0), tree() {}
    void build(vector<int>& array) {
        size = array.size();
        tree = vector<Data>(size * 4);
        build(array, 0, 0, size);
    }
    void update(int index, int value) {
        update(0, 0, size, index, value);
    }
    int query() {
        return tree[0].value;
    }

private:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(vector<int>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = Data(array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            tree[v] = Data::combine(tree[left(v)], tree[right(v)]);
        }
    }
    void update(int v, int tl, int tr, int index, int value) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = Data(value);
        } else {
            const int tm = (tl + tr) / 2;
            if (index < tm) {
                update(left(v), tl, tm, index, value);
            } else {
                update(right(v), tm, tr, index, value);
            }
            tree[v] = Data::combine(tree[left(v)], tree[right(v)]);
        }
    }
};

int main() {
    int n, m;
    vector<int> array;
    SegmentTree tree;

    scanf("%d %d", &n, &m);
    int size = 1 << n;
    array = vector<int>(size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    tree.build(array);

    for (int i = 0; i < m; ++i) {
        int p, b;
        scanf("%d %d", &p, &b);
        p--;
        tree.update(p, b);
        int ans = tree.query();
        printf("%d\n", ans);
    }

    return 0;
}