#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a;
    string s;
    cin >> a >> s;
    cout << (a >= 3200 ? s : "red") << endl;

    return 0;
}