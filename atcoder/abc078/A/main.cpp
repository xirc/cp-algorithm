#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char X, Y;
    
    cin >> X >> Y;
    if (X < Y) {
        cout << "<" << endl;
    } else if (X > Y) {
        cout << ">" << endl;
    } else {
        cout << "=" << endl;
    }

    return 0;
}