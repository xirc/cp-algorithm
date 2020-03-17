#include <map>
#include <string>
#include "union-find-tree.hpp"
#include "../template-main.hpp"
#include "template-main-union-find-tree.hpp"

using namespace std;

string to_string(UnionFindTree::node value) {
    return to_string(value.parent);
}

using Interp = UnionFindTreeInterp<UnionFindTree>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}