#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    unsigned long a, b;
    cin >> a >> b;

    bitset<32> bitA(a), bitB(b);

    cout << (bitA & bitB) << endl;
    cout << (bitA | bitB) << endl;
    cout << (bitA ^ bitB) << endl;

    return 0;
}