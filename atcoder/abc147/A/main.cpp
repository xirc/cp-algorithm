#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    int S = A + B + C;
    cout << (S >= 22 ? "bust" : "win") << endl;

    return 0;
}