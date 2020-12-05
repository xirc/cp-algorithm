#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int D, N;
    cin >> D >> N;

    int m = (int)pow(100, D);
    if (N < 100) {
        cout << (N * m) << endl;
    } else {
        cout << (101 * m) << endl;
    }

    return 0;
}