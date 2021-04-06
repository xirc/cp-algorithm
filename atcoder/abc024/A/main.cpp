#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C, K;
    int S, T;

    cin >> A >> B >> C >> K;
    cin >> S >> T;

    if (S + T >= K) {
        A -= C;
        B -= C;
    }
    int F = A * S + B * T;
    cout << F << endl;

    return 0;
}