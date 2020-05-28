#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, W;
    while (cin >> H >> W, H || W) {
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                string w = ((x + y) & 1) ? "." : "#";
                cout << w;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}