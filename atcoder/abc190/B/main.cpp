#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bool pass = false;
    int N, S, D;
    cin >> N >> S >> D;
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        if (X < S && Y > D) {
            pass = true;
        }
    }
    cout << (pass ? "Yes" : "No") << endl;

    return 0;
}