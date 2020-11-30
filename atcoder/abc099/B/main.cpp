#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    int x = b - a;
    int eh = (1 + x) * x / 2;
    int h = eh - b;
    cout << h << endl;

    return 0;
}