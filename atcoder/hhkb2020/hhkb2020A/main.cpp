#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char S, T;
    cin >> S >> T;
    if (S == 'Y') {
        cout << toupper(T, locale::classic()) << endl;
    } else {
        cout << T << endl;
    }

    return 0;
}