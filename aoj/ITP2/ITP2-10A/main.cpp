#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unsigned long x;
    cin >> x;

    bitset<32> b(x);
    cout << b << endl;
    cout << (~b) << endl;
    cout << (b << 1) << endl;
    cout << (b >> 1) << endl;

    return 0;
}