#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int solve(int A, int B) {
    int C = A + B;
    if (C >= 15 && B >= 8) return 1;
    if (C >= 10 && B >= 3) return 2;
    if (C >= 3) return 3;
    return 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    cout << solve(A, B) << endl;

    return 0;
}