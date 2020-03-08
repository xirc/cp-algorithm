// Finding the maximum

#include <map>
#include <string>
#include "segment-tree.hpp"
#include "../template-main.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

struct Maximum {
    static constexpr int id() {
        return INT_MIN;
    }
    static int op(int lhs, int rhs) {
        return std::max(lhs, rhs);
    }
};
struct Assign {
    static constexpr int id() {
        return INT_MIN;
    }
    static int op(int lhs, int rhs) {
        return rhs;
    }
};
using SegmentTreeImpl = SegmentTree<int,Maximum,Assign>;

struct Value {
    static int make_value(int value) {
        return value;
    }
    static string repr_value(int value) {
        return to_string(value);
    }
};
using SegmentTreeInterp = SegmentTreeInterpPURQ<int,SegmentTreeImpl,Value>;

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] =
        Command { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] =
        Command { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}