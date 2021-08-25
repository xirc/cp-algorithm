#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X;
    cin >> X;
    bool should_turn_on = X >= 30;
    cout << (should_turn_on ? "Yes" : "No") << endl;

    return 0;
}