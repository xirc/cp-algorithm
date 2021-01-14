#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    string a = s.substr(0, 5);
    string b = s.substr(6, 7);
    string c = s.substr(14, 5);
    cout << a << " " << b << " " << c << endl;

    return 0;
}