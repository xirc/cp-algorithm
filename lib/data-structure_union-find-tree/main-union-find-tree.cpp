#include <map>
#include <string>
#include "union-find-tree.hpp"
#include "../template-main.hpp"
#include "template-main-union-find-tree.hpp"

using namespace std;

struct Repr {
    static string to_string(int value) {
        return std::to_string(value);
    }
};
using Interp = UnionFindTreeInterp<UnionFindTree, Repr>;
Interp* interp = new Interp();

void setup(string& header, map<string,Command>& commands) {
    setup(interp, header, commands);
}