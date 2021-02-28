#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H1, W1, H2, W2;
    cin >> H1 >> W1 >> H2 >> W2;
    auto ans = (H1 == H2 || H1 == W2 || W1 == H2 || W1 == W2);
    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}