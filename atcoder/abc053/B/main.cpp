#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int l = s.find_first_of('A');
    int r = s.find_last_of('Z');
    cout << (r - l + 1) << endl;

    return 0;
}