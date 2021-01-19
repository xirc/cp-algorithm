#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    A = (A - 2 + 13) % 13;
    B = (B - 2 + 13) % 13;
    if (A > B) {
        cout << "Alice" << endl;
    } else if (A < B) {
        cout << "Bob" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}