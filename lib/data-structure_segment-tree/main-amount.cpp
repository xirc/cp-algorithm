// Searching for the first element greater than a given amount

#include <algorithm>
#include <numeric>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Query {
    const int id = numeric_limits<int>::lowest();
    int operator()(int lhs, int rhs) const {
        return std::max(lhs, rhs);
    }
};
struct Update {
    int operator()(int lhs, int rhs) const {
        return rhs;
    }
};

class SegmentTreeImpl : public SegmentTree<int,int> {
public:
    SegmentTreeImpl(int n): SegmentTree(n, Query(), Update()) {}

    int query(int l, int r, int x) {
        return query(0, 0, N, l, r, x);
    }

protected:
    int query(int v, int lv, int rv, int l, int r, int x) {
        if (lv >= r || rv <= l) {
            return -1;
        }
        if (l <= lv && rv <= r) {
            if (tree[v] <= x){
                return -1;
            }
            while (rv - lv > 1) {
                const int mv = lv + (rv - lv) / 2;
                if (tree[left(v)] > x) {
                    v = left(v);
                    rv = mv;
                } else {
                    v = right(v);
                    lv = mv;
                }
            }
            return lv;
        }

        const int mv = lv + (rv - lv) / 2;
        const int ans = query(left(v), lv, mv, l, r, x);
        if (ans != -1) {
            return ans;
        }
        return query(right(v), mv, rv, l, r, v);
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTreeImpl>
{
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase(
            std::shared_ptr<SegmentTreeImpl>(new SegmentTreeImpl(0))
        )
    {}
    void action_query() {
        int l, r, x;
        cin >> l >> r >> x;
        auto ans = m_tree->query(l, r, x);
        cout << ans << endl;
    }
    void action_update() {
        int i, v;
        cin >> i >> v;
        bool ans = m_tree->update(i, E(v));
        cout << (ans ? "true" : "false") << endl;
    }
    string to_string(const int& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = {"query {left} {right} {value}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}