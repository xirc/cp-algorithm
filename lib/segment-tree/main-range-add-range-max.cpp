// Range Update & Range Query
// Range Update: add a number to all numbers in the segments 'array[l,r)'
// Range Query: Finding the max in the segments 'array[l,r)'

#include <map>
#include <string>
#include "segment-tree-base.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Data {
    int max;
    int lazy;
    Data() {}
    Data(int max): Data(max, 0) {}
    Data(int max, int lazy): max(max), lazy(lazy) {}
};

class SegmentTree : public SegmentTreeBase<int,Data> {
public:
    SegmentTree(int n): SegmentTreeBase(n) {}
    // O(N)
    void build(std::vector<int>& array) {
        m_size = array.size();
        m_tree.resize(m_size * 4);
        build(array, 0, 0, m_size);
    }
    // O(log N)
    int query(int l, int r) {
        return query(0, 0, m_size, max(l,0), min(r,m_size)).max;
    }
    // O(log N)
    void update(int l, int r, int value) {
        update(0, 0, m_size, l, r, value);
    }
protected:
    int at(int index) override {
        return query(index, index + 1);
    }
    void pushdown(int v) {
        const int vl = left(v), vr = right(v);
        const int lazy = m_tree[v].lazy;
        m_tree[v] = Data(m_tree[v].max, 0);
        m_tree[vl] = Data(m_tree[vl].max + lazy, m_tree[vl].lazy + lazy);
        m_tree[vr] = Data(m_tree[vr].max + lazy, m_tree[vr].lazy + lazy);
    }
    void build(std::vector<int>& array, int v, int tl, int tr) {
        if (tr - tl == 1) {
            m_tree[v] = Data(array[tl]);
        } else {
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            build(array, vl, tl, tm);
            build(array, vr, tm, tr);
            m_tree[v] = Data(max(m_tree[vl].max,m_tree[vr].max));
        }
    }
    Data query(int v, int tl, int tr, int l, int r) {
        if (l >= r) {
            return Data(INT_MIN);
        }
        if (l == tl && r == tr) {
            return m_tree[v];
        }
        pushdown(v);
        const int tm = (tl + tr) / 2;
        const int vl = left(v), vr = right(v);
        const auto lhs = query(vl, tl, tm, l, min(r,tm));
        const auto rhs = query(vr, tm, tr, max(l,tm), r);
        return Data(max(lhs.max,rhs.max));
    }
    void update(int v, int tl, int tr, int l, int r, int value) {
        if (l >= r) {
            return;
        }
        if (l == tl && r == tr) {
            m_tree[v] = Data(m_tree[v].max + value, m_tree[v].lazy + value);
        } else {
            pushdown(v);
            const int tm = (tl + tr) / 2;
            const int vl = left(v), vr = right(v);
            update(vl, tl, tm, l, min(r, tm), value);
            update(vr, tm, tr, max(l,tm), r, value);
            int acc = max(m_tree[vl].max, m_tree[vr].max);
            m_tree[v] = Data(acc, 0);
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
        int l, r;
        cin >> l >> r;
        auto ans = m_tree.query(l, r);
        cout << ans << endl;
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
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}