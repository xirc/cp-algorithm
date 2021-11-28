#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<string> ss = { "ABC", "ARC", "AGC", "AHC" };
    for (int i = 0; i < 3; ++i) {
        string s;
        cin >> s;
        ss.erase(s);
    }
    assert(ss.size() == 1);
    cout << *ss.begin() << endl;

    return 0;
}