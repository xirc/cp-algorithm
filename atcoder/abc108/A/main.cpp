#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    int odd = (K + 1) / 2, even = K / 2;
    cout << (odd * even) << endl;

    return 0;
}