#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S, T, U;
    int A, B;

    cin >> S >> T >> A >> B >> U;
    if (S == U) --A;
    else if (T == U) --B;
    cout << A << " " << B << endl;

    return 0;
}