#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    int D = A - B;
    int M = 1;
    for (int i = 0; i < D; ++i) {
        M *= 32;
    }
    cout << M << endl;

    return 0;
}