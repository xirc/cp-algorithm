#include <map>
#include <string>
#include "union-find-tree-distance.hpp"
#include "../template-main.hpp"
#include "template-main-union-find-tree.hpp"

using namespace std;

struct Repr {
    static string to_string(UnionFindTree::node node) {
        return "(" + std::to_string(node.parent) + "," + std::to_string(node.length) + ")";
    }
};
using Interp = UnionFindTreeInterp<UnionFindTree, Repr>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}