#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int X, A, B;
    cin >> X >> A >> B;
    X -= A;
    X %= B;
    cout << X << endl;

    return 0;
}