#include <bits/stdc++.h>
#include "../template-main.hpp"
#include "template-extgcd-interop.hpp"
#include "extgcd-iterative.hpp"

using namespace std;

// Compute Extended Euculidean Algorithm
// Time: O( log(min(a,b)) )

void setup(string& header, map<string,Command>& commands) {
    setup(header, commands, extgcd);
    header = "Extended Euclidean Algorithm (Iterative)";
}