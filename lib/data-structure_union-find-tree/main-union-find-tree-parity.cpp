#include <map>
#include <string>
#include "union-find-tree-parity.hpp"
#include "../template-main.hpp"
#include "template-main-union-find-tree.hpp"

using namespace std;

string to_string(UnionFindTree::node node) {
    return "(" + to_string(node.parent) + "," + to_string(node.bipartite) + ")";
}

using Interp = UnionFindTreeInterp<UnionFindTree>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}