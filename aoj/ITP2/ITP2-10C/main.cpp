#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bitset<64> bits;

    int Q;
    cin >> Q;

    int t, i;
    while (Q--, Q >= 0) {
        cin >> t;
        if (t == 0) {
            // test i
            cin >> i;
            auto ans = (bits[i] ? 1 : 0);
            cout << ans << endl;
        } else if (t == 1) {
            // set i
            cin >> i;
            bits[i] = true;
        } else if (t == 2) {
            // clear i
            cin >> i;
            bits[i] = false;
        } else if (t == 3) {
            // flip i
            cin >> i;
            bits[i].flip();
        } else if (t == 4) {
            // all
            auto ans = bits.all() ? 1 : 0;
            cout << ans << endl;
        } else if (t == 5) {
            // any
            auto ans = bits.any() ? 1 : 0;
            cout << ans << endl;
        } else if (t == 6) {
            // none
            auto ans = bits.none() ? 1 : 0;
            cout << ans << endl;
        } else if (t == 7) {
            // count
            auto ans = bits.count();
            cout << ans << endl;
        } else if (t == 8) {
            // val
            auto ans = bits.to_ullong();
            cout << ans << endl;
        } else throw;
    }

    return 0;
}