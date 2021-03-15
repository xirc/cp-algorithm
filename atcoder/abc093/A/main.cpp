#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto pass = s == "abc";
    cout << (pass ? "Yes" : "No") << endl;

    return 0;
}