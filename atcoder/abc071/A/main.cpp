#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, a, b;
    cin >> x >> a >> b;
    int da = abs(x - a);
    int db = abs(x - b);
    if (da < db) {
        cout << "A" << endl;
    } else if (db < da) {
        cout << "B" << endl;
    } else throw;

    return 0;
}