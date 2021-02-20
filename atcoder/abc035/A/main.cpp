#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int W, H;
    cin >> W >> H;
    if (4 * H == 3 * W) {
        cout << "4:3" << endl;
    } else {
        cout << "16:9" << endl;
    }

    return 0;
}