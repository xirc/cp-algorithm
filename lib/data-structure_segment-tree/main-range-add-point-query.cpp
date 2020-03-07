// Range Update & Point Query
// Range Update: add a number to all numbers in the segments 'array[l,r)'
// Point Query: ask what is the value of 'array[i]'

#include <map>
#include <string>
#include "segment-tree-base.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

class SegmentTree : public SegmentTreeBase<int,int> {
public:
    SegmentTree(int n): SegmentTreeBase(n) {}
    // O(N)
    void build(std::vector<int>& array) {
        m_size = array.size();
        m_tree.resize(m_size * 4);
        build(array, 0, 0, m_size);
    }
    // O(log N)
    int query(int index) {
        if (index < 0 || index >= m_size) {
            throw;
        }
        return query(0, 0, m_size, index);
    }
    // O(log N)
    void update(int l, int r, int value) {
        update(0, 0, m_size, l, r, value);
    }
protected:
    int at(int index) override {
        return query(index);
    }
    void build(std::vector<int>& array, int v, int tl, int tr) {
        if (tr - tl == 1) {
            m_tree[v] = array[tl];
        } else {
            const int tm = (tl + tr) / 2;
            build(array, left(v), tl, tm);
            build(array, right(v), tm, tr);
            m_tree[v] = 0;
        }
    }
    int query(int v, int tl, int tr, int index) {
        if (tr - tl == 1) {
            return m_tree[v];
        }
        const int tm = (tl + tr) / 2;
        if (index < tm) {
            return m_tree[v] + query(left(v), tl, tm, index);
        } else {
            return m_tree[v] + query(right(v), tm, tr, index);
        }
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (l >= r) {
            return;
        }
        if (l == tl && r == tr) {
            m_tree[v] += value;
        } else {
            const int tm = (tl + tr) / 2;
            update(left(v), tl, tm, l, min(r, tm), value);
            update(right(v), tm, tr, max(l,tm), r, value);
        }
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<int,SegmentTree>
{
protected:
    int make_value(int value) {
        return value;
    }
    string repr_value(int value) {
        return to_string(value);
    }

public:
    void action_query() {
        int x;
        cin >> x;
        auto ans = m_tree.query(x);
        cout << repr_value(ans) << endl;
    }
    void action_update() {
        int l, r, v;
        cin >> l >> r >> v;
        m_tree.update(l, r, v);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {index}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}