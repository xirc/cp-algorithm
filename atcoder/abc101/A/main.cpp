#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int n = 0;
    for (auto c : s) {
        if (c == '+') ++n;
        else if (c == '-') --n;
        else throw;
    }
    cout << n << endl;

    return 0;
}