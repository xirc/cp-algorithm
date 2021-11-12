#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int A, int B, int C, int D) {
    ll CDB = ll(C) * D - B;
    if (CDB <= 0) return -1;
    return (A + CDB - 1) / CDB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << solve(A, B, C, D) << endl;

    return 0;
}