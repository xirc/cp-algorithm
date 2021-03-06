// Range Update & Point Query
// Range Update: assign each element of a certain segment 'array[l,r)'
// Point Query: ask what is the value of 'array[i]'

#include <map>
#include <string>
#include "cpalgo/ds/segment-tree-rupq.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Option {
    bool active;
    int value;
    Option(): active(false), value(0) {}
    Option(int value): active(true), value(value) {}
};
struct Query {
    const int id = 0;
};
struct Update {
    int operator()(const int& lhs, const Option& rhs) const {
        if (rhs.active) {
            return rhs.value;
        }
        return lhs;
    }
};
struct Lazy {
    const Option id = Option();
    Option operator()(const Option& lhs, const Option& rhs) const {
        if (rhs.active) {
            return rhs;
        }
        return lhs;
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTree<int,Option>>
{
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase<SegmentTree<int,Option>>(
            std::shared_ptr<SegmentTree<int,Option>>(
                new SegmentTree<int,Option>(0, Query(), Update(), Lazy())
            )
        )
    {}
    void action_query() {
        int x;
        cin >> x;
        auto ans = m_tree->query(x);
        cout << to_string(ans) << endl;
    }
    void action_update() {
        int l, r, v;
        cin >> l >> r >> v;
        m_tree->update(l, r, E(v));
    }
    string to_string(const int& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {index}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}