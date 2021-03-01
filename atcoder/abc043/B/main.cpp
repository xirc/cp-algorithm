#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    vector<char> cs;

    cin >> s;
    for (auto ch : s) {
        if (ch == 'B') {
            if (cs.size()) cs.pop_back();
        } else {
            cs.push_back(ch);
        }
    }
    cout << string(cs.begin(), cs.end()) << endl;

    return 0;
}