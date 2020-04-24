// Finding the maximum

#include <numeric>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp-purq.hpp"

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
using SegmentTreeInterp = SegmentTreeInterpPURQ<SegmentTree<int,int>,Query,Update>;

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}