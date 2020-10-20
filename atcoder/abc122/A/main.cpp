#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char b;
    cin >> b;
    if (b == 'A') {
        cout << "T";
    } else if (b == 'T') {
        cout << "A";
    } else if (b == 'C') {
        cout << "G";
    } else if (b == 'G') {
        cout << "C";
    }
    cout << endl;

    return 0;
}