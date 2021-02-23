#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int L, H;
    int N;

    cin >> L >> H;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        if (A < L) {
            cout << L - A << endl;
        } else if (A > H) {
            cout << -1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}