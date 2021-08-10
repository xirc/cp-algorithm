#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int X = (A + D - 1) / D;
    int Y = (C + B - 1) / B;
    cout << (X >= Y ? "Yes" : "No") << endl;

    return 0;
}