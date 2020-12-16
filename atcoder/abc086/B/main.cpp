#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    string c = a + b;
    int m = stoi(c);
    int q = (int)sqrt(m);
    bool sq = q * q == m;
    cout << (sq ? "Yes" : "No") << endl;

    return 0;
}