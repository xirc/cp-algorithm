#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ff = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string A, B;
    cin >> A >> B;
    stringstream ss(A + B);
    int C;
    ss >> C;
    cout << (C * 2) << endl;

    return 0;
}