#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> x >> y;
    int z = x != y ? (x | y) ^ 3 : x;
    cout << z << endl;

    return 0;
}