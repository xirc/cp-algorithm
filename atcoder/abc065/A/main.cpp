#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, A, B;

    cin >> X >> A >> B;
    A -= B;
    if (A >= 0) {
        cout << "delicious" << endl;
    } else if (A >= -X) {
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }

    return 0;
}