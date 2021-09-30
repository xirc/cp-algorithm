#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int M, H;
    cin >> M >> H;
    cout << (H % M == 0 ? "Yes" : "No") << endl;

    return 0;
}