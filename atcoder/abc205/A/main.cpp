#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    auto energy = A * B / ff(100);
    cout << fixed << setprecision(7) << energy << endl;

    return 0;
}