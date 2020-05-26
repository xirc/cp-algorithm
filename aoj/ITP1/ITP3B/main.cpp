#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i = 0, x;
    while (true) {
        cin >> x;
        i++;
        if (x == 0) {
            break;
        }
        cout << "Case " << i << ": " << x << endl;
    }

    return 0;
}