#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    if (A > B) {
        cout << "Takahashi" << endl;
    } else if (A < B) {
        cout << "Aoki" << endl;
    } else {
        if (C == 0) {
            cout << "Aoki" << endl;
        } else {
            cout << "Takahashi" << endl;
        }
    }

    return 0;
}