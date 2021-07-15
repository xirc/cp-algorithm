#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    string sa = "", sb = "";
    for (int i = 0; i < b; ++i) sa += to_string(a);
    for (int i = 0; i < a; ++i) sb += to_string(b);
    cout << min(sa, sb) << endl;

    return 0;
}