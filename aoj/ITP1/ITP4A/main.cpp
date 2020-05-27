#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    int d = a / b, r = a % b;
    double f = (double)a / b;

    cout << fixed << setprecision(5) << d << " " << r << " " << f << endl;

    return 0;
}