#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, K;
    cin >> A >> B >> K;
    assert(A <= B);
    if (B - A < 2*K) {
        for (int i = A; i <= B; ++i) {
            cout << i << endl;
        }
    } else {
        for (int i = 0; i < K; ++i) {
            cout << (A+i) << endl;
        }
        for (int i = K - 1; i >= 0; --i) {
            cout << (B-i) << endl;
        }
    }

    return 0;
}