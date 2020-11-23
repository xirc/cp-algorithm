#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int R;
    cin >> R;
    if (R < 1200) {
        cout << "ABC" << endl;
    } else if (R < 2800) {
        cout << "ARC" << endl;
    } else {
        cout << "AGC" << endl;
    }

    return 0;
}