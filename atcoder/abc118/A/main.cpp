#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    if (B % A == 0) {
        cout << (A + B) << endl;
    } else {
        cout << (B - A) << endl;
    }

    return 0;
}