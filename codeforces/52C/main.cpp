// https://codeforces.com/problemset/problem/52/C

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

class SegmentTree {
    int size;
    vector<long long> tree;
    vector<long long> lazy;

public:
    SegmentTree(): size(0), tree(), lazy() {}
    void build(vector<int>& array) {
        size = array.size();
        tree = vector<long long>(size * 4);
        lazy = vector<long long>(size * 4);
        build(array, 0, 0, size);
    }
    void update(int l, int r, int value) {
        if (r >= l) {
            update(0, 0, size, l, r + 1, value);
        } else {
            update(0, 0, size, l, size, value);
            update(0, 0, size, 0, r + 1, value);
        }
    }
    long long query(int l, int r) {
        if (r >= l) {
            return query(0, 0, size, l, r + 1);
        } else {
            auto lhs = query(0, 0, size, l, size);
            auto rhs = query(0, 0, size, 0, r + 1);
            return min(lhs, rhs);
        }
    }

private:
    static constexpr int left(int v) { return 2 * v + 1; }
    static constexpr int right(int v) { return 2 * v + 2; }
    void build(vector<int>& array, int v, int tl, int tr) {
        if (tr - tl <= 0) return;
        if (tr - tl == 1) {
            tree[v] = array[tl];
            lazy[v] = 0;
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            tree[v] = min(tree[left(v)], tree[right(v)]);
            lazy[v] = 0;
        }
    }
    void pushdown(int v) {
        if (left(v) < 4 * size) {
            tree[left(v)] += lazy[v];
            lazy[left(v)] += lazy[v];
        }
        if (right(v) < 4 * size) {
            tree[right(v)] += lazy[v];
            lazy[right(v)] += lazy[v];
        }
        lazy[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (tr - tl <= 0 || r - l <= 0) return;
        pushdown(v);
        if (tl == l && tr == r) {
            tree[v] += value;
            lazy[v] += value;
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, min(r,tm), value);
            update(right(v), tm, tr, max(l,tm), r, value);
            tree[v] = min(tree[left(v)], tree[right(v)]);
        }
    }
    long long query(int v, int tl, int tr, int l, int r) {
        if (tr - tl <= 0 || r - l <= 0) return LONG_LONG_MAX;
        pushdown(v);
        if (tl == l && tr == r) {
            return tree[v];
        } else {
            const int tm = (tl + tr) / 2;
            const auto lhs = query(left(v), tl, tm, l, min(r,tm));
            const auto rhs = query(right(v), tm, tr, max(l,tm), r);
            return min(lhs, rhs);
        }
    }
};

vector<int> read(string line) {
    int value;
    vector<int> token;
    stringstream ss(line);
    while (!ss.eof()) {
        ss >> value;
        token.push_back(value);
    }
    return token;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    vector<int> array;
    SegmentTree tree;

    cin >> n;
    array = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    tree.build(array);

    string line;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; ++i) {
        getline(cin, line);
        auto token = read(line);
        if (token.size() == 2) {
            // RMQ
            int lf = token[0], rg = token[1];
            long long ans = tree.query(lf, rg);
            cout << ans << endl;
        } else if (token.size() == 3) {
            // INC
            int lf = token[0], rg = token[1], v = token[2];
            tree.update(lf, rg, v);
        } else {
            // Do nothing
        }
    }

    return 0;
}