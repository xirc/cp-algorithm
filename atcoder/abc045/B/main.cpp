#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    int i = 0;
    vector<int> is = { 0, 0, 0 };
    vector<string> abc = { a, b, c };
    string cs = "abc", csu = "ABC";
    while (is[i] < abc[i].size()) {
        auto ch = abc[i][is[i]];
        is[i]++;
        i = cs.find(ch);
        assert(i >= 0 && i < 3);
    }
    cout << csu[i] << endl;

    return 0;
}