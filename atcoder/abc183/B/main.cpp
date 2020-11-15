#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long Sx, Sy, Gx, Gy;
    cin >> Sx >> Sy >> Gx >> Gy;
    double Rx = (Gx*Sy + Gy*Sx) / double(Gy + Sy);
    cout << fixed << setprecision(7) << Rx << endl;

    return 0;
}