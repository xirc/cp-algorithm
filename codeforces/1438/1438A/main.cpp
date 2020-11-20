#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, N;
    cin >> T;

    for (int tt = 0; tt < T; ++tt) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << 1;
        }
        cout << endl;
    }

    return 0;
}