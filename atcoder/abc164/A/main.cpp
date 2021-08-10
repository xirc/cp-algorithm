#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int S, W;
    cin >> S >> W;
    cout << (W >= S ? "unsafe" : "safe") << endl;

    return 0;
}