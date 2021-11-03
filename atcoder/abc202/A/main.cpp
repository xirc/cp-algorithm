#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    a = 7 - a;
    b = 7 - b;
    c = 7 - c;
    cout << (a + b + c) << endl;

    return 0;
}