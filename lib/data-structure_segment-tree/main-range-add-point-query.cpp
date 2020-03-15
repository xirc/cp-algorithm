// Range Update & Point Query
// Range Update: add a number to all numbers in the segments 'array[l,r)'
// Point Query: ask what is the value of 'array[i]'

#include <map>
#include <string>
#include "segment-tree-rupq.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp.hpp"

using namespace std;

struct Query {
    const int id = 0;
};
struct Update {
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};
struct Lazy {
    const int id = 0;
    int operator()(const int& lhs, const int& rhs) const {
        return lhs + rhs;
    }
};

class SegmentTreeInterp
    : public SegmentTreeInterpBase<SegmentTree<int,int>>
{
public:
    SegmentTreeInterp()
        : SegmentTreeInterpBase<SegmentTree<int,int>>(
            std::shared_ptr<SegmentTree<int,int>>(
                new SegmentTree<int,int>(0, Query(), Update(), Lazy())
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
        m_tree->update(l, r, v);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {index}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {left} {right} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}