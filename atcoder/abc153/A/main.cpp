#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int H, A;
    cin >> H >> A;
    int C = (H + A - 1) / A;
    cout << C << endl;

    return 0;
}