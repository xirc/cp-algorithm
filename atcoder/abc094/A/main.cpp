#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, X;
    cin >> A >> B >> X;
    if (X < A || X > A + B) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}