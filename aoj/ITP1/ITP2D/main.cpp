#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int W, H, x, y, r;
    cin >> W >> H >> x >> y >> r;
    bool outx = (x - r < 0 || x + r > W);
    bool outy = (y - r < 0 || y + r > H);
    if (outx || outy) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}