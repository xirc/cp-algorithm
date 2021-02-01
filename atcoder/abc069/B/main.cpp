#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    cout << s[0] << (s.size() - 2) << *s.rbegin() << endl;

    return 0;
}