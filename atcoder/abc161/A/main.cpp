#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, Y, Z;
    cin >> X >> Y >> Z;
    swap(X, Y);
    swap(X, Z);
    cout << X << " " << Y << " " << Z << endl;

    return 0;
}