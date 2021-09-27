#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    int C = A - B;
    ff discount_rate = ff(C) * 100 / ff(A);
    cout << fixed << setprecision(3) << discount_rate << endl;

    return 0;
}