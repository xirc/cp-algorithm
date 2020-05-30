#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, p;
    cin >> s >> p;
    s = s + s;
    bool ans = s.find(p) != string::npos;
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}