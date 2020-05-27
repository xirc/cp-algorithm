#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double r;
    cin >> r;
    double area = M_PI * r * r;
    double circumference = 2 * M_PI * r;

    cout << fixed << setprecision(5)
        << area << " " << circumference << endl;

    return 0;
}