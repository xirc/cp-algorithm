#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    int m = (a - 1) + (a <= b ? 1 : 0);
    cout << m << endl;

    return 0;
}