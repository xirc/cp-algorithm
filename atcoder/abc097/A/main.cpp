#include <bits/stdc++.h>

using namespace std;

bool solve(int a, int b, int c, int d) {
    if (abs(a - c) <= d) {
        return true;
    }
    return abs(b - c) <= d && abs(a - b) <= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (solve(a, b, c, d) ? "Yes" : "No") << endl;

    return 0;
}