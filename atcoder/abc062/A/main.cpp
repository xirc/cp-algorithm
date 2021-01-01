#include <bits/stdc++.h>

using namespace std;

set<int> A = { 1, 3, 5, 7, 8, 10, 12 };
set<int> B = { 4, 6, 9, 11 };
set<int> C = { 2 };

bool solve(int x, int y) {
    if (A.count(x) > 0 && A.count(y) > 0) {
        return true;
    } else if (B.count(x) > 0 && B.count(y) > 0) {
        return true;
    } else if (C.count(x) > 0 && C.count(y) > 0) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> x >> y;
    auto ans = solve(x, y) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}