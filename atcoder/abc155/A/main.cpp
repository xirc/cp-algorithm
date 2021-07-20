#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    bool not_poor = (A == B && B == C) || (A != B && B != C && C != A);
    cout << (not_poor ? "No" : "Yes") << endl;

    return 0;
}