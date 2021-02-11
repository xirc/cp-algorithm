#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    cout << (b - a % b) % b << endl;

    return 0;
}