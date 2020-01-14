// https://codeforces.com/contest/474/problem/F

#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

struct Data {
    int value;
    int count;
    Data(): value(0), count(0) {}
    Data(int value): value(value), count(1) {}
    static Data compose(Data lhs, Data rhs) {
        Data ans;
        ans.value = gcd(lhs.value, rhs.value);
        ans.count += lhs.value == ans.value ? lhs.count : 0;
        ans.count += rhs.value == ans.value ? rhs.count : 0;
        return ans;
    };
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
    int query(int l, int r) {
        auto ans = query(0, 0, size, max(l,0), min(r,size));
        return (r - l) - ans.count;
    }

private:
    static constexpr int left(int v) { return 2 * v + 1; }
    static constexpr int right(int v) { return 2 * v + 2; }
    void build(vector<int>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = Data(array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            tree[v] = Data::compose(tree[left(v)], tree[right(v)]);
        }
    }
    Data query(int v, int tl, int tr, int l, int r) {
        if (tr - tl <= 0 || r - l <= 0) return Data();
        if (tl == l && tr == r) {
            return tree[v];
        } else {
            const int tm = (tl + tr) / 2;
            const auto lhs = query(left(v), tl, tm, l, min(r, tm));
            const auto rhs = query(right(v), tm, tr, max(l,tm), r);
            return Data::compose(lhs, rhs);
        }
    }
};

int main() {
    int n, t;
    vector<int> array;
    SegmentTree tree;

    scanf("%d", &n);
    
    array = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
    }
    tree.build(array);

    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        int ans = tree.query(l, r+1);
        printf("%d\n", ans);
    }

    return 0;
}