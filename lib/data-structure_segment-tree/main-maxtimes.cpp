// Finding the maximum and the number of times it appears

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

using pii = pair<int,int>;

struct MaxTimes {
    static constexpr pii id() {
        return {0, 0};
    }
    static pii op(pii lhs, pii rhs) {
        if (lhs.first > rhs.first) {
            return lhs;
        } else if (lhs.first < rhs.first) {
            return rhs;
        } else {
            return { lhs.first, lhs.second + rhs.second };
        }
    }
};
struct Assign {
    static constexpr pii id() {
        return { 0, 0 };
    }
    static pii op(pii lhs, pii rhs) {
        return rhs;
    }
};
using SegmentTreeImpl = SegmentTree<pii,MaxTimes,Assign>;

struct Value {
    static pii make_value(int value) {
        return { value, 1 };
    }
    static string repr_value(pii value) {
        return "(" + to_string(value.first) + "," + to_string(value.second) + ")";
    }
};
using SegmentTreeInterp = SegmentTreeInterpPURQ<pii,SegmentTreeImpl,Value>;

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string &header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}