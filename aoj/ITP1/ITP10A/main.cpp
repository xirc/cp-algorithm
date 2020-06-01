#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double dx = x1 - x2, dy = y1 - y2;
    double distance = hypot(dx, dy);
    cout << fixed << setprecision(4) << distance << endl;

    return 0;
}