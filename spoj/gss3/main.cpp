// https://www.spoj.com/problems/GSS3/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Use long long instead of int.
// WA if you use int.
struct Data {
    long long prefix, suffix, sum, ans;
    Data() {}
    Data(long long value)
        : prefix(value)
        , suffix(value)
        , sum(value)
        , ans(value)
    {}
    static Data op(Data lhs, Data rhs) {
        Data ans;
        ans.prefix = max(lhs.prefix, lhs.sum + rhs.prefix);
        ans.suffix = max(rhs.suffix, lhs.suffix + rhs.sum);
        ans.sum = lhs.sum + rhs.sum;
        ans.ans = max({lhs.ans, rhs.ans, lhs.suffix + rhs.prefix });
        return ans;
    }
};

class SegmentTree {
    int n;
    vector<Data> tree;
public:
    SegmentTree(): n(0), tree() {}
    void build(vector<long long>& array) {
        n = array.size();
        tree = vector<Data>(4*n, Data(0));
        build(array, 0, 0, n);
    }
    void update(int index, long long value) {
        update(0, 0, n, index, value);
    }
    long long query(int l, int r) {
        return query(0, 0, n, max(l,0), min(r,n)).ans;
    }
private:
    static constexpr int left(int v) { return v * 2 + 1; }
    static constexpr int right(int v) { return v * 2 + 2; }
    void build(vector<long long>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = Data(array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            tree[v] = Data::op(tree[left(v)], tree[right(v)]);
        }
    }
    void update(int v, int tl, int tr, int index, long long value) {
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
            tree[v] = Data::op(tree[left(v)], tree[right(v)]);
        }
    }
    Data query(int v, int tl, int tr, int l, int r) {
        if (tr - tl <= 0 || r - l <= 0) return Data(INT_MIN);
        if (tl == l && tr == r) {
            return tree[v];
        } else {
            const int tm = (tl + tr) / 2;
            const Data lhs = query(left(v), tl, tm, l, min(r,tm));
            const Data rhs = query(right(v), tm, tr, max(l,tm), r);
            return Data::op(lhs, rhs);
        }
    }
};

int main() {
    int n, m;
    vector<long long> array;
    SegmentTree tree;

    scanf("%d", &n);
    array = vector<long long>(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &array[i]);
    }
    tree.build(array);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int q, x, y;
        scanf("%d %d %d", &q, &x, &y);
        if (q == 0) {
            x--;
            tree.update(x, y);
        } else if (q == 1) {
            x--, y--;
            long long ans = tree.query(x, y+1);
            printf("%lld\n", ans);
        }
    }

    return 0;
}