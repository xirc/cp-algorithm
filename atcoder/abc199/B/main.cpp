#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;

    cin >> N;
    int A, B;

    int L = 1, R = 1000;
    for (int i = 0; i < N; ++i) {
        cin >> A;
        L = max(L, A);
    }
    for (int i = 0; i < N; ++i) {
        cin >> B;
        R = min(R, B);
    }
    cout << max(0, R - L + 1) << endl;

    return 0;
}