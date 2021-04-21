#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string c1, c2;
    cin >> c1 >> c2;
    bool pass = (c1[0] == c2[2] && c2[0] == c1[2] && c1[1] == c2[1]);
    cout << (pass ? "YES" : "NO") << endl;

    return 0;
}