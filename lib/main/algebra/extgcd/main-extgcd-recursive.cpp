#include <bits/stdc++.h>
#include "template/template-main.hpp"
#include "template-extgcd-interop.hpp"
#include "cpalgo/algebra/extgcd-recursive.hpp"

using namespace std;

// Compute Extended Euculidean Algorithm
// Time: O( log(min(a,b)) )

void setup(string& header, map<string,Command>& commands) {
    setup(header, commands, extgcd);
    header = "Extended Euclidean Algorithm (Recursive)";
}