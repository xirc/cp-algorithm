// Finding the least common multiple

#include <map>
#include <string>
#include "cpalgo/ds/segment-tree.hpp"
#include "template-segment-tree-interp-purq.hpp"

using namespace std;

int gcd(int lhs, int rhs) {
    while (lhs % rhs != 0) {
        int tmp = rhs;
        rhs = lhs % rhs;
        lhs = tmp;
    }
    return rhs;
}

int lcm(int lhs, int rhs) {
    return lhs * rhs / gcd(lhs, rhs);
}

struct Query {
    const int id = 0;
    int operator()(int lhs, int rhs) const {
        if (!lhs || !rhs) {
            return lhs ? lhs : rhs;
        }
        return lcm(lhs,rhs);
    }
};
struct Update {
    int operator()(int lhs, int rhs) const {
        return rhs;
    }
};
class SegmentTreeInterp : public SegmentTreeInterpPURQ<SegmentTree<int,int>,Query,Update> {
    string to_string(const int& value) override {
        return std::to_string(value);
    }
};

SegmentTreeInterp* interp = new SegmentTreeInterp();
void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
    commands["query"] = { "query {left} {right}", bind(&SegmentTreeInterp::action_query, interp) };
    commands["update"] = { "update {index} {value}", bind(&SegmentTreeInterp::action_update, interp) };
}