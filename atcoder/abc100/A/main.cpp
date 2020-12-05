#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;

    if (A <= 8 && B <= 8) {
        cout << "Yay!" << endl;
    } else {
        cout << ":(" << endl;
    }

    return 0;
}