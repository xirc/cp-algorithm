// Finding the maximum

#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

struct Query {
    const int id = INT_MIN;
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
    commands["query"] =
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}