#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    while (cin >> x >> y, x != 0 || y != 0) {
        if (x > y) swap(x, y);
        cout << x << " " << y << endl;
    }

    return 0;
}